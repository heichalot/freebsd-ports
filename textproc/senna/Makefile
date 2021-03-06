# New ports collection makefile for:	Senna
# Date created:		May 1 2005
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	senna
PORTVERSION=	1.1.4
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	senna/33763

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Embeddable Fulltext Search Engine

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_LDCONFIG=	YES
CONFIGURE_ARGS=	--with-sennahome=${SENNA_HOME}
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
MAKE_ARGS=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}"
WRKSRC=		${WRKDIR}/${DISTNAME}

SENNA_HOME?=	/var/senna

OPTIONS=	MECAB	"use mecab for morphological analysis" on \
		NFKC	"use nfkc based utf8 normalization" on

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ${ARCH}
.endif

.if defined(WITH_MECAB)
CONFIGURE_ARGS+=	--with-mecab
LIB_DEPENDS+=	mecab:${PORTSDIR}/japanese/mecab
.else
CONFIGURE_ARGS+=	--without-mecab
.endif

.if !defined(WITH_NFKC)
CONFIGURE_ARGS+=	--disable-nfkc
.endif

.include <bsd.port.post.mk>
