# New ports collection makefile for:	xf86-video-vmware
# Date Created:				17 Feb 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xf86-video-vmware
PORTVERSION=	10.16.9
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org vmware display driver

XORG_CAT=	driver
USE_XORG=	xextproto xineramaproto videoproto

MAN4=		vmware.4x

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
USE_GCC=	4.2+
.endif

.include <bsd.port.post.mk>
