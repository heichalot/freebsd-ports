# ports collection makefile for:   mikmod304
# Date created:        16 November 1998
# Whom:                yoshiaki Uchikawa
#
# $FreeBSD$
#

PORTNAME=	mikmod
PORTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://mikmod.raphnet.net/files/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Mod player which plays MTM, STM, XM, MOD, S3M, ULT, UNI and IT mods

LIB_DEPENDS=	mikmod.2:${PORTSDIR}/audio/libmikmod

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

.ifdef (WITH_COLOR)
CONFIGURE_ARGS+=	--enable-color-interface
.endif

MAN1=		mikmod.1
PLIST_FILES=	bin/mikmod

PORTSCOUT=	skipv:3.3.0

.include <bsd.port.mk>
