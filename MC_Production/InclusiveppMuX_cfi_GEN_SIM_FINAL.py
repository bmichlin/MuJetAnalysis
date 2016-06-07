# Auto generated configuration file
# using: 
# Revision: 1.19 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: InclusiveppMuX_cfi -s GEN,SIM --mc --datatier GEN-SIM --beamspot NominalCollision2015 --conditions 74X_mcRun2_asymptotic_realisticBS_v1 --magField 38T_PostLS1 --eventcontent RAWSIM --customise=SLHCUpgradeSimulations/Configuration/postLS1Customs.customisePostLS1 --fileout out_sim.root -n 10 --no_exec
import FWCore.ParameterSet.Config as cms

process = cms.Process('SIM')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.Geometry.GeometrySimDB_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_PostLS1_cff')
process.load('Configuration.StandardSequences.Generator_cff')
process.load('IOMC.EventVertexGenerators.VtxSmearedNominalCollision2015_cfi')
process.load('GeneratorInterface.Core.genFilterSummary_cff')
process.load('Configuration.StandardSequences.SimIdeal_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10)
)

# Input source
process.source = cms.Source("EmptySource")

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    annotation = cms.untracked.string('InclusiveppMuX_cfi nevts:10'),
    name = cms.untracked.string('Applications'),
    version = cms.untracked.string('$Revision: 1.19 $')
)

# Output definition

process.RAWSIMoutput = cms.OutputModule("PoolOutputModule",
    SelectEvents = cms.untracked.PSet(
        SelectEvents = cms.vstring('generation_step')
    ),
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('GEN-SIM'),
        filterName = cms.untracked.string('')
    ),
    eventAutoFlushCompressedSize = cms.untracked.int32(5242880),
    fileName = cms.untracked.string('out_sim.root'),
    outputCommands = process.RAWSIMEventContent.outputCommands,
    splitLevel = cms.untracked.int32(0)
)

# Additional output definition

# Other statements
process.genstepfilter.triggerConditions=cms.vstring("generation_step")
from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '74X_mcRun2_asymptotic_realisticBS_v1', '')

# Double J/psi filter
process.oniagenfilter = cms.EDFilter("MCParticlePairFilter",
    Status = cms.untracked.vint32(2, 2),
    MinPt = cms.untracked.vdouble(3.5, 3.5),
    #MinPt = cms.untracked.vdouble(10.0, 10.0),
    MaxEta = cms.untracked.vdouble(2.5, 2.5),
    MinEta = cms.untracked.vdouble(-2.5, -2.5),
    ParticleCharge = cms.untracked.int32(0),
    ParticleID1 = cms.untracked.vint32(443),
    ParticleID2 = cms.untracked.vint32(443)
)
# Four muons filter
process.fourmugenfilter = cms.EDFilter("MCMultiParticleFilter",
                                       src = cms.InputTag("generator"),
                                       NumRequired = cms.int32(4),
                                       AcceptMore = cms.bool(True),
                                       ParticleID = cms.vint32(13),
                                       Status = cms.vint32(1),
                                       PtMin = cms.vdouble(3.0),
                                       EtaMax = cms.vdouble(2.5),
                                       )
#NEW
from Configuration.Generator.Pythia8CommonSettings_cfi import *
from Configuration.Generator.Pythia8CUEP8M1Settings_cfi import *

process.generator = cms.EDFilter("Pythia8GeneratorFilter",
   crossSection = cms.untracked.double(1.755e-04),
   maxEventsToPrint = cms.untracked.int32(1),
   pythiaPylistVerbosity = cms.untracked.int32(1),
   filterEfficiency = cms.untracked.double(0.000416),
   pythiaHepMCVerbosity = cms.untracked.bool(True),
   comEnergy = cms.double(13000.0),
   PythiaParameters = cms.PSet(
   pythia8CommonSettingsBlock,
   pythia8CUEP8M1SettingsBlock,
   processParameters = cms.vstring(
           'Main:timesAllowErrors = 10000',
           'Charmonium:all = on', # turn on charmonium production
#!           'PartonLevel:MI = on', # worked before Pythia 8.20
           'PartonLevel:MPI = on', # works since Pythia 8.20
           'SecondHard:generate = on',
           'SecondHard:Charmonium = on',
           # Modify phase-space for pTHat
           'PhaseSpace:pTHatMin = 3.0',
           'PhaseSpace:pTHatMinSecond = 3.0',
           'PhaseSpace:pTHatMinDiverge = 0.5',
           # Allow Jpsi-->2mu only:
           '443:onMode = off',
           '443:onIfAny = -13 13',
           # Modify Singlet decays:
           '445:onMode    = off',    # turn off all chi_2c decays 
           '445:onIfAny   = 443 22', # turn on chi_2c --> Jpsi+gamma (bRatio="0.2020000")
           '10441:onMode  = off',    # chi_0c
           '10441:onIfAny = 443 22', # turn on chi_0c --> Jpsi+gamma (bRatio="0.0200000")
           '20443:onMode  = off',    # chi_1c
           '20443:onIfAny = 443 22', # turn on chi_1c --> Jpsi+gamma (bRatio="0.3560000")
           # Modify Octet decays (worked before Pythia 8.20)
#!           '9900443:onMode = off', # ccbar[3S1(8)]
#!           '9900443:onIfAny = 443 21',                                  
#!           '9900441:onMode = off', # ccbar[1S0(8)]
#!           '9900441:onIfAny = 443 21',                                  
#!           '9910441:onMode = off', # ccbar[3P0(8)]
#!           '9910441:onIfAny = 443 21',
           # Modify Octet decays (works since Pythia 8.20):
           '9940003:onMode = off', # J/psi[3S1(8)]
           '9940003:onIfAny = 443 21',
           '9940005:onMode = off', # chi_2c[3S1(8)]
           '9940005:onIfAny = 445 21',
           '9940011:onMode = off', # chi_0c[3S1(8)]
           '9940011:onIfAny = 10441 21',
           '9940023:onMode = off', # chi_1c[3S1(8)]
           '9940023:onIfAny = 20443 21',
           '9941003:onMode = off', # J/psi[1S0(8)]
           '9941003:onIfAny = 443 21',
           '9942003:onMode = off', # J/psi[3PJ(8)]
           '9942003:onIfAny = 443 21',
       ),
       parameterSets = cms.vstring('pythia8CommonSettings',
                                   'pythia8CUEP8M1Settings',
                                   'processParameters')
   )
)
#OLD
#process.mugenfilter = cms.EDFilter("MCSmartSingleParticleFilter",
#    MaxDecayRadius = cms.untracked.vdouble(1500.0, 1500.0),
#    MaxDecayZ = cms.untracked.vdouble(3000.0, 3000.0),
#    MaxEta = cms.untracked.vdouble(2.5, 2.5),
#    MinDecayZ = cms.untracked.vdouble(-3000.0, -3000.0),
#    MinEta = cms.untracked.vdouble(-2.5, -2.5),
#    MinPt = cms.untracked.vdouble(2.5, 2.5),
#    ParticleID = cms.untracked.vint32(13, -13),
#    Status = cms.untracked.vint32(1, 1)
#)
#
#
#process.generator = cms.EDFilter("Pythia6GeneratorFilter",
#    PythiaParameters = cms.PSet(
#        parameterSets = cms.vstring('pythiaUESettings', 
#            'processParameters'),
#        processParameters = cms.vstring('MSEL=1           ! User defined processes', 
#            'MSTJ(22)=4       ! Decay unstable particles in a cylinder', 
#            'PARJ(73)=1500.   ! max. radius for MSTJ(22)=4', 
#            'PARJ(74)=3000.   ! max. Z for MSTJ(22)=4', 
#            'MDCY(C130,1)=1   ! decay k0-longs', 
#            'MDCY(C211,1)=1   ! decay pions', 
#            'MDCY(C321,1)=1   ! decay kaons'),
#        pythiaUESettings = cms.vstring('MSTJ(11)=3     ! Choice of the fragmentation function', 
#            'MSTJ(22)=2     ! Decay those unstable particles', 
#            'PARJ(71)=10 .  ! for which ctau  10 mm', 
#            'MSTP(2)=1      ! which order running alphaS', 
#            'MSTP(33)=0     ! no K factors in hard cross sections', 
#            'MSTP(51)=10042 ! structure function chosen (external PDF CTEQ6L1)', 
#            'MSTP(52)=2     ! work with LHAPDF', 
#            'MSTP(81)=1     ! multiple parton interactions 1 is Pythia default', 
#            'MSTP(82)=4     ! Defines the multi-parton model', 
#            'MSTU(21)=1     ! Check on possible errors during program execution', 
#            'PARP(82)=1.8387   ! pt cutoff for multiparton interactions', 
#            'PARP(89)=1960. ! sqrts for which PARP82 is set', 
#            'PARP(83)=0.5   ! Multiple interactions: matter distrbn parameter', 
#            'PARP(84)=0.4   ! Multiple interactions: matter distribution parameter', 
#            'PARP(90)=0.16  ! Multiple interactions: rescaling power', 
#            'PARP(67)=2.5    ! amount of initial-state radiation', 
#            'PARP(85)=1.0  ! gluon prod. mechanism in MI', 
#            'PARP(86)=1.0  ! gluon prod. mechanism in MI', 
#            'PARP(62)=1.25   ! ', 
#            'PARP(64)=0.2    ! ', 
#            'MSTP(91)=1      !', 
#            'PARP(91)=2.1   ! kt distribution', 
#            'PARP(93)=15.0  ! ')
#    ),
#    comEnergy = cms.double(10000.0),
#    crossSection = cms.untracked.double(51560000000.0),
#    filterEfficiency = cms.untracked.double(0.002305),
#    maxEventsToPrint = cms.untracked.int32(0),
#    pythiaHepMCVerbosity = cms.untracked.bool(False),
#    pythiaPylistVerbosity = cms.untracked.int32(1)
#)

process.ProductionFilterSequence = cms.Sequence(process.generator+process.oniagenfilter+process.fourmugenfilter+process.genParticles)
#process.ProductionFilterSequence = cms.Sequence(process.generator+process.mugenfilter)

# Path and EndPath definitions
process.generation_step = cms.Path(process.pgen)
process.simulation_step = cms.Path(process.psim)
process.genfiltersummary_step = cms.EndPath(process.genFilterSummary)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.RAWSIMoutput_step = cms.EndPath(process.RAWSIMoutput)

# Schedule definition
process.schedule = cms.Schedule(process.generation_step,process.genfiltersummary_step,process.simulation_step,process.endjob_step,process.RAWSIMoutput_step)
# filter all path with the production filter sequence
for path in process.paths:
	getattr(process,path)._seq = process.ProductionFilterSequence * getattr(process,path)._seq 

# customisation of the process.

# Automatic addition of the customisation function from SLHCUpgradeSimulations.Configuration.postLS1Customs
from SLHCUpgradeSimulations.Configuration.postLS1Customs import customisePostLS1 

#call to customisation function customisePostLS1 imported from SLHCUpgradeSimulations.Configuration.postLS1Customs
process = customisePostLS1(process)

# End of customisation functions

