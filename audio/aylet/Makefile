# New ports collection makefile for:	aylet
# Date created:				9 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	aylet
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/Linux/apps/sound/players/ \
		CRITICAL
PKGNAMEPREFIX?=

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A command line player for the .ay audio file format

USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

ALL_TARGET?=	${PORTNAME}
CFLAGS+=	-DDRIVER_OSS -I${LOCALBASE}/include

.if ${PKGNAMEPREFIX} == ""

MAN1=		aylet.1
PLIST_FILES=	bin/aylet

.endif

aylet-post-patch:
.for flag in CC CFLAGS
	@${REINPLACE_CMD} -e 's|^${flag}=|${flag}?=|' \
		${WRKSRC}/Makefile
.endfor
	@${REINPLACE_CMD} -e 's|\((CC)\)\ \-o|\1 $$\(CFLAGS) -o|' \
			${WRKSRC}/Makefile

.if ${PKGNAMEPREFIX} == ""

post-patch: aylet-post-patch

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
