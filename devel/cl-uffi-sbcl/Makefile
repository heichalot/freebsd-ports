# New ports collection Makefile for:	cl-uffi-sbcl
# Date created:				19 August 2004
# Whom:					Matthew X. Economou <xenophon+fbsdports@irtnog.org>
#
# $FreeBSD$

PORTNAME=	uffi
PORTVERSION=	1.6.2
PORTREVISION=	2
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Universal Foreign Function Interface for Common Lisp (SBCL binaries)

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/uffi/uffi.asd:${PORTSDIR}/devel/cl-uffi
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/uffi/uffi.asd:${PORTSDIR}/devel/cl-uffi

USE_ASDF_FASL=	yes
FASL_TARGET=	sbcl
FASL_BUILD=	yes

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
