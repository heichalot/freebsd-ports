# New ports collection makefile for:		xdelta
# Date created:    01 April 2007
# Whom:            Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	xdelta
PORTVERSION=	3.0u
CATEGORIES=	misc devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open-source binary diff, VCDIFF/RFC 3284 delta compression

ALL_TARGET=	xdelta3
USE_GMAKE=	yes
PLIST_FILES=	bin/xdelta3

post-patch:
	${REINPLACE_CMD} -E -e 's/^(CFLAGS)=/\1+=/' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdelta3 ${PREFIX}/bin/

.include <bsd.port.mk>
