#include "stdafx.h"
#include "ClassBlade.h"
#include "tchar.h"
#include <math.h>
#include "main.h"


bool CBladePairData::LoadXMLData(TiXmlElement* pElem)
{

	TiXmlElement* pElem1st;
	TiXmlElement* pElem2nd;
	TiXmlElement* pElem3rd;

	for (pElem1st = pElem->FirstChildElement(); pElem1st != NULL; pElem1st = pElem1st->NextSiblingElement())
	{

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"brclr")
		{
			BRCLR = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"brcll")
		{
			BRCLL = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"g1")
		{
			G1 = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"g2")
		{
			G2 = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"blade")
		{
			CBladeData* tempBladeData = new CBladeData;


			for (pElem2nd = pElem1st->FirstChildElement(); pElem2nd != NULL; pElem2nd = pElem2nd->NextSiblingElement())
			{
				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"bladetype")
				{
					CString TempStr = Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value());
					if (TempStr.MakeLower() == L"rotor")
					{
						tempBladeData = mRotor;
						//tempBladeData->mType = rotor;
					}
					else if (TempStr.MakeLower() == L"stator")
					{
						tempBladeData = mStator;
						//tempBladeData->mType = stator;
					}
					else
					{
						AfxMessageBox(L"XMLERROR-bladetype");
						return false;
					}
				}
				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"location")
				{

					for (pElem3rd = pElem2nd->FirstChildElement(); pElem3rd != NULL; pElem3rd = pElem3rd->NextSiblingElement())
					{
						if (Data->MyFunction->Basic->Char2CString(pElem3rd->Value()).MakeLower() == L"radialh")
						{
							tempBladeData->RelaCoor.y = _wtof(Data->MyFunction->Basic->Char2CString(pElem3rd->FirstChild()->Value())) / 2.0;
						}

						if (Data->MyFunction->Basic->Char2CString(pElem3rd->Value()).MakeLower() == L"axialx")
						{
							tempBladeData->RelaCoor.x = _wtof(Data->MyFunction->Basic->Char2CString(pElem3rd->FirstChild()->Value()));
							//AfxMessageBox(L"CoorX");
							//AfxMessageBox(Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value()));
						}

					}
				}

				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"profile")
				{
					tempBladeData->mBlade->LoadXMLData(pElem2nd);

				}

				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"statorhub"
					|| Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"rotorhub")
				{
					tempBladeData->mHub->LoadXMLData(pElem2nd);
				}

				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"shroud")
				{
					tempBladeData->mShroud->LoadXMLData(pElem2nd);
				}

				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"bulkhead")
				{
					tempBladeData->mBulkHead->LoadXMLData(pElem2nd);
				}
			}

		}

		//StatorToothList
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"statortoothlist")
		{

			for (pElem2nd = pElem1st->FirstChildElement(); pElem2nd != NULL; pElem2nd = pElem2nd->NextSiblingElement())
			{
				CSealToothData* tSTData = new CSealToothData;
				tSTData->LoadXMLData(pElem2nd);

				mStatorToothList.push_back(tSTData);
			}

		}

		//RotorToothList
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"rotortoothlist")
		{

			for (pElem2nd = pElem1st->FirstChildElement(); pElem2nd != NULL; pElem2nd = pElem2nd->NextSiblingElement())
			{
				CSealToothData* tSTData = new CSealToothData;
				tSTData->LoadXMLData(pElem2nd);

				mRotorToothList.push_back(tSTData);
			}
		}


	}

	return true;
}

bool CBladePairData::ExportXMLData(TiXmlElement* pElem)
{
	CString str;

	//BladePair
	TiXmlElement *BladePairElement = new TiXmlElement("BladePair");
	pElem->LinkEndChild(BladePairElement);

	TLType tTLType = Data->MainData->mSettings->mTLType;
	if (tTLType == reaction)
	{
		//BRCLR
		TiXmlElement *BRCLRElement = new TiXmlElement("BRCLR");
		BladePairElement->LinkEndChild(BRCLRElement);
		str.Format(L"%.1f", BRCLR);
		TiXmlText *BRCLRContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		BRCLRElement->LinkEndChild(BRCLRContent);

		//BRCLL
		TiXmlElement *BRCLLElement = new TiXmlElement("BRCLL");
		BladePairElement->LinkEndChild(BRCLLElement);
		str.Format(L"%.1f", BRCLL);
		TiXmlText *BRCLLContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		BRCLLElement->LinkEndChild(BRCLLContent);

		//G1
		TiXmlElement *G1Element = new TiXmlElement("G1");
		BladePairElement->LinkEndChild(G1Element);
		str.Format(L"%.1f", G1);
		TiXmlText *G1Content = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		G1Element->LinkEndChild(G1Content);

		//G2
		TiXmlElement *G2Element = new TiXmlElement("G2");
		BladePairElement->LinkEndChild(G2Element);
		str.Format(L"%.1f", G2);
		TiXmlText *G2Content = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		G2Element->LinkEndChild(G2Content);



	}

	for (int j = 0; j < 2; ++j)
	{
		CBladeData* tmpBladeData;
		if (j == 0)
		{
			tmpBladeData = mStator;
			str = L"stator";
		}
		if (j == 1)
		{
			tmpBladeData = mRotor;
			str = L"rotor";
		}

		TiXmlElement *BladeElement = new TiXmlElement("Blade");
		BladePairElement->LinkEndChild(BladeElement);

		//BladeType
		TiXmlElement *BladeTypeElement = new TiXmlElement("BladeType");
		BladeElement->LinkEndChild(BladeTypeElement);
		TiXmlText *BladeTypeContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		BladeTypeElement->LinkEndChild(BladeTypeContent);

		//Location
		TiXmlElement *LocationElement = new TiXmlElement("Location");
		BladeElement->LinkEndChild(LocationElement);

		//AxialX
		TiXmlElement *AxialXElement = new TiXmlElement("AxialX");
		LocationElement->LinkEndChild(AxialXElement);
		str.Format(L"%.1f", tmpBladeData->RelaCoor.x);
		TiXmlText *AxialXContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		AxialXElement->LinkEndChild(AxialXContent);

		//RadialH
		TiXmlElement *RadialHElement = new TiXmlElement("RadialH");
		LocationElement->LinkEndChild(RadialHElement);
		str.Format(L"%.1f", tmpBladeData->RelaCoor.y * 2);
		TiXmlText *RadialHContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		RadialHElement->LinkEndChild(RadialHContent);


		//Profile
		tmpBladeData->mBlade->ExportXMLData(BladeElement);

		//////////////////////////////


		if (j == 0 && tTLType == impulse)
		{
			//BulkHead
			tmpBladeData->mBulkHead->ExportXMLData(BladeElement);
		}
		else
		{
			//Hub
			tmpBladeData->mHub->ExportXMLData(BladeElement, j);

			////////////////////////////////////

			//Shroud
			tmpBladeData->mShroud->ExportXMLData(BladeElement);
		}



	}

	//StatorToothList
	if (mStatorToothList.size() > 0)
	{
		TiXmlElement *StatorToothListElement = new TiXmlElement("StatorToothList");
		BladePairElement->LinkEndChild(StatorToothListElement);

		for (int j = 0; j < mStatorToothList.size(); ++j)
		{
			mStatorToothList[j]->ExportXMLData(StatorToothListElement);
		}

	}


	//RotorToothList
	if (mRotorToothList.size() > 0)
	{
		TiXmlElement *RotorToothListElement = new TiXmlElement("RotorToothList");
		BladePairElement->LinkEndChild(RotorToothListElement);

		for (int j = 0; j < mRotorToothList.size(); ++j)
		{
			mRotorToothList[j]->ExportXMLData(RotorToothListElement);
		}

	}


	return true;
}

CBladePairData::CBladePairData()
{
	Order = 0;
	mRotor = new CBladeData();
	mStator = new CBladeData();
	BRCLR = 0;
	BRCLL = 0;
	TRCLR = 0;
	TRCLL = 0;
	G1 = 0;
	G2 = 0;
	mStatorToothList.clear();	
	mRotorToothList.clear();

}

CBladeData::CBladeData()
{
	mBlade = new CProfileData();
	mHub = new CHubData();
	mShroud = new CShroudData();
	mBulkHead = new CBulkheadData();
	int					Order = 0;					
	BladeType			mType = stator;
	AcGePoint3d			RelaCoor;				

}
