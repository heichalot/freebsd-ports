# New ports collection makefile for:	htpdate
# Date created:			9 Jun 2005
# Whom:				Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	htpdate
PORTVERSION=	1.0.4
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.clevervest.com/htp/archive/c/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Time synchronization over http utility

USE_BZIP2=	yes

MANCOMPRESSED=	no
NO_MANCOMPRESS=	yes
MAN8=	htpdate.8.gz

PLIST_FILES=	bin/htpdate

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/htpdate ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/${MAN8} ${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
