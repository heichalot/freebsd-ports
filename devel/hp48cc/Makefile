# New ports collection makefile for:	hp48cc
# Date created:				Sun Aug 12 04:33:37 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	hp48cc
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	devel lang
MASTER_SITES=	http://www.sigala.it/sandro/files/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	C-like compiler that translates input code to the HP48 RPN language

USE_BISON=	build
GNU_CONFIGURE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
MAKE_JOBS_UNSAFE=	yes

MAN1=		${PORTNAME}.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
