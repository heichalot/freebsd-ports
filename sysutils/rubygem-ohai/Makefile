# Ports collection makefile for:	rubygem-ohai
# Date created:				18 Mar 2010
# Whom:					Renaud Chaput <renchap@cocoa-x.com>
#
# $FreeBSD$
#

PORTNAME=	ohai
PORTVERSION=	0.5.4
CATEGORIES=	sysutils
MASTER_SITES=	RG

MAINTAINER=	renchap@cocoa-x.com
COMMENT=	Ohai profiles your system and emits JSON

RUN_DEPENDS=	rubygem-mixlib-log>=1.1.0:${PORTSDIR}/devel/rubygem-mixlib-log \
		rubygem-mixlib-config>=1.1.0:${PORTSDIR}/devel/rubygem-mixlib-config \
		rubygem-mixlib-cli>=1.1.0:${PORTSDIR}/devel/rubygem-mixlib-cli \
		rubygem-systemu>=1.2.0:${PORTSDIR}/devel/rubygem-systemu \
		rubygem-extlib>=0.9.14:${PORTSDIR}/devel/rubygem-extlib \
		rubygem-json>=1.1.9:${PORTSDIR}/devel/rubygem-json

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/ohai

.include <bsd.port.mk>
