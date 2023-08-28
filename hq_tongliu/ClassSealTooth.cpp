#include "stdafx.h"
#include "ClassSealTooth.h"
#include "tchar.h"
#include "Main.h"


CSealToothData::CSealToothData()
{
	ToothType = 0;
	ToothL = 0;
	ToothX = 0;

	ToothRightW = 0;
	ToothLeftW = 0;

}

CSealToothData::~CSealToothData()
{

}

bool CSealToothData::LoadXMLData(TiXmlElement* pElem)
{
	TiXmlElement* pElem1st;

	for (pElem1st = pElem->FirstChildElement(); pElem1st != NULL; pElem1st = pElem1st->NextSiblingElement())
	{
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"toothtype")
		{
			ToothType = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"toothl")
		{
			ToothL = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"toothx")
		{
			ToothX = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"toothrightw")
		{
			ToothRightW = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"toothleftw")
		{
			ToothLeftW = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}
	}
	return true;
}

bool CSealToothData::ExportXMLData(TiXmlElement* pElem)
{
	CString str;
	//SealTooth
	TiXmlElement *SealToothElement = new TiXmlElement("SealTooth");
	pElem->LinkEndChild(SealToothElement);

	//ToothType
	TiXmlElement *ToothTypeElement = new TiXmlElement("ToothType");
	SealToothElement->LinkEndChild(ToothTypeElement);
	str.Format(L"%d", ToothType);
	TiXmlText *ToothTypeContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	ToothTypeElement->LinkEndChild(ToothTypeContent);

	//ToothL
	TiXmlElement *ToothLElement = new TiXmlElement("ToothL");
	SealToothElement->LinkEndChild(ToothLElement);
	str.Format(L"%.1f", ToothL);
	TiXmlText *ToothLContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	ToothLElement->LinkEndChild(ToothLContent);

	//ToothX
	TiXmlElement *ToothXElement = new TiXmlElement("ToothX");
	SealToothElement->LinkEndChild(ToothXElement);
	str.Format(L"%.1f", ToothX);
	TiXmlText *ToothXContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	ToothXElement->LinkEndChild(ToothXContent);

	//ToothRightW
	TiXmlElement *ToothRightWElement = new TiXmlElement("ToothRightW");
	SealToothElement->LinkEndChild(ToothRightWElement);
	str.Format(L"%.1f", ToothRightW);
	TiXmlText *ToothRightWContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	ToothRightWElement->LinkEndChild(ToothRightWContent);

	//ToothLeftW
	TiXmlElement *ToothLeftWElement = new TiXmlElement("ToothLeftW");
	SealToothElement->LinkEndChild(ToothLeftWElement);
	str.Format(L"%.1f", ToothLeftW);
	TiXmlText *ToothLeftWContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	ToothLeftWElement->LinkEndChild(ToothLeftWContent);

	return true;
}



