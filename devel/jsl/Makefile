# New ports collection makefile for:	pylint
# Date created:		28 May 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	jsl
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.Awfulhak.org/pub/jsl/ \
		http://www.javascriptlint.com/download/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Analyzes javascript code looking for bugs and signs of poor quality

PLIST_FILES=	bin/jsl
WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_GMAKE=	yes
MAKEFILE=	Makefile.ref
MAKE_ARGS=	OS_CFLAGS="-DXP_UNIX -DHAVE_VA_COPY -DVA_COPY=va_copy"
CFLAGS+=	-fPIC

.include <bsd.port.pre.mk>

JSLCFG_CMD=	${UNAME} -sr | ${SED} 's, ,,'

post-patch:
	${LN} -s Linux_All.mk ${WRKSRC}/config/$$(${JSLCFG_CMD}).mk

do-install:
	${INSTALL} ${WRKSRC}/$$(${JSLCFG_CMD})_DBG.OBJ/jsl ${PREFIX}/bin/jsl

.include <bsd.port.post.mk>
