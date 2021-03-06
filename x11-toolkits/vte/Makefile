# New ports collection makefile for:	vte
# Date created:				05 October 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/vte/Makefile,v 1.110 2010/04/26 22:38:09 kwm Exp $
#

PORTNAME=	vte
PORTVERSION=	0.24.1
PORTREVISION?=	0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	Terminal widget with improved accessibility and I18N support

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

USE_GMAKE=	yes
USE_BISON=	build
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22
USE_GETTEXT=	yes
USE_GNOME?=	gnomeprefix gnomehack gtk20 ltverhack referencehack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
#		BSD_PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS?=--disable-python \
		--disable-freetypetest

.if !defined(MASTERDIR)
OPTIONS=	GLX	"Enable support for DRI/GLX rendering" off
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900007
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-gnome-pty-helper_gnome-utmp.c
.endif

.if defined(WITH_GLX) && !defined(MASTERDIR)
CONFIGURE_ARGS+=	--with-glX
USE_GL=			yes
.endif

.include <bsd.port.post.mk>

.endif
