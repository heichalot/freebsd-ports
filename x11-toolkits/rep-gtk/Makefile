# New ports collection makefile for:   rep-gtk
# Date created:        06 October 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-toolkits/rep-gtk/Makefile,v 1.1 2006/07/18 16:49:16 ahze Exp $

PORTNAME=	rep-gtk
PORTVERSION=	0.15
PORTREVISION=	7
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
#DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK+ binding for rep Lisp interpreter

LIB_DEPENDS=	rep.13:${PORTSDIR}/lang/librep

PLIST_SUB=	GNUHOST=${ARCH}-pc-freebsd${OSREL:C/\..*//}

USE_GMAKE=	yes
USE_GNOME=	gtk12
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	${ARCH}-pc-freebsd${OSREL:C/\..*//}

.if defined(PACKAGE_BUILDING)
.undef WITHOUT_GNOME
.undef WITHOUT_ALL
WITH_GNOME=	yes
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibglade}!=""
USE_GNOME+=	libglade
PKGNAMESUFFIX=	-gnome
CONFIGURE_ARGS=	--with-gnome --with-libglade --with-gdk-pixbuf \
		--with-gnome-canvas-pixbuf
.else
CONFIGURE_ARGS=	--without-libglade --without-gnome --without-gdk-pixbuf \
		--without-gnome-canvas-pixbuf
.endif

.include <bsd.port.post.mk>
