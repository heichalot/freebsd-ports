# New ports collection makefile for:	liblas
# Date created:				21 June 2008
# Whom:					Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	liblas
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	http://liblas.org/raw-attachment/wiki/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Library For Reading And Writing LAS-Format Data

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/las-1.0.0

.include <bsd.port.mk>
