# New ports collection makefile for:   py-migrate
# Date created:        9 November 2006
# Whom:                elvstone@gmail.com
#
# $FreeBSD$
#

PORTNAME=	migrate
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		http://dose.se/distfiles/migrate/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sqlalchemy-${PORTNAME}-${PORTVERSION}

MAINTAINER=	elvstone@gmail.com
COMMENT=	Database schema migrations for SQLAlchemy

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0.3.10:${PORTSDIR}/databases/py-sqlalchemy

PROJECTHOST=	sqlalchemy-migrate
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	sqlalchemy_${PORTNAME}

.include <bsd.port.mk>
