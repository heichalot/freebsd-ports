# New ports collection makefile for:	libhangul
# Date created:				31 January 2007
# Whom:					Hyogeol, Lee <hyogeollee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libhangul
PORTVERSION=	0.0.10
CATEGORIES=	korean
MASTER_SITES=	http://kldp.net/frs/download.php/5417/

MAINTAINER=	hyogeollee@gmail.com
COMMENT=	A library for hangul processing

USE_ICONV=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
