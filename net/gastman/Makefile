# New ports collection makefile for:	gastman
# Date created:		2005-07-11
# Whom:			Filippo Natali <filippo.natali@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gastman
PORTVERSION=	1.0.r1
PORTREVISION=	7
CATEGORIES=	net
MASTER_SITES=	http://ftp.digium.com/pub/gastman/
DISTNAME=	${PORTNAME}-1.0-RC1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical Manager interface for Asterisk

USE_GNOME=	gtk20
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CFLAGS=|CFLAGS= -I${WRKSRC}/include ${CFLAGS} |g; \
		 s|$$(INSTALL_PREFIX)/usr/sbin|${PREFIX}/bin|g; \
		 s|$$(INSTALL_PREFIX)/usr/share|${PREFIX}/share|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		 's|ICON_PATH "/usr/share/gastman/icons"|ICON_PATH "${PREFIX}/share/${PORTNAME}/icons"|g' ${WRKSRC}/gui.c

.include <bsd.port.mk>
