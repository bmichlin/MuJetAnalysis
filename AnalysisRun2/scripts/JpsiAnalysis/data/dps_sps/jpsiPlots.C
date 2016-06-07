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

TH1F *t1_data_jpsi_DeltaRapidityC             = new TH1F("t1_data_jpsi_DeltaRapidityC", "t1_data_jpsi_DeltaRapidityC", 10, 0, 5);
TH1F *t1_data_jpsi_DeltaRapidityA             = new TH1F("t1_data_jpsi_DeltaRapidityA", "t1_data_jpsi_DeltaRapidityA", 10, 0, 5);

TH1F *t1_sps_jpsi_DeltaRapidity = new TH1F("t1_sps_jpsi_DeltaRapidity", "t1_sps_jpsi_DeltaRapidity", 10, 0, 5);
TH1F *t1_dps_jpsi_DeltaRapidity = new TH1F("t1_dps_jpsi_DeltaRapidity", "t1_dps_jpsi_DeltaRapidity", 10, 0, 5);

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
				if((jpsi_inv_mass_dimuon1 > 3.3 || jpsi_inv_mass_dimuon1 < 2.8 || jpsi_inv_mass_dimuon2 > 3.3 || jpsi_inv_mass_dimuon2 < 2.8)) continue;
				if(type == 2 && (jpsi_isoTk_dimuon1 < 0 || jpsi_isoTk_dimuon2 < 0 || jpsi_isoTk_dimuon1 > 12 || jpsi_isoTk_dimuon2 > 12)) continue; //TODO should this be here?

//{{{
//---Rapidity for DPS/SPS
				double p1 = sqrt(jpsi_px_dimuon1*jpsi_px_dimuon1+jpsi_py_dimuon1*jpsi_py_dimuon1+jpsi_pz_dimuon1*jpsi_pz_dimuon1);
				double p2 = sqrt(jpsi_px_dimuon2*jpsi_px_dimuon2+jpsi_py_dimuon2*jpsi_py_dimuon2+jpsi_pz_dimuon2*jpsi_pz_dimuon2);

				double e1 = sqrt(p1*p1 + jpsi_inv_mass_dimuon1*jpsi_inv_mass_dimuon1);
				double e2 = sqrt(p2*p2 + jpsi_inv_mass_dimuon2*jpsi_inv_mass_dimuon2);

				double num1 = e1 + jpsi_pz_dimuon1;
				double num2 = e2 + jpsi_pz_dimuon2;

				double den1 = e1 - jpsi_pz_dimuon1;
				double den2 = e2 - jpsi_pz_dimuon2;

				double arg1 = num1/den1;
				double arg2 = num2/den2;

				double ln1 = log(arg1);
				double ln2 = log(arg2);

				double y1 = (0.5)*ln1;
				double y2 = (0.5)*ln2;

				double dy = fabs(y1-y2);
				//}}}

				if(type == 0) t1_dps_jpsi_DeltaRapidity->Fill(dy);
				if(type == 1) t1_sps_jpsi_DeltaRapidity->Fill(dy);

				if(jpsi_isoTk_dimuon1 >= 0 && jpsi_isoTk_dimuon2 >= 0 && jpsi_isoTk_dimuon1 <= 2 && jpsi_isoTk_dimuon2 <= 2){ //Region A
					if(type == 0){ t1_dps_regionA_dimuon1_lxy->Fill(jpsi_Lxy_dimuon1); t1_dps_regionA_dimuon2_lxy->Fill(jpsi_Lxy_dimuon2); }
					if(type == 1){ t1_sps_regionA_dimuon1_lxy->Fill(jpsi_Lxy_dimuon1); t1_sps_regionA_dimuon2_lxy->Fill(jpsi_Lxy_dimuon2); }
					if(type == 2){ t1_data_regionA_dimuon1_lxy->Fill(jpsi_Lxy_dimuon1); t1_data_regionA_dimuon2_lxy->Fill(jpsi_Lxy_dimuon2); t1_data_jpsi_DeltaRapidityA->Fill(dy);}
				}
				if(jpsi_isoTk_dimuon1 >= 0 && jpsi_isoTk_dimuon2 >= 0 && jpsi_isoTk_dimuon1 > 2  && jpsi_isoTk_dimuon2 > 2 ){ //Region C
					if(type == 2){ t1_data_np_regionC_dimuon1_lxy->Fill(jpsi_Lxy_dimuon1); t1_data_np_regionC_dimuon2_lxy->Fill(jpsi_Lxy_dimuon2); t1_data_jpsi_DeltaRapidityC->Fill(dy);}
				}
			}
		} // closing for loop
		myfile->Close();
	} // closing while loop
}

void makePlotsPretty(){

	TCanvas *c1 = new TCanvas("c1","c1",700,500);
	//Figure 35 Right
	t1_data_jpsi_DeltaRapidityA->Draw("EP");
	t1_data_jpsi_DeltaRapidityC->Scale(11.0/39.0);
	t1_data_jpsi_DeltaRapidityC->Draw("same");
	t1_data_jpsi_DeltaRapidityA->GetXaxis()->SetTitle("|#Delta y|");
	t1_data_jpsi_DeltaRapidityA->GetYaxis()->SetTitle("Events/0.5 GeV");
	t1_data_jpsi_DeltaRapidityA->SetTitle("CMS 2015  #sqrt{s} = 13 TeV  L_{int} = 2.65 fb^{-1}");
	t1_data_jpsi_DeltaRapidityC->GetXaxis()->SetTitle("|#Delta y|");
	t1_data_jpsi_DeltaRapidityC->GetYaxis()->SetTitle("Events/0.5 GeV");
	t1_data_jpsi_DeltaRapidityC->SetTitle("CMS 2015  #sqrt{s} = 13 TeV  L_{int} = 2.65 fb^{-1}");

	TLegend *leg = new TLegend(0.6203438,0.5957895,0.752149,0.7810526);
	leg->SetBorderSize(0);
	leg->SetFillColor(0);
	leg->SetTextSize(0.045);
	leg->AddEntry(t1_data_jpsi_DeltaRapidityA,"|#Delta y| Reg. A","L");
	leg->AddEntry(t1_data_jpsi_DeltaRapidityC,"|#Delta y| Reg. C (norm)","L");
	leg->Draw("same");

	c1->SaveAs("data_template_rapidity.pdf");
	c1->SaveAs("data_template_rapidity.png");
	c1->SaveAs("data_template_rapidity.C");

	c1->Clear();
	//Figure 36 Right
	t1_data_jpsi_DeltaRapidityA->Add(t1_data_jpsi_DeltaRapidityC,-1);
	t1_sps_jpsi_DeltaRapidity->Scale(11.0/t1_sps_jpsi_DeltaRapidity->Integral());
	t1_dps_jpsi_DeltaRapidity->Scale(11.0/t1_dps_jpsi_DeltaRapidity->Integral());

	t1_data_jpsi_DeltaRapidityA->SetLineColor(kBlack);
	t1_sps_jpsi_DeltaRapidity->SetLineColor(kBlue);
	t1_dps_jpsi_DeltaRapidity->SetLineColor(kRed);
	
	t1_data_jpsi_DeltaRapidityA->Draw("EP");
	t1_sps_jpsi_DeltaRapidity->Draw("same");
	t1_dps_jpsi_DeltaRapidity->Draw("same");

	TLegend *leg2 = new TLegend(0.6203438,0.5957895,0.752149,0.7810526);
	leg2->SetBorderSize(0);
	leg2->SetFillColor(0);
	leg2->SetTextSize(0.045);
	leg2->AddEntry(t1_data_jpsi_DeltaRapidityA,"DATA (After subtraction)","L");
	leg2->AddEntry(t1_sps_jpsi_DeltaRapidity,  "J#psi J#psi MC SPS","L");
	leg2->AddEntry(t1_dps_jpsi_DeltaRapidity,  "J#psi J#psi MC DPS","L");
	leg2->Draw("same");

	c1->SaveAs("norm_data_sps_dps.pdf");
	c1->SaveAs("norm_data_sps_dps.png");
	c1->SaveAs("norm_data_sps_dps.C");

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

