# New ports collection makefile for:	xf86-video-intel
# Date Created:				28 May 2007
# Whom:					lesi@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xf86-video-intel29
PORTVERSION=	2.9.1
CATEGORIES=	x11-drivers
DISTNAME=	xf86-video-intel-${PORTVERSION}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Driver for Intel integrated graphics chipsets

CONFLICTS=	xf86-video-i810-[0-9]* xf86-video-intel-[0-9]*

ONLY_FOR_ARCHS=	amd64 i386
USE_GL=		gl

XORG_CAT=	driver
USE_XORG=	xvmc xineramaproto xextproto x11 xf86driproto glproto
MAN4=		intel.4x

IGNORE=		we have to wait of GEM support to get ironlake chips to work

.include <bsd.port.mk>
