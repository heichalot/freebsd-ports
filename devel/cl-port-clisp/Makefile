# New ports collection Makefile for:	cl-port-clisp
# Date created:				12 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=	port
PORTVERSION=	2002.10.02.1
PORTREVISION=	4
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Cross-Lisp portability package

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/port/port.asd:${PORTSDIR}/devel/cl-port
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/port/port.asd:${PORTSDIR}/devel/cl-port

USE_ASDF_FASL=	yes
FASL_TARGET=	clisp
FASL_BUILD=	yes

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
