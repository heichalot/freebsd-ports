# New ports collection makefile for:   pecl-amfext
# Date created:		11 February 2007
# Whom:			Piotr Rybicki <meritus@innervision.pl>
#
# $FreeBSD$
#

PORTNAME=	amfext
PORTVERSION=	0.9.2
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	meritus@innervision.pl
COMMENT=	Implements encoding and decoding of AMF and AMF3 messages

USE_PHP=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	amf

CONFIGURE_ARGS=	--enable-amf
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/php/ext/standard"

.include <bsd.port.mk>
