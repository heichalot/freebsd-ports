# New ports collection makefile for:	igraph
# Date created:		09 May, 2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	igraph
PORTVERSION=	0.9.7
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Ruby extension for using the igraph library

BUILD_DEPENDS=	${LOCALBASE}/lib/libigraph.so:${PORTSDIR}/math/igraph

CONFIGURE_ARGS+=	--with-igraph-include=${LOCALBASE}/include/igraph \
			--without-igraph-lib=${LOCALBASE}/lib

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
