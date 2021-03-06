--- plugins/digestmd5.c.orig	2006-05-17 20:46:17.000000000 +0400
+++ plugins/digestmd5.c
@@ -2715,7 +2715,7 @@ static sasl_server_plug_t digestmd5_serv
 	"DIGEST-MD5",			/* mech_name */
 #ifdef WITH_RC4
 	128,				/* max_ssf */
-#elif WITH_DES
+#elif defined(WITH_DES)
 	112,
 #else 
 	1,
@@ -4034,7 +4034,7 @@ static sasl_client_plug_t digestmd5_clie
 	"DIGEST-MD5",
 #ifdef WITH_RC4				/* mech_name */
 	128,				/* max ssf */
-#elif WITH_DES
+#elif defined(WITH_DES)
 	112,
 #else
 	1,
