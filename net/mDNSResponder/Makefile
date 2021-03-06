# ex:ts=8
# Ports collection makefile for:  mDNSResponder
# Date created:			  Tues Mar 2, 2004
# Whom:				  Alfred Perlstein <alfred@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	mDNSResponder
PORTVERSION=	214
CATEGORIES=	net dns
MASTER_SITES=	http://opensource.apple.com/tarballs/mDNSResponder/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apple's mDNSResponder

MAKE_JOBS_UNSAFE=	yes

USE_BISON=	build
USE_LDCONFIG=	YES

USE_GMAKE=	YES
USE_RC_SUBR=	mdnsd.sh
MAKE_ARGS+=	os=freebsd LOCALBASE=${PREFIX} MANPATH=${MANPREFIX}/man
BUILD_WRKSRC=	${WRKSRC}/mDNSPosix
INSTALL_WRKSRC=	${WRKSRC}/mDNSPosix
EXTRA_PROGS_BIN=mDNSClientPosix \
		mDNSIdentify \
		mDNSNetMonitor \
		mDNSProxyResponderPosix \
		mDNSResponderPosix
EXTRA_PROGS_SBIN=dnsextd
MAKE_JOBS_UNSAFE=	yes

EXTRAMAN8=	dnsextd.8 mDNSResponderPosix.8

MAN8=		mdnsd.8 ${EXTRAMAN8}

CONFLICTS=	avahi-libdns-[0-9]*

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not compile on alpha
.endif

post-patch:
	${MV} ${WRKSRC}/mDNSShared/mDNSResponder.8 \
		${WRKSRC}/mDNSShared/mDNSResponderPosix.8
pre-build:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		-e 's|mDNSResponder.8|mDNSResponderPosix.8|g' \
		${WRKSRC}/mDNSPosix/Makefile

post-install:
	cd ${INSTALL_WRKSRC}/build/prod && \
		${INSTALL_PROGRAM} ${EXTRA_PROGS_BIN} ${PREFIX}/bin && \
		${INSTALL_PROGRAM} ${EXTRA_PROGS_SBIN} ${PREFIX}/sbin
.	for section in 1 2 3 4 5 6 7 8
.		for page in ${EXTRAMAN${section}}
			${INSTALL_MAN} ${WRKSRC}/mDNSShared/${page} ${MAN${section}PREFIX}/man/man${page:E}/
.		endfor
.	endfor

.include <bsd.port.post.mk>
