# Ports collection makefile for:  authforce
# Date created:                   08.05.2002
# Whom:                           ache
#
# $FreeBSD$
#

PORTNAME=	authforce
PORTVERSION=	0.9.6
PORTREVISION=	9
CATEGORIES=	security www
MASTER_SITES=	http://www.divineinvasion.net/authforce/

MAINTAINER=	ache@FreeBSD.org
COMMENT=	HTTP authentication brute forcer

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl

USE_BZIP2=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="-lintl"

MAN1=		authforce.1
MANCOMPRESSED=	yes
INFO=		authforce

.include <bsd.port.mk>
