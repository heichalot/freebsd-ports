# New ports collection makefile for:	tuxpaint
# Date created:				14 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	tuxpaint
PORTVERSION=	0.9.20
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Drawing program designed for young children

LIB_DEPENDS=	paper.2:${PORTSDIR}/print/libpaper \
		rsvg-2:${PORTSDIR}/graphics/librsvg2

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_SDL=	image mixer sdl ttf pango

MAN1=		tp-magic-config.1 tuxpaint.1 tuxpaint-import.1
MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
			${WRKSRC}/${MAKEFILE} \
			${WRKSRC}/src/tuxpaint-import.sh \
			${WRKSRC}/src/tp_magic_api.h.in \
			${WRKSRC}/src/tuxpaint.conf \
			${WRKSRC}/hildon/tuxpaint.conf
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|install-doc\([^:]\)|\1|' ${WRKSRC}/${MAKEFILE}
.endif

.include <bsd.port.mk>
