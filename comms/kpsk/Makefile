# New ports collection makefile for:	kpsk
# Date created:		2002-06-12
# Whom:			Patrick Gardella <patrick@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kpsk
PORTVERSION=	1.0
PORTREVISION=	9
CATEGORIES=	comms kde hamradio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/_.tar.bz2%20files

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	A PSK31 digital radio communications application for the KDE

LIB_DEPENDS=	db4:${PORTSDIR}/databases/db4

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="-D_POSIX_C_SOURCE -I${LOCALBASE}/include" \
		USER_LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-debug=full

post-patch:
	@${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g; \
		s,-pedantic,,g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's/-ldb-4.0/-ldb4/g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL_MAN} ${WRKSRC}/doc/en/HTML/handbook.html ${PREFIX}/share/doc/HTML/en/kpsk/
.endif

.include <bsd.port.mk>
