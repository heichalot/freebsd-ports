# New ports collection makefile for:	GraphR
# Date created:		24 October 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	graph
PORTVERSION=	0.1.9
PORTREVISION=	4
CATEGORIES=	graphics ruby
MASTER_SITES=	SF/rockit/${PORTNAME}r/${PORTVERSION}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}r-${PORTVERSION:S/./-/g}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Graph-related Ruby classes

RUN_DEPENDS=	${LOCALBASE}/bin/dot:${PORTSDIR}/graphics/graphviz

USE_RUBY=	yes

NO_BUILD=	yes

DOCS=		BUGS Changelog README

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
