void NMSSM_mH_mA_trigger_efficiency_barrelMuon()
{
//=========Macro generated from canvas: c/c
//=========  (Tue Sep 20 01:03:15 2016) by ROOT version6.02/05
   TCanvas *c = new TCanvas("c", "c",0,0,800,600);
   gStyle->SetOptStat(0);
   c->Range(0.375,0.2499999,6.625,7.75);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetFrameBorderMode(0);
   c->SetFrameBorderMode(0);
   
   TH2F *unnamed = new TH2F("unnamed","HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx efficiency",5,1,6,6,1,7);
   unnamed->SetBinContent(8,0.9766864);
   unnamed->SetBinContent(10,0.9727502);
   unnamed->SetBinContent(11,0.9702859);
   unnamed->SetBinContent(12,0.9650081);
   unnamed->SetBinContent(15,0.978393);
   unnamed->SetBinContent(16,0.9759442);
   unnamed->SetBinContent(17,0.9748966);
   unnamed->SetBinContent(18,0.9706326);
   unnamed->SetBinContent(19,0.9673241);
   unnamed->SetBinContent(22,0.9774819);
   unnamed->SetBinContent(23,0.974151);
   unnamed->SetBinContent(24,0.9734327);
   unnamed->SetBinContent(25,0.9733938);
   unnamed->SetBinContent(26,0.9655517);
   unnamed->SetBinContent(29,0.9758656);
   unnamed->SetBinContent(30,0.9769093);
   unnamed->SetBinContent(31,0.9738486);
   unnamed->SetBinContent(32,0.972883);
   unnamed->SetBinContent(33,0.9695107);
   unnamed->SetBinContent(36,0.9765326);
   unnamed->SetBinContent(37,0.9766657);
   unnamed->SetBinContent(38,0.9739873);
   unnamed->SetBinContent(39,0.97373);
   unnamed->SetBinContent(40,0.9707474);
   unnamed->SetBinContent(43,0.9757761);
   unnamed->SetBinContent(44,0.9759091);
   unnamed->SetBinContent(45,0.9755057);
   unnamed->SetBinContent(46,0.9960099);
   unnamed->SetBinContent(47,0.971271);
   unnamed->SetMinimum(0.9);
   unnamed->SetMaximum(1);
   unnamed->SetEntries(29);
   unnamed->SetStats(0);
   unnamed->SetContour(20);
   unnamed->SetContourLevel(0,0.9);
   unnamed->SetContourLevel(1,0.905);
   unnamed->SetContourLevel(2,0.91);
   unnamed->SetContourLevel(3,0.915);
   unnamed->SetContourLevel(4,0.92);
   unnamed->SetContourLevel(5,0.925);
   unnamed->SetContourLevel(6,0.93);
   unnamed->SetContourLevel(7,0.935);
   unnamed->SetContourLevel(8,0.94);
   unnamed->SetContourLevel(9,0.945);
   unnamed->SetContourLevel(10,0.95);
   unnamed->SetContourLevel(11,0.955);
   unnamed->SetContourLevel(12,0.96);
   unnamed->SetContourLevel(13,0.965);
   unnamed->SetContourLevel(14,0.97);
   unnamed->SetContourLevel(15,0.975);
   unnamed->SetContourLevel(16,0.98);
   unnamed->SetContourLevel(17,0.985);
   unnamed->SetContourLevel(18,0.99);
   unnamed->SetContourLevel(19,0.995);
   
   TPaletteAxis *palette = new TPaletteAxis(6.03125,1,6.3125,7,);
palette->SetLabelColor(1);
palette->SetLabelFont(42);
palette->SetLabelOffset(0.005);
palette->SetLabelSize(0.035);
palette->SetTitleOffset(1);
palette->SetTitleSize(0.035);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#850100");
   palette->SetFillColor(ci);
   palette->SetFillStyle(1001);
   unnamed->GetListOfFunctions()->Add(palette,"br");

   ci = TColor::GetColor("#000099");
   unnamed->SetLineColor(ci);
   unnamed->GetXaxis()->SetTitle("m_{H} [Gev]");
   unnamed->GetXaxis()->SetBinLabel(1,"90");
   unnamed->GetXaxis()->SetBinLabel(2,"100");
   unnamed->GetXaxis()->SetBinLabel(3,"110");
   unnamed->GetXaxis()->SetBinLabel(4,"125");
   unnamed->GetXaxis()->SetBinLabel(5,"150");
   unnamed->GetXaxis()->SetLabelFont(42);
   unnamed->GetXaxis()->SetLabelSize(0.05);
   unnamed->GetXaxis()->SetTitleSize(0.05);
   unnamed->GetXaxis()->SetTitleFont(42);
   unnamed->GetYaxis()->SetTitle("m_{A} [GeV]");
   unnamed->GetYaxis()->SetBinLabel(1,"0.5");
   unnamed->GetYaxis()->SetBinLabel(2,"0.75");
   unnamed->GetYaxis()->SetBinLabel(3,"1.0");
   unnamed->GetYaxis()->SetBinLabel(4,"2.0");
   unnamed->GetYaxis()->SetBinLabel(5,"3.0");
   unnamed->GetYaxis()->SetBinLabel(6,"3.55");
   unnamed->GetYaxis()->SetLabelFont(42);
   unnamed->GetYaxis()->SetLabelSize(0.05);
   unnamed->GetYaxis()->SetTitleSize(0.05);
   unnamed->GetYaxis()->SetTitleFont(42);
   unnamed->GetZaxis()->SetLabelFont(42);
   unnamed->GetZaxis()->SetLabelSize(0.035);
   unnamed->GetZaxis()->SetTitleSize(0.035);
   unnamed->GetZaxis()->SetTitleFont(42);
   unnamed->Draw("COLZ TEXT");
   
   TPaveText *pt = new TPaveText(0.15,0.9341608,0.85,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *AText = pt->AddText("HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx efficiency");
   pt->Draw();
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
