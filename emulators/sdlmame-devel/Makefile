# New ports collection makefile for:	sdlmame
# Date created:				2007-01-10
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	sdlmame-devel
PORTVERSION=	0.135u3
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.arcadebsd.org/pub/ArcadeBSD/ports/distfiles/ \
		http://rbelmont.mameworld.info/
DISTNAME=	sdlmame${PORTVERSION:S/.//}

MAINTAINER=	elbarto@ArcadeBSD.org
COMMENT=	SDL port of the popular MAME (Multi Arcade Machine Emulator)

FETCH_ENV=	HTTP_USER_AGENT=defined
USE_ZIP=	yes
USE_XORG=	xext xrender xinerama xi
USE_GL=		gl
USE_GNOME?=	gtk20 gconf2
USE_GMAKE=	yes
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"
USE_SDL=	sdl
MAKEFILE=	makefile
ONLY_FOR_ARCHS=	i386 amd64
SUB_FILES=	pkg-message

OPTIONS=	DEBUG "Build sdlmame debugger" off

IGNORE=		outdated, use emulators/mame

.include <bsd.port.pre.mk>

.if !defined(WITH_DEBUG)
USE_GNOME=		#
EXTRA_PATCHES+=		${FILESDIR}/sdl.mak.patch
.endif

MAKE_JOBS_SAFE=		yes

.if ${ARCH} == "amd64"
MAKE_ENV+=	PTR64=1
.endif
.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|ui.bdf|${DATADIR}/ui.bdf|g" ${WRKSRC}/src/emu/ui.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${MKDIR} ${PREFIX}/libexec/${PORTNAME}
.for f in chdman ldresample ldverify testkeys unidasm
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/libexec/${PORTNAME}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs ${DOCSDIR}
.endif
	${MKDIR} ${DATADIR}
	${CP} ${WRKSRC}/ui.bdf ${DATADIR}/
	${CP} -R ${WRKSRC}/keymaps ${DATADIR}/
	${MKDIR} ${EXAMPLESDIR}
	${CP} ${FILESDIR}/mame.ini ${EXAMPLESDIR}

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
