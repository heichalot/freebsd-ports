# New ports collection makefile for: sattrack
# Date created:                      6 Apr 1996
# Whom:                              Brent J. Nordquist <bjn@visi.com>
#
# $FreeBSD$
#

PORTNAME=	sattrack
PORTVERSION=	3.1.6
PORTREVISION=	2
CATEGORIES=	astro hamradio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real-time satellite tracking and orbit propagation program

USE_XORG=	xt
WRKSRC=		${WRKDIR}/SatTrack-${PORTVERSION}/src

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
