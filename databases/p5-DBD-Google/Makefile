# ex:ts=8
# Ports collection makefile for:	p5-DBD-Google
# Date created:			Apr 7, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	DBD-Google
PORTVERSION=	0.51
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	Treat Google as a datasource for DBI

BUILD_DEPENDS=	${SITE_PERL}/Net/Google.pm:${PORTSDIR}/net/p5-Net-Google \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/SQL/Parser.pm:${PORTSDIR}/databases/p5-SQL-Statement \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBD::Google.3 SQL::Dialects::Google.3

.include <bsd.port.mk>
