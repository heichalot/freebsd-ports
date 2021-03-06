# New ports collection makefile for:	Democracy
# Date created:		30 November 2006
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	miro
PORTVERSION=	2.5.4
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.osuosl.org/pub/pculture.org/miro/src/	\
		http://ftp.osuosl.org/pub/pculture.org/miro/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A video player to get internet TV broadcasts

BUILD_DEPENDS=	pyrexc:${PORTSDIR}/devel/pyrex				\
		update-mime-database:${PORTSDIR}/misc/shared-mime-info
LIB_DEPENDS=	boost_python.4:${PORTSDIR}/devel/boost-python-libs		\
		xine.1:${PORTSDIR}/multimedia/libxine
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb	\
		${PYTHON_SITELIBDIR}/pysqlite2/_sqlite.so:${PORTSDIR}/databases/py-pysqlite23	\
		${PYTHON_SITELIBDIR}/dbus/glib.py:${PORTSDIR}/devel/py-dbus	\
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/_pynotify.so:${PORTSDIR}/devel/py-notify	\
		convert:${PORTSDIR}/graphics/ImageMagick

BUILD_WRKSRC=	${WRKSRC}/platform/gtk-x11
INSTALL_WRKSRC=	${WRKSRC}/platform/gtk-x11

CONFLICTS=	Miro-[0-9]*

USE_GCC=	4.4+
USE_GNOME=	gtk20 pygnomeextras
USE_GECKO=	libxul seamonkey
USE_OPENSSL=	yes
USE_PYTHON=	yes
WANT_GSTREAMER=	yes
USE_GETTEXT=	yes
USE_PYDISTUTILS=	yes
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}"
INSTALLS_ICONS=	yes
INSTALLS_EGGINFO=	yes

MANCOMPRESSED=	yes
MAN1=		miro.1 miro.real.1

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}

.include <bsd.port.pre.mk>

.if defined(WITH_GSTREAMER)
USE_GSTREAMER+=	python
.endif

.if defined(GECKO) && ${GECKO:Mlibxul}!=""
CPPFLAGS+=	-D_WCHAR_T_DECLARED
XPCOM_LIB=	${GECKO}
GTKMOZEMBED_LIB=${GECKO}
XULRUNNER_19=	True
.else
XPCOM_LIB=	${GECKO}-xpcom
GTKMOZEMBED_LIB=${GECKO}-gtkmozembed
XULRUNNER_19=	False
.endif

.SILENT:

post-patch:
.for file in setup.py plat/resources.py
	${REINPLACE_CMD} -e 's|%%XPCOM_RUNTIME_PATH%%|${LOCALBASE}/lib/${GECKO}|g ; \
		 s|%%XPCOM_LIB%%|${XPCOM_LIB}|g ; \
		 s|%%GTKMOZEMBED_LIB%%|${GTKMOZEMBED_LIB}|g ; \
		 s|%%XULRUNNER_19%%|${XULRUNNER_19}|g ; \
		 s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		 s|%%CC%%|${CC}|g ; \
		 s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g ; \
		 s|%%PREFIX%%|${PREFIX}|g ; \
		 s|%%MANPREFIX%%|${MANPREFIX}|g' \
		${BUILD_WRKSRC}/${file}
.endfor
.for file in miro.real
	${REINPLACE_CMD} -e 's|python2.4|${PYTHON_VERSION}|g' \
		${BUILD_WRKSRC}/${file}
.endfor
.for file in run.sh
	${REINPLACE_CMD} -e 's|^PREFIX=.*|PREFIX=${PREFIX}|g' \
		${BUILD_WRKSRC}/${file}
.endfor
.for file in plat/renderers/xinerenderer.py
	${REINPLACE_CMD} -e 's|lib/miro|libexec/miro|g' \
		${BUILD_WRKSRC}/${file}
.endfor

.if defined(MAINTAINER_MODE)
regression-test:	install
	LANG=C LC_ALL=C ${PREFIX}/bin/miro --unittest
.endif

.include <bsd.port.post.mk>
