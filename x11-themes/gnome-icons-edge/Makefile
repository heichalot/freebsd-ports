# New ports collection makefile for:	Edge GNOME Iconset
# Date created:				26 March, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

# Port logic gratuitously stolen from lioux's logic in
# x11-themes/kde-icons-noia. If it's not defined here
# and you think it should be, check
# x11-themes/gnome-icons/bsd.gnome-icons.mk for it.

PORTNAME=	edge
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	x11-themes gnome
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	adamw/edge
DISTNAME=	${PORTNAME}-icons-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sleek white icon theme for GNOME

RESTRICTED=	${REASON}

WRKSRC=		${WRKDIR}/Edge-Icons-${PORTVERSION}

.include "${.CURDIR}/../gnome-icons/bsd.gnome-icons.mk"
.include <bsd.port.mk>
