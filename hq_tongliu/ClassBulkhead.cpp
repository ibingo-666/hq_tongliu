#include "stdafx.h"
#include "ClassBulkhead.h"

#include<string.h>
#include <io.h>
#include <cstdlib>
#include "tchar.h"
#include "Main.h"
#include <math.h>

CBulkheadData::CBulkheadData()
{

	A = 0;
	B = 0;
	C = 0;
	D = 0;
	E = 0;
	F = 0;

	L = 0;
	M = 0;
	N = 0;
	P = 0;
	Q = 0;
	
	X1 = 0;
	X2 = 0;
	X3 = 0;
	Y = 0;
	Y3= 0;

	mBulkHeadToothList.clear();
}


CBulkheadData::~CBulkheadData()
{
}



bool CBulkheadData::LoadXMLData(TiXmlElement* pElem)
{
	TiXmlElement* pElem1st;
	TiXmlElement* pElem2nd;

	for (pElem1st = pElem->FirstChildElement(); pElem1st != NULL; pElem1st = pElem1st->NextSiblingElement())
	{

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"bulkheadtype")
		{
			if (Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()).MakeLower() == L"bact_type")
			{
				mBulkHeadType = Bact_Type;
			}
			else if (Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()).MakeLower() == L"fir_type")
			{
				mBulkHeadType = Fir_Type;
			}
			else if (Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()).MakeLower() == L"t_type")
			{
				mBulkHeadType = T_Type;
			}
			else 
			{
				AfxMessageBox(L"XMLERROR-BulkHead");
				return false;
			}
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"a")
		{
			A = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"b")
		{
			B = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"c")
		{
			C = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"d")
		{
			D = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"e")
		{
			E = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"f")
		{
			F = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"l")
		{
			L = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"m")
		{
			M = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"n")
		{
			N = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"p")
		{
			P = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"q")
		{
			Q = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"x1")
		{
			X1 = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"x2")
		{
			X2 = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}


		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"x3")
		{
			X3 = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"y")
		{
			Y = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"y3")
		{
			Y3 = _wtof(Data->MyFunction->Basic->Char2CString(pElem1st->FirstChild()->Value()));
		}

		//BulkheadToothList
		if (Data->MyFunction->Basic->Char2CString(pElem1st->Value()).MakeLower() == L"bulkheadtoothlist")
		{

			for (pElem2nd = pElem1st->FirstChildElement(); pElem2nd != NULL; pElem2nd = pElem2nd->NextSiblingElement())
			{
				CSealToothData* tSTData = new CSealToothData;
				tSTData->LoadXMLData(pElem2nd);

				mBulkHeadToothList.push_back(tSTData);
			}
		}

	}

	return true;
}

bool CBulkheadData::ExportXMLData(TiXmlElement* pElem)
{
	CString str;
	TiXmlElement *BulkheadElement = NULL;

	BulkheadElement = new TiXmlElement("Bulkhead");
	pElem->LinkEndChild(BulkheadElement);

	//BulkheadType
	TiXmlElement *TypeElement = new TiXmlElement("BulkheadType");
	BulkheadElement->LinkEndChild(TypeElement);
	if (mBulkHeadType == Bact_Type)
		str = L"Bacterial";
	//else if (mTLType == impulse)
	//	str = L"Impulse";
	TiXmlText *TypeContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
	TypeElement->LinkEndChild(TypeContent);


	//A
	if (A != 0)
	{
		TiXmlElement *AElement = new TiXmlElement("A");
		BulkheadElement->LinkEndChild(AElement);
		str.Format(L"%.1f", A);
		TiXmlText *AContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		AElement->LinkEndChild(AContent);
	}

	//B
	if (B != 0)
	{
		TiXmlElement *BElement = new TiXmlElement("B");
		BulkheadElement->LinkEndChild(BElement);
		str.Format(L"%.1f", B);
		TiXmlText *BContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		BElement->LinkEndChild(BContent);
	}

	//C
	if (C != 0)
	{
		TiXmlElement *CElement = new TiXmlElement("C");
		BulkheadElement->LinkEndChild(CElement);
		str.Format(L"%.1f", C);
		TiXmlText *CContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		CElement->LinkEndChild(CContent);
	}

	//D
	if (D != 0)
	{
		TiXmlElement *DElement = new TiXmlElement("D");
		BulkheadElement->LinkEndChild(DElement);
		str.Format(L"%.1f", D);
		TiXmlText *DContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		DElement->LinkEndChild(DContent);
	}

	//E
	if (E != 0)
	{
		TiXmlElement *EElement = new TiXmlElement("E");
		BulkheadElement->LinkEndChild(EElement);
		str.Format(L"%.1f", E);
		TiXmlText *EContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		EElement->LinkEndChild(EContent);
	}

	//F
	if (F != 0)
	{
		TiXmlElement *FElement = new TiXmlElement("F");
		BulkheadElement->LinkEndChild(FElement);
		str.Format(L"%.1f", F);
		TiXmlText *FContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		FElement->LinkEndChild(FContent);
	}

	//L
	if (L != 0)
	{
		TiXmlElement *LElement = new TiXmlElement("L");
		BulkheadElement->LinkEndChild(LElement);
		str.Format(L"%.1f", L);
		TiXmlText *LContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		LElement->LinkEndChild(LContent);
	}

	//M
	if (M != 0)
	{
		TiXmlElement *MElement = new TiXmlElement("M");
		BulkheadElement->LinkEndChild(MElement);
		str.Format(L"%.1f", M);
		TiXmlText *MContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		MElement->LinkEndChild(MContent);
	}

	//N
	if (N != 0)
	{
		TiXmlElement *NElement = new TiXmlElement("N");
		BulkheadElement->LinkEndChild(NElement);
		str.Format(L"%.1f", N);
		TiXmlText *NContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		NElement->LinkEndChild(NContent);
	}

	//P
	if (P != 0)
	{
		TiXmlElement *PElement = new TiXmlElement("P");
		BulkheadElement->LinkEndChild(PElement);
		str.Format(L"%.1f", P);
		TiXmlText *PContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		PElement->LinkEndChild(PContent);
	}

	//Q
	if (Q != 0)
	{
		TiXmlElement *QElement = new TiXmlElement("Q");
		BulkheadElement->LinkEndChild(QElement);
		str.Format(L"%.1f", Q);
		TiXmlText *QContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		QElement->LinkEndChild(QContent);
	}

	//X1
	if (X1 != 0)
	{
		TiXmlElement *X1Element = new TiXmlElement("X1");
		BulkheadElement->LinkEndChild(X1Element);
		str.Format(L"%.1f", X1);
		TiXmlText *X1Content = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		X1Element->LinkEndChild(X1Content);
	}

	//X2
	if (X2 != 0)
	{
		TiXmlElement *X2Element = new TiXmlElement("X2");
		BulkheadElement->LinkEndChild(X2Element);
		str.Format(L"%.1f", X2);
		TiXmlText *X2Content = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		X2Element->LinkEndChild(X2Content);
	}

	//X3
	if (X3 != 0)
	{
		TiXmlElement *X3Element = new TiXmlElement("X3");
		BulkheadElement->LinkEndChild(X3Element);
		str.Format(L"%.1f", X3);
		TiXmlText *X3Content = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		X3Element->LinkEndChild(X3Content);
	}

	//Y
	if (Y != 0)
	{
		TiXmlElement *YElement = new TiXmlElement("Y");
		BulkheadElement->LinkEndChild(YElement);
		str.Format(L"%.1f", Y);
		TiXmlText *YContent = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		YElement->LinkEndChild(YContent);
	}

	//Y3
	if (Y3 != 0)
	{
		TiXmlElement *Y3Element = new TiXmlElement("Y3");
		BulkheadElement->LinkEndChild(Y3Element);
		str.Format(L"%.1f", Y3);
		TiXmlText *Y3Content = new TiXmlText(Data->MyFunction->Basic->CString2Char(str));
		Y3Element->LinkEndChild(Y3Content);
	}


	return true;
}
