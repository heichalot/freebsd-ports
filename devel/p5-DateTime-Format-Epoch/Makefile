# New ports collection makefile for:	p5-DateTime-Format-Epoch
# Date created:	   2 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-Epoch
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert DateTimes to/from epoch seconds

RUN_DEPENDS=	p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/Math/BigInt.pm:${PORTSDIR}/math/p5-Math-BigInt
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Format::Epoch.3 \
		DateTime::Format::Epoch::ActiveDirectory.3 \
		DateTime::Format::Epoch::DotNet.3 \
		DateTime::Format::Epoch::JD.3 \
		DateTime::Format::Epoch::Lilian.3 \
		DateTime::Format::Epoch::MJD.3 \
		DateTime::Format::Epoch::MacOS.3 \
		DateTime::Format::Epoch::RJD.3 \
		DateTime::Format::Epoch::RataDie.3 \
		DateTime::Format::Epoch::TAI64.3 \
		DateTime::Format::Epoch::TJD.3 \
		DateTime::Format::Epoch::Unix.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README TODO

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
