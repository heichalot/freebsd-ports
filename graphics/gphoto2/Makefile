# New ports collection makefile for: 	gphoto
# Date created:		26 May 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	gphoto2
PORTVERSION=	2.4.9
CATEGORIES=	graphics
MASTER_SITES=	SF/gphoto/gphoto/${PORTVERSION}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	A command-line frontend to libgphoto2

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		gphoto2.2:${PORTSDIR}/graphics/libgphoto2

USE_GNOME=	gnometarget
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--without-cdk
MAKE_JOBS_SAFE=	yes

MAN1=		gphoto2.1

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

OPTIONS=	AALIB "Enable command line capture preview (aalib)" on

.include <bsd.port.pre.mk>

.if defined(WITH_AALIB)
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib \
		jpeg.11:${PORTSDIR}/graphics/jpeg
.else
CONFIGURE_ARGS+=--without-aalib --without-jpeg
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREADS_LIBS:S/"//g}|g ; \
		 s|-g -Wall||g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
.for file in NEWS
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
