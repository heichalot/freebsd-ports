# New ports collection makefile for:	portlint
# Date created:		13 Jun 1997
# Whom:			Jun-ichiro itojun Hagino <itojun@itojun.org>
#
# $FreeBSD$
#
# This port is self contained in the src directory.
#

PORTNAME=	portlint
PORTVERSION=	2.13.1
CATEGORIES=	ports-mgmt
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	A verifier for FreeBSD port directory

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/src
USE_PERL5_RUN=	yes

SRC=		${.CURDIR}/src

MAN1=		portlint.1

do-fetch:
	@${DO_NADA}

pre-patch:
	@${CP} -R ${SRC} ${WRKDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|' ${WRKSRC}/portlint.pl
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|' \
		${WRKSRC}/portlintgrep.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/portlint.pl ${PREFIX}/bin/portlint
	${INSTALL_MAN} ${WRKSRC}/portlint.1 ${MAN1PREFIX}/man/man1
	${MKDIR} ${EXAMPLESDIR}
.if !defined(NOPORTEXAMPLES)
	${INSTALL} -o ${SHAREOWN} -g ${SHAREGRP} -m 555 -d ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/portlintgrep.pl ${EXAMPLESDIR}/portlintgrep
.endif

.include <bsd.port.mk>
