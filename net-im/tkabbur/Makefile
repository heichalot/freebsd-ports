# New ports collection makefile for:	tkabbur
# Date created:				06 October 2008
# Whom:					Dennis Herrmann <adox@mcx2.org>
#
# $FreeBSD$
#

PORTNAME=	tkabbur
PORTVERSION=	0.8
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Is a modification of XMPP/Jabber client Tkabber

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
		dtplite:${PORTSDIR}/devel/tcllib \
		${LOCALBASE}/lib/tls/pkgIndex.tcl:${PORTSDIR}/devel/tcltls \
		${LOCALBASE}/lib/bwidget/pkgIndex.tcl:${PORTSDIR}/x11-toolkits/bwidget

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_BZIP2=	yes
NO_BUILD=	yes

SUBDIRS=	contrib emoticons ifacetk jabberlib mclistbox \
		msgs pixmaps plugins sounds tclxml trans

do-install:
	${ECHO} -e "#!/bin/sh\nexec wish8.4 ${DATADIR}/tkabbur.tcl \
		-name tkabbur \"\$$@\"\n" > ${PREFIX}/bin/tkabbur
	${CHMOD} +x ${PREFIX}/bin/tkabbur
	${CHMOD} 755 ${WRKSRC}/*.tcl
	${MKDIR} ${DATADIR}
	${CP} ${WRKSRC}/*.tcl ${DATADIR}
.for i in ${SUBDIRS}
	${CHMOD} -R 755 ${WRKSRC}/${i}
	${CP} -R ${WRKSRC}/${i} ${DATADIR}
.endfor

.include <bsd.port.mk>
