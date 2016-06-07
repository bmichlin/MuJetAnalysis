{

	TFile *f = new TFile("Jpsi_Plots.root");

	//TH1F *data_rapC = (TH1F*)f->Get("t1_data_jpsi_DeltaRapidityC");
	TH1F *data_rapA = (TH1F*)f->Get("t1_data_jpsi_DeltaRapidityA");
	//data_rapC->Scale(11.0/39.0);
	//data_rapA->Add(data_rapC,-1);



	//TH1F *data =(TH1F*)f->Get("t1_data_regionA_dimuon1_lxy");
	TH1F *mc0 = (TH1F*)f->Get("t1_sps_jpsi_DeltaRapidity");
	TH1F *mc1 = (TH1F*)f->Get("t1_dps_jpsi_DeltaRapidity");

	TObjArray *mc = new TObjArray(2);        // MC histograms are put in this array
	mc->Add(mc0);
	mc->Add(mc1);
	TFractionFitter* fit = new TFractionFitter(data_rapA, mc); // initialise
	fit->Constrain(1,0.0,1.0);               // constrain fraction 1 to be between 0 and 1
	fit->SetRangeX(1,10);                    // use only the first 100 bins in the fit
	Int_t status = fit->Fit();               // perform the fit
	cout << "fit status: " << status << endl;

	data_rapA->SetLineColor(kBlack);
	mc0->SetLineColor(kGreen);
	mc1->SetLineColor(kBlack);
	TLegend *leg9 = new TLegend(0.40,0.6,0.80,0.75);
	leg9->SetFillColor(kWhite);
	leg9->SetFillStyle(0);
	leg9->SetBorderSize(0);
	leg9->SetTextFont(42);
	leg9->SetTextSize(0.035);
	leg9->SetMargin(0.13);
	leg9->AddEntry(data_rapA,"DATA (After subtraction)","PL");
	//leg9->AddEntry(mc0, "SPS MC (Normalized to Data)");
	//leg9->AddEntry(mc1, "DPS MC (Normalized to Data)");


	if (status == 0) {                       // check on fit status
		TH1F* result = (TH1F*) fit->GetPlot();

		gStyle->SetOptStat(0);

		leg9->AddEntry(result,"Combined model (DPS + SPS)","FL");
		data_rapA->SetTitle("CMS 2015  #sqrt{s} = 13 TeV  L_{int} = 2.65 fb^{-1}");
		data_rapA->GetXaxis()->SetTitle("#mu#mu_{1} L_{XY} [cm]");
		data_rapA->GetYaxis()->SetTitle("Events/0.04 GeV");

		txtHeader = new TLegend(.93,.935,1.47,1.);

		txtHeader->SetFillColor(kWhite);
		txtHeader->SetFillStyle(0);
		txtHeader->SetBorderSize(0);
		txtHeader->SetTextFont(42);
		txtHeader->SetTextSize(0.045);
		txtHeader->SetTextAlign(22);
		//txtHeader->SetHeader("CMS 2015  #sqrt{s} = 13 TeV  L_{int} = 2.65 fb^{-1}");

		TCanvas *c = new TCanvas("c");
		c->SetCanvasSize(1000,900);
		c->SetLeftMargin(0.126);
		c->SetRightMargin(0.154);
		c->cd();

		data_rapA->GetYaxis()->SetTitleOffset(0.94);

//Plot mc0 and mc1 normalized to 11 (number of prompt events in data)
//mc0->Scale(11.0/mc0->Integral());
//mc1->Scale(11.0/mc1->Integral());

		data_rapA->Draw("Ep");
		result->Draw("same");
		leg9->Draw("same");
		//mc0->Draw("same");
		//mc1->Draw("same");
		txtHeader->Draw("same");
		c->SaveAs("Rapidity_fit.png","recreate");
		c->SaveAs("Rapidity_fit.C","recreate");
		c->SaveAs("Rapidity_fit.pdf","recreate");
	}
}
