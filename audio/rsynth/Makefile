# New ports collection makefile for:	rsynth
# Date created:		03 Jan 1995
# Whom:			faulkner@mpd.tandem.com
#
# $FreeBSD$
#

PORTNAME=	rsynth
PORTVERSION=	2.0
PORTREVISION=	3
CATEGORIES=	audio accessibility
MASTER_SITES=	ftp://svr-ftp.eng.cam.ac.uk/pub/comp.speech/synthesis/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Speech synthesizer

LIB_DEPENDS=	gdbm:${PORTSDIR}/databases/gdbm	\
		audio:${PORTSDIR}/audio/nas

GNU_CONFIGURE=	yes

pre-configure:
	@${CP} ${FILESDIR}/freebsdplay.c ${WRKSRC}/config/freebsdplay.c
	@${CP} ${FILESDIR}/config.guess ${WRKSRC}/config.guess
	@${CP} ${FILESDIR}/config.sub ${WRKSRC}/config.sub
	@${CP} ${FILESDIR}/configure ${WRKSRC}/configure

.include <bsd.port.mk>
