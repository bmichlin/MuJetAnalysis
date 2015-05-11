import FWCore.ParameterSet.Config as cms

from MuJetAnalysis.LeptonJetProducer.MuJetProducer_cfi import *
from MuJetAnalysis.LeptonJetProducer.ElectronJetProducer_cfi import *

TrackerMuJetProducer05 = MuJetProducer.clone(
    maxMass = cms.double(5.),
    muons = cms.InputTag("cleanPatTrackerMuonsTriggerMatch"),
    selectTrackerMuons = cms.bool(True),
    selectGlobalMuons = cms.bool(False),
    groupingMode = cms.string("GroupByMassAndVertexProbOrDeltaR"),
    maxDeltaR = cms.double(0.01),
    minSegmentMatches = cms.int32(2),
    minTrackerHits = cms.int32(8),
    maxTrackerNormChi2 = cms.double(4.0)
)

PFMuJetProducer05 = MuJetProducer.clone(
    maxMass = cms.double(5.),
    muons = cms.InputTag("cleanPatPFMuonsTriggerMatch"),
    selectTrackerMuons = cms.bool(False),
    selectGlobalMuons = cms.bool(False),
    groupingMode = cms.string("GroupByMassAndVertexProbOrDeltaR"),
    maxDeltaR = cms.double(0.01),
#    minSegmentMatches = cms.int32(2),
    minSegmentMatches = cms.int32(-1),
    minTrackerHits = cms.int32(-1),
    maxTrackerNormChi2 = cms.double(-1.0)
)