#include "tester.h"
#include "resource.h"
#include "Driver.h"
#include "Automation.h"
#include "dialog.h"
#include "Magnum_OI.h"
#include "wafermap.h"
#include <math.h>

//using namespace std;

///////////////////////
// Dialog MANUAL_TEST
///////////////////////

EXTERN_BOOL_VARIABLE ( bTESTER_SIMULATION_MODE )
EXTERN_BOOL_VARIABLE ( bTESTING_ONGOING )
EXTERN_CSTRING_VARIABLE( OI_REV )

extern CDriver		TheDevice;

extern void read_prd();
extern bool CheckTesterVsRelease();
extern void build_relationship(CString SourceStr_Group, CString ResultStr_Group, CString SourceStr, CString *ResultStr);
extern void check_server();
CSTRING_VARIABLE( PROGRAM_NAME,		"", ""	) { }
CSTRING_VARIABLE( DEVICE_NAME,		"", ""	) { }
CSTRING_VARIABLE( LOT_NUM,			"", ""	) { }
CSTRING_VARIABLE( FLOW_NAME,		"", ""	) 
{
	if(OnHost())
	{
		for( int isite=1; isite<=MAX_SITES_NUM; isite += SITE_PER_CONTROLLER_NUM)
		{
			remote_send( FLOW_NAME, isite, FALSE);
		}
	}
}

CSTRING_VARIABLE( COMMENTS,			"", ""	) { }
CSTRING_VARIABLE( USER_C,			"", ""	) { }
CSTRING_VARIABLE( PROBE_CARD_ID,	"", ""	) { }

CSTRING_VARIABLE( LATEST_WAFER_NUM,	"0", ""	) { }
CSTRING_VARIABLE( TOUCHDOWNS,	"0", ""	) { }

CSTRING_VARIABLE( STATUS_WAFERS,	"0000000000000000000000000", ""	) { }

CSTRING_VARIABLE( SWT_File_Name,	"", ""	) { }

CSTRING_VARIABLE( TOOL, "SST_PROBER_TOOL", ""){}

CSTRING_VARIABLE( TEST_PROGRAM_DIR, "", ""){}
CSTRING_VARIABLE( DRIVER_DLL_DIR,	"Y:\\Script\\Engineering\\M2\\drivers", ""	) { }
CSTRING_VARIABLE( DRIVER_DLL,		"Y:\\Script\\Engineering\\M2\\drivers\\tsk_mag2.dll", ""	) { }
CSTRING_VARIABLE( SWT_DIR,			"Y:\\Script\\Engineering\\M2\\swt", ""	) { }
CSTRING_VARIABLE(SWT, "", "") { }
CSTRING_VARIABLE( cDutToSiteInfo , "", "" ) { }

ONEOF_VARIABLE( oPROGRAM_NAME,		"", ""	) { }
ONEOF_VARIABLE( oDRIVER_DLL, "", ""	) { }
ONEOF_VARIABLE( oSWT,		"", ""	) { }

BOOL_VARIABLE(EngineeringMode,		FALSE,	"") { }

// User Vars for Customer OI
CSTRING_VARIABLE(oi_PRODUCT_SETUP, "", "") { }
CSTRING_VARIABLE(oi_OPERATOR_ID, "", "") { }
CSTRING_VARIABLE(oi_DATALOG_SETUP, "", "") { }

CSTRING_VARIABLE(oi_PROBER, "IDLE", "") { }
CSTRING_VARIABLE(oi_STATUS, "IDLE", "") { }

//CSTRING_VARIABLE(oi_LOT_ID, "", "") { }  // LOT_NUM
CSTRING_VARIABLE(oi_PROBER_LOT_ID, "", "") { }
CSTRING_VARIABLE(oi_WAFER_ID, "", "") { }
CSTRING_VARIABLE(oi_START_TIME, "0:0:0", "") { }
CSTRING_VARIABLE(oi_TEST_TIME, "0:0:0", "") { }

ONEOF_VARIABLE(oi_RUNMODE_SELECTED,"Production,Retest,Correlation", "") { }
ONEOF_VARIABLE(oi_TESTER_ID,"T1,T2,T3", "") { }
ONEOF_VARIABLE(oi_SORT_ID,"S1,S2,S3", "") { }
ONEOF_VARIABLE(oi_TEST_PROGRAM,  "TP0,TP9,TP2017", "") { }

INT_VARIABLE(oi_PASS, 0, "") { }
INT_VARIABLE(oi_FAIL, 0, "") { }
INT_VARIABLE(oi_TESTED, 0, "") { }
CSTRING_VARIABLE(oi_PASS_YIELD, "0.0", "") { }
CSTRING_VARIABLE(oi_FAIL_YIELD, "0.0", "") { }

CSTRING_VARIABLE(PRODUCT_ID_chk, "", "") { }
CSTRING_VARIABLE(SORT_ID_chk, "", "") { }
CSTRING_VARIABLE(LOT_ID_chk, "", "") { }
CSTRING_VARIABLE(PROBECARD_ID_chk, "", "") { }
CSTRING_VARIABLE(OPERATOR_ID_chk, "", "") { }
CSTRING_VARIABLE(TEST_PROGRAM_chk, "", "") { }
CSTRING_VARIABLE(RUNMODESELECTED_chk, "", "") { }
//CL Debug
CSTRING_VARIABLE(oi_bin_def, "", "") {}

//////  User Vars filled up from .prd file  /////
CSTRING_VARIABLE(SMIC_Prod_ID, "", "") {}
CSTRING_VARIABLE(Test_Program_Package, "", "") {}
CSTRING_VARIABLE(Test_Program_Directory, "", "") {}
CSTRING_VARIABLE(Tester_Directory, "", "") {}
CSTRING_VARIABLE(Tester_ID, "", "") {}
CSTRING_VARIABLE(Test_flow, "", "") {}
CSTRING_VARIABLE(Test_Program, "", "") {}
CSTRING_VARIABLE(Probe_Card_Setup_Name, "", "") {}
CSTRING_VARIABLE(Notch_side, "", "") {}
CSTRING_VARIABLE(Bin_Definition_File, "", "") {}
CSTRING_VARIABLE ( Grid_Xmax, "0", "" ) { }	
CSTRING_VARIABLE ( Grid_Ymax, "0", "" ) { }	
CSTRING_VARIABLE(Fab_Site, "", "") {}
CSTRING_VARIABLE(Test_Site, "", "") {}
CSTRING_VARIABLE(Probe_Card_ID, "", "") {}
CSTRING_VARIABLE(X_Die_Size, "", "") {}
CSTRING_VARIABLE(Y_Die_Size, "", "") {}
INT_VARIABLE ( Start_X_Address, 0, "" ) { }	
INT_VARIABLE ( Start_Y_Address, 0, "" ) { }	
INT_VARIABLE ( End_X_Address, 0, "" ) { }	
INT_VARIABLE ( End_Y_Address, 0, "" ) { }	
INT_VARIABLE ( Test_Site_Number, 0, "" ) { }	
INT_VARIABLE ( Gross_Die, 0, "" ) { }	
INT_VARIABLE ( Prr_Check_Number, 0, "" ) { }	
CSTRING_VARIABLE(Magnum_UI_Version, "", "") { }
CSTRING_VARIABLE(Datalog_Setup, "", "") { }
CSTRING_VARIABLE(ReleaseTester, "", "") { }
CSTRING_VARIABLE(Sort_ID, "", "") { }
CSTRING_VARIABLE(Load_Board_ID, "", "") { }
CSTRING_VARIABLE(ROM_Code, "", "") { }
CSTRING_VARIABLE(X_Street, "", "") { }
CSTRING_VARIABLE(Y_Street, "", "") { }
CSTRING_VARIABLE(Customer_Code, "", "") { }
CSTRING_VARIABLE(Customer_PartID, "", "") { }
CSTRING_VARIABLE(ServerDirectory, "", "") { }

CSTRING_VARIABLE( PROBER_MSG, "", "" ) { }
CSTRING_VARIABLE( STATUS_MSG, "", "" ) { }

// derived values
CSTRING_VARIABLE(Test_flow_step, "000", "") {}

// Used for sending text to UI and OI 
CSTRING_VARIABLE(oi_TEST_PROGRAM_OUTPUT, "", "") { }
CSTRING_VARIABLE(tpo, "", "") {}
CSTRING_VARIABLE(uio, "", "") {}
CSTRING_VARIABLE(line, "", "") {}

BOOL_VARIABLE(bUseLotNumEntry,		TRUE,	"") { // enl 112017
	if(bUseLotNumEntry) {
		LOT_NUM.Empty();
		update_control(LOT_NUM);
		EnableWindow( get_HWND( LOT_NUM	),  TRUE);
	}
	else {
		LOT_NUM = "will come from the prober";
		update_control(LOT_NUM);
		EnableWindow( get_HWND( LOT_NUM	),  FALSE);
	}
}

extern void display_xfer_user_vars();
ONEOF_VARIABLE(oi_PRODUCT_ID,"", "") { //enl 112917
	// clear prd variables before loading new values from the prd file
	ReleaseTester = "";
	SMIC_Prod_ID = "";
	Sort_ID = "";
	Test_Program = "";
	Probe_Card_ID = "";
	//return; //a8p
	read_prd();

	output("oi_RUNMODE_SELECTED = %s", oi_RUNMODE_SELECTED);

	// ONEOF_VARIABLES
	//set_choices( oi_PRODUCT_ID, SMIC_Prod_ID);
	set_choices( oi_SORT_ID, Sort_ID);
	set_choices( oi_TEST_PROGRAM, Test_Program);
	//PROBE_CARD_ID = Probe_Card_ID; //m8p

	update_variable ( oi_SORT_ID );
	update_variable ( oi_TEST_PROGRAM );
	update_variable(oi_RUNMODE_SELECTED);
	//PROBE_CARD_ID = TheDevice.Hnd_Query("b");
	update_variable(PROBE_CARD_ID); //a8p
	//CString temp = TheDevice.Hnd_Query("b");
	//LOT_NUM = temp.Mid(1, 6);//TheDevice.Hnd_Query("b");  //a8p
	//update_control(LOT_NUM);
	//update_variable(LOT_NUM);

	//update_control( PROBE_CARD_ID );//m8p

	display_xfer_user_vars();
}

ONEOF_VARIABLE(oi_PRD_FILENAME,"", "") {  // enl 112717

	// clear prd variables before loading new values from the prd file
	ReleaseTester = "";
	SMIC_Prod_ID = "";
	Sort_ID = "";
	Test_Program = "";
	//return; //a8p
	read_prd();

	output("oi_RUNMODE_SELECTED = %s", oi_RUNMODE_SELECTED);

	// ONEOF_VARIABLES
	//set_choices( oi_PRODUCT_ID, SMIC_Prod_ID);
	set_choices( oi_SORT_ID, Sort_ID);
	set_choices( oi_TEST_PROGRAM, Test_Program);
	
	//update_variable ( oi_PRODUCT_ID );
	update_variable ( oi_SORT_ID );
	update_variable ( oi_TEST_PROGRAM );
	update_variable ( oi_RUNMODE_SELECTED );
	update_variable(PROBE_CARD_ID); //a8p

	//update_control( PROBE_CARD_ID );//m8p

	display_xfer_user_vars();
}

//////////////////////////////////////////////////////////

VOID_VARIABLE(vExit, "")
{
	output("  Terminating Magnum OI");
	//remote_set( "ui_Exit", 0, -1, TRUE, INFINITE );
	testprogexit();
}

VOID_VARIABLE ( vUnload, "" ) 
{
	  if(bTESTING_ONGOING) return; //enl 110817 do not do unloading of test program when testing is ongoing

      // run an end of lot summary, just in case
      //remote_set("oi_LotEnd", "1", 0, TRUE);

      output("Unloading Existing Program");
      while (remote_wait("ProgLoadEvent", 0) != -1);    // flush any queued signals
      remote_set("ui_Close", -999, -1, TRUE, INFINITE);
      output("Existing Program Closed");

	  EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vLoad ), TRUE);
	  EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vUnload ), FALSE);
	  EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vExit), TRUE);

	  set_window_text(AutoProbe, "Start Auto Test" );
	  EnableWindow( get_HWND( AutoProbe		),  FALSE);

	  EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vWaferMap ), FALSE);
	  EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vProbeCardMap ), FALSE);
}

VOID_VARIABLE ( vHelp, "" ) 
{
}
VOID_VARIABLE ( vCOF_Mode, "" ) 
{
}
VOID_VARIABLE ( vDebug_Mode, "" ) 
{
}
VOID_VARIABLE ( vManual_Continuity, "" ) 
{
}
VOID_VARIABLE ( vDatalog, "" ) 
{
	remote_fetch(dlog, 0, FALSE); // get existing dlog setup from test program
	if (invoke(DATALOG_DIALOG) == IDCANCEL)
		return;

	update_variable ( dlog_pins );
	invoke(dlog_pins); // send dlog mode to tester
}

DIALOG(DATALOG_DIALOG) 
{
	CONTROL( IDC_RADIO1, dlog_pins );
}

BOOL_VARIABLE( FK1, FALSE, "" ) { remote_send(FK1, 0, FALSE); }
BOOL_VARIABLE( FK2, FALSE, "" ) { remote_send(FK2, 0, FALSE); }
BOOL_VARIABLE( FK3, FALSE, "" ) { remote_send(FK3, 0, FALSE); }
BOOL_VARIABLE( FK4, FALSE, "" ) { remote_send(FK4, 0, FALSE); }
BOOL_VARIABLE( FK5, FALSE, "" ) { remote_send(FK5, 0, FALSE); }
BOOL_VARIABLE( FK6, FALSE, "" ) { remote_send(FK6, 0, FALSE); }
BOOL_VARIABLE( FK7, FALSE, "" ) { remote_send(FK7, 0, FALSE); }
BOOL_VARIABLE( FK8, FALSE, "" ) { remote_send(FK8, 0, FALSE); }
BOOL_VARIABLE( FK9, FALSE, "" ) { remote_send(FK9, 0, FALSE); }
BOOL_VARIABLE( FK10, FALSE, "" ) { remote_send(FK10, 0, FALSE); }
BOOL_VARIABLE( FK11, FALSE, "" ) { remote_send(FK11, 0, FALSE); }
BOOL_VARIABLE( FK12, FALSE, "" ) { remote_send(FK12, 0, FALSE); }
BOOL_VARIABLE( FK13, FALSE, "" ) { remote_send(FK13, 0, FALSE); }
BOOL_VARIABLE( FK14, FALSE, "" ) { remote_send(FK14, 0, FALSE); }
BOOL_VARIABLE( FK15, FALSE, "" ) { remote_send(FK15, 0, FALSE); }
BOOL_VARIABLE( FK16, FALSE, "" ) { remote_send(FK16, 0, FALSE); }

// Setting dlog related USER_VARS to host disabled. Let testprogram decide level of datalog
INT_VARIABLE(  dlog, 4, "datalog All" ) { /*remote_send(dlog, 0, FALSE);*/ }
INT_VARIABLE( DLog_vector_count, 10, "DLog_vector_count" ) { /*remote_send(DLog_vector_count, 0, FALSE);*/} ;	

BOOL_VARIABLE(  para, TRUE, "" ) { /*remote_send(para, 0, TRUE, INFINITE);*/ }
BOOL_VARIABLE(  func, TRUE, "" ) { /*remote_send(func, 0, TRUE, INFINITE);*/ }
BOOL_VARIABLE(  user, TRUE, "" ) { /*remote_send(user, 0, TRUE, INFINITE);*/ }
BOOL_VARIABLE(  fdlog, TRUE, "func" ) { /*remote_send(fdlog, 0, TRUE, INFINITE);*/ }
BOOL_VARIABLE( lvm, TRUE, "lvm" ) {/*remote_send(lvm, 0, TRUE, INFINITE);*/} ;	
BOOL_VARIABLE( shmoo, TRUE, "shmoo" ) {/*remote_send(shmoo, 0, TRUE, INFINITE);*/} ;
BOOL_VARIABLE( search, TRUE, "search" ) {/*remote_send(search, 0, TRUE, INFINITE);*/} ;

BOOL_VARIABLE ( bGPIB_MONITOR_PAUSE, FALSE, "" ) { }
BOOL_VARIABLE ( bIGNORE_SWT, FALSE, "" ) { }
BOOL_VARIABLE ( bWMAP_TOOL, FALSE, "" ) { }

CSTRING_VARIABLE ( TSK_PROGRAM_NAME, "", "" ) { }
CSTRING_VARIABLE ( TSK_PROGRAM_DIR,  "", "" ) { }
CSTRING_VARIABLE ( TSK_PROGRAM_DRV,  "", "" ) { }
CSTRING_VARIABLE ( WMAP_TOOL_CFG,  "C:\\nextest\\user_tools\\wmap_tool", "" ) { }

EXTERN_VOID_VARIABLE( datalog_button )
EXTERN_VOID_VARIABLE( vReset )
EXTERN_VOID_VARIABLE( vLoad )

extern void CheckingVariables ( void );
extern void InitDB ( void );
extern void Nxt_system( CString cOIcmd );

EXTERN_INT_VARIABLE ( MAX_DUTS )	// it will be auto calculated

ONEOF_VARIABLE( oDriverType, "prober, handler", "") 
{ 
	TheDevice.SetType(oDriverType);
	if(oDriverType=="prober")
	{
		EnableWindow( get_HWND( PROBE_CARD_ID	),  TRUE	);
	}
	else
	{
		EnableWindow( get_HWND( PROBE_CARD_ID	),  FALSE	);
	}
}

//VOID_VARIABLE ( vPrgOpen, "" )
//{
//	PROGRAM_NAME = get_open_file_name();
//	update_control ( PROGRAM_NAME );
//}

VOID_VARIABLE ( vPrgOpen, "" )
{
	CFileFind dir_finder, exe_finder;
	CString dir_filename, exe_filename, filelist="";

	if(TEST_PROGRAM_DIR=="")
	{
		PROGRAM_NAME = get_open_file_name();
	}
	else
	{
		dir_filename = TEST_PROGRAM_DIR + "\\*";

		BOOL bWorking = dir_finder.FindFile( dir_filename );
	
		while(bWorking)
		{
			bWorking = dir_finder.FindNextFile();

			if(dir_finder.IsDirectory())
			{
        		exe_filename = dir_finder.GetFilePath() + "\\*.exe";

				if(exe_finder.FindFile( exe_filename ))
				{
					exe_finder.FindNextFile();
					CString path = exe_finder.GetFilePath();
					filelist += vFormat("%s,", path.Right(path.GetLength() - (TEST_PROGRAM_DIR.GetLength()+1)));
				}
			}
		}
		
		set_choices(oPROGRAM_NAME, filelist);
	
		invoke(SELECT_TEST_PROGRAM);
	
		PROGRAM_NAME = TEST_PROGRAM_DIR + "\\" + oPROGRAM_NAME;	
	}

	update_control ( PROGRAM_NAME );
}

VOID_VARIABLE ( vDllOpen, "" )
{
	CFileFind finder;
	CString filename, filelist="";

	filename = DRIVER_DLL_DIR + "\\*.dll";

	BOOL bWorking = finder.FindFile( filename );

	if(bWorking==FALSE)
	{
		CString msg = vFormat("Error !!! no *.dll files found");
		AfxMessageBox ( msg );
		return;
	}

	while(bWorking)
	{
		bWorking = finder.FindNextFile();

		filelist += vFormat("%s,", finder.GetFileName());
	}

	filelist.TrimRight(',');

	set_choices(oDRIVER_DLL, filelist);

	invoke(SELECT_DRIVER_DLL);

	DRIVER_DLL = DRIVER_DLL_DIR + "\\" + oDRIVER_DLL;

	update_control ( DRIVER_DLL );
}

//VOID_VARIABLE ( vSWTOpen, "" )
//{
//	SWT = get_open_file_name();
//	update_control ( SWT );
//}

VOID_VARIABLE ( vSWTOpen, "" )
{
	CFileFind finder;
	CString filename, filelist="";

	filename = SWT_DIR + "\\*.swt";

	BOOL bWorking = finder.FindFile( filename );

	if(bWorking==FALSE)
	{
		CString msg = vFormat("Error !!! no *.swt files found");
		AfxMessageBox ( msg );
		return;
	}

	while(bWorking)
	{
		bWorking = finder.FindNextFile();

		filelist += vFormat("%s,", finder.GetFileName());
	}

	filelist.TrimRight(',');

	set_choices( oSWT, filelist);

	invoke( SELECT_SWT);

	SWT = SWT_DIR + "\\" + oSWT;

	update_control ( SWT );
}

CString FnameHenkan ( CString cMsg )
{
	char cDrv[8];
	char cDir[256];
	char cName[256];
	char cExt[256];

	_splitpath( cMsg.GetBuffer(0), cDrv, cDir, cName, cExt );
	cMsg.ReleaseBuffer();

	TSK_PROGRAM_NAME = (CString)cName;
	TSK_PROGRAM_DIR  = (CString)cDir;
	TSK_PROGRAM_DRV  = (CString)cDrv;

return (CString)cName;
}



VOID_VARIABLE( AutoProbe, "" )
{
	CString txt= get_window_text(AutoProbe);
	//output("<<<<<<<< AutoProbe invoked >>>>> txt = %s", txt); // enl debugs

	if(txt=="Start Auto Test")
	{
		//FnameHenkan ( PROGRAM_NAME );
	
		remote_set	 ( TOOL, TOOL, 0, FALSE );
	
		update_variable ( PROGRAM_NAME );
	    update_variable ( DEVICE_NAME );
		update_variable ( LOT_NUM );
		update_variable ( FLOW_NAME );
		update_variable ( COMMENTS );
		update_variable ( USER_C );
	    update_variable ( PROBE_CARD_ID );
	
		LATEST_WAFER_NUM = "0";
		STATUS_WAFERS = "0000000000000000000000000";
	
		update_variable ( LATEST_WAFER_NUM );
	    update_variable ( STATUS_WAFERS );
	
		if ( LOT_NUM.IsEmpty() && bUseLotNumEntry) {
			AfxMessageBox ( "A LOT NUM is required" );
			return;
		}
	
		//send updated varaibles value to ui host
		remote_set ( PROGRAM_NAME, TSK_PROGRAM_NAME, 0, FALSE );
		remote_send ( DEVICE_NAME,		0, FALSE );
		remote_send ( LOT_NUM,			0, FALSE );
	
		if(FLOW_NAME=="")
		{
			remote_fetch( FLOW_NAME, 0, FALSE);
			update_control(FLOW_NAME);
		}
		else
		{
			remote_send ( FLOW_NAME, 0, FALSE );
		}
	
		remote_send ( COMMENTS,			0, FALSE );
		remote_send ( USER_C,			0, FALSE );
	
	// update variables on test program to follow OI.
		remote_send ( dlog,			0, FALSE );
		remote_send ( para,			0, FALSE );
		remote_send ( func,			0, FALSE );
		remote_send ( user,			0, FALSE );
		remote_send ( fdlog,		0, FALSE );
	
		remote_send ( FK1,			0, FALSE );
		remote_send ( FK2,			0, FALSE );
		remote_send ( FK3,			0, FALSE );
		remote_send ( FK4,			0, FALSE );
		remote_send ( FK5,			0, FALSE );
		remote_send ( FK6,			0, FALSE );
		remote_send ( FK7,			0, FALSE );
		remote_send ( FK8,			0, FALSE );
		remote_send ( FK9,			0, FALSE );
		remote_send ( FK10,			0, FALSE );
		remote_send ( FK11,			0, FALSE );
		remote_send ( FK12,			0, FALSE );
		remote_send ( FK13,			0, FALSE );
		remote_send ( FK14,			0, FALSE );
		remote_send ( FK15,			0, FALSE );
		remote_send ( FK16,			0, FALSE );
	
		//SWT_File_Name = TSK_PROGRAM_NAME;
		AutoTesting = TRUE;
		
		bGPIB_MONITOR_PAUSE = FALSE;
	
		//EnableWindow( get_HWND( AutoProbe		),  FALSE);
		//set_window_text(AutoProbe, "Pause" );
	
		EnableWindow( get_HWND( PROGRAM_NAME	),  FALSE	);
		EnableWindow( get_HWND( DEVICE_NAME		),  FALSE	);
		EnableWindow( get_HWND( LOT_NUM			),  FALSE	);
		EnableWindow( get_HWND( bUseLotNumEntry	),  FALSE	); // enl 112017
		EnableWindow( get_HWND( FLOW_NAME		),  FALSE	);
		EnableWindow( get_HWND( COMMENTS		),  FALSE	);
		EnableWindow( get_HWND( USER_C			),  FALSE	);
		EnableWindow( get_HWND( PROBE_CARD_ID	),  FALSE	);
		EnableWindow( get_HWND( vPrgOpen		),  FALSE	);
		EnableWindow( get_HWND( vReset			),  FALSE	);
		EnableWindow( get_HWND( DRIVER_DLL		),  FALSE	);
		EnableWindow( get_HWND( SWT	),				FALSE);
		EnableWindow( get_HWND( vDllOpen	),		FALSE);
		EnableWindow( get_HWND( vSWTOpen	),		FALSE);

		EnableWindow( get_HWND( oi_OPERATOR_ID	),	FALSE);
		EnableWindow( get_HWND( oi_TESTER_ID	),	FALSE);
		EnableWindow( get_HWND( oi_PRODUCT_ID	),	FALSE);
		EnableWindow( get_HWND( oi_SORT_ID	),	FALSE);
		EnableWindow( get_HWND( oi_TEST_PROGRAM	),	FALSE);
//		EnableWindow( get_HWND( oi_PRD_FILENAME	),	FALSE);
		EnableWindow( get_HWND( oi_RUNMODE_SELECTED	),	FALSE);

		EnableWindow( get_HWND( vLoad	),  FALSE);
//		EnableWindow( get_HWND( vPause	),  TRUE);
		EnableWindow( get_HWND( StopAutoProbe	),  TRUE);
 		EnableWindow( get_HWND( vExit ), FALSE);
	
		set_window_text(AutoProbe, "Pause Test" );
		EnableWindow( get_HWND( AutoProbe		),  TRUE);

		disable_manual_buttons();

		//CheckingVariables ();
		InitDB ();
	
		remote_send( AutoTestLoop, site_num(), TRUE );
	}
	else if(txt == "Pause Test")
	{			
		bGPIB_MONITOR_PAUSE = TRUE;
		set_window_text(AutoProbe, "Resume Test" );
		EnableWindow( get_HWND( AutoProbe		),  TRUE);
		enable_manual_buttons();
	}
	else //Resume
	{
		bGPIB_MONITOR_PAUSE = FALSE;
		set_window_text(AutoProbe, "Pause Test" );
		EnableWindow( get_HWND( AutoProbe		),  TRUE);
		disable_manual_buttons();
	}
}

extern	void clear_each_variables ( void );
EXTERN_VOID_VARIABLE( StopAutoProbe )

void vStopAutoProbe ( void )
{
//	EnableWindow( get_HWND( AutoProbe	  ),  TRUE);

	EnableWindow( get_HWND( PROGRAM_NAME ),		TRUE);
	EnableWindow( get_HWND( vPrgOpen ),			TRUE);
	EnableWindow( get_HWND( DEVICE_NAME	),		TRUE);
	EnableWindow( get_HWND( LOT_NUM	),			TRUE);
	EnableWindow( get_HWND( bUseLotNumEntry	),	TRUE); //enl 112017
	EnableWindow( get_HWND( FLOW_NAME	),		TRUE);
	EnableWindow( get_HWND( COMMENTS	),		TRUE);
	EnableWindow( get_HWND( USER_C	),			TRUE);
	EnableWindow( get_HWND( DRIVER_DLL	),		TRUE);
	EnableWindow( get_HWND( SWT	),				TRUE);
	EnableWindow( get_HWND( vDllOpen	),		TRUE);
	EnableWindow( get_HWND( vSWTOpen	),		TRUE);
	EnableWindow( get_HWND( PROBE_CARD_ID	),	oDriverType == "prober" ? TRUE : FALSE);

	EnableWindow( get_HWND( vLoad	),		TRUE);
	EnableWindow( get_HWND( AutoProbe		),  FALSE);
	EnableWindow( get_HWND( StopAutoProbe	),  FALSE);
	EnableWindow( get_HWND( vReset			),  TRUE	);
	EnableWindow( get_HWND( vExit), TRUE);

	LOT_NUM = "";
	COMMENTS = "";

	update_control ( LOT_NUM );
	update_control ( COMMENTS );

	update_variable ( LATEST_WAFER_NUM );
    update_variable ( STATUS_WAFERS );

	EnableWindow( get_HWND( vHnd_UnloadWafer	  ),	TheDevice.Hnd_UnloadWafer!=NULL ? TRUE : FALSE);
	EnableWindow( get_HWND( vHnd_LoadWafer	  ),		TheDevice.Hnd_LoadWafer!=NULL ? TRUE : FALSE);
	EnableWindow( get_HWND( vHnd_ZUp	  ),			TheDevice.Hnd_ZUp!=NULL ? TRUE : FALSE);
	EnableWindow( get_HWND( vHnd_ZDown	  ),			TheDevice.Hnd_ZDown!=NULL ? TRUE : FALSE);
	EnableWindow( get_HWND( vHnd_Move	  ),			TheDevice.Hnd_Move!=NULL ? TRUE : FALSE);
	EnableWindow( get_HWND( BASE_X_COORD	  ),			TheDevice.Hnd_Move!=NULL ? TRUE : FALSE);
	EnableWindow( get_HWND( BASE_Y_COORD	  ),			TheDevice.Hnd_Move!=NULL ? TRUE : FALSE);
}

VOID_VARIABLE( StopAutoProbe, "" )
{
	int i = AfxMessageBox ( "!!! Are you sure you want to STOP auto test ? !!!           ", MB_OKCANCEL );

	output("i=%d", i);
	if ( i == 2 ) return;

	AutoTesting = FALSE;
	bGPIB_MONITOR_PAUSE = FALSE;

	vStopAutoProbe ();
}

VOID_VARIABLE ( ui_ProgUnloaded, "" ) 
{
	output ( "Site%d Program unloaded send by %d",site_num(),sender );
	output ( "Program unloaded done" );
	remote_signal ( "ProgUnloaded", site_num() );
}

bool read_switch_file ( void )
{
	EXTERN_INT_VARIABLE ( MAX_SITES_NUM )
	EXTERN_UINT64_VARIABLE	( iv_SiteMask )
	extern int Hnd_ProbeCardSiteLocationRelativeX[];
	extern int Hnd_ProbeCardSiteLocationRelativeY[];
	extern void Printout_ProbeCardMap ( int );

	if(bIGNORE_SWT)
	{
		output("read_switch_file: ignoring SWT");
		return true;
	}

//	FnameHenkan ( PROGRAM_NAME );
//	CString cSwtFile = vFormat ( "%s%s%s.swt",TSK_PROGRAM_DRV,TSK_PROGRAM_DIR, TSK_PROGRAM_NAME );
//	cSwtFile = SWT;

	CString cSwtFile = SWT_DIR + "\\" + Probe_Card_Setup_Name;

	if ( VERBOSITY ) output ( "switch file name is %s", cSwtFile );

	FILE * File1;
		
	File1 = fopen ( cSwtFile, "r" );
	if ( File1 == NULL ) 
	{
		CString cMsg = vFormat ( "Cannot open switch file : %s", cSwtFile );
		AfxMessageBox ( cMsg );
		fatal ( "%s", cMsg );
	}

	char moji[256];
	BOOL flag1 = FALSE;
	BOOL flag2 = FALSE;
	extern 	int iSiteToDut[D_SITES_IN_PROBER];
	int max_index = 0;
	int index = 0;
	int iTemp;

	CString cMsg;
	CString cTemp;

	while ( (int)fgets( moji, 255, File1 ) != NULL )
	{
		int cidx;
		cMsg = (CString)moji;

		if ( (cidx=cMsg.Find ( "MAGNUM_SITE_NUMBER", 0 )) != -1 ) 
		{
			cMsg.Replace('\t', ' ');
			cidx = cMsg.Find(" ", cidx);
			cTemp = cMsg.Right(cMsg.GetLength() - cidx - 1); 
			cTemp.TrimLeft(" "); 

			MAX_SITES_NUM = atoi(cTemp);
			if(MAX_SITES_NUM>bits(ui_SiteMask))
			{
				CString CMsg = vFormat("NOT ENOUGH SITES ENABLED %d : should be %d",  bits(ui_SiteMask), MAX_SITES_NUM);
				AfxMessageBox(CMsg);
				return false;
			}

			remote_set	 ( MAX_SITES_NUM, MAX_SITES_NUM, 0, FALSE );

			MAX_DUTS = ( MAX_DUT_NUM_PER_SITE * MAX_SITES_NUM ) / SITE_PER_CONTROLLER_NUM;

			output ( "Sites per controller   = %d", SITE_PER_CONTROLLER_NUM );
			output ( "Max duts / site        = %d", MAX_DUT_NUM_PER_SITE );
			output ( "total duts / probecard = %d", MAX_DUTS );

			continue;
		}

		if ( (cidx=cMsg.Find ( "WMAP_TOOL_CFG", 0 )) != -1 ) 
		{
			CFileFind finder;

			cMsg.Replace('\t', ' ');
			cidx = cMsg.Find(" ", cidx);
			cTemp = cMsg.Right(cMsg.GetLength() - cidx - 1); 
			cTemp.TrimLeft(); 
			cTemp.TrimRight(); 

			WMAP_TOOL_CFG += vFormat("\\%s", cTemp);

			if(finder.FindFile(WMAP_TOOL_CFG))
			{
				bWMAP_TOOL = TRUE;

				remote_send( WMAP_TOOL_CFG, 0, TRUE, INFINITE);
			}
			else
			{
				CString msg = vFormat("read_switch_file: Error !!! no %s file", WMAP_TOOL_CFG);
				AfxMessageBox ( msg );
			}

			continue;
		}

		if ( cMsg.Find ( "Sites_Mapping Beg", 0 ) != -1 ) 
		{

			memset( iDutToSite, -1, sizeof(int) * D_SITES_IN_PROBER );
			memset( iSiteToDut, -1, sizeof(int) * D_SITES_IN_PROBER );

			flag1 = TRUE;
			continue;
		}

		if ( cMsg.Find ( "End of Sites_mapping", 0 ) != -1 )
		{
			flag1 = FALSE;
			continue;
		}

		if ( cMsg.Find ( "Multi_Prb Beg", 0 ) != -1 ) {
			flag2 = TRUE;
			continue;
		}

		if ( cMsg.Find ( "End of Multi_Prb", 0 ) != -1 )
		{
			flag2 = FALSE;
			continue;
		}

		if ( (flag1 == TRUE ) && (max_index<MAX_DUTS))
		{
			int site;

			sscanf( cMsg, "Site%d", &site);

			//output ( "%s", cMsg );

			iTemp =	cMsg.FindOneOf(" \t");
			iSiteToDut[site-1] = atoi ( cMsg.Right( cMsg.GetLength() - iTemp ) ) - 1;
			iDutToSite[iSiteToDut[site-1]] = site-1;

			output ( "iSiteToDut[%d]=%d", 	site-1, iSiteToDut[site-1] );
			output ( "iDutToSite[%d]=%d", 	iSiteToDut[site-1], iDutToSite[iSiteToDut[site-1]] );

			//if(iSiteToDut[site-1] > 0) // enl added to allow computation of configs with less than MAX_DUTS
				MAX_PH_SITES = site > MAX_PH_SITES ? site : MAX_PH_SITES;

			//output ( "iSiteToDut[%d]=%d", 	max_index, iSiteToDut[max_index] );
			//output ( "iDutToSite[%d]=%d", 	max_index, iDutToSite[max_index] );
			max_index++;
		}
			
		if ( (flag2 == TRUE ) && (index/2<MAX_DUTS))
		{
			output ( "%s", cMsg );
			iTemp =	cMsg.FindOneOf(" \t");
			if ( ! (index % 2) )
			{
				Hnd_ProbeCardSiteLocationRelativeX[iSiteToDut[index/2]] = atoi ( cMsg.Right( cMsg.GetLength() - iTemp ) );
				output ( "index %d , X = %d", iSiteToDut[index/2] , Hnd_ProbeCardSiteLocationRelativeX[iSiteToDut[index/2]] );
			} else {
				Hnd_ProbeCardSiteLocationRelativeY[iSiteToDut[index/2]] = atoi ( cMsg.Right( cMsg.GetLength() - iTemp ) );
				output ( "index %d , Y = %d", iSiteToDut[index/2], Hnd_ProbeCardSiteLocationRelativeY[iSiteToDut[index/2]] );
			}
			index++;
		}
	}
	fclose ( File1 );

	output ( "\n<<<<< MAX_PH_SITES=%d >>>>>\n", 	MAX_PH_SITES );

	if(oDriverType=="prober")
	{
		int ix = Hnd_ProbeCardSiteLocationRelativeX[0];
		int iy = Hnd_ProbeCardSiteLocationRelativeY[0];

		output("ix=%d iy=%d", ix,iy);
	
		for ( int i = 0; i < max_index; i++ )
		{
			Hnd_ProbeCardSiteLocationRelativeX[i] = Hnd_ProbeCardSiteLocationRelativeX[i] - ix;
			Hnd_ProbeCardSiteLocationRelativeY[i] = Hnd_ProbeCardSiteLocationRelativeY[i] - iy;

			output("Hnd_ProbeCardSiteLocationRelativeX[%d] = %d", i, Hnd_ProbeCardSiteLocationRelativeX[i]);
			output("Hnd_ProbeCardSiteLocationRelativeY[%d] = %d", i, Hnd_ProbeCardSiteLocationRelativeY[i]);
		}
	
		ix = Hnd_ProbeCardSiteLocationRelativeX[iSiteToDut[0]];
		iy = Hnd_ProbeCardSiteLocationRelativeY[iSiteToDut[0]];
	
		output("ix=%d iy=%d max_index = %d", ix,iy, max_index);

		for ( int i = 0; i < max_index; i++ )
		{
			Hnd_ProbeCardSiteLocationRelativeX[i] -= ix;
			Hnd_ProbeCardSiteLocationRelativeY[i] -= iy;

			output("Hnd_ProbeCardSiteLocationRelativeX[%d] = %d", i, Hnd_ProbeCardSiteLocationRelativeX[i]);
			output("Hnd_ProbeCardSiteLocationRelativeY[%d] = %d", i, Hnd_ProbeCardSiteLocationRelativeY[i]);
		}
	
		//Printout_ProbeCardMap ( max_index ); // Not working on 336 duts. disanled for now until further study... - enl 092917
	}
	//initialize cDutToSiteInfo user variable and send to host

	cDutToSiteInfo = vFormat ( "%d,", MAX_DUTS );

	for ( int i = 0; i < MAX_DUTS; i++ )
	{
		cDutToSiteInfo = cDutToSiteInfo + vFormat ( " %d,", iDutToSite[i] );
	}

	remote_send ( cDutToSiteInfo,	0, FALSE );
	if(ONLINE_DEBUG) output("DEBUG: Sent to Host : cDutToSiteInfo = %s", cDutToSiteInfo);

	/* enl - may implement later, but will need test program mods 
	if(TT_PROFILE) TB_Timer.StartTimer("remote_send cDutToSiteInfo to all sites");
	// enl 112417 - send to sites so that the sites will not need to get from the host which can have tt variance between sites
	for (int site = 0 ; site < MAX_SITES_NUM; site += SITE_PER_CONTROLLER_NUM) {
		remote_send ( cDutToSiteInfo,	site+1, FALSE );
		if(ONLINE_DEBUG) output("cDutToSiteInfo remote_send to site%d", site+1 );
	}
	if(TT_PROFILE) TB_Timer.StopTimer("remote_send cDutToSiteInfo to all sites - END");
	*/


	return true;
}

CString GetPrefix(CString filename)
{
	CString prefix;

	int iSlash = filename.ReverseFind('\\');
	int iPeriod = filename.Find(".exe");

	prefix = filename.Mid( iSlash+1, iPeriod - (iSlash+1));
	prefix.MakeUpper();

	return prefix;
}

VOID_VARIABLE( vLoad, "" )
{
	update_variable ( oi_RUNMODE_SELECTED );
	if(oi_RUNMODE_SELECTED == "Production" || oi_RUNMODE_SELECTED == "Retest")  // enl 112917
		if(!CheckTesterVsRelease()) 
			return;

	EnableWindow( get_HWND( vLoad	),  FALSE);
	EnableWindow( get_HWND( AutoProbe		),  FALSE);
	EnableWindow( get_HWND( StopAutoProbe	),  FALSE);
	EnableWindow( get_HWND( vExit), FALSE);

	EnableWindow( get_HWND( vPrgOpen	),  FALSE);
	EnableWindow( get_HWND( vDllOpen	),  FALSE);
	EnableWindow( get_HWND( vSWTOpen	),  FALSE);

	//update_variable ( oi_PRODUCT_ID );
	update_variable ( oi_SORT_ID );
	update_variable ( oi_TESTER_ID );
	update_variable ( oi_OPERATOR_ID );
	update_variable ( oi_RUNMODE_SELECTED );
	update_variable ( PROBE_CARD_ID );

	update_variable ( PROGRAM_NAME );
	update_variable ( DEVICE_NAME );
	update_variable ( LOT_NUM );
	update_variable ( FLOW_NAME );
	update_variable ( COMMENTS );
	update_variable ( USER_C );

	update_variable( DRIVER_DLL );
	update_variable( SWT );
    update_variable ( PROBE_CARD_ID );

	update_variable ( oi_TEST_PROGRAM );
// cl modification 20180223
	build_relationship(Test_Program, Bin_Definition_File, oi_TEST_PROGRAM, &oi_bin_def);
	build_relationship(Test_Program, Test_Program_Package, oi_TEST_PROGRAM, &oi_PRODUCT_SETUP);
	output("Now you have selected %s", oi_bin_def);
	output("Now you have selected %s", oi_PRODUCT_SETUP);
	
	check_server();//check whether server is disconnect

	output("7z x \"" + oi_PRODUCT_SETUP + "\" -y -aos -o \"" + TEST_PROGRAM_DIR + "\"");
	Nxt_system("7z x \"" + oi_PRODUCT_SETUP + "\" -y -aos -o \"" + TEST_PROGRAM_DIR+"\"");

	PROGRAM_NAME = TEST_PROGRAM_DIR + "\\Debug\\" + oi_TEST_PROGRAM;

	if (oi_SORT_ID == "")  //A8P
	{
		AfxMessageBox("Sort ID is Error\n Please confirm these portion");

		EnableWindow(get_HWND(vLoad), TRUE);
		EnableWindow(get_HWND(vPrgOpen), TRUE);
		EnableWindow(get_HWND(vDllOpen), TRUE);
		EnableWindow(get_HWND(vSWTOpen), TRUE);
		EnableWindow(get_HWND(vExit), TRUE);
		return;
	} //oi_SORT_ID

	if (PROGRAM_NAME == "" || DRIVER_DLL == "")  //?8P
	{
		AfxMessageBox(" PROGRAM_NAME or DRIVER_DLL is Empty\n Please confirm these portions");

		EnableWindow(get_HWND(vLoad), TRUE);
		EnableWindow(get_HWND(vPrgOpen), TRUE);
		EnableWindow(get_HWND(vDllOpen), TRUE);
		EnableWindow(get_HWND(vSWTOpen), TRUE);
		EnableWindow(get_HWND(vExit), TRUE);
		return;
	}

	if (oi_OPERATOR_ID == "" || strlen(oi_OPERATOR_ID) != 7)
	{
		AfxMessageBox(" Operator ID is Error\n Please confirm these portions");

		EnableWindow(get_HWND(vLoad), TRUE);
		EnableWindow(get_HWND(vPrgOpen), TRUE);
		EnableWindow(get_HWND(vDllOpen), TRUE);
		EnableWindow(get_HWND(vSWTOpen), TRUE);
		EnableWindow(get_HWND(vExit), TRUE);
		return;
	}
	CString wfrid = TheDevice.Hnd_Query("V"); //a8p
	//if (strlen(LOT_NUM) != 6 && bUseLotNumEntry) 
	if (wfrid.Find(LOT_NUM)==-1)
	{
		AfxMessageBox(" LOT ID is Error\n Please confirm these portion");

		EnableWindow(get_HWND(vLoad), TRUE);
		EnableWindow(get_HWND(vPrgOpen), TRUE);
		EnableWindow(get_HWND(vDllOpen), TRUE);
		EnableWindow(get_HWND(vSWTOpen), TRUE);
		EnableWindow(get_HWND(vExit), TRUE);
		return;
	}//*/
	//ReleaseTester.Find(oi_TESTER_ID) == -1
	//if (strlen(PROBE_CARD_ID) != 14 || PROBE_CARD_ID.Find("-") != 5 || PROBE_CARD_ID.Mid(9, 1) == "-" || PROBE_CARD_ID.Mid(12, 1) == "-")
	if (Probe_Card_ID.Find(PROBE_CARD_ID) == -1 || strlen(PROBE_CARD_ID) != 14)  //A8P
	{
		AfxMessageBox("Probe Card ID is Error\n Please confirm these portion");

		EnableWindow(get_HWND(vLoad), TRUE);
		EnableWindow(get_HWND(vPrgOpen), TRUE);
		EnableWindow(get_HWND(vDllOpen), TRUE);
		EnableWindow(get_HWND(vSWTOpen), TRUE);
		EnableWindow(get_HWND(vExit), TRUE);
		return;
	} 





	/*
	if(DEVICE_NAME == "")
	{
		DEVICE_NAME = GetPrefix(PROGRAM_NAME);
		update_control(DEVICE_NAME);
	}
	*/


	/////// Show DOUBLE_CHECK dialog ////////
	PRODUCT_ID_chk = oi_PRODUCT_ID;
	SORT_ID_chk = oi_SORT_ID;
	LOT_ID_chk = LOT_NUM;
	PROBECARD_ID_chk = PROBE_CARD_ID;
	OPERATOR_ID_chk = oi_OPERATOR_ID;
	TEST_PROGRAM_chk = oi_TEST_PROGRAM;
	update_variable(oi_RUNMODE_SELECTED);
	RUNMODESELECTED_chk = oi_RUNMODE_SELECTED;

	if (invoke(DOUBLE_CHECK) == IDCANCEL) { // enl 112017 corrected button behavior
		EnableWindow( get_HWND( vLoad	),  TRUE);
		EnableWindow( get_HWND( vPrgOpen	),  TRUE);
		EnableWindow( get_HWND( vDllOpen	),  TRUE);
		EnableWindow( get_HWND( vSWTOpen	),  TRUE);
		EnableWindow( get_HWND( vExit), TRUE);
		return;
	}
	////////////////////////////////////////

	output("Loading testprogram %s", PROGRAM_NAME);

	if(!bProgLoaded)
	{
		remote_set ( "ui_Close", -999, -1 );
		output ( "ready to close" );
		int i = remote_wait ( "ProgUnloaded", 120000 );
		output("ui closed");
	
		output ( "close done" );
		remote_set ( "ui_TestProgConfiguration", FLOW_NAME, -1 );
		remote_set ( "ui_Open", PROGRAM_NAME, -1 );
	
		output("ui_TestProgConfiguration=%s", remote_get ( "ui_TestProgConfiguration", -1 ));
		i = remote_wait ( "ProgLoaded",	240000 );
	
		output ( "remote wait ProgLoaded = %d", i );
	}
	
	if(!bDriverLoaded)
	{
		//load driver //m8p gpib
		TheDevice.SetDLL( DRIVER_DLL );
		output("driver = %s", DRIVER_DLL);
	
		TheDevice.init();
		if(	TheDevice.Hnd_Init() == FALSE)
		{
			AfxMessageBox("Handler/Prober did not initialize correctly. Please check GPIB connection.");
			warning( "Hnd_Init failure" );

			EnableWindow( get_HWND( vLoad	),  TRUE);
			EnableWindow( get_HWND( vPrgOpen	),  TRUE);
			EnableWindow( get_HWND( vDllOpen	),  TRUE);
			EnableWindow( get_HWND( vSWTOpen	),  TRUE);
			EnableWindow( get_HWND( vExit), TRUE);

			// enl 111017
			remote_fetch(bProgLoaded, 0, FALSE);
			if(bProgLoaded) {
				EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vLoad ), FALSE);
 				EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vUnload ), TRUE); 
				EnableWindow( get_HWND( vExit), FALSE);
			}

			return;
		}

		bDriverLoaded = TRUE;
	}//*/

	remote_send( OI_SITE_NUM, 0, FALSE );
	remote_send( LOT_NUM, 0, FALSE );

	CheckingVariables ();
	if(!read_switch_file ())
	{
		invoke(vUnload); // enl 102716

		//EnableWindow( get_HWND( vLoad	),  TRUE); // original

		//EnableWindow( get_HWND( vPrgOpen	),  TRUE); //NA
		//EnableWindow( get_HWND( vDllOpen	),  TRUE); //NA
		//EnableWindow( get_HWND( vSWTOpen	),  TRUE); //NA

		return;
	}

	remote_send( FLOW_NAME, 0, TRUE );                                

//	EnableWindow( get_HWND( vLoad	),  TRUE);
	EnableWindow( get_HWND( AutoProbe		),  TRUE);
	set_window_text(AutoProbe, "Start Auto Test" );

//	EnableWindow( get_HWND( StopAutoProbe	),  TRUE);

	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vWaferMap ), TRUE);
    EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vProbeCardMap ), TRUE);

	EnableWindow( get_HWND( vPrgOpen	),  TRUE);
	EnableWindow( get_HWND( vDllOpen	),  TRUE);
	EnableWindow( get_HWND( vSWTOpen	),  TRUE);

	EnableWindow( get_HWND( FK1	  ),  TRUE);
	EnableWindow( get_HWND( FK2	  ),  TRUE);
	EnableWindow( get_HWND( FK3	  ),  TRUE);
	EnableWindow( get_HWND( FK4	  ),  TRUE);
	EnableWindow( get_HWND( FK5	  ),  TRUE);
	EnableWindow( get_HWND( FK6	  ),  TRUE);
	EnableWindow( get_HWND( FK7	  ),  TRUE);
	EnableWindow( get_HWND( FK8	  ),  TRUE);
	EnableWindow( get_HWND( FK9	  ),  TRUE);
	EnableWindow( get_HWND( FK10	  ),  TRUE);
	EnableWindow( get_HWND( FK11	  ),  TRUE);
	EnableWindow( get_HWND( FK12	  ),  TRUE);
	EnableWindow( get_HWND( FK13	  ),  TRUE);
	EnableWindow( get_HWND( FK14	  ),  TRUE);
	EnableWindow( get_HWND( FK15	  ),  TRUE);
	EnableWindow( get_HWND( FK16	  ),  TRUE);

	EnableWindow( get_HWND( datalog_button	  ),  TRUE);

	if(oDriverType=="prober")
	{
		//enable wafermap orientation radio buttons
		EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, IDC_RADIO9	),  TRUE);
		EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, IDC_RADIO10),  TRUE);
		EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, IDC_RADIO11),  TRUE);
		EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, IDC_RADIO12),  TRUE);
	}

	enable_manual_buttons();
}

void clear_each_variables ( void )
{
	PROGRAM_NAME = ""; 
    DEVICE_NAME= ""; 
	LOT_NUM = ""; 
	FLOW_NAME = ""; 
	COMMENTS = ""; 
	USER_C = ""; 
    PROBE_CARD_ID = "";

	LATEST_WAFER_NUM = "0";
	STATUS_WAFERS = "0000000000000000000000000";
	
	remote_set ( FK1, FALSE, site_num(), TRUE );
	remote_set ( FK2, FALSE, site_num(), TRUE );
	remote_set ( FK3, FALSE, site_num(), TRUE );
	remote_set ( FK4, FALSE, site_num(), TRUE );
	remote_set ( FK5, FALSE, site_num(), TRUE );
	remote_set ( FK6, FALSE, site_num(), TRUE );
	remote_set ( FK7, FALSE, site_num(), TRUE );
	remote_set ( FK8, FALSE, site_num(), TRUE );
	remote_set ( FK9, FALSE, site_num(), TRUE );
	remote_set ( FK10, FALSE, site_num(), TRUE );
	remote_set ( FK11, FALSE, site_num(), TRUE );
	remote_set ( FK12, FALSE, site_num(), TRUE );
	remote_set ( FK13, FALSE, site_num(), TRUE );
	remote_set ( FK14, FALSE, site_num(), TRUE );
	remote_set ( FK15, FALSE, site_num(), TRUE );
	remote_set ( FK16, FALSE, site_num(), TRUE );

	set_window_text(datalog_button, "Datalog On" );
	invoke ( datalog_button );

	remote_set ( dlog, 1, site_num(), TRUE );
	remote_set ( para, FALSE, site_num(), TRUE );
	remote_set ( func, FALSE, site_num(), TRUE );
	remote_set ( user, FALSE, site_num(), TRUE );

	update_control(PROGRAM_NAME);
    update_control(DEVICE_NAME);
	update_control(LOT_NUM );
	update_control(FLOW_NAME );
	update_control(COMMENTS);
	update_control(USER_C);
    update_control(PROBE_CARD_ID);
    update_control(oi_OPERATOR_ID);

    update_control(LATEST_WAFER_NUM);
    update_control(STATUS_WAFERS);

	update_control(FK1 = FK1);
	update_control(FK2 = FK2);
	update_control(FK3 = FK3);
	update_control(FK4 = FK4);
	update_control(FK5 = FK5);
	update_control(FK6 = FK6);
	update_control(FK7 = FK7);
	update_control(FK8 = FK8);
	update_control(FK9 = FK9);
	update_control(FK10 = FK10);
	update_control(FK11 = FK11);
	update_control(FK12 = FK12);
	update_control(FK13 = FK13);
	update_control(FK14 = FK14);
	update_control(FK15 = FK15);
	update_control(FK16 = FK16);
}

VOID_VARIABLE( vReset, "" )
{
	int i = AfxMessageBox ( "!!! Are you sure to RESET ? !!!           ", MB_OKCANCEL );
	if ( i == 2 ) return;

	clear_each_variables ();

//	TheDevice.Hnd_Init();
//	TheDevice.Hnd_Poll();	// only poll
}

ONEOF_VARIABLE( dlog_pins, "All Pins, Passing Pins, Failing Pins, Headers Only, Off", "")
{
	if(dlog_pins=="All Pins")
	{
		//remote_set ( dlog, 4, site_num(), TRUE );
		remote_set ( dlog, 4, 0, TRUE );
	}
	if(dlog_pins=="Passing Pins")
	{
		//remote_set ( dlog, 3, site_num(), TRUE );
		remote_set ( dlog, 3, 0, TRUE );
	}
	if(dlog_pins=="Failing Pins")
	{
		//remote_set ( dlog, 2, site_num(), TRUE );
		remote_set ( dlog, 2, 0, TRUE );
	}
	if(dlog_pins=="Headers Only")
	{
		//remote_set ( dlog, 1, site_num(), TRUE );
		remote_set ( dlog, 1, 0, TRUE );
	}
	if(dlog_pins=="Off")
	{
		//remote_set ( dlog, 0, site_num(), TRUE );
		remote_set ( dlog, 0, 0, TRUE );
	}

	output("DEBUG: dlog = %d sent to HOST", dlog);
} 

VOID_VARIABLE( datalog_button, "" )
{
	CString t= get_window_text(datalog_button);

	if(t != "Datalog On")
	{ 
		set_window_text(PROBER_DIALOG_CUSTOMER, datalog_button, "Datalog On" );

		EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, IDC_RADIO4	),  TRUE);
		EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, IDC_RADIO5	),  TRUE);
		EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, IDC_RADIO6	),  TRUE);
		EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, IDC_RADIO7	),  TRUE);

		EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, IDC_DATALOG_PARA	  ),  TRUE);
		EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, IDC_DATALOG_FUNC	  ),  TRUE);
		EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, IDC_DATALOG_LVM	  ),  TRUE);
		EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, IDC_DATALOG_USER	  ),  TRUE);
		EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, IDC_DATALOG_FILE	  ),  TRUE);
		EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, IDC_DATALOG_SHMOO	  ),  TRUE);
		EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, IDC_DATALOG_SEARCH	  ),  TRUE);
		EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, IDC_DATALOG_VEC_CNT	  ),  TRUE);
	}
	else 
	{ 
		set_window_text(datalog_button, "Datalog Off" );
	
		remote_set ( dlog_pins, "Headers Only", site_num(), TRUE );
		remote_set ( para, FALSE, site_num(), TRUE );
		remote_set ( func, FALSE, site_num(), TRUE );
		remote_set ( user, FALSE, site_num(), TRUE );
		remote_set ( shmoo, FALSE, site_num(), TRUE );
		remote_set ( search, FALSE, site_num(), TRUE );
		remote_set ( fdlog, FALSE, site_num(), TRUE );

		update_control( dlog_pins);
		update_control( para = FALSE );
		update_control( func = FALSE );
		update_control( lvm = FALSE );
		update_control( user = FALSE );
		update_control( shmoo = FALSE );
		update_control( search = FALSE );
		update_control( fdlog = FALSE );

		EnableWindow( get_HWND( dlog_pins	),  FALSE);
		EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, IDC_RADIO5	),  FALSE);
		EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, IDC_RADIO6	),  FALSE);
		EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, IDC_RADIO7	),  FALSE);

		EnableWindow( get_HWND( para	  ),  FALSE);
		EnableWindow( get_HWND( func	  ),  FALSE);
		EnableWindow( get_HWND( lvm	  ),  FALSE);
		EnableWindow( get_HWND( user	  ),  FALSE);
		EnableWindow( get_HWND( shmoo	  ),  FALSE);
		EnableWindow( get_HWND( search	  ),  FALSE);
		EnableWindow( get_HWND( fdlog	  ),  FALSE);
		EnableWindow( get_HWND( DLog_vector_count	  ),  FALSE);
	}

	remote_send( dlog, 0, FALSE );
	remote_send( para, 0, FALSE );
	remote_send( func, 0, FALSE );
	remote_send( user, 0, FALSE );
	remote_send( shmoo, 0, FALSE );
	remote_send( search, 0, FALSE );
	remote_send( fdlog, 0, TRUE, INFINITE );
}

/*
VOID_VARIABLE ( vPause, "" ) 
{
	if ( bGPIB_MONITOR_PAUSE == FALSE )
	{
		bGPIB_MONITOR_PAUSE = TRUE;
		set_window_text(vPause, "Resume" );
	}
	else
	{
		bGPIB_MONITOR_PAUSE = FALSE;
		set_window_text(vPause, "Pause" );
	}
}
*/

VOID_VARIABLE(vPause, "") 
{
  bGPIB_MONITOR_PAUSE = TRUE;
}


void enable_manual_buttons()
{

   	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vCOF_Mode ), TRUE);
  	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vDebug_Mode ), TRUE);
  	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vManual_Continuity ), TRUE);
  	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vDatalog ), TRUE);
 	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vUnload ), TRUE);
 	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vHelp ), TRUE);

#if 0
	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vHnd_UnloadWafer	  ),	TheDevice.Hnd_UnloadWafer!=NULL ? TRUE : FALSE);
	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vHnd_LoadWafer	  ),		TheDevice.Hnd_LoadWafer!=NULL ? TRUE : FALSE);
	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vHnd_ZUp	  ),			TheDevice.Hnd_ZUp!=NULL ? TRUE : FALSE);
	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vHnd_ZDown	  ),			TheDevice.Hnd_ZDown!=NULL ? TRUE : FALSE);
	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vHnd_Move	  ),			TheDevice.Hnd_Move!=NULL ? TRUE : FALSE);
	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vHnd_Move_to_first	  ),	TheDevice.Hnd_Move_to_first!=NULL ? TRUE : FALSE);

//	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, BASE_X_COORD	  ),		TheDevice.Hnd_Move!=NULL ? TRUE : FALSE);
//	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, BASE_Y_COORD	  ),		TheDevice.Hnd_Move!=NULL ? TRUE : FALSE);
#endif
}

void disable_manual_buttons()
{
  	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vHelp ), FALSE);
  	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vCOF_Mode ), FALSE);
  	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vDebug_Mode ), FALSE);
  	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vManual_Continuity ), FALSE);
  	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vDatalog ), FALSE);
 	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vUnload ), FALSE);
 	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vHelp ), FALSE);

#if 0
	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vHnd_UnloadWafer	  ),	FALSE);
	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vHnd_LoadWafer	  ),		FALSE);
	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vHnd_ZUp	  ),			FALSE);
	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vHnd_ZDown	  ),			FALSE);
	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vHnd_Move	  ),			FALSE);
	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, vHnd_Move_to_first	  ),	FALSE);

//	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, BASE_X_COORD	  ),		FALSE);
//	EnableWindow( get_HWND( PROBER_DIALOG_CUSTOMER, BASE_Y_COORD	  ),		FALSE);
#endif
}

VOID_VARIABLE ( vWaferMap, "" ) 
{
	static bool first = true;

	remote_set( "ui_ShowTool", "WafermapTool", - 1, TRUE, INFINITE );
//	if(first) {
//		remote_set( "ui_HideTool", "WafermapTool", - 1, TRUE, INFINITE );
//		first = false;
//	}
}
VOID_VARIABLE ( vProbeCardMap, "" ) 
{
	//start the grid dialog here
}

VOID_VARIABLE ( vHnd_UnloadWafer, "" ) 
{
	CString cMsg;

	disable_manual_buttons();

	if(	TheDevice.Hnd_UnloadWafer())
	{
		cMsg = "Wafer unloaded successfully";
	}
	else
	{
		cMsg = "Problem unloading wafer";
	}

	output( cMsg );
	AfxMessageBox( cMsg, MB_OK | MB_SETFOREGROUND | MB_TOPMOST );

	enable_manual_buttons();
}

VOID_VARIABLE ( vHnd_LoadWafer, "" ) 
{
	CString cMsg;

	disable_manual_buttons();

	if(	TheDevice.Hnd_LoadWafer())
	{
		cMsg = "Wafer loaded successfully";
	}
	else
	{
		cMsg = "Problem loading wafer";
	}

	output( cMsg );
	AfxMessageBox( cMsg, MB_OK | MB_SETFOREGROUND | MB_TOPMOST );

	enable_manual_buttons();
}

VOID_VARIABLE ( vHnd_ZUp, "" ) 
{
	CString cMsg;

	disable_manual_buttons();

	if(	TheDevice.Hnd_ZUp())
	{
		cMsg = "Wafer Z Up successful";
	}
	else
	{
		cMsg = "Problem with Z Up";
	}

	output( cMsg );
	AfxMessageBox( cMsg, MB_OK | MB_SETFOREGROUND | MB_TOPMOST );

	enable_manual_buttons();
}

VOID_VARIABLE ( vHnd_ZDown, "" ) 
{
	CString cMsg;

	disable_manual_buttons();

	if(	TheDevice.Hnd_ZDown())
	{
		cMsg = "Wafer Z Down successful";
	}
	else
	{
		cMsg = "Problem with Z Down";
	}

	output( cMsg );
	AfxMessageBox( cMsg, MB_OK | MB_SETFOREGROUND | MB_TOPMOST );

	enable_manual_buttons();
}

VOID_VARIABLE ( vHnd_Move, "" ) 
{
	CString cMsg;

	disable_manual_buttons();

	update_variable(BASE_X_COORD);
	update_variable(BASE_Y_COORD);

	if(	TheDevice.Hnd_Move( BASE_X_COORD, BASE_Y_COORD))
	{
		cMsg = "Wafer Move successful";
	}
	else
	{
		cMsg = "Problem with Move";
	}

	output( cMsg );
	AfxMessageBox( cMsg, MB_OK | MB_SETFOREGROUND | MB_TOPMOST);

	enable_manual_buttons();
}

VOID_VARIABLE ( vHnd_Move_to_first, "" ) 
{
	CString cMsg;

	disable_manual_buttons();

	if(	TheDevice.Hnd_Move_to_first())
	{
		cMsg = "Wafer Move successful";
	}
	else
	{
		cMsg = "Problem with Move";
	}

	DevInfo = TheDevice.Hnd_GetInfo ();
	BASE_X_COORD = DevInfo.iX;
	BASE_Y_COORD = DevInfo.iY;
	update_control(BASE_X_COORD);
	update_control(BASE_Y_COORD);

	output( cMsg );
	AfxMessageBox( cMsg, MB_OK | MB_SETFOREGROUND | MB_TOPMOST);

	enable_manual_buttons();
}

VOID_VARIABLE ( vHIDDEN,	"" ) 
{
	// to convert default to <ENTER> to <TAB>
	HWND dlg = get_HWND(PROBER_DIALOG_CUSTOMER);
	HWND hwnd3 = GetFocus();

	HWND nextwnd = GetNextDlgTabItem ( dlg, hwnd3, false ); 
	
	SetFocus ( nextwnd );
}

DIALOG( SELECT_TEST_PROGRAM ) 
{
	CONTROL(IDC_SELECT_TEST_PROGRAM,		oPROGRAM_NAME		);
}

DIALOG( SELECT_DRIVER_DLL ) 
{
	CONTROL(IDC_DRIVER_DLL,		oDRIVER_DLL		);
}

DIALOG( SELECT_SWT ) 
{
	CONTROL(IDC_SWT,		oSWT		);
}

DIALOG(PROBER_DIALOG_CUSTOMER) 
{

  CONTROL(IDC_DATALOG_SETUP, oi_DATALOG_SETUP);
  IMMEDIATE_CONTROL(IDC_PRODUCT_ID, oi_PRODUCT_ID);
  CONTROL(IDC_SORT_ID, oi_SORT_ID);
  CONTROL(IDC_PROBECARD_ID, PROBE_CARD_ID);
  CONTROL(IDC_TEST_PROGRAM, oi_TEST_PROGRAM);
  CONTROL(IDC_RUNMODE_SELECTED, oi_RUNMODE_SELECTED);
  CONTROL(IDC_LOT_ID,  LOT_NUM);
  CONTROL(IDC_PROBER_LOT_ID,  oi_PROBER_LOT_ID);
  CONTROL(IDC_WAFER_ID,	LATEST_WAFER_NUM	);
  //CONTROL(IDC_WAFER_ID,  oi_WAFER_ID);
  CONTROL(IDC_TEST_PROGRAM_OUTPUT,  oi_TEST_PROGRAM_OUTPUT);
  CONTROL(IDC_TESTER_ID, oi_TESTER_ID);
  CONTROL(IDC_WAFER_MAP,  vWaferMap		);
  CONTROL(IDC_PROBECARD_MAP,  vProbeCardMap		);
  CONTROL(IDC_OPERATOR_ID, oi_OPERATOR_ID);
  //CONTROL(IDC_PRD_FILENAME, oi_PRD_FILENAME);

  CONTROL(IDC_PASS, oi_PASS);
  CONTROL(IDC_FAIL, oi_FAIL);
  CONTROL(IDC_TESTED, oi_TESTED);
  CONTROL(IDC_PASS_YIELD, oi_PASS_YIELD);
  CONTROL(IDC_FAIL_YIELD, oi_FAIL_YIELD);
  CONTROL(IDC_OI_REV,  OI_REV		);
  CONTROL(IDC_TEMPERATURE, CHUCK_TEMP);
  CONTROL(IDC_PROBER, PROBER_MSG);
  CONTROL(IDC_STATUS, STATUS_MSG);
  
  //CONTROL(IDC_START_TIME, TEST_START_TIME_GMT);
  CONTROL(IDC_START_TIME, TEST_START_TIME);
  CONTROL(IDC_TEST_TIME, TOTAL_TEST_TIME_GMT);

  IMMEDIATE_CONTROL(IDC_LOAD_PROGRAM, vLoad);
  IMMEDIATE_CONTROL(IDC_START_PAUSE_TEST, AutoProbe);
  IMMEDIATE_CONTROL(IDC_COF_MODE, vCOF_Mode);
  IMMEDIATE_CONTROL(IDC_DEBUG_MODE, vDebug_Mode);
  IMMEDIATE_CONTROL(IDC_MANUAL_CONTINUITY, vManual_Continuity);
  IMMEDIATE_CONTROL(IDC_DATALOG, vDatalog);
  IMMEDIATE_CONTROL(IDC_UNLOAD, vUnload);
  IMMEDIATE_CONTROL(IDC_EXIT_c, vExit);
  IMMEDIATE_CONTROL(IDC_HELP_c, vHelp);
  IMMEDIATE_CONTROL(IDCANCEL,  cExitDlg		);
  IMMEDIATE_CONTROL(IDC_USE_LOT_NUM_ENTRY,  bUseLotNumEntry		);
  	
#if 0
	IMMEDIATE_CONTROL(IDC_START_AUTO_PROBE,		AutoProbe		);
	IMMEDIATE_CONTROL(IDC_STOP_AUTO_PROBE,		StopAutoProbe	);
	IMMEDIATE_CONTROL(IDC_LOAD_BUTTON,			vLoad			);
	IMMEDIATE_CONTROL(IDC_RESET_BUTTON,			vReset			);
//	IMMEDIATE_CONTROL(IDC_PAUSE,				vPause			);
	IMMEDIATE_CONTROL(ID_WAFERLOAD,				vHnd_LoadWafer	);
	IMMEDIATE_CONTROL(ID_WAFERUNLOAD,			vHnd_UnloadWafer	);
	IMMEDIATE_CONTROL(ID_ZUP,					vHnd_ZUp	);
	IMMEDIATE_CONTROL(ID_ZDOWN,					vHnd_ZDown	);
	IMMEDIATE_CONTROL(ID_MOVE,					vHnd_Move	);
	IMMEDIATE_CONTROL(IDC_MOVE_TO_FIRST_DIE,	vHnd_Move_to_first	);
	IMMEDIATE_CONTROL(IDC_HIDDEN,				vHIDDEN	);
	IMMEDIATE_CONTROL(IDCANCEL,					cExitDlg		);

	CONTROL( IDC_X,	BASE_X_COORD);
	CONTROL( IDC_Y,	BASE_Y_COORD);

	CONTROL(IDC_PROGRAM_NAME,		PROGRAM_NAME		);
	CONTROL(IDC_DEVICE_NAME,		DEVICE_NAME			);
	CONTROL(IDC_LOT_NUM,			LOT_NUM				);
	CONTROL(IDC_FLOW_NAME,			FLOW_NAME			);
	CONTROL(IDC_COMMENTS,			COMMENTS			);
	CONTROL(IDC_USER_C,				USER_C				);
	CONTROL(IDC_DLL_NAME,			DRIVER_DLL			);
	CONTROL(IDC_SWT_NAME,			SWT					);
	CONTROL(IDC_PROBE_CARD_ID,		PROBE_CARD_ID		);

	CONTROL(IDC_LATEST_WAFER_NUM,	LATEST_WAFER_NUM	);
	CONTROL(IDC_TOUCHDOWNS,			TOUCHDOWNS	);
	CONTROL(IDC_STATUS_WAFERS,		STATUS_WAFERS		);

	IMMEDIATE_CONTROL(IDC_PRG_OPEN,			vPrgOpen	);
	IMMEDIATE_CONTROL(IDC_DLL_OPEN,			vDllOpen	);
	IMMEDIATE_CONTROL(IDC_SWT_OPEN,			vSWTOpen	);

	IMMEDIATE_CONTROL( IDC_DATALOG_BUTTON,		datalog_button	);

	IMMEDIATE_CONTROL( IDC_RADIO4,		dlog_pins );

	IMMEDIATE_CONTROL( IDC_RADIO9,		WM_ORIGIN );

	IMMEDIATE_CONTROL( IDC_DATALOG_PARA,	para	);
	IMMEDIATE_CONTROL( IDC_DATALOG_FUNC,	func	);
	IMMEDIATE_CONTROL( IDC_DATALOG_LVM,	    lvm	);
	IMMEDIATE_CONTROL( IDC_DATALOG_USER,	user	);
	IMMEDIATE_CONTROL( IDC_DATALOG_FILE,	fdlog	);

	IMMEDIATE_CONTROL( IDC_DATALOG_SHMOO,	shmoo	);
	IMMEDIATE_CONTROL( IDC_DATALOG_SEARCH,	search	);

	CONTROL( IDC_DATALOG_VEC_CNT,	DLog_vector_count);

 	IMMEDIATE_CONTROL( IDC_CHECK_FK1,	FK1		);
	IMMEDIATE_CONTROL( IDC_CHECK_FK2,	FK2		);
	IMMEDIATE_CONTROL( IDC_CHECK_FK3,	FK3		);
	IMMEDIATE_CONTROL( IDC_CHECK_FK4,	FK4		);
	IMMEDIATE_CONTROL( IDC_CHECK_FK5,	FK5		);
	IMMEDIATE_CONTROL( IDC_CHECK_FK6,	FK6		);
	IMMEDIATE_CONTROL( IDC_CHECK_FK7,	FK7		);
	IMMEDIATE_CONTROL( IDC_CHECK_FK8,	FK8		);
	IMMEDIATE_CONTROL( IDC_CHECK_FK9,	FK9		);
	IMMEDIATE_CONTROL( IDC_CHECK_FK10,	FK10	);
	IMMEDIATE_CONTROL( IDC_CHECK_FK11,	FK11	);
	IMMEDIATE_CONTROL( IDC_CHECK_FK12,	FK12	);
	IMMEDIATE_CONTROL( IDC_CHECK_FK13,	FK13	);
	IMMEDIATE_CONTROL( IDC_CHECK_FK14,	FK14	);
	IMMEDIATE_CONTROL( IDC_CHECK_FK15,	FK15	);
    IMMEDIATE_CONTROL( IDC_CHECK_FK16,	FK16	);

	//TOPMOST(FALSE);
#endif
}

DIALOG(DOUBLE_CHECK) 
{
  CONTROL(IDC_PRODUCT_ID_CHECK, PRODUCT_ID_chk);
  CONTROL(IDC_SORT_ID_CHECK, SORT_ID_chk);
  CONTROL(IDC_LOT_ID_CHECK, LOT_ID_chk);
  CONTROL(IDC_PROBECARD_ID_CHECK, PROBECARD_ID_chk);
  CONTROL(IDC_OPERATOR_ID_CHECK, OPERATOR_ID_chk);
  CONTROL(IDC_TEST_PROGRAM_CHECK, TEST_PROGRAM_chk);
  CONTROL(IDC_RUNMODESELECTED_CHECK, RUNMODESELECTED_chk);
}

VOID_VARIABLE(DIALOG_VALUE_READ, "") 
{
	char *libvar;

   /* Get the value of the LIB environment variable. */
	libvar = getenv( "TesterID" );

	remote_signal ( "ProgUnloaded", site_num() );

	HWND dlg = get_HWND(PROBER_DIALOG_CUSTOMER);
	SetWindowText(dlg, OI_REV);

}


CSTRING_VARIABLE( WFR_SLOT_ID, "0", "" ) { }
CSTRING_VARIABLE( CHUCK_TEMP, "----", "" ) { }
CSTRING_VARIABLE( WM_PROBER_FILE_NAME, "", "" ) { }
CSTRING_VARIABLE( WM_ORIENT, "", "" ) { }

EXTERN_CSTRING_VARIABLE( TOTAL_TEST_TIME_GMT	)

EXTERN_CSTRING_VARIABLE( WAFER_START_TIME_GMT	)
EXTERN_CSTRING_VARIABLE( WAFER_START_DATE		)
EXTERN_CSTRING_VARIABLE( WAFER_START_TIME		)
EXTERN_CSTRING_VARIABLE( WAFER_END_TIME_GMT		)
EXTERN_CSTRING_VARIABLE( WAFER_END_DATE			)
EXTERN_CSTRING_VARIABLE( WAFER_END_TIME			)

EXTERN_INT_VARIABLE ( WM_STARTX )
EXTERN_INT_VARIABLE ( WM_STARTY )

CSTRING_VARIABLE ( RAW_DATA_HEADER_STRING,	"", "" ) { }

/* original
void MkRawDataHeader ( void )
{
	RAW_DATA_HEADER_STRING = "";

	RAW_DATA_HEADER_STRING  = vFormat ( "%-32s", LOT_NUM );
	RAW_DATA_HEADER_STRING += vFormat ( "%-3s",WFR_SLOT_ID );
	RAW_DATA_HEADER_STRING += vFormat ( "%-16s",DEVICE_NAME );
	RAW_DATA_HEADER_STRING += vFormat ( "%-32s",SWT_File_Name );
	RAW_DATA_HEADER_STRING += vFormat ( "%-32s",TSK_PROGRAM_NAME );
	RAW_DATA_HEADER_STRING += vFormat ( " %s %s %s  %s %s %s", WAFER_START_DATE,WAFER_START_TIME,WAFER_START_TIME_GMT,WAFER_END_DATE,WAFER_END_TIME,WAFER_END_TIME_GMT );
	RAW_DATA_HEADER_STRING += vFormat ( " %-16s",PROBE_CARD_ID );
	RAW_DATA_HEADER_STRING += vFormat ( "%-16s","NA" );
	RAW_DATA_HEADER_STRING += vFormat ( "%-128s\n", COMMENTS );
	RAW_DATA_HEADER_STRING += vFormat ( "%-16s", TOTAL_TEST_TIME_GMT );

	CString cMsg = TSK_PROGRAM_DRV + TSK_PROGRAM_DIR;
	RAW_DATA_HEADER_STRING += vFormat ( "%-32s", cMsg );

	(CHUCK_TEMP == "25.0") ? cMsg = "NA" : cMsg = CHUCK_TEMP;
	RAW_DATA_HEADER_STRING += vFormat ( "%-16s", cMsg );

	RAW_DATA_HEADER_STRING += vFormat ( "%4d%4d %s %-20s\n",
												WM_STARTX,
												WM_STARTY,
												WM_ORIENT,
												WM_PROBER_FILE_NAME );
}
*/

// SMIC
void MkRawDataHeader ( void )
{
  RAW_DATA_HEADER_STRING = "";

  RAW_DATA_HEADER_STRING  = vFormat ( "Lot ID:%s\n", LOT_NUM );
  RAW_DATA_HEADER_STRING += vFormat ( "Wafer ID:%s\n",WFR_SLOT_ID );
  RAW_DATA_HEADER_STRING += vFormat ( "SMIC Prod ID:%s\n",oi_PRODUCT_ID );
  RAW_DATA_HEADER_STRING += vFormat ( "Test Program:%s\n",oi_TEST_PROGRAM );
  RAW_DATA_HEADER_STRING += vFormat ( "Tester ID:%s\n",oi_TESTER_ID );
  RAW_DATA_HEADER_STRING += vFormat ( "Operator ID:%s\n",oi_OPERATOR_ID );
  RAW_DATA_HEADER_STRING += vFormat ( "Start Time:%s %s\n", WAFER_START_DATE,WAFER_START_TIME);
  RAW_DATA_HEADER_STRING += vFormat ( "End Time:\n" );
  RAW_DATA_HEADER_STRING += vFormat ( "Notch Side:%s\n",Notch_side );
  RAW_DATA_HEADER_STRING += vFormat ( "Sort ID:%s\n",oi_SORT_ID );
  RAW_DATA_HEADER_STRING += vFormat ( "Bin Definition File:%s\n",oi_bin_def);
  RAW_DATA_HEADER_STRING += vFormat ( "Grid Xmax:%s\n",Grid_Xmax );
  RAW_DATA_HEADER_STRING += vFormat ( "Grid Ymax:%s\n",Grid_Ymax );
  RAW_DATA_HEADER_STRING += vFormat ( "Fab Site:%s\n",Fab_Site );
  RAW_DATA_HEADER_STRING += vFormat ( "Test Site:%s\n",Test_Site );
  RAW_DATA_HEADER_STRING += vFormat("Probe Card ID:%s\n", PROBE_CARD_ID);
  RAW_DATA_HEADER_STRING += vFormat("Load Board ID:%s\n", Load_Board_ID);
  RAW_DATA_HEADER_STRING += vFormat("ROM Code:%s\n", ROM_Code);
  RAW_DATA_HEADER_STRING += vFormat ( "X Die Size:%s\n",X_Die_Size );
  RAW_DATA_HEADER_STRING += vFormat ( "Y Die Size:%s\n",Y_Die_Size );
  RAW_DATA_HEADER_STRING += vFormat("X Street:%s\n", X_Street);
  RAW_DATA_HEADER_STRING += vFormat("Y Street:%s\n", Y_Street);
  RAW_DATA_HEADER_STRING += vFormat ( "Customer Code:%s\n",Customer_Code );
  RAW_DATA_HEADER_STRING += vFormat("Customer PartID:%s\n", Customer_PartID);

}

void display_xfer_user_vars (void) //output and load setup
{
	Magnum_UI_Version = current_release( );

	output("<<<<<<< User vars from Magnum_OI.ini file >>>>>>>");
	output("%25s : %-20s","TEST_PROGRAM_DIR",TEST_PROGRAM_DIR);
	output("%25s : %-20s","DRIVER_DLL_DIR",DRIVER_DLL_DIR);

	output("<<<<<<< User vars from .prd file >>>>>>>");
	output("%25s : %-20s","SMIC_Prod_ID",SMIC_Prod_ID);
	output("%25s : %-20s","Test_Program_Package",Test_Program_Package);
	output("%25s : %-20s","Test_Program_Directory",Test_Program_Directory);
	output("%25s : %-20s","Tester_Directory",Tester_Directory);
	output("%25s : %-20s","Test_flow",Test_flow);
	output("%25s : %-20s","Tester_ID",Tester_ID);
	output("%25s : %-20s","Test_Program",Test_Program);
	output("%25s : %-20s","Probe_Card_Setup_Name",Probe_Card_Setup_Name);
	output("%25s : %-20s","Notch_side",Notch_side);
	output("%25s : %-20s","Bin_Definition_File",Bin_Definition_File);
	output("%25s : %-20s","Grid_Xmax",Grid_Xmax);
	output("%25s : %-20s","Grid_Ymax",Grid_Ymax);
	output("%25s : %-20s","Fab_Site",Fab_Site);
	output("%25s : %-20s","Test_Site",Test_Site);
	output("%25s : %-20s","Probe_Card_ID",Probe_Card_ID);
	output("%25s : %-20s","WM_ORIGIN",WM_ORIGIN);
	output("%25s : %-20s","X_Die_Size",X_Die_Size);
	output("%25s : %-20s","Y_Die_Size",Y_Die_Size);
	output("%25s : %-20s","Customer_Code",Customer_Code);
	output("%25s : %-20d","Start_X_Address",Start_X_Address);
	output("%25s : %-20d","Start_Y_Address",Start_Y_Address);
	output("%25s : %-20d","End_X_Address",End_X_Address);
	output("%25s : %-20d","End_Y_Address",End_Y_Address);
	output("%25s : %-20d","Test_Site_Number",Test_Site_Number);
	output("%25s : %-20d","Gross_Die",Gross_Die);
	output("%25s : %-20d","Prr_Check_Number",Prr_Check_Number);
	output("%25s : %-20s","Magnum_UI_Version",Magnum_UI_Version);
	output("%25s : %-20s","Datalog_Setup",Datalog_Setup);
	output("%25s : %-20s","ReleaseTester",ReleaseTester);
	output("%25s : %-20s", "Sort_ID", Sort_ID);
	output("%25s : %-20s", "Load_Board_ID", Load_Board_ID);
	output("%25s : %-20s", "ROM_Code", ROM_Code);
	output("%25s : %-20s", "X_Die_Size", X_Die_Size);
	output("%25s : %-20s", "Y_Die_Size", Y_Die_Size);
	output("%25s : %-20s", "X_Street", X_Street);
	output("%25s : %-20s", "Y_Street", Y_Street);
	output("%25s : %-20s", "Customer_Code", Customer_Code);
	output("%25s : %-20s", "Customer_PartID", Customer_PartID);
	output("%25s : %-20s", "ServerDirectory", ServerDirectory);
	output("%25s : %-20d","OFFLINE_DEBUG",OFFLINE_DEBUG);
	output("");

	tpo = "<<<<<<<<< Checking Test Program Output Window >>>>>>\r\n"; // OI test program output window 
	uio = "<<<<<<<<< Checking UI Output Window >>>>>>\n"; // ui output
	line = "";
	line.Format("%25s : %-20s","Magnum_OI_Rev",OI_REV); tpo += line; tpo += "\r\n"; uio += line; uio += "\n";
	line.Format("%25s : %-20s","Magnum_UI_Version",Magnum_UI_Version); tpo += line; tpo += "\r\n"; uio += line; uio += "\n";
	line.Format("%25s : %-20s","Datalog_Setup",Datalog_Setup); tpo += line; tpo += "\r\n"; uio += line; uio += "\n";
	line.Format("%25s : %-20s","ReleaseTester",ReleaseTester); tpo += line; tpo += "\r\n"; uio += line; uio += "\n";
	oi_TEST_PROGRAM_OUTPUT = tpo;
	output(uio);

	// Transfer needed vars to OI vars
	// CSTRING_VARIABLES
	oi_DATALOG_SETUP = Datalog_Setup;

	// ONEOF_VARIABLES
	//set_choices( oi_PRODUCT_ID, SMIC_Prod_ID);
	set_choices( oi_SORT_ID, Sort_ID);
	set_choices( oi_TEST_PROGRAM, Test_Program);

	// Update Magnum_OI.ini vars with value coming from prd
	TEST_PROGRAM_DIR = Test_Program_Directory;

	// derived vars
	Test_flow_step = Test_flow.Right(1);

	output("%25s : %-20s","oi_TEST_PROGRAM",oi_TEST_PROGRAM);
	output("%25s : %-20s","TEST_PROGRAM_DIR",TEST_PROGRAM_DIR);
	output("%25s : %-20s","Test_flow_step",Test_flow_step);
}
