# New ports collection makefile for:	mingplot
# Date created:				14 Nov 2003
# Whom:					UMENO Takashi <umeno@rr.iij4u.or.jp>
#
# $FreeBSD$
#

PORTNAME=	mingplot
PORTVERSION=	0.3
PORTREVISION=	3
CATEGORIES=	graphics www
MASTER_SITES=	http://0xcc.net/mingplot/

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	A tool to generate a flash-based chart

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/ming/mingc.so:${PORTSDIR}/graphics/ruby-ming

USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv

.include <bsd.port.mk>
