# Ports collection makefile for:  pear-XML_NITF
# Date created:			  18 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	XML_NITF
PORTVERSION=	1.1.0
CATEGORIES=	devel pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR NITF XML parser

BUILD_DEPENDS=	${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	XML
FILES=		NITF.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
