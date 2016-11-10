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
#include "TSystemFile.h"
#include "TSystemDirectory.h"
#include "TChainElement.h"
#include "/home/bmichlin/JpsiEstimation/CMSSW_7_4_12_patch4/src/MuJetAnalysis/AnalysisRun2/scripts/Helpers.h"

std::vector<float>  GetId( TH2F* h_ID, float pt, float eta );

TString mass_string;
TString cT_string;
TString fileName;

std::map<TString, TString > mass_strings = {
	{"0250", "0.25"}, {"0275", "0.275"}, {"0300","0.3"}, {"0400", "0.4"}, {"0700", "0.7"},
	{"1000", "1.0"}, {"1500", "1.5"}, {"2000", "2.0"}, {"8500", "8.5"}
};
std::map<TString, double > cT_strings = {
	{"000_",0.0}, {"005_", 0.05}, {"010_", 0.10}, {"020_", 0.20}, {"050_", 0.50}, {"100_", 1.00},
	{"200_", 2.00}, {"300_", 3.00}, {"500_", 5.00}, {"1000", 10.0}, {"2000", 20.0}, {"8500", 85.0}
};

void AddSFBranch(const std::vector<std::string>& dirNames) {
	bool verbose(false);
	//Get SF
	TFile *f_ID  = new TFile("/fdata/hepx/store/user/bmichlin/AddScaleFactors/MuonID_Z_RunCD_Reco76X_Feb15.root","open");
	TH2F *h_ID   = (TH2F*) f_ID->Get("MC_NUM_LooseID_DEN_genTracks_PAR_pt_spliteta_bin1/abseta_pt_ratio");
	//Signal

	////----
	TChain* chain = new TChain("dummy");
	TString ext("out_ana_");
	decodeFileNameMany(dirNames, mass_string, cT_string);
	fileName = "DarkSUSY_mH_125_mGammaD_" + mass_string + "_cT_" + cT_string;
	// add files to the chain
	addfilesMany(chain, dirNames, ext);

	//Initialize Variables
	//{{{
	Float_t pt0, pt1, pt2, pt3;
	Float_t eta0, eta1, eta2, eta3;
	Float_t ScaleF_ID, ScaleF_IDerr;
	//}}}

	TObjArray *fileElements=chain->GetListOfFiles();
	TIter next(fileElements);
	TChainElement *chEl=0;

	while ((chEl=(TChainElement*)next())) {
		if (verbose) std::cout << "running on file " << chEl->GetTitle() << std::endl;
		TFile* myfile = new TFile(chEl->GetTitle());
		if (!myfile) {
			if (verbose) std::cout << "File " << chEl->GetTitle() << " does not exist" << std::endl;
			continue;
		}

		if (verbose) std::cout << "Loading directory cutFlowAnalyzerPXBL3PXFL2" << std::endl;
		myfile->cd("cutFlowAnalyzerPXBL3PXFL2");

		TTree *t = (TTree*)myfile->Get("cutFlowAnalyzerPXBL3PXFL2/Events");
		if (!t) {
			if (verbose) std::cout << "Tree cutFlowAnalyzerPXBL3PXFL2/Events does not exist" << std::endl;
			continue;
		}

		//Pull variables from nTuple
		//{{{
		t->SetBranchAddress("selMu0_pT",&pt0);
		t->SetBranchAddress("selMu1_pT",&pt1);
		t->SetBranchAddress("selMu2_pT",&pt2);
		t->SetBranchAddress("selMu3_pT",&pt3);

		t->SetBranchAddress("selMu0_eta",&eta0);
		t->SetBranchAddress("selMu1_eta",&eta1);
		t->SetBranchAddress("selMu2_eta",&eta2);
		t->SetBranchAddress("selMu3_eta",&eta3);

		TBranch *bScaleF_ID  = t->Branch("ScaleF_ID",&ScaleF_ID,"ScaleF_ID/F");
		TBranch *bScaleF_IDerr = t->Branch("ScaleF_IDerr",&ScaleF_IDerr,"ScaleF_IDerr/F");
		//}}}


		////----

		//TFile *f = new TFile("out_ana_1.root","update");
		//TTree *T = (TTree*)f->Get("cutFlowAnalyzer/Events");
		//float pt0, pt1, pt2, pt3;
		//float eta0, eta1, eta2, eta3;
		//float ScaleF_ID, ScaleF_IDerr;
		//TBranch *bScaleF_ID  = T->Branch("ScaleF_ID",&ScaleF_ID,"ScaleF_ID/F");
		//TBranch *bScaleF_ISO = T->Branch("ScaleF_IDerr",&ScaleF_IDerr,"ScaleF_IDerr/F");
		/*
		   T->SetBranchAddress("selMu0_pT",&pt0);
		   T->SetBranchAddress("selMu1_pT",&pt1);
		   T->SetBranchAddress("selMu2_pT",&pt2);
		   T->SetBranchAddress("selMu3_pT",&pt3);
		   T->SetBranchAddress("selMu0_eta",&eta0);
		   T->SetBranchAddress("selMu1_eta",&eta1);
		   T->SetBranchAddress("selMu2_eta",&eta2);
		   T->SetBranchAddress("selMu3_eta",&eta3);
		   */
		Long64_t nentries = t->GetEntries();
		for (Long64_t i=0;i<nentries;i++) {
			t->GetEntry(i);
			ScaleF_ID     = GetId(h_ID,pt0,eta0)[0] * GetId(h_ID,pt1,eta1)[0] * GetId(h_ID,pt2,eta2)[0] * GetId(h_ID,pt3,eta3)[0];
			ScaleF_IDerr  = GetId(h_ID,pt0,eta0)[1] * GetId(h_ID,pt1,eta1)[1] * GetId(h_ID,pt2,eta2)[1] * GetId(h_ID,pt3,eta3)[1];
			bScaleF_ID->Fill();
			bScaleF_IDerr->Fill();
		}
		t->Print();
		cout << "File has been printed" << endl;
		myfile->cd("cutFlowAnalyzerPXBL3PXFL2");
		cout << "cd director" << endl;
		t->Write();
		cout << "writing new branches" << endl;
		delete myfile;
		cout << "File deleted" << endl;
		delete f_ID;
		cout << "histo deleted" << endl;
		//myfile->Close();
	}//while loop
	cout << "while loop completes" << endl;
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

void AddBranch(){
cout << "Begin adding SF branches" << endl;
	std::vector< std::vector<string> > DarkSUSY_mH_125_mGammaD_v;
	cout << "Vector initialized" << endl;
	//readTextFileWithSamples("/fdata/hepx/store/user/bmichlin/FullSampleList_InclHighCT.txt", DarkSUSY_mH_125_mGammaD_v); //To run over EVERY sample
	readTextFileWithSamples("/fdata/hepx/store/user/bmichlin/singlefile.txt", DarkSUSY_mH_125_mGammaD_v); //Run over a single file (mGammaD_0250_cT_000_Evt_79k) for testing purposes
	cout << "Text file read" << endl;
	for(auto v: DarkSUSY_mH_125_mGammaD_v) AddSFBranch(v);
	cout << "file-for loop completes" << endl;
}

