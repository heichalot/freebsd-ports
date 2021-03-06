# New ports collection makefile for:	gpgme
# Date created:		15 June 2001
# Whom:			teramoto@comm.eng.osaka-u.ac.jp
#
# $FreeBSD$
#

PORTNAME=	gpgme
PORTVERSION=	1.3.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	gpgme
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	A library to make access to GnuPG easier

LIB_DEPENDS=	gpg-error.0:${PORTSDIR}/security/libgpg-error

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS=	--includedir=${PREFIX}/include/gpgme \
		--with-g13=no

INFO=		gpgme
PORTDOCS=	AUTHORS ChangeLog COPYING COPYING.LESSER INSTALL \
		NEWS README THANKS TODO

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS=	GNUPG1 "Use GNUPG 1.x instead of GNUPG 2.x" off \
		PTH "Build alternate lib with GNU portable threads" off \
		UISERVER "Enable the GNUPG UI Server support" off

.include <bsd.port.pre.mk>

.if defined(WITH_GNUPG1)
BUILD_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg1
RUN_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg1
CONFIGURE_ARGS+=--with-gpg=${LOCALBASE}/bin/gpg \
		--with-gpgsm=no \
		--with-gpgconf=no
.else
BUILD_DEPENDS+=	gpg2:${PORTSDIR}/security/gnupg
RUN_DEPENDS+=	gpg2:${PORTSDIR}/security/gnupg
CONFIGURE_ARGS+=--with-gpg=${LOCALBASE}/bin/gpg2 \
		--with-gpgconf=${LOCALBASE}/bin/gpgconf
.if exists(${LOCALBASE}/bin/gpgsm)
LIB_DEPENDS+=	assuan.0:${PORTSDIR}/security/libassuan
CONFIGURE_ARGS+=--with-gpgsm=${LOCALBASE}/bin/gpgsm
.else
CONFIGURE_ARGS+=--with-gpgsm=no
.endif
.endif

.if defined(WITH_PTH)
LIB_DEPENDS+=	pth:${PORTSDIR}/devel/pth
PLIST_SUB+=	WITH_PTH=''
.else
CONFIGURE_ARGS+=--without-pth --without-pth-test
PLIST_SUB+=	WITH_PTH='@comment '
.endif

.if defined(WITH_UISERVER)
CONFIGURE_ARGS+=--enable-fd-passing
LIB_DEPENDS+=	assuan.0:${PORTSDIR}/security/libassuan
.endif

verify: checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.sig

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
					${WRKSRC}/${CONFIGURE_SCRIPT} \
					${WRKSRC}/src/Makefile.in \
					${WRKSRC}/src/gpgme-config.in
	@${REINPLACE_CMD} -e 's|^clfilesdir.*|clfilesdir=$$\(libdir\)/common-lisp/gpgme|g' \
					${WRKSRC}/lang/cl/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
