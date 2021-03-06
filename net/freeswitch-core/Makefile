# Ports collection makefile for: freeswitch-core
# Date created: May 11, 2010
# Whom: Eric F Crist <ecrist@secure-computing.net>
#
# $FreeBSD$
#

PORTNAME=	freeswitch
PORTVERSION=	1.0.6
CATEGORIES=	net
MASTER_SITES=	http://files.freeswitch.org/ \
		ftp://ftp.secure-computing.net/pub/freeswitch/ \
		ftp://ftp2.secure-computing.net/pub/freeswitch/
PKGNAMESUFFIX=	-core
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ecrist@secure-computing.net
COMMENT=	FreeSwitch SoftSwitch Port

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		gnutls:${PORTSDIR}/security/gnutls \
		odbc:${PORTSDIR}/databases/unixODBC

WRKSRC=		${WRKDIR}/freeswitch-${PORTVERSION}

ONLY_FOR_ARCHS=	i386 amd64

USE_AUTOTOOLS=	autoconf:262:env automake:110:env libtool:22:env

USE_PERL5_BUILD=yes

USE_GMAKE=	yes
SUB_FILES=	pkg-install pkg-message
USE_RC_SUBR=	freeswitch
HAS_CONFIGURE=	yes
VARBASE?=	/var
CONFIGURE_ARGS=	--prefix=${PREFIX}/share/${PORTNAME} \
		--bindir=${PREFIX}/bin \
		--sysconfdir=${PREFIX}/etc/${PORTNAME}/conf \
		--includedir=${PREFIX}/include/${PORTNAME} \
		--libdir=${PREFIX}/lib/${PORTNAME}/lib \
		--with-modinstdir=${PREFIX}/lib/${PORTNAME}/mod \
		--with-rundir=${VARBASE}/run \
		--with-libgnutls-prefix=${LOCALBASE} \
		--with-ogg=${LOCALBASE} \
		--with-ogg-libraries=${LOCALBASE}/lib \
		--with-ogg-includes=${LOCALBASE}/include

CONFIGURE_ENV+=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${PREFIX}/include

FREESWITCH_USER=	freeswitch
FREESWITCH_GROUP=	${FREESWITCH_USER}
UID=    610
GID=    ${UID}
SUB_LIST=	FREESWITCH_USER=${FREESWITCH_USER} FREESWITCH_GROUP=${FREESWITCH_GROUP} UID=${UID} GID=${GID}

OPTIONS=	MODSHOUT        "Enable mod_shout (streaming audio/mp3)" on \
		MODFLITE	"Enable mod_flite (Text to Speech)" on \
		MODUNIMRCP	"Enable mod_unimrcp tts (new testing)" off \
		MODTTSCMDLINE	"Enable mod_tts_commandline (testing)" off \
		MODPOCKETSPHINX	"Enable mod_pockectsphinx (voice control)" on \
		MODCIDLOOKUP	"Enable mod_cidlookup" on \
		MODDPDIRECTORY	"Enable mod_dialplan_directory" off \
		MODDIRECTORY	"Enable mod_directory" on \
 		MODDINGALING	"Enable mod_dingaling(google talk)" on \
		MODEASYROUTE	"Enable mod_easyroute(routeing tool)" on \
		MODERLANGEVENT  "Enable mod_erlang_event (Call Center Dist)" off \
		MODFAX		"Enable mod_fax" on \
		MODLCR		"Enable mod_lcr (least cost routing)" on \
		MODSOUNDTOUCH	"Enable mod_soundtouch" on \
		MODRSS		"Enable mod_rss (rss feed reader)" on \
		MODSNOM		"Enable mod_snom (snom control)" off \
		MODVMD		"Enable mod_vmd (voice mail detection)" on \
		MODSPY		"Enable mod_spy" on \
		MODAMRWB	"Enable mod_amrwb (amrwb codec)" on \
		MODCELT		"Enable mod_celt (celt codec)" on \
		MODSILK		"Enable mod_silk (New Silk Codec)" on \
		MODOPENZAP	"Enable mod_openzap dahdi support" off \
		MODSKINNY	"Enable mod_skinny Skinny Support (Beta)" off \
		MODMEMCACHE	"Enable mod_memcache" on \
		MODMULTICAST	"Enable mod_event_multicast" on \
		MODNIBBLEBILL   "Enable mod_nibblebill(billing)" on \
		MODPORTAUDIO    "Enable mod_portaudio" on \
		MODPASTREAM	"Enable mod_portaudio_stream (new)" on \
		MODSHELLSTREAM	"Enable mod_SHELL_stream (New)" on \
		MODSPDRMNKYODBC	"Enable mod_spidermonkey_odbc (req odbc)" on \
		MODPERL		"Enable mod_perl (perl support)" off \
		MODPYTHON	"Enable mod_python (python lang)" off \
		MODCURL		"Enable mod_curl" off \
		MODXMLCURL	"Enable mod_xml_curl" off \
		MODDISTRIBUTOR	"Enable mod_distributor (testing)" off \
		MODSNAPSHOT	"Enable mod_snapshot (testing)" off \
		MODSAYDE	"Enable mod_say_de (German support)" off \
		MODSAYES	"Enable mod_say_se (Spanish support)" off \
		MODSAYEN	"Enable mod_say_en (English support)" on \
		MODSAYHU	"Enable mod_say_hu (Hungarian support(new)" off \
		MODSAYFR	"Enable mod_say_fr (French support)" off \
		MODSAYIT	"Enable mod_say_it (Italian support)" off \
		MODSAYNL	"Enable mod_say_nl (Dutch support)" off \
		MODSAYRU	"Enable mod_say_ru (Russian support)" on \
		MODSAYTH	"Enable mod_say_th (Thi support(new)" off \
		MODSAYZH	"Enable mod_say_zh (Chinese support)" off

.include <bsd.port.options.mk>

.if defined(PACKAGE_BUILDING)
BROKEN=		Fails to compile on pointyhat
.endif

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
CONFIGURE_ARGS+=	--enable-64
.endif

.for i in MODFLITE MODPOCKETSPHINX MODCIDLOOKUP MODDPDIRECTORY MODEASYROUTE MODLCR MODSOUNDTOUCH \
	MODRSS MODSNOM MODVMD MODSPY MODAMRWB MODCELT MODMULTICAST MODPORTAUDIO MODCURL MODXMLCURL \
	MODSAYDE MODSAYEN MODSAYES MODSAYFR MODSAYHU MODSAYIT MODSAYNL MODSAYRU MODSAYTH MODSAYZH \
	MODNIBBLEBILL MODDINGALING MODDIRECTORY MODMEMCACHE MODPYTHON MODPASTREAM MODSHELLSTREAM \
	MODSILK MODSPDRMNKYODBC MODUNIMRCP MODTTSCMDLINE MODDISTRIBUTOR MODSNAPSHOT MODSKINNY
.if !defined(WITH_${i})
PLIST_SUB+=     WITH_${i}="@comment "
.else
PLIST_SUB+=     WITH_${i}=""
.endif
.endfor

.if !defined(WITH_MODOPENZAP)
PLIST_SUB+=	WITH_MODOPENZAP="@comment "
.else
PLIST_SUB+=	WITH_MODOPENZAP=""
CONFIGURE_ARGS+=	--with-libpri
BUILD_DEPENDS+=	libpri>=1.2.0:${PORTSDIR}/misc/libpri \
		${LOCALBASE}/include/dahdi/wctdm_user.h:${PORTSDIR}/misc/dahdi
LIB_DEPENDS+=	pri:${PORTSDIR}/misc/libpri
RUN_DEPENDS+=	${LOCALBASE}/include/dahdi/wctdm_user.h:${PORTSDIR}/misc/dahdi
.endif

.if !defined(WITH_MODSHOUT)
PLIST_SUB+=	WITH_MODSHOUT="@comment "
.else
PLIST_SUB+=	WITH_MODSHOUT=""
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
.endif

.if !defined(WITH_MODPERL)
PLIST_SUB+=	WITH_MODPERL="@comment "
.else
PLIST_SUB+=	WITH_MODPERL=""
LIB_DEPENDS+=	gdbm:${PORTSDIR}/databases/gdbm \
		db:${PORTSDIR}/databases/db42
.endif

.if !defined(WITH_MODFAX)
PLIST_SUB+=	WITH_MODFAX="@comment "
.else
PLIST_SUB+=	WITH_MODFAX=""
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
.endif

.if !defined(WITH_MODERLANGEVENT)
PLIST_SUB+=	WITH_MODERLANGEVENT="@comment "
.else
PLIST_SUB+=	WITH_MODERLANGEVENT=""
BUILD_DEPENDS+=	${LOCALBASE}/lib/erlang/usr/include/erl_driver.h:${PORTSDIR}/lang/erlang-lite
.endif

.if !defined(WITH_MODSKINNY)
PLIST_SUB+=	WITH_MODSKINNY="@comment "
.else
PLIST_SUB+=	WITH_MODSKINNY=""
.endif

pre-configure:
	cd ${WRKSRC} && ./rebootstrap.sh
	@${REINPLACE_CMD} -e 's|pkgconfigdir = $$(libdir)/pkgconfig|pkgconfigdir = $(libdir)data/libdata/pkgconfig|g' ${WRKSRC}/libs/*/Makefile.am
	@${REINPLACE_CMD} -e 's|pkgconfigdir = $$(libdir)/pkgconfig|pkgconfigdir = $(libdir)data/libdata/pkgconfig|g' ${WRKSRC}/libs/*/Makefile.in
	@${REINPLACE_CMD} -e 's|pkgconfigdir = $$(libdir)/pkgconfig|pkgconfigdir = $(libdir)data/libdata/pkgconfig|g' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|pkgconfigdir = $$(libdir)/pkgconfig|pkgconfigdir = $(libdir)data/libdata/pkgconfig|g' ${WRKSRC}/Makefile.in

post-configure:
.for i in mod_unimrcp mod_flite mod_pocketsphinx
.if defined(WITH_${i:C/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(asr_tts/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.if defined(WITH_MODTTSCMDLINE)
	@${REINPLACE_CMD} -e 's|#asr_tts/mod_tts_commandline|asr_tts/mod_tts_commandline|g' ${WRKSRC}/modules.conf
.endif
.for i in mod_cidlookup mod_easyroute mod_fax mod_lcr mod_soundtouch mod_rss mod_snom \
	mod_vmd mod_spy mod_curl mod_nibblebill mod_memcache mod_directory mod_distributor \
	mod_snapshot
.if defined(WITH_${i:C/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(applications/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.for i in mod_amrwb mod_celt mod_silk
.if defined(WITH_${i:C/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(codecs/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.for i in  mod_shell_stream mod_shout
.if defined(WITH_${i:C/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(formats/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.if defined(WITH_MODPASTREAM)
	@${REINPLACE_CMD} -e 's|#formats/mod_portaudio_stream|formats/mod_portaudio_stream|g' ${WRKSRC}/modules.conf
.endif
.for i in mod_say_de mod_say_es mod_say_en mod_say_fr mod_say_hu mod_say_it mod_say_nl mod_say_ru mod_say_th mod_say_zh
.if defined(WITH_${i:C/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(say/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.for i in mod_perl mod_python
.if defined(WITH_${i:C/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(languages/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.if defined(WITH_MODSPDRMNKYODBC)
	@${REINPLACE_CMD} -e 's|#languages/mod_spidermonkey_odbc|languages/mod_spidermonkey_odbc|g' ${WRKSRC}/modules.conf
.endif
.for i in mod_skinny mod_portaudio mod_dingaling
.if defined(WITH_${i:C/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(endpoints/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.if defined(WITH_MODDPDIRECTORY)
	@${REINPLACE_CMD} -e 's|#dialplans/mod_dialplan_directory|dialplans/mod_dialplan_directory|g' ${WRKSRC}/modules.conf
.endif
.if defined(WITH_MODOPENZAP)
	@${REINPLACE_CMD} -e 's|#../../libs/openzap/mod_openzap|../../libs/openzap/mod_openzap|g' ${WRKSRC}/modules.conf
.endif
.if defined(WITH_MODMULTICAST)
	@${REINPLACE_CMD} -e 's|#event_handlers/mod_event_multicast|event_handlers/mod_event_multicast|g' ${WRKSRC}/modules.conf
.endif
.if defined(WITH_MODERLANGEVENT)
	@${REINPLACE_CMD} -e 's|#event_handlers/mod_erlang_event|event_handlers/mod_erlang_event|g' ${WRKSRC}/modules.conf
.endif
.if defined(WITH_MODXMLCURL)
	@${REINPLACE_CMD} -e 's|#xml_int/mod_xml_curl|xml_int/mod_xml_curl|g' ${WRKSRC}/modules.conf
.endif
.if defined(WITH_MODSKINNY)
	@${REINPLACE_CMD} -e 's|#endpoints/mod_skinny|endpoints/mod_skinny|g' ${WRKSRC}/modules.conf
.endif

pre-install:
	@${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

do-install:
	cd ${WRKSRC} && ${GMAKE} ${INSTALL}
	@${MKDIR} ${VARBASE}/db/${PORTNAME}
	@${RM} -rf ${PREFIX}/share/${PORTNAME}/db
	@${LN} -F -s ${VARBASE}/db/${PORTNAME}/ ${PREFIX}/share/${PORTNAME}/db
	@${CHOWN} -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${VARBASE}/db/${PORTNAME}
	@${CHMOD} -R 774 ${VARBASE}/db/${PORTNAME}
	@${MKDIR} ${VARBASE}/${PORTNAME}/recordings
	@${RM} -rf ${PREFIX}/share/${PORTNAME}/recordings
	@${LN} -F -s ${VARBASE}/${PORTNAME}/recordings ${PREFIX}/share/${PORTNAME}/recordings
	@${MKDIR} ${VARBASE}/${PORTNAME}/scripts
	@${RM} -rf ${PREFIX}/share/${PORTNAME}/scripts
	@${LN} -F -s ${VARBASE}/${PORTNAME}/scripts ${PREFIX}/share/${PORTNAME}/scripts
	@${MKDIR} ${VARBASE}/log/${PORTNAME}/xml_cdr
	@${RM} -rf ${PREFIX}/share/${PORTNAME}/log
	@${LN} -F -s ${VARBASE}/log/${PORTNAME}/ ${PREFIX}/share/${PORTNAME}/log
	@${CHOWN} -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${VARBASE}/log/${PORTNAME}
	@${CHMOD} -R 774 ${VARBASE}/log/${PORTNAME}
	@${MKDIR} ${VARBASE}/spool/voicemail
	@${LN} -F -s ${VARBASE}/spool/voicemail ${PREFIX}/share/${PORTNAME}/storage
	@${CHOWN} -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${VARBASE}/spool/voicemail
	@${CHMOD} -R 774 ${VARBASE}/spool/voicemail
	@${CHOWN} -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${VARBASE}/${PORTNAME}
	@${CHMOD} -R 774 ${VARBASE}/${PORTNAME}
	@${CHOWN} -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${PREFIX}/share/${PORTNAME}
	@${CHMOD} -R 774 ${PREFIX}/share/${PORTNAME}
	@${CHOWN} -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${PREFIX}/etc/${PORTNAME}
	@${CHMOD} -R 774 ${PREFIX}/etc/${PORTNAME}

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}/conf
	(cd ${WRKSRC}/conf/ && \
		${COPYTREE_SHARE} \* ${EXAMPLESDIR}/conf)
.endif
.if defined(WITH_MODOPENZAP)
	(cd ${WRKSRC}/libs/openzap/conf/ && \
		${CP} *.conf ${EXAMPLESDIR}/conf && \
		${CP} openzap.conf.xml ${EXAMPLESDIR}/conf/autoload_configs)
.endif
	@${CAT} ${PKGMESSAGE}

.if ${OSVERSION} < 700000
IGNORE=		freeswitch is only supported on FreeBSD 7 or newer
.endif

.include <bsd.port.mk>
