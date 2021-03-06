# New ports collection makefile for:	iiimf-le-unit
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	le-unit
PORTVERSION=	12.2
PORTREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	iiimf-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IIIMF UNIcode Table based generic composition engine

LIB_DEPENDS=	iiimp.1:${PORTSDIR}/textproc/iiimf-protocol-lib \
		iiimcf.3:${PORTSDIR}/textproc/iiimf-client-lib
RUN_DEPENDS=	iiimd:${PORTSDIR}/textproc/iiimf-server

ONLY_FOR_ARCHS=	i386

USE_BZIP2=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_GNOME=	libxml2
USE_XORG=	x11
USE_AUTOTOOLS=	automake:19:env autoconf:262:env libtool:22:env

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}
BUILDDIR=	${WRKSRC}/leif

.include <bsd.port.pre.mk>

CFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib -liconv ${PTHREAD_LIBS}
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

post-patch:
	${REINPLACE_CMD} \
		-e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		-e "s,%%PREFIX%%,${PREFIX},g" \
		${WRKSRC}/Makefile ${BUILDDIR}/Makefile.am \
		${BUILDDIR}/../lib/EIMIL/Makefile.am

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${GMAKE} reconfig
	@${REINPLACE_CMD} -e "/^ltmain=/!s^\$$ac_aux_dir/ltmain.sh^${LIBTOOLFLAGS} ${LTMAIN}^g" \
			  -e '/^LIBTOOL=/s^\$$(top_builddir)/libtool^${LIBTOOL}^g' \
		${BUILDDIR}/../lib/EIMIL/configure ${BUILDDIR}/configure
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${GMAKE} config

pre-install:
	${REINPLACE_CMD} \
		-e "/^BUILDDIRS/s,lib/EIMIL,,g" \
		${WRKSRC}/Makefile

.include <bsd.port.post.mk>
