void e_hlt_vs_cT.test()
{
//=========Macro generated from canvas: c/c
//=========  (Mon Jan 25 13:59:20 2016) by ROOT version6.02/05
   TCanvas *c = new TCanvas("c", "c",0,52,700,500);
   gStyle->SetOptStat(0);
   c->Range(-2.75,-0.125,22.75,1.125);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetFrameBorderMode(0);
   c->SetFrameBorderMode(0);
   
   TH2F *1 = new TH2F("1","",400,-0.2,20.2,100,0,1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   1->SetLineColor(ci);
   1->GetXaxis()->SetTitle("c#tau [mm]");
   1->GetXaxis()->SetLabelFont(42);
   1->GetXaxis()->SetLabelSize(0.035);
   1->GetXaxis()->SetTitleSize(0.035);
   1->GetXaxis()->SetTitleFont(42);
   1->GetYaxis()->SetTitle("HLT efficiency");
   1->GetYaxis()->SetLabelFont(42);
   1->GetYaxis()->SetLabelSize(0.035);
   1->GetYaxis()->SetTitleSize(0.035);
   1->GetYaxis()->SetTitleFont(42);
   1->GetZaxis()->SetLabelFont(42);
   1->GetZaxis()->SetLabelSize(0.035);
   1->GetZaxis()->SetTitleSize(0.035);
   1->GetZaxis()->SetTitleFont(42);
   1->Draw("");
   
   Double_t Graph0_fx1001[25] = {
   0,
   0,
   0.05,
   0.05,
   0.1,
   0.1,
   0.2,
   0.2,
   0.5,
   0.5,
   1,
   1,
   2,
   2,
   3,
   3,
   5,
   10,
   10,
   10,
   10,
   20,
   20,
   20,
   20};
   Double_t Graph0_fy1001[25] = {
   0.9689701,
   0.9673017,
   0.9651198,
   0.9627853,
   0.9695636,
   0.9623268,
   0.9626421,
   0.9666951,
   0.9589958,
   0.9574803,
   0.9542334,
   0.9635036,
   1,
   0.9259259,
   1,
   0.9508197,
   0.9473684,
   1,
   0.8571429,
   1,
   1,
   1,
   1,
   1,
   1};
   Double_t Graph0_fex1001[25] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph0_fey1001[25] = {
   0.002572328,
   0.002120521,
   0.002259465,
   0.002434377,
   0.00237675,
   0.002660208,
   0.003120147,
   0.003027328,
   0.005736388,
   0.005661846,
   0.009996797,
   0.009249761,
   0,
   0.02254002,
   0,
   0.02768725,
   0.05122782,
   0,
   0.13226,
   0,
   0,
   0,
   0,
   0,
   0};
   TGraphErrors *gre = new TGraphErrors(25,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","Graph",100,0,22);
   Graph_Graph1001->SetMinimum(0.6973711);
   Graph_Graph1001->SetMaximum(1.027512);
   Graph_Graph1001->SetDirectory(0);
   Graph_Graph1001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1001->SetLineColor(ci);
   Graph_Graph1001->GetXaxis()->SetLabelFont(42);
   Graph_Graph1001->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1001->GetXaxis()->SetTitleFont(42);
   Graph_Graph1001->GetYaxis()->SetLabelFont(42);
   Graph_Graph1001->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1001->GetYaxis()->SetTitleFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1001);
   
   gre->Draw(" pl");
   
   Double_t Graph1_fx1002[17] = {
   0,
   0,
   0.05,
   0.05,
   0.1,
   0.1,
   0.2,
   0.2,
   0.5,
   0.5,
   1,
   1,
   2,
   2,
   3,
   5,
   5};
   Double_t Graph1_fy1002[17] = {
   0.9730921,
   0.9759487,
   0.9718819,
   0.9728618,
   0.970061,
   0.967966,
   0.9679505,
   0.9642338,
   0.9584665,
   0.9563286,
   0.962578,
   0.9390244,
   0.9677419,
   0.9452055,
   0.975,
   1,
   0.8928571};
   Double_t Graph1_fex1002[17] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph1_fey1002[17] = {
   0.002029829,
   0.003541979,
   0.00207189,
   0.004659604,
   0.002353351,
   0.00244617,
   0.002953216,
   0.003166734,
   0.01127758,
   0.005559993,
   0.008653845,
   0.02642467,
   0.01832135,
   0.01883455,
   0.02468552,
   0,
   0.05845122};
   gre = new TGraphErrors(17,Graph1_fx1002,Graph1_fy1002,Graph1_fex1002,Graph1_fey1002);
   gre->SetName("Graph1");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(2);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1002 = new TH1F("Graph_Graph1002","Graph",100,0,5.5);
   Graph_Graph1002->SetMinimum(0.8178465);
   Graph_Graph1002->SetMaximum(1.016559);
   Graph_Graph1002->SetDirectory(0);
   Graph_Graph1002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1002->SetLineColor(ci);
   Graph_Graph1002->GetXaxis()->SetLabelFont(42);
   Graph_Graph1002->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1002->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1002->GetXaxis()->SetTitleFont(42);
   Graph_Graph1002->GetYaxis()->SetLabelFont(42);
   Graph_Graph1002->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1002->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1002->GetYaxis()->SetTitleFont(42);
   Graph_Graph1002->GetZaxis()->SetLabelFont(42);
   Graph_Graph1002->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1002->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1002->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1002);
   
   gre->Draw(" pl");
   
   Double_t Graph2_fx1003[0] = {
