# New ports collection makefile for:	gonzui
# Date created:	Wed Dec  1 16:35:00 GMT 2004
# Whom:		sumikawa
#
# $FreeBSD$
#

PORTNAME=	gonzui
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	A source code search engine

BUILD_DEPENDS=	${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb \
		${RUBY_ARCHLIBDIR}/iconv.so:${PORTSDIR}/converters/ruby-iconv
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb \
		${RUBY_ARCHLIBDIR}/iconv.so:${PORTSDIR}/converters/ruby-iconv

USE_RUBY=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
