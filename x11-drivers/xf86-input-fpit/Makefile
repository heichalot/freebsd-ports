# New ports collection makefile for:	xf86-input-fpit
# Date Created:				17 Feb 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xf86-input-fpit
PORTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org fpit input driver

BROKEN=		does not compile

XORG_CAT=	driver
USE_XORG=	xrandr

MAN4=		fpit.4x

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
USE_GCC=	4.2+
.endif

.include <bsd.port.post.mk>
