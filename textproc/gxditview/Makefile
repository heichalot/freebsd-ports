# New ports collection makefile for:   gxditview
# Date created:                24 June 1998
# Whom:                        Dom Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	gxditview
PORTVERSION=	${GXDVVERSION}${GXDVREVISION}
PORTREVISION=	3
CATEGORIES=	textproc
DISTFILES=	# none

MAINTAINER=	ru@FreeBSD.org
COMMENT=	An X11 based previewer for groff output

MAN1=		gxditview.1
PLIST_FILES=	bin/gxditview lib/X11/app-defaults/GXditview

.if !exists(/usr/src/contrib/groff/src)
IGNORE=		requires /usr/src/contrib/groff/src to build
GXDVVERSION=	1.16
GXDVREVISION=	.1
.else
GXDVVERSION!=	cat /usr/src/contrib/groff/VERSION
GXDVREVISION!=	sed -e 's/^0$$//' -e 's/^[1-9].*$$/.&/' /usr/src/contrib/groff/REVISION
.endif

.if exists(/usr/src/contrib/groff/src/devices/xditview) && \
    exists(/usr/src/gnu/usr.bin/groff/src/devices/xditview)
USE_XORG=	x11 xproto xt xmu xaw
MANCOMPRESSED=	maybe
WRKSRC=		/usr/src/gnu/usr.bin/groff/src/devices/xditview
MAKE_ENV=	MAKEOBJDIR=${WRKDIR}

pre-configure-script:
	@${DO_NADA}
.elif exists(/usr/src/contrib/groff/src/xditview)
USE_IMAKE=	yes

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKSRC}
	${CP} -rp /usr/src/contrib/groff/src/xditview/* ${WRKSRC}
.endif

.include <bsd.port.mk>
