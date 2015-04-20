## import skeleton process
from PhysicsTools.PatAlgos.patTemplate_cfg import *

## PostLS1 Magnetic field                                                                                                                                                                         
process.load('Configuration.StandardSequences.MagneticField_38T_PostLS1_cff')

# verbose flags for the PF2PAT modules
process.options.allowUnscheduled = cms.untracked.bool(True)

### Add MuJet Dataformats
from MuJetAnalysis.DataFormats.EventContent_version10_cff import *
process = customizePatOutput(process)

process.load("MuJetAnalysis.DataFormats.RECOtoPAT_cff")
process.patMuons.addGenMatch = cms.bool(True)
process.patMuons.embedGenMatch = cms.bool(True)

## pick latest HLT process
process.patTrigger.processName = cms.string( "*" )
process.patTriggerEvent.processName = cms.string( "*" )

process.source = cms.Source("PoolSource",
  fileNames = cms.untracked.vstring(
        'file:out_hlt.root'
  )
)

process.maxEvents.input = -1

process.load("MuJetAnalysis.LeptonJetProducer.LeptonJetProducer_cff")
process.load("MuJetAnalysis.CutFlowAnalyzer.CutFlowAnalyzer_cfi")

process.p = cms.Path(
    process.TrackerMuJetProducer05 *
    process.PFMuJetProducer05 *
    process.cutFlowAnalyzer
)

process.outpath = cms.EndPath(process.out)

process.TFileService = cms.Service("TFileService",
    fileName = cms.string("out_ana.root")
)
