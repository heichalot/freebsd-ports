# New ports collection makefile for:	zope-coreblog2
# Date created:				18 December 2005
# Whom:					Yasushi Hayashi
#
# $FreeBSD$
#

PORTNAME=	coreblog2
PORTVERSION=	0.90b
PORTREVISION=	3
CATEGORIES=	www zope
MASTER_SITES=	http://coreblog.org/junk/
PKGNAMEPREFIX=	zope-
DISTNAME=	COREBlog2_09b
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fully-featured blog product for Plone

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}/CMFPlone/__init__.py:${PORTSDIR}/www/plone

USE_PYTHON=	2.4
USE_ZOPE=	2.9
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=COREBlog2

WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}

do-build:
	-@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@${CHMOD} -R og+rX ${WRKSRC}/
	@${CP} -R ${WRKSRC} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
