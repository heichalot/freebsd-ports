# Ports collection makefile for:  postgresql-plproxy
# Date created:    27 July 2007
# Whom:            Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	plproxy
PORTVERSION=	2.0.5
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/1818/
PKGNAMEPREFIX=	postgresql-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	PL/Proxy is database partitioning system

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex

USE_PGSQL=	yes
USE_GMAKE=	yes
USE_BISON=	build

post-patch:
	@${REINPLACE_CMD} -e 's= flex= ${LOCALBASE}/bin/flex=g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
