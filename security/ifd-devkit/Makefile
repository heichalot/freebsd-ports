# New ports collection makefile for:	ifd-devkit
# Date created:		23 August 2002
# Whom:			Bruce M Simpson
#
# $FreeBSD$
#

PORTNAME=	ifd-devkit
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.linuxnet.com/drivers/readers/files/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	IFD Handler Developer's Kit for MUSCLE PC/SC Lite

LIB_DEPENDS=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_LDCONFIG=	yes

NOMAN=

.include <bsd.port.mk>
