# New ports collection makefile for:	nagios-check_bacula
# Date created: 	10 Juli 2008
# Whom:			Anders Troback
#
# $FreeBSD$
#

PORTNAME=	check_bacula
PORTVERSION=	5.0.0
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/bacula/bacula/${PORTVERSION}
PKGNAMEPREFIX=	nagios-
DISTNAME=	bacula-${PORTVERSION}

MAINTAINER=	freebsd@troback.com
COMMENT=	Nagios plugin for Bacula

WRKSRC=		${WRKDIR}/bacula-${PORTVERSION}
CONFIGURE_ARGS=	--enable-client-only \
		--disable-build-dird \
		--disable-build-stored \
		--disable-nls
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

post-build:
	${MAKE} -C ${WRKSRC}/examples/nagios/check_bacula

do-install:
	@${MKDIR} ${PREFIX}/libexec/nagios
	${INSTALL_PROGRAM} ${WRKSRC}/examples/nagios/check_bacula/.libs/check_bacula \
		${PREFIX}/libexec/nagios/
	${INSTALL_PROGRAM} ${WRKSRC}/src/lib/.libs/libbac.so.1 \
		${PREFIX}/lib

.include <bsd.port.post.mk>
