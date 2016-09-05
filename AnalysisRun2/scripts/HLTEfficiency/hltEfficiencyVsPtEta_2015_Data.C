#include <iostream>
using namespace std;
#include <algorithm>    // std::max
#include "../Helpers.h"
#include <cstdlib>

TString fileName;

bool trigger_fired(std::string t, const std::vector<std::string>* v)
{
  auto vv = *v;
  return std::find(vv.begin(), vv.end(), t) != vv.end();
}

void efficiency_trigger(const std::vector<std::string>& dirNames, int layers = 1)
{
  bool verbose(true);
  TChain* chain = new TChain("dummy");
  TString ext("out_ana_");

  fileName = "DoubleMuon_2015_PromptReco_v2";
  cout << "Tag name " << fileName << endl;

  cout << "Preparing histograms" << endl;
  TH1D* RECO_leading_pt_fid = new TH1D("RECO_leading_pt_fid" + fileName,"",10,0.,50.);
  TH1D* hlt_RECO_leading_pt_fid = new TH1D("hlt_RECO_leading_pt_fid" + fileName,"",10,0.,50.);
  TH1D* backup_hlt_RECO_leading_pt_fid = new TH1D("backup_hlt_RECO_leading_pt_fid" + fileName,"",10,0.,50.);

  TH1D* RECO_leading_eta_fid = new TH1D("RECO_leading_eta_fid" + fileName,"",5,-2.5,2.5);
  TH1D* hlt_RECO_leading_eta_fid = new TH1D("hlt_RECO_leading_eta_fid" + fileName,"",5,-2.5,2.5);
  TH1D* backup_hlt_RECO_leading_eta_fid = new TH1D("backup_hlt_RECO_leading_eta_fid" + fileName,"",5,-2.5,2.5);

  TH1D* RECO_leading_phi_fid = new TH1D("RECO_leading_phi_fid" + fileName,"",6,-TMath::Pi(),TMath::Pi());
  TH1D* hlt_RECO_leading_phi_fid = new TH1D("hlt_RECO_leading_phi_fid" + fileName,"",6,-TMath::Pi(),TMath::Pi());
  TH1D* backup_hlt_RECO_leading_phi_fid = new TH1D("backup_hlt_RECO_leading_phi_fid" + fileName,"",6,-TMath::Pi(),TMath::Pi());

  // add files to the chain
  addfilesMany(chain, dirNames, ext);

  Int_t event;
  Int_t run;
  Int_t lumi;

  Int_t nRecoMu;
  
  Float_t selMu0_pT;
  Float_t selMu1_pT;
  Float_t selMu2_pT;
  Float_t selMu3_pT;

  Float_t selMu0_eta;
  Float_t selMu1_eta;
  Float_t selMu2_eta;
  Float_t selMu3_eta;

  Float_t selMu0_phi;
  Float_t selMu1_phi;
  Float_t selMu2_phi;
  Float_t selMu3_phi;

  Bool_t is1SelMu17;
  Bool_t is2SelMu8;
  Bool_t is3SelMu8;
  Bool_t is4SelMu8;

  Bool_t isDiMuonHLTFired;

  std::vector<std::string> *hltPaths = 0;
  
  //============= Counters ===========================//

  Int_t ev_isDiMuonHLTFired = 0;

  TObjArray *fileElements=chain->GetListOfFiles();
  TIter next(fileElements);
  TChainElement *chEl=0;

  while ((chEl=(TChainElement*)next())) {
    if (verbose) std::cout << "running on file " << chEl->GetTitle() << std::endl;
    TFile* myfile = new TFile(chEl->GetTitle()); //dirname  +
    if (!myfile) {
      if (verbose) std::cout << "File " << chEl->GetTitle() << " does not exist" << std::endl;
      continue;
    }

    TString analyzer = "cutFlowAnalyzer";
    if (verbose) std::cout << "Loading directory " << analyzer << std::endl;
    myfile->cd(analyzer);

    TTree *t = (TTree*)myfile->Get(analyzer + "/Events");
    if (!t) {
      if (verbose) std::cout << "Tree " + analyzer + "/Events does not exist" << std::endl;
      continue;
    }

    if (verbose) cout<<"  Events  "<<t->GetEntries()<<endl;

    // Event info
    t->SetBranchAddress("event", &event);
    t->SetBranchAddress("run",   &run);
    t->SetBranchAddress("lumi",  &lumi);

    // RECO Level Selectors
    t->SetBranchAddress("nRecoMu",  &nRecoMu);

    t->SetBranchAddress("selMu0_pT",    &selMu0_pT);
    t->SetBranchAddress("selMu1_pT",    &selMu1_pT);
    t->SetBranchAddress("selMu2_pT",    &selMu2_pT);
    t->SetBranchAddress("selMu3_pT",    &selMu3_pT);

    t->SetBranchAddress("selMu0_eta",    &selMu0_eta);
    t->SetBranchAddress("selMu1_eta",    &selMu1_eta);
    t->SetBranchAddress("selMu2_eta",    &selMu2_eta);
    t->SetBranchAddress("selMu3_eta",    &selMu3_eta);

    t->SetBranchAddress("selMu0_phi",    &selMu0_phi);
    t->SetBranchAddress("selMu1_phi",    &selMu1_phi);
    t->SetBranchAddress("selMu2_phi",    &selMu2_phi);
    t->SetBranchAddress("selMu3_phi",    &selMu3_phi);

    t->SetBranchAddress("is1SelMu17",                     &is1SelMu17);
    t->SetBranchAddress("is2SelMu8",                      &is2SelMu8);
    t->SetBranchAddress("is3SelMu8",                      &is3SelMu8);
    t->SetBranchAddress("is4SelMu8",                      &is4SelMu8);

    t->SetBranchAddress("isDiMuonHLTFired",               &isDiMuonHLTFired);

    t->SetBranchAddress("hltPaths", &hltPaths);
    
    for(int k=0; k<t->GetEntries(); k++) {
      t->GetEntry(k);
      
      if (nRecoMu<4) continue;

      cout << "number of paths " << hltPaths->size() << endl;
      for (auto i: *hltPaths)
	cout << i << ' ' << endl;
      cout << endl;

      Int_t nSelMuPtLow = 0;
      Int_t nSelMuPtHigh = 0;
      
      double minPtLow = 8;
      double minPtHigh = 17;

      if (selMu0_pT>=minPtLow) nSelMuPtLow++;
      if (selMu1_pT>=minPtLow) nSelMuPtLow++;
      if (selMu2_pT>=minPtLow) nSelMuPtLow++;
      if (selMu3_pT>=minPtLow) nSelMuPtLow++;
      
      if (selMu0_pT>=minPtHigh) nSelMuPtHigh++;
      if (selMu1_pT>=minPtHigh) nSelMuPtHigh++;
      if (selMu2_pT>=minPtHigh) nSelMuPtHigh++;
      if (selMu3_pT>=minPtHigh) nSelMuPtHigh++;

      if (nSelMuPtLow>=4 and nSelMuPtHigh>=1){
	if (verbose) {
	  cout << selMu0_pT << " "
	       << selMu1_pT << " "
	       << selMu2_pT << " "
	       << selMu3_pT << " " << endl;
	  
	  cout << selMu0_eta << " "
	       << selMu1_eta << " "
	       << selMu2_eta << " "
	       << selMu3_eta << " " << endl;
	  
	  cout << selMu0_phi << " "
	       << selMu1_phi << " "
	       << selMu2_phi << " "
	       << selMu3_phi << " " << endl;
	  
	  cout << "OK denom" << endl;
	}
	RECO_leading_pt_fid->Fill(selMu0_pT);
	RECO_leading_eta_fid->Fill(selMu0_eta);
	RECO_leading_phi_fid->Fill(selMu0_phi);

	if (trigger_fired("HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx_v2", hltPaths)){
	  if (verbose) cout << "\tOK num" <<endl;
	  hlt_RECO_leading_pt_fid->Fill(selMu0_pT);
	  hlt_RECO_leading_eta_fid->Fill(selMu0_eta);
	  hlt_RECO_leading_phi_fid->Fill(selMu0_phi);
	}
      }
      if (verbose) cout << endl;

    } // closing for loop
    myfile->Close();
  } // closing while loop
  
  // TEfficiency objects
  TEfficiency* eff_hlt_RECO_leading_pt_fid = new TEfficiency(*hlt_RECO_leading_pt_fid, *RECO_leading_pt_fid);
  TEfficiency* eff_hlt_RECO_leading_eta_fid = new TEfficiency(*hlt_RECO_leading_eta_fid, *RECO_leading_eta_fid);
  TEfficiency* eff_hlt_RECO_leading_phi_fid = new TEfficiency(*hlt_RECO_leading_phi_fid, *RECO_leading_phi_fid);
  
  enum Variable{Pt=0,Eta=1,Phi=3};

  // Plots
  struct MyEfficiencyPlot
  {
    static void plot(enum Variable v, TEfficiency* eff, TString cTitle) { 

      TCanvas *c = new TCanvas("c","c",700,500);
      gStyle->SetOptStat(0);
      
      double xMin;
      double xMax;
      int xBin = 50;
      TString xTitle;
      TString yTitle = "HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx efficiency";
      TString title;

      if (v==Variable::Pt){
	xMin = 0;
	xMax = 50;
	xTitle = "Leading muon p_{T} [GeV]";
	title = "leading muon p_{T}";
      }
      else if (v==Variable::Eta){
	xMin = -2.5;
	xMax = 2.5;
	xTitle ="Leading muon #eta";
	title = "leading muon #eta";
      }
      else if (v==Variable::Phi){
	xMin = -TMath::Pi();
	xMax = TMath::Pi();
	xBin = 60;
	xTitle ="Leading muon #phi";
	title = "leading muon #phi";
      }
      
      TH1F *base = new TH1F("","Trigger efficiency on 2015 data", xBin, xMin, xMax);
      base->GetXaxis()->SetTitle(xTitle);
      base->GetYaxis()->SetTitle(yTitle);
      base->Draw();
      
      eff->SetLineWidth(1);
      eff->SetMarkerSize(5);
      eff->SetLineColor(kBlue);
      eff->SetMarkerColor(kBlue);
      eff->SetMarkerStyle(7);
      eff->Draw("same");

      TLegend *leg = new TLegend(0.15,0.15,0.85,0.45);
      leg->SetBorderSize(0);
      leg->SetFillColor(0);
      leg->SetTextSize(0.045);
      leg->AddEntry(eff,"Data", "PL");
      // leg->Draw("same");

      c->SaveAs(TString("trigger_efficiency_plots_pt_eta_phi/" + cTitle + "_" + fileName + ".png"),"recreate");
      c->Clear();
    }
  };

  // MyEfficiencyPlot::plot(Variable::Pt,  eff_hlt_leading_pt_fid, "eff_hlt_vs_leading_pT_L" + std::to_string(layers));
  // MyEfficiencyPlot::plot(Variable::Eta, eff_hlt_leading_eta_fid, "eff_hlt_vs_leading_eta_L" + std::to_string(layers));
  // MyEfficiencyPlot::plot(Variable::Phi, eff_hlt_leading_phi_fid, "eff_hlt_vs_leading_phi_L" + std::to_string(layers));
  MyEfficiencyPlot::plot(Variable::Pt,  eff_hlt_RECO_leading_pt_fid, "eff_hlt_RECO_vs_leading_pT");
  MyEfficiencyPlot::plot(Variable::Eta, eff_hlt_RECO_leading_eta_fid, "eff_hlt_RECO_vs_leading_eta");
  MyEfficiencyPlot::plot(Variable::Phi, eff_hlt_RECO_leading_phi_fid, "eff_hlt_RECO_vs_leading_phi");
}

void hltEfficiencyVsPtEta_2015_Data()
{
  std::vector<string> input_data;
  input_data.push_back("/fdata/hepx/store/user/lpernie/DoubleMuon//DoubleMuon_2015Dv1noPrompt_AOD_260373_260534_7412p4_p1_patTuple_cutana_mujets_18/160527_210126/0000/");
  input_data.push_back("/fdata/hepx/store/user/lpernie/DoubleMuon//DoubleMuon_2015Dv1noPrompt_AOD_260373_260534_7412p4_p1_patTuple_cutana_mujets_18/160527_210126/0001/");
  input_data.push_back("/fdata/hepx/store/user/lpernie/DoubleMuon//DoubleMuon_2015Dv1noPrompt_AOD_260373_260534_7412p4_p1_patTuple_cutana_mujets_18/160527_210126/0002/");
  input_data.push_back("/fdata/hepx/store/user/lpernie/DoubleMuon//DoubleMuon_2015Dv1noPrompt_AOD_260373_260534_7412p4_p1_patTuple_cutana_mujets_18/160527_210126/0003/");
  input_data.push_back("/fdata/hepx/store/user/lpernie/DoubleMuon//DoubleMuon_2015Dv1noPrompt_AOD_260373_260534_7412p4_p1_patTuple_cutana_mujets_18/160527_210126/0004/");
  input_data.push_back("/fdata/hepx/store/user/lpernie/DoubleMuon//DoubleMuon_2015Dv1noPrompt_AOD_260373_260534_7412p4_p1_patTuple_cutana_mujets_18/160527_210126/0005/");
  input_data.push_back("/fdata/hepx/store/user/lpernie/DoubleMuon//DoubleMuon_2015Dv1noPrompt_AOD_260373_260534_7412p4_p1_patTuple_cutana_mujets_18/160527_210126/0006/");
  input_data.push_back("/fdata/hepx/store/user/lpernie/DoubleMuon//DoubleMuon_2015Dv1noPrompt_AOD_260373_260534_7412p4_p1_patTuple_cutana_mujets_18/160527_210126/0007/");
  input_data.push_back("/fdata/hepx/store/user/lpernie/DoubleMuon//DoubleMuon_2015Dv1noPrompt_AOD_260373_260534_7412p4_p1_patTuple_cutana_mujets_18/160527_210126/0008/");

  efficiency_trigger(input_data);
}

