# New ports collection makefile for:	(wm)miniCHESS
# Date created:		24 Sep 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	wmminichess
PORTVERSION=	0.8
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.insanum.com/miniCHESS/
DISTNAME=	miniCHESS-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window Maker chess dockapp game

RUN_DEPENDS=	${LOCALBASE}/bin/gnuchess:${PORTSDIR}/games/gnuchess

USE_GMAKE=	YES
USE_XORG=	xpm
MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		LOCAL="${LOCALBASE}" MKDIR="${MKDIR}" \
		INSTALL_DATA="${INSTALL_DATA}"

.include <bsd.port.mk>
