# New ports collection makefile for:	libpafe
# Date created:				21 February 2010
# Whom:					Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libpafe
PORTVERSION=	0.0.7
#PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	http://homepage3.nifty.com/slokar/pasori/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	FeliCa read/write library for Sony RC-S320 USB FeliCa R/W(PaSoRi)

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	bin/felica_dump bin/pasori_test \
		include/libpafe/felica_command.h \
		include/libpafe/libpafe.h \
		include/libpafe/pasori_command.h \
		lib/libpafe.a lib/libpafe.so lib/libpafe.la lib/libpafe.so.0
PLIST_DIRS=	include/libpafe

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1:${PORTSDIR}/devel/libusb
CONFIGURE_ENV+= CPPFLAGS="${CPPFLAGS} -I${PREFIX}/include" \
		LDFLAGS="${LDFLAGS} -L${PREFIX}/lib"
.endif

.include <bsd.port.post.mk>
