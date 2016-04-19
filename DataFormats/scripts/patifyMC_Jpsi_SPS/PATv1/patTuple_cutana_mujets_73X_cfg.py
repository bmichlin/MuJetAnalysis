## import skeleton process
from PhysicsTools.PatAlgos.patTemplate_cfg import *

# verbose flags for the PF2PAT modules
process.options.allowUnscheduled = cms.untracked.bool(True)

### Add MuJet Dataformats
from MuJetAnalysis.DataFormats.EventContent_version10_cff import *
process = customizePatOutput(process)

process.load("MuJetAnalysis.DataFormats.RECOtoPAT_cff")
process.patMuons.addGenMatch = cms.bool(False)
process.patMuons.embedGenMatch = cms.bool(False)

## pick latest HLT process
process.patTrigger.processName = cms.string( "*" )
process.patTriggerEvent.processName = cms.string( "*" )

process.load("MuJetAnalysis.MuJetProducer.MuJetProducer_cff")
process.load("MuJetAnalysis.CutFlowAnalyzer.CutFlowAnalyzer_cfi")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
		"file:/afs/cern.ch/work/b/bmichlin/public/withTAMU/CMSSW_7_4_12_patch4/src/MuJetAnalysis/DataFormats/scripts/patifyMC_Jpsi_SPS/PATv1/out_reco_18.root"
    )
)

process.maxEvents.input = 500

process.p = cms.Path(
	process.MuJetProducers * 
    process.cutFlowAnalyzer
)

process.outpath = cms.EndPath(process.out)

process.TFileService = cms.Service("TFileService",
    fileName = cms.string("out_ana_jpsi_sps.root")
)
