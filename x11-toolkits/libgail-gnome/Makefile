# New ports collection makefile for:   libgail-gnome
# Date Created:			12 April 2002
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/libgail-gnome/Makefile,v 1.24 2010/04/01 13:23:49 kwm Exp $
#

PORTNAME=	libgail-gnome
PORTVERSION=	1.20.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An implementation of the ATK interfaces for GNOME widgets

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomeprefix gnomehack gnomepanel libgnomeui atspi
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
PLIST_FILES=	lib/gtk-2.0/modules/libgail-gnome.la \
		lib/gtk-2.0/modules/libgail-gnome.so \
		libdata/pkgconfig/libgail-gnome.pc

.include <bsd.port.mk>
