# New ports collection makefile for:	xbase
# Date created:				Nov 22, 2003
# Whom:					Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$

PORTNAME=	xbase
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.rekallrevealed.org/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An xbase (i.e. dBase, FoxPro, etc.) compatible C++ class library

USE_AUTOTOOLS=	libtool:22
USE_GNOME=	lthack
USE_LDCONFIG=	yes

.if defined(MAINTAINER_MODE)
test:	install
.for exi in sample1 sample2 sample3 sample4 sample5
	(cd /tmp && ${WRKSRC}/examples/${exi})
.endfor
.endif

.include <bsd.port.mk>
