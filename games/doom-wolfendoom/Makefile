# New ports collection makefile for:	doom-wolfendoom
# Date created:				21 Sep 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	wolfendoom
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://www.ijs.si/~lesi/distfiles/doom/
PKGNAMEPREFIX=	${DMPKGNAMEPREFIX}
DISTNAME=	${PORTNAME}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Wolfenstein 3D levels ported to Doom II

USE_BZIP2=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${DMDIR}/${PORTNAME}

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.pre.mk>

do-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WRKDIR}/${PORTNAME}
	${FIND} ${WRKDIR}/${PORTNAME} ! -type d -exec ${CHMOD} 0644 {} \;
	${FIND} ${WRKDIR}/${PORTNAME} -type d -exec ${CHMOD} 0755 {} \;
	${MKDIR} ${DATADIR}
	${TAR} -cf - -C ${WRKDIR}/${PORTNAME} . | ${TAR} -xpvf - -C ${DATADIR}

.include <bsd.port.post.mk>
