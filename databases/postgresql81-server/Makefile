# New ports collection makefile for:	PostgreSQL
# Date created:		November 13, 1998
# Whom:			Marc G. Fournier <scrappy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	postgresql
PORTVERSION?=	8.1.21
PORTREVISION=	1
CATEGORIES?=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR=	source/v${PORTVERSION}
PKGNAMESUFFIX?=	-server
DISTFILES?=	postgresql-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER?=	girgen@FreeBSD.org
COMMENT?=	The most advanced open-source database available anywhere

CONFLICTS?=	${PORTNAME}-client-7.* \
		${PORTNAME}${PKGNAMESUFFIX}-7.* \
		${PORTNAME}-client-8.[02-9]* \
		${PORTNAME}${PKGNAMESUFFIX}-8.[02-9]*

WRKSRC=		${WRKDIR}/postgresql-${PORTVERSION}
DIST_SUBDIR=	postgresql

UNIQUENAME?=	${PORTNAME}81
LATEST_LINK?=	${PKGNAMEPREFIX}${UNIQUENAME}${PKGNAMESUFFIX}

PKGINSTALL?=	${PKGDIR}/pkg-install${PKGNAMESUFFIX}
USE_BZIP2=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
.if defined(NO_BUILD)
.undef USE_GMAKE
.undef GNU_CONFIGURE
.endif

CONFIGURE_ARGS+=--with-libraries=${LOCALBASE}/lib \
		--with-includes=${LOCALBASE}/include \
		--enable-thread-safety \
		--with-docdir=${DOCSDIR}
LDFLAGS+=	-L${PREFIX}/lib
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

PLIST=		${PKGDIR}/pkg-plist${PKGNAMESUFFIX}

BUILD_DIRS?=	src/port src/timezone src/backend src/backend/utils/mb/conversion_procs \
		src/bin/initdb src/bin/ipcclean src/bin/pg_ctl src/bin/pg_controldata \
		src/bin/pg_resetxlog src/pl

INSTALL_DIRS?=	${BUILD_DIRS}

.if !defined(CLIENT_ONLY) && !defined(SLAVE_ONLY)
SERVER_ONLY=	yes
USE_RC_SUBR=	postgresql
SUB_FILES+=	dot.cshrc dot.profile
USE_PGSQL=	yes
WANT_PGSQL_VER=	${PORTVERSION:C/([0-9][0-9]*)\.([0-9][0-9]*).*/\1\2/g}
.endif

.if !defined(SLAVE_ONLY)
OPTIONS=	NLS "Use internationalized messages" on
.endif

# Cannot check this with standard OPTION due to a catch-22.
# USE_OPENSSL must precede bsd.port.pre.mk, but then we don't know
# what OPTIONS are set.
#
# If you *don't* want SSL, set WITHOUT_SSL=YES when making
.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-openssl
.endif

.include <bsd.port.pre.mk>

.if !defined(SLAVE_ONLY)
OPTIONS+=	PAM "Build with PAM support (server only)" off
OPTIONS+=	MIT_KRB5 "Build with MIT's kerberos support" off
OPTIONS+=	HEIMDAL_KRB5 "Builds with Heimdal kerberos support" off
OPTIONS+=	OPTIMIZED_CFLAGS "Builds with compiler optimizations (-O3)" off
#  to run regression tests:
OPTIONS+=	TESTS "Allows the use of a \"check\" target (server)" off
OPTIONS+=	DEBUG "Builds with debugging symbols" off

# See http://people.freebsd.org/~girgen/postgresql-icu/README.html for more info
OPTIONS+=	ICU   "Use ICU for unicode collation (server)" off

# See http://gppl.moonbone.ru/ for more info
OPTIONS+=	HIER  "Builds with query hierarchy (server)" off

# See http://www.freebsd.org/cgi/query-pr.cgi?pr=ports/76999 for more info
# (requires dump/restore if modified.)
OPTIONS+=	INTDATE "Builds with 64-bit date/time type (server)" off

.  if (defined(SERVER_ONLY) && defined(WITH_HIER)) || make(makesum)
PATCH_SITES+=	http://people.freebsd.org/~girgen/postgresql-hier/:hier812055
PATCHFILES+=	hier-Pg8.1.2-0.5.5.diff.gz:hier812055
USE_BISON=	build
.  endif

.  if (defined(SERVER_ONLY) && defined(WITH_ICU)) || make(makesum)
USE_AUTOTOOLS=	autoconf:262
CONFIGURE_ARGS+=--with-icu
LIB_DEPENDS=	icudata:${PORTSDIR}/devel/icu
PATCH_SITES+=	http://people.freebsd.org/~girgen/postgresql-icu/:icu
PATCHFILES+=	pg-8121-icu-xx-2010-05-14.diff.gz:icu
.  endif

PATCH_DIST_STRIP=-p1

.  if defined(SERVER_ONLY) && defined(WITH_PAM)
CONFIGURE_ARGS+=--with-pam
.  endif

.  if defined(WITH_INTDATE)
CONFIGURE_ARGS+=--enable-integer-datetimes
.  endif

.  if !(defined(WITHOUT_GETTEXT) || defined(WITHOUT_NLS))
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	GETTEXT=""
USE_GETTEXT=	YES
.  else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	GETTEXT="@comment "
.  endif

.  if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -funroll-loops
.  endif

.  if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
INSTALL_TARGET=	install
.  else
INSTALL_TARGET=	install-strip
.  endif

.  if defined(WITH_MIT_KRB5)
.    if exists(/usr/lib/libkrb5.so) || exists(/usr/bin/krb5-config)
BROKEN=		You must remove heimdal's /usr/bin/krb5-config and /usr/lib/libkrb5.so*, and set NO_KERBEROS=true in /etc/make.conf to build successfully with MIT-KRB
.    endif
# Allow defining a home built MIT Kerberos by setting KRB5_HOME
.    if defined(KRB5_HOME) && exists(${KRB5_HOME}/lib/libgssapi_krb5.a) && exists(${KRB5_HOME}/bin/krb5-config)
CONFIGURE_ARGS+=--with-krb5
.    else
LIB_DEPENDS+=	krb5.3:${PORTSDIR}/security/krb5
CONFIGURE_ARGS+=--with-krb5
.    endif
.  endif

.  if defined(WITH_HEIMDAL_KRB5)
# Allow defining a home built Heimdal Kerberos by setting HEIMDAL_HOME
.    if defined(HEIMDAL_HOME) && exists(${HEIMDAL_HOME}/lib/libgssapi.a) && exists(${HEIMDAL_HOME}/bin/krb5-config)
CONFIGURE_ARGS+=--with-krb5
.    else
# Postgresql apps will not link properly when libpq is linked with base heimdal in /usr,
# so we always use the heimdal port. See
# http://lists.freebsd.org/pipermail/freebsd-stable/2005-October/018809.html
LIB_DEPENDS+=	krb5.23:${PORTSDIR}/security/heimdal
CONFIGURE_ARGS+=--with-krb5
.    endif
.  endif

.  if (defined(SERVER_ONLY) && defined(WITH_TESTS)) || make(makesum)
EXTRA_PATCHES= ${FILESDIR}/regresspatch-src-test-regress-pgregress-sh
.  endif

.endif # !SLAVE_ONLY

.if ${ARCH} == sparc64 && ${OSVERSION} < 700000
USE_GCC=	4.2+
.endif

.if defined(CLIENT_ONLY)
MAN1=		clusterdb.1 createdb.1 createlang.1 createuser.1   \
		dropdb.1 droplang.1 dropuser.1 ecpg.1 initdb.1	   \
		ipcclean.1 pg_config.1 pg_controldata.1 pg_ctl.1   \
		pg_dump.1 pg_dumpall.1 pg_resetxlog.1 pg_restore.1 \
		postgres.1 postmaster.1 psql.1 reindexdb.1 vacuumdb.1

MAN7=		abort.7 alter_aggregate.7 alter_conversion.7 alter_database.7 \
		alter_domain.7 alter_function.7 alter_group.7		      \
		alter_index.7 alter_language.7 alter_operator_class.7	      \
		alter_role.7						      \
		alter_schema.7 alter_sequence.7 alter_table.7		      \
		alter_trigger.7 alter_user.7 analyze.7 begin.7		      \
		checkpoint.7 close.7 cluster.7 comment.7 commit.7	      \
		commit_prepared.7					      \
		copy.7 create_aggregate.7 create_cast.7			      \
		create_constraint_trigger.7 create_conversion.7		      \
		create_database.7 create_domain.7 create_function.7	      \
		create_group.7 create_index.7 create_language.7		      \
		create_operator.7 create_operator_class.7		      \
		create_role.7						      \
		create_rule.7 create_schema.7 create_sequence.7		      \
		create_table.7 create_table_as.7 create_trigger.7	      \
		create_type.7 create_user.7 create_view.7 deallocate.7	      \
		declare.7 delete.7					      \
		drop_aggregate.7 drop_cast.7 drop_conversion.7		      \
		drop_database.7 drop_domain.7 drop_function.7		      \
		drop_group.7 drop_index.7 drop_language.7		      \
		drop_operator.7 drop_operator_class.7 drop_role.7	      \
		drop_rule.7						      \
		drop_schema.7 drop_sequence.7 drop_table.7 drop_trigger.7     \
		drop_type.7 drop_user.7 drop_view.7 end.7 execute.7	      \
		explain.7 fetch.7 grant.7 insert.7 listen.7 load.7	      \
		lock.7 move.7 notify.7 prepare.7 prepare_transaction.7	      \
		reindex.7 reset.7					      \
		revoke.7 rollback.7 rollback_prepared.7 select.7	      \
		select_into.7 set.7					      \
		set_constraints.7 set_role.7 set_transaction.7 show.7	      \
		set_session_authorization.7 start_transaction.7		      \
		truncate.7 unlisten.7 update.7 vacuum.7			      \
		alter_operator.7 alter_tablespace.7 alter_type.7	      \
		create_tablespace.7 drop_tablespace.7			      \
		release_savepoint.7 rollback_to_savepoint.7		      \
		savepoint.7 \
		spi_connect.7 spi_copytuple.7 spi_cursor_close.7 \
                spi_cursor_fetch.7 spi_cursor_find.7 spi_cursor_move.7 \
                spi_cursor_open.7 spi_exec.7 spi_execp.7 spi_execute.7 \
                spi_execute_plan.7 spi_finish.7 spi_fname.7 spi_fnumber.7 \
                spi_freeplan.7 spi_freetuple.7 spi_freetuptable.7 \
                spi_getargcount.7 spi_getargtypeid.7 spi_getbinval.7 \
                spi_getnspname.7 spi_getrelname.7 spi_gettype.7 \
		spi_gettypeid.7 \
                spi_getvalue.7 spi_is_cursor_plan.7 spi_modifytuple.7 \
                spi_palloc.7 spi_pfree.7 spi_pop.7 spi_prepare.7 spi_push.7 \
                spi_repalloc.7 spi_returntuple.7 spi_saveplan.7
.endif

.if defined(SERVER_ONLY)
pre-everything::
	@${SH} ${PKGINSTALL} ${PORTNAME} BACKUPWARNING
.endif

.if !defined(NO_BUILD)

pre-configure:
.  if defined(WITH_MIT_KRB5) && defined(WITH_HEIMDAL_KRB5)
	@${ECHO} "MIT's and Heimdal Kerberos are mutually exclusive."
	@${ECHO} "Please choose one or the other."
	@exit 1
.  endif

do-build:
	@ cd ${WRKSRC}/src/backend ;\
	${GMAKE} ../../src/include/parser/parse.h ../../src/include/utils/fmgroids.h
	@ for dir in ${BUILD_DIRS}; do \
		cd ${WRKSRC}/$${dir} && ${SETENV} ${MAKE_ENV} ${GMAKE}; \
	done

.  if exists(${FILESDIR}/pkg-message${PKGNAMESUFFIX}.in)
SUB_FILES+=	pkg-message${PKGNAMESUFFIX}
PKGMESSAGE=	${WRKSRC}/pkg-message${PKGNAMESUFFIX}
.  endif
.endif

.if defined(SERVER_ONLY)
pre-su-install:
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL
.endif

.if !defined(NO_BUILD)
post-patch:
	@${REINPLACE_CMD} s/@PTHREAD_LIBS@// ${WRKSRC}/src/Makefile.global.in

do-install:
	@for dir in ${INSTALL_DIRS}; do \
	    cd ${WRKSRC}/$${dir} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${INSTALL_TARGET}; \
	done
.  if defined(SERVER_ONLY)
	@ ${MKDIR} ${PREFIX}/share/postgresql
.    for i in profile cshrc
	${INSTALL_DATA} ${WRKDIR}/dot.$i ${PREFIX}/share/postgresql/dot.$i.dist; \
	${INSTALL_DATA} -o pgsql -g pgsql ${WRKDIR}/dot.$i ~pgsql/dot.$i.dist ; \
	if [ ! -f ~pgsql/.$i ]; then \
		${CP} -p ~pgsql/dot.$i.dist ~pgsql/.$i; \
	fi
.    endfor
	@ ${CHOWN} -R pgsql:pgsql ~pgsql/. ;\
	${MKDIR} ${PREFIX}/etc/periodic/daily ;\
	${INSTALL_SCRIPT} ${FILESDIR}/502.pgsql \
			${PREFIX}/etc/periodic/daily
.  endif # SERVER_ONLY
.  if defined(CLIENT_ONLY)
	@ cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${GMAKE} install-local
.  endif
	@ if [ -r ${PKGMESSAGE} ]; then \
		${MKDIR} ${DOCSDIR} ;\
		${INSTALL_DATA} ${PKGMESSAGE} ${DOCSDIR}/README${PKGNAMESUFFIX} ;\
		${ECHO} "======================================================================" ;\
		${CAT} ${PKGMESSAGE} ;\
		${ECHO} "======================================================================" ;\
	fi
.endif # !NO_BUILD

.if defined(SERVER_ONLY) && defined(WITH_TESTS)
check:
	@if [ `id -u` != 0 ] ; then \
	  ${ECHO} "Running postgresql regressions tests" ;\
	  cd ${WRKSRC}; ${GMAKE} check ;\
	 else \
	  ${ECHO} "You cannot run regression tests when postgresql is built as user root." ; \
	  ${ECHO} "Clean and rebuild the port as a regular user to run the tests." ;\
	 fi
.endif

.include <bsd.port.post.mk>
