#include "stdafx.h"
#include "ClassShroud.h"
#include "tchar.h"
#include "Main.h"


CShroudData::CShroudData()
{

	Order = 0;
	mType = stator;
	isDiversion = false;
	mSrdType = StageTooth;

	ToothDistance.clear();

	ToothNum = 0;
	ToothW = 0;			
	ToothH = 0;			

	ET = 0;
	E = 0;
	H1 = 0;
	A1 = 0;
	B1 = 0;
	G = 0;
	HG1 = 0;
	DiversionA = 0;
	DiversionH = 0;
	S = 0;					

}

bool CShroudData::LoadXMLData(TiXmlElement* pElem)
{
	TiXmlElement* pElem1st;
	TiXmlElement* pElem2nd;

	for (pElem1st = pElem->FirstChildElement(); pElem1st != NULL; pElem1st = pElem1st->NextSiblingElement())
	{
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"shroudtype")
		{
			if (Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()).MakeLower() == L"stage")
			{
				mSrdType = StageTooth;
			}
			else if (Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()).MakeLower() == L"step")
			{
				mSrdType = StepTooth;
			}
			else
			{
				AfxMessageBox(L"XMLERROR-shroudtype");
				return false;
			}
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"isdiversion")
		{
			if (Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()).MakeLower() == L"true")
			{
				isDiversion = true;
			}
			else if (Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()).MakeLower() == L"false")
			{
				isDiversion = false;
			}
			else
			{
				AfxMessageBox(L"XMLERROR-isdiversion");
				return false;
			}
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"toothw")
		{
			ToothW = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"ToothW");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"toothh")
		{
			ToothH = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"ToothH");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"toothnum")
		{
			ToothNum = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"ToothNum");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"toothdis")
		{

			for (pElem2nd = pElem1st->FirstChildElement(); pElem2nd != NULL; pElem2nd = pElem2nd->NextSiblingElement())
			{

				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"distance")
				{
					ToothDistance.push_back(
						_wtof(Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value())));
					//AfxMessageBox(L"ProHeight");
					//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value()));
				}
			}
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"e")
		{
			E = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"E");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"h1")
		{
			H1 = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"H1");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"a1")
		{
			A1 = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"A1");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"b1")
		{
			B1 = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"B1");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"hg1")
		{
			HG1 = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"HG1");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"diversiona")
		{
			DiversionA = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"DiversionA");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"diversionh")
		{
			DiversionH = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
			//AfxMessageBox(L"DiversionH");
			//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

	}

	return true;
}

bool CShroudData::ExportXMLData(TiXmlElement* pElem)
{
	CString str;
	TiXmlElement *ShroudElement = new TiXmlElement("Shroud");
	pElem->LinkEndChild(ShroudElement);

	//IsDiversion
	TiXmlElement *IsDiversionElement = new TiXmlElement("IsDiversion");
	ShroudElement->LinkEndChild(IsDiversionElement);
	if (isDiversion == true)
		str = L"True";
	else if (isDiversion == false)
		str = L"False";
	TiXmlText *IsDiversionContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	IsDiversionElement->LinkEndChild(IsDiversionContent);

	//ShroudType
	TiXmlElement *ShroudTypeElement = new TiXmlElement("ShroudType");
	ShroudElement->LinkEndChild(ShroudTypeElement);
	if (mSrdType == StageTooth)
		str = L"Stage";
	else if (mSrdType == StepTooth)
		str = L"Step";
	TiXmlText *ShroudTypeContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	ShroudTypeElement->LinkEndChild(ShroudTypeContent);

	//ToothW
	if (ToothW != 0)
	{
		TiXmlElement *ToothWElement = new TiXmlElement("ToothW");
		ShroudElement->LinkEndChild(ToothWElement);
		str.Format(L"%.1f", ToothW);
		TiXmlText *ToothWContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		ToothWElement->LinkEndChild(ToothWContent);
	}

	//ToothH
	if (ToothH != 0)
	{
		TiXmlElement *ToothHElement = new TiXmlElement("ToothH");
		ShroudElement->LinkEndChild(ToothHElement);
		str.Format(L"%.1f", ToothH);
		TiXmlText *ToothHContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		ToothHElement->LinkEndChild(ToothHContent);
	}

	//ToothNum
	if (ToothNum != 0)
	{
		TiXmlElement *ToothNumElement = new TiXmlElement("ToothNum");
		ShroudElement->LinkEndChild(ToothNumElement);
		str.Format(L"%d", ToothNum);
		TiXmlText *ToothNumContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		ToothNumElement->LinkEndChild(ToothNumContent);
	}

	//ToothDistance
	if (ToothDistance.size() > 0)
	{
		TiXmlElement *ToothDistanceElement = new TiXmlElement("ToothDis");
		ShroudElement->LinkEndChild(ToothDistanceElement);

		for (int k = 0; k < ToothDistance.size(); ++k)
		{
			TiXmlElement *DistanceElement = new TiXmlElement("Distance");
			ToothDistanceElement->LinkEndChild(DistanceElement);
			str.Format(L"%.1f", ToothDistance[k]);
			TiXmlText *DistanceContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
			DistanceElement->LinkEndChild(DistanceContent);
		}
	}

	//ET
	if (ET != 0)
	{
		TiXmlElement *ETElement = new TiXmlElement("ET");
		ShroudElement->LinkEndChild(ETElement);
		str.Format(L"%.1f", ET);
		TiXmlText *ETContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		ETElement->LinkEndChild(ETContent);
	}

	//E
	if (E != 0)
	{
		TiXmlElement *EElement = new TiXmlElement("E");
		ShroudElement->LinkEndChild(EElement);
		str.Format(L"%.1f", E);
		TiXmlText *EContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		EElement->LinkEndChild(EContent);
	}

	//H1
	if (H1 != 0)
	{
		TiXmlElement *H1Element = new TiXmlElement("H1");
		ShroudElement->LinkEndChild(H1Element);
		str.Format(L"%.1f", H1);
		TiXmlText *H1Content = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		H1Element->LinkEndChild(H1Content);
	}

	//A1
	if (A1 != 0)
	{
		TiXmlElement *A1Element = new TiXmlElement("A1");
		ShroudElement->LinkEndChild(A1Element);
		str.Format(L"%.1f", A1);
		TiXmlText *A1Content = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		A1Element->LinkEndChild(A1Content);
	}

	//B1
	if (B1 != 0)
	{
		TiXmlElement *B1Element = new TiXmlElement("B1");
		ShroudElement->LinkEndChild(B1Element);
		str.Format(L"%.1f", B1);
		TiXmlText *B1Content = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		B1Element->LinkEndChild(B1Content);
	}

	//G
	if (G != 0)
	{
		TiXmlElement *GElement = new TiXmlElement("G");
		ShroudElement->LinkEndChild(GElement);
		str.Format(L"%.1f", G);
		TiXmlText *GContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		GElement->LinkEndChild(GContent);
	}

	//HG1
	if (HG1 != 0)
	{
		TiXmlElement *HG1Element = new TiXmlElement("HG1");
		ShroudElement->LinkEndChild(HG1Element);
		str.Format(L"%.1f", HG1);
		TiXmlText *HG1Content = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		HG1Element->LinkEndChild(HG1Content);
	}

	//DiversionA
	if (DiversionA != 0)
	{
		TiXmlElement *DiversionAElement = new TiXmlElement("DiversionA");
		ShroudElement->LinkEndChild(DiversionAElement);
		str.Format(L"%.1f", DiversionA);
		TiXmlText *DiversionAContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		DiversionAElement->LinkEndChild(DiversionAContent);
	}

	//DiversionH
	if (DiversionH != 0)
	{
		TiXmlElement *DiversionHElement = new TiXmlElement("DiversionH");
		ShroudElement->LinkEndChild(DiversionHElement);
		str.Format(L"%.1f", DiversionH);
		TiXmlText *DiversionHContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		DiversionHElement->LinkEndChild(DiversionHContent);
	}

	return true;
}

