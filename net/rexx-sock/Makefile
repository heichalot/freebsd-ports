# ex:ts=8
# Ports collection makefile for:	rexx-sock
# Date created:			Nov 11, 2003
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	sock
PORTVERSION=	1.4
CATEGORIES=	net
MASTER_SITES=	SF/rx${PORTNAME}/rx${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	rexx-
DISTNAME=	RxSock-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A function package for Rexx programmers to create sockets

BUILD_DEPENDS=	rexx-regina>=3.3_1:${PORTSDIR}/lang/rexx-regina
RUN_DEPENDS=	rexx-regina>=3.3_1:${PORTSDIR}/lang/rexx-regina

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-rexx=regina
MAKE_ARGS=	INSTALL="${INSTALL}"
USE_LDCONFIG=	yes

DATADIR=	${PREFIX}/share/rx${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|ld -Bdynamic -Bshareable|$${CC} -shared|g' \
		${WRKSRC}/configure
.for file in Makefile.in rxsock-config.in
	@${REINPLACE_CMD} -e 's|-lc||g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
