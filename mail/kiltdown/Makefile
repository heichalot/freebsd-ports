# New ports collection makefile for:	kiltdown
# Date Created:				16 Jun 2001
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	kiltdown
PORTVERSION=	0.8.045
PORTREVISION=	14
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Kiltdown is an UI independant Email Client for UNIX

LIB_DEPENDS=	db3:${PORTSDIR}/databases/db3

PLIST_FILES=	bin/kiltdown

USE_QT_VER=	3
USE_GMAKE=	yes
MY_CONFIGURE_ARGS=	-release
MY_CONFIGURE_ARGS+=	-qtinc ${LOCALBASE}/include -qtlib ${LOCALBASE}/lib
MY_CONFIGURE_ARGS+=	-dbinc ${LOCALBASE}/include/db3 -dblib ${LOCALBASE}/lib
BUILD_ENV+=		PATH=${PATH}:${LOCALBASE}/bin
MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${MV} ${WRKSRC}/configs/bsd-generic ${WRKSRC}/configs/bsd-generic.sed
	${SED} \
	 -e "s|SYS_CFLAGS=-pthread|SYS_CFLAGS=${PTHREAD_CFLAGS} ${CFLAGS}|" \
	 -e "s|SYS_LDFLAGS=-pthread|SYS_LDFLAGS=${PTHREAD_LIBS} ${LDFLAGS}|" \
		${WRKSRC}/configs/bsd-generic.sed \
		> ${WRKSRC}/configs/bsd-generic

do-configure:
	(cd ${CONFIGURE_WRKSRC} && \
		./${CONFIGURE_SCRIPT} ${MY_CONFIGURE_ARGS} )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kiltdown/kiltdown ${PREFIX}/bin/

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
