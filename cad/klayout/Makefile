# Ports collection makefile for:  klayout
# Date created:			  Sat, Apr 28, 2007
# Whom:				  Hiroki Sato <hrs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	klayout
PORTVERSION=	0.19.3
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.klayout.de/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A Qt-based GDS2 Viewer

USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network moc_build sql uic_build \
		rcc_build qt3support xml
PLIST_FILES=	bin/klayout \
		bin/strm2gds \
		bin/strm2oas \
		bin/strm2txt \
		bin/strmclip \
		bin/strmcmp \
		bin/strmxor

PLATFORMKEYWORD=	freebsd-32-gcc-release

do-build:
	cd ${WRKSRC} && \
		${SH} build.sh -platform ${PLATFORMKEYWORD} \
			-qtbin ${QT_PREFIX}/bin \
			-qtinc ${QT_INCDIR} \
			-qtlib ${QT_LIBDIR}

do-install:
	cd ${WRKSRC}/bin.${PLATFORMKEYWORD} && \
		${INSTALL_PROGRAM} ${PLIST_FILES:S,^bin/,,} \
		${PREFIX}/bin

.include <bsd.port.mk>
