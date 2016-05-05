void e_hlt_vs_cT()
{
//=========Macro generated from canvas: c/c
//=========  (Mon Jan 25 12:52:42 2016) by ROOT version6.02/05
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
   0.9679565,
   0.9640032,
   0.9659805,
   0.9646177,
   0.958215,
   0.9587264,
   0.9604743,
   0.9752066,
   0.9487179,
   0.9565217,
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
   0.001636746,
   0.001656906,
   0.001782137,
   0.002176172,
   0.004030261,
   0.006831019,
   0.01224961,
   0.0141359,
   0.03531986,
   0.04252258,
   0};
   TGraphErrors *gre = new TGraphErrors(11,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","Graph",100,0,22);
   Graph_Graph1001->SetMinimum(0.9047379);
   Graph_Graph1001->SetMaximum(1.00866);
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
   0.9737418,
   0.972039,
   0.9690198,
   0.9661235,
   0.9567308,
   0.9591474,
   0.9539749,
   0.975,
   0.8965517};
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
   0.001763032,
   0.001893329,
   0.001696875,
   0.002162921,
   0.004987786,
   0.008342538,
   0.01355398,
   0.02468552,
   0.0565523};
   gre = new TGraphErrors(9,Graph1_fx1002,Graph1_fy1002,Graph1_fex1002,Graph1_fey1002);
   gre->SetName("Graph1");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(2);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1002 = new TH1F("Graph_Graph1002","Graph",100,0,5.5);
   Graph_Graph1002->SetMinimum(0.8240308);
   Graph_Graph1002->SetMaximum(1.015654);
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
   
   Double_t Graph2_fx1003[9] = {
   0,
   0.05,
   0.1,
   0.2,
   0.5,
   1,
   2,
   3,
   5};
   Double_t Graph2_fy1003[9] = {
   0.9712128,
   0.9765044,
   0.9704256,
   0.9694853,
   0.9669454,
   0.9310345,
   0.9698113,
   0.9496403,
   1};
   Double_t Graph2_fex1003[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph2_fey1003[9] = {
   0.002097155,
   0.002345362,
   0.001857504,
   0.002331985,
   0.003567741,
   0.04705436,
   0.01051097,
   0.01854871,
   0};
   gre = new TGraphErrors(9,Graph2_fx1003,Graph2_fy1003,Graph2_fex1003,Graph2_fey1003);
   gre->SetName("Graph2");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(3);
   gre->SetMarkerColor(3);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1003 = new TH1F("Graph_Graph1003","Graph",100,0,5.5);
   Graph_Graph1003->SetMinimum(0.8723781);
   Graph_Graph1003->SetMaximum(1.011602);
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
   
   Double_t Graph3_fx1004[9] = {
   0,
   0.05,
   0.1,
   0.2,
   0.5,
   1,
   2,
   3,
   5};
   Double_t Graph3_fy1004[9] = {
   0.9799715,
   0.9758271,
   0.9773603,
   0.9738524,
   0.9690792,
   0.9779582,
   0.9655172,
   0.9217391,
   0.9322034};
   Double_t Graph3_fex1004[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph3_fey1004[9] = {
   0.001412607,
   0.001697001,
   0.002308522,
   0.003846555,
   0.003190877,
   0.005000687,
   0.01197945,
   0.02504537,
   0.03272904};
   gre = new TGraphErrors(9,Graph3_fx1004,Graph3_fy1004,Graph3_fex1004,Graph3_fey1004);
   gre->SetName("Graph3");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(7);
   gre->SetMarkerColor(7);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1004 = new TH1F("Graph_Graph1004","Graph",100,0,5.5);
   Graph_Graph1004->SetMinimum(0.8880672);
   Graph_Graph1004->SetMaximum(0.9915854);
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
   
   Double_t Graph4_fx1005[9] = {
   0,
   0.05,
   0.1,
   0.2,
   0.5,
   1,
   2,
   3,
   5};
   Double_t Graph4_fy1005[9] = {
   0.984,
   0.9787496,
   0.9789315,
   0.9775382,
   0.9759186,
   0.9738562,
   0.9720497,
   0.9720559,
   0.9365079};
   Double_t Graph4_fex1005[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph4_fey1005[9] = {
   0.001304628,
   0.001461226,
   0.001488954,
   0.001678776,
   0.002208814,
   0.0048757,
   0.006495231,
   0.00736329,
   0.0307217};
   gre = new TGraphErrors(9,Graph4_fx1005,Graph4_fy1005,Graph4_fex1005,Graph4_fey1005);
   gre->SetName("Graph4");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(8);
   gre->SetMarkerColor(8);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1005 = new TH1F("Graph_Graph1005","Graph",100,0,5.5);
   Graph_Graph1005->SetMinimum(0.8978344);
   Graph_Graph1005->SetMaximum(0.9932565);
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
   
   Double_t Graph5_fx1006[9] = {
   0,
   0.05,
   0.1,
   0.2,
   0.5,
   1,
   2,
   3,
   5};
   Double_t Graph5_fy1006[9] = {
   0.9813461,
   0.9812525,
   0.9800084,
   0.9790982,
   0.9765865,
   0.9798817,
   0.9680066,
   0.9664903,
   0.9571429};
   Double_t Graph5_fex1006[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph5_fey1006[9] = {
   0.001518972,
   0.001580859,
   0.001432011,
   0.001550199,
   0.001921491,
   0.002415041,
   0.005040432,
   0.007557749,
   0.01210378};
   gre = new TGraphErrors(9,Graph5_fx1006,Graph5_fy1006,Graph5_fex1006,Graph5_fey1006);
   gre->SetName("Graph5");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#ff9933");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#ff9933");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1006 = new TH1F("Graph_Graph1006","Graph",100,0,5.5);
   Graph_Graph1006->SetMinimum(0.9412565);
   Graph_Graph1006->SetMaximum(0.9866477);
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
   
   Double_t Graph6_fx1007[7] = {
   0,
   0.05,
   0.1,
   0.2,
   1,
   2,
   3};
   Double_t Graph6_fy1007[7] = {
   0.9798387,
   0.9807647,
   0.9874286,
   0.9783291,
   0.9756368,
   0.9763996,
   0.9641407};
   Double_t Graph6_fex1007[7] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph6_fey1007[7] = {
   0.001487508,
   0.001492065,
   0.003766527,
   0.001780063,
   0.002565297,
   0.00355631,
   0.004836528};
   gre = new TGraphErrors(7,Graph6_fx1007,Graph6_fy1007,Graph6_fex1007,Graph6_fey1007);
   gre->SetName("Graph6");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#ffcc00");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#ffcc00");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1007 = new TH1F("Graph_Graph1007","Graph",100,0,3.3);
   Graph_Graph1007->SetMinimum(0.9561151);
   Graph_Graph1007->SetMaximum(0.9943842);
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
   
   Double_t Graph7_fx1008[10] = {
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
   Double_t Graph7_fy1008[10] = {
   0.9844256,
   0.9833812,
   0.978175,
   0.9765184,
   0.9754264,
   0.9713691,
   0.976824,
   0.9768271,
   0.9541139,
   0.9750779};
   Double_t Graph7_fex1008[10] = {
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
   Double_t Graph7_fey1008[10] = {
   0.001760996,
   0.001831125,
   0.00210653,
   0.002275366,
   0.002632426,
   0.003804925,
   0.004408229,
   0.006352105,
   0.005885279,
   0.008700809};
   gre = new TGraphErrors(10,Graph7_fx1008,Graph7_fy1008,Graph7_fex1008,Graph7_fey1008);
   gre->SetName("Graph7");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetMarkerColor(4);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1008 = new TH1F("Graph_Graph1008","Graph",100,0,21.995);
   Graph_Graph1008->SetMinimum(0.9444329);
   Graph_Graph1008->SetMaximum(0.9899824);
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
   
   Double_t Graph8_fx1009[9] = {
   0,
   0.05,
   0.1,
   0.2,
   0.5,
   1,
   2,
   3,
   5};
   Double_t Graph8_fy1009[9] = {
   0.9906094,
   0.9909893,
   0.9885133,
   0.9913484,
   0.9914687,
   0.9898761,
   0.9865019,
   0.9859337,
   0.9866859};
   Double_t Graph8_fex1009[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph8_fey1009[9] = {
   0.0009346358,
   0.000915498,
   0.001029759,
   0.0008884794,
   0.0008808757,
   0.0009737521,
   0.001175843,
   0.001337801,
   0.001451649};
   gre = new TGraphErrors(9,Graph8_fx1009,Graph8_fy1009,Graph8_fex1009,Graph8_fey1009);
   gre->SetName("Graph8");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(6);
   gre->SetMarkerColor(6);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1009 = new TH1F("Graph_Graph1009","Graph",100,0,5.5);
   Graph_Graph1009->SetMinimum(0.9838205);
   Graph_Graph1009->SetMaximum(0.9931249);
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
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph1","m_{#gamma D}=0.275 GeV","PL");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph2","m_{#gamma D}=0.300 GeV","PL");
   entry->SetLineColor(3);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(3);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph3","m_{#gamma D}=0.400 GeV","PL");
   entry->SetLineColor(7);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(7);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph4","m_{#gamma D}=0.700 GeV","PL");
   entry->SetLineColor(8);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(8);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph5","m_{#gamma D}=1.000 GeV","PL");

   ci = TColor::GetColor("#ff9933");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ff9933");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph6","m_{#gamma D}=1.500 GeV","PL");

   ci = TColor::GetColor("#ffcc00");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ffcc00");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph7","m_{#gamma D}=2.000 GeV","PL");
   entry->SetLineColor(4);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(4);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph8","m_{#gamma D}=8.500 GeV","PL");
   entry->SetLineColor(6);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(6);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   leg->Draw();
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
