from CRABClient.UserUtilities import config
config = config()

config.section_("General")
config.General.requestName = 'SPS_JPSI_CRAB3_412p4_TriggerOptional_PATANA_v1'
config.General.workArea = 'crab_projects'
config.General.transferLogs = True

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'patTuple_cutana_mujets_73X_cfg.py'
#config.JobType.outputFiles = ['out_ana_jpsiTest.root']
config.JobType.outputFiles = ['out_ana_jpsi_dps.root']

config.section_("Data")
config.Data.inputDataset = '/SPS_JPsi_RunII/jrorie-SPS_2JPsi_4mu_13TeV_herwigPP_CMSSW763_batch001_CRAB3_RAW2DIGI_L1Reco_RECO-88bce9c03789200acbcec1ef5d5dc0d3/USER'
config.Data.inputDBS = 'https://cmsweb.cern.ch/dbs/prod/phys03/DBSReader'
#config.Data.splitting = 'FileBased'
#config.Data.unitsPerJob = 20
#NJOBS = 500
#config.Data.outLFNDirBase = '/store/group/lpcdarksusy/'
#config.Data.outLFNDirBase = '/store/user/bmichlin/'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
config.Data.outLFNDirBase = '/store/user/bmichlin/'
config.Data.publication = False
config.Data.outputDatasetTag = 'SPS_JPSI_CRAB3_412p4_TriggerOptional_PATANA_v1'

config.section_("Site")
config.Site.storageSite = 'T3_US_TAMU'

