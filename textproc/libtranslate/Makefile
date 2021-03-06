# New ports collection makefile for:	libtranslate
# Date created:			15 Jan 2005
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		libtranslate
PORTVERSION=		0.99
PORTREVISION=	5
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		ports@FreeBSD.org
COMMENT=		A natural language translation library

USE_GNOME=		glib20 gnomehack intlhack
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LDCONFIG=		yes
CPPFLAGS=		-I${LOCALBASE}/include
LDFLAGS=		-L${LOCALBASE}/lib
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=		--with-html-dir=${PREFIX}/share/doc

OPTIONS=		GENERIC "generic module" on \
			TALKFILTERS "talkfilters module" on

MAN1=			translate.1

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GENERIC)
CONFIGURE_ARGS+=	--disable-generic
PLIST_SUB+=		GENERIC="@comment "
.else
PLIST_SUB+=		GENERIC=""
USE_GNOME+=		libxml2
LIB_DEPENDS+=		soup-2.2:${PORTSDIR}/devel/libsoup22
MAN5+=			services.xml.5
.endif

.if defined(WITHOUT_TALKFILTERS)
CONFIGURE_ARGS+=	--disable-talkfilters
PLIST_SUB+=		TALKFILTERS="@comment "
.else
PLIST_SUB+=		TALKFILTERS=""
LIB_DEPENDS+=		talkfilters:${PORTSDIR}/misc/talkfilters
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.post.mk>
