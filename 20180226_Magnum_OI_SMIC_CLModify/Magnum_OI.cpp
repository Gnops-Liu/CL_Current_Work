//
// Created Release 4.1 1/1/10 
//  08/25/10
//	Automation.cpp - Removed call to TheDevice.init and TheDevice.Hnd_Init() 
//	dialog.cpp - Added calls to TheDevice.init and TheDevice.Hnd_Init() in vLoad
//	dialog.cpp - removed vHidden from PROBER dialog
//	dialog.cpp - added buttons for wafer load/unload
//  09/09/10 
//	Automation.cpp - read_ini reads from C:\nextest\user_tools\Magnum_OI.ini
//	dialog.cpp - put vHidden back in PROBER dialog
//  10/22/10
//	Automation.cpp - AutoTestLoop: Tool terminates if tester has more SA than swt specifies.
//						Fix: logical & of ui_LoadedSlotMask and iv_SiteMask to determine if program loaded on required SAs
//  10/27/10
//	dialog.cpp - fdlog remote_send invokes remote body of variable
//  3/29/11
//				Automation.cpp - ShowWaferNumber() - removed calls to update_variable()
//  5/2/11
//  dialog.cpp - Added support for loading Magnum_OI from UI User menu.
//  Automation.cpp - Added call to Hnd_Start in AutoTestLoop
//  5/27/11
//  Driver.cpp - CDriver::init was not recognizing handler dlls. Replaced remote_set call with set_value call in 
//					CDriver::init().
//  5/27/11
//  Automation.cpp - AnyReady was not setting readymask correctly for handlers. If driving a handler
//                     do not call get_mask(x,y) when setting readymask.


// SMIC release notes
// 111317 - LOT_NUM should come from the prober. Implemented LOT_NUM to be set from .prd file only on Simulation mode
//
// 112517 - Major change related to proper setting of D_TOTAL_DUTS_ON_WAFER. 

#include <math.h>

#include "tester.h"
#include "Driver.h"
#include "Automation.h"
#include "dialog.h"
#include <direct.h>

extern void display_xfer_user_vars (void);
extern void OfflineDebug_Warning();

CSTRING_VARIABLE( OI_REV,			"Magnum_OI_SMIC rev. 120217", ""	) { }

CSTRING_VARIABLE( TOOLS, "", ""){}

INT_VARIABLE ( MAX_SITES_NUM, 8, "" ) { }	// need to set per Magnum.
INT_VARIABLE ( OI_SITE_NUM, 1, "" ) { }	

EXTERN_DIALOG			( PROBER_DIALOG_CUSTOMER ) 
EXTERN_VOID_VARIABLE	( DIALOG_VALUE_READ )
EXTERN_UINT64_VARIABLE	( iv_SiteMask )
EXTERN_VOID_VARIABLE	( AutoTestLoop )
EXTERN_BOOL_VARIABLE	( bGPIB_MONITOR_PAUSE )
EXTERN_CSTRING_VARIABLE ( DRIVER_DLL	)
EXTERN_CSTRING_VARIABLE ( STATUS_MSG	)
EXTERN_BOOL_VARIABLE	( bTESTER_SIMULATION_MODE )
EXTERN_ONEOF_VARIABLE	( oi_TESTER_ID )
EXTERN_CSTRING_VARIABLE (ReleaseTester)

EXTERN_ONEOF_VARIABLE(oi_PRD_FILENAME)
EXTERN_ONEOF_VARIABLE(oi_PRODUCT_ID)

UINT64_VARIABLE ( ui_SiteMask, 0, "" ) { }

BOOL_VARIABLE( bProgLoaded, FALSE, ""){};
BOOL_VARIABLE( bDriverLoaded, FALSE, ""){};

CSTRING_VARIABLE(PRD_DIR, "Y:\\Script\\Engineering\\M2\\product_loader", "") { } // enl 112717
CString cPrdFileName = ""; // enl 112717
CString cPrdFileList=""; // enl 112717
CString cTesterID_File="C:\\nextest\\_production\\testerid.txt"; // enl 112817

// Transform the notification from UI into a signal to
// our HOST_BEGIN_BLOCK, which is waiting for "ProgLoaded"
VOID_VARIABLE(ui_ProgLoaded,"")
{
//	ASSERT ( sender == -1 );  // -1 is UI
	remote_signal ( "ProgLoaded", site_num() );  // should signal the host
}

// Transform the notification from UI into a signal to
// our HOST_BEGIN_BLOCK, which is waiting for "TestDone"
VOID_VARIABLE ( ui_TestDone, "" )
{
//	output("Inside ui_TestDone");
//	ASSERT ( sender == -1 );  // -1 is UI
	remote_signal ( "TestDone", site_num() );  // should signal the Tool
}



//--------------------- must function--------------
void EnsureSingleInstance() 
{
	char *name = __argv[0];
	if ( FindWindow ( "static", name )) 
		fatal ("[%s] already running. Terminate to restart.", name );
	else
		CreateWindow ("static", name, 0, 0, 0, 0, 0, 0, 0, 0, 0 );
}
//--------------------- must function--------------

VOID_VARIABLE ( cExitDlg, "ext" ) 
{
	output ("  Terminating Magnum OI" );
	//remote_set( "ui_Exit", 0, -1, TRUE, INFINITE );
	testprogexit();
}
VOID_VARIABLE ( vExitDlg, "" ) 
{
	output ("  Terminating Magnum OI" );
	//remote_set( "ui_Exit", 0, -1, TRUE, INFINITE );
	testprogexit();
}


extern void Read_ProbeCardSiteInfo ( void );
extern void SwapData_Bin_PF ( void );

extern bool read_switch_file ( void );

void read_prd()
{
	//CString cPrdFile = PRD_DIR + "\\" + oi_PRD_FILENAME;
	CString cPrdFile = PRD_DIR + "\\" + oi_PRODUCT_ID;

	output("<<< Reading PRD file %s", cPrdFile);

	if(!set_values_from_file(cPrdFile))
	{
		output("could not read file %s, using default values", cPrdFile);
	}
}

// enl 112717 - Need the list of prd files from the product_loader directory to show up as a dropdown menu  
void FindPrdFilesFromFolder(CString p_strFolderPath, CString& p_pFiles)
{
    HANDLE hFile = INVALID_HANDLE_VALUE;
    WIN32_FIND_DATA   FindFileData;
    CString strTemp;

    strTemp.Format(_T("%s\\%s"), p_strFolderPath, _T("\\*"));
    hFile = FindFirstFile(strTemp, &FindFileData);
    CString strFilePath;

	p_pFiles.Empty();
	p_pFiles += ",";  //a8p 20171201
    if (INVALID_HANDLE_VALUE != hFile) 
    {
        do
        {
            //Skip directories
            if (FILE_ATTRIBUTE_DIRECTORY & FindFileData.dwFileAttributes)
                continue;

            //strFilePath.Format(_T("%s\\%s"), p_strFolderPath, FindFileData.cFileName);
            //p_pFiles->Add(strFilePath);

            strFilePath.Format(_T("%s,"),FindFileData.cFileName);
            p_pFiles+=strFilePath;
            strFilePath.Empty();            
        } while(FindNextFile(hFile, &FindFileData));

        FindClose(hFile);
    }   
	p_pFiles.TrimRight(",");
}

void read_testerid_file()
{
	FILE * file;
	file = fopen( cTesterID_File, "r" );

	if (file != NULL) {
		char line [1000];
		while(fgets(line,sizeof line,file)!= NULL) { } /* read a line from a file */
		fclose(file);
		set_choices( oi_TESTER_ID, line);
		update_variable ( oi_TESTER_ID );
		output("oi_TESTER_ID : %s", oi_TESTER_ID);
	}
	else {
		CString cMsg;
		cMsg.Format ( "ERROR reading %s", cTesterID_File );
		AfxMessageBox(cMsg);
		output("%s - Terminating Magnum OI", cMsg);
		remote_set( "ui_Exit", 0, -1, TRUE, INFINITE );
	}
}

bool CheckTesterVsRelease() {
	if(ReleaseTester.Find(oi_TESTER_ID) == -1) {
		CString cMsg;
		cMsg.Format ( "Tester: %s is not in ReleaseTester: %s", oi_TESTER_ID, ReleaseTester);
		AfxMessageBox(cMsg);
		return FALSE;
		//output("%s - Terminating Magnum OI", cMsg);
		//remote_set( "ui_Exit", 0, -1, TRUE, INFINITE );
	}
	return TRUE;
}

VOID_VARIABLE ( cTest1, "t1" ) 
{
}

TOOL_CONFIGURATION( SST_PROBER_TOOL )
{
}


TOOL_BEGIN_BLOCK( TBB_TOOL )
{
	if (!bDriverLoaded)
	{
		//load driver //m8p Init gpib device
		TheDevice.SetDLL(DRIVER_DLL);
		output("driver = %s", DRIVER_DLL);

		TheDevice.init();
		if (TheDevice.Hnd_Init() == FALSE)
		{
			AfxMessageBox("Handler/Prober did not initialize correctly. Please check GPIB connection.");
			warning("Hnd_Init failure");
			return;
		}
		bDriverLoaded = TRUE;
		//PROBE_CARD_ID = TheDevice.Hnd_Query("ur0001");
		//PROBE_CARD_ID = TheDevice.Hnd_Query("b");
	}//*/
	char cwd[100];
	//return; //a8p  start
	EnsureSingleInstance();

	menu_add ( "test1",			cTest1 );
	menu_add ( "Exit Tool",		cExitDlg );

	// Get the site mask form UI just to see what it is
	remote_fetch ( ui_SiteMask, -1, FALSE );
	output ( "[Magnum_OI]:ui_SiteMask is 0x%x", ui_SiteMask );

	OI_SITE_NUM = site_num();
	output ( "[Magnum_OI]:OI_SITE_NUM is %d", OI_SITE_NUM );

	update_control(OI_REV); // enl 111017pm
	read_ini();
	
	FindPrdFilesFromFolder(PRD_DIR, cPrdFileList); // enl 112717
	output("PRD Files : %s", cPrdFileList);
	//set_choices(oi_PRD_FILENAME, cPrdFileList);
	//invoke(oi_PRD_FILENAME);
	set_choices(oi_PRODUCT_ID, cPrdFileList);
	invoke(oi_PRODUCT_ID);

	read_testerid_file(); // enl 112817

	display_xfer_user_vars();

	TOOLS = vFormat( "%s", _getcwd(cwd, 100));

	if(DRIVER_DLL_DIR == "")
	{
		DRIVER_DLL_DIR = TOOLS;
		DRIVER_DLL_DIR.Replace( "user_tools", "drivers");
	}

	if(SWT_DIR == "")
	{
		SWT_DIR = DRIVER_DLL_DIR + "\\swt";
	}

	run_modeless ( PROBER_DIALOG_CUSTOMER );
	invoke ( DIALOG_VALUE_READ );

	bGPIB_MONITOR_PAUSE = TRUE;

	remote_fetch(bProgLoaded, 0, FALSE);

	if(bProgLoaded)
	{
		PROGRAM_NAME = remote_get( "ui_TestProgName", -1 );
		output(" Get ui_TestProgName => %s", PROGRAM_NAME );

		output("ui_TestProgConfiguration=%s", remote_get ( "ui_TestProgConfiguration", -1 ));

		remote_fetch( FLOW_NAME, 0, FALSE);

		update_control(FLOW_NAME);
		update_control(PROGRAM_NAME);
	}

	TB_Timer.Init();
	FTimer.Init();
	ATimer.Init();

	// enl 111117 - messagebox placed here at the end to make sure all controls are already populated.
	// it looks like some controls gets updated ahead of pushing the OK button on the messagebox
	if(OFFLINE_DEBUG) OfflineDebug_Warning(); 
}

TOOL_END_BLOCK( name ) {
}