# New ports collection makefile for:	py-django-livesettings
# Date created:				19 May 2010
# Whom:					Kevin Golding <ports@caomhin.org>
#
# $FreeBSD$
#

PORTNAME=	django-livesettings
PORTVERSION=	1.4.4
CATEGORIES=	www python
MASTER_SITES=	http://www.caomhin.org/ports/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Configure settings via Django admin interface rather than by editing settings.py

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_NOEGGINFO=	yes
PYEASYINSTALL_EGG=	${PYDISTUTILS_PKGNAME:C/[^A-Za-z0-9.]+/_/g}-${PORTVERSION:C/([[:digit:]]\.[[:digit:]])\./\1_/g}-${PYTHON_VERSION:S/thon//}${PYEASYINSTALL_OSARCH}.egg
PYEASYINSTALL_UNINSTALLARGS=	-q -m -S ${PYTHON_SITELIBDIR} \
				${PYDISTUTILS_PKGNAME}==${PYDISTUTILS_PKGVERSION:C/([[:digit:]]\.[[:digit:]])\./\1_/g}

.include <bsd.port.mk>
