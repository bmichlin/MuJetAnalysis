#include <iostream>
using namespace std;
#include <algorithm>    // std::max
#include <stdlib.h>
#include <iomanip>
#include "TMath.h"
#include <math.h>
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
#include "TChain.h"
#include "TGraphErrors.h" 
#include "TCollection.h"
#include "TSystemFile.h"
#include "TSystemDirectory.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TChainElement.h" 
#include "TStyle.h"

//============= Global Variables ===========================//
TFile *BAM = new TFile("Jpsi_Plots.root","RECREATE");

//Plot initialization
//{{{

TH1F *t1_data_np_regionC_dimuon1_lxy = new TH1F("t1_data_np_regionC_dimuon1_lxy", "t1_data_np_regionC_dimuon1_lxy", 25, -0.3, 0.7);
TH1F *t1_data_np_regionC_dimuon2_lxy = new TH1F("t1_data_np_regionC_dimuon2_lxy", "t1_data_np_regionC_dimuon2_lxy", 25, -0.3, 0.7);

TH1F *t1_data_regionA_dimuon1_lxy = new TH1F("t1_data_regionA_dimuon1_lxy", "t1_data_regionA_dimuon1_lxy", 25, -0.3, 0.7);
TH1F *t1_data_regionA_dimuon2_lxy = new TH1F("t1_data_regionA_dimuon2_lxy", "t1_data_regionA_dimuon2_lxy", 25, -0.3, 0.7);

TH1F *t1_sps_regionA_dimuon1_lxy = new TH1F("t1_sps_dimuon1_lxy", "t1_sps_dimuon1_lxy", 25, -0.3, 0.7);
TH1F *t1_sps_regionA_dimuon2_lxy = new TH1F("t1_sps_dimuon2_lxy", "t1_sps_dimuon2_lxy", 25, -0.3, 0.7);

TH1F *t1_dps_regionA_dimuon1_lxy = new TH1F("t1_dps_dimuon1_lxy", "t1_dps_dimuon1_lxy", 25, -0.3, 0.7);
TH1F *t1_dps_regionA_dimuon2_lxy = new TH1F("t1_dps_dimuon2_lxy", "t1_dps_dimuon2_lxy", 25, -0.3, 0.7);


//}}}

void addfiles(TChain *ch, const TString dirname=".", const TString ext=".root")
{
	bool verbose(false);
	TSystemDirectory dir(dirname, dirname);
	TList *files = dir.GetListOfFiles();
	if (files) {
		if (verbose) std::cout << "Found files" << std::endl;
		TSystemFile *file;
		TString fname;
		TIter next(files);
		while ((file=(TSystemFile*)next())) {
			fname = file->GetName();
			if (verbose) std::cout << "found fname " << fname << std::endl;
			if (!file->IsDirectory() && fname.BeginsWith(ext)) {
				if (verbose) std::cout << "adding fname " << fname << std::endl;
				ch->Add(fname);
			}
		}
	}
}

void analyze(TString fileName, int type){
	bool verbose(false);
	TString dirname(fileName);
	TChain* chain = new TChain("dummy");
	TString ext("out_ana_");

	// add files to the chain
	addfiles(chain, dirname, ext);

	//Initialize Variables and counters
	//{{{
	Float_t jpsi_event_failure_type;
	Float_t jpsi_inv_mass_dimuon1;
	Float_t jpsi_inv_mass_dimuon2;
	Float_t jpsi_mass_dimuon1;
	Float_t jpsi_mass_dimuon2;
	Float_t jpsi_isoTk_dimuon1;
	Float_t jpsi_isoTk_dimuon2;
	Float_t jpsi_Lxy_dimuon1;
	Float_t jpsi_Lxy_dimuon2;
	Float_t jpsi_L_dimuon1;
	Float_t jpsi_L_dimuon2;
	Float_t jpsi_px_dimuon1;
	Float_t jpsi_px_dimuon2;
	Float_t jpsi_py_dimuon1;
	Float_t jpsi_py_dimuon2;
	Float_t jpsi_pz_dimuon1;
	Float_t jpsi_pz_dimuon2;
	Int_t   jpsi_trigger;
	//}}}

	TObjArray *fileElements=chain->GetListOfFiles();
	TIter next(fileElements);
	TChainElement *chEl=0;

	while ((chEl=(TChainElement*)next())) {
		if (verbose) std::cout << "running on file " << chEl->GetTitle() << std::endl;
		TFile* myfile = new TFile(dirname + chEl->GetTitle());
		if (!myfile) {
			if (verbose) std::cout << "File " << chEl->GetTitle() << " does not exist" << std::endl;
			continue;
		}

		if (verbose) std::cout << "Loading directory cutFlowAnalyzer" << std::endl;
		myfile->cd("cutFlowAnalyzer");

		TTree *t = (TTree*)myfile->Get("cutFlowAnalyzer/Jpsi_Events");
		if (!t) {
			if (verbose) std::cout << "Tree cutFlowAnalyzer/Jpsi_Events does not exist" << std::endl;
			continue;
		}

		if (verbose) cout<<"  Events  "<<t->GetEntries()<<endl;

		//Pull variables from nTuple
		//{{{
		// Event info
		t->SetBranchAddress("jpsi_event_failure_type", &jpsi_event_failure_type);
		t->SetBranchAddress("jpsi_inv_mass_dimuon1", &jpsi_inv_mass_dimuon1);
		t->SetBranchAddress("jpsi_inv_mass_dimuon2", &jpsi_inv_mass_dimuon2);
		t->SetBranchAddress("jpsi_mass_dimuon1", &jpsi_mass_dimuon1);
		t->SetBranchAddress("jpsi_mass_dimuon2", &jpsi_mass_dimuon2);
		t->SetBranchAddress("jpsi_isoTk_dimuon1", &jpsi_isoTk_dimuon1 );
		t->SetBranchAddress("jpsi_isoTk_dimuon2", &jpsi_isoTk_dimuon2 );
		t->SetBranchAddress("jpsi_Lxy_dimuon1", &jpsi_Lxy_dimuon1 );
		t->SetBranchAddress("jpsi_Lxy_dimuon2", &jpsi_Lxy_dimuon2 );
		t->SetBranchAddress("jpsi_L_dimuon1", &jpsi_L_dimuon1 );
		t->SetBranchAddress("jpsi_L_dimuon2", &jpsi_L_dimuon2 );
		t->SetBranchAddress("jpsi_px_dimuon1", &jpsi_px_dimuon1);
		t->SetBranchAddress("jpsi_px_dimuon2", &jpsi_px_dimuon2);
		t->SetBranchAddress("jpsi_py_dimuon1", &jpsi_py_dimuon1);
		t->SetBranchAddress("jpsi_py_dimuon2", &jpsi_py_dimuon2);
		t->SetBranchAddress("jpsi_pz_dimuon1", &jpsi_pz_dimuon1);
		t->SetBranchAddress("jpsi_pz_dimuon2", &jpsi_pz_dimuon2);
		t->SetBranchAddress("jpsi_trigger", &jpsi_trigger );
		//}}}

		for(int k=0;k<t->GetEntries();k++){
			t->GetEntry(k);
			if((type == 1 || type == 0) || (type == 2 && jpsi_trigger == 1)){ //Turn the trigger off for MC

				//Clean data
				if(type == 2 && (jpsi_inv_mass_dimuon1 > 3.3 || jpsi_inv_mass_dimuon1 < 2.8 || jpsi_inv_mass_dimuon2 > 3.3 || jpsi_inv_mass_dimuon2 < 2.8)) continue;
				if(type == 2 && (jpsi_isoTk_dimuon1 < 0 || jpsi_isoTk_dimuon2 < 0 || jpsi_isoTk_dimuon1 > 12 || jpsi_isoTk_dimuon2 > 12)) continue; //TODO should this be here?

				if(jpsi_isoTk_dimuon1 >= 0 && jpsi_isoTk_dimuon2 >= 0 && jpsi_isoTk_dimuon1 <= 2 && jpsi_isoTk_dimuon2 <= 2){ //Region A
					if(type == 0){ t1_dps_regionA_dimuon1_lxy->Fill(jpsi_Lxy_dimuon1); t1_dps_regionA_dimuon2_lxy->Fill(jpsi_Lxy_dimuon2); }
					if(type == 1){ t1_sps_regionA_dimuon1_lxy->Fill(jpsi_Lxy_dimuon1); t1_sps_regionA_dimuon2_lxy->Fill(jpsi_Lxy_dimuon2); }
					if(type == 2){ t1_data_regionA_dimuon1_lxy->Fill(jpsi_Lxy_dimuon1); t1_data_regionA_dimuon2_lxy->Fill(jpsi_Lxy_dimuon2); }
				}
				if(jpsi_isoTk_dimuon1 >= 0 && jpsi_isoTk_dimuon2 >= 0 && jpsi_isoTk_dimuon1 > 2  && jpsi_isoTk_dimuon2 > 2 ){ //Region C
					if(type == 2){ t1_data_np_regionC_dimuon1_lxy->Fill(jpsi_Lxy_dimuon1); t1_data_np_regionC_dimuon2_lxy->Fill(jpsi_Lxy_dimuon2);}
				}
			}
		} // closing for loop
		myfile->Close();
	} // closing while loop
}

void makePlotsPretty(){

	TCanvas *c1 = new TCanvas("c1","c1",700,500);
	t1_data_np_regionC_dimuon1_lxy->DrawNormalized();
	c1->Clear();
	t1_data_np_regionC_dimuon2_lxy->DrawNormalized();
	c1->Clear();

	t1_data_regionA_dimuon1_lxy->DrawNormalized();
	c1->Clear();
	t1_data_regionA_dimuon2_lxy->DrawNormalized();
	c1->Clear();

	t1_sps_regionA_dimuon1_lxy->DrawNormalized();
	c1->Clear();
	t1_sps_regionA_dimuon2_lxy->DrawNormalized();
	c1->Clear();

	t1_dps_regionA_dimuon1_lxy->DrawNormalized();
	c1->Clear();
	t1_dps_regionA_dimuon2_lxy->DrawNormalized();
	c1->Clear();
}


void jpsiPlots()
{
	cout << "Begin plotting Jpsi" << endl;
	analyze("/fdata/hepx/store/user/bmichlin/DPS_Jpsi/", 0); //DPS MC
	analyze("/fdata/hepx/store/user/bmichlin/SPS_SLURM_v1/", 1); //SPS MC
    analyze("/fdata/hepx/store/user/bmichlin/MuOnia/DoubleJpsi_2015D_7412p4_patTuple_cutana_mujets_Run2015D_v3_v27/160316_215529/0000/", 2); //Data
	analyze("/fdata/hepx/store/user/bmichlin/MuOnia/DoubleJpsi_2015D_7412p4_patTuple_cutana_mujets_Run2015D_v4_v27/160316_215441/0000/", 2); //Data
	analyze("/fdata/hepx/store/user/bmichlin/MuOnia/DoubleJpsi_2015D_7412p4_patTuple_cutana_mujets_Run2015D_v4_v27/160316_215441/0001/", 2); //Data
	makePlotsPretty();
	BAM->Write();
}

