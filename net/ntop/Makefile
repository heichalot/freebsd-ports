# New ports collection makefile for:   ntop
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	ntop
PORTVERSION=	3.3.10
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://www.ntop.org/trac/export/4103/trunk/ntop/3rd_party/ \
		SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTFILES=	etter.finger.os.gz \
		GeoIPASNum.dat.gz \
		GeoLiteCity.dat.gz \
		oui.txt.gz \
		specialMAC.txt.gz \
		${PORTNAME}-${PORTVERSION}.tar.gz
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Network monitoring tool with command line and web interfaces

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm \
		event-1.4:${PORTSDIR}/devel/libevent
BUILD_DEPENDS=	rrdtool>=1.2:${PORTSDIR}/databases/rrdtool \
		geoiplookup:${PORTSDIR}/net/GeoIP
RUN_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz \
		${LOCALBASE}/lib/X11/fonts/URW/a010013l.afm:${PORTSDIR}/x11-fonts/urwfonts

DBDIR?=		/var/db

MAKE_JOBS_SAFE=	yes
USE_AUTOTOOLS=	libtool:22 automake:19 autoconf:262
USE_GNOME=	libxml2
USE_LUA=	5.1
USE_GMAKE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
PLIST_SUB=	DBDIR=${DBDIR} \
		PORTVERSION=${PORTVERSION}
CONFIGURE_ARGS=	--localstatedir=${DBDIR} \
		--with-ossl-root=${OPENSSLBASE} \
		--with-gdbm-root=${LOCALBASE} \
		--with-zlib-root=/usr \
		--disable-snmp
# we currently disable IPv6
CONFIGURE_ARGS+=--disable-ipv6

MAN8=		ntop.8

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-deinstall
SUB_LIST=	DBDIR=${DBDIR}
USE_RC_SUBR=	ntop.sh

##
## Available knobs:
##    WITH_LOCALE:        Enable locale (i18n) support.
##    WITH_PCAP_PORT:     Use libpcap from ports.
##    WITH_XMLDUMP:       Enable XML Dump support.
##    WITHOUT_TCPWRAPPER: Disable TCP wrapper support.
##
OPTIONS=	LOCALE "Enable locale (i18n) support." Off \
		PCAP_PORT "Use libpcap from ports." Off \
		XMLDUMP "Enable XML Dump support." Off \
		TCPWRAPPER "Enable TCP wrapper support" On

.include <bsd.port.pre.mk>

.if defined(WITH_TCPWRAPPER)
CONFIGURE_ARGS+=	--with-tcpwrap
.endif

.if defined(WITH_PCAP_PORT)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap
CONFIGURE_ARGS+=	--with-pcap-root=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--with-pcap-root=/usr
.endif

.if defined(WITH_LOCALE) && !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
CONFIGURE_ARGS+=	--enable-i18n \
			--with-localedir=${LOCALBASE}/share/locale
.endif

.if defined(WITH_XMLDUMP)
LIB_DEPENDS+=		gdome.8:${PORTSDIR}/textproc/gdome2
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include/libxml2 \
			-I${LOCALBASE}/include/libxml2/libxml \
			-I${LOCALBASE}/include/libgdome \
			-I${LOCALBASE}/include/glib-2.0"
.endif

.if ${OSVERSION} < 700000
BROKEN=		does not configure on 6.X
.endif

post-extract:
	@${RM} ${WRKSRC}/configureextra/FREEBSD
	@${CP} ${_DISTDIR}/etter.finger.os.gz ${WRKSRC}
	@${CP} ${_DISTDIR}/GeoIPASNum.dat.gz ${WRKSRC}
	@${CP} ${_DISTDIR}/GeoLiteCity.dat.gz ${WRKSRC}
	@${CP} ${_DISTDIR}/oui.txt.gz ${WRKSRC}
	@${CP} ${_DISTDIR}/specialMAC.txt.gz ${WRKSRC}

pre-configure:
	@cd ${WRKSRC} && ${SETENV} ${SCRIPTS_ENV} ${SH} autogen.sh --noconfig

pre-install:
	@cd ${WRKSRC} && ${GMAKE} dnetter

post-install:
	@${MKDIR} ${DBDIR}/ntop
	@${CHOWN} -R nobody:nobody ${DBDIR}/ntop
	@${INSTALL} -d ${ETCDIR}/l7-patterns
	@cd ${WRKSRC}/l7-patterns/&&${COPYTREE_SHARE} . ${ETCDIR}/l7-patterns

.include <bsd.port.post.mk>
