# New ports collection makefile for:	git-merge-changelog
# Date created:		19 April 2010
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	git-merge-changelog
PORTVERSION=	${GNULIB_PORTVERSION}
PORTREVISION=	${GNULIB_PORTREVISION}
PORTEPOCH=	${GNULIB_PORTEPOCH}
CATEGORIES=	devel
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Git "merge" driver for GNU style ChangeLog files

EXTRACT_DEPENDS=	${GNULIB_DIR}/lib/${PORTNAME}.c:${GNULIB_PORTDIR}	\
			automake-1.10:${PORTSDIR}/devel/automake110		\
			autoconf-2.62:${PORTSDIR}/devel/autoconf262

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

GNULIB_DIR=	${LOCALBASE}/share/gnulib
GNULIB_PORT=	devel/gnulib
GNULIB_PORTDIR=	${PORTSDIR}/${GNULIB_PORT}
GNULIB_PORTVERSION!=	cd ${GNULIB_PORTDIR} && ${MAKE} -V PORTVERSION
GNULIB_PORTREVISION!=	cd ${GNULIB_PORTDIR} && ${MAKE} -V PORTREVISION
GNULIB_PORTEPOCH!=	cd ${GNULIB_PORTDIR} && ${MAKE} -V PORTEPOCH
GNULIB_WRKSRC!=	cd ${GNULIB_PORTDIR} && ${MAKE} -V WRKSRC

do-extract:
	${MKDIR} ${WRKDIR}
	cd ${GNULIB_DIR}; ./gnulib-tool --create-testdir --dir="${WRKSRC}" ${PORTNAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
