# New ports collection makefile for:	zope-btreefolder2
# Date created:				6 Jan 2004
# Whom:					Khairil Yusof
#
# $FreeBSD$
#

PORTNAME=	btreefolder2
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	www zope
MASTER_SITES=	http://hathaway.freezope.org/Software/BTreeFolder2/
PKGNAMEPREFIX=	zope-
DISTNAME=	BTreeFolder2-${PORTVERSION}

MAINTAINER=	kaeru@inigo-tech.com
COMMENT=	Zope product that can store many items

DEPRECATED=	Included in Zope 2.8 and later
EXPIRATION_DATE=2007-08-31
USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

WRKSRC=		${WRKDIR}/BTreeFolder2

CONFLICTS=	plone[0-9]*-[0-9]*

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py  ${WRKSRC}/tests
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${WRKSRC}

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@${CHMOD} -R og+rX ${WRKSRC}/
	@${CP} -R ${WRKSRC} \
		${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
