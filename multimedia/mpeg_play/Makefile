# New ports collection makefile for:	mpeg_play
# Date created:		17 December 1994
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	mpeg_play
PORTVERSION=	2.4
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.bsd-geek.de/FreeBSD/distfiles/ \
		ftp://mm-ftp.cs.berkeley.edu/pub/multimedia/mpeg/play/
EXTRACT_SUFX=	-patched-src.tar.gz

MAINTAINER=	lme@FreeBSD.org
COMMENT=	A program to play mpeg movies on X displays

WRKSRC=		${WRKDIR}/mpeg_play
USE_IMAKE=	yes
USE_XORG=	x11 xext
MAN1=		mpeg_play.1
PLIST_FILES=	bin/mpeg_play

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Does not compile on ia64
.endif

pre-patch:
	${CP} ${WRKSRC}/Imakefile.proto ${WRKSRC}/Imakefile
	${CP} ${WRKSRC}/mpeg_play.1 ${WRKSRC}/mpeg_play.man

.include <bsd.port.post.mk>
