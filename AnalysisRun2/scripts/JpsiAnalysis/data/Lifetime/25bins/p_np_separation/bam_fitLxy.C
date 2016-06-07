{

	TFile *f = new TFile("Jpsi_Plots.root");

	TH1F *data =(TH1F*)f->Get("t1_data_regionA_dimuon1_lxy");
	TH1F *mc0 = (TH1F*)f->Get("t1_data_np_regionC_dimuon1_lxy");
	TH1F *mc1 = (TH1F*)f->Get("t1_sps_dimuon1_lxy");

	TObjArray *mc = new TObjArray(2);        // MC histograms are put in this array
	mc->Add(mc0);
	mc->Add(mc1);
	TFractionFitter* fit = new TFractionFitter(data, mc); // initialise
	fit->Constrain(1,0.0,1.0);               // constrain fraction 1 to be between 0 and 1
	fit->SetRangeX(1,25);                    // use only the first 100 bins in the fit
	Int_t status = fit->Fit();               // perform the fit
	cout << "fit status: " << status << endl;

	TLegend *leg9 = new TLegend(0.40,0.6,0.80,0.75);
	leg9->SetFillColor(kWhite);
	leg9->SetFillStyle(0);
	leg9->SetBorderSize(0);
	leg9->SetTextFont(42);
	leg9->SetTextSize(0.035);
	leg9->SetMargin(0.13);
	leg9->AddEntry(data,"DATA (Region A)","PL");


	if (status == 0) {                       // check on fit status
		TH1F* result = (TH1F*) fit->GetPlot();

		gStyle->SetOptStat(0);

		leg9->AddEntry(result,"(propmt + non-prompt) J#psi J#psi","FL");
		data->SetTitle("CMS 2015  #sqrt{s} = 13 TeV  L_{int} = 2.65 fb^{-1}");
		data->GetXaxis()->SetTitle("#mu#mu_{1} L_{XY} [cm]");
		data->GetYaxis()->SetTitle("Events/0.04 GeV");

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

		data->GetYaxis()->SetTitleOffset(0.94);

		data->Draw("Ep");
		result->Draw("same");
		leg9->Draw("same");
		txtHeader->Draw("same");
		c->SaveAs("Lxy_fit.png","recreate");
		c->SaveAs("Lxy_fit.C","recreate");
		c->SaveAs("Lxy_fit.pdf","recreate");
	}
}
