# ex:ts=8
# Ports collection makefile for:	mcron
# Date created:			Dec 17, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mcron
PORTVERSION=	1.0.4
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	mcron

MAINTAINER=	stefan@fh-mainz.de
COMMENT=	A 100% compatible replacement for Vixie cron

BUILD_DEPENDS=	guile>=1.8.6:${PORTSDIR}/lang/guile
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
MAKEFILE=	makefile

INFO=		mcron

.include <bsd.port.mk>
