# New ports collection makefile for:	postfix-current
# Date created: 	18 Mar 1999
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	postfix
DISTVERSION=	2.8-20100323
PORTEPOCH=	4
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.porcupine.org/mirrors/postfix-release/experimental/ \
		ftp://postfix.mirrors.pair.com/experimental/ \
		ftp://ftp.tux.org/pub/net/postfix/experimental/ \
		http://mirrors.rootservices.net/postfix/experimental/ \
		ftp://ftp.samurai.com/pub/postfix/experimental/ \
		http://ftp.unicamp.br/pub/postfix/experimental/
PKGNAMESUFFIX=	-current
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	A secure alternative to widely-used Sendmail

CONFLICTS=	courier-0.* postfix-1.* postfix-2.* postfix-current-2.[0-79]* \
		sendmail-8.* sendmail-*-8.* smail-3.* zmailer-2.*

MAKE_JOBS_SAFE=	yes
USE_SUBMAKE=	yes
USE_PERL5_BUILD=yes
USE_RC_SUBR=	postfix.sh

OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}${PKGNAMESUFFIX}/options
OPTIONS=	PCRE		"Perl Compatible Regular Expressions" 			on \
		SASL2		"Cyrus SASLv2 (Simple Auth. and Sec. Layer)"		off \
		DOVECOT		"Dovecot SASL authentication method"			off \
		SASLKRB		"If your SASL req. Kerberos select this option"		off \
		SASLKRB5	"If your SASL req. Kerberos5 select this option"	off \
		SASLKMIT	"If your SASL req. MIT Kerberos5 select this option"	off \
		TLS		"Enable SSL and TLS support"				off \
		BDB		"Berkeley DB (choose version with WITH_BDB_VER)"	off \
		MYSQL		"MySQL maps (choose version with WITH_MYSQL_VER)"	off \
		PGSQL		"PostgreSQL maps (choose with DEFAULT_PGSQL_VER)"	off \
		OPENLDAP	"OpenLDAP maps (choose ver. with WITH_OPENLDAP_VER)"	off \
		CDB		"CDB maps lookups"					off \
		NIS		"NIS maps lookups"					off \
		TEST		"SMTP/LMTP test server and generator"			off

MAN1=	postalias.1 postcat.1 postconf.1 postdrop.1 postfix.1 postkick.1 \
	postlock.1 postlog.1 postmap.1 postmulti.1 postqueue.1 postsuper.1 \
	sendmail.1 qshape.1

MAN5=	access.5 aliases.5 bounce.5 canonical.5 cidr_table.5 generic.5 \
	header_checks.5 ldap_table.5 master.5 mysql_table.5 nisplus_table.5 \
	pcre_table.5 pgsql_table.5 postconf.5 postfix-wrapper.5 regexp_table.5 \
	relocated.5 tcp_table.5 transport.5 virtual.5

MAN8=	anvil.8 bounce.8 cleanup.8 discard.8 dnsblog.8 error.8 flush.8 local.8 master.8 \
	oqmgr.8 pickup.8 pipe.8 postscreen.8 proxymap.8 qmgr.8 qmqpd.8 scache.8 showq.8 \
	smtp.8 smtpd.8 spawn.8 tlsmgr.8 trivial-rewrite.8 verify.8 virtual.8

MLINKS=	sendmail.1 mailq.1 \
	sendmail.1 newaliases.1 \
	header_checks.5 body_checks.5 \
	bounce.8 defer.8 \
	bounce.8 trace.8 \
	smtp.8 lmtp.8

CONF1=	access aliases canonical generic header_checks main.cf master.cf \
	relocated transport virtual

.if !defined(DEBUG)
MAKEFILEFLAGS+=	DEBUG=
.endif

MAKEFILEFLAGS+=	CC="${CC}" OPT="${CFLAGS}"

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}"

.include <bsd.port.pre.mk>

# Default requirement for postfix rc script
_REQUIRE=	LOGIN cleanvar

.if defined(WITH_PCRE)
LIB_DEPENDS+=		pcre.0:${PORTSDIR}/devel/pcre
POSTFIX_CCARGS+=	-DHAS_PCRE -I${LOCALBASE}/include
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib -lpcre
.else
POSTFIX_CCARGS+=	-DNO_PCRE
.endif

.if defined(WITH_SASL2)
LIB_DEPENDS+=		sasl2.2:${PORTSDIR}/security/cyrus-sasl2
POSTFIX_CCARGS+=	-DUSE_SASL_AUTH -DUSE_CYRUS_SASL -I${LOCALBASE}/include -I${LOCALBASE}/include/sasl
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib -lsasl2 -lpam -lcrypt
.endif

.if defined(WITH_DOVECOT)
RUN_DEPENDS+=		dovecot:${PORTSDIR}/mail/dovecot
POSTFIX_CCARGS+=	-DUSE_SASL_AUTH -DDEF_SERVER_SASL_TYPE=\\\"dovecot\\\"
.endif

.if defined(WITH_SASLKRB)
.if defined(WITH_SASLKRB5) || defined(WITH_SASLKMIT)
BROKEN=			Select only one SASL Kerberos option
.endif
POSTFIX_AUXLIBS+=	-lkrb -lcrypto -lcom_err
.endif

.if defined(WITH_SASLKRB5)
.if defined(WITH_SASLKRB) || defined(WITH_SASLKMIT)
BROKEN=			Select only one SASL Kerberos option
.endif
.if ${OSVERSION} >= 800037
KRB5_EXTR=		-lhx509
.endif
POSTFIX_AUXLIBS+=	-lkrb5 ${KRB5_EXTR} -lcrypto -lcrypt -lcom_err -lasn1 -lroken
.endif

.if defined(WITH_SASLKMIT)
.if defined(WITH_SASLKRB) || defined(WITH_SASLKRB5)
BROKEN=			Select only one SASL Kerberos option
.endif
LIB_DEPENDS+=		krb5.3:${PORTSDIR}/security/krb5
POSTFIX_AUXLIBS+=	-Wl,--rpath,$${KRB5_HOME:-${LOCALBASE}}/lib -lkrb5 -lcrypto -lcrypt -lcom_err
.endif

.if defined(WITH_TLS)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
POSTFIX_CCARGS+=	-DUSE_TLS -I${OPENSSLINC}
POSTFIX_AUXLIBS+=	-L${OPENSSLLIB} ${LDFLAGS} -lssl -lcrypto
.endif

.if defined(WITH_BDB)
USE_BDB=		yes
POSTFIX_CCARGS+=	-I${BDB_INCLUDE_DIR}
POSTFIX_AUXLIBS+=	-L${BDB_LIB_DIR} -l${BDB_LIB_NAME}
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
POSTFIX_CCARGS+=	-DHAS_MYSQL -I${LOCALBASE}/include/mysql
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib/mysql -lmysqlclient -lz -lcrypt -lm
_REQUIRE+=		mysql
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=		yes
POSTFIX_CCARGS+=	-DHAS_PGSQL -I${LOCALBASE}/include -I${LOCALBASE}/pgsql/include
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/pgsql/lib -lpq -lcrypt
_REQUIRE+=		postgresql
.endif

.if defined(WITH_OPENLDAP)
USE_OPENLDAP=		yes
.if defined(WITH_OPENLDAP_VER)
WANT_OPENLDAP_VER=	${WITH_OPENLDAP_VER}
.endif
POSTFIX_CCARGS+=	-DHAS_LDAP -I${LOCALBASE}/include
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib -lldap -llber
_REQUIRE+=		slapd
.endif

.if defined(WITH_CDB)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libcdb.a:${PORTSDIR}/databases/tinycdb
POSTFIX_CCARGS+=	-DHAS_CDB -I${LOCALBASE}/include
POSTFIX_AUXLIBS+=	-L${LOCALBASE}/lib -lcdb
.endif

.if defined(WITH_NIS)
POSTFIX_CCARGS+=	-DHAS_NIS
_REQUIRE+=		ypserv
.endif

.if defined(WITH_TEST)
BINTEST=	qmqp-sink qmqp-source smtp-sink smtp-source
MANTEST=	qmqp-sink.1 qmqp-source.1 smtp-sink.1 smtp-source.1
MAN1+=		${MANTEST}
PLIST_SUB+=	SUB_TEST=""
.else
PLIST_SUB+=	SUB_TEST="@comment "
.endif

.if defined(NOPORTDOCS)
READMEDIR=no
.else
READMEDIR=${PREFIX}/share/doc/postfix
.endif

SUB_LIST+=	REQUIRE="${_REQUIRE}"

pre-patch:
.if defined(WITH_SASL2) && !defined(WITH_MYSQL) && exists(${LOCALBASE}/lib/libsasl2.a)
	@if /usr/bin/nm ${LOCALBASE}/lib/libsasl2.a | ${GREP} -wq "mysql_init"; then \
		${ECHO_MSG}; \
		${ECHO_MSG} "Your SASL2 library it's compiled with MYSQL"; \
		${ECHO_MSG} "If you use MYSQL in ${PORTNAME} consider CTRL+C and"; \
		${ECHO_MSG} "select MYSQL OPTION in config menu."; \
		${ECHO_MSG} "# make clean config"; \
		${ECHO_MSG}; \
		sleep 5; \
	fi
.endif

	@${ECHO} "<HTML><BODY>See <A HREF="header_checks.5.html">header_checks.5.html</A></BODY></HTML>" \
		> ${WRKSRC}/html/body_checks.5.html
	@${FIND} -P ${WRKSRC}/man -type f | ${XARGS} \
		${REINPLACE_CMD} -e "s|/etc/postfix|${PREFIX}/etc/postfix|g"
	@${FIND} -P ${WRKSRC}/README_FILES -type f | ${XARGS} \
		${REINPLACE_CMD} -e "s|/etc/postfix|${PREFIX}/etc/postfix|g"
	@${FIND} -P ${WRKSRC}/conf -type f | ${XARGS} \
		${REINPLACE_CMD} -e "s|/etc/postfix|${PREFIX}/etc/postfix|g"

post-patch:
# All files modified with ${FILESDIR}/patch-* to use !!PREFIX!! need REINPLACE. Put below.
	@${REINPLACE_CMD} -e "s,!!PREFIX!!,${PREFIX},g" \
		${WRKSRC}/conf/main.cf ${WRKSRC}/src/global/mail_params.h
	@${REINPLACE_CMD} -e "s|perl|${PERL}|" ${WRKSRC}/src/bounce/Makefile.in

do-configure:
	(cd ${WRKSRC} && ${MAKE} -f Makefile.init makefiles ${MAKEFILEFLAGS} \
	CCARGS="${POSTFIX_CCARGS}" AUXLIBS="${POSTFIX_AUXLIBS}" && \
	${ECHO} "all: default" >> Makefile)

pre-su-install:
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	cd ${WRKSRC}; ${SH} postfix-install -non-interactive install_root=/ tempdir=/tmp \
		config_directory=${PREFIX}/etc/postfix \
		data_directory=/var/db/postfix \
		daemon_directory=${PREFIX}/libexec/postfix \
		command_directory=${PREFIX}/sbin \
		queue_directory=/var/spool/postfix \
		sendmail_path=${PREFIX}/sbin/sendmail \
		newaliases_path=${PREFIX}/bin/newaliases \
		mailq_path=${PREFIX}/bin/mailq \
		mail_owner=postfix \
		setgid_group=maildrop \
		manpage_directory=${MANPREFIX}/man \
		sample_directory=${PREFIX}/etc/postfix \
		readme_directory=${READMEDIR}

	${INSTALL_SCRIPT} ${WRKSRC}/auxiliary/rmail/rmail ${PREFIX}/bin/rmail

	${INSTALL_SCRIPT} ${WRKSRC}/auxiliary/qshape/qshape.pl ${PREFIX}/bin/qshape
	${INSTALL_MAN} ${WRKSRC}/man/man1/qshape.1 ${MANPREFIX}/man/man1

.for f in ${BINTEST}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} ${PREFIX}/bin
.endfor
.for f in ${MANTEST}
	${INSTALL_MAN} ${WRKSRC}/man/man1/${f} ${MANPREFIX}/man/man1
.endfor

	@${MKDIR} ${PREFIX}/etc/postfix/dist
.for f in ${CONF1}
	${INSTALL_DATA} ${WRKSRC}/conf/${f} ${PREFIX}/etc/postfix/dist
.endfor

.if !defined(NOPORTDOCS)
	${INSTALL} -d -o ${DOCOWN} -g ${DOCGRP} -m 555 ${DOCSDIR}
	@cd ${WRKSRC}/html && ${INSTALL_DATA} *.html *.jpg *.png ${DOCSDIR} && \
		${ECHO_MSG} "Installed HTML documentation in ${DOCSDIR}"
.endif

post-install:
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
# Fix compressed man pages
	@${REINPLACE_CMD} -E -e "s|(man[158]/.*.[158]):|\1.gz:|g" ${PREFIX}/libexec/postfix/postfix-files
	@${RM} -f ${PREFIX}/libexec/postfix/postfix-files.bak
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
