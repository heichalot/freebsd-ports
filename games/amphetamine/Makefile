# New ports collection makefile for:	amphetamine
# Date created:				6 March 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	amphetamine
PORTVERSION=	0.8.10
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://homepage.hispeed.ch/loehrer/amph/files/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-data-${DATAVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 2D - Jump'n'run shooter

USE_BZIP2=	yes
USE_XORG=	xpm
USE_SDL=	sdl
USE_GMAKE=	yes

DATAVERSION=	0.8.6

post-install:
	@cd ${WRKDIR}/amph && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/amph

.include <bsd.port.mk>
