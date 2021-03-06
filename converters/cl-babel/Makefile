# New ports collection makefile for:	cl-babel
# Date created:				20 January 2010
# Whom:					Jimmy Olgeni <olgeni@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	babel
PORTVERSION=	2010.01.16
PORTREVISION=	1
CATEGORIES=	converters lisp
PKGNAMEPREFIX=	cl-
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	olgeni

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A charset encoding/decoding library written in Common Lisp

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/alexandria.asd:${PORTSDIR}/devel/cl-alexandria \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/trivial-features.asd:${PORTSDIR}/devel/cl-trivial-features \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-gray-streams/trivial-gray-streams.asd:${PORTSDIR}/devel/cl-trivial-gray-streams
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/alexandria/alexandria.asd:${PORTSDIR}/devel/cl-alexandria \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/trivial-features.asd:${PORTSDIR}/devel/cl-trivial-features \
		${LOCALBASE}/${CL_LIBDIR_REL}/trivial-gray-streams/trivial-gray-streams.asd:${PORTSDIR}/devel/cl-trivial-gray-streams

NO_BUILD=	yes

USE_ASDF=	yes

do-install:
	@${MKDIR} ${ASDF_PATHNAME}
	@${MKDIR} ${ASDF_PATHNAME}/src
	@${INSTALL_DATA} ${WRKSRC}/src/*.lisp ${ASDF_PATHNAME}/src
	@${INSTALL_DATA} ${WRKSRC}/babel.asd ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/babel-streams.asd ${ASDF_PATHNAME}
	@${LN} -sf ${ASDF_PATHNAME}/*.asd ${ASDF_REGISTRY}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in COPYRIGHT HEADER NOTES README
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/tests/* ${EXAMPLESDIR}
.endif

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
