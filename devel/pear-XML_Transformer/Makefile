# Ports collection makefile for:  pear-XML_Transformer
# Date created:			  29 September 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	XML_Transformer
PORTVERSION=	1.1.1
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR XML Transformations in PHP

BUILD_DEPENDS=	${PEARDIR}/XML/Util.php:${PORTSDIR}/devel/pear-XML_Util
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	XML
FILES=		Transformer/Driver/Cache.php Transformer/Driver/OutputBuffer.php \
		Transformer/Namespace/Anchor.php Transformer/Namespace/DocBook.php \
		Transformer/Namespace/Image.php Transformer/Namespace/PHP.php \
		Transformer/Namespace/Widget.php \
		Transformer/CallbackRegistry.php Transformer/Namespace.php \
		Transformer.php
DOCS=		README
_DOCSDIR=	.
TESTS=		AllTests.php TestNamespace.php TransformerTest.php
_TESTSDIR=	Transformer/Tests

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
