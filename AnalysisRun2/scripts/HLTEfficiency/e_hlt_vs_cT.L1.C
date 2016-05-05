void e_hlt_vs_cT.L1()
{
//=========Macro generated from canvas: c/c
//=========  (Mon Jan 25 21:56:49 2016) by ROOT version6.02/05
   TCanvas *c = new TCanvas("c", "c",0,52,700,500);
   gStyle->SetOptStat(0);
   c->Range(-2.75,0.775,22.75,1.025);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetFrameBorderMode(0);
   c->SetFrameBorderMode(0);
   
   TH2F *1 = new TH2F("1","",400,-0.2,20.2,100,0.8,1);
   1->SetStats(0);

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
   
   Double_t Graph0_fx1001[11] = {
   0,
   0.05,
   0.1,
   0.2,
   0.5,
   1,
   2,
   3,
   5,
   10,
   20};
   Double_t Graph0_fy1001[11] = {
   0.978355,
   0.9688889,
   0.950495,
   0.9631902,
   0.8969072,
   0.9285714,
   0.9333333,
   0.7777778,
   1,
   1,
   1};
   Double_t Graph0_fex1001[11] = {
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
   Double_t Graph0_fey1001[11] = {
   0.009574614,
   0.01157453,
   0.01526243,
   0.01474837,
   0.03087465,
   0.03973919,
   0.06440612,
   0.1385799,
   0,
   0,
   0};
   TGraphErrors *gre = new TGraphErrors(11,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#ff0000");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","Graph",100,0,22);
   Graph_Graph1001->SetMinimum(0.6031177);
   Graph_Graph1001->SetMaximum(1.03608);
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
   
   Double_t Graph1_fx1002[9] = {
   0,
   0.05,
   0.1,
   0.2,
   0.5,
   1,
   2,
   3,
   5};
   Double_t Graph1_fy1002[9] = {
   0.9637883,
   0.9543147,
   0.962406,
   0.9710744,
   0.9754601,
   0.987013,
   1,
   0.8,
   1};
   Double_t Graph1_fex1002[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph1_fey1002[9] = {
   0.009859799,
   0.01051928,
   0.008246744,
   0.007618069,
   0.01211845,
   0.01290241,
   0,
   0.1788854,
   0};
   gre = new TGraphErrors(9,Graph1_fx1002,Graph1_fy1002,Graph1_fex1002,Graph1_fey1002);
   gre->SetName("Graph1");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#ffcc00");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#ffcc00");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1002 = new TH1F("Graph_Graph1002","Graph",100,0,5.5);
   Graph_Graph1002->SetMinimum(0.583226);
   Graph_Graph1002->SetMaximum(1.037889);
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
   
   Double_t Graph2_fx1003[15] = {
   0.05,
   0.1,
   0.2,
   0.5,
   1,
   2,
   0,
   0.05,
   0.1,
   0.2,
   0.5,
   1,
   2,
   3,
   5};
   Double_t Graph2_fy1003[15] = {
   0.95,
   0.978903,
   0.9691011,
   0.936,
   1,
   0.9444444,
   0.9738562,
   0.95,
   0.9777283,
   0.9691011,
   0.936,
   1,
   0.9714286,
   1,
   0.8333333};
   Double_t Graph2_fex1003[15] = {
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
   Double_t Graph2_fey1003[15] = {
   0.01541104,
   0.009334831,
   0.0091713,
   0.01547953,
   0,
   0.0539903,
   0.009121599,
   0.01541104,
   0.006964064,
   0.0091713,
   0.01547953,
   0,
   0.02816031,
   0,
   0.1521452};
   gre = new TGraphErrors(15,Graph2_fx1003,Graph2_fy1003,Graph2_fex1003,Graph2_fey1003);
   gre->SetName("Graph2");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#33ff00");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#33ff00");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1003 = new TH1F("Graph_Graph1003","Graph",100,0,5.5);
   Graph_Graph1003->SetMinimum(0.649307);
   Graph_Graph1003->SetMaximum(1.031881);
   Graph_Graph1003->SetDirectory(0);
   Graph_Graph1003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1003->SetLineColor(ci);
   Graph_Graph1003->GetXaxis()->SetLabelFont(42);
   Graph_Graph1003->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1003->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1003->GetXaxis()->SetTitleFont(42);
   Graph_Graph1003->GetYaxis()->SetLabelFont(42);
   Graph_Graph1003->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1003->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1003->GetYaxis()->SetTitleFont(42);
   Graph_Graph1003->GetZaxis()->SetLabelFont(42);
   Graph_Graph1003->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1003->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1003->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1003);
   
   gre->Draw(" pl");
   
   Double_t Graph3_fx1004[10] = {
   0,
   0.05,
   0.1,
   0.2,
   0.5,
   0,
   0.05,
   0.1,
   0.2,
   0.5};
   Double_t Graph3_fy1004[10] = {
   0.9796954,
   0.9875,
   0.9692308,
   0.9830508,
   0.9583333,
   0.97543,
   0.980226,
   0.9692308,
   0.9830508,
   0.9583333};
   Double_t Graph3_fex1004[10] = {
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
   Double_t Graph3_fey1004[10] = {
   0.01004869,
   0.008783418,
   0.01236672,
   0.01188286,
   0.01289873,
   0.007673679,
   0.007399611,
   0.01236672,
   0.01188286,
   0.01289873};
   gre = new TGraphErrors(10,Graph3_fx1004,Graph3_fy1004,Graph3_fex1004,Graph3_fey1004);
   gre->SetName("Graph3");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#009900");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#009900");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1004 = new TH1F("Graph_Graph1004","Graph",100,0,0.55);
   Graph_Graph1004->SetMinimum(0.9403497);
   Graph_Graph1004->SetMaximum(1.001368);
   Graph_Graph1004->SetDirectory(0);
   Graph_Graph1004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1004->SetLineColor(ci);
   Graph_Graph1004->GetXaxis()->SetLabelFont(42);
   Graph_Graph1004->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1004->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1004->GetXaxis()->SetTitleFont(42);
   Graph_Graph1004->GetYaxis()->SetLabelFont(42);
   Graph_Graph1004->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1004->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1004->GetYaxis()->SetTitleFont(42);
   Graph_Graph1004->GetZaxis()->SetLabelFont(42);
   Graph_Graph1004->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1004->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1004->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1004);
   
   gre->Draw(" pl");
   
   Double_t Graph4_fx1005[6] = {
   0.2,
   0.5,
   1,
   2,
   3,
   5};
   Double_t Graph4_fy1005[6] = {
   0.9734748,
   0.9700997,
   0.9791667,
   0.9764706,
   0.9375,
   1};
   Double_t Graph4_fex1005[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph4_fey1005[6] = {
   0.00827601,
   0.009816642,
   0.01457713,
   0.0164409,
   0.03025768,
   0};
   gre = new TGraphErrors(6,Graph4_fx1005,Graph4_fy1005,Graph4_fex1005,Graph4_fey1005);
   gre->SetName("Graph4");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#0099cc");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#0099cc");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1005 = new TH1F("Graph_Graph1005","Graph",100,0,5.48);
   Graph_Graph1005->SetMinimum(0.8979665);
   Graph_Graph1005->SetMaximum(1.009276);
   Graph_Graph1005->SetDirectory(0);
   Graph_Graph1005->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1005->SetLineColor(ci);
   Graph_Graph1005->GetXaxis()->SetLabelFont(42);
   Graph_Graph1005->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1005->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1005->GetXaxis()->SetTitleFont(42);
   Graph_Graph1005->GetYaxis()->SetLabelFont(42);
   Graph_Graph1005->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1005->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1005->GetYaxis()->SetTitleFont(42);
   Graph_Graph1005->GetZaxis()->SetLabelFont(42);
   Graph_Graph1005->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1005->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1005->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1005);
   
   gre->Draw(" pl");
   
   Double_t Graph5_fx1006[7] = {
   0,
   0.05,
   0.1,
   0.5,
   1,
   2,
   3};
   Double_t Graph5_fy1006[7] = {
   1,
   0.9677419,
   1,
   1,
   1,
   1,
   1};
   Double_t Graph5_fex1006[7] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph5_fey1006[7] = {
   0,
   0.03173351,
   0,
   0,
   0,
   0,
   0};
   gre = new TGraphErrors(7,Graph5_fx1006,Graph5_fy1006,Graph5_fex1006,Graph5_fey1006);
   gre->SetName("Graph5");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#0000ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1006 = new TH1F("Graph_Graph1006","Graph",100,0,3.3);
   Graph_Graph1006->SetMinimum(0.9296093);
   Graph_Graph1006->SetMaximum(1.006399);
   Graph_Graph1006->SetDirectory(0);
   Graph_Graph1006->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1006->SetLineColor(ci);
   Graph_Graph1006->GetXaxis()->SetLabelFont(42);
   Graph_Graph1006->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1006->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1006->GetXaxis()->SetTitleFont(42);
   Graph_Graph1006->GetYaxis()->SetLabelFont(42);
   Graph_Graph1006->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1006->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1006->GetYaxis()->SetTitleFont(42);
   Graph_Graph1006->GetZaxis()->SetLabelFont(42);
   Graph_Graph1006->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1006->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1006->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1006);
   
   gre->Draw(" pl");
   
   Double_t Graph6_fx1007[3] = {
   0,
   0.1,
   3};
   Double_t Graph6_fy1007[3] = {
   0.9473684,
   1,
   0.9285714};
   Double_t Graph6_fex1007[3] = {
   0,
   0,
   0};
   Double_t Graph6_fey1007[3] = {
   0.05122782,
   0,
   0.06883029};
   gre = new TGraphErrors(3,Graph6_fx1007,Graph6_fy1007,Graph6_fex1007,Graph6_fey1007);
   gre->SetName("Graph6");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#9966ff");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#9966ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1007 = new TH1F("Graph_Graph1007","Graph",100,0,3.3);
   Graph_Graph1007->SetMinimum(0.8457152);
   Graph_Graph1007->SetMaximum(1.014026);
   Graph_Graph1007->SetDirectory(0);
   Graph_Graph1007->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1007->SetLineColor(ci);
   Graph_Graph1007->GetXaxis()->SetLabelFont(42);
   Graph_Graph1007->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1007->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1007->GetXaxis()->SetTitleFont(42);
   Graph_Graph1007->GetYaxis()->SetLabelFont(42);
   Graph_Graph1007->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1007->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1007->GetYaxis()->SetTitleFont(42);
   Graph_Graph1007->GetZaxis()->SetLabelFont(42);
   Graph_Graph1007->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1007->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1007->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1007);
   
   gre->Draw(" pl");
   
   Double_t Graph7_fx1008[2] = {
   10,
   20};
   Double_t Graph7_fy1008[2] = {
   1,
   1};
   Double_t Graph7_fex1008[2] = {
   0,
   0};
   Double_t Graph7_fey1008[2] = {
   0,
   0};
   gre = new TGraphErrors(2,Graph7_fx1008,Graph7_fy1008,Graph7_fex1008,Graph7_fey1008);
   gre->SetName("Graph7");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#ff00ff");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#ff00ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1008 = new TH1F("Graph_Graph1008","Graph",100,9,21);
   Graph_Graph1008->SetMinimum(0.9);
   Graph_Graph1008->SetMaximum(2.1);
   Graph_Graph1008->SetDirectory(0);
   Graph_Graph1008->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1008->SetLineColor(ci);
   Graph_Graph1008->GetXaxis()->SetLabelFont(42);
   Graph_Graph1008->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1008->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1008->GetXaxis()->SetTitleFont(42);
   Graph_Graph1008->GetYaxis()->SetLabelFont(42);
   Graph_Graph1008->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1008->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1008->GetYaxis()->SetTitleFont(42);
   Graph_Graph1008->GetZaxis()->SetLabelFont(42);
   Graph_Graph1008->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1008->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1008->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1008);
   
   gre->Draw(" pl");
   
   Double_t Graph8_fx1009[1] = {
   0};
   Double_t Graph8_fy1009[1] = {
   1};
   Double_t Graph8_fex1009[1] = {
   0};
   Double_t Graph8_fey1009[1] = {
   0};
   gre = new TGraphErrors(1,Graph8_fx1009,Graph8_fy1009,Graph8_fex1009,Graph8_fey1009);
   gre->SetName("Graph8");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1009 = new TH1F("Graph_Graph1009","Graph",100,0,1.1);
   Graph_Graph1009->SetMinimum(0.9);
   Graph_Graph1009->SetMaximum(2.1);
   Graph_Graph1009->SetDirectory(0);
   Graph_Graph1009->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1009->SetLineColor(ci);
   Graph_Graph1009->GetXaxis()->SetLabelFont(42);
   Graph_Graph1009->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1009->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1009->GetXaxis()->SetTitleFont(42);
   Graph_Graph1009->GetYaxis()->SetLabelFont(42);
   Graph_Graph1009->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1009->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1009->GetYaxis()->SetTitleFont(42);
   Graph_Graph1009->GetZaxis()->SetLabelFont(42);
   Graph_Graph1009->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1009->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1009->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1009);
   
   gre->Draw(" pl");
   
   TLegend *leg = new TLegend(0.5,0.15,0.85,0.45,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.045);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph0","m_{#gamma D}=0.250 GeV","PL");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ff0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph1","m_{#gamma D}=0.275 GeV","PL");

   ci = TColor::GetColor("#ffcc00");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ffcc00");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph2","m_{#gamma D}=0.300 GeV","PL");

   ci = TColor::GetColor("#33ff00");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#33ff00");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph3","m_{#gamma D}=0.400 GeV","PL");

   ci = TColor::GetColor("#009900");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#009900");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph4","m_{#gamma D}=0.700 GeV","PL");

   ci = TColor::GetColor("#0099cc");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#0099cc");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph5","m_{#gamma D}=1.000 GeV","PL");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#0000ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph6","m_{#gamma D}=1.500 GeV","PL");

   ci = TColor::GetColor("#9966ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#9966ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph7","m_{#gamma D}=2.000 GeV","PL");

   ci = TColor::GetColor("#ff00ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ff00ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph8","m_{#gamma D}=8.500 GeV","PL");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   leg->Draw();
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
