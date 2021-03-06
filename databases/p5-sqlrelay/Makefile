# New ports collection makefile for:	Perl5 modules for SQL Relay
# Date created:		2 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	${SQLRELAY_PORTNAME}
PORTVERSION=	${SQLRELAY_PORTVERSION}
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	# none
PKGNAMEPREFIX=	p5-
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 modules to access to SQL Relay, including a DBD interface

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
EXTRACT_DEPENDS=	${NONEXISTENT}:${SQLRELAY_PORTDIR}:patch
LIB_DEPENDS=		sqlrclient.0:${SQLRELAY_PORTDIR}

BROKEN=		does not build

USE_PERL5=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${SQLRELAY_CONFIGURE_ARGS} \
		--with-pod2man=`which pod2man` \
		--with-perl-prefix="/usr"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		${SQLRELAY_CONFIGURE_ENV}

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		DBD::SQLRelay.3 SQLRelay::Connection.3 SQLRelay::Cursor.3

.include "${.CURDIR}/../sqlrelay/Makefile.common"
.include <bsd.port.pre.mk>

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -fs `${SQLRELAY_WRKSRC_CMD}` ${WRKSRC}
	${RM} -rf ${WRKSRC}/src/api/perl/CVS

post-patch:
	${REINPLACE_CMD} -e 's/installman3dir/siteman3dir/g' \
		${WRKSRC}/src/api/perl/*/Makefile

do-build:
	for dir in ${WRKSRC}/src/api/perl/*; do \
		cd $$dir && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} ${ALL_TARGET}; \
	done

do-install:
	for dir in ${WRKSRC}/src/api/perl/*; do \
		cd $$dir && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} ${INSTALL_TARGET}; \
	done

.include <bsd.port.post.mk>
