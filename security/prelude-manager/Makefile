# New ports collection makefile for:	prelude-manager
# Date created:			Sun Aug 4 19:31:17 CEST 2002
# Whom:				Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$

PORTNAME=	prelude-manager
PORTVERSION=	0.9.14.2
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=   http://www.prelude-ids.com/download/releases/%SUBDIR%/
MASTER_SITE_SUBDIR=     ${PORTNAME} ${PORTNAME}/old

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Prelude Network Intrusion Detection System central logging point

LIB_DEPENDS+=	prelude.20:${PORTSDIR}/security/libprelude \
		gnutls.40:${PORTSDIR}/security/gnutls

USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf:262
USE_RC_SUBR=	prelude-manager.sh
CONFIGURE_ARGS=		--with-html-dir=${PREFIX}/share/doc \
			--localstatedir=/var
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="${LIBS} -L${LOCALBASE}/lib"

PRELUDEUSER?=	prelude
PRELUDEGROUP?=	prelude
PRELUDEDIR?=	/nonexistent

PRELUDEUID=	281
PRELUDEGID=	${PRELUDEUID}

MAN1=		prelude-manager.1

.include <bsd.port.pre.mk>

PLIST_SUB+=	PRELUDEDIR=${PRELUDEDIR} \
		PRELUDEUSER=${PRELUDEUSER} \
		PRELUDEGROUP=${PRELUDEGROUP}

SUB_FILES=	pkg-install \
		pkg-deinstall

SUB_LIST=	PREFIX=${PREFIX} \
		${PLIST_SUB}

.if defined(WITHOUT_XML)
PLIST_SUB+=		WITH_XML="@comment "
CONFIGURE_ARGS+=	--disable-xmltest --without-xml
.else
LIB_DEPENDS+=	xml2.5:${PORTSDIR}/textproc/libxml2
PLIST_SUB+=	WITH_XML=""
.endif

.if defined(WITHOUT_PRELUDEDB)
PLIST_SUB+=	WITH_PRELUDEDB="@comment "
.else
LIB_DEPENDS+=	preludedb.4:${PORTSDIR}/security/libpreludedb
PLIST_SUB+=	WITH_PRELUDEDB=""
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/prelude-manager/prelude-manager.conf ]; then \
	   ${CP} -p ${PREFIX}/etc/prelude-manager/prelude-manager.conf-dist \
	      ${PREFIX}/etc/prelude-manager/prelude-manager.conf ; \
	fi
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/smtp
	${INSTALL_DATA} ${WRKSRC}/plugins/reports/smtp/template.example ${EXAMPLESDIR}/smtp/template.example
.endif

.include <bsd.port.post.mk>
