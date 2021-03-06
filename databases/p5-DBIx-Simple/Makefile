# New ports collection makefile for:	DBIx::Simple
# Date created:				10 December 2005
# Whom:					Parv <parv@pair.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Simple
PORTVERSION=	1.32
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	parv@pair.com
COMMENT=	Simplified object oriented interface to Perl DBI

RUN_DEPENDS=	p5-DBI>=1.21:${PORTSDIR}/databases/p5-DBI

OPTIONS=	SQL_INTERP "Interpolate Perl variables into SQL with DBI" off \
		SQL_ABSTRACT "Generate SQL from Perl data structures" off \
		DBIX_XHTML_TABLE "Create XHTML tables from SQL queries" off \
		TEXT_TABLE "Create plain text table from data" off

PERL_CONFIGURE=	yes

MAN3=	DBIx::Simple.3 \
	DBIx::Simple::Examples.3 \
	DBIx::Simple::Comparison.3

.include <bsd.port.pre.mk>

.if defined(WITH_SQL_INTERP)
RUN_DEPENDS+=	${SITE_PERL}/SQL/Interp.pm:${PORTSDIR}/databases/p5-SQL-Interp
.endif

.if defined(WITH_SQL_ABSTRACT)
RUN_DEPENDS+=	p5-SQL-Abstract>=0:${PORTSDIR}/databases/p5-SQL-Abstract
.endif

.if defined(WITH_DBIX_XHTML_TABLE)
RUN_DEPENDS+=	p5-DBIx-XHTML_Table>=0:${PORTSDIR}/databases/p5-DBIx-XHTML_Table
.endif

.if defined(WITH_TEXT_TABLE)
RUN_DEPENDS+=	p5-Text-Table>=0:${PORTSDIR}/textproc/p5-Text-Table
.endif

.include <bsd.port.post.mk>
