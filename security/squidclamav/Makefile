# New ports collection makefile for:	squidclamav
# Date created:		2008-06-02
# Whom: 		Laurent LEVIER <llevier@argosnet.com>
#
# $FreeBSD$
#

PORTNAME=	squidclamav
PORTVERSION=	5.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	llevier@argosnet.com
COMMENT=	Squid interface to ClamAV

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
NO_LATEST_LINK=	yes
SUB_FILES=	pkg-message

PLIST_FILES=	bin/${PORTNAME} etc/${PORTNAME}.conf.dist

post-configure:
	@${REINPLACE_CMD} -E 's|^(LDFLAGS = ).*|\1-L${LOCALBASE}/lib|' \
		${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/etc/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf.dist
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
