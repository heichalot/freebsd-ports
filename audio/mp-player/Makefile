# New ports collection makefile for:	mp-player
# Date created:				26 Aug 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	mp-player
PORTVERSION=	0.6
CATEGORIES=	audio
MASTER_SITES=	http://mp.waw.cx/ \
		CRITICAL
DISTNAME=	mp-current
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A curses based module tracker using libmikmod

LIB_DEPENDS=	mikmod.2:${PORTSDIR}/audio/libmikmod

MAKE_JOBS_SAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lmikmod ${PTHREAD_LIBS} -lncurses -lpanel
DEFINES=	-D_REENTRANT

WRKSRC=		${WRKDIR}/mp-beta-06

PLIST_FILES=	bin/mp-player

post-patch:
	@${RM} ${WRKSRC}/mp

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} ${DEFINES} ${WRKSRC}/mp.c -o ${WRKSRC}/mp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
