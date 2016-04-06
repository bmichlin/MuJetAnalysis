from CRABClient.UserUtilities import config
config = config()

config.section_("General")
config.General.requestName = 'DoubleJpsi_2015D_7412p4_patTuple_cutana_mujets_Run2015D_v3_v27'
config.General.workArea = 'crab_projects'
config.General.transferLogs = True

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'patTuple_cutana_mujets_73X_cfg.py'
config.JobType.outputFiles = ['out_ana_PF_Jpsi.root']

config.section_("Data")
#config.Data.inputDataset = '/MuOnia/Run2015D-PromptReco-v4/AOD' 
config.Data.inputDataset = '/MuOnia/Run2015D-PromptReco-v3/AOD'  
config.Data.inputDBS = 'global'
config.Data.splitting = 'LumiBased'
config.Data.unitsPerJob = 20
config.Data.lumiMask = 'Cert_246908-260627_13TeV_PromptReco_Collisions15_25ns_JSON_MuonPhys_v2.txt'
config.Data.outLFNDirBase = '/store/user/bmichlin/'
config.Data.publication = True
config.Data.outputDatasetTag = 'DoubleJpsi_2015D_7412p4_patTuple_cutana_mujets_Run2015D_v3_v27'

config.section_("Site")
config.Site.storageSite = 'T3_US_TAMU'

