# New ports collection makefile for:   smartmontools
# Date created:        12 October 2003
# Whom:                Eduard Martinescu
#
# $FreeBSD$
#

PORTNAME=	smartmontools
PORTVERSION=	5.39.1
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	S.M.A.R.T. disk monitoring tools

CONFLICTS=	smartmontools-devel-[0-9]*

USE_GMAKE=	yes
# hack to prevent gmake failure on 6.xx
GMAKE=		make
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-docdir=${DOCSDIR} --enable-sample \
    --disable-dependency-tracking --enable-drivedb

SUB_FILES=	pkg-message smart
USE_RC_SUBR=	smartd

MAN5=		smartd.conf.5
MAN8=		smartd.8 smartctl.8

CFLAGS:=	${CFLAGS:S/-O2/-O/} -Wno-write-strings

post-patch:
	@${REINPLACE_CMD} -e 's| install-initdDATA | |' ${WRKSRC}/Makefile.in

post-install:
	${MKDIR} ${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/smart ${PREFIX}/etc/periodic/daily/smart
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
