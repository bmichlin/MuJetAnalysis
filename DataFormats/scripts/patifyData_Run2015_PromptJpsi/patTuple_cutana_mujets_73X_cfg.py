## import skeleton process
from PhysicsTools.PatAlgos.patTemplate_cfg import *

from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag
#process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
#For CMSSW 74X X>10
process.GlobalTag = GlobalTag(process.GlobalTag, '74X_dataRun2_Prompt_v3')
#For CMSSW 741
#process.GlobalTag = GlobalTag(process.GlobalTag, '74X_dataRun2_Prompt_v0')

# verbose flags for the PF2PAT modules
process.options.allowUnscheduled = cms.untracked.bool(True)

### Add MuJet Dataformats
from MuJetAnalysis.DataFormats.EventContent_version10_cff import *
process = customizePatOutput(process)

process.load("MuJetAnalysis.DataFormats.RECOtoPAT_cff")
#process.patMuons.addGenMatch = cms.bool(True)
#process.patMuons.embedGenMatch = cms.bool(True)
process.patMuons.addGenMatch = cms.bool(False)
process.patMuons.embedGenMatch = cms.bool(False)

## pick latest HLT process
process.patTrigger.processName = cms.string( "*" )
process.patTriggerEvent.processName = cms.string( "*" )

process.load("MuJetAnalysis.MuJetProducer.MuJetProducer_cff")
process.load("MuJetAnalysis.CutFlowAnalyzer.CutFlowAnalyzer_cfi")
process.cutFlowAnalyzer.fillGenLevel = cms.bool(False)

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
		#"file:JpsiEvents_259809.root"
		#"file:4Events_OddBehaior.root"
		#"file:JpsiEvent_259809.root"
		#"/store/data/Run2015D/MuOnia/AOD/PromptReco-v4/000/259/809/00000/2C061B7F-0D7B-E511-A8C8-02163E0119D1.root"
		"file:2C061B7F-0D7B-E511-A8C8-02163E0119D1.root"
    )
)

process.maxEvents.input = -1

process.p = cms.Path(
	process.MuJetProducers * 
    process.cutFlowAnalyzer
)

process.outpath = cms.EndPath(process.out)

process.TFileService = cms.Service("TFileService",
    fileName = cms.string("out_ana_PF_Jpsi.root")
)
