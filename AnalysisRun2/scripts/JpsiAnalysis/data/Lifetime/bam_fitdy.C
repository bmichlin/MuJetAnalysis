void fit(){
  
  //TFile *f = new TFile("forfitdy.root");

  TH1F *data = (TH1F*)f->Get("t1_data_jpsi_deltay");
  TH1F *mc0 = (TH1F*)f->Get("t1_sps_jpsi_deltay");
  TH1F *mc1 = (TH1F*)f->Get("t1_jpsi_deltay");
  
  TObjArray *mc = new TObjArray(3);        // MC histograms are put in this array
  mc->Add(mc0);
  mc->Add(mc1);
  TFractionFitter* fit = new TFractionFitter(data, mc); // initialise
  fit->Constrain(1,0.0,1.0);               // constrain fraction 1 to be between 0 and 1
  fit->SetRangeX(1,14);                    // use only the first 15 bins in the fit
  Int_t status = fit->Fit();               // perform the fit
  cout << "fit status: " << status << endl;

  TLegend *leg9 = new TLegend(0.40,0.6,0.80,0.75);
  leg9->SetFillColor(kWhite);
  leg9->SetFillStyle(0);
  leg9->SetBorderSize(0);
  leg9->SetTextFont(42);
  leg9->SetTextSize(0.035);
  leg9->SetMargin(0.13);
  leg9->AddEntry(data,"DATA (After subtraction)","PL");


  if (status == 0) {                       // check on fit status
    TH1F* result = (TH1F*) fit->GetPlot();
    leg9->AddEntry(result,"Combined model (DPS+SPS)","FL");
    data->GetXaxis()->SetTitle("|#Delta y|");
    data->GetYaxis()->SetTitle("Events/0.33GeV");

  txtHeader = new TLegend(.93,.935,.1.47,1.);

  txtHeader->SetFillColor(kWhite);
  txtHeader->SetFillStyle(0);
  txtHeader->SetBorderSize(0);
  txtHeader->SetTextFont(42);
  txtHeader->SetTextSize(0.045);
  txtHeader->SetTextAlign(22);
  txtHeader->SetHeader("CMS 2012  #sqrt{s} = 8 TeV  L_{int} = 20.65 fb^{-1}");


    TLine *l1 = new TLine(0.0,0.0,5.0,0.0);
    l1->SetLineStyle(2);

    TCanvas *c = new TCanvas("c");
  c->SetCanvasSize(1000,900);
  c->SetLeftMargin(0.126);
  c->SetRightMargin(0.154);
  c->cd();

  data->GetYaxis()->SetTitleOffset(0.94);



    data->Draw("Ep");
    result->Draw("same");
    leg9->Draw("same");
    l1->Draw("same");
    txtHeader->Draw("same");
    c->SaveAs("dyfit.eps","recreate");
    c->SaveAs("dyfit.pdf","recreate");
  }
}
