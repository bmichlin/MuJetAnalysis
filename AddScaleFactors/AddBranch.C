#include <TH1F.h>
#include <TFile.h>
#include <TMath.h>
#include <TCanvas.h>
#include <TH2F.h>
#include <TH1D.h>
#include <THStack.h>
#include <TRandom3.h>
#include <TFormula.h>
#include <TPad.h>
#include <TLegend.h>
#include <TStyle.h>
#include <TROOT.h>
#include <TMarker.h>
#include <TChain.h>
#include <memory>
#include <string>
#include <map>
#include <vector>
#include "TTree.h"
#include "TLatex.h"
#include "TMath.h"
#include "TBranch.h"
#include "TFile.h"
#include "TStyle.h"
#include "TString.h"
#include "TEventList.h"
#include <iostream>
#include <sstream>
#include <fstream>

std::vector<float>  GetId( TH2F* h_ID, float pt, float eta );

void AddBranch() {
   //Get SF
   TFile *f_ID  = new TFile("/afs/cern.ch/work/l/lpernie/H2a4Mu/DisplacedMuonJetAnalysis_2015/CMSSW_7_6_3_patch2/src/MuonID_Z_RunCD_Reco76X_Feb15.root","open");
   TH2F *h_ID   = (TH2F*) f_ID->Get("MC_NUM_LooseID_DEN_genTracks_PAR_pt_spliteta_bin1/abseta_pt_ratio");
   //Signal
   TFile *f = new TFile("out_ana_1.root","update");
   TTree *T = (TTree*)f->Get("cutFlowAnalyzer/Events");
   float pt0, pt1, pt2, pt3;
   float eta0, eta1, eta2, eta3;
   float ScaleF_ID, ScaleF_IDerr;
   TBranch *bScaleF_ID  = T->Branch("ScaleF_ID",&ScaleF_ID,"ScaleF_ID/F");
   TBranch *bScaleF_ISO = T->Branch("ScaleF_IDerr",&ScaleF_IDerr,"ScaleF_IDerr/F");
   T->SetBranchAddress("selMu0_pT",&pt0);
   T->SetBranchAddress("selMu1_pT",&pt1);
   T->SetBranchAddress("selMu2_pT",&pt2);
   T->SetBranchAddress("selMu3_pT",&pt3);
   T->SetBranchAddress("selMu0_eta",&eta0);
   T->SetBranchAddress("selMu1_eta",&eta1);
   T->SetBranchAddress("selMu2_eta",&eta2);
   T->SetBranchAddress("selMu3_eta",&eta3);
   Long64_t nentries = T->GetEntries();
   for (Long64_t i=0;i<nentries;i++) {
      T->GetEntry(i);
      ScaleF_ID     = GetId(h_ID,pt0,eta0)[0] * GetId(h_ID,pt1,eta1)[0] * GetId(h_ID,pt2,eta2)[0] * GetId(h_ID,pt3,eta3)[0];
      bScaleF_IDerr = GetId(h_ID,pt0,eta0)[1] * GetId(h_ID,pt1,eta1)[1] * GetId(h_ID,pt2,eta2)[1] * GetId(h_ID,pt3,eta3)[1];
      bScaleF_ID->Fill();
      bScaleF_IDerr->Fill();
   }
   T->Print();
   f->cd("cutFlowAnalyzer");
   T->Write();
   delete f;
   delete f_ID;
}

std::vector<float> GetId( TH2F* h_ID, float pt, float eta ){
  std::vector<float> result; result.clear();
  if( pt<25 ){
    if( fabs(eta)<0.9 ){
	result.push_back( h_ID->GetBinContent(1,1) );
	result.push_back( h_ID->GetBinError(1,1) );
	return result;
    }
    else if( fabs(eta)<1.2 ){
	result.push_back( h_ID->GetBinContent(2,1) );
	result.push_back( h_ID->GetBinError(2,1) );
	return result;
    }
    else if( fabs(eta)<2.1 ){
	result.push_back( h_ID->GetBinContent(3,1) );
	result.push_back( h_ID->GetBinError(3,1) );
	return result;
    }
    else{
	result.push_back( h_ID->GetBinContent(4,1) );
	result.push_back( h_ID->GetBinError(4,1) );
	return result;
    }
  }
  else if(pt<30 ){
    if( fabs(eta)<0.9 ){
	result.push_back( h_ID->GetBinContent(1,2) );
	result.push_back( h_ID->GetBinError(1,2) );
	return result;
    }
    else if( fabs(eta)<1.2 ){
	result.push_back( h_ID->GetBinContent(2,2) );
	result.push_back( h_ID->GetBinError(2,2) );
	return result;
    }
    else if( fabs(eta)<2.1 ){
	result.push_back( h_ID->GetBinContent(3,2) );
	result.push_back( h_ID->GetBinError(3,2) );
	return result;
    }
    else{
	result.push_back( h_ID->GetBinContent(4,2) );
	result.push_back( h_ID->GetBinError(4,2) );
	return result;
    }
  }
  else if(pt<40 ){
    if( fabs(eta)<0.9 ){
	result.push_back( h_ID->GetBinContent(1,3) );
	result.push_back( h_ID->GetBinError(1,3) );
	return result;
    }
    else if( fabs(eta)<1.2 ){
	result.push_back( h_ID->GetBinContent(2,3) );
	result.push_back( h_ID->GetBinError(2,3) );
	return result;
    }
    else if( fabs(eta)<2.1 ){
	result.push_back( h_ID->GetBinContent(3,3) );
	result.push_back( h_ID->GetBinError(3,3) );
	return result;
    }
    else{
	result.push_back( h_ID->GetBinContent(4,3) );
	result.push_back( h_ID->GetBinError(4,3) );
	return result;
    }
  }
  else if(pt<50 ){
    if( fabs(eta)<0.9 ){
	result.push_back( h_ID->GetBinContent(1,4) );
	result.push_back( h_ID->GetBinError(1,4) );
	return result;
    }
    else if( fabs(eta)<1.2 ){
	result.push_back( h_ID->GetBinContent(2,4) );
	result.push_back( h_ID->GetBinError(2,4) );
	return result;
    }
    else if( fabs(eta)<2.1 ){
	result.push_back( h_ID->GetBinContent(3,4) );
	result.push_back( h_ID->GetBinError(3,4) );
	return result;
    }
    else{
	result.push_back( h_ID->GetBinContent(4,4) );
	result.push_back( h_ID->GetBinError(4,4) );
	return result;
    }
  }
  else if(pt<60 ){
    if( fabs(eta)<0.9 ){
	result.push_back( h_ID->GetBinContent(1,5) );
	result.push_back( h_ID->GetBinError(1,5) );
	return result;
    }
    else if( fabs(eta)<1.2 ){
	result.push_back( h_ID->GetBinContent(2,5) );
	result.push_back( h_ID->GetBinError(2,5) );
	return result;
    }
    else if( fabs(eta)<2.1 ){
	result.push_back( h_ID->GetBinContent(3,5) );
	result.push_back( h_ID->GetBinError(3,5) );
	return result;
    }
    else{
	result.push_back( h_ID->GetBinContent(4,5) );
	result.push_back( h_ID->GetBinError(4,5) );
	return result;
    }
  }
  else{
    if( fabs(eta)<0.9 ){
	result.push_back( h_ID->GetBinContent(1,6) );
	result.push_back( h_ID->GetBinError(1,6) );
	return result;
    }
    else if( fabs(eta)<1.2 ){
	result.push_back( h_ID->GetBinContent(2,6) );
	result.push_back( h_ID->GetBinError(2,6) );
	return result;
    }
    else if( fabs(eta)<2.1 ){
	result.push_back( h_ID->GetBinContent(3,6) );
	result.push_back( h_ID->GetBinError(3,6) );
	return result;
    }
    else{
	result.push_back( h_ID->GetBinContent(4,6) );
	result.push_back( h_ID->GetBinError(4,6) );
	return result;
    }
  }
}
