# New ports collection makefile for:	p5-Geo-EOP
# Date created:      			23 January 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Geo-EOP
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	Perl Module to Process Earth Observation Products Meta-data

RUN_DEPENDS=	p5-Geo-GML>=0.12:${PORTSDIR}/graphics/p5-Geo-GML \
		p5-Test-Pod>=1.26:${PORTSDIR}/devel/p5-Test-Pod \
		p5-XML-Compile>=0.96:${PORTSDIR}/textproc/p5-XML-Compile \
		p5-XML-Compile-Cache>=0.14:${PORTSDIR}/textproc/p5-XML-Compile-Cache

MAN3=		Geo::EOP::Util.3 Geo::EOP.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
