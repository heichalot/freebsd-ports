# New ports collection makefile for:   pluxml
# Date created:                14 December 2007
# Whom:                        Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	pluxml
PORTVERSION=	4
CATEGORIES=	french www
MASTER_SITES=	http://download.pluxml.org/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-blog-beta${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small weblog in php and xml

USE_ZIP=	yes
USE_PHP=	xml pcre
WANT_PHP_WEB=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGMESSAGE=	${WRKDIR}/pkg-message

NO_BUILD=	yes

SUB_FILES=	pkg-message pkg-deinstall
SUB_LIST=	WWWDIR=${WWWDIR} \
		PORTNAME=${PORTNAME}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

do-install:
	${MKDIR} ${WWWDIR}
	${CP} -R ${WRKSRC} ${WWWDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
