#
# Ports collection makefile for:	scorched3d
# Date created:				Jan 5, 2003
# Whom:					mdodd
#
# $FreeBSD$

PORTNAME=		scorched3d
PORTVERSION=		0.${SCORCH_VERSION}${SCORCH_REVISION}
PORTREVISION=	4
CATEGORIES=		games
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}/Version%20${SCORCH_VERSION}/
DISTNAME=		Scorched3D-${SCORCH_VERSION}-src

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Scorched is a game based loosely on the classic DOS game

LIB_DEPENDS=		fftw3f:${PORTSDIR}/math/fftw3-float \
			fftw3:${PORTSDIR}/math/fftw3 \
			jpeg:${PORTSDIR}/graphics/jpeg \
			png:${PORTSDIR}/graphics/png

SCORCH_VERSION=		42.1

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
.endif
USE_OPENAL=	al alut
USE_SDL=		mixer net sdl
GNU_CONFIGURE=		yes
USE_GL=			yes
USE_GMAKE=		yes
USE_AUTOTOOLS=	automake:15 autoconf:262
USE_PERL5=	yes
USE_WX=		2.4+
WX_CONF_ARGS=	absolute
USE_DOS2UNIX=	mkinstalldirs

WRKSRC=			${WRKDIR}/scorched
AUTOMAKE_ARGS=		--foreign
CONFIGURE_ARGS=		--program-prefix='' \
			--prefix=${PREFIX}/games/scorched3d \
			--datadir=${PREFIX}/games/scorched3d
.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--with-mysql
.endif
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ARGS=		ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" \
			AUTOMAKE="${TRUE}" AUTOHEADER="${TRUE}"

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g' \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's,png_infopp_NULL,NULL,g' \
		${WRKSRC}/src/common/image/ImagePng.cpp

pre-configure:
	@cd ${WRKSRC}/scripts && ${PERL} createAMMakefile.pl
	@cd ${WRKSRC} && ${ACLOCAL}

pre-install:
	@${MKDIR} ${PREFIX}/games/scorched3d

.include <bsd.port.post.mk>
