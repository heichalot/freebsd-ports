# ex:ts=8
# New ports collection makefile for:   freecell-solver
# Date created:                Fab 9, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freecell-solver
PORTVERSION=	2.42.0
CATEGORIES=	games
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/ \
		BERLIOS/fc-solve

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program that automatically solves games of Freecell

OPTIONS=	JUDY "Use libJudy for states and stacks storage" off \
		REDBLACK "Use libredblack for states and stacks storage" off \
		TCMALLOC "Use Google's TCMalloc" off

USE_BZIP2=	yes
USE_PERL5_BUILD=	yes
USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes
USE_LDCONFIG=	yes

MAN6=	fc-solve-board_gen.6 \
	fc-solve.6 \
	freecell-solver-range-parallel-solve.6 \
	make-aisleriot-freecell-board.6 \
	make-gnome-freecell-board.6 \
	make_pysol_freecell_board.py.6 \
	pi-make-microsoft-freecell-board.6

CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.pre.mk>

.if defined(WITH_JUDY) && defined(WITH_REDBLACK)
IGNORE=		you cannot enable both JUDY and REDBLACK
.endif

.if defined(WITH_JUDY)
LIB_DEPENDS+=	Judy.1:${PORTSDIR}/devel/judy
CMAKE_ARGS+=	-DFCS_STACK_STORAGE:STRING="FCS_STACK_STORAGE_JUDY" \
		-DFCS_STATE_STORAGE:STRING="FCS_STATE_STORAGE_JUDY"
.endif

.if defined(WITH_REDBLACK)
LIB_DEPENDS+=	redblack.2:${PORTSDIR}/devel/libredblack
CMAKE_ARGS+=	-DFCS_STACK_STORAGE:STRING="FCS_STACK_STORAGE_LIBREDBLACK_TREE" \
		-DFCS_STATE_STORAGE:STRING="FCS_STATE_STORAGE_LIBREDBLACK_TREE"
.endif

.if defined(WITH_TCMALLOC)
LIB_DEPENDS+=	tcmalloc.0:${PORTSDIR}/devel/google-perftools
CMAKE_ARGS+=	-DFCS_USE_TCMALLOC:BOOL=ON
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS.txt HACKING.txt INSTALL.txt NEWS.txt README.txt \
	README.win32.txt TODO.txt USAGE.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for file in ctypes-test.py
	${INSTALL_DATA} ${WRKSRC}/examples/${file} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.post.mk>
