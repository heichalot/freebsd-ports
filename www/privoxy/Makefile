# New ports collection makefile for:	privoxy
# Date created:				21 November 2002
# Whom:					John von Essen
#
# $FreeBSD$
#

PORTNAME=	privoxy
PORTVERSION=	3.0.16
PORTREVISION=	1
CATEGORIES=	www ipv6
MASTER_SITES=	SF/ijbswa/Sources/${PORTVERSION}%20%28stable%29
DISTNAME=	privoxy-${PORTVERSION}-stable-src

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Privoxy is a web proxy with advanced filtering capabilities

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

WRKSRC=		${WRKDIR}/privoxy-${PORTVERSION}-stable

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262

USE_RC_SUBR=	privoxy
SUB_FILES=	pkg-message

MAKEFILE=	GNUmakefile

# privoxy-devel is the development release available at the Privoxy website.
# It's not (yet) part of the FreeBSD ports collection.
CONFLICTS=	privoxy-devel-[0-9]*

MAN1=		privoxy.1

CONFIGURE_ENV=	LDFLAGS=-L${LOCALBASE}/lib \
		CPPFLAGS=-I${LOCALBASE}/include/

OPTIONS=	ACCEPT_FILTER "Enable support for accf_http(9)" Off \
		DEBUG "Build with debugging symbols" Off \
		EDITOR "Allow to enable the webbased action editor" On \
		FORCE "Allows to optionally bypass blocks" On \
		PRIVOXY_TOOLS "Install Privoxy-Log-Parser, uagen etc." Off \
		TOGGLE "Support for remote toggling" On

.include <bsd.port.pre.mk>

.if defined(WITH_ACCEPT_FILTER)
CONFIGURE_ARGS+=	 --enable-accept-filter
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--with-debug
.endif

.if defined(WITHOUT_EDITOR)
CONFIGURE_ARGS+=	--disable-editor
.endif

.if defined(WITHOUT_FORCE)
CONFIGURE_ARGS+=	--disable-force
.endif

.if defined(WITHOUT_TOGGLE)
CONFIGURE_ARGS+=	--disable-toggle
.endif

.if defined(WITH_PRIVOXY_TOOLS)
USE_PERL5_RUN=	yes
RUN_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
PLIST_SUB+=	PRIVOXY_TOOLS=""
.else
PLIST_SUB+=	PRIVOXY_TOOLS="@comment "
.endif

post-patch:
	${REINPLACE_CMD} \
		-e 's,^\(confdir\) \.,\1 ${PREFIX}/etc/privoxy,' \
		-e 's,^\(logdir\) \.,\1 /var/log/privoxy,' \
		-e 's,^\(actionsfile user\),#\1,' \
	${WRKSRC}/config
.if !defined(NOPORTDOCS)
	${REINPLACE_CMD} \
		-e 's,^#\(user-manual\) http://www.privoxy.org/user-manual/,\1 ${DOCSDIR}/user-manual,' \
	${WRKSRC}/config
.endif
	${REINPLACE_CMD} \
		-e 's,\(/etc/privoxy\),${PREFIX}\1,' ${WRKSRC}/tools/uagen.pl
# Effectivly apply revision 1.208 to fix a regression test.
	${REINPLACE_CMD} \
		-e 's,\(-fast-redirects -hide-refer\),\1r,' ${WRKSRC}/default.action.master

pre-configure:
	@cd ${WRKSRC}; ${AUTOHEADER}

pre-su-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${MKDIR} ${PREFIX}/etc/privoxy/templates
	@${INSTALL_PROGRAM} ${WRKSRC}/privoxy ${PREFIX}/sbin
	@${INSTALL_DATA} ${WRKSRC}/templates/[a-z]* ${PREFIX}/etc/privoxy/templates
.if defined(WITH_PRIVOXY_TOOLS)
.for privoxy_tool in privoxy-log-parser.pl privoxy-regression-test.pl uagen.pl
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/${privoxy_tool} ${PREFIX}/bin
.endfor
.endif
.for defaultfile in default.action default.filter regression-tests.action
	@${INSTALL_DATA} ${WRKSRC}/${defaultfile} ${PREFIX}/etc/privoxy
	@${CHOWN} privoxy:privoxy ${PREFIX}/etc/privoxy/${defaultfile}
	@${CHMOD} 0444 ${PREFIX}/etc/privoxy/${defaultfile}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
.for examplefile in config match-all.action trust user.action
	@${INSTALL_DATA} ${WRKSRC}/${examplefile} ${EXAMPLESDIR}/
	@${CHOWN} privoxy:privoxy ${EXAMPLESDIR}/${examplefile}
	@${CHMOD} 0640 ${EXAMPLESDIR}/${examplefile}
.endfor
	@${INSTALL_MAN}  ${WRKSRC}/privoxy.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/user-manual
	@${INSTALL_DATA} ${WRKSRC}/doc/webserver/user-manual/[a-z]* ${DOCSDIR}/user-manual
	@${INSTALL_DATA} ${WRKSRC}/doc/webserver/p_doc.css ${DOCSDIR}/user-manual
.endif

post-install:
	@${MKDIR} /var/run/privoxy
	@${CHOWN} privoxy:privoxy /var/run/privoxy
	@${CHMOD} 0750 /var/run/privoxy
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
