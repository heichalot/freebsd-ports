# New ports collection makefile for:	dixit
# Date created:				2005-01-11
# Whom:					Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
#
# $FreeBSD$
#

PORTNAME=	dixit
PORTVERSION=	10.4.4
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/10.4/:dixit \
		SF/${PORTNAME}/${PORTNAME}_qdb/:db
DISTFILES=	${PORTNAME}-${PORTVERSION}.tgz:${PORTNAME} \
		${_DB_D}:db
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tgz

MAINTAINER=	itetcu@people.tecnik93.com
COMMENT=	Romanian dictionaries databases and query application

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_SUB=	_DB=${_DB} DB_DIR=${DB_DIR} _DB_F=${_DB_F}

DB_DIR?=	/var/db/dixit
DB_OWNER?=	root
DB_GROUP?=	wheel
DB_MODE?=	0664
# DB_DATE is the time of the file in the zip archive, not the time of the last
# update of the database (which is a little earlier, but TZ makes it appear to
# be later), but it's all we can do in a makefile.
DB_DATE=201004010000
_DB_D=	${PORTNAME}.qdb.tar.bz2
_DB_F=	${PORTNAME}.qdb
_DB=	${DB_DIR}/${_DB_F}

HAS_CONFIGURE=	yes

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network moc_build qmake_build rcc_build
#USE_GMAKE=	yes
#MAKE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS} QTDIR="${QT_PREFIX}"

pre-everything::
	@${ECHO_CMD}
	@${ECHO_CMD} "Your dictionary database directory is:"
	@${ECHO_CMD} "DB_DIR=${DB_DIR} (default /var/db/dixit)"
	@${ECHO_CMD} "You need about 65MB for the dictionary db."
#	@${ECHO_CMD} "To overwrite the database, irrespectiv of it's last update"
#	@${ECHO_CMD} "time define DB_OVERWRITE=yes"
#.ifdef(DB_OVERWRITE)
#	@${ECHO_CMD} "DB_OVERWRITE is set, the database will be overwritten !!"
#.endif
	@${ECHO_CMD}
	@${ECHO_CMD} "You can allow all users to update (but potentially also delete"
	@${ECHO_CMD} "or alter) the dictionaries database by setting DB_MODE=0666"
	@${ECHO_CMD} "DB_OWNER=${DB_OWNER} (default: root)"
	@${ECHO_CMD} "DB_GROUP=${DB_GROUP} (default: wheel)"
	@${ECHO_CMD} "DB_MODE=${DB_MODE} (default: 0664)"
	@${ECHO_CMD}

do-configure:
	@${REINPLACE_CMD} -e "s^dixit.qdb^${_DB}^" ${WRKSRC}/src/dixit.h
#	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
#		-spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ ${PORTNAME}.pro
	cd ${WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} ${QMAKE} -unix PREFIX=${PREFIX} ${PORTNAME}.pro

do-install:
	@${MKDIR} ${DB_DIR}
	@${TOUCH} -t ${DB_DATE} ${WRKSRC}/${_DB_F}
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}  ${PREFIX}/bin/${PORTNAME}
	@${ECHO_CMD} "	===> Installing database ... .. ."
.ifndef(DB_OVERWRITE)
	@if [ ! -e "${_DB}" -o "${_DB}" -ot "${WRKSRC}/${_DB_F}" ]; \
		then	${TAR} -C ${DB_DIR:S/${PORTNAME}//} -xf ${DISTDIR}/${_DB_D} && \
			${ECHO_CMD} "	===> ... Done."; \
		else	${ECHO_CMD} "	===> Exisitng database is newer, skiping";\
	fi
.else
	@${ECHO_CMD} "	===> DB_OVERWRITE is set, installing database ... .. ."
	${TAR} -C ${DB_DIR:S/${PORTNAME}//} -xf ${DISTDIR}/${_DB_D}
	@${ECHO_CMD} "	===> ... Done."
.endif
	@${CHOWN} ${DB_OWNER}:${DB_GROUP} ${_DB}
	@${CHMOD} ${DB_MODE} ${_DB}

.include <bsd.port.mk>
