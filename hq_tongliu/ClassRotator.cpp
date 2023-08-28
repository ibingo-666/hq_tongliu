#include "stdafx.h"
#include "ClassRotator.h"
#include "Main.h"

CRotatorData::CRotatorData()
{		
	SecLength = 0;	
	SecRadius = 0;	
	FilletType = 0;	
	FilletX = 0;	
	FilletA = 0;	
	FilletB = 0;	
	FilletC = 0;

}

CRotatorData::~CRotatorData()
{

}

bool CRotatorData::LoadXMLData(TiXmlElement* pElem)
{


	TiXmlElement* pElem1st;


	for (pElem1st = pElem->FirstChildElement(); pElem1st != NULL; pElem1st = pElem1st->NextSiblingElement())
	{
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"secname")
		{
			SecName = Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value());

		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"seclength")
		{
			SecLength = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"secradius")
		{
			SecRadius = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"fillettype")
		{
			FilletType = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"filletx")
		{
			FilletX = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"filleta")
		{
			FilletA = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"filletb")
		{
			FilletB = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"filletc")
		{
			FilletC = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}
	}


	return true;
}

bool CRotatorData::ExportXMLData(TiXmlElement* pElem)
{
	CString str;
	//RotatorData
	TiXmlElement *RotatorDataElement = new TiXmlElement("RotatorData");
	pElem->LinkEndChild(RotatorDataElement);

	//SecName
	TiXmlElement *SecNameElement = new TiXmlElement("SecName");
	RotatorDataElement->LinkEndChild(SecNameElement);
	TiXmlText *SecNameContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(SecName));
	SecNameElement->LinkEndChild(SecNameContent);

	//SecLength
	TiXmlElement *SecLengthElement = new TiXmlElement("SecLength");
	RotatorDataElement->LinkEndChild(SecLengthElement);
	str.Format(L"%.1f", SecLength);
	TiXmlText *SecLengthContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	SecLengthElement->LinkEndChild(SecLengthContent);

	//SecRadius
	TiXmlElement *SecRadiusElement = new TiXmlElement("SecRadius");
	RotatorDataElement->LinkEndChild(SecRadiusElement);
	str.Format(L"%.1f", SecRadius);
	TiXmlText *SecRadiusContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	SecRadiusElement->LinkEndChild(SecRadiusContent);

	//FilletType
	TiXmlElement *FilletTypeElement = new TiXmlElement("FilletType");
	RotatorDataElement->LinkEndChild(FilletTypeElement);
	str.Format(L"%d", FilletType);
	TiXmlText *FilletTypeContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	FilletTypeElement->LinkEndChild(FilletTypeContent);

	//FilletX
	TiXmlElement *FilletXElement = new TiXmlElement("FilletX");
	RotatorDataElement->LinkEndChild(FilletXElement);
	str.Format(L"%.1f", FilletX);
	TiXmlText *FilletXContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	FilletXElement->LinkEndChild(FilletXContent);

	//FilletA
	TiXmlElement *FilletAElement = new TiXmlElement("FilletA");
	RotatorDataElement->LinkEndChild(FilletAElement);
	str.Format(L"%.1f", FilletA);
	TiXmlText *FilletAContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	FilletAElement->LinkEndChild(FilletAContent);

	//FilletB
	TiXmlElement *FilletBElement = new TiXmlElement("FilletB");
	RotatorDataElement->LinkEndChild(FilletBElement);
	str.Format(L"%.1f", FilletB);
	TiXmlText *FilletBContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	FilletBElement->LinkEndChild(FilletBContent);

	//FilletC
	TiXmlElement *FilletCElement = new TiXmlElement("FilletC");
	RotatorDataElement->LinkEndChild(FilletCElement);
	str.Format(L"%.1f", FilletC);
	TiXmlText *FilletCContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	FilletCElement->LinkEndChild(FilletCContent);

	return true;
}
