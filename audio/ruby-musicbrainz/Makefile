# New ports collection makefile for:	MB-Ruby
# Date created:		23 March 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	musicbrainz
PORTVERSION=	0.3.0
CATEGORIES=	audio ruby
MASTER_SITES=	http://www.pablotron.org/download/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	mb-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	stas@FreeBSD.org
COMMENT=	MusicBrainz bindings for Ruby

LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

RUBY_SHEBANG_FILES=	${WRKSRC}/examples/*.rb

INSTALL_TARGET=	site-install

DOCS=		README TODO doc

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
	@(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "${DOCS}" ${RUBY_MODDOCDIR}/)
.endif

.include <bsd.port.mk>
