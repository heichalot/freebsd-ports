# New ports collection makefile for:	xtar
# Date created:		31 Jul 1996
# Whom:			shanee@augusta.de
#
# $FreeBSD$
#

PORTNAME=	xtar
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities

MAINTAINER=	ports@FreeBSD.org
COMMENT=	View and manipulate contents of a tar file

USE_MOTIF=	yes
USE_IMAKE=	yes
USE_XORG=	ice sm x11 xext xp xt
MAKE_ARGS=	XMLIB="${MOTIFLIB}"
MAN1=		xtar.1
PLIST_FILES=	bin/xtar lib/X11/xtar/xtar.doc lib/X11/app-defaults/XTar
PLIST_DIRS=	lib/X11/xtar

.include <bsd.port.mk>
