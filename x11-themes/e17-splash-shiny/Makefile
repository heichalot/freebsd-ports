# New ports collection makefile for:	e17-splash-shiny
# Date created:		4 Aug 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	shiny
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	x11-themes
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		${MASTER_SITE_GET_E}
MASTER_SITE_SUBDIR=	Themes/E17_-_Startup
PKGNAMEPREFIX=	e17-splash-
DISTNAME=	init_shiny_reflection
EXTRACT_SUFX=	.edj

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Shiny splash screen for e17 window manager

RUN_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	share/enlightenment/data/init/${DISTNAME}${EXTRACT_SUFX}

do-extract:
	${MKDIR} ${WRKDIR}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}

do-install:
	${MKDIR} ${PREFIX}/share/enlightenment/data/init
	${INSTALL_DATA} ${WRKSRC}/${DISTFILES} \
		${PREFIX}/share/enlightenment/data/init

.include <bsd.port.mk>
