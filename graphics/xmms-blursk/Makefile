# New ports collection makefile for:	xmms-blursk
# Date created:				19 Aug 2002
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	blursk
PORTVERSION=	1.3
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://web.cecs.pdx.edu/~kirkenda/blursk/
PKGNAMEPREFIX=	xmms-
DISTNAME=	Blursk-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A XMMS plugin inspired by "Blur Scope"

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Visualization/libblursk.so
USE_GNOME=	gtk12
USE_XORG=	x11 xv
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} ${CFLAGS} ${PTHREAD_CFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT} \
		${BUILD_WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
