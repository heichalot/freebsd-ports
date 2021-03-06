# New ports collection makefile for:	ocaml cryptokit
# Date created:		Thu Jan  9 03:04:06 BRST 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cryptokit
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://caml.inria.fr/distrib/bazar-ocaml/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	Jaap.Boender@pps.jussieu.fr
COMMENT=	A variety of cryptographic primitives for Objective Caml

USE_OCAML=	yes
USE_OCAML_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

ALL_TARGET=	all allopt

.ifndef(NOPORTDOCS)
ALL_TARGET+=	doc

PORTDOCS=	*
.endif

DOC_FILES=	Changes LICENSE README

post-configure:
# CFLAGS,PREFIX safeness
	@${REINPLACE_CMD} -E -e \
		's|^(INSTALLDIR).*$$|\1=${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}|; \
		s|^CFLAGS=|CFLAGS\+=|; \
		s|(^CFLAGS.*)-O|\1|' \
		${WRKSRC}/Makefile

pre-install:
# in pre-install to make sure we're using the correct user:group
# combo
	@${REINPLACE_CMD} -E -e \
		's|cp |${INSTALL_DATA} |' \
		${WRKSRC}/Makefile
# create installation dir
	@${MKDIR} ${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/stublibs

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/doc
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}/doc
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${INSTALL_DATA} ${FILESDIR}/META ${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

.include <bsd.port.post.mk>
