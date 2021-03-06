# Common stuff for Licq-based ports
# $FreeBSD$

PKGNAMEPREFIX=		licq-
LICQ_VER=		1.3.9
QT_LICQ_VER=		1.3.9
OSD_LICQ_VER=		1.3.9
CONSOLE_LICQ_VER=	1.3.9
.if ${PORTNAME} != "base"
RUN_DEPENDS+=		licq:${PORTSDIR}/${LICQ_PORT}
.endif
MASTER_SITES=		SF/licq/licq/${LICQ_VER}
DISTNAME=		${PKGNAMEPREFIX}${LICQ_VER}
DISTFILES=		${DISTNAME}.tar.bz2
GNU_CONFIGURE=		yes
MD5_FILE?=		${PORTSDIR}/${LICQ_PORT}/distinfo
USE_GMAKE=		yes
USE_BZIP2=		yes
WRKSRC?=		${WRKDIR}/${DISTNAME}/plugins/${PORTNAME}
PLIST_SUB+=		LICQ_DEVEL="@comment "
CXXFLAGS+=		-Wno-deprecated
CONFIGURE_ENV+=		CXXFLAGS="${CXXFLAGS}"
