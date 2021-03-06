# New ports collection makefile for:	BIEW
# Date created:				04 February 2000
# Whom:					Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	biew
PORTVERSION=	6.0.0
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}-src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Binary file viewer and editor

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--cc="${CC}" --with-extraincdir="${LOCALBASE}/include" \
		--ld="${CC}" --with-extralibdir="${LOCALBASE}/lib" \
		--prefix="${PREFIX}" --datadir="${DATADIR}"
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
MAKEFILE=	makefile
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.//g}

PLIST_FILES=	bin/biew \
		%%DATADIR%%/assembly.skn \
		%%DATADIR%%/biew.hlp \
		%%DATADIR%%/golded.skn \
		%%DATADIR%%/insight.skn \
		%%DATADIR%%/standard.skn
PLIST_DIRS=	%%DATADIR%%

MAN1=		biew.1
PORTDOCS=	biew_en.txt biew_ru.txt develop.en develop.ru file_ini.en \
		file_ini.ru licence.en licence.ru release.txt unix.txt

OPTIONS=	SLANG	"Use S-Lang based display renderer"	on

.include <bsd.port.pre.mk>

.if defined(WITH_SLANG)
LIB_DEPENDS=	slang.2:${PORTSDIR}/devel/libslang2
CONFIGURE_ARGS+=	--enable-slang
.else
CONFIGURE_ARGS+=	--enable-curses
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},' ${WRKSRC}/configure

post-build:
	${LN} -sf ../../biewlib ${WRKSRC}/tools/biewhlp/biewlib
	cd ${WRKSRC}/tools/biewhlp && ${GMAKE} ${MAKE_ARGS}
	${LN} -sf ../../biewlib ${WRKSRC}/tools/lzss/biewlib
	cd ${WRKSRC}/tools/lzss && ${GMAKE} ${MAKE_ARGS}
	(cd ${WRKSRC}/hlp; ${LN} -sf ../tools/biewhlp/biewhlp; \
	${LN} -sf ../tools/lzss/lzss; ./biewhlp biewhlp.prj)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/biew ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin_rc/skn/*.skn ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/hlp/biew.hlp ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/doc/biew.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
