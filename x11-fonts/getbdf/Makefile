# New ports collection makefile for:    getbdf
# Date created:         30 August 1996
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	getbdf
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.netsw.org/x11/tools/internal/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	ache@FreeBSD.org
COMMENT=	Convert any X server font to .bdf format

PLIST_FILES=	bin/getbdf
USE_PERL5_BUILD=yes
USE_XORG=	x11
NO_WRKSUBDIR=	yes
ALL_TARGET=	getbdf

pre-patch:
	@${PERL} -pi -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/Xargs.c ${WRKSRC}/getbdf.c

do-install:
	cd ${WRKSRC}; \
	${INSTALL} -c -s -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} getbdf ${PREFIX}/bin

.include <bsd.port.mk>
