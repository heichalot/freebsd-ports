# ex:ts=8
# Ports collection makefile for:	py-rrdpipe
# Date created:			May 31, 2002
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	rrdpipe
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/ \
		http://mirror2.unixfreunde.de/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyRRDpipe-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable Python module to access RRDTool files via pipes

LIB_DEPENDS=	rrd:${PORTSDIR}/databases/rrdtool

USE_PYTHON=	yes
NO_BUILD=	yes
PLIST_FILES=	lib/%%PYTHON_VERSION%%/site-packages/RRDpipe.py

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/RRDpipe.py ${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
