# New ports collection makefile for:	xmms-speex
# Date created:				3 Oct 2002
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-speex
PORTVERSION=	0.9.1
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://jzb.rapanden.dk/pub/
DISTNAME=	speex-xmms-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMMS input plugin to play speex files

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS=	speex.1:${PORTSDIR}/audio/speex
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Input/libspeex.so
WRKSRC=		${WRKDIR}/speex-xmms

USE_XORG=	x11
USE_GNOME=	gtk12
USE_GMAKE=	yes

MAKE_FLAGS=	CC="${CC}" CFLAGS="${CFLAGS} -fPIC"

post-patch:
	@${REINPLACE_CMD} -Ee 's|([(][(]int\*[)] packet[)])\+\+|packet=\1+1|'\
		${WRKSRC}/speexutil.c

.include <bsd.port.mk>
