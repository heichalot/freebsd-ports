# New ports collection makefile for:	xmms-fc
# Date created:				8 Jan 2002
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-fc
PORTVERSION=	0.5.4
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A XMMS future composer input plugin

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Input/libfc.so lib/xmms/Input/libfc.la
GNU_CONFIGURE=	yes
USE_GNOME=	gtk12
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
