# New ports collection makefile for: 	codelite
# Date created:				7 May 2008
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	codelite
DISTVERSION=	2.5.3.${SVN_REVISION}
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/Releases/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	An Open Source IDE for C/C++

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	xterm:${PORTSDIR}/x11/xterm

OPTIONS=	CSCOPE	"Enable CScope integration" OFF

USE_WX=		2.8
WX_UNICODE=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes

.include <bsd.port.pre.mk>

SVN_REVISION=	4075

.if defined(WITH_CSCOPE)
RUN_DEPENDS+=	cscope:${PORTSDIR}/devel/cscope
.endif

post-patch:
.if ${ARCH} == "amd64"
	${REINPLACE_CMD} -e '66s|=|= -fPIC|' ${WRKSRC}/configure
.endif
	${REINPLACE_CMD} -e 's|wx-config|${WX_CONFIG}|g' ${WRKSRC}/configure
#	Configure script does not respect --prefix
	${REINPLACE_CMD} -e '/^prefix/s|/usr|${PREFIX}|; \
	    /^plugins_dir/s|/usr/lib/codelite|${DATADIR}/plugins|' \
	    ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|$${cur_rev}|${SVN_REVISION}|' \
	    ${WRKSRC}/le_makerevision.sh
# 	CTags already installed
.if exists(${LOCALBASE}/include/readtags.h)
	${RM} ${WRKSRC}/CodeLite/readtags.h
.endif

.include <bsd.port.post.mk>
