import FWCore.ParameterSet.Config as cms

LeptonJetFlowAnalyzer = cms.EDAnalyzer('LeptonJetAnalyzer',
    analyzerDebug = cms.int32(0),
    fillGenLevel = cms.bool(True),
#    muons = cms.InputTag("cleanPatTrackerMuonsTriggerMatch"),
#    muJets = cms.InputTag("TrackerMuJetProducer05"),
    muons = cms.InputTag("cleanPatPFMuonsTriggerMatch"),
    muJets = cms.InputTag("PFMuJetProducer05"),
    DiMuons_Iso_Max = cms.double(2.0),
    ## add electron variables
    nThrowsConsistentVertexesCalculator = cms.int32(100000),
    hltPaths = cms.vstring(
        'HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v1',
    )
)
