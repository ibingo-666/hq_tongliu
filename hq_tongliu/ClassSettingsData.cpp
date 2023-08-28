#include "stdafx.h"
#include "ClassSettingsData.h"
#include "tchar.h"
#include "Main.h"

CSettingsData::CSettingsData()
{
	mVersion = 0.0;				
	mTLType = reaction;			
	mDisplayType = All;	
	mPresType = SuperHighPressure;
	BladePairNum = 0;				
	BladeDirect = true;			
	BladeSmooth = true;			
	SmoothD1 = 0;
	SmoothD2 = 0;


}


CSettingsData::~CSettingsData()
{
}

bool CSettingsData::LoadXMLData(TiXmlElement* pElem)
{

	TiXmlElement* pElem1st;
	TiXmlElement* pElem2nd;
	TiXmlElement* pElem3rd;


	for (pElem1st = pElem->FirstChildElement(); pElem1st != NULL; pElem1st = pElem1st->NextSiblingElement())
	{
		//version
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"version")
		{
			mVersion = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		//TLtype
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"type")
		{
			CString TempStr = Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value());
			if (TempStr.MakeLower() == L"reaction")
			{
				mTLType = reaction;
			}
			else if (TempStr.MakeLower() == L"impulse")
			{
				mTLType = impulse;
			}
			else
			{
				AfxMessageBox(L"XMLERROR-type");
				return false;
			}
		}

		//DisplayType
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"displaytype")
		{
			CString TempStr = Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value());
			if (TempStr.MakeLower() == L"all")
			{
				mDisplayType = All;
			}
			else if (TempStr.MakeLower() == L"rotor")
			{
				mDisplayType = Rotor;
			}
			else if (TempStr.MakeLower() == L"stator")
			{
				mDisplayType = Stator;
			}
			else
			{
				AfxMessageBox(L"XMLERROR-displaytype");
				return false;
			}
		}

		//Pressuretype
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"pressuretype")
		{
			CString TempStr = Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value());
			if (TempStr.MakeLower() == L"superhighpressure")
			{
				mPresType = SuperHighPressure;
			}
			else if (TempStr.MakeLower() == L"highpressure")
			{
				mPresType = HighPressure;
			}
			else if (TempStr.MakeLower() == L"mediumpressure")
			{
				mPresType = MediumPressure;
			}
			else if (TempStr.MakeLower() == L"lowpressure")
			{
				mPresType = LowPressure;
			}
		}

		//cylindertype
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"cylindertype")
		{
			mCylinderType = Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value());
		}


		//bladenum
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"bladepairnum")
		{
			BladePairNum = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		//direction
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"direction")
		{
			CString TempStr = Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value());
			if (TempStr.MakeLower() == L"right")
			{
				BladeDirect = false;
			}
			else if (TempStr.MakeLower() == L"left")
			{
				BladeDirect = true;
			}
			else
			{
				AfxMessageBox(L"XMLERROR-direction");
				return false;
			}
		}

		//bladesmooth
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"issmooth")
		{
			CString TempStr = Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value());
			if (TempStr.MakeLower() == L"true")
			{
				BladeSmooth = true;
			}
			else if (TempStr.MakeLower() == L"false")
			{
				BladeSmooth = false;
			}
			else
			{
				AfxMessageBox(L"XMLERROR-issmooth");
				return false;
			}
		}

		//SmoothD1
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"smoothd1")
		{
			SmoothD1 = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		//SmoothD2
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"smoothd2")
		{
			SmoothD2 = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}


	}
	return 0;
}

bool CSettingsData::ExportXMLData(TiXmlElement* pElem)
{
	CString str;

	TiXmlElement *SettingElement = new TiXmlElement("Setting");
	pElem->LinkEndChild(SettingElement);



	//Version
	TiXmlElement *VersionElement = new TiXmlElement("Version");
	SettingElement->LinkEndChild(VersionElement);
	str.Format(L"%.2f", mVersion);
	TiXmlText *VersionContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	VersionElement->LinkEndChild(VersionContent);

	//TLType
	TiXmlElement *TypeElement = new TiXmlElement("Type");
	SettingElement->LinkEndChild(TypeElement);
	if (mTLType == reaction)
		str = L"Reaction";
	else if (mTLType == impulse)
		str = L"Impulse";
	TiXmlText *TypeContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	TypeElement->LinkEndChild(TypeContent);

	//DisplayType
	TiXmlElement *DisplayTypeElement = new TiXmlElement("DisplayType");
	SettingElement->LinkEndChild(DisplayTypeElement);
	if (mDisplayType == All)
		str = L"All";
	else if (mDisplayType == Rotor)
		str = L"Rotor";
	else if (mDisplayType == Stator)
		str = L"Stator";
	TiXmlText *DisplayTypeContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	DisplayTypeElement->LinkEndChild(DisplayTypeContent);

	//PressType
	TiXmlElement *PressureTypeElement = new TiXmlElement("PressureType");
	SettingElement->LinkEndChild(PressureTypeElement);
	if (mPresType == SuperHighPressure)
		str = L"SuperHighPressure";
	else if (mPresType == HighPressure)
		str = L"HighPressure";
	else if (mPresType == MediumPressure)
		str = L"MediumPressure";
	else if (mPresType == LowPressure)
		str = L"LowPressure";
	TiXmlText *PressureTypeContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	PressureTypeElement->LinkEndChild(PressureTypeContent);

	// CylinderType
	TiXmlElement *CylinderTypeElement = new TiXmlElement("CylinderType");
	SettingElement->LinkEndChild(CylinderTypeElement);
	TiXmlText *CylinderTypeContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(mCylinderType));
	CylinderTypeElement->LinkEndChild(CylinderTypeContent);



	//BladePairNum
	TiXmlElement *BladeNumElement = new TiXmlElement("BladePairNum");
	SettingElement->LinkEndChild(BladeNumElement);
	str.Format(L"%d", BladePairNum);
	TiXmlText *BladeNumContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	BladeNumElement->LinkEndChild(BladeNumContent);


	//Direction
	TiXmlElement *DirectionElement = new TiXmlElement("Direction");
	SettingElement->LinkEndChild(DirectionElement);
	if (BladeDirect == true)
		str = L"Left";
	else if (BladeDirect == false)
		str = L"Right";
	TiXmlText *DirectionContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	DirectionElement->LinkEndChild(DirectionContent);

	//BladeSmooth
	TiXmlElement *BladeSmoothElement = new TiXmlElement("IsSmooth");
	SettingElement->LinkEndChild(BladeSmoothElement);
	if (BladeSmooth == true)
		str = L"True";
	else if (BladeSmooth == false)
		str = L"False";
	TiXmlText *BladeSmoothContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	BladeSmoothElement->LinkEndChild(BladeSmoothContent);

	//SmoothD1
	TiXmlElement *SmoothD1Element = new TiXmlElement("SmoothD1");
	SettingElement->LinkEndChild(SmoothD1Element);
	str.Format(L"%.1f", SmoothD1);
	TiXmlText *SmoothD1Content = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	SmoothD1Element->LinkEndChild(SmoothD1Content);

	//SmoothD2
	TiXmlElement *SmoothD2Element = new TiXmlElement("SmoothD2");
	SettingElement->LinkEndChild(SmoothD2Element);
	str.Format(L"%.1f", SmoothD2);
	TiXmlText *SmoothD2Content = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	SmoothD2Element->LinkEndChild(SmoothD2Content);

	return true;
}
