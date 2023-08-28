#include "stdafx.h"
#include "ClassHub.h"
#include<string.h>
#include <io.h>
#include <cstdlib>
#include "tchar.h"
#include "Main.h"
#include <math.h>


bool CHubData::LoadXMLData(TiXmlElement* pElem)
{
	TiXmlElement* pElem1st;

	for (pElem1st = pElem->FirstChildElement(); pElem1st != NULL; pElem1st = pElem1st->NextSiblingElement())
	{
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"hubtype")
		{
			mHubType = Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value());
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"hubmidtype")
		{
			HubMiddleType = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower().Find(L"rl") > -1)
		{
			RL.push_back(_wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value())));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower().Find(L"rh") > -1)
		{
			RH.push_back(_wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value())));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower().Find(L"rr") > -1)
		{
			RR.push_back(_wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value())));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower().Find(L"rc") > -1)
		{
			RC.push_back(_wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value())));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower().Find(L"ra") > -1)
		{
			RA.push_back(_wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value())));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"sa")
		{
			SA = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"SA");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"sb")
		{
			SB = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"SB");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"sb1")
		{
			SB1 = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"SA");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"sb2")
		{
			SB2 = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"SA");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"sb3")
		{
			SB3 = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"SA");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"sc")
		{
			SC = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"SC");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"sleadw")
		{
			SLeadH = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"SLeadH");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"sleadh")
		{
			SLeadH = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"SLeadH");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"strailw")
		{
			STrailW = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"STrailW");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"th")
		{
			TH = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"H");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"th1")
		{
			TH1 = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"H1");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"th2")
		{
			TH2 = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"H2");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"td")
		{
			TD = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"D");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}


		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"td1")
		{
			TD1 = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"D1");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"td2")
		{
			TD2 = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"D2");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"td3")
		{
			TD3 = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"D3");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"tw")
		{
			TW = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));

		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"bacta")
		{
			BactA = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"bactb")
		{
			BactB = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"bactc")
		{
			BactC = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"bactd")
		{
			BactD = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"bacte")
		{
			BactE = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"bactf")
		{
			BactF = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"bactg")
		{
			BactG = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"bacthg")
		{
			BactHg = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"bacthr")
		{
			BactHr = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"fira")
		{
			FirA = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"firb")
		{
			FirB = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"firc")
		{
			FirC = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"fire")
		{
			FirE = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"firf")
		{
			FirF = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"firh")
		{
			FirH = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

	}
	return true;

}

bool CHubData::ExportXMLData(TiXmlElement* pElem, int HubType)
{
	CString str;
	TiXmlElement *HubElement = NULL;


	if (HubType == 0)
	{
		HubElement = new TiXmlElement("StatorHub");
		pElem->LinkEndChild(HubElement);
	}
	if (HubType == 1)
	{
		HubElement = new TiXmlElement("RotorHub");
		pElem->LinkEndChild(HubElement);
	}

	//HubType
	TiXmlElement *SAElement = new TiXmlElement("HubType");
	HubElement->LinkEndChild(SAElement);
	TiXmlText *SAContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(mHubType));
	SAElement->LinkEndChild(SAContent);

	//HubMiddleType
	if (HubMiddleType != 0)
	{
		TiXmlElement *HubMiddleTypeElement = new TiXmlElement("HubMidType");
		HubElement->LinkEndChild(HubMiddleTypeElement);
		str.Format(L"%.1d", HubMiddleType);
		TiXmlText *HubMiddleTypeContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		HubMiddleTypeElement->LinkEndChild(HubMiddleTypeContent);
	}

	//RL
	for (int i = 0; i < RL.size(); ++i)
	{
		str.Format(L"RL%d", i + 1);
		std::string namestr = CT2A(str.GetString());
		TiXmlElement *RLElement = new TiXmlElement(namestr.c_str());
		HubElement->LinkEndChild(RLElement);
		str.Format(L"%.1f", RL[i]);
		TiXmlText *RLContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		RLElement->LinkEndChild(RLContent);
	}

	//RH
	for (int i = 0; i < RH.size(); ++i)
	{
		str.Format(L"RH%d", i + 1);
		std::string namestr = CT2A(str.GetString());
		TiXmlElement *RHElement = new TiXmlElement(namestr.c_str());
		HubElement->LinkEndChild(RHElement);
		str.Format(L"%.1f", RH[i]);
		TiXmlText *RHContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		RHElement->LinkEndChild(RHContent);
	}

	//RR
	for (int i = 0; i < RR.size(); ++i)
	{
		str.Format(L"RR%d", i + 1);
		std::string namestr = CT2A(str.GetString());
		TiXmlElement *RRElement = new TiXmlElement(namestr.c_str());
		HubElement->LinkEndChild(RRElement);
		str.Format(L"%.1f", RR[i]);
		TiXmlText *RRContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		RRElement->LinkEndChild(RRContent);
	}

	//RC
	for (int i = 0; i < RC.size(); ++i)
	{
		str.Format(L"RC%d", i + 1);
		std::string namestr = CT2A(str.GetString());
		TiXmlElement *RCElement = new TiXmlElement(namestr.c_str());
		HubElement->LinkEndChild(RCElement);
		str.Format(L"%.1f", RC[i]);
		TiXmlText *RCContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		RCElement->LinkEndChild(RCContent);
	}

	//RA
	for (int i = 0; i < RA.size(); ++i)
	{
		str.Format(L"RA%d", i + 1);
		std::string namestr = CT2A(str.GetString());
		TiXmlElement *RAElement = new TiXmlElement(namestr.c_str());
		HubElement->LinkEndChild(RAElement);
		str.Format(L"%.1f", RA[i]);
		TiXmlText *RAContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		RAElement->LinkEndChild(RAContent);
	}

	//SA
	if (SA != 0)
	{
		TiXmlElement *SAElement = new TiXmlElement("SA");
		HubElement->LinkEndChild(SAElement);
		str.Format(L"%.1f", SA);
		TiXmlText *SAContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		SAElement->LinkEndChild(SAContent);
	}

	//SB
	if (SB != 0)
	{
		TiXmlElement *SBElement = new TiXmlElement("SB");
		HubElement->LinkEndChild(SBElement);
		str.Format(L"%.1f", SB);
		TiXmlText *SBContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		SBElement->LinkEndChild(SBContent);
	}

	//SB1
	if (SB1 != 0)
	{
		TiXmlElement *SB1Element = new TiXmlElement("SB1");
		HubElement->LinkEndChild(SB1Element);
		str.Format(L"%.1f", SB1);
		TiXmlText *SB1Content = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		SB1Element->LinkEndChild(SB1Content);
	}

	//SB2
	if (SB2 != 0)
	{
		TiXmlElement *SB2Element = new TiXmlElement("SB2");
		HubElement->LinkEndChild(SB2Element);
		str.Format(L"%.1f", SB2);
		TiXmlText *SB2Content = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		SB2Element->LinkEndChild(SB2Content);
	}

	//SB3
	if (SB3 != 0)
	{
		TiXmlElement *SB3Element = new TiXmlElement("SB3");
		HubElement->LinkEndChild(SB3Element);
		str.Format(L"%.1f", SB3);
		TiXmlText *SB3Content = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		SB3Element->LinkEndChild(SB3Content);
	}

	//SC
	if (SC != 0)
	{
		TiXmlElement *SCElement = new TiXmlElement("SC");
		HubElement->LinkEndChild(SCElement);
		str.Format(L"%.1f", SC);
		TiXmlText *SCContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		SCElement->LinkEndChild(SCContent);
	}

	//SG
	if (SG != 0)
	{
		TiXmlElement *SGElement = new TiXmlElement("SG");
		HubElement->LinkEndChild(SGElement);
		str.Format(L"%.1f", SG);
		TiXmlText *SGContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		SGElement->LinkEndChild(SGContent);
	}

	//SLeadW
	if (SLeadW != 0)
	{
		TiXmlElement *SLeadWElement = new TiXmlElement("SLeadW");
		HubElement->LinkEndChild(SLeadWElement);
		str.Format(L"%.1f", SLeadW);
		TiXmlText *SLeadWContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		SLeadWElement->LinkEndChild(SLeadWContent);
	}

	//SLeadH
	if (SLeadH != 0)
	{
		TiXmlElement *SLeadHElement = new TiXmlElement("SLeadH");
		HubElement->LinkEndChild(SLeadHElement);
		str.Format(L"%.1f", SLeadH);
		TiXmlText *SLeadHContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		SLeadHElement->LinkEndChild(SLeadHContent);
	}

	//STrailW
	if (STrailW != 0)
	{
		TiXmlElement *STrailWElement = new TiXmlElement("STrailW");
		HubElement->LinkEndChild(STrailWElement);
		str.Format(L"%.1f", STrailW);
		TiXmlText *STrailWContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		STrailWElement->LinkEndChild(STrailWContent);
	}

	//TD
	if (TD != 0)
	{
		TiXmlElement *TDElement = new TiXmlElement("TD");
		HubElement->LinkEndChild(TDElement);
		str.Format(L"%.1f", TD);
		TiXmlText *TDContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		TDElement->LinkEndChild(TDContent);
	}

	//TD1
	if (TD1 != 0)
	{
		TiXmlElement *TD1Element = new TiXmlElement("TD1");
		HubElement->LinkEndChild(TD1Element);
		str.Format(L"%.1f", TD1);
		TiXmlText *TD1Content = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		TD1Element->LinkEndChild(TD1Content);
	}

	//TD2
	if (TD2 != 0)
	{
		TiXmlElement *TD2Element = new TiXmlElement("TD2");
		HubElement->LinkEndChild(TD2Element);
		str.Format(L"%.1f", TD2);
		TiXmlText *TD2Content = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		TD2Element->LinkEndChild(TD2Content);
	}

	//TD3
	if (TD3 != 0)
	{
		TiXmlElement *TD3Element = new TiXmlElement("TD3");
		HubElement->LinkEndChild(TD3Element);
		str.Format(L"%.1f", TD3);
		TiXmlText *TD3Content = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		TD3Element->LinkEndChild(TD3Content);
	}

	//TH
	if (TH != 0)
	{
		TiXmlElement *THElement = new TiXmlElement("TH");
		HubElement->LinkEndChild(THElement);
		str.Format(L"%.1f", TH);
		TiXmlText *THContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		THElement->LinkEndChild(THContent);
	}

	//TH1
	if (TH1 != 0)
	{
		TiXmlElement *TH1Element = new TiXmlElement("TH1");
		HubElement->LinkEndChild(TH1Element);
		str.Format(L"%.1f", TH1);
		TiXmlText *TH1Content = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		TH1Element->LinkEndChild(TH1Content);
	}

	//TH2
	if (TH2 != 0)
	{
		TiXmlElement *TH2Element = new TiXmlElement("TH2");
		HubElement->LinkEndChild(TH2Element);
		str.Format(L"%.1f", TH2);
		TiXmlText *TH2Content = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		TH2Element->LinkEndChild(TH2Content);
	}

	//TW
	if (TW != 0)
	{
		TiXmlElement *TWElement = new TiXmlElement("TW");
		HubElement->LinkEndChild(TWElement);
		str.Format(L"%.1f", TW);
		TiXmlText *TWContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		TWElement->LinkEndChild(TWContent);
	}

	//BactA
	if (BactA != 0)
	{
		TiXmlElement *BactAElement = new TiXmlElement("BactA");
		HubElement->LinkEndChild(BactAElement);
		str.Format(L"%.1f", BactA);
		TiXmlText *BactAContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		BactAElement->LinkEndChild(BactAContent);
	}

	//BactB
	if (BactB != 0)
	{
		TiXmlElement *BactBElement = new TiXmlElement("BactB");
		HubElement->LinkEndChild(BactBElement);
		str.Format(L"%.1f", BactB);
		TiXmlText *BactBContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		BactBElement->LinkEndChild(BactBContent);
	}

	//BactC
	if (BactC != 0)
	{
		TiXmlElement *BactCElement = new TiXmlElement("BactC");
		HubElement->LinkEndChild(BactCElement);
		str.Format(L"%.1f", BactC);
		TiXmlText *BactCContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		BactCElement->LinkEndChild(BactCContent);
	}

	//BactD
	if (BactD != 0)
	{
		TiXmlElement *BactDElement = new TiXmlElement("BactD");
		HubElement->LinkEndChild(BactDElement);
		str.Format(L"%.1f", BactD);
		TiXmlText *BactDContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		BactDElement->LinkEndChild(BactDContent);
	}

	//BactE
	if (BactE != 0)
	{
		TiXmlElement *BactEElement = new TiXmlElement("BactE");
		HubElement->LinkEndChild(BactEElement);
		str.Format(L"%.1f", BactE);
		TiXmlText *BactEContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		BactEElement->LinkEndChild(BactEContent);
	}

	//BactF
	if (BactF != 0)
	{
		TiXmlElement *BactFElement = new TiXmlElement("BactF");
		HubElement->LinkEndChild(BactFElement);
		str.Format(L"%.1f", BactF);
		TiXmlText *BactFContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		BactFElement->LinkEndChild(BactFContent);
	}

	//BactG
	if (BactG != 0)
	{
		TiXmlElement *BactGElement = new TiXmlElement("BactG");
		HubElement->LinkEndChild(BactGElement);
		str.Format(L"%.1f", BactG);
		TiXmlText *BactGContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		BactGElement->LinkEndChild(BactGContent);
	}

	//BactHg
	if (BactHg != 0)
	{
		TiXmlElement *BactHgElement = new TiXmlElement("BactHg");
		HubElement->LinkEndChild(BactHgElement);
		str.Format(L"%.1f", BactHg);
		TiXmlText *BactHgContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		BactHgElement->LinkEndChild(BactHgContent);
	}

	//BactHr
	if (BactHr != 0)
	{
		TiXmlElement *BactHrElement = new TiXmlElement("BactHr");
		HubElement->LinkEndChild(BactHrElement);
		str.Format(L"%.1f", BactHr);
		TiXmlText *BactHrContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		BactHrElement->LinkEndChild(BactHrContent);
	}

	//FirA
	if (FirA != 0)
	{
		TiXmlElement *FirAElement = new TiXmlElement("FirA");
		HubElement->LinkEndChild(FirAElement);
		str.Format(L"%.1f", FirA);
		TiXmlText *FirAContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		FirAElement->LinkEndChild(FirAContent);
	}

	//FirB
	if (FirB != 0)
	{
		TiXmlElement *FirBElement = new TiXmlElement("FirB");
		HubElement->LinkEndChild(FirBElement);
		str.Format(L"%.1f", FirB);
		TiXmlText *FirBContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		FirBElement->LinkEndChild(FirBContent);
	}

	//FirC
	if (FirC != 0)
	{
		TiXmlElement *FirCElement = new TiXmlElement("FirC");
		HubElement->LinkEndChild(FirCElement);
		str.Format(L"%.1f", FirC);
		TiXmlText *FirCContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		FirCElement->LinkEndChild(FirCContent);
	}

	//FirE
	if (FirE != 0)
	{
		TiXmlElement *FirEElement = new TiXmlElement("FirE");
		HubElement->LinkEndChild(FirEElement);
		str.Format(L"%.1f", FirE);
		TiXmlText *FirEContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		FirEElement->LinkEndChild(FirEContent);
	}

	//FirF
	if (FirF != 0)
	{
		TiXmlElement *FirFElement = new TiXmlElement("FirF");
		HubElement->LinkEndChild(FirFElement);
		str.Format(L"%.1f", FirF);
		TiXmlText *FirFContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		FirFElement->LinkEndChild(FirFContent);
	}

	//FirH
	if (FirH != 0)
	{
		TiXmlElement *FirHgElement = new TiXmlElement("FirH");
		HubElement->LinkEndChild(FirHgElement);
		str.Format(L"%.1f", FirH);
		TiXmlText *FirHgContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		FirHgElement->LinkEndChild(FirHgContent);
	}

	return true;
}

CHubData::CHubData()
{
	Order = 0;							//序号
	mBladeType = stator;				//叶片类型
	HubMiddleType = 0;

	RL.clear();						//动叶参数
	RH.clear();
	RR.clear();
	RC.clear();
	RA.clear();

	a1 = 45;

	TD = 0;
	TD1 = 0;
	TD2 = 0;
	TD3 = 0;
	TH = 0;
	TH1 = 0;
	TH2 = 0;
	TW = 0;

	SA = 0;							//静叶参数
	SB = 0;
	SB1 = 0;
	SB2 = 0;
	SB3 = 0;
	SC = 0;
	SG = 0;
	SLeadW = 0;
	SLeadH = 0;
	STrailW = 0;


	BactA = 0;
	BactB = 0;
	BactC = 0;
	BactD = 0;							
	BactE = 0;						
	BactF = 0;							
	BactG = 0;						
	BactHg = 0;

	FirA = 0;
	FirB = 0;
	FirC = 0;
	FirE = 0;
	FirF = 0;
	FirH = 0;
}

CHubData::~CHubData()
{

}
