// (C) Copyright 2002-2007 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//----- acrxEntryPoint.cpp
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "resource.h"
#include "axdb.h"
#include "Main.h"

//-----------------------------------------------------------------------------
#define szRDS _RXST("")

ClassProjectAllData *Data = new ClassProjectAllData();

//-----------------------------------------------------------------------------
//----- ObjectARX EntryPoint
class Chq_tongliuApp : public AcRxArxApp {

public:
	Chq_tongliuApp () : AcRxArxApp () {}

	virtual AcRx::AppRetCode On_kInitAppMsg (void *pkt) {
		// TODO: Load dependencies here

		// You *must* call On_kInitAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kInitAppMsg (pkt) ;
		
		// TODO: Add your initialization code here

		return (retCode) ;
	}

	virtual AcRx::AppRetCode On_kUnloadAppMsg (void *pkt) {
		// TODO: Add your code here

		// You *must* call On_kUnloadAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kUnloadAppMsg (pkt) ;

		// TODO: Unload dependencies here

		return (retCode) ;
	}

	virtual void RegisterServerComponents () {
	}


	// - hq_tongliu.test command (do not rename)
	static void hq_tongliutest(void)
	{
	//	// Add your code for command hq_tongliuw.test here
		//if (!Data->MainData->LoadXMLData())
		//	return;

		Data->ResPath =  L"C:\\Users\\ibingo\\Desktop\\TLRES";
		Data->EXCELPath = L"C:\\Users\\ibingo\\Desktop\\AirPassageData.xls";
		Data->XMLPath =  L"C:\\Users\\ibingo\\Desktop\\AirPassageData.xml";
		
		if (!Data->MainData->Export())
			return;
	}

	static int ads_Generate()
	{
		//Data->StrMainPath = Data->MyFunction->System->GetNowOrderPath();
		struct resbuf* args = acedGetArgs();
		Data->ResPath = args->resval.rstring;
		Data->EXCELPath =  Data->ResPath + "\\AirPassageData.xls";
		Data->XMLPath =  Data->ResPath + "\\AirPassageData.xml";
		//acedAlert(Data->ResPath);


		
		if (!Data->MainData->Export())
			return -1;

		return 0;
	}
} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT(Chq_tongliuApp)

ACED_ARXCOMMAND_ENTRY_AUTO(Chq_tongliuApp, hq_tongliu, test, test, ACRX_CMD_TRANSPARENT, NULL)
ACED_ADSSYMBOL_ENTRY_AUTO(Chq_tongliuApp, Generate, false)
