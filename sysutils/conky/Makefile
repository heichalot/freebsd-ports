# New ports collection makefile for:	conky
# Date created:				2005-08-27
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	conky
PORTVERSION=	1.7.2
PORTREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	ntarmos@cs.uoi.gr
COMMENT=	An advanced, highly configurable system monitor for X

CONFLICTS?=	conky-awesome-[0-9]*
SLAVEDIRS=	sysutils/conky-awesome

USE_ICONV=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_XORG?=	x11 xext xdamage
USE_GNOME?=	pkgconfig
USE_ICONV=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=	--disable-portmon \
			--disable-hddtemp \
			--disable-iostats
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

MAN1=		conky.1
PLIST_FILES=	bin/conky
PORTEXAMPLES=	conkyrc.sample
PORTDOCS=	README AUTHORS ChangeLog TODO NEWS \
		docs.html variables.html config_settings.html

OPTIONS+=	APCUPSD "Enable APCUPSD support" Off \
		AUDACIOUS "Enable Audacious support" Off \
		BMPX "Enable BMPX support" Off \
		MPD "Enable MPD support" Off \
		RSS "Enable RSS support" Off \
		METAR "Enable METAR Weather support" Off \
		XOAP "Enable XOAP Weather support" Off \
		XMMS2 "Enable XMMS2 support" Off

.if !empty(USE_XORG)
OPTIONS+=	DOUBLE_BUFFER "Enable double buffering" On \
		IMLIB2 "Enable Imlib2 support" Off \
		LUA "Enable Lua support" Off \
		LUA_CAIRO "Enable Lua-Cairo binding (impl. Lua)" Off \
		LUA_IMLIB2 "Enable Lua-Imlib2 binding (impl. Lua/Imlib2)" Off \
		XFT "Enable Xft support" Off
.else
OPTIONS+=	LUA "Enable Lua support" Off
.endif

.include <bsd.port.pre.mk>

.if empty(USE_XORG)
WITHOUT_DOUBLE_BUFFER=	On
CONFIGURE_ARGS+=	--disable-x11 --disable-own-window
.undef WITH_IMLIB2
.undef WITH_LUA_CAIRO
.undef WITH_LUA_IMLIB2
.undef WITH_XFT
.endif

.if defined(WITH_APCUPSD)
RUN_DEPENDS+=		${LOCALBASE}/sbin/apcupsd:${PORTSDIR}/sysutils/apcupsd
CONFIGURE_ARGS+=	--enable-apcupsd
.else
CONFIGURE_ARGS+=	--disable-apcupsd
.endif

.if defined(WITH_AUDACIOUS)
LIB_DEPENDS+=		audclient.2:${PORTSDIR}/multimedia/audacious
CONFIGURE_ARGS+=	--enable-audacious
.else
CONFIGURE_ARGS+=	--disable-audacious
.endif

.if defined(WITH_BMPX)
BUILD_DEPENDS+=		beep-media-player-2:${PORTSDIR}/multimedia/bmpx
RUN_DEPENDS+=		beep-media-player-2:${PORTSDIR}/multimedia/bmpx
LIB_DEPENDS+=		dbus-1.3:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=	--enable-bmpx
.else
CONFIGURE_ARGS+=	--disable-bmpx
.endif

.if defined(WITH_LUA) || defined(WITH_LUA_CAIRO) || defined(WITH_LUA_IMLIB2)
USE_LUA=		5.1+
CONFIGURE_ARGS+=	--enable-lua
.else
CONFIGURE_ARGS+=	--disable-lua
.endif

.if defined(WITH_LUA_CAIRO)
LIB_DEPENDS+=		cairo.2:${PORTSDIR}/graphics/cairo
BUILD_DEPENDS+=		tolua++-5.1:${PORTSDIR}/lang/tolua++
CONFIGURE_ARGS+=	--enable-lua-cairo
.endif

.if defined(WITH_IMLIB2) || defined(WITH_LUA_IMLIB2)
LIB_DEPENDS+=		Imlib2.5:${PORTSDIR}/graphics/imlib2
CONFIGURE_ARGS+=	--enable-imlib2
.else
CONFIGURE_ARGS+=	--disable-imlib2
.endif

.if defined(WITH_LUA_IMLIB2)
BUILD_DEPENDS+=		tolua++-5.1:${PORTSDIR}/lang/tolua++
CONFIGURE_ARGS+=	--enable-lua-imlib2
.endif

.if defined(WITH_XFT)
LIB_DEPENDS+=		Xft.2:${PORTSDIR}/x11-fonts/libXft
CONFIGURE_ARGS+=	--enable-xft
.else
CONFIGURE_ARGS+=	--disable-xft
.endif

.if defined(WITHOUT_MPD)
CONFIGURE_ARGS+=	--disable-mpd
.endif

.if defined(WITH_RSS)
LIB_DEPENDS+=		curl.6:${PORTSDIR}/ftp/curl \
			xml2.5:${PORTSDIR}/textproc/libxml2
CONFIGURE_ARGS+=	--enable-rss
USE_GNOME+=		glib20
.endif

.if defined(WITH_METAR)
LIB_DEPENDS+=		curl.6:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--enable-weather-metar
.endif

.if defined(WITH_XOAP)
LIB_DEPENDS+=		curl.6:${PORTSDIR}/ftp/curl \
			xml2.5:${PORTSDIR}/textproc/libxml2
CONFIGURE_ARGS+=	--enable-weather-xoap
.endif

.if defined(WITH_XMMS2)
LIB_DEPENDS+=		xmmsclient.5:${PORTSDIR}/audio/xmms2
CONFIGURE_ARGS+=	--enable-xmms2
.else
CONFIGURE_ARGS+=	--disable-xmms2
.endif

.if defined(WITHOUT_DOUBLE_BUFFER)
CONFIGURE_ARGS+=	--disable-double-buffer
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,lua5\.1,lua-5.1,g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,imlib_context_disconnect_display();,,g' \
		${WRKSRC}/src/imlib2.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/conky ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/conky.1 ${PREFIX}/man/man1

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.	if !empty(USE_XORG)
	@${INSTALL_DATA} ${WRKSRC}/data/conky.conf ${EXAMPLESDIR}/conkyrc.sample
.	else
	@${INSTALL_DATA} ${WRKSRC}/data/conky_no_x11.conf ${EXAMPLESDIR}/conkyrc.sample
.	endif
.endif

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README AUTHORS ChangeLog TODO NEWS
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.for i in docs.html variables.html config_settings.html
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
