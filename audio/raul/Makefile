# New ports collection makefile for:	raul
# Date created:		2008-07-22
# Whom:			Edward Tomasz Napierala <trasz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	raul
PORTVERSION=	0.5.1
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	C++ utility library primarily aimed at audio/musical applications

LIB_DEPENDS=	boost_date_time.4:${PORTSDIR}/devel/boost-libs \
		jack.0:${PORTSDIR}/audio/jack \
		lash.2:${PORTSDIR}/audio/lash \
		glibmm-2.4.1:${PORTSDIR}/devel/glibmm

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
CXXFLAGS+=	${CFLAGS}
CONFIGURE_ENV=	"-I${LOCALBASE}/include"
CONFIGURE_ENV=	"CXXFLAGS=${CFLAGS} -I${LOCALBASE}/include"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		Does not compile
.endif

.include <bsd.port.post.mk>
