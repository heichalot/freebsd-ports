# New ports collection makefile for:   rep-gtk
# Date created:        06 October 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-toolkits/rep-gtk2/Makefile,v 1.8 2006/07/18 16:50:28 ahze Exp $

PORTNAME=	rep-gtk2
PORTVERSION=	0.90.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/rep-gtk/rep-gtk/${PORTVERSION}
DISTNAME=	rep-gtk-${PORTVERSION}

MAINTAINER=	anray@FreeBSD.org
COMMENT=	GTK+-2 binding for rep Lisp interpreter

LIB_DEPENDS=	rep.13:${PORTSDIR}/lang/librep

PLIST_SUB=	GNUHOST=${ARCH}-pc-freebsd${OSREL:C/\..*//}

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:262:env automake:110:env libtool:22:env
CONFIGURE_SCRIPT=	autogen.sh
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \

CONFIGURE_TARGET=	${ARCH}-pc-freebsd${OSREL:C/\..*//}

pre-configure:
	@${MKDIR} ${WRKSRC}/m4

.include <bsd.port.mk>
