# New ports collection makefile for:	RDF::Notation3
# Date created:		21 Nov 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	RDF-Notation3
PORTVERSION=	0.91
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	RDF Notation3 parser

BUILD_DEPENDS=	${SITE_PERL}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${SITE_PERL}/RDF/Core.pm:${PORTSDIR}/textproc/p5-RDF-Core \
		${SITE_PERL}/${PERL_ARCH}/RDFStore.pm:${PORTSDIR}/textproc/p5-RDFStore
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		RDF::Notation3.3 RDF::Notation3::PrefTriples.3 \
		RDF::Notation3::RDFCore.3 RDF::Notation3::RDFStore.3 \
		RDF::Notation3::ReaderFile.3 RDF::Notation3::ReaderString.3 \
		RDF::Notation3::SAX.3 RDF::Notation3::Template::TReader.3 \
		RDF::Notation3::Template::TTriples.3 \
		RDF::Notation3::Template::TXML.3 RDF::Notation3::Triples.3 \
		RDF::Notation3::XML.3

post-patch:
	@${FIND} ${WRKSRC} -name "*.pm" | \
	${XARGS} ${PERL} -pi -e 's!^require 5.005_62;!!'
	${MV} ${WRKSRC}/doc/*.pod ${WRKSRC}/lib/RDF

.include <bsd.port.mk>
