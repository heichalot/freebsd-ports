# Ports collection makefile for:	newgem
# Date created:				January 12, 2010
# Whom:					Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	newgem
PORTVERSION=	1.5.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Bundle ruby libraries into gems

RUN_DEPENDS=	rubygem-activesupport>=2.0.2:${PORTSDIR}/devel/rubygem-activesupport \
  rubygem-rubigen>=1.5.1:${PORTSDIR}/devel/rubygem-rubigen \
  rubygem-hoe>=1.8.0:${PORTSDIR}/devel/rubygem-hoe \
  rubygem-redcloth>=4.0.0:${PORTSDIR}/www/rubygem-redcloth \
  rubygem-syntax>=1.0.0:${PORTSDIR}/textproc/rubygem-syntax \
  rubygem-rubigen>=1.5.3:${PORTSDIR}/devel/rubygem-rubigen

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/newgem

.include <bsd.port.mk>
