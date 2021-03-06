# New ports collection Makefile for:	proxy-suite
# Date created:				06 April 2001
# Whom:					Thomas Quinot <thomas@cuivre.fr.eu.org>
#
# $FreeBSD$
#

PORTNAME=	proxy-suite
PORTVERSION=	1.9.2.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.suse.com/pub/projects/proxy-suite/src/ \
		ftp://ftp.gwdg.de/pub/linux/suse/ftp.suse.com/projects/proxy-suite/src/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.gwdg.de/pub/linux/suse/ftp.suse.com/projects/proxy-suite/src/

MAINTAINER=	thomas@cuivre.fr.eu.org
COMMENT=	The SuSE Proxy-Suite, a set of programs to enhance firewall security

USE_AUTOTOOLS=	autoconf:262
USE_GMAKE=	yes
USE_BZIP2=	yes

#
# basic configure args
#
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-libwrap=/usr/lib --with-regex \
		--localstatedir=/var/run \
		--enable-warnings --enable-so-linger \
		--disable-proc-mods

#
# OPTIONAL: RFC1579 support -- not complete yet.
#
.if defined(WITH_RFC1579)
CONFIGURE_ARGS+=	--enable-rfc1579
.endif

#
# OPTIONAL: include ldap-support
#
.if defined(WITH_LDAP)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-libldap=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--without-libldap
.endif

#
# OPTIONAL: re-build the sgml documentation (postscript, html)
# unfortunatenly this docu it is not up to date :-((
# reading of the manual pages and HOWTO's makes more sense...
#
.if !defined(WITH_SGMLDOC)
ALL_TARGET=	 -C ftp-proxy
.endif

MAN8=		ftp-proxy.8
MAN5=		ftp-proxy.conf.5
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

pre-install:
	@${STRIP_CMD} ${WRKSRC}/ftp-proxy/ftp-proxy

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
