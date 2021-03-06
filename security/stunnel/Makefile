# New ports collection makefile for:	stunnel
# Date created:		Mon Jan 11 11:53:54 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $FreeBSD$
#

PORTNAME=	stunnel
PORTVERSION=	4.33
CATEGORIES=	security
MASTER_SITES=	http://www.stunnel.org/download/stunnel/src/ \
		ftp://stunnel.mirt.net/stunnel/ \
		ftp://stunnel.mirt.net/stunnel/OBSOLETE/ \
		ftp://opensores.thebunker.net/pub/mirrors/stunnel/download/stunnel/src/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	SSL encryption wrapper for standard network daemons

USE_AUTOTOOLS=	libtool:22
USE_OPENSSL=	YES
USE_RC_SUBR=	stunnel

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var/tmp --with-pem-dir=${PEM_DIR} \
		--enable-static --disable-fips

.if !defined(NOPORTDOCS)
MAN8=		stunnel.8 stunnel.fr.8 stunnel.pl.8
.endif

PEM_DIR?=	${PREFIX}/etc

OPTIONS=	FORK	"use the fork(3) threading model"	off \
		PTHREAD	"use the pthread(3) threading model (default)"	on \
		UCONTEXT	"use the ucontext(3) threading model"	off \
		DH	"use Diffie-Hellman key negotiation" off \
		IPV6	"enable IPv6 support" off \
		LIBWRAP	"use TCP wrappers" on

.include <bsd.port.pre.mk>

.if defined(WITH_DH)
CONFIGURE_ARGS+=	--enable-dh
.else
CONFIGURE_ARGS+=	--disable-dh
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITH_LIBWRAP)
CONFIGURE_ARGS+=	--enable-libwrap
LDFLAGS+=		-lwrap
.else
CONFIGURE_ARGS+=	--disable-libwrap
.endif

.if defined(WITH_UCONTEXT) && defined(WITH_FORK) || defined(WITH_UCONTEXT) && defined(WITH_PTHREAD) || defined(WITH_FORK) && defined(WITH_PTHREAD)
BROKEN=	'The WITH_UCONTEXT, WITH_FORK and WITH_PTHREAD options are mutually exclusive - please specify at most one of them, the default is WITH_PTHREAD'
.endif

.if defined(WITH_UCONTEXT)
CONFIGURE_ARGS+=--with-threads=ucontext
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} ${PTHREAD_CFLAGS}" LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
.elif defined(WITH_FORK)
CONFIGURE_ARGS+=--with-threads=fork
.else
CONFIGURE_ARGS+=--with-threads=pthread
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} ${PTHREAD_CFLAGS}" LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
.endif

post-patch:
# place files under /var/tmp so that this can be run by an unprivileged
# user stunnel and group stunnel
	@${REINPLACE_CMD} -E -e 's|\@prefix\@/var/lib/stunnel/|/var/tmp/stunnel|; \
		s|nobody|stunnel|;s|nogroup|stunnel|' \
		${WRKSRC}/tools/stunnel.conf-sample.in
	${REINPLACE_CMD} -E -e 's|\$$\(prefix\)/var/run/stunnel/stunnel.pid|$$(localstatedir)/stunnel.pid|' \
		${WRKSRC}/src/Makefile.in
	@${FIND} ${WRKSRC} -type f -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -E -e 's,@(ACLOCAL|AUTO(MAKE|CONF|HEADER))@,/usr/bin/true,'
.ifdef(NOPORTDOCS)
	@${REINPLACE_CMD} -E -e 's/ install-docDATA/ /; s/^(SUBDIRS.+)doc/\1/' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -E -e 's/([^n])install-examplesDATA/\1/' \
		${WRKSRC}/tools/Makefile.in
.endif

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO} ""
	@${ECHO} "**************************************************************************"
	@${ECHO} "To create and install a new certificate, type \"make cert\""
	@${ECHO} ""
	@${ECHO} "And don't forget to check out the FAQ at http://www.stunnel.org/"
	@${ECHO} "**************************************************************************"
	@${ECHO} ""
	@${ECHO} "*********************** WARNING! WARNING! WARNING! ***********************"
	@${ECHO} "The stunnel startup script has been converted to rc_subr"
	@${ECHO} "format now.  You have to set at least the stunnel_enable"
	@${ECHO} "variable, and maybe also stunnel_config and stunnel_pidfile,"
	@${ECHO} "if you want stunnel to be started automatically at boot time!"
	@${ECHO} "**************************************************************************"
	@${ECHO} ""

cert:
	@${ECHO} ""
	@${ECHO} "**************************************************************************"
	@${ECHO} "The new certificate will be saved into ${ETCDIR}/stunnel.pem"
	@${ECHO} "**************************************************************************"
	@${ECHO} ""
	@(cd ${WRKSRC}/tools/; make install-data-local)

.if !defined(WITH_STUNNEL_SSL_ENGINE)
EXTRA_PATCHES=	${FILESDIR}/ssl-noengine.patch
pre-patch:
	@${ECHO} "*************************************************************************"
	@${ECHO} "Note: you have to explicitly define WITH_STUNNEL_SSL_ENGINE to activate"
	@${ECHO} "the OpenSSL ENGINE code on FreeBSD 5.x or 6.x."
	@${ECHO} "There are known reliability issues with stunnel and the OpenSSL ENGINE"
	@${ECHO} "code, so you are advised not to enable it."
	@${ECHO} "*************************************************************************"
.else
pre-patch:
	@${ECHO} "*************************************************************************"
	@${ECHO} "Note: you have defined WITH_STUNNEL_SSL_ENGINE.  Now stunnel will activate"
	@${ECHO} "the OpenSSL ENGINE code even on FreeBSD 5.x."
	@${ECHO} "There are known reliability issues with stunnel and the OpenSSL ENGINE"
	@${ECHO} "code.  You have enabled it at your own risk."
	@${ECHO} "*************************************************************************"
.endif

.include <bsd.port.post.mk>
