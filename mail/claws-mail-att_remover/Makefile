# New ports collection makefile for:	sylpheed-claws-att_remover
# Date created:	3 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	att_remover
PORTVERSION=	1.0.12
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-

MAINTAINER=	c0rn@o2.pl
COMMENT=	Attachments removing plugin for claws-mail

BUILD_DEPENDS=	claws-mail>=3.7.6:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.7.6:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262

PLIST_FILES=	lib/claws-mail/plugins/att_remover.a \
		lib/claws-mail/plugins/att_remover.la \
		lib/claws-mail/plugins/att_remover.so

.include <bsd.port.mk>
