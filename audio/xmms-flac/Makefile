# New ports collection makefile for:	xmms-flac
# Date created:		2003-06-10
# Whom:			Christian Weisgerber <naddy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmms-flac
PORTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/flac/flac-src/flac-${PORTVERSION}-src
DISTNAME=	flac-${PORTVERSION}

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	XMMS input plugin for playing FLAC files

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms \
		FLAC.10:${PORTSDIR}/audio/flac \
		pthread-stubs.0:${PORTSDIR}/devel/libpthread-stubs \
		ogg.7:${PORTSDIR}/audio/libogg \
		xcb.2:${PORTSDIR}/x11/libxcb

USE_AUTOTOOLS=	libtool:22
USE_GETTEXT=	yes
USE_GNOME=	gtk12
USE_ICONV=	yes
USE_XORG=	x11 xau xdmcp xext xi
CONFIGURE_ARGS=	--with-libiconv-prefix="${LOCALBASE}" \
		--with-ogg="${LOCALBASE}" \
		--with-xmms-prefix="${LOCALBASE}"
MAKE_ARGS=	LIBTOOL="${LIBTOOL} --tag=disable-static"
MAKEFILE=	${FILESDIR}/Makefile
MAKE_JOBS_SAFE=	yes

# "obj" is magic to our make(1)
post-configure:
	@${RM} -rf ${WRKSRC}/obj

# XXX
post-install:
	${RM} ${PREFIX}/lib/xmms/Input/libxmms-flac.la

.include <bsd.port.mk>
