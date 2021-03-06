# New ports collection makefile for:	rt3
# Date created:				28 November 2002
# Whom:					autrijus
#
# $FreeBSD$
#

PORTNAME=	rt
PORTVERSION?=	3.6.7
PORTREVISION=	6
CATEGORIES=	www
MASTER_SITES=	http://download.bestpractical.com/pub/rt/release/ \
		http://download.bestpractical.com/pub/rt/devel/ \
		ftp://ftp.eu.uu.net/pub/unix/ticketing/rt/release/ \
		ftp://ftp.eu.uu.net/pub/unix/ticketing/rt/devel/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RT is an industrial-grade ticketing system written in Perl

CONFLICTS=	rt-2* rt-3.0* rt-3.2* rt-3.4* rt-3.8*

PERL_MODULES =	${SITE_PERL}/Apache/Mason.pm:${PORTSDIR}/www/p5-HTML-Mason \
		${SITE_PERL}/Apache/Session.pm:${PORTSDIR}/www/p5-Apache-Session \
		p5-DBIx-SearchBuilder>=0.53:${PORTSDIR}/databases/p5-DBIx-SearchBuilder \
		${SITE_PERL}/HTML/FormatText.pm:${PORTSDIR}/textproc/p5-HTML-Format \
		${SITE_PERL}/HTML/Scrubber.pm:${PORTSDIR}/www/p5-HTML-Scrubber \
		${SITE_PERL}/HTML/TreeBuilder.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${SITE_PERL}/Locale/Maketext/Fuzzy.pm:${PORTSDIR}/devel/p5-Locale-Maketext-Fuzzy \
		${SITE_PERL}/Locale/Maketext/Lexicon.pm:${PORTSDIR}/devel/p5-Locale-Maketext-Lexicon \
		${SITE_PERL}/Log/Dispatch.pm:${PORTSDIR}/devel/p5-Log-Dispatch \
		${SITE_PERL}/Mail/Mailer.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/MIME/Entity.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/Module/Versions/Report.pm:${PORTSDIR}/devel/p5-Module-Versions-Report \
		${SITE_PERL}/Regexp/Common.pm:${PORTSDIR}/textproc/p5-Regexp-Common \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/Text/Autoformat.pm:${PORTSDIR}/textproc/p5-Text-Autoformat \
		${SITE_PERL}/Text/Quoted.pm:${PORTSDIR}/textproc/p5-Text-Quoted \
		${SITE_PERL}/Text/Template.pm:${PORTSDIR}/textproc/p5-Text-Template \
		${SITE_PERL}/Text/WikiFormat.pm:${PORTSDIR}/textproc/p5-Text-WikiFormat \
		${SITE_PERL}/Text/Wrapper.pm:${PORTSDIR}/textproc/p5-Text-Wrapper \
		${SITE_PERL}/Time/ParseDate.pm:${PORTSDIR}/devel/p5-Time-modules \
		${SITE_PERL}/Tree/Simple.pm:${PORTSDIR}/devel/p5-Tree-Simple \
		${SITE_PERL}/XML/RSS.pm:${PORTSDIR}/textproc/p5-XML-RSS \
		${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph \
		${SITE_PERL}/GD/Text.pm:${PORTSDIR}/graphics/p5-GD-TextUtil \
		${SITE_PERL}/Calendar/Simple.pm:${PORTSDIR}/devel/p5-Calendar-Simple \
		${SITE_PERL}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/CSS/Squish.pm:${PORTSDIR}/textproc/p5-CSS-Squish \
		p5-Devel-StackTrace>=1.19:${PORTSDIR}/devel/p5-Devel-StackTrace \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		p5-XML-Simple>=2.18:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-require
LATEST_LINK=	rt36
HAS_CONFIGURE=	yes
NO_BUILD=	yes
NO_PACKAGE=	Executes scripts in post-install phase
USE_APACHE=	1.3+
USE_PERL5=	5.8.3+

CONFIGURE_ARGS=	--prefix=${RT_PATH} \
		--enable-layout=${LAYOUT} \
		--with-web-user=${WEB_USER} \
		--with-web-group=${WEB_GROUP} \
		--with-libs-group=${LIBS_GROUP} \
		--with-db-host=${DB_HOST} \
		--with-db-port=${DB_PORT} \
		--with-db-type=${DB_TYPE} \
		--with-db-rt-user=${DB_USER} \
		--with-db-rt-pass=${DB_PASSWORD} \
		--with-db-database=${DB_DATABASE} \
		--with-db-dba=${DB_DBA_USER}

.include <bsd.port.pre.mk>
.if defined(WITH_FASTCGI)
PERL_MODULES+=	${LOCALBASE}/${APACHEMODDIR}/mod_fastcgi.so:${PORTSDIR}/www/mod_fastcgi
PERL_MODULES+=		${SITE_PERL}/${PERL_ARCH}/FCGI.pm:${PORTSDIR}/www/p5-FastCGI
.else
PERL_MODULES+=	${SITE_PERL}/Apache/DBI.pm:${PORTSDIR}/www/p5-Apache-DBI
.	if ${APACHE_VERSION} == 13
PERL_MODULES+=	${SITE_PERL}/${PERL_ARCH}/Apache/Request.pm:${PORTSDIR}/www/p5-libapreq
.	else
PERL_MODULES+=	${LOCALBASE}/${APACHEMODDIR}/mod_perl.so:${PORTSDIR}/www/mod_perl2
.	endif
.endif
.if defined(MULTIPLE_INSTANCES)
EXTRA_PATCHES+=	${FILESDIR}/multiple*
.endif

DB_TYPE?=	mysql

.if ${DB_TYPE} == "Oracle"
PERL_MODULES+=	${SITE_PERL}/${PERL_ARCH}/DBD/Oracle.pm:${PORTSDIR}/databases/p5-DBD-Oracle
.else
.if ${DB_TYPE} == "Pg"
PERL_MODULES+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.else
.if ${DB_TYPE} == "SQLite"
PERL_MODULES+=	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite
.else
DB_TYPE=	mysql
PERL_MODULES+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
.endif
.endif
.endif

BUILD_DEPENDS+=	${PERL_MODULES}
RUN_DEPENDS+=	${PERL_MODULES}

RT_PATH?=	${PREFIX}/rt3
PLIST_SUB=	RT_PATH=${RT_PATH}  RTPLIST=${RT_PATH:S/^${PREFIX}\///}
LAYOUT?=	RT3

DB_DBA_USER?=	root
DB_USER?=	rt_user
DB_PASSWORD?=	rt_pass
DB_HOST?=	localhost
DB_DATABASE?=	rt3
DB_DBA_PASSWORD?=

WEB_USER?=	www
WEB_GROUP?=	www
LIBS_GROUP?=	wheel

.if defined(UPGRADE_RT30)
UPGRADES=	3.1.0 3.1.15 3.1.17
.endif
.if defined(UPGRADE_RT30) || defined(UPGRADE_RT32)
UPGRADES+=	3.3.0 3.3.11
.endif
.if defined(UPGRADE_RT30) || defined(UPGRADE_RT32) || defined(UPGRADE_RT34)
UPGRADES+=	3.5.1
.endif

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      UPGRADE_RT30                    Upgrading from a RT 3.0 installation"
	@${ECHO} "      UPGRADE_RT32                    Upgrading from a RT 3.2 installation"
	@${ECHO} "      UPGRADE_RT34                    Upgrading from a RT 3.4 installation"
	@${ECHO} "      INITIAL_INSTALL                 Do initialize DB (for initial install only)"
	@${ECHO} "      WITH_FASTCGI                    Use FastCGI instead of mod_perl"
	@${ECHO} "      MULTIPLE_INSTANCES              Patch RT to allow for multiple instances"
	@${ECHO} "                 (see: http://wiki.bestpractical.com/index.cgi?MultipleInstances)"
	@${ECHO} ""
	@${ECHO} "      DB_TYPE=type                    mysql, Oracle, Pg or SQLite (mysql)"
	@${ECHO} "      DB_HOST=hostname                The database host (localhost)"
	@${ECHO} "      DB_PORT=port                    The database port"
	@${ECHO} "      DB_DATABASE=port                The database name (rt3)"

	@${ECHO} "      DB_DBA_USER=username            Name of database administrator (root)"
	@${ECHO} "      DB_DBA_PASSWORD=password        Password of database administrator"
	@${ECHO} "      DB_USER=username                Name of database user for RT (rt_user)"
	@${ECHO} "      DB_PASSWORD=password            Name of database password for RT (rt_pass)"
	@sleep 3

pre-install:
	@${RM} -f ${WRKSRC}/html/Admin/Queues/*orig 2>/dev/null
	@${RM} -f ${WRKSRC}/html/Search/Elements/*orig 2>/dev/null
	@${RM} -f ${WRKSRC}/lib/RT/I18N/*orig 2>/dev/null
	@${RM} -f ${WRKSRC}/lib/*orig ${WRKSRC}/lib/*.in 2>/dev/null
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} \
		${PKGNAME} PRE-INSTALL

post-install:
	@${INSTALL_DATA} ${WRKSRC}/README ${RT_PATH}/README
	@[ -f ${RT_PATH}/etc/RT_SiteConfig.pm ] || \
		${CP} -p ${RT_PATH}/etc/RT_SiteConfig.pm-dist ${RT_PATH}/etc/RT_SiteConfig.pm
.if !defined(INITIAL_INSTALL)
.if defined(UPGRADES)
.for version in ${UPGRADES}
	-@${PERL} ${RT_PATH}/sbin/rt-setup-database --action schema --datadir ${WRKSRC}/etc/upgrade/${version} --dba '${DB_DBA_USER}' --dba-password '${DB_DBA_PASSWORD}'
	-@${PERL} ${RT_PATH}/sbin/rt-setup-database --action acl --datadir ${WRKSRC}/etc/upgrade/${version} --dba '${DB_DBA_USER}' --dba-password '${DB_DBA_PASSWORD}'
	-@${PERL} ${RT_PATH}/sbin/rt-setup-database --action insert --datadir ${WRKSRC}/etc/upgrade/${version} --dba '${DB_DBA_USER}' --dba-password '${DB_DBA_PASSWORD}'
.endfor
	@${ECHO} ""
	@${ECHO} "Upgrade of RT3 complete."
.else
	@${ECHO} ""
	@${ECHO} "Installation of RT3 complete."
	@${ECHO} "If you are upgrading from RT 3.0, please enter this now:"
	@${ECHO} "    make post-install -DUPGRADE_RT30"
	@${ECHO} ""
	@${ECHO} "If you are upgrading from RT 3.2, please enter this now:"
	@${ECHO} "    make post-install -DUPGRADE_RT32"
	@${ECHO} ""
	@${ECHO} "If you are upgrading from RT 3.4, please enter this now:"
	@${ECHO} "    make post-install -DUPGRADE_RT34"
	@${ECHO} ""
	@${ECHO} "If you are initializing a new installation, please do this:"
	@${ECHO} "    make post-install -DINITIAL_INSTALL"
	@${ECHO} ""
	@${ECHO} "Note that for both commands above, you will still need to"
	@${ECHO} "supply the same build flags as passed to 'make install',"
	@${ECHO} "in particular DB_DBA_USER and DB_DBA_PASSWORD."
	@${ECHO} ""
.endif
.else
	-@${PERL} ${RT_PATH}/sbin/rt-setup-database --force --action drop --dba '${DB_DBA_USER}' --dba-password '${DB_DBA_PASSWORD}'
	-@${PERL} ${RT_PATH}/sbin/rt-setup-database --force --action init --dba '${DB_DBA_USER}' --dba-password '${DB_DBA_PASSWORD}'
	@${SED} s!%%RT_PATH%%!${RT_PATH}!g ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
