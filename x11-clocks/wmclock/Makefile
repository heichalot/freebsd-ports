# New ports collection makefile for:	wmclock
# Date created:				05 May 2001
# Whom:					Per Otterstr=F6m <pelle@fukt.bth.se>
#
# $FreeBSD$
#

PORTNAME=	wmclock
PORTVERSION=	1.0.12.2
PORTREVISION=	3
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://www.jmknoble.net/WindowMaker/wmclock/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

PATCH_SITES=	http://www.jmknoble.net/WindowMaker/wmclock/
PATCHFILES=	wmclock_nopolling.patch.gz

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A dockable clock applet for Window Maker

USE_IMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_XORG=	xpm
MAN1=		wmclock.1
PLIST_FILES=	bin/wmclock

HAS_CONFIGURE=	yes

.include <bsd.port.mk>
