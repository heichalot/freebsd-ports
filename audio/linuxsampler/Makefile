# New ports collection makefile for:	linuxsampler
# Date created:		2007-01-24
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	linuxsampler
PORTVERSION=	1.0.0
CATEGORIES=	audio
MASTER_SITES=	http://download.linuxsampler.org/packages/

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Modular MIDI sampler

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack \
		gig.10:${PORTSDIR}/audio/libgig \
		sqlite3.8:${PORTSDIR}/databases/sqlite3

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	"HAVE_UNIX98=1"
CFLAGS+=	"-I${LOCALBASE}/include"
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget
USE_LDCONFIG=	yes
RESTRICTED=	no commercial use
MAN1=		linuxsampler.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		Does not compile
.endif

.if ${ARCH} == "sparc64"
IGNORE=		Not yet ported to sparc64
.endif

.include <bsd.port.post.mk>
