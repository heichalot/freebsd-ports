# New ports collection makefile for:	xfsm
# Date Created:				24 Nov 1997
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfsm
PORTVERSION=	1.99
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/status/xstatus
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X File System Monitor

USE_IMAKE=	yes
USE_XORG=	xbitmaps x11 xext
MAKE_ARGS=	CC="${CC}" CCOPTIONS="-DFreeBSD"
MAN1=		xfsm.1
PLIST_FILES=	bin/xfsm

.include <bsd.port.mk>
