# New ports collection makefile for:    netselect
# Date created:                         15 July 2006
# Whom:                                 Timothy Redaelli <drizzt@gufi.org>
#
# $FreeBSD$
#

PORTNAME=	netselect
PORTVERSION=	0.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GENTOO} \
		http://www.worldvisions.ca/~apenwarr/netselect/
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	drizzt@gufi.org
COMMENT=	Ultrafast implementation of ping

PLIST_FILES=	bin/${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS=	SUID "Install with the sticky bit (mode 4110)" off

.include <bsd.port.pre.mk>

.if defined(WITH_SUID)
BINMODE=	4110
.else
BINMODE=	0100
.endif

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>
