# New ports collection makefile for:  mongodb-devel
# Date created:        3 November 2009
# Whom:                ivoras
#
# $FreeBSD$
#

PORTNAME=	mongodb
PORTVERSION=	1.3.1
CATEGORIES=	databases net
MASTER_SITES=	http://downloads.mongodb.org/src/
PKGNAMESUFFIX=	-devel
DISTNAME=	mongodb-src-r${PORTVERSION}

MAINTAINER=	ivoras@FreeBSD.org
COMMENT=	A NOSQL distributed document-oriented database

LIB_DEPENDS=	boost_system:${PORTSDIR}/devel/boost-libs \
		js:${PORTSDIR}/lang/spidermonkey \
		pcre:${PORTSDIR}/devel/pcre \
		nspr4:${PORTSDIR}/devel/nspr \
		execinfo.1:${PORTSDIR}/devel/libexecinfo

CONFLICTS=	mongodb-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	"not yet ported to anything other than i386 and amd64"

USE_SCONS=	yes
SCONS_TARGET=	all
USE_RC_SUBR=	mongod

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 700042
BROKEN=		Does not build
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/local#${PREFIX}#g' ${WRKSRC}/SConstruct

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mongo ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mongod ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mongodump ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mongoexport ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mongofiles ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mongoimport ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mongorestore ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mongos ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mongosniff ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libmongoclient.a ${PREFIX}/lib

post-install:
	@if [ ! -f ${PREFIX}/etc/mongodb.conf ]; then \
		${TOUCH} ${PREFIX}/etc/mongodb.conf ; \
	fi

	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

.include <bsd.port.post.mk>
