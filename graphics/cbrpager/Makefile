# ex:ts=8
# Ports collection makefile for:	cbrpager
# Date created:			Oct 28, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cbrpager
PORTVERSION=	0.9.20
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/cbrPager-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A viewer for cbr (comic book archive) files

USE_GNOME=	libgnomeui
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/cbrpager \
		share/locale/es/LC_MESSAGES/cbrpager.mo \
		share/locale/fr/LC_MESSAGES/cbrpager.mo

.include <bsd.port.mk>
