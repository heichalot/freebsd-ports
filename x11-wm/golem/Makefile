# New ports collection makefile for:   golem
# Date created:        11 August 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	golem
PORTVERSION=	0.0.5
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small window manager with themes and plugins

.if defined(WANT_SOUND)
LIB_DEPENDS=	esd.2:${PORTSDIR}/audio/esound
CONFIGURE_ARGS=	--enable-sound
PLIST_SUB+=	NO_SOUND=""
.else
PLIST_SUB+=	NO_SOUND="@comment "
.endif

USE_XORG=	x11 xext xpm
GNU_CONFIGURE=	yes

.if defined(WANT_XINERAMA)
CONFIGURE_ARGS+=	--enable-xinerama
USE_XORG+=	xinerama
.endif

MANCOMPRESSED=	yes
MAN1=		golem.1

.include <bsd.port.mk>
