# New ports collection makefile for:	p5-Spoon
# Date created:				Fri Jul 16 14:17:55 CST 2004
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Spoon
PORTVERSION=	0.24
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/I/IN/INGY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Spiffy Application Building Framework

BUILD_DEPENDS=	${SITE_PERL}/Spiffy.pm:${PORTSDIR}/devel/p5-Spiffy \
		${SITE_PERL}/IO/All.pm:${PORTSDIR}/devel/p5-IO-All \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Spoon.3 \
		Spoon::Base.3 \
		Spoon::CGI.3 \
		Spoon::Command.3 \
		Spoon::ContentObject.3 \
		Spoon::Cookie.3 \
		Spoon::DataObject.3 \
		Spoon::Formatter.3 \
		Spoon::Hooks.3 \
		Spoon::Hub.3 \
		Spoon::Installer.3 \
		Spoon::MetadataObject.3 \
		Spoon::Plugin.3 \
		Spoon::Registry.3 \
		Spoon::Template.3 \
		Spoon::Template::TT2.3 \
		Spoon::Utils.3 \
		Spoon::Config.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
