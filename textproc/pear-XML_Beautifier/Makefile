# Ports collection makefile for:  pear-XML_Beautifier
# Date created:			  31 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	XML_Beautifier
PORTVERSION=	1.2.0
CATEGORIES=	textproc devel pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class to format XML documents

BUILD_DEPENDS=	${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser \
		${PEARDIR}/XML/Util.php:${PORTSDIR}/devel/pear-XML_Util
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	XML
FILES=		Beautifier/Renderer.php Beautifier/Tokenizer.php \
		Beautifier/Renderer/Plain.php Beautifier.php
EXAMPLES=	example1.php example2.php example3.php \
		example4.php example5.php example6.php \
		example7.php \
		test.xml test2.xml test3.xml

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
