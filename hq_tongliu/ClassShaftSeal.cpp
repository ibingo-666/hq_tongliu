#include "stdafx.h"
#include "ClassShaftSeal.h"
#include "tchar.h"
#include "Main.h"



CGlandSealData::CGlandSealData()
{
	mSTData.clear();

	SSA = 0;
	SSB = 0;
	SSC = 0;
	SSD = 0;
	SSF = 0;
	SSG = 0;
	SSH = 0;
	SSL = 0;
	SSM = 0;
	SSN = 0;
	SSP = 0;
	SSQ = 0;
	SSR = 0;
	SSX = 0;
	SSY = 0;


}

CGlandSealData::~CGlandSealData()
{

}

CShaftSealData::CShaftSealData()
{
	mGlandSeal = new CGlandSealData();

	mGlandSealNum = 0;					
	mShaftSealType = Stage;				
	mShaftSealLocation = Leading;		
	mRealToothNum = 0;					
	mShaftSealLength = 0.0;				
	mShaftSealRadius = 0.0;				
	mAxialX = 0.0;						

}

CShaftSealData::~CShaftSealData()
{

}

bool CShaftSealData::LoadXMLData(TiXmlElement* pElem)
{

	TiXmlElement* pElem1st;
	TiXmlElement* pElem2nd;
	//TiXmlElement* pElem3rd;

	for (pElem1st = pElem->FirstChildElement(); pElem1st != NULL; pElem1st = pElem1st->NextSiblingElement())
	{
		//ShaftType
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"shafttype")
		{
			CString TempStr = Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value());
			if (TempStr.MakeLower() == L"stage")
			{
				mShaftSealType = Stage;
			}
			else if (TempStr.MakeLower() == L"flat")
			{
				mShaftSealType = Flat;
			}
			else if (TempStr.MakeLower() == L"cross")
			{
				mShaftSealType = Cross;
			}
			else if (TempStr.MakeLower() == L"relative")
			{
				mShaftSealType = Relative;
			}
			else
			{
				return false;
			}
		}

		//SSLocation
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"sslocation")
		{
			CString TempStr = Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value());
			if (TempStr.MakeLower() == L"leading")
			{
				mShaftSealLocation = Leading;
			}
			else if (TempStr.MakeLower() == L"trailing")
			{
				mShaftSealLocation = Trailing;
			}
			else
			{
				//AfxMessageBox(L"Testfalse");

				return false;
			}
		}

		//RealToothNum
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"realtoothnum")
		{
			mRealToothNum = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));

		}

		//AxialX
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"axialx")
		{
			mAxialX = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		//GlandSealNum
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"glandsealnum")
		{
			mGlandSealNum = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		//ShaftSealLength
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"shaftseallength")
		{
			mShaftSealLength = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		//ShaftSealRadius
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"shaftsealradius")
		{
			mShaftSealRadius = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"glandseal")
		{
			//CGlandSealData* tmpGlandSealData = new CGlandSealData;
			//AfxMessageBox(L"Test3");

			for (pElem2nd = pElem1st->FirstChildElement(); pElem2nd != NULL; pElem2nd = pElem2nd->NextSiblingElement())
			{
				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"ssa")
				{
					mGlandSeal->SSA = _wtof(Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value()));
				}
				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"ssb")
				{
					mGlandSeal->SSB = _wtof(Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value()));
				}
				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"ssc")
				{
					mGlandSeal->SSC = _wtof(Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value()));
				}
				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"ssd")
				{
					mGlandSeal->SSD = _wtof(Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value()));
				}
				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"ssf")
				{
					mGlandSeal->SSF = _wtof(Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value()));
				}
				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"ssg")
				{
					mGlandSeal->SSG = _wtof(Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value()));
				}
				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"ssh")
				{
					mGlandSeal->SSH = _wtof(Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value()));
				}
				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"ssl")
				{
					mGlandSeal->SSL = _wtof(Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value()));
				}
				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"ssm")
				{
					mGlandSeal->SSM = _wtof(Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value()));
				}
				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"ssn")
				{
					mGlandSeal->SSN = _wtof(Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value()));
				}
				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"ssp")
				{
					mGlandSeal->SSP = _wtof(Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value()));
				}
				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"ssq")
				{
					mGlandSeal->SSQ = _wtof(Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value()));
				}
				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"ssr")
				{
					mGlandSeal->SSR = _wtof(Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value()));
				}
				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"ssx")
				{
					mGlandSeal->SSX = _wtof(Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value()));
				}
				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"ssy")
				{
					mGlandSeal->SSY = _wtof(Data->MyFunction->Basic->Char2CString(pElem2nd->FirstChild()->Value()));
				}


				if (Data->MyFunction->Basic->Char2CString(pElem2nd->Value()).MakeLower() == L"sealtooth")
				{


					CSealToothData* tSTData = new CSealToothData;
					tSTData->LoadXMLData(pElem2nd);

					mGlandSeal->mSTData.push_back(tSTData);
				}
			}
		}

	}

	return true;
}

bool CShaftSealData::ExportXMLData(TiXmlElement* pElem)
{

	CString str;
	TiXmlElement *ShaftSealElement = new TiXmlElement("ShaftSeal");
	pElem->LinkEndChild(ShaftSealElement);


	//ShaftType
	TiXmlElement *ShaftTypeElement = new TiXmlElement("ShaftType");
	ShaftSealElement->LinkEndChild(ShaftTypeElement);
	if (mShaftSealType == Stage)
		str = L"Stage";
	else if (mShaftSealType == Flat)
		str = L"Flat";
	else if (mShaftSealType == Cross)
		str = L"Cross";
	else if (mShaftSealType == Relative)
		str = L"Relative";
	else
		return false;
	TiXmlText *ShaftTypeContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	ShaftTypeElement->LinkEndChild(ShaftTypeContent);

	//SSLocation
	TiXmlElement *SSLocationElement = new TiXmlElement("SSLocation");
	ShaftSealElement->LinkEndChild(SSLocationElement);
	if (mShaftSealLength == Leading)
		str = L"Leading";
	else if (mShaftSealLength == Trailing)
		str = L"Trailing";
	else
		return false;
	TiXmlText *SSLocationContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	SSLocationElement->LinkEndChild(SSLocationContent);

	//RealToothNum
	TiXmlElement *RealToothNumElement = new TiXmlElement("RealToothNum");
	ShaftSealElement->LinkEndChild(RealToothNumElement);
	str.Format(L"%d", mRealToothNum);
	TiXmlText *RealToothNumContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	RealToothNumElement->LinkEndChild(RealToothNumContent);

	//AxialX
	TiXmlElement *AxialXElement = new TiXmlElement("AxialX");
	ShaftSealElement->LinkEndChild(AxialXElement);
	str.Format(L"%0.3f", mAxialX);
	TiXmlText *AxialXContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	AxialXElement->LinkEndChild(AxialXContent);

	//GlandSealNum
	TiXmlElement *GlandSealNumElement = new TiXmlElement("GlandSealNum");
	ShaftSealElement->LinkEndChild(GlandSealNumElement);
	str.Format(L"%d", mGlandSealNum);
	TiXmlText *GlandSealNumContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	GlandSealNumElement->LinkEndChild(GlandSealNumContent);

	//ShaftSealLength
	TiXmlElement *ShaftSealLengthElement = new TiXmlElement("ShaftSealLength");
	ShaftSealElement->LinkEndChild(ShaftSealLengthElement);
	str.Format(L"%0.3f", mShaftSealLength);
	TiXmlText *ShaftSealLengthContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	ShaftSealLengthElement->LinkEndChild(ShaftSealLengthContent);

	//ShaftSealRadius
	TiXmlElement *ShaftSealRadiusElement = new TiXmlElement("ShaftSealRadius");
	ShaftSealElement->LinkEndChild(ShaftSealRadiusElement);
	str.Format(L"%0.3f", mShaftSealRadius);
	TiXmlText *ShaftSealRadiusContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	ShaftSealRadiusElement->LinkEndChild(ShaftSealRadiusContent);


	//GlandSeal
	TiXmlElement *GlandSealElement = new TiXmlElement("GlandSeal");
	ShaftSealElement->LinkEndChild(GlandSealElement);

	//SSA
	TiXmlElement *SSAElement = new TiXmlElement("SSA");
	GlandSealElement->LinkEndChild(SSAElement);
	str.Format(L"%0.3f", mGlandSeal->SSA);
	TiXmlText *SSAContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	SSAElement->LinkEndChild(SSAContent);

	//SSB
	TiXmlElement *SSBElement = new TiXmlElement("SSB");
	GlandSealElement->LinkEndChild(SSBElement);
	str.Format(L"%0.3f", mGlandSeal->SSB);
	TiXmlText *SSBContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	SSBElement->LinkEndChild(SSBContent);

	//SSC
	TiXmlElement *SSCElement = new TiXmlElement("SSC");
	GlandSealElement->LinkEndChild(SSCElement);
	str.Format(L"%0.3f", mGlandSeal->SSC);
	TiXmlText *SSCContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	SSCElement->LinkEndChild(SSCContent);

	//SSD
	TiXmlElement *SSDElement = new TiXmlElement("SSD");
	GlandSealElement->LinkEndChild(SSDElement);
	str.Format(L"%0.3f", mGlandSeal->SSD);
	TiXmlText *SSDContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	SSDElement->LinkEndChild(SSDContent);

	//SSF
	TiXmlElement *SSFElement = new TiXmlElement("SSF");
	GlandSealElement->LinkEndChild(SSFElement);
	str.Format(L"%0.3f", mGlandSeal->SSF);
	TiXmlText *SSFContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	SSFElement->LinkEndChild(SSFContent);

	//SSG
	TiXmlElement *SSGElement = new TiXmlElement("SSG");
	GlandSealElement->LinkEndChild(SSGElement);
	str.Format(L"%0.3f", mGlandSeal->SSG);
	TiXmlText *SSGContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	SSGElement->LinkEndChild(SSGContent);

	//SSH
	TiXmlElement *SSHElement = new TiXmlElement("SSH");
	GlandSealElement->LinkEndChild(SSHElement);
	str.Format(L"%0.3f", mGlandSeal->SSH);
	TiXmlText *SSHContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	SSHElement->LinkEndChild(SSHContent);

	//SSL
	TiXmlElement *SSLElement = new TiXmlElement("SSL");
	GlandSealElement->LinkEndChild(SSLElement);
	str.Format(L"%0.3f", mGlandSeal->SSL);
	TiXmlText *SSLContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	SSLElement->LinkEndChild(SSLContent);

	//SSM
	TiXmlElement *SSMElement = new TiXmlElement("SSM");
	GlandSealElement->LinkEndChild(SSMElement);
	str.Format(L"%0.3f", mGlandSeal->SSM);
	TiXmlText *SSMContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	SSMElement->LinkEndChild(SSMContent);

	//SSN
	TiXmlElement *SSNElement = new TiXmlElement("SSN");
	GlandSealElement->LinkEndChild(SSNElement);
	str.Format(L"%0.3f", mGlandSeal->SSN);
	TiXmlText *SSNContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	SSNElement->LinkEndChild(SSNContent);

	//SSP
	TiXmlElement *SSPElement = new TiXmlElement("SSP");
	GlandSealElement->LinkEndChild(SSPElement);
	str.Format(L"%0.3f", mGlandSeal->SSP);
	TiXmlText *SSPContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	SSPElement->LinkEndChild(SSPContent);

	//SSR
	TiXmlElement *SSRElement = new TiXmlElement("SSR");
	GlandSealElement->LinkEndChild(SSRElement);
	str.Format(L"%0.3f", mGlandSeal->SSR);
	TiXmlText *SSRContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	SSRElement->LinkEndChild(SSRContent);

	//SSQ
	TiXmlElement *SSQElement = new TiXmlElement("SSQ");
	GlandSealElement->LinkEndChild(SSQElement);
	str.Format(L"%0.3f", mGlandSeal->SSQ);
	TiXmlText *SSQContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	SSQElement->LinkEndChild(SSQContent);

	//SSX
	TiXmlElement *SSXElement = new TiXmlElement("SSX");
	GlandSealElement->LinkEndChild(SSXElement);
	str.Format(L"%0.3f", mGlandSeal->SSX);
	TiXmlText *SSXContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	SSXElement->LinkEndChild(SSXContent);

	//SSY
	TiXmlElement *SSYElement = new TiXmlElement("SSY");
	GlandSealElement->LinkEndChild(SSYElement);
	str.Format(L"%0.3f", mGlandSeal->SSY);
	TiXmlText *SSYContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	SSYElement->LinkEndChild(SSYContent);

	if (mGlandSeal->mSTData.size() > 0)
	{

		for (int j = 0; j < mGlandSeal->mSTData.size(); ++j)
		{
			mGlandSeal->mSTData[j]->ExportXMLData(GlandSealElement);
		}

	}

	return true;
}
