# New ports collection makefile for:	hgview
# Date created:		20 Nov 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hgview
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	LOGILAB

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A fast Mercurial log navigator written in pyqt4

RUN_DEPENDS=	hg:${PORTSDIR}/devel/mercurial \
		${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_SITELIBDIR}/PyQt4/Qsci.so:${PORTSDIR}/devel/py-qt4-qscintilla2 \
		${PYTHON_SITELIBDIR}/mx/DateTime/__init__.py:${PORTSDIR}/lang/py-mx-base \
		${PYTHON_SITELIBDIR}/docutils/__init__.py:${PORTSDIR}/textproc/py-docutils
BUILD_DEPENDS=	hg:${PORTSDIR}/devel/mercurial \
		xmlto:${PORTSDIR}/textproc/xmlto \
		asciidoc:${PORTSDIR}/textproc/asciidoc

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_GMAKE=	yes
PORTDOCS=	*

MAN1=		hgview.1

post-patch:
	@${REINPLACE_CMD} -e 's|share/python-support/mercurial-common|${PYTHON_SITELIBDIR:C,^${PYTHONBASE}/,,}|' \
		${WRKSRC}/hgviewlib/__pkginfo__.py
	@${FIND} ${WRKSRC} -name __pkginfo__.py | ${XARGS} \
		${REINPLACE_CMD} -e 's|share/man|man|'
	@${REINPLACE_CMD} -e 's|path/to.*hgview.py|${PYTHON_SITELIBDIR}/hgext/hgview.py|' \
		${WRKSRC}/README
	@${REINPLACE_CMD} -e '/system/ s|make|${GMAKE}|' ${WRKSRC}/setup.py

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
