# New ports collection makefile for:	p5-Net-BitTorrent
# Date created:		2008-04-12
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-BitTorrent
PORTVERSION=	0.052
CATEGORIES=	net-p2p perl5
MASTER_SITES=	CPAN/../../authors/id/S/SA/SANKO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	BitTorrent peer-to-peer protocol class

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA.pm:${PORTSDIR}/security/p5-Digest-SHA \
		${SITE_PERL}/${PERL_ARCH}/version.pm:${PORTSDIR}/devel/p5-version
BUILD_DEPENDS=	${RUN_DEPENDS}

CONFIGURE_ARGS=	</dev/null
PERL_MODBUILD=	yes

MAN1=		net-bittorrent.pl.1
MAN3=		Net::BitTorrent.3 \
		Net::BitTorrent::Notes.3 \
		Net::BitTorrent::ConfigData.3 \
		Net::BitTorrent::DHT.3 \
		Net::BitTorrent::Peer.3 \
		Net::BitTorrent::Protocol.3 \
		Net::BitTorrent::Torrent.3 \
		Net::BitTorrent::Torrent::File.3 \
		Net::BitTorrent::Torrent::Tracker.3 \
		Net::BitTorrent::Torrent::Tracker::HTTP.3 \
		Net::BitTorrent::Torrent::Tracker::UDP.3 \
		Net::BitTorrent::Util.3 \
		Net::BitTorrent::Version.3

.include <bsd.port.mk>
