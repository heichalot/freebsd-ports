# ex:ts=8
# Ports collection makefile for:	p5-Font-TTF
# Date created:			Apr 28, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Font-TTF
PORTVERSION=	0.45
PORTREVISION=	1
CATEGORIES=	x11-fonts perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for TrueType font hacking

PERL_CONFIGURE=	yes

MAN3=	\
	Font::TTF.3 \
	Font::TTF::AATKern.3 \
	Font::TTF::AATutils.3 \
	Font::TTF::Anchor.3 \
	Font::TTF::Bsln.3 \
	Font::TTF::Cmap.3 \
	Font::TTF::Coverage.3 \
	Font::TTF::Cvt_.3 \
	Font::TTF::Delta.3 \
	Font::TTF::Dumper.3 \
	Font::TTF::EBDT.3 \
	Font::TTF::EBLC.3 \
	Font::TTF::Fdsc.3 \
	Font::TTF::Feat.3 \
	Font::TTF::Fmtx.3 \
	Font::TTF::Font.3 \
	Font::TTF::Fpgm.3 \
	Font::TTF::GDEF.3 \
	Font::TTF::GPOS.3 \
	Font::TTF::GSUB.3 \
	Font::TTF::Glyf.3 \
	Font::TTF::Glyph.3 \
	Font::TTF::GrFeat.3 \
	Font::TTF::Hdmx.3 \
	Font::TTF::Head.3 \
	Font::TTF::Hhea.3 \
	Font::TTF::Hmtx.3 \
	Font::TTF::Kern.3 \
	Font::TTF::Kern::ClassArray.3 \
	Font::TTF::Kern::CompactClassArray.3 \
	Font::TTF::Kern::OrderedList.3 \
	Font::TTF::Kern::StateTable.3 \
	Font::TTF::Kern::Subtable.3 \
	Font::TTF::LTSH.3 \
	Font::TTF::Loca.3 \
	Font::TTF::Manual.3 \
	Font::TTF::Maxp.3 \
	Font::TTF::Mort.3 \
	Font::TTF::Mort::Chain.3 \
	Font::TTF::Mort::Contextual.3 \
	Font::TTF::Mort::Insertion.3 \
	Font::TTF::Mort::Ligature.3 \
	Font::TTF::Mort::Noncontextual.3 \
	Font::TTF::Mort::Rearrangement.3 \
	Font::TTF::Mort::Subtable.3 \
	Font::TTF::Name.3 \
	Font::TTF::OS_2.3 \
	Font::TTF::OTTags.3 \
	Font::TTF::OldCmap.3 \
	Font::TTF::OldMort.3 \
	Font::TTF::PCLT.3 \
	Font::TTF::PSNames.3 \
	Font::TTF::Post.3 \
	Font::TTF::Prep.3 \
	Font::TTF::Prop.3 \
	Font::TTF::Segarr.3 \
	Font::TTF::Table.3 \
	Font::TTF::Ttc.3 \
	Font::TTF::Ttopen.3 \
	Font::TTF::Utils.3 \
	Font::TTF::Vhea.3 \
	Font::TTF::Vmtx.3 \
	Font::TTF::XMLparse.3

post-extract:
	@${FIND} ${WRKSRC} -name '*.swp' -delete

.include <bsd.port.mk>
