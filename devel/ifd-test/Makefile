# New ports collection makefile for:	ifd-test
# Date created:		23 August 2002
# Whom:			Bruce M Simpson
#
# $FreeBSD$
#

PORTNAME=	ifd-test
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	devel security
MASTER_SITES=	http://www.linuxnet.com/drivers/readers/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IFD Test Suite for PC/SC Lite

LIB_DEPENDS=    pcsclite.1:${PORTSDIR}/devel/pcsc-lite

USE_GMAKE=	yes

NOMAN=
PLIST_FILES=	sbin/ifdtest
CFLAGS+=	${PTHREAD_CFLAGS}
MAKE_ENV=	LIBS="-L${PREFIX}/lib -lpcsclite ${PTHREAD_LIBS}"

post-patch:
	${REINPLACE_CMD} -e "s,LPSTR,LPTSTR,g; s,LPCSTR,LPCTSTR,g" \
		${WRKSRC}/commands.h ${WRKSRC}/ifdtest.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ifdtest ${PREFIX}/sbin

.include <bsd.port.mk>
