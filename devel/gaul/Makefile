# ex:ts=8
# Ports collection makefile for:	gaul
# Date created:			Oct 28, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gaul
PORTVERSION=	0.1849.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-devel/0.1849
DISTNAME=	${PORTNAME}-devel-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Genetic Algorithm Utility Library

LIB_DEPENDS=	slang.2:${PORTSDIR}/devel/libslang2

MAKE_JOBS_SAFE=  yes

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -lcurses ${PTHREAD_LIBS}"
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread||g' ${WRKSRC}/configure

.include <bsd.port.mk>
