# New ports collection makefile for:	nabi
# Date created:		5 August 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nabi
PORTVERSION=	0.99.7
CATEGORIES=	korean gnome
MASTER_SITES=	http://kldp.net/frs/download.php/5633/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hangul X Input Method for Everywhere

LIB_DEPENDS=	hangul.1:${PORTSDIR}/korean/libhangul

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"

.if defined(WITH_LAYOUT_390)
CONFIGURE_ARGS=	--with-default-keyboard=39
.elif defined(WITH_LAYOUT_3FINAL)
CONFIGURE_ARGS=	--with-default-keyboard=3f
.endif

.include <bsd.port.mk>
