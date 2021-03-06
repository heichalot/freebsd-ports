# New ports collection makefile for:	AI-Categorizer
# Date created:				19 Feb 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	AI-Categorizer
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatic Text Categorization

BUILD_DEPENDS=	${SITE_PERL}/Class/Container.pm:${PORTSDIR}/devel/p5-Class-Container \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		${SITE_PERL}/Statistics/Contingency.pm:${PORTSDIR}/math/p5-Statistics-Contingency \
		${SITE_PERL}/Lingua/Stem.pm:${PORTSDIR}/textproc/p5-Lingua-Stem \
		${SITE_PERL}/Time/Progress.pm:${PORTSDIR}/devel/p5-Time-Progress \
		${SITE_PERL}/${PERL_ARCH}/Algorithm/SVM.pm:${PORTSDIR}/devel/p5-Algorithm-SVM \
		${SITE_PERL}/${PERL_ARCH}/AI/DecisionTree.pm:${PORTSDIR}/math/p5-AI-DecisionTree \
		${SITE_PERL}/Algorithm/NaiveBayes.pm:${PORTSDIR}/devel/p5-Algorithm-NaiveBayes
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	AI::Categorizer.3 \
	AI::Categorizer::Category.3 \
	AI::Categorizer::Collection.3 \
	AI::Categorizer::Collection::Files.3 \
	AI::Categorizer::Document.3 \
	AI::Categorizer::Experiment.3 \
	AI::Categorizer::FeatureSelector.3 \
	AI::Categorizer::FeatureSelector::CategorySelector.3 \
	AI::Categorizer::FeatureSelector::ChiSquare.3 \
	AI::Categorizer::FeatureSelector::DocFrequency.3 \
	AI::Categorizer::FeatureVector.3 \
	AI::Categorizer::Hypothesis.3 \
	AI::Categorizer::KnowledgeSet.3 \
	AI::Categorizer::Learner.3 \
	AI::Categorizer::Learner::Boolean.3 \
	AI::Categorizer::Learner::DecisionTree.3 \
	AI::Categorizer::Learner::Guesser.3 \
	AI::Categorizer::Learner::KNN.3 \
	AI::Categorizer::Learner::NaiveBayes.3 \
	AI::Categorizer::Learner::SVM.3 \
	AI::Categorizer::Learner::Weka.3 \
	AI::Categorizer::Storable.3

PERL_MODBUILD=	yes

.include <bsd.port.mk>
