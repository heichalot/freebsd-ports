# New ports collection makefile for:	devel/p5-Test-YAML-Valid
# Date created:				10 April 2007
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-YAML-Valid
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Test for valid YAML

RUN_DEPENDS=	p5-YAML>=0.60:${PORTSDIR}/textproc/p5-YAML \
		p5-Test-Simple>0:${PORTSDIR}/devel/p5-Test-Simple
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Test::YAML::Valid.3

OPTIONS=	YAMLSYCK "Use YAML::Syck for testing" OFF

post-patch:
	${PERL} -pi -e '$$_="" if /auto_install/' ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>
.if defined(WITH_YAMLSYCK)
RUN_DEPENDS+=	p5-YAML-Syck>0:${PORTSDIR}/textproc/p5-YAML-Syck
BUILD_DEPENDS+=	p5-YAML-Syck>0:${PORTSDIR}/textproc/p5-YAML-Syck
.endif
.include <bsd.port.post.mk>
