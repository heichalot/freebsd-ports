# ex:ts=8
# Ports collection makefile for:	p5-Gnome2-Canvas
# Date created:			Apr 1, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Gnome2-Canvas
PORTVERSION=	1.002
PORTREVISION=	6
CATEGORIES=	x11-toolkits gnome perl5
MASTER_SITES=	CPAN/Gnome2 \
		SF/gtk2-perl/Gnome2_Canvas/${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allows a perl developer to use the GnomeCanvas widget with Gtk2-Perl

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		${SITE_PERL}/${PERL_ARCH}/Glib.pm:${PORTSDIR}/devel/p5-Glib2 \
		${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/Cairo.pm:${PORTSDIR}/graphics/p5-Cairo
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Glib.pm:${PORTSDIR}/devel/p5-Glib2 \
		${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2

USE_GNOME=	libgnomecanvas
PERL_CONFIGURE=	5.8.0+
MAKE_JOBS_UNSAFE=	yes

post-install:
	@cd ${WRKSRC}/blib/man3 && ${FIND} * -name "*.3" | ${SED} \
		's,^,${MAN3PREFIX:S,^${PREFIX}/,,}/man/man3/,' >> ${TMPPLIST}

.include <bsd.port.mk>
