from CRABClient.UserUtilities import config
config = config()

config.section_("General")
config.General.requestName = 'DPS_JPSI_CRAB3_412p4_TriggerOptional_PATANA_v27'
config.General.workArea = 'crab_projects'
config.General.transferLogs = True

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'patTuple_cutana_mujets_73X_cfg.py'
#config.JobType.outputFiles = ['out_ana_jpsiTest.root']
config.JobType.outputFiles = ['out_ana_jpsi_dps.root']

config.section_("Data")
config.Data.inputDataset = '/DoubleJPSIDPS/lpernie-DoubleJPSI_DPS7_4_12_p4_74X_mcRun2_asymptotic_realisticBS_v1_RECO_01-0faf8b54196debb742209d4c523ceb35/USER'
config.Data.inputDBS = 'https://cmsweb.cern.ch/dbs/prod/phys03/DBSReader'
#config.Data.splitting = 'FileBased'
#config.Data.unitsPerJob = 20
#NJOBS = 500
#config.Data.outLFNDirBase = '/store/group/lpcdarksusy/'
#config.Data.outLFNDirBase = '/store/user/bmichlin/'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 10
config.Data.outLFNDirBase = '/store/user/bmichlin/'
config.Data.publication = False
config.Data.outputDatasetTag = 'DPS_JPSI_CRAB3_412p4_TriggerOptional_PATANA_v27'

config.section_("Site")
config.Site.storageSite = 'T3_US_TAMU'

