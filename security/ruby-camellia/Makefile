# New ports collection makefile for:	camellia-rb
# Date created:		9 August 2008
# Whom:			Yoshisato YANAGISAWA <osho@pcc-software.org>
#
# $FreeBSD$
#

PORTNAME=	camellia
PORTVERSION=	1.0
CATEGORIES=	security ruby
MASTER_SITES=	http://info.isl.ntt.co.jp/crypt/camellia/dl/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-rb-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	osho@pcc-software.org
COMMENT=	A Ruby extension library which implements Camellia encryption

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

INSTALL_TARGET=	site-install

DOCS=		README.txt History.txt License.txt
EXAMPLES=	cext/camellia-example.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
