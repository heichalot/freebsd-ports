# ports collection makefile for:	Mird 1.0.7
# Date created:				07 November 2001
# Whom:					Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	mird
PORTVERSION=	1.0.7
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.oav.net/pkg_freebsd/distfiles/ \
		http://grendel.firewall.com/caudium-pkg/ \
		http://www.mirar.org/mird/
DISTNAME=	Mird-${PORTVERSION}

MAINTAINER=	kiwi@oav.net
COMMENT=	A free database library with transaction support

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_AUTOTOOLS=	autoconf:262:env
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-debug
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,CFLAGS=,CFLAGS+=,' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's,-O,,g' ${WRKSRC}/src/configure

post-install:
	${STRIP_CMD} ${PREFIX}/lib/libmird.so.1

.include <bsd.port.mk>
