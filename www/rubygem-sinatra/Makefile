# Ports collection makefile for:	rubygem-sinatra
# Date created:				2008-11-02
# Whom:					Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$

PORTNAME=	sinatra
PORTVERSION=	0.9.5
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A classy web development framework in ruby

RUN_DEPENDS=	rubygem-rack>=0.9.1:${PORTSDIR}/www/rubygem-rack

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
