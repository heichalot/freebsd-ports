# New ports collection makefile for:	ocaml-sem
# Date created:		19 April 2005
# Whom:			asmith
#
# $FreeBSD$
#

PORTNAME=	sem
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://ocaml-sem.sourceforge.net/files/ \
		SF/ocaml-${PORTNAME}/${PORTNAME}/${PORTVERSION}		

PKGNAMEPREFIX=	ocaml-

MAINTAINER=	argentoff@gmail.com
COMMENT=	POSIX semaphores for OCaml

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib

MAKE_ENV=	OCAML_LIB_INSTALL="${PREFIX}/lib/ocaml/site-lib/sem" \
		INCDIRS="${LOCALBASE}/include" LIBDIRS="${LOCALBASE}/lib"
MAKE_JOBS_UNSAFE=	yes

.if !defined(WITH_CUSTOM)
MAKE_ENV+=	NO_CUSTOM=y
.endif
ALL_TARGET=	all

PORTDOCS=	html README
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

USE_BZIP2=	yes
USE_GMAKE=	yes

PKGDEINSTALL=	${PKGINSTALL}

post-install:
	@${FIND} ${PREFIX}/lib/ocaml/site-lib/sem -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm lib/ocaml/site-lib/sem" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ocamlfind remove sem 2>/dev/null || true" >> ${TMPPLIST}
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
	${CP} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
