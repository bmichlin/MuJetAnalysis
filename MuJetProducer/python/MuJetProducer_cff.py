import FWCore.ParameterSet.Config as cms

from MuJetAnalysis.MuJetProducer.MuJetProducer_cfi import *

TrackerMuJetProducer05 = MuJetProducer.clone(
    muons = cms.InputTag("cleanPatTrackerMuonsTriggerMatch"),
    groupingMode = cms.string("GroupByDeltaRAndMass"),
)

PFMuJetProducer05 = MuJetProducer.clone(
    muons = cms.InputTag("cleanPatPFMuonsTriggerMatch"),
    groupingMode = cms.string("GroupByDeltaRAndMass"),
    selectTrackerMuons = cms.bool(False),
    selectGlobalMuons = cms.bool(False),
    minSegmentMatches = cms.int32(-1),
    minTrackerHits = cms.int32(-1),
    maxTrackerNormChi2 = cms.double(-1.0)
)

TrackerMuJetProducer05PXBL2PXFL2 = TrackerMuJetProducer05.clone(
    barrelPixelLayer = cms.int32(2),
    endcapPixelLayer = cms.int32(2),
)
PFMuJetProducer05PXBL2PXFL2 = PFMuJetProducer05.clone(
    barrelPixelLayer = cms.int32(2),
    endcapPixelLayer = cms.int32(2),
)

TrackerMuJetProducer05PXBL3PXFL2 = TrackerMuJetProducer05.clone(
    barrelPixelLayer = cms.int32(3),
    endcapPixelLayer = cms.int32(2),
)
PFMuJetProducer05PXBL3PXFL2 = PFMuJetProducer05.clone(
    barrelPixelLayer = cms.int32(3),
    endcapPixelLayer = cms.int32(2),
)

MuJetProducers = cms.Sequence(
    TrackerMuJetProducer05 * 
    PFMuJetProducer05 *
    TrackerMuJetProducer05PXBL2PXFL2 *
    PFMuJetProducer05PXBL2PXFL2 *
    TrackerMuJetProducer05PXBL3PXFL2 *
    PFMuJetProducer05PXBL3PXFL2
)
