# New ports collection makefile for:	pecl-imagick
# Date created:			13 Apr 2007
# Whom:				Andrey Slusar <anray@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	imagick
DISTVERSION=	3.0.0RC1
CATEGORIES=	graphics
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	anray@FreeBSD.org
COMMENT=	Provides a wrapper to the ImageMagick/GraphicsMagick library

LIB_DEPENDS=	MagickWand.3:${PORTSDIR}/graphics/ImageMagick

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--with-imagick=${LOCALBASE}

.include <bsd.port.mk>
