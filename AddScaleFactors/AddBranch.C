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

float GetId( float pt, float eta );
float GetIso( float pt, float eta );

void AddBranch() {
   TFile *f = new TFile("out_ana_1.root","update");
   TTree *T = (TTree*)f->Get("cutFlowAnalyzer/Events");
   float pt0, pt1, pt2, pt3;
   float eta0, eta1, eta2, eta3;
   float ScaleF_ID, ScaleF_ISO;
   TBranch *bScaleF_ID  = T->Branch("ScaleF_ID",&ScaleF_ID,"ScaleF_ID/F");
   TBranch *bScaleF_ISO = T->Branch("ScaleF_ISO",&ScaleF_ISO,"ScaleF_ISO/F");
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
      ScaleF_ID = GetId(pt0,eta0) * GetId(pt1,eta1) * GetId(pt2,eta2) * GetId(pt3,eta3);
      ScaleF_ISO = GetIso(pt0,eta0) * GetIso(pt1,eta1) * GetIso(pt2,eta2) * GetIso(pt3,eta3);
      bScaleF_ID->Fill();
      bScaleF_ISO->Fill();
   }
   T->Print();
   f->cd("cutFlowAnalyzer");
   T->Write();
   delete f;
}

float GetId( float pt, float eta ){
  if( pt<25 ){
    if( fabs(eta)<0.9 ){
	return 0.9862;
    }
    else if( fabs(eta)<1.2 ){
	return 0.9970;
    }
    else if( fabs(eta)<2.1 ){
	return 0.9980;
    }
    else{
	return 0.9934;
    }
  }
  else if(pt<30 ){
    if( fabs(eta)<0.9 ){
	return 0.9934;
    }
    else if( fabs(eta)<1.2 ){
	return 0.9901;
    }
    else if( fabs(eta)<2.1 ){
	return 0.9973;
    }
    else{
	return 0.9924;
    }
  }
  else if(pt<40 ){
    if( fabs(eta)<0.9 ){
	return 0.9979;
    }
    else if( fabs(eta)<1.2 ){
	return 0.9975;
    }
    else if( fabs(eta)<2.1 ){
	return 0.999;
    }
    else{
	return 0.996;
    }
  }
  else if(pt<50 ){
    if( fabs(eta)<0.9 ){
	return 0.998;
    }
    else if( fabs(eta)<1.2 ){
	return 0.9979;
    }
    else if( fabs(eta)<2.1 ){
	return 0.999;
    }
    else{
	return 0.995;
    }
  }
  else if(pt<60 ){
    if( fabs(eta)<0.9 ){
	return 0.9967;
    }
    else if( fabs(eta)<1.2 ){
	return 0.9964;
    }
    else if( fabs(eta)<2.1 ){
	return 0.9968;
    }
    else{
	return 0.9932;
    }
  }
  else{
    if( fabs(eta)<0.9 ){
	return 0.9976;
    }
    else if( fabs(eta)<1.2 ){
	return 0.99756;
    }
    else if( fabs(eta)<2.1 ){
	return 0.998;
    }
    else{
	return 0.9906;
    }
  }
}

float GetIso( float pt, float eta ){
  if( pt<25 ){
    if( fabs(eta)<0.9 ){
	return 1.0042;
    }
    else if( fabs(eta)<1.2 ){
	return 1.0051;
    }
    else if( fabs(eta)<2.1 ){
	return 1.;
    }
    else{
	return 1.006;
    }
  }
  else if(pt<30 ){
    if( fabs(eta)<0.9 ){
	return 0.9979;
    }
    else if( fabs(eta)<1.2 ){
	return 0.9997;
    }
    else if( fabs(eta)<2.1 ){
	return 1.0023;
    }
    else{
	return 0.9988;
    }
  }
  else if(pt<40 ){
    if( fabs(eta)<0.9 ){
	return 1.001;
    }
    else if( fabs(eta)<1.2 ){
	return 1.001;
    }
    else if( fabs(eta)<2.1 ){
	return 1.002;
    }
    else{
	return 0.9994;
    }
  }
  else if(pt<50 ){
    if( fabs(eta)<0.9 ){
	return 0.9996;
    }
    else if( fabs(eta)<1.2 ){
	return 0.9992;
    }
    else if( fabs(eta)<2.1 ){
	return 0.9999;
    }
    else{
	return 0.99949;
    }
  }
  else if(pt<60 ){
    if( fabs(eta)<0.9 ){
	return 1.003;
    }
    else if( fabs(eta)<1.2 ){
	return 0.9997;
    }
    else if( fabs(eta)<2.1 ){
	return 0.9999;
    }
    else{
	return 1.0002;
    }
  }
  else{
    if( fabs(eta)<0.9 ){
	return 0.9993;
    }
    else if( fabs(eta)<1.2 ){
	return 1.;
    }
    else if( fabs(eta)<2.1 ){
	return 1.0005;
    }
    else{
	return 1.001;
    }
  }
}
