# New ports collection makefile for:	p5-Image-Heatmap
# Date created:		2009-07-20
# Whom:			Steven Kreuzer <skreuzer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Image-Heatmap
PORTVERSION=	0.559
PORTREVISION=	2
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN/../../authors/id/W/WA/WAZZUTEKE
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Build heatmap images

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Image/Magick.pm:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=	${WRKDIR}/${PORTNAME}
PERL_CONFIGURE=	yes

MAN3=	Image::Heatmap.3

.include <bsd.port.mk>
