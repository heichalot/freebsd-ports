# New ports collection makefile for:	gmpc-magnatune
# Date created:		September 14 2007
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gmpc-magnatune
PORTVERSION=	0.19.0
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION}/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A Autoplaylist plugin for gmpc

LIB_DEPENDS=	mpd:${PORTSDIR}/audio/libmpd \
		curl.6:${PORTSDIR}/ftp/curl \
		sqlite3:${PORTSDIR}/databases/sqlite3
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:${PORTSDIR}/audio/gmpc
RUN_DEPENDS=	gmpc:${PORTSDIR}/audio/gmpc

GNU_CONFIGURE=	yes
USE_XORG=	x11
USE_GMAKE=	yes
USE_GNOME=	gnomehack intltool
USE_LDCONFIG=	yes

.include <bsd.port.mk>
