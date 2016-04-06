from CRABClient.UserUtilities import config
config = config()

config.section_("General")
config.General.requestName = 'DoubleJPSI_DPS7_4_12_p4_74X_mcRun2_asymptotic_realisticBS_v1_GENSIM_04_BAM_TEST'
config.General.workArea = 'crab_projects'
config.General.transferLogs = True

config.section_("JobType")
config.JobType.pluginName = 'PrivateMC'
config.JobType.psetName = 'InclusiveppMuX_cfi_GEN_SIM_FINAL.py'
config.JobType.outputFiles = ['out_sim.root']

config.section_("Data")
config.Data.splitting = 'EventBased'
config.Data.unitsPerJob = 312000
NJOBS = 10000
config.Data.totalUnits = config.Data.unitsPerJob * NJOBS
#config.Data.outLFNDirBase = '/store/group/alca_muonalign/lpernie/DoubleJPSI_DPS7_4_1_p1_MCRUN2_74_V9_01'
config.Data.outLFNDirBase = '/store/group/lpcdarksusy/'
config.Data.publication = True
config.Data.outputDatasetTag = 'DoubleJPSI_DPS7_4_12_p4_74X_mcRun2_asymptotic_realisticBS_v1_GENSIM_04_BAM_TEST'
config.Data.outputPrimaryDataset = 'DoubleJPSIDPS'

config.section_("Site")
#config.Site.storageSite = 'T2_CH_CERN'
config.Site.storageSite = 'T3_US_FNALLPC'

#https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions15/13TeV/
#https://cmsweb.cern.ch/das/request?view=list&limit=50&instance=prod%2Fglobal&input=dataset%3D%2FDoubleMu*%2FRun2015*-PromptReco-v1%2FAOD

#NJOBS = 1
#config.Data.totalUnits = config.Data.unitsPerJob * NJOBS
