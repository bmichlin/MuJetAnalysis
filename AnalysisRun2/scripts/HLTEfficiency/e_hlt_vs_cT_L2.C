void e_hlt_vs_cT_L2()
{
//=========Macro generated from canvas: c/c
//=========  (Wed Jan 27 13:26:48 2016) by ROOT version6.02/05
   TCanvas *c = new TCanvas("c", "c",0,0,700,500);
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
   0.9675407,
   0.9619916,
   0.9635263,
   0.9587252,
   0.9479167,
   0.9411858,
   0.9326955,
   0.9443508,
   0.9339752,
   0.9328704,
   0.8709677};
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
   0.001574901,
   0.001601274,
   0.001610825,
   0.00171858,
   0.002192335,
   0.002958344,
   0.004550919,
   0.00543511,
   0.009209878,
   0.01203998,
   0.04257497};
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
   Graph_Graph1001->SetMinimum(0.8143205);
   Graph_Graph1001->SetMaximum(0.9831879);
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
   0.9717438,
   0.9701139,
   0.9660176,
   0.9610771,
   0.9503861,
   0.9402612,
   0.9416532,
   0.927451,
   0.9566667};
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
   0.001758138,
   0.001854304,
   0.001583314,
   0.001747129,
   0.002783237,
   0.003950587,
   0.004718257,
   0.01148619,
   0.01175522};
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
   Graph_Graph1002->SetMinimum(0.9102111);
   Graph_Graph1002->SetMaximum(0.9792556);
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
   0.9717706,
   0.9757959,
   0.9681091,
   0.9696423,
   0.9571598,
   0.979021,
   0.9448873,
   0.9369592,
   0.9449275};
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
   0.002013569,
   0.002269378,
   0.001740552,
   0.001822633,
   0.002202875,
   0.01198452,
   0.00424857,
   0.006042017,
   0.01228166};
   gre = new TGraphErrors(9,Graph2_fx1003,Graph2_fy1003,Graph2_fex1003,Graph2_fey1003);
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
   Graph_Graph1003->SetMinimum(0.9249084);
   Graph_Graph1003->SetMaximum(0.9970143);
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
   0.9787509,
   0.9751324,
   0.9751233,
   0.9707235,
   0.9612022,
   0.9610455,
   0.9438559,
   0.9460293,
   0.9396552};
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
   0.001437045,
   0.001670855,
   0.002280832,
   0.003447603,
   0.002257124,
   0.003067354,
   0.0052979,
   0.006274243,
   0.008356536};
   gre = new TGraphErrors(9,Graph3_fx1004,Graph3_fy1004,Graph3_fex1004,Graph3_fey1004);
   gre->SetName("Graph3");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#009900");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#009900");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1004 = new TH1F("Graph_Graph1004","Graph",100,0,5.5);
   Graph_Graph1004->SetMinimum(0.9264097);
   Graph_Graph1004->SetMaximum(0.9850768);
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
   0.9827586,
   0.9781711,
   0.9756529,
   0.9753059,
   0.9702649,
   0.963138,
   0.9505637,
   0.9542414,
   0.9378378};
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
   0.001330618,
   0.001448982,
   0.002159657,
   0.001644193,
   0.00189857,
   0.003344493,
   0.003685854,
   0.003418252,
   0.008875873};
   gre = new TGraphErrors(9,Graph4_fx1005,Graph4_fy1005,Graph4_fex1005,Graph4_fey1005);
   gre->SetName("Graph4");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#0099cc");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#0099cc");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1005 = new TH1F("Graph_Graph1005","Graph",100,0,5.5);
   Graph_Graph1005->SetMinimum(0.9234492);
   Graph_Graph1005->SetMaximum(0.989602);
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
   0.9809034,
   0.9806145,
   0.9800809,
   0.9781894,
   0.973763,
   0.9698619,
   0.9578119,
   0.9511979,
   0.944066};
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
   0.001514281,
   0.001583313,
   0.001404972,
   0.001529159,
   0.001749517,
   0.002019503,
   0.002855994,
   0.003705376,
   0.004351259};
   gre = new TGraphErrors(9,Graph5_fx1006,Graph5_fy1006,Graph5_fex1006,Graph5_fey1006);
   gre->SetName("Graph5");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#0000ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1006 = new TH1F("Graph_Graph1006","Graph",100,0,5.5);
   Graph_Graph1006->SetMinimum(0.9354444);
   Graph_Graph1006->SetMaximum(0.986688);
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
   
   Double_t Graph6_fx1007[8] = {
   0,
   0.05,
   0.1,
   0.2,
   1,
   2,
   3,
   5};
   Double_t Graph6_fy1007[8] = {
   0.9796233,
   0.9799146,
   0.9877232,
   0.9772299,
   0.9713501,
   0.9620751,
   0.9512813,
   0.9451443};
   Double_t Graph6_fex1007[8] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph6_fey1007[8] = {
   0.001482782,
   0.001507302,
   0.003678798,
   0.001796445,
   0.002185003,
   0.002677631,
   0.003612658,
   0.003245558};
   gre = new TGraphErrors(8,Graph6_fx1007,Graph6_fy1007,Graph6_fex1007,Graph6_fey1007);
   gre->SetName("Graph6");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#9966ff");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#9966ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1007 = new TH1F("Graph_Graph1007","Graph",100,0,5.5);
   Graph_Graph1007->SetMinimum(0.9369484);
   Graph_Graph1007->SetMaximum(0.9963523);
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
   0,
   0.05,
   0.1,
   0.2,
   0.5,
   1,
   2,
   3,
   10,
   20};
   Double_t Graph7_fy1008[10] = {
   0.9795229,
   0.9840224,
   0.9817049,
   0.9779173,
   0.9759585,
   0.9712108,
   0.9659722,
   0.9575372,
   0.9386568,
   0.9372393};
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
   0.002057737,
   0.001772025,
   0.001900227,
   0.002091651,
   0.002205197,
   0.002432856,
   0.0027584,
   0.003284936,
   0.002467777,
   0.003417978};
   gre = new TGraphErrors(10,Graph7_fx1008,Graph7_fy1008,Graph7_fex1008,Graph7_fey1008);
   gre->SetName("Graph7");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#ff00ff");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#ff00ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1008 = new TH1F("Graph_Graph1008","Graph",100,0,22);
   Graph_Graph1008->SetMinimum(0.928624);
   Graph_Graph1008->SetMaximum(0.9909917);
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
   0.992126,
   0.992268,
   0.987156,
   0.9803371,
   0.990991,
   0.994012,
   0.9678571,
   0.9881657,
   0.96875};
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
   0.007842954,
   0.004446757,
   0.004823313,
   0.007358457,
   0.005177871,
   0.004221476,
   0.01054069,
   0.008318465,
   0.01775805};
   gre = new TGraphErrors(9,Graph8_fx1009,Graph8_fy1009,Graph8_fex1009,Graph8_fey1009);
   gre->SetName("Graph8");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1009 = new TH1F("Graph_Graph1009","Graph",100,0,5.5);
   Graph_Graph1009->SetMinimum(0.9460943);
   Graph_Graph1009->SetMaximum(1.004867);
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
