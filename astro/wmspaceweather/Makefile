# New ports collection makefile for:	wmSpaceWeather
# Date created:		16 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	wmspaceweather
PORTVERSION=	1.04
PORTREVISION=	3
CATEGORIES=	astro windowmaker
MASTER_SITES=	http://dockapps.org/files/15/22/
DISTNAME=	wmSpaceWeather-${PORTVERSION}

MAINTAINER=	xride@FreeBSD.org
COMMENT=	A DockApp that shows the weather at geosynchronous orbit

WRKSRC=		${WRKDIR}/${DISTNAME}/wmSpaceWeather

# distfile is actually just a tar with suffix .tar.gz:
EXTRACT_CMD=	${CAT}
EXTRACT_BEFORE_ARGS=

USE_XORG=	x11 xext xpm
ALL_TARGET=	clean all
MAKE_JOBS_UNSAFE=	yes

MAN1=	wmSpaceWeather.1

PLIST_FILES=	bin/GetKp bin/wmSpaceWeather

.include <bsd.port.mk>
