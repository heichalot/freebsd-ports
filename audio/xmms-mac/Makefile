# New ports collection makefile for:	xmms-mac
# Date Created:				23 February 2005
# Whom:					<arundel@h3c.de>
#
# $FreeBSD$

PORTNAME=	mac
PORTVERSION=	0.3.1
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://repository.slacky.eu/slackware-12.2/multimedia/${PKGNAMEPREFIX}${PORTNAME}/${PORTVERSION}/src/ \
		http://ftp.hosteurope.de/mirror/ftp.frugalware.org/pub/frugalware/frugalware-testing/source/xlib-extra/${PKGNAMEPREFIX}${PORTNAME}/ \
		http://ftp.yz.yamagata-u.ac.jp/pub/linux/plamo/Plamo-src/contrib/Sound/MAC/ \
		http://www10.frugalware.org/pub/linux/frugalware/frugalware-current/source/xlib-extra/${PKGNAMEPREFIX}${PORTNAME}/ \
		CENKES
PKGNAMEPREFIX=	xmms-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	alexbestms@wwu.de
COMMENT=	Native Monkey Audio Codec plugin for the XMMS1 Multimedia Player

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms \
		mac.2:${PORTSDIR}/audio/mac

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	CPPFLAGS="${CPPFLAGS}"
USE_AUTOTOOLS=	autoconf:262
CPPFLAGS+=	"-I${LOCALBASE}/include"
USE_LDCONFIG=	yes

PLIST_FILES=	lib/xmms/Input/libxmms-mac.so

post-patch:
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/aclocal.m4

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/.libs/libxmms-mac.so ${PREFIX}/lib/xmms/Input

.include <bsd.port.mk>
