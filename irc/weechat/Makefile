# New ports collection makefile for:    weechat
# Date created:                         2003-03-07
# Whom:                                 clement
#
# $FreeBSD$
#

PORTNAME=	weechat
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://weechat.org/files/src/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A lightweight and user friendly ncurse based IRC client

USE_ICONV=	yes
USE_LDCONFIG=	yes
USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
WANT_PERL=	yes

OPTIONS=	RUBY		"Ruby scripting support."	Off	\
		PYTHON		"Python scripting support."	Off	\
		PERL		"Perl scripting support."	Off	\
		TCL		"TCL scripting support."	Off	\
		LUA		"Lua scripting support."	Off	\
		CHARSET		"Charset support."		On	\
		DEBUG		"Debugging."			Off	\
		ASPELL		"Spell checking."		Off	\
		GNUTLS		"GNU TLS."			Off	\
		NLS		"NLS support."			On	\
		DOCUMENTATION	"Build documentation."		Off

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
CMAKE_BUILD_TYPE=	Debug
.endif

.if defined(WITHOUT_CHARSET)
CMAKE_ARGS+=	-DDISABLE_CHARSET=yes
PLIST_SUB+=	CHARSET="@comment "
.else
PLIST_SUB+=	CHARSET=""
.endif

.if defined(WITHOUT_NLS)
CMAKE_ARGS+=	-DDISABLE_NLS=yes
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.if defined(WITH_ASPELL)
BUILD_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
PLIST_SUB+=	ASPELL=""
.else
CMAKE_ARGS+=	-DDISABLE_ASPELL=yes
PLIST_SUB+=	ASPELL="@comment "
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON=""
.else
CMAKE_ARGS+=	-DDISABLE_PYTHON=yes
PLIST_SUB+=	PYTHON="@comment "
.endif

.if defined(WITH_RUBY)
.include "${PORTSDIR}/Mk/bsd.ruby.mk"
USE_RUBY=	yes
PLIST_SUB+=	RUBY=""
.else
CMAKE_ARGS+=	-DDISABLE_RUBY=yes
PLIST_SUB+=	RUBY="@comment "
.endif

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls.40:${PORTSDIR}/security/gnutls
.else
CMAKE_ARGS+=	-DDISABLE_GNUTLS=yes
.endif

.if defined(WITH_PERL)
USE_PERL5=	yes
PLIST_SUB+=	PERL=""
.else
CMAKE_ARGS+=	-DDISABLE_PERL=yes
PLIST_SUB+=	PERL="@comment "
.endif

.if defined(WITH_TCL)
USE_TCL=	83+
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
PLIST_SUB+=	TCL=""
.else
CMAKE_ARGS+=	-DDISABLE_TCL=yes
PLIST_SUB+=	TCL="@comment "
.endif

.if defined(WITH_LUA)
USE_LUA=	5.0+
PLIST_SUB+=	LUA=""
.else
CMAKE_ARGS+=	-DDISABLE_LUA=yes
PLIST_SUB+=	LUA="@comment "
.endif

.if defined(WITH_DOCUMENTATION)
BUILD_DEPENDS+=	asciidoc:${PORTSDIR}/textproc/asciidoc
BUILD_DEPENDS+=	source-highlight:${PORTSDIR}/textproc/source-highlight
PLIST_SUB+=	DOCUMENTATION=""
.else
CMAKE_ARGS+=	-DDISABLE_DOC=yes
PLIST_SUB+=	DOCUMENTATION="@comment "
.endif

MAN1=	weechat-curses.1

post-patch:
	@${REINPLACE_CMD} -e 's|$${LIBDIR}/../pkgconfig|$${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|INSTALL|#INSTALL|' ${WRKSRC}/doc/CMakeLists.txt

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/weechat-curses.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
