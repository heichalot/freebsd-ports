# New ports collection makefile for:	thrift
# Date created:	   30 Nov 2007
# Whom:		   Jon M. Dugan <jdugan@x1024.net>
#
# $FreeBSD$
#

PORTNAME=	thrift
PORTVERSION=	0.2.0
PORTEPOCH=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=

MAINTAINER=	jdugan@x1024.net
COMMENT=	Python interface to Thrift

EXTRACT_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/devel/thrift:extract

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-extract:
	@${LN} -sfh \
	`cd ${PORTSDIR}/devel/thrift && ${MAKE} -V WRKSRC`/lib/py ${WRKSRC}

do-patch:
	${REINPLACE_CMD} "/name = '/s/Thrift/thrift/" \
	    ${WRKSRC}/setup.py
	${REINPLACE_CMD} "/version = '/s/0\.1/${PORTVERSION}/" \
	    ${WRKSRC}/setup.py

.include <bsd.port.mk>
