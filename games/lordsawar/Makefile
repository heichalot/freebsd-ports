# New ports collection makefile for:   lordsawar
# Date created:                 12 February 2008
# Whom:                         spam@rm-rf.kiev.ua
#
# $FreeBSD$
#

PORTNAME=	lordsawar
PORTVERSION=	0.1.5
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	spam@rm-rf.kiev.ua
COMMENT=	A Warlords II clone

LIB_DEPENDS=	glademm-2.4:${PORTSDIR}/devel/libglademm24 \
		gnet-2.0:${PORTSDIR}/net/gnet2 \
		uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid

BUILD_DEPENDS=	bjam:${PORTSDIR}/devel/boost-jam \
		${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	intltool
USE_SDL=	sdl image

OPTIONS=	SOUND	"Enable sound"	on

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=--disable-nls \
		--with-boost-includedir=${LOCALBASE}/include/

.if !defined(WITHOUT_SOUND)
USE_SDL+=	mixer
.else
CONFIGURE_ARGS+=--disable-sound
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="${PTHREAD_LIBS}"

.include <bsd.port.post.mk>
