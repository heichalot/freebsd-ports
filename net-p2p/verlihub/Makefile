# New ports collection makefile for:	Verlihub
# Date created:				2 April 2004
# Whom:					Bill Cadwallader <hurbold@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	verlihub
DISTVERSION=	0.9.8e-r2
PORTEPOCH=	1
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/Verlihub/${DISTVERSION}

MAINTAINER=	me@skylord.ru
COMMENT=	A Direct Connect protocol server (Hub)

# XXX: Actually, bash isn't required for building,
# but otherwise configure script would pick the wrong path
BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	GeoIP.5:${PORTSDIR}/net/GeoIP \
		pcre.0:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_RC_SUBR=	verlihub
USE_GCC=	4.2+
USE_AUTOTOOLS=	libtool:22
USE_MYSQL=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
SUB_FILES+=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|for libpath in /|for libpath in ${PREFIX} /|g' ${WRKSRC}/config_geoip

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
