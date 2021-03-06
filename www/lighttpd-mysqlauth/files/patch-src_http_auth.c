diff -Naur new/lighttpd-1.4.23/src/http_auth.c old/lighttpd-1.4.23/src/http_auth.c
--- src/http_auth.c	2009-06-11 14:05:06.000000000 +0400
+++ src/http_auth.c	2009-10-08 10:10:15.000000000 +0400
@@ -24,6 +24,7 @@
 #include <errno.h>
 #include <unistd.h>
 #include <ctype.h>
+#include <mysql/mysql.h>
 
 #include "server.h"
 #include "log.h"
@@ -291,6 +292,117 @@
 		stream_close(&f);
 	} else if (p->conf.auth_backend == AUTH_BACKEND_LDAP) {
 		ret = 0;
+       } else if (p->conf.auth_backend == AUTH_BACKEND_MYSQL) {
+               MYSQL_RES *result;
+               MYSQL_ROW row;
+               int port = atoi(p->conf.auth_mysql_port->ptr);
+               char q[255];
+
+               if (p->conf.auth_mysql_socket->ptr != NULL)
+                   if (0 == strcmp(p->conf.auth_mysql_socket->ptr, "")) p->conf.auth_mysql_socket->ptr = NULL;
+
+               p->conf.mysql_conn = mysql_init(NULL);
+
+               if (mysql_real_connect(p->conf.mysql_conn, p->conf.auth_mysql_host->ptr, p->conf.auth_mysql_user->ptr, p->conf.auth_mysql_pass->ptr, p->conf.auth_mysql_db->ptr, port, p->conf.auth_mysql_socket->ptr, 0))
+               {
+//#define MY_HOSTING
+
+#ifdef MY_HOSTING
+                   char my_full_realm[255];
+                   char *my_realm = NULL;
+                   char *my_domain = NULL;
+
+                   char *uname;
+                   size_t unamelen;
+
+                   unamelen = strlen(username->ptr);
+                   uname = malloc(unamelen*2+1);
+
+                   mysql_real_escape_string(p->conf.mysql_conn,
+                                            uname, username->ptr,
+                                            (unsigned long)unamelen);
+
+                   strcpy(my_full_realm, realm->ptr);
+                   my_realm = strtok(my_full_realm, "@");
+
+                   if (my_realm != NULL)
+                   my_domain = strtok(NULL, "@");
+
+                   sprintf(q, "SELECT %s FROM %s, %s WHERE %s='%s' AND %s='%s' AND %s='%s' AND %s=%s",
+                               p->conf.auth_mysql_col_pass->ptr,
+
+                               p->conf.auth_mysql_users_table->ptr,
+                               p->conf.auth_mysql_domains_table->ptr,
+
+                               p->conf.auth_mysql_col_user->ptr,
+                               uname,
+
+                               p->conf.auth_mysql_col_realm->ptr,
+                               my_realm,
+
+                               p->conf.auth_mysql_col_domain->ptr,
+                               my_domain,
+
+                               p->conf.auth_mysql_domains_table_col_domain_id->ptr,
+                               p->conf.auth_mysql_users_table_col_domain_id->ptr
+                   );
+
+                   free(uname);
+#else
+                   // sanitize username & realm by taguchi@ff.iij4u.or.jp
+                   char *uname, *urealm;
+                   size_t unamelen, urealmlen;
+
+                   unamelen = strlen(username->ptr);
+                   urealmlen = strlen(realm->ptr);
+                   uname = malloc(unamelen*2+1);
+                   urealm = malloc(urealmlen*2+1);
+
+                   mysql_real_escape_string(p->conf.mysql_conn,
+                                            uname, username->ptr,
+                                            (unsigned long)unamelen);
+
+                   mysql_real_escape_string(p->conf.mysql_conn,
+                                            urealm, realm->ptr,
+                                            (unsigned long)unamelen);
+
+                   mysql_real_escape_string(p->conf.mysql_conn,
+                                            urealm, realm->ptr,
+                                            (unsigned long)urealmlen);
+
+                   sprintf(q, "SELECT %s FROM %s WHERE %s='%s' AND %s='%s'",
+                               p->conf.auth_mysql_col_pass->ptr,
+                               p->conf.auth_mysql_users_table->ptr,
+                               p->conf.auth_mysql_col_user->ptr,
+                               uname,
+                               p->conf.auth_mysql_col_realm->ptr,
+                               urealm
+                   );
+
+                   free(uname);
+                   free(urealm);
+#endif
+
+                   mysql_query(p->conf.mysql_conn, q);
+                   result = mysql_store_result(p->conf.mysql_conn);
+                   if (mysql_num_rows(result) == 1)
+                   {
+                       /* found */
+                       row = mysql_fetch_row(result);
+                       buffer_copy_string_len(password, row[0], strlen(row[0]));
+
+                       ret = 0;
+                   } else
+                   {
+                       /* not found */
+                       ret = -1;
+                   }
+
+                   mysql_free_result(result);
+                   mysql_close(p->conf.mysql_conn);
+
+                   p->conf.mysql_conn = NULL;
+               }
 	} else {
 		return -1;
 	}
@@ -831,6 +943,60 @@
 
 		return 0;
 #endif
+       } else if (p->conf.auth_backend == AUTH_BACKEND_MYSQL) {
+               /*
+                   we check for md5 crypt() now
+                   request by Nicola Tiling <nti@w4w.net>
+               */
+               if (password->ptr[0] == '$' && password->ptr[2] == '$')
+               {
+                   char salt[32];
+                   char *crypted;
+                   size_t salt_len = 0;
+                   char *dollar = NULL;
+
+                   if (NULL == (dollar = strchr(password->ptr + 3, '$'))) {
+                       fprintf(stderr, "%s.%d\n", __FILE__, __LINE__);
+                       return -1;
+                   }
+
+                   salt_len = dollar - password->ptr;
+
+                   if (salt_len > sizeof(salt) - 1)
+                   {
+                       fprintf(stderr, "%s.%d\n", __FILE__, __LINE__);
+                       return -1;
+                   }
+
+                   strncpy(salt, password->ptr, salt_len);
+
+                   salt[salt_len] = '\0';
+
+                   crypted = crypt(pw, salt);
+
+                   if (0 == strcmp(password->ptr, crypted))
+                   {
+                       return 0;
+                   } else {
+                       fprintf(stderr, "%s.%d\n", __FILE__, __LINE__);
+                   }
+               } else
+               /* plain md5 check now */
+               {
+                       MD5_CTX Md5Ctx;
+                       HASH HA1;
+                       char a1[256];
+
+                       MD5_Init(&Md5Ctx);
+                       MD5_Update(&Md5Ctx, (unsigned char *)pw, strlen(pw));
+                       MD5_Final(HA1, &Md5Ctx);
+
+                       CvtHex(HA1, a1);
+
+                       if (0 == strcmp(password->ptr, a1)) {
+                               return 0;
+                       }
+               }
 	}
 	return -1;
 }
diff -Naur new/lighttpd-1.4.23/src/http_auth.h old/lighttpd-1.4.23/src/http_auth.h
--- src/http_auth.h	2009-03-31 02:16:59.000000000 +0400
+++ src/http_auth.h	2009-10-08 10:13:56.000000000 +0400
@@ -8,13 +8,15 @@
 # define USE_LDAP
 # include <ldap.h>
 #endif
+#include <mysql/mysql.h>
 
 typedef enum {
 	AUTH_BACKEND_UNSET,
 	AUTH_BACKEND_PLAIN,
 	AUTH_BACKEND_LDAP,
 	AUTH_BACKEND_HTPASSWD,
-	AUTH_BACKEND_HTDIGEST
+        AUTH_BACKEND_HTDIGEST,
+        AUTH_BACKEND_MYSQL
 } auth_backend_t;
 
 typedef struct {
@@ -49,6 +51,22 @@
 	buffer *ldap_filter_pre;
 	buffer *ldap_filter_post;
 #endif
+
+       MYSQL  *mysql_conn;
+       buffer *auth_mysql_host;
+       buffer *auth_mysql_user;
+       buffer *auth_mysql_pass;
+       buffer *auth_mysql_db;
+       buffer *auth_mysql_port;
+       buffer *auth_mysql_socket;
+       buffer *auth_mysql_users_table;
+       buffer *auth_mysql_col_user;
+       buffer *auth_mysql_col_pass;
+       buffer *auth_mysql_col_realm;
+       buffer *auth_mysql_domains_table;
+       buffer *auth_mysql_col_domain;
+       buffer *auth_mysql_domains_table_col_domain_id;
+       buffer *auth_mysql_users_table_col_domain_id;
 } mod_auth_plugin_config;
 
 typedef struct {
diff -Naur new/lighttpd-1.4.23/src/Makefile.am old/lighttpd-1.4.23/src/Makefile.am
--- src/Makefile.am	2009-06-16 17:45:42.000000000 +0400
+++ src/Makefile.am	2009-10-08 10:26:56.000000000 +0400
@@ -242,7 +242,7 @@
 lib_LTLIBRARIES += mod_auth.la
 mod_auth_la_SOURCES = mod_auth.c http_auth_digest.c http_auth.c
 mod_auth_la_LDFLAGS = -module -export-dynamic -avoid-version -no-undefined
-mod_auth_la_LIBADD = $(CRYPT_LIB) $(LDAP_LIB) $(LBER_LIB) $(common_libadd)
+mod_auth_la_LIBADD = $(MYSQL_LIBS) $(CRYPT_LIB) $(LDAP_LIB) $(LBER_LIB) $(common_libadd)
 
 lib_LTLIBRARIES += mod_rewrite.la
 mod_rewrite_la_SOURCES = mod_rewrite.c
diff -Naur lighttpd-1.4.23/src/Makefile.in old/lighttpd-1.4.23/src/Makefile.in
--- src/Makefile.in	2009-06-19 23:19:22.000000000 +0400
+++ src/Makefile.in	2009-10-08 10:26:25.000000000 +0400
@@ -706,7 +706,7 @@
 mod_compress_la_LIBADD = $(Z_LIB) $(BZ_LIB) $(common_libadd)
 mod_auth_la_SOURCES = mod_auth.c http_auth_digest.c http_auth.c
 mod_auth_la_LDFLAGS = -module -export-dynamic -avoid-version -no-undefined
-mod_auth_la_LIBADD = $(CRYPT_LIB) $(LDAP_LIB) $(LBER_LIB) $(common_libadd)
+mod_auth_la_LIBADD = $(MYSQL_LIBS) $(CRYPT_LIB) $(LDAP_LIB) $(LBER_LIB) $(common_libadd)
 mod_rewrite_la_SOURCES = mod_rewrite.c
 mod_rewrite_la_LDFLAGS = -module -export-dynamic -avoid-version -no-undefined
 mod_rewrite_la_LIBADD = $(PCRE_LIB) $(common_libadd)
diff -Naur new/lighttpd-1.4.23/src/mod_auth.c old/lighttpd-1.4.23/src/mod_auth.c
--- src/mod_auth.c	2009-04-11 16:08:19.000000000 +0400
+++ src/mod_auth.c	2009-10-08 10:24:13.000000000 +0400
@@ -6,6 +6,7 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <unistd.h>
+#include <mysql/mysql.h>
 
 #include "plugin.h"
 #include "http_auth.h"
@@ -83,6 +84,20 @@
 			if (s->ldap) ldap_unbind_s(s->ldap);
 #endif
 
+                       buffer_free(s->auth_mysql_host);
+                       buffer_free(s->auth_mysql_user);
+                       buffer_free(s->auth_mysql_pass);
+                       buffer_free(s->auth_mysql_db);
+                       buffer_free(s->auth_mysql_socket);
+                       buffer_free(s->auth_mysql_users_table);
+                       buffer_free(s->auth_mysql_col_user);
+                       buffer_free(s->auth_mysql_col_pass);
+                       buffer_free(s->auth_mysql_col_realm);
+                       buffer_free(s->auth_mysql_domains_table);
+                       buffer_free(s->auth_mysql_col_domain);
+                       buffer_free(s->auth_mysql_domains_table_col_domain_id);
+                       buffer_free(s->auth_mysql_users_table_col_domain_id);
+
 			free(s);
 		}
 		free(p->config_storage);
@@ -120,6 +135,21 @@
 	PATCH(ldap_filter_post);
 #endif
 
+       PATCH(auth_mysql_host);
+       PATCH(auth_mysql_user);
+       PATCH(auth_mysql_pass);
+       PATCH(auth_mysql_db);
+       PATCH(auth_mysql_port);
+       PATCH(auth_mysql_socket);
+       PATCH(auth_mysql_users_table);
+       PATCH(auth_mysql_col_user);
+       PATCH(auth_mysql_col_pass);
+       PATCH(auth_mysql_col_realm);
+       PATCH(auth_mysql_domains_table);
+       PATCH(auth_mysql_col_domain);
+       PATCH(auth_mysql_domains_table_col_domain_id);
+       PATCH(auth_mysql_users_table_col_domain_id);
+
 	/* skip the first, the global context */
 	for (i = 1; i < srv->config_context->used; i++) {
 		data_config *dc = (data_config *)srv->config_context->data[i];
@@ -169,6 +199,34 @@
 				PATCH(auth_ldap_bindpw);
 			} else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.ldap.allow-empty-pw"))) {
 				PATCH(auth_ldap_allow_empty_pw);
+                       } else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.host"))) {
+                               PATCH(auth_mysql_host);
+                       } else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.user"))) {
+                               PATCH(auth_mysql_user);
+                       } else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.pass"))) {
+                               PATCH(auth_mysql_pass);
+                       } else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.db"))) {
+                               PATCH(auth_mysql_db);
+                       } else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.port"))) {
+                               PATCH(auth_mysql_port);
+                       } else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.socket"))) {
+                               PATCH(auth_mysql_user);
+                       } else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.users_table"))) {
+                               PATCH(auth_mysql_users_table);
+                       } else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.col_user"))) {
+                               PATCH(auth_mysql_col_user);
+                       } else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.col_pass"))) {
+                               PATCH(auth_mysql_col_pass);
+                       } else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.col_realm"))) {
+                               PATCH(auth_mysql_col_realm);
+                       } else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.domains_table"))) {
+                               PATCH(auth_mysql_domains_table);
+                       } else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.col_domain"))) {
+                               PATCH(auth_mysql_col_domain);
+                       } else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.domains_table_col_domain_id"))) {
+                               PATCH(auth_mysql_domains_table_col_domain_id);
+                       } else if (buffer_is_equal_string(du->key, CONST_STR_LEN("auth.backend.mysql.users_table_col_domain_id"))) {
+                               PATCH(auth_mysql_users_table_col_domain_id);
 			}
 		}
 	}
@@ -323,10 +381,24 @@
 		{ "auth.backend.ldap.starttls",     NULL, T_CONFIG_BOOLEAN, T_CONFIG_SCOPE_CONNECTION }, /* 8 */
  		{ "auth.backend.ldap.bind-dn",      NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION }, /* 9 */
  		{ "auth.backend.ldap.bind-pw",      NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION }, /* 10 */
-		{ "auth.backend.ldap.allow-empty-pw",     NULL, T_CONFIG_BOOLEAN, T_CONFIG_SCOPE_CONNECTION }, /* 11 */
+                { "auth.backend.ldap.allow-empty-pw",     NULL, T_CONFIG_BOOLEAN, T_CONFIG_SCOPE_CONNECTION },
 		{ "auth.backend.htdigest.userfile", NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION }, /* 12 */
 		{ "auth.backend.htpasswd.userfile", NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION }, /* 13 */
 		{ "auth.debug",                     NULL, T_CONFIG_SHORT, T_CONFIG_SCOPE_CONNECTION },  /* 14 */
+                { "auth.backend.mysql.host",        NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION },
+                { "auth.backend.mysql.user",        NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION },
+                { "auth.backend.mysql.pass",        NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION },
+                { "auth.backend.mysql.db",          NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION },
+                { "auth.backend.mysql.port",        NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION },
+                { "auth.backend.mysql.socket",      NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION },
+                { "auth.backend.mysql.users_table", NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION },
+                { "auth.backend.mysql.col_user",    NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION },
+                { "auth.backend.mysql.col_pass",    NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION },
+                { "auth.backend.mysql.col_realm",   NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION }, /* 23 */
+                { "auth.backend.mysql.domains_table",               NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION },
+                { "auth.backend.mysql.col_domain",                  NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION },
+                { "auth.backend.mysql.domains_table_col_domain_id", NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION },
+                { "auth.backend.mysql.users_table_col_domain_id",   NULL, T_CONFIG_STRING, T_CONFIG_SCOPE_CONNECTION }, /* 27 */
 		{ NULL,                             NULL, T_CONFIG_UNSET, T_CONFIG_SCOPE_UNSET }
 	};
 
@@ -355,6 +427,22 @@
 		s->auth_debug = 0;
 
 		s->auth_require = array_init();
+                s->mysql_conn                             = NULL;
+                s->auth_mysql_host                        = buffer_init();
+                s->auth_mysql_user                        = buffer_init();
+                s->auth_mysql_pass                        = buffer_init();
+                s->auth_mysql_db                          = buffer_init();
+                s->auth_mysql_port                        = buffer_init();
+                s->auth_mysql_socket                      = buffer_init();
+                s->auth_mysql_users_table                 = buffer_init();
+                s->auth_mysql_col_user                    = buffer_init();
+                s->auth_mysql_col_pass                    = buffer_init();
+                s->auth_mysql_col_realm                   = buffer_init();
+                s->auth_mysql_domains_table               = buffer_init();
+                s->auth_mysql_col_domain                  = buffer_init();
+                s->auth_mysql_domains_table_col_domain_id = buffer_init();
+                s->auth_mysql_users_table_col_domain_id   = buffer_init();
+
 
 #ifdef USE_LDAP
 		s->ldap_filter_pre = buffer_init();
@@ -377,7 +465,20 @@
 		cv[12].destination = s->auth_htdigest_userfile;
 		cv[13].destination = s->auth_htpasswd_userfile;
 		cv[14].destination = &(s->auth_debug);
-
+                cv[15].destination = s->auth_mysql_host;
+                cv[16].destination = s->auth_mysql_user;
+                cv[17].destination = s->auth_mysql_pass;
+                cv[18].destination = s->auth_mysql_db;
+                cv[19].destination = s->auth_mysql_port;
+                cv[20].destination = s->auth_mysql_socket;
+                cv[21].destination = s->auth_mysql_users_table;
+                cv[22].destination = s->auth_mysql_col_user;
+                cv[23].destination = s->auth_mysql_col_pass;
+                cv[24].destination = s->auth_mysql_col_realm;
+                cv[25].destination = s->auth_mysql_domains_table;
+                cv[26].destination = s->auth_mysql_col_domain;
+                cv[27].destination = s->auth_mysql_domains_table_col_domain_id;
+                cv[28].destination = s->auth_mysql_users_table_col_domain_id;
 		p->config_storage[i] = s;
 		ca = ((data_config *)srv->config_context->data[i])->value;
 
@@ -394,6 +495,8 @@
 				s->auth_backend = AUTH_BACKEND_PLAIN;
 			} else if (0 == strcmp(s->auth_backend_conf->ptr, "ldap")) {
 				s->auth_backend = AUTH_BACKEND_LDAP;
+                        } else if (0 == strcmp(s->auth_backend_conf->ptr, "mysql")) {
+                                s->auth_backend = AUTH_BACKEND_MYSQL;
 			} else {
 				log_error_write(srv, __FILE__, __LINE__, "sb", "auth.backend not supported:", s->auth_backend_conf);
 
@@ -534,6 +637,28 @@
 				return (ret);
 			break;
 		}
+               case AUTH_BACKEND_MYSQL: {
+                       int port = atoi(s->auth_mysql_port->ptr);
+
+                       if (p->conf.auth_mysql_socket->ptr != NULL)
+                           if (0 == strcmp(s->auth_mysql_socket->ptr, "")) s->auth_mysql_socket->ptr = NULL;
+
+                       s->mysql_conn = mysql_init(NULL);
+                       if (!mysql_real_connect(s->mysql_conn, s->auth_mysql_host->ptr, s->auth_mysql_user->ptr, s->auth_mysql_pass->ptr, s->auth_mysql_db->ptr, port, NULL, 0))
+                       {
+                           log_error_write(srv, __FILE__, __LINE__, "sbsbsbsbss",
+                               "opening connection to mysql:", s->auth_mysql_host,
+                               "user:", s->auth_mysql_user,
+                               "pass:", s->auth_mysql_pass,
+                               "db:", s->auth_mysql_db,
+                               "failed:", strerror(errno));
+
+                           return HANDLER_ERROR;
+                       }
+                       mysql_close(s->mysql_conn);
+
+                       break;
+               }
 		default:
 			break;
 		}
