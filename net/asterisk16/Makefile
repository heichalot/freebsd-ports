# New ports collection makefile for:	asterisk
# Date created:				17 October 2003
# Whom:					Maxim Sobolev <sobomax@portaone.com>
#
# $FreeBSD$
#

PORTNAME=	asterisk
PORTVERSION=	1.6.0.21
PORTREVISION=	4
PKGNAMESUFFIX=	16
CATEGORIES=	net
MASTER_SITES=	http://downloads.asterisk.org/pub/telephony/asterisk/ \
		http://downloads.asterisk.org/pub/telephony/asterisk/old-releases/

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	An Open Source PBX and telephony toolkit

LIB_DEPENDS=	speex.1:${PORTSDIR}/audio/speex \
		newt.52:${PORTSDIR}/devel/newt \
		execinfo:${PORTSDIR}/devel/libexecinfo
RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

ONLY_FOR_ARCHS=	i386 amd64

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/openh323" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-gsm=${LOCALBASE}
CPPFLAGS=	-I${LOCALBASE}/include -I${LOCALBASE}/include/openh323
USE_GMAKE=	yes
USE_BISON=	build
USE_RC_SUBR=	asterisk.sh
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		MKDIR="${MKDIR}" \
		PWLIBDIR=${LOCALBASE}/share/pwlib \
		OPENH323DIR=${LOCALBASE}/share/openh323 \
		OSVERSION=${OSVERSION} \
		NOISY_BUILD=YES \
		DOCSDIR=${DOCSDIR} \
		ASTCFLAGS="${CFLAGS}"
MAN8=		asterisk.8 astgenkey.8 autosupport.8 safe_asterisk.8
CONFLICTS=	asterisk*-1.2* asterisk*-1.4*

OPTIONS=	OGGVORBIS	"Enable Ogg Vorbis support" on \
		ODBC		"Enable ODBC support" on \
		POSTGRES	"Enable PostgreSQL support" on \
		RADIUS		"Enable RADIUS accounting support" on \
		SNMP		"Enable SNMP support" on \
		H323		"Enable H.323 support" on \
		FREETDS		"Enable FreeTDS support" on \
		JABBER		"Enable Jabber and Gtalk support" on \
		SQLITE          "Enable SQLITE support" on \
		GSM		"Enable GSM codec" on \
		CURL		"Enable CURL support" on \
		ILBC		"Enable iLBC codec" off \
		SPANDSP		"Enable Spandsp faxing support" off \
#		CODEC_PATCH	"Apply codec negotiation patch" off \
#		MISC_PATCHES	"Apply additional patches" off

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
OPTIONS+=	DAHDI		"Enable DAHDI support" on

# Include this since we have altered OPTIONS.
.include "$(PORTSDIR)/Mk/bsd.port.options.mk"
.endif

.if !defined(WITH_H323)
PLIST_SUB+=	WITH_H323="@comment "
CONFIGURE_ARGS+= --without-h323
.else
PLIST_SUB+=	WITH_H323=""
CONFIGURE_ARGS+= --with-h323=${LOCALBASE}
LIB_DEPENDS+=	pt_r.1:${PORTSDIR}/devel/pwlib \
		h323_r.1:${PORTSDIR}/net/openh323
.endif

.if !defined(WITH_DAHDI)
PLIST_SUB+=	WITH_DAHDI="@comment "
CONFIGURE_ARGS+= --without-dahdi
.else
PLIST_SUB+=	WITH_DAHDI=""
CONFIGURE_ARGS+= --with-dahdi
BUILD_DEPENDS+=	libpri>=1.4.10:${PORTSDIR}/misc/libpri \
		${LOCALBASE}/include/dahdi/user.h:${PORTSDIR}/misc/dahdi
LIB_DEPENDS+=	pri.1:${PORTSDIR}/misc/libpri
RUN_DEPENDS+=	${LOCALBASE}/lib/dahdi/dahdi.ko:${PORTSDIR}/misc/dahdi
.endif

#
# WITH_FREETDS, WITH_PGSQL and WITH_SQLITE can also be added to MAKE_ENV
# similarly
.if !defined(WITH_ODBC)
PLIST_SUB+=	WITH_ODBC="@comment "
CONFIGURE_ARGS+= --without-odbc
.else
PLIST_SUB+=	WITH_ODBC=""
CONFIGURE_ARGS+= --with-odbc --with-ltdl
LIB_DEPENDS+=	odbc.1:${PORTSDIR}/databases/unixODBC \
		ltdl.7:${PORTSDIR}/devel/libltdl22
.endif

.if !defined(WITH_FREETDS)
PLIST_SUB+=	WITH_FREETDS="@comment "
CONFIGURE_ARGS+= --without-tds
.else
PLIST_SUB+=	WITH_FREETDS=""
CONFIGURE_ARGS+= --with-tds=${LOCALBASE}
LIB_DEPENDS+=	tds.5:${PORTSDIR}/databases/freetds
.endif

.if !defined(WITH_POSTGRES)
PLIST_SUB+=	WITH_POSTGRES="@comment "
CONFIGURE_ARGS+= --without-postgres
.else
PLIST_SUB+=	WITH_POSTGRES=""
USE_PGSQL=	yes
CONFIGURE_ARGS+= --with-postgres
.endif

.if !defined(WITH_OGGVORBIS)
PLIST_SUB+=	WITH_OGGVORBIS="@comment "
CONFIGURE_ARGS+= --without-ogg
.else
PLIST_SUB+=	WITH_OGGVORBIS=""
CONFIGURE_ARGS+= --with-ogg
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
.endif

.if !defined(WITH_RADIUS)
PLIST_SUB+=	WITH_RADIUS="@comment "
CONFIGURE_ARGS+= --without-radius
.else
PLIST_SUB+=	WITH_RADIUS=""
CONFIGURE_ARGS+= --with-radius
LIB_DEPENDS+=	radiusclient-ng.2:${PORTSDIR}/net/radiusclient
.endif

.if !defined(WITH_SNMP)
PLIST_SUB+=	WITH_SNMP="@comment "
CONFIGURE_ARGS+= --without-netsnmp
.else
PLIST_SUB+=	WITH_SNMP=""
CONFIGURE_ARGS+= --with-netsnmp
LIB_DEPENDS+=	netsnmp.20:${PORTSDIR}/net-mgmt/net-snmp
.endif

.if !defined(WITH_JABBER)
PLIST_SUB+=	WITH_JABBER="@comment "
CONFIGURE_ARGS+= --without-iksemel
.else
PLIST_SUB+=	WITH_JABBER=""
CONFIGURE_ARGS+= --with-iksemel
LIB_DEPENDS+=	iksemel.4:${PORTSDIR}/textproc/iksemel
.endif

.if !defined(WITH_SQLITE)
PLIST_SUB+=	WITH_SQLITE="@comment "
CONFIGURE_ARGS+=	--without-sqlite \
		--with-sqlite3=no
.else
PLIST_SUB+=	WITH_SQLITE=""
CONFIGURE_ARGS+= --with-sqlite
LIB_DEPENDS+=	sqlite:${PORTSDIR}/databases/sqlite2 \
		sqlite3:${PORTSDIR}/databases/sqlite3
.endif

.if !defined(WITH_ILBC)
PLIST_SUB+=	WITH_ILBC="@comment "
.else
PLIST_SUB+=	WITH_ILBC=""
EXTRA_PATCHES+=	${PATCHDIR}/ilbc_enable.diff
.endif

.if !defined(WITH_GSM)
PLIST_SUB+=	WITH_GSM="@comment "
CONFIGURE_ARGS+= --without-gsm
.else
PLIST_SUB+=	WITH_GSM=""
CONFIGURE_ARGS+= --with-gsm
LIB_DEPENDS+=	gsm.1:${PORTSDIR}/audio/gsm
.endif

.if !defined(WITH_CURL)
PLIST_SUB+=	WITH_CURL="@comment "
CONFIGURE_ARGS+= --with-curl=no \
		--with-libcurl=no
.else
PLIST_SUB+=	WITH_CURL=""
CONFIGURE_ARGS+= --with-curl \
		--with-libcurl
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl
.endif

.if !defined(WITH_SPANDSP)
PLIST_SUB+=	WITH_SPANDSP="@comment "
CONFIGURE_ARGS+= --without-spandsp
.else
PLIST_SUB+=	WITH_SPANDSP=""
CONFIGURE_ARGS+= --with-spandsp
LIB_DEPENDS+=	spandsp.2:${PORTSDIR}/comms/spandsp-devel
.endif

.if defined(WITH_CODEC_PATCH)
PATCHFILES=	asterisk-1.4.22-codec-negotiation-20081110.diff.gz
PATCH_SITES=	http://b2bua.org/chrome/site/
EXTRA_PATCHES+=	${PATCHDIR}/codecnego-patch-Makefile
.else
EXTRA_PATCHES+=	${PATCHDIR}/nocodecnego-patch-Makefile
.endif

.if defined(WITH_MISC_PATCHES)
EXTRA_PATCHES+=	${PATCHDIR}/dtmf_debug.diff
EXTRA_PATCHES+=	${PATCHDIR}/feature_disconnect.diff
EXTRA_PATCHES+=	${PATCHDIR}/sip_force_callid.diff
EXTRA_PATCHES+=	${PATCHDIR}/sip_set_auth.diff
.if defined(WITH_CODEC_PATCH)
EXTRA_PATCHES+=	${PATCHDIR}/rtp_force_dtmf-codecnego.diff
.else
EXTRA_PATCHES+=	${PATCHDIR}/rtp_force_dtmf-nocodecnego.diff
.endif
.endif

post-extract:
	${MKDIR} ${WRKSRC}/codecs/ilbc
	${FIND} ${WRKSRC} -name '*.d' -delete

post-patch:
	${REINPLACE_CMD} -e 's|/var/lib|${PREFIX}/share|g' ${WRKSRC}/configs/musiconhold.conf.sample

.include <bsd.port.post.mk>
