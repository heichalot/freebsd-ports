# New ports collection makefile for:	rename
# Date created:				7 July 2005
# Whom:					Chad Castleberry AKA ritalin
#
# $FreeBSD$
#

PORTNAME=	rename
PORTVERSION=	1.3
CATEGORIES=	sysutils
MASTER_SITES=	https://oncourse.iu.edu/access/content/user/crcastle/Filemanager_Public_Files/ \
		http://mirror2.unixfreunde.de/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	chadcastleberry@gmail.com
COMMENT=	Rename multiple files using regular expressions

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/${PORTNAME}
MAN1=		rename.1

post-extract:
	@${RM} -f ${WRKSRC}/config.cache

.include <bsd.port.mk>
