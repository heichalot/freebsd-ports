# New ports collection makefile for:	p5-Config-Auto
# Date created:				August 29 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$

PORTNAME=	Config-Auto
PORTVERSION=	0.20
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Config
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Magical config file parser

BUILD_DEPENDS=	${SITE_PERL}/Config/IniFiles.pm:${PORTSDIR}/devel/p5-Config-IniFiles \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

OPTIONS=	XMLSIMPLE "Support for XML config files" off

.include <bsd.port.pre.mk>

.ifdef(WITH_XMLSIMPLE)
BUILD_DEPENDS+=	${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS+=	${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple
.endif

MAN3=		Config::Auto.3

.include <bsd.port.post.mk>
