# New ports collection makefile for:    Distutils
# Date created:         23 March 2000
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	distutils
PORTVERSION=	1.0.2
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYTHON}
MASTER_SITE_SUBDIR=	community/sigs/current/distutils-sig/download
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Distutils-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Module Distribution Utilities

USE_PYTHON=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} > 211
IGNORE=		won't work with the installed Python: use the version distributed with ${PYTHON_VERSION}
.endif

do-build:
	@(cd ${WRKSRC}; ${PYTHON_CMD} setup.py build)

do-install:
	@(cd ${WRKSRC}; ${PYTHON_CMD} setup.py install)

.include <bsd.port.post.mk>
