# New ports collection makefile for:	wmapm
# Date created:		99/07/02
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmapm
PORTVERSION=	3.1
PORTREVISION=	2
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://dockapps.org/files/18/25/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Laptop battery status display for WindowMaker

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/${DISTNAME}/wmapm

USE_XORG=	xpm

MAN1=		wmapm.1
PLIST_FILES=	bin/wmapm

BINMODE=	2755
BINGRP=		operator

.include <bsd.port.mk>
