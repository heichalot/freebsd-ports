# ex:ts=8
# New ports collection makefile for:	xmlrpc-c
# Date created:			Mar 8, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmlrpc-c
PORTVERSION=	1.06.39
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/Xmlrpc-c%20Super%20Stable/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	garga@FreeBSD.org
COMMENT=	XML-RPC library for C and C++

MAKE_JOBS_UNSAFE=	yes

OPTIONS=	DEBUG "Compile with debugging information" off \
		CURL "Compile with curl support" on \
		LIBWWW "Compile with libwww support" off

CONFLICTS=	xmlrpc-epi-0.* xmlrpc-c-devel-[0-9]*

USE_GNOME=	gnometarget
USE_PERL5=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22:env
GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile
MAKE_ARGS=	LIBTOOL="${LIBTOOL}" \
		CFLAGS_COMMON="${CFLAGS}" \
		CXXFLAGS_COMMON="${CXXFLAGS}"
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if !defined(WITH_DEBUG)
CFLAGS+=	-DNDEBUG
.endif

.if defined(WITH_CURL)
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--enable-curl-client
.else
CONFIGURE_ARGS+=	--disable-curl-client
.endif

.if defined(WITH_LIBWWW)
LIB_DEPENDS+=	wwwcore.1:${PORTSDIR}/www/libwww
CONFIGURE_ARGS+=	--enable-libwww-client
.else
CONFIGURE_ARGS+=	--disable-libwww-client
.endif

.if defined(WITHOUT_LIBWWW) && defined(WITHOUT_CURL)
PLIST_SUB+=	CLIENT="@comment "
.else
PLIST_SUB+=	CLIENT=""
.endif

post-extract:
	@${FIND} ${WRKSRC} -type l -name blddir | ${XARGS} ${RM}
	@${FIND} ${WRKSRC} -type l -name srcdir | ${XARGS} ${RM}

post-patch:
	@${GREP} -lR '\-lpthread' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g'

.include <bsd.port.post.mk>
