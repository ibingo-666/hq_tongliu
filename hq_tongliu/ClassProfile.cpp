#include "stdafx.h"
#include "ClassProfile.h"
#include "tchar.h"
#include "Main.h"


CProfileData::CProfileData()
{
	Order = 0;
	mType = stator;
	mProfileList.clear();

	ShroudLeadW = 0;
	ShroudTrailW = 0;
	HubLeadW = 0;
	HubTrailW = 0;
	BladeHeight = 0;
	Alpha = 0;
	Theta = 0;



}

CProfileData::~CProfileData()
{
}

bool CProfileData::LoadXMLData(TiXmlElement* pElem)
{
	TiXmlElement* pElem1st;
	TiXmlElement* pElem2nd;
	for (pElem1st = pElem->FirstChildElement(); pElem1st != NULL; pElem1st = pElem1st->NextSiblingElement())
	{
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"height")
		{
			BladeHeight = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"BladeHeight");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"alpha")
		{
			Alpha = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"Alpha");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"theta")
		{
			Theta = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"Theta");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"shroudleadw")
		{
			ShroudLeadW = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"ShroudLeadW");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"shroudtrailw")
		{
			ShroudTrailW = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"ShroudTrailW");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"hubleadw")
		{
			HubLeadW = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"HubLeadW");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"hubtrailw")
		{
			HubTrailW = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"HubTrailW");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}


		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"layerdata")
		{
			CLayerData tempPro;
			for (pElem2nd = pElem1st->FirstChildElement(); pElem2nd != NULL; pElem2nd = pElem2nd->NextSiblingElement())
			{
				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"height")
				{
					tempPro.Height = _wtof(Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value()));
					//AfxMessageBox(L"ProHeight");
					//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value()));
				}

				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"leadwidth")
				{
					tempPro.LeadingWidth = _wtof(Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value()));
					//AfxMessageBox(L"LeadingWidth");
					//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value()));
				}

				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"trailwidth")
				{
					tempPro.TrailingWidth = _wtof(Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value()));
					//AfxMessageBox(L"TrailingWidth");
					//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value()));
				}
			}
			mProfileList.push_back(tempPro);

		}
	}
	return true;
}

bool CProfileData::ExportXMLData(TiXmlElement* pElem)
{
	CString str;

	//Profile
	TiXmlElement *ProfileElement = new TiXmlElement("Profile");
	pElem->LinkEndChild(ProfileElement);

	//Height
	TiXmlElement *PHeightElement = new TiXmlElement("Height");
	ProfileElement->LinkEndChild(PHeightElement);
	str.Format(L"%.1f", BladeHeight);
	TiXmlText *PHeightContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	PHeightElement->LinkEndChild(PHeightContent);

	//Alpha
	TiXmlElement *AlphaElement = new TiXmlElement("Alpha");
	ProfileElement->LinkEndChild(AlphaElement);
	str.Format(L"%.1f", Alpha);
	TiXmlText *AlphaContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	AlphaElement->LinkEndChild(AlphaContent);

	//Theta
	TiXmlElement *ThetaElement = new TiXmlElement("Theta");
	ProfileElement->LinkEndChild(ThetaElement);
	str.Format(L"%.1f", Theta);
	TiXmlText *ThetaContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	ThetaElement->LinkEndChild(ThetaContent);

	//ShroudLeadW
	TiXmlElement *ShroudLeadWElement = new TiXmlElement("ShroudLeadW");
	ProfileElement->LinkEndChild(ShroudLeadWElement);
	str.Format(L"%.3f", ShroudLeadW);
	TiXmlText *ShroudLeadWContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	ShroudLeadWElement->LinkEndChild(ShroudLeadWContent);

	//ShroudTrailW
	TiXmlElement *ShroudTrailWElement = new TiXmlElement("ShroudTrailW");
	ProfileElement->LinkEndChild(ShroudTrailWElement);
	str.Format(L"%.3f", ShroudTrailW);
	TiXmlText *ShroudTrailWContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	ShroudTrailWElement->LinkEndChild(ShroudTrailWContent);

	//HubLeadW
	TiXmlElement *HubLeadWElement = new TiXmlElement("HubLeadW");
	ProfileElement->LinkEndChild(HubLeadWElement);
	str.Format(L"%.3f", HubLeadW);
	TiXmlText *HubLeadWContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	HubLeadWElement->LinkEndChild(HubLeadWContent);

	//HubTrailW
	TiXmlElement *HubTrailWElement = new TiXmlElement("HubTrailW");
	ProfileElement->LinkEndChild(HubTrailWElement);
	str.Format(L"%.3f", HubTrailW);
	TiXmlText *HubTrailWContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	HubTrailWElement->LinkEndChild(HubTrailWContent);

	for (int k = 0; k < mProfileList.size(); ++k)
	{
		//LayerData
		TiXmlElement *LayerDataElement = new TiXmlElement("LayerData");
		ProfileElement->LinkEndChild(LayerDataElement);

		//Height
		TiXmlElement *LHeightElement = new TiXmlElement("Height");
		LayerDataElement->LinkEndChild(LHeightElement);
		str.Format(L"%.1f", mProfileList[k].Height);
		TiXmlText *LHeightContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		LHeightElement->LinkEndChild(LHeightContent);

		//LeadWidth
		TiXmlElement *LeadWidthElement = new TiXmlElement("LeadWidth");
		LayerDataElement->LinkEndChild(LeadWidthElement);
		str.Format(L"%.1f", mProfileList[k].LeadingWidth);
		TiXmlText *LeadWidthContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		LeadWidthElement->LinkEndChild(LeadWidthContent);

		//TrailWidth
		TiXmlElement *TrailWidthElement = new TiXmlElement("TrailWidth");
		LayerDataElement->LinkEndChild(TrailWidthElement);
		str.Format(L"%.1f", mProfileList[k].TrailingWidth);
		TiXmlText *TrailWidthContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		TrailWidthElement->LinkEndChild(TrailWidthContent);

	}

	return true;
}
