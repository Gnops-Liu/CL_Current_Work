#include "tester.h"
#include "Driver.h"
#include "Automation.h"
#include "dialog.h"
#include "wafermap.h"
#include "die_masking.h"
#include "ProbeCardSites.h"
#include "ShlObj.h"

#include "time.h"
void MyTimer(CString str)
{
         CString str1 = "MyTimer: ";
         CString str2 = " Start from:";
         str1 += str;
         str1 += " ";
         //str1 += str2;
         str1 += CTime::GetCurrentTime().Format("<COLOR = GREEN>%H:%M:%S<COLOR = BLACK>");
         output(str1);
}

TEST_TIMER TB_Timer; 
TEST_TIMER FTimer;
TEST_TIMER ATimer;

extern CString cOIOutput;

//range of dut is 0..MAX_DUTS-1
void get_xy( int dut, int *x, int *y);

__int64 readymask[60];		// magnum grande number

// interface to test programs
// shared events
VOID_VARIABLE( RUN_TESTS_HOST, ""){}
VOID_VARIABLE( MASK_SITES,"") {}
VOID_VARIABLE( START_OF_WAFER_EVENT, "") {}
VOID_VARIABLE( START_OF_LOT_EVENT, "") {}
VOID_VARIABLE( END_OF_WAFER_EVENT, "") {}
VOID_VARIABLE( END_OF_LOT_EVENT, "") {}
VOID_VARIABLE( DEV_READY_EVENT, "") {}

// active site slot
UINT64_VARIABLE ( ui_LoadedSlotMask, 0, "" ) { }
UINT64_VARIABLE ( ui_LoadedMask, 0, "" ) { }

BOOL_VARIABLE ( bTESTING_ONGOING, FALSE, "" ) { }
BOOL_VARIABLE ( bTESTER_SIMULATION_MODE, FALSE, "" ) { }
BOOL_VARIABLE ( bFIRST, TRUE, "" ) { }

// shared variables
// duts mask
INT64_VARIABLE( iv_init_dut_mask, 0, "" ) { }

// test results
CSTRING_VARIABLE ( cDutDatas, "", "" ) { }

// sites/controller
INT_VARIABLE ( SITE_PER_CONTROLLER_NUM, 2, "" ) { }
// max duts number/site
INT_VARIABLE ( MAX_DUT_NUM_PER_SITE, 6, "" ) { }

// max site slog
UINT64_VARIABLE ( iv_SiteMask, 0, "" ) { }

// probe card site infomation
CSTRING_VARIABLE ( cProbeCardSiteInfo , "", "" ) { }
CSTRING_VARIABLE ( WFR_ID , "", "" ) { }

// shared extern variables
// max slot number of ev 2, pv 5, sv 10, ssv 20, gv 40, gd 60
EXTERN_INT_VARIABLE ( MAX_SITES_NUM ) 

INT_VARIABLE( BASE_X_COORD, 99, "" ) { update_control(BASE_X_COORD);}
INT_VARIABLE( BASE_Y_COORD, 99, "" ) { update_control(BASE_Y_COORD);}

EXTERN_CSTRING_VARIABLE( PROGRAM_NAME )
EXTERN_CSTRING_VARIABLE( DEVICE_NAME )
EXTERN_CSTRING_VARIABLE( LOT_NUM )
EXTERN_CSTRING_VARIABLE( FLOW_NAME )

EXTERN_CSTRING_VARIABLE( COMMENTS )
EXTERN_CSTRING_VARIABLE( USER_C )
EXTERN_CSTRING_VARIABLE( PROBE_CARD_ID )

EXTERN_CSTRING_VARIABLE( WFR_SLOT_ID )
EXTERN_CSTRING_VARIABLE( CHUCK_TEMP )
INT_VARIABLE ( iWFR_SLOT_ID, 0, "" ) { } // used for debugs

EXTERN_CSTRING_VARIABLE( WM_PROBER_FILE_NAME )
EXTERN_CSTRING_VARIABLE( WM_ORIENT )

EXTERN_ONEOF_VARIABLE( oi_PRODUCT_ID )
EXTERN_CSTRING_VARIABLE(ServerDirectory)
EXTERN_INT_VARIABLE ( Gross_Die )	

// enl 112417 - WARNING!!! The four EXTERN vars below have a desirable effect fixing a possible problem.
// Without these lines, sDutInfoNum which tracks the total dies tested will just rollover (reset back) 
// after an increment when it reaches D_TOTAL_DUTS_ON_WAFER. In case you set the D_TOTAL_DUTS_ON_WAFER
// to a value lower than the total dies in the wafer, sDutInfoNum may have a wrong value after reaching 
// D_TOTAL_DUTS_ON_WAFER and will not reflect the actual number of duts already tested. This will affect
// the retest stage determination.
// If these lines are here, sDutInfoNum behaves normally and you will get a fatal error. If D_TOTAL_DUTS_ON_WAFER
// is set less that the total dies in a wafer, the sDutInfo[D_TOTAL_DUTS_ON_WAFER] structure will be out of bounds
// when sDutInfoNum is not rolling over (correct behavior). I thought this was due tothe integer size limit, but
// already tried long, ulong, etc. with the same result. I'm still trying to find out the cause of this, 
// but a simple solution will be to make sure that D_TOTAL_DUTS_ON_WAFER is set so much larger than the total dies 
// per wafer.
EXTERN_CSTRING_VARIABLE(oi_TEST_PROGRAM_OUTPUT)
EXTERN_CSTRING_VARIABLE(tpo)
EXTERN_CSTRING_VARIABLE(uio)
EXTERN_CSTRING_VARIABLE(line)
///////////// Lines above are needed for safety to make sure sDutInfoNum behaves correctly /////////

BOOL_VARIABLE( VERBOSITY, FALSE, "VERBOSITY"){}
BOOL_VARIABLE( OFFLINE_DEBUG, FALSE, "OFFLINE_DEBUG"){}
BOOL_VARIABLE( ONLINE_DEBUG, FALSE, "ONLINE_DEBUG"){}
BOOL_VARIABLE( TT_PROFILE, FALSE, "TT_PROFILE"){}
BOOL_VARIABLE( RAWDATA_DUMP, TRUE, "RAWDATA_DUMP"){}

// local variables
BOOL_VARIABLE( AutoTesting, TRUE, "Continue automatic test Loop"){}

INT_VARIABLE ( WM_STARTX, 0, "" ) { }		// 1st touch down location in a wafer.
INT_VARIABLE ( WM_STARTY, 0, "" ) { }		// 1st touch down location in a wafer.
INT_VARIABLE( iTOTAL_TEST_TIME_GMT, 0, "") { }

INT_VARIABLE(  Hnd_PositionMinY, 1000, ""){};
INT_VARIABLE(  Hnd_PositionMaxY, -1000, ""){};
INT_VARIABLE(  Hnd_PositionMinX, 1000, ""){};
INT_VARIABLE(  Hnd_PositionMaxX, -1000, ""){};

SNAPSHOT( WMAP_FIELD_OUTLINE )
{
	VARIABLE(Hnd_PositionMinY);
	VARIABLE(Hnd_PositionMaxY);
	VARIABLE(Hnd_PositionMinX);
	VARIABLE(Hnd_PositionMaxX);
};

BOOL_VARIABLE ( bFIRST_XY_COORDINATE, FALSE, "" ) { }

// pass/fail in probecard
int pass_fails[D_SITES_IN_PROBER];	// pass fail number.
// intefacebin(hardbin) in probecard
int intbin_info[D_SITES_IN_PROBER];	// bin category number.

// sites infomation of probecard.
int iSiteToDut[D_SITES_IN_PROBER];	
int iDutToSite[D_SITES_IN_PROBER];
  
// dut test results db
DutInfo sDutInfo[D_TOTAL_DUTS_ON_WAFER];
int		sDutInfoNum;
int		total_pass;	
int		total_fail;
int		Previous_sDutInfoNum; // enl 112417


// max duts number in probecard
INT_VARIABLE ( MAX_DUTS, 336, "" ) { }	// it will be auto calculated
INT_VARIABLE ( MAX_PH_SITES, 0, "" ) { }	

// test results files
CString cTempRawDataFileName="";
CString cRawDataFileName="";
CString cRawDataFileNameToServer="";
CString cRetestDataFileName=""; // enl 091117
CString cSwtFileName="";
CString cLogDir = "C:\\Log";
CString cLogRawDataDumpDir = "C:\\Log\\rawdata_dump";
CString cRawDataFileDir = "C:\\Datalogs\\rawdata";	//enl 112717 - Rawdata folder C:\\Datalogs\\rawdata\\1st5char of productid
CString cDatalogsDir = "C:\\Datalogs";
CString cRawDataDumpFileName="";

extern int Hnd_ProbeCardSiteLocationRelativeX[];
extern int Hnd_ProbeCardSiteLocationRelativeY[];
extern int Hnd_PositionX[];
extern int Hnd_PositionY[];

// -------------------
// 20081021 arayama
// it is no needed in TestProgram
// so this part must be CStrings.
// but I don't have the time to change.
CSTRING_VARIABLE( TEST_START_DATE, "", "") { }
CSTRING_VARIABLE( TEST_START_TIME, "", "") { }
CSTRING_VARIABLE( TEST_START_TIME_GMT, "", "") { }
CSTRING_VARIABLE( TEST_END_TIME_GMT, "", "") { }
CSTRING_VARIABLE( TOTAL_TEST_TIME_GMT, "", "") { }

CSTRING_VARIABLE( WAFER_START_TIME_GMT, "", "") { }
CSTRING_VARIABLE( WAFER_START_DATE, "", "") { }
CSTRING_VARIABLE( WAFER_START_TIME, "", "") { }
CSTRING_VARIABLE( WAFER_END_TIME_GMT, "", "") { }
CSTRING_VARIABLE( WAFER_END_DATE, "", "") { }
CSTRING_VARIABLE( WAFER_END_TIME, "", "") { }
CSTRING_VARIABLE( TOTAL_WAFER_TIME_GMT, "", "") { }

CSTRING_VARIABLE(RAWDATA_DATE, "", "") { }
CSTRING_VARIABLE(RAWDATA_TIME, "", "") { }
CSTRING_VARIABLE(RETESTDATA_DATE, "", "") { }
CSTRING_VARIABLE(RETESTDATA_TIME, "", "") { }

// -------------------



// local extern variables
EXTERN_BOOL_VARIABLE ( bGPIB_MONITOR_PAUSE )

EXTERN_CSTRING_VARIABLE (LATEST_WAFER_NUM)
EXTERN_CSTRING_VARIABLE (STATUS_WAFERS)

extern void MkRawDataHeader (void);
extern void Read_ProbeCardSiteInfo ( void );

EXTERN_CSTRING_VARIABLE ( RAW_DATA_HEADER_STRING )
EXTERN_CSTRING_VARIABLE ( TSK_PROGRAM_NAME )
EXTERN_CSTRING_VARIABLE ( TSK_PROGRAM_DIR )
EXTERN_CSTRING_VARIABLE ( TSK_PROGRAM_DRV )

void OfflineDebug_Warning()
{
	CString cMsg;
	cMsg = "<<<<<<<<  WARNING!!! OI is using OFFLINE_DEBUG  >>>>>>>>";
	output( "<COLOR=Red> %s </COLOR>", cMsg );
	AfxMessageBox( cMsg, MB_OK | MB_SETFOREGROUND | MB_TOPMOST );
}

// gpib infomations
devinfo	DevInfo;
CDriver		TheDevice;

void SwapData_Bin_PF ( void )
{
	int iWork[D_SITES_IN_PROBER];
	int i;

// bin swapping

	memset( iWork, 0, sizeof(int)*D_SITES_IN_PROBER);

	for ( i = 0; i < D_SITES_IN_PROBER; i++ )
	{
		if(iSiteToDut[i] == -1)
		{
			continue;
		}

		iWork[i] = intbin_info[iSiteToDut[i]];
	}

	for ( i = 0; i < D_SITES_IN_PROBER; i++ )
	{
		intbin_info[i] = iWork[i];
	}

// passfail swapping

	memset( iWork, 0, sizeof(int)*D_SITES_IN_PROBER);

	for ( i = 0; i < D_SITES_IN_PROBER; i++ )
	{
		if(iSiteToDut[i] == -1)
		{
			continue;
		}

		iWork[i] = pass_fails[iSiteToDut[i]];
	}

	for ( i = 0; i < D_SITES_IN_PROBER; i++ )
	{
		pass_fails[i] = iWork[i];
	}
}

// AnyReady( ) will return TRUE as soon as any index of array is TRUE. If none are  
// TRUE, FALSE is returned
bool AnyReady( bool *ReadyDutsArray)
{
	bool Ready = FALSE;
	int SiteNum, DutWithinSite;
	int TDUT_Num, x, y;

	// Clear readymask
	for ( int SiteCntr = 0; SiteCntr < MAX_SITES_NUM; SiteCntr++ )
		readymask[SiteCntr] = 0;

	for ( int dut = 0; dut < D_SITES_IN_PROBER; dut++ )
	{
		if ( ReadyDutsArray[dut] )
		{
			TDUT_Num = iSiteToDut[dut];
			SiteNum = TDUT_Num / MAX_DUT_NUM_PER_SITE;
			SiteNum *= SITE_PER_CONTROLLER_NUM;
			DutWithinSite = TDUT_Num % MAX_DUT_NUM_PER_SITE;

			get_xy( TDUT_Num, &x, &y);

			if ( VERBOSITY ) {
				if(TDUT_Num>=0)
					output("<COLOR=Blue> AnyReady() TDUT_Num=%d SiteNum=%d DutWithinSite=%d x=%d y=%d</COLOR>\\", TDUT_Num, SiteNum, DutWithinSite, x, y);
			}
			// Mark this dut as populated 
			if(oDriverType=="prober")
			{
				readymask[SiteNum] |= (__int64) get_mask(x,y) << DutWithinSite;
			}
			else
			{
				readymask[SiteNum] |= (__int64) 0x1 << DutWithinSite;
			}

			if ( VERBOSITY ) {
				if(TDUT_Num>=0)
					output("<COLOR=Blue> readymask[%d]=%d </COLOR>\\", SiteNum, readymask[SiteNum]);
			}
			Ready = TRUE;

			if ( VERBOSITY ) {
				if(TDUT_Num+1 > 0)
					output ( "PDUT%d mapping to TDUT%d is Ready", dut+1, TDUT_Num+1 );
			}
		}
	}
	return(Ready);
}

void Nxt_system( CString cOIcmd )
{
	STARTUPINFO sinfo;
	PROCESS_INFORMATION pinfo;

	ZeroMemory( &sinfo, sizeof( STARTUPINFO ) );
	ZeroMemory( &pinfo, sizeof( PROCESS_INFORMATION ) );
	
	sinfo.cb = sizeof( STARTUPINFO );
	sinfo.dwFlags = STARTF_USESHOWWINDOW;
	sinfo.wShowWindow = SW_SHOWNORMAL;

	if (!CreateProcess( NULL,
                     cOIcmd.GetBuffer(0),
                     NULL,
                     NULL,
                     FALSE,
                     0,
                     NULL,
                     NULL,
                     &sinfo,
                     &pinfo ) )
	{ 
		// if process error occur then quit
		CString cMsg;
		cMsg.Format ( "FATAL ERROR! during --- %s\n", (LPCTSTR)cOIcmd );
		AfxMessageBox(cMsg);
//		return;
	}

	cOIcmd.ReleaseBuffer();
}

void run_tests(void)
{

	for (int site = 0 ; site < MAX_SITES_NUM; site += SITE_PER_CONTROLLER_NUM) {
		if ( VERBOSITY ) output("iv_init_dut_mask 0x%I64x", readymask[site] );
		remote_set("iv_init_dut_mask", readymask[site], site+1);	
	}

	for (int site = 0 ; site < MAX_SITES_NUM; site += SITE_PER_CONTROLLER_NUM) {
		if ( VERBOSITY ) output("remote_send DEV_READY to site");
		remote_send( DEV_READY_EVENT, site+1, TRUE, INFINITE);
	}

	if ( VERBOSITY ) output("remote_send DEV_READY to host");
	remote_send( DEV_READY_EVENT, 0, TRUE, INFINITE);

}

void LotStartTime ( void )
{
	if ( COMMENTS.IsEmpty() ) {
		CString cMsg;
		CString cW;
	
		CString cWeek[] = { "x ", "Sun ", "Mon ", "Tue ", "Wed ", "Thr ", "Fri ", "Sat " };
		CString cMonth[] = { "x ", "Jan ", "Feb ", "Mar ", "Apr ", "May ", "Jun ", "Jul ", "Aug ", "Sep ", "Oct ", "Nov ", "Dec " };

		CTime ttime = CTime::GetCurrentTime();
		cMsg = ".....";	
		cMsg += cWeek[ttime.GetDayOfWeek()];
		cMsg += cMonth[ ttime.GetMonth()];
		cW.Format ( "%02d ", ttime.GetDay() );
		cMsg += cW;
		cW.Format ( "%02d:", ttime.GetHour() );
		cMsg += cW;
		cW.Format ( "%02d:", ttime.GetMinute() );
		cMsg += cW;
		cW.Format ( "%02d ", ttime.GetSecond() );
		cMsg += cW;
		cW.Format ( "%4d ", ttime.GetYear() );
		cMsg += cW;

		output ( "comments = %s\n", cMsg );

		COMMENTS.Format ( "%s", cMsg );

		output ( "comments = %s\n", COMMENTS );

		update_variable( COMMENTS );
		remote_send(COMMENTS, 0, FALSE);
		update_control(COMMENTS);
	}
}


void WaferStartTime ( void )
{
	CTime ttime = CTime::GetCurrentTime();
	WAFER_START_TIME_GMT = vFormat ( "%d", ttime );

	CString cMsg;

	//Start Time : 2017 / 09 / 10 18 : 51 : 51
	//	End Time : 2017 / 09 / 10 20 : 10 : 22

	// month:day:year 
	cMsg = vFormat("%04d/", ttime.GetYear());
	cMsg += vFormat("%02d/", ttime.GetMonth());
	cMsg += vFormat ( "%02d", ttime.GetDay() );

	WAFER_START_DATE = cMsg;

	//hour:minitus:second
	cMsg = vFormat ( "%02d:", ttime.GetHour() );
	cMsg += vFormat ( "%02d:", ttime.GetMinute() );
	cMsg += vFormat ( "%02d", ttime.GetSecond() );

	WAFER_START_TIME = cMsg;

	remote_send ( WAFER_START_TIME,			0, FALSE );
	remote_send ( WAFER_START_DATE,			0, FALSE );
	remote_send ( WAFER_START_TIME_GMT,		0, FALSE );

	output ( "Wafer Start Time = %s % s%s", WAFER_START_DATE, WAFER_START_TIME, WAFER_START_TIME_GMT );
}

void WaferEndTime ( void )
{
	CTime ttime = CTime::GetCurrentTime();
	WAFER_END_TIME_GMT = vFormat ( "%d", ttime );

	CString cMsg;

	//Start Time : 2017 / 09 / 10 18 : 51 : 51
	//	End Time : 2017 / 09 / 10 20 : 10 : 22

	// month:day:year 
	cMsg = vFormat("%04d\\/", ttime.GetYear());
	cMsg += vFormat("%02d\\/", ttime.GetMonth());
	cMsg += vFormat ( "%02d", ttime.GetDay() );

	WAFER_END_DATE = cMsg;

	//hour:minitus:second
	cMsg = vFormat ( "%02d:", ttime.GetHour() );
	cMsg += vFormat ( "%02d:", ttime.GetMinute() );
	cMsg += vFormat ( "%02d", ttime.GetSecond() );

	WAFER_END_TIME = cMsg;

	long int iTs = atol ( WAFER_START_TIME_GMT );
	long int iTe = atol ( WAFER_END_TIME_GMT );
	long int iTt = ( iTe - iTs );

	TOTAL_WAFER_TIME_GMT = vFormat ( "%ld", iTt );

	remote_send ( WAFER_END_TIME,		0, FALSE );
	remote_send ( WAFER_END_DATE,		0, FALSE );
	remote_send ( WAFER_END_TIME_GMT,	0, FALSE );

	output ( "Wafer End Time GMT = %s %s %s", WAFER_END_DATE, WAFER_END_TIME, WAFER_END_TIME_GMT );
}

void RawDataTime(void)
{
	CTime ttime = CTime::GetCurrentTime();

	CString cMsg;

	//Start Time : 2017 / 09 / 10 18 : 51 : 51
	//	End Time : 2017 / 09 / 10 20 : 10 : 22

	// month:day:year 
	cMsg = vFormat("%04d", ttime.GetYear());
	cMsg += vFormat("%02d", ttime.GetMonth());
	cMsg += vFormat("%02d", ttime.GetDay());

	RAWDATA_DATE = cMsg;

	//hour:minitus:second
	cMsg = vFormat("%02d", ttime.GetHour());
	cMsg += vFormat("%02d", ttime.GetMinute());
	cMsg += vFormat("%02d", ttime.GetSecond());

	RAWDATA_TIME = cMsg;

	remote_send(RAWDATA_DATE, 0, FALSE);
	remote_send(RAWDATA_TIME, 0, FALSE);

	output("RawDataTime = %s_%s", RAWDATA_DATE, RAWDATA_TIME);
}

void RetestDataTime(void)
{
	CTime ttime = CTime::GetCurrentTime();

	CString cMsg;

	//Start Time : 2017 / 09 / 10 18 : 51 : 51
	//	End Time : 2017 / 09 / 10 20 : 10 : 22

	// month:day:year 
	cMsg = vFormat("%04d", ttime.GetYear());
	cMsg += vFormat("%02d", ttime.GetMonth());
	cMsg += vFormat("%02d", ttime.GetDay());

	RETESTDATA_DATE = cMsg;

	//hour:minitus:second
	cMsg = vFormat("%02d", ttime.GetHour());
	cMsg += vFormat("%02d", ttime.GetMinute());
	cMsg += vFormat("%02d", ttime.GetSecond());

	RETESTDATA_TIME = cMsg;

	remote_send(RETESTDATA_DATE, 0, FALSE);
	remote_send(RETESTDATA_TIME, 0, FALSE);

	output("RetestDataTime = %s_%s", RETESTDATA_DATE, RETESTDATA_TIME);
}

void TestStartTime ( void )
{
	if ( TEST_START_TIME_GMT.IsEmpty() ) 
	{
		CTime ttime = CTime::GetCurrentTime();
		TEST_START_TIME_GMT = vFormat ( "%ld", ttime );

		output ( "Test Start Time is = %s", TEST_START_TIME_GMT );

		CString cMsg;

		//Start Time : 2017 / 09 / 10 18 : 51 : 51
		//	End Time : 2017 / 09 / 10 20 : 10 : 22

		// month:day:year 
		cMsg = vFormat("%04d/", ttime.GetYear());
		cMsg += vFormat("%02d/", ttime.GetMonth());
		cMsg += vFormat ( "%02d", ttime.GetDay() );

		TEST_START_DATE = cMsg;

		//hour:minitus:second
		cMsg = vFormat ( "%02d:", ttime.GetHour() );
		cMsg += vFormat ( "%02d:", ttime.GetMinute() );
		cMsg += vFormat ( "%02d", ttime.GetSecond() );

		TEST_START_TIME = cMsg;

		remote_send ( TEST_START_DATE,			0, FALSE );
		remote_send ( TEST_START_TIME,			0, FALSE );
		remote_send ( TEST_START_TIME_GMT,		0, FALSE );

		update_control(TEST_START_TIME); 

		output ( "TEST Start Time = %s % s%s", TEST_START_DATE, TEST_START_TIME, TEST_START_TIME_GMT );

	}
}

void TestEndTime ( void )
{
	CTime ttime = CTime::GetCurrentTime();
	TEST_END_TIME_GMT = vFormat ( "%ld", ttime );
	//output ( "Test End Time is = %s", TEST_END_TIME_GMT );

	long int iTs = atol ( TEST_START_TIME_GMT );
	long int iTe = atol ( TEST_END_TIME_GMT );
	long int iTt = ( iTe - iTs ) * 1000;

	TOTAL_TEST_TIME_GMT = vFormat ( "%ld", iTt );

	iTOTAL_TEST_TIME_GMT += iTt;
//	remote_send ( TOTAL_TEST_TIME_GMT, 0, FALSE );
	update_control(TOTAL_TEST_TIME_GMT);

	//output ( "Total Test Time = %s", TOTAL_TEST_TIME_GMT );
}


void  ShowWaferNumber ( void )
{
	LATEST_WAFER_NUM = WFR_SLOT_ID;

    update_control(LATEST_WAFER_NUM);
    update_control(STATUS_WAFERS);
}



void InitDB ( void )
{
	for ( int i = 0; i < D_SITES_IN_PROBER; i++ )
	{
		pass_fails[i] = 0;
		intbin_info[i] = 0;
	}

	for ( int j = 0; j < sDutInfoNum; j++ )
	{
		sDutInfo[j].x = 0;
		sDutInfo[j].y = 0;
		sDutInfo[j].HardBin = 0;
		sDutInfo[j].SoftBin = 0;
		sDutInfo[j].DutNumber = 0;
		sDutInfo[j].PassFail = 0;
		sDutInfo[j].TestTime = 0;
	}
	sDutInfoNum = 0;
	//sDutInfoNum = D_TOTAL_DUTS_ON_WAFER - 10; // enl debug to simulate reaching beyond D_TOTAL_DUTS_ON_WAFER during test
	
	// enl added 090817
	total_pass = 0;
	total_fail = 0;

	oi_PASS = 0;
	oi_FAIL = 0;
	oi_TESTED = 0;
	oi_PASS_YIELD.Empty();
	oi_FAIL_YIELD.Empty();

	update_control(oi_PASS);
	update_control(oi_FAIL);
	update_control(oi_TESTED);
	update_control(oi_PASS_YIELD);
	update_control(oi_FAIL_YIELD);

}

CString GetChrFromLine ( CString& cMsg )
{
	CString cRet;

	int i = cMsg.Find ( ",", 0 );
	if ( i != -1 ) {
		cRet = cMsg.Left(i);
		cMsg = cMsg.Right ( cMsg.GetLength() - i - 1 );
		return cRet;
	}

	cRet = "0";
	return cRet;
}

void SearchDouble ( void )
{
	BOOL flag = FALSE;

	if(bDISABLE_DUPLICATE_DIE)
	{
		return;
	}

	/* enl 112417 - can be anabled if needed
	output("Previous_sDutInfoNum=%d : sDutInfoNum=%d",Previous_sDutInfoNum,sDutInfoNum);
	if(sDutInfoNum < Previous_sDutInfoNum) { // enl 112417 to detect sDutInfoNum rollover problem
		CString cMsg = vFormat ( "WARNING!!! Rollover problem!!! sDutInfoNum=%d is less than Previous_sDutInfoNum=%d. Please unload the program", sDutInfoNum, Previous_sDutInfoNum );
		AfxMessageBox ( cMsg );
		warning( "%s", cMsg );
	}
	*/

	int i;
	for ( i = 0; i < sDutInfoNum; i++ )
	{
		if ( ( sDutInfo[sDutInfoNum].x == sDutInfo[i].x ) && ( sDutInfo[sDutInfoNum].y == sDutInfo[i].y ) )
		{
			sDutInfo[i].x			= sDutInfo[sDutInfoNum].x;
			sDutInfo[i].y			= sDutInfo[sDutInfoNum].y;
			sDutInfo[i].HardBin		= sDutInfo[sDutInfoNum].HardBin;
			sDutInfo[i].DutNumber	= sDutInfo[sDutInfoNum].DutNumber;
			sDutInfo[i].PassFail	= sDutInfo[sDutInfoNum].PassFail;
			sDutInfo[i].TestTime	= sDutInfo[sDutInfoNum].TestTime;

			sDutInfo[sDutInfoNum].x			= 0;
			sDutInfo[sDutInfoNum].y			= 0;
			sDutInfo[sDutInfoNum].HardBin	= 0;
			sDutInfo[sDutInfoNum].DutNumber	= 0;
			sDutInfo[sDutInfoNum].PassFail	= 0;
			sDutInfo[sDutInfoNum].TestTime	= 0;

			flag = TRUE;
			break;
		}
	}

	if(TT_PROFILE) TB_Timer.StartTimer("RAWDATA writing");
	if (flag) { // This is a retest die
		// enl 091317 added to write retest dies result on another file
		output("<COLOR=Red> <<<<< Duplicate x,y detected - RETEST! x=%d y=%d >>>>> </COLOR>", sDutInfo[i].x, sDutInfo[i].y);
		// SMIC Retest File
		FILE * File1;
		File1 = fopen ( cRetestDataFileName, "a" );
		if ( File1 == NULL ) 
		{
			CString cMsg = vFormat ( "Cannot open file1 %s", cRetestDataFileName );
			AfxMessageBox ( cMsg );
			output ( "%s", cMsg );
		} else {
			fprintf ( File1, "%4d %4d %4d %4d %4d %4d\n",
							sDutInfo[i].x,
							sDutInfo[i].y,
							sDutInfo[i].HardBin,
							sDutInfo[i].SoftBin,
							0,
							(sDutInfo[i].DutNumber)+1); // enl added 112517
			fclose ( File1 );
		}

		if(sDutInfo[i].PassFail)
		{ // if dut passed retest add it to total_pass remove in total_fail
			total_pass++;
			total_fail--;
		}
		// if dut failed retest no change in total_pass and total_fail
	}
	else { // This is a first test die
		// enl 091417 added to write raw dies result per touchdown
		FILE * File1;
		File1 = fopen ( cRawDataFileName, "a" );
		if ( File1 == NULL ) 
		{
			CString cMsg = vFormat ( "Cannot open file2 %s", cRawDataFileName );
			AfxMessageBox ( cMsg );
			output ( "%s", cMsg );
		} else {
			fprintf ( File1, "%4d %4d %4d %4d %4d %4d\n",
							sDutInfo[sDutInfoNum].x,
							sDutInfo[sDutInfoNum].y,
							sDutInfo[sDutInfoNum].HardBin,
							sDutInfo[sDutInfoNum].SoftBin,
							0,
							(sDutInfo[sDutInfoNum].DutNumber)+1); // enl added 112517
			fclose ( File1 );
		}

		if(sDutInfoNum > D_TOTAL_DUTS_ON_WAFER) { // enl 112417 to detect wrong setup of D_TOTAL_DUTS_ON_WAFER
			CString cMsg = vFormat ( "WARNING!!! D_TOTAL_DUTS_ON_WAFER value problem!!! sDutInfoNum=%d is now larger than D_TOTAL_DUTS_ON_WAFER=%d. Please unload the program", sDutInfoNum, D_TOTAL_DUTS_ON_WAFER );
			AfxMessageBox ( cMsg );
			warning( "%s", cMsg );
		}	

		if(sDutInfo[sDutInfoNum].PassFail)
			total_pass++;
		else
			total_fail++;

		sDutInfoNum++;

		//Previous_sDutInfoNum = sDutInfoNum; // enl 112417
	}
	if(TT_PROFILE) TB_Timer.StopTimer("RAWDATA writing2");

}

void CollectDB ( void )
{
	CString cTemp;
	int iSite, iDutNum, iEleNum;
	int x, y;
	int dut, ele;
	int iDatas[32];

	for ( int i = 0; i < D_SITES_IN_PROBER; i++ )
	{
		pass_fails[i] = 0;
		intbin_info[i] = 0;
	}

	for ( int site = 0; site <MAX_SITES_NUM; site += SITE_PER_CONTROLLER_NUM )
	{
		cTemp = remote_get (  cDutDatas, site + 1, FALSE );

//			  site,duts,elements,x,y,sbin,hbin,dutnum,pf,tt,x,y,sbin,hbin,dutnum,pf,tt 
//		cTemp = "1, 2, 7, 35, 36, 0, 7, 2, 1, 321233, 37,38, 0, 8, 3, 2, 98763,";

		iSite   = atoi ( GetChrFromLine ( cTemp ) );
		iDutNum = atoi ( GetChrFromLine ( cTemp ) );
		iEleNum = atoi ( GetChrFromLine ( cTemp ) );

		//output ( "%d, %d, %d", iSite,iDutNum,iEleNum );

		for ( dut = 0; dut < iDutNum; dut++ )
		{
			if(ONLINE_DEBUG) output("DEBUG: iDutToSite[%d]=%d", dut, iDutToSite[dut]);

			for ( ele = 0; ele < iEleNum; ele++ )
			{
				iDatas[ele] = atoi ( GetChrFromLine ( cTemp ) );
			}

			x = iDatas[0];
			y = iDatas[1];

//			if ( x < 0 || y < 0 ) continue; //does not allow -ve coords

			if(ONLINE_DEBUG) output("DEBUG: sDutInfoNum = %d", sDutInfoNum);

			sDutInfo[sDutInfoNum].x				= Hnd_PositionX[iDatas[4]];
			sDutInfo[sDutInfoNum].y				= Hnd_PositionY[iDatas[4]];
			sDutInfo[sDutInfoNum].SoftBin		= iDatas[2];
			sDutInfo[sDutInfoNum].HardBin		= iDatas[3];
			sDutInfo[sDutInfoNum].DutNumber		= iDatas[4];
			sDutInfo[sDutInfoNum].PassFail		= iDatas[5];
			sDutInfo[sDutInfoNum].TestTime		= iDatas[6];

			if(ONLINE_DEBUG) output ( "RAWDATA [%d][%d] %d, %d, %d, %d, %d", 
							sDutInfo[sDutInfoNum].x,
							sDutInfo[sDutInfoNum].y,
							sDutInfo[sDutInfoNum].SoftBin, 
							sDutInfo[sDutInfoNum].HardBin, 
							sDutInfo[sDutInfoNum].DutNumber,
							sDutInfo[sDutInfoNum].PassFail,
							sDutInfo[sDutInfoNum].TestTime);

			pass_fails[iDatas[4]] = iDatas[5];	// pass = 1, fail = 0;
			intbin_info[iDatas[4]] = iDatas[3];	// bins infomation
			//output("intbin_info[iDatas[4]] = %d", intbin_info[iDatas[4]]);

			//output("CollectDB: before SearchDouble: cRawDataFileName = %s", cRawDataFileName);
			//SearchDouble(); // enl 112717 - no need to check for duplicate x/y. Customer wafermap will take care of it

			// enl 091417 added to write raw dies result per touchdown
			FILE * File1;
			File1 = fopen ( cRawDataFileName, "a" );
			if ( File1 == NULL ) 
			{
				CString cMsg = vFormat ( "Cannot open file9 %s", cRawDataFileName );
				AfxMessageBox ( cMsg );
				output ( "%s", cMsg );
			} else {
				fprintf ( File1, "%4d %4d %4d %4d %4d %4d\n",
								sDutInfo[sDutInfoNum].x,
								sDutInfo[sDutInfoNum].y,
								sDutInfo[sDutInfoNum].HardBin,
								sDutInfo[sDutInfoNum].SoftBin,
								0,
								(sDutInfo[sDutInfoNum].DutNumber)+1); // enl added 112517
				fclose ( File1 );
			}
			if(RAWDATA_DUMP) {
				FILE * FileRDD;
				FileRDD = fopen ( cRawDataDumpFileName, "a" );
				if ( FileRDD == NULL ) 
				{
					CString cMsg = vFormat ( "Cannot open file3 %s", cRawDataDumpFileName );
					//AfxMessageBox ( cMsg );
					output ( "%s", cMsg );
				} else {
					fprintf ( FileRDD, "%4d %4d %4d %4d %4d %4d\n",
									sDutInfo[sDutInfoNum].x,
									sDutInfo[sDutInfoNum].y,
									sDutInfo[sDutInfoNum].HardBin,
									sDutInfo[sDutInfoNum].SoftBin,
									0,
									(sDutInfo[sDutInfoNum].DutNumber)+1); // enl added 112517
					fclose ( FileRDD );
				}
			}

			if(sDutInfo[sDutInfoNum].PassFail)
				total_pass++;
			else
				total_fail++;

			sDutInfoNum++;

			if(sDutInfoNum > D_TOTAL_DUTS_ON_WAFER) { // enl 112417 to detect wrong setup of D_TOTAL_DUTS_ON_WAFER
				CString cMsg = vFormat ( "WARNING!!! D_TOTAL_DUTS_ON_WAFER value problem!!! sDutInfoNum=%d is now larger than D_TOTAL_DUTS_ON_WAFER=%d. Please unload the program", sDutInfoNum, D_TOTAL_DUTS_ON_WAFER );
				AfxMessageBox ( cMsg );
				warning( "%s", cMsg );
			}

			//Previous_sDutInfoNum = sDutInfoNum; // enl 112417 - will later be used to detect rollover issues
			if(TT_PROFILE) TB_Timer.StopTimer("RAWDATA writing2");

		}
	}

	 // enl added 090817
	oi_PASS = total_pass;
	oi_FAIL = total_fail;
	oi_TESTED = sDutInfoNum;
	if(sDutInfoNum > 0) {
		oi_PASS_YIELD = vFormat("%3.2f %%", ((float)oi_PASS/(float)oi_TESTED)*100);
		oi_FAIL_YIELD = vFormat("%3.2f %%", ((float)oi_FAIL/(float)oi_TESTED)*100);
	}
	else {
		oi_PASS_YIELD = vFormat("%3.2f %%", 0);
		oi_FAIL_YIELD = vFormat("%3.2f %%", 0);
	}
	output("oi_PASS_YIELD = %s", oi_PASS_YIELD);

	update_control(oi_PASS);
	update_control(oi_FAIL);
	update_control(oi_TESTED);
	update_control(oi_PASS_YIELD);
	update_control(oi_FAIL_YIELD);

    output("DEBUG: CollectDB -  sDutInfoNum = %d", sDutInfoNum);

}

void MakeTempRawDataFileName ( void )
{
	cTempRawDataFileName = cRawDataFileDir;
	CreateDirectory ( cTempRawDataFileName, NULL );

	cTempRawDataFileName = cTempRawDataFileName + vFormat ( "\\%s", DEVICE_NAME );
	CreateDirectory ( cTempRawDataFileName, NULL );

	cTempRawDataFileName = cTempRawDataFileName + vFormat ( "\\%s", LOT_NUM );
	CreateDirectory ( cTempRawDataFileName, NULL );

	CString cM = WAFER_START_DATE.Mid ( 0, 2 );
	CString cD = WAFER_START_DATE.Mid ( 3, 2 );
	CString cH = WAFER_START_TIME.Mid ( 0, 2 );
	CString cN = WAFER_START_TIME.Mid ( 3, 2 );

	cTempRawDataFileName = cTempRawDataFileName + vFormat ( "\\%s_%s.temp_%s%s%s%s",
													LOT_NUM,
													WFR_SLOT_ID,
													cM,cD,cH,cN );
}

void MakeRawDataFileName ( void ) // enl 091417
{

	if(oi_PRODUCT_ID.IsEmpty()) {
		CString cMsg = vFormat ( "oi_PRODUCT_ID is Empty!!! Will use temp directory named Tmp9999");
		AfxMessageBox ( cMsg );
		output ( "%s", cMsg );
		oi_PRODUCT_ID = "Tmp9999";
	}

	cRawDataFileName = cRawDataFileDir + vFormat ( "\\%s", oi_PRODUCT_ID.Left(5) ); // enl 112717
	//CStringW wRawDataFileName = cRawDataFileName;
	//CreateDirectory ( cRawDataFileName, NULL ); // added to make sure log directory is created - enl 093017
	//SHCreateDirectory ( NULL, wRawDataFileName); // enl 112817 - need recursive directory creation

	// enl 112917 - Create directories in primitive one dir at a time to check if problem free
	CreateDirectory ( cDatalogsDir, NULL ); 
	CreateDirectory ( cRawDataFileDir, NULL ); 
	CreateDirectory ( cRawDataFileName, NULL ); 

	if(RAWDATA_DUMP) {
		cRawDataDumpFileName = cLogRawDataDumpDir + vFormat ( "\\%s", oi_PRODUCT_ID.Left(5) );
		CreateDirectory ( cLogDir, NULL ); 
		CreateDirectory ( cLogRawDataDumpDir, NULL ); 
		CreateDirectory ( cRawDataDumpFileName, NULL ); 
	}

//	Start Time : 2017 / 09 / 10 18 : 51 : 51
//		End Time : 2017 / 09 / 10 20 : 10 : 22

	RawDataTime();
	CString cTimeStamp = vFormat("%s_%s",RAWDATA_DATE,RAWDATA_TIME);
	cRawDataFileName += vFormat ( "\\%s-%s-%s-%s", LOT_NUM, LATEST_WAFER_NUM, oi_SORT_ID, cTimeStamp );
	//cRawDataFileNameToServer = ServerDirectory + vFormat("\\%s", oi_PRODUCT_ID.Left(5)) + vFormat("\\%s-%s-%s", LOT_NUM, LATEST_WAFER_NUM, oi_SORT_ID);
	cRawDataFileNameToServer = ServerDirectory + vFormat("\\%s-%s-%s", LOT_NUM, LATEST_WAFER_NUM, oi_SORT_ID);
	if (oi_RUNMODE_SELECTED == "Retest")
		cRawDataFileName += vFormat ( "-%s", "retest" );
	if(oi_RUNMODE_SELECTED == "Correlation")
		cRawDataFileName += vFormat ( "-%s", "corr" );

	if(RAWDATA_DUMP) {	
		cRawDataDumpFileName += vFormat ( "\\%s-%s-%s-%s", LOT_NUM, LATEST_WAFER_NUM, oi_SORT_ID, cTimeStamp );
		if(oi_RUNMODE_SELECTED == "Retest")
			cRawDataDumpFileName += vFormat ( "-%s", "retest" );
		if(oi_RUNMODE_SELECTED == "Correlation")
			cRawDataDumpFileName += vFormat ( "-%s", "corr" );
	}

	if(ONLINE_DEBUG) output("DEBUG: MakeRawDataFileName() : cRawDataFileName = %s", cRawDataFileName);
	MkRawDataHeader ();
	output("<<<<<<<<<<<< RAW_DATA_HEADER_STRING >>>>>>>>>>>>\n%s\n", RAW_DATA_HEADER_STRING);

	FILE * File1;
	File1 = fopen ( cRawDataFileName, "w" );
	if ( File1 == NULL ) 
	{
		CString cMsg = vFormat ( "Cannot open file4 %s", cRawDataFileName );
		AfxMessageBox ( cMsg );
		output ( "%s", cMsg );
	} else {
		fprintf ( File1, "%s", RAW_DATA_HEADER_STRING );
		fprintf ( File1, "%s\n", "RawData" );

		fclose ( File1 );
	}

	if(RAWDATA_DUMP) {
		FILE * FileRDD;
		FileRDD = fopen ( cRawDataDumpFileName, "w" );
		if ( FileRDD == NULL ) 
		{
			CString cMsg = vFormat ( "Cannot open file5 %s", cRawDataDumpFileName );
			//AfxMessageBox ( cMsg );
			output ( "%s", cMsg );
		} else {
			fprintf ( FileRDD, "%s", RAW_DATA_HEADER_STRING );
			fprintf ( FileRDD, "%s\n", "RawData" );

			fclose ( FileRDD );
		}
	}

}

void WriteRawDataFileEnd ( void ) // enl 091417
{
	// Need to insert the END TIME string into the per touchdown raw data file END TIME field.
	// Used built in nextest perl library to do inline edits to the raw data file. This is far more simple than using c-code.
	CString cmdline;
	cmdline.Format("perl -p -i.bak -e \"s/End Time:/End Time:%s %s/g\" %s", WAFER_END_DATE, WAFER_END_TIME, cRawDataFileName); 
	output("SYSTEM CMD: %s",cmdline); 
	system(cmdline);
	cmdline.Format("perl -p -i.bak -e \"eof && s/$/\\nDataEnd/\" %s", cRawDataFileName); 
	output("SYSTEM CMD: %s",cmdline); 
	system(cmdline);
	cmdline.Format("del /F /Q %s.bak", cRawDataFileName); 
	output("SYSTEM CMD: %s",cmdline); 
	system(cmdline); // remove backup file

	if(RAWDATA_DUMP) {
		FILE * FileRDD;
		FileRDD = fopen ( cRawDataDumpFileName, "a" );
		if ( FileRDD == NULL ) 
		{
			CString cMsg = vFormat ( "Cannot open file6 %s", cRawDataDumpFileName );
			//AfxMessageBox ( cMsg );
			output ( "%s", cMsg );
		} else {
			fprintf ( FileRDD, "DataEnd\n Gross Tested = %d End Time:%s %s\n", sDutInfoNum, WAFER_END_DATE, WAFER_END_TIME );
			fclose ( FileRDD );
		}
	}
}

void CopyRawDataFileToServer() { // enl 112817
	output("CopyRawDataFileToServer() : Gross_Die = %d sDutInfoNum = %d", Gross_Die, sDutInfoNum);
	if(Gross_Die == sDutInfoNum) { // copy to server
		CString cmdline;
		cmdline.Format("ECHO F|xcopy %s %s /y/e", cRawDataFileName, cRawDataFileNameToServer); // enl 112717 - echo F| to force an answer when xcopy asks if dest is "file or dir ?"
		output("%s", cmdline);
		system(cmdline);
	}
}



#if 0

void MakeRetestDataFileName ( void ) // enl 091117
{
	cRetestDataFileName = cRawDataFileDir;
	CreateDirectory ( cRetestDataFileName, NULL ); // added to make sure log directory is created - enl 093017

	if ( LOT_NUM.IsEmpty() ) LOT_NUM = "999";
	if ( LATEST_WAFER_NUM.IsEmpty() ) LATEST_WAFER_NUM = "999";
	if ( Test_flow_step.IsEmpty() ) Test_flow_step = "999";

	RetestDataTime();
	CString cTimeStamp = vFormat("%s_%s", RETESTDATA_DATE, RETESTDATA_TIME);
	cRetestDataFileName += vFormat("\\%s-%s-%s-%s-%s", LOT_NUM, LATEST_WAFER_NUM, oi_SORT_ID, cTimeStamp, "retest");

	if(ONLINE_DEBUG) output("DEBUG: MakeRetestDataFileName() : cRetestDataFileName = %s", cRetestDataFileName);
	MkRawDataHeader ();
	output("<<<<<<<<<<<< RAW_DATA_HEADER_STRING >>>>>>>>>>>>\n%s\n", RAW_DATA_HEADER_STRING);

	FILE * File1;

	File1 = fopen ( cRetestDataFileName, "w" );
	if ( File1 == NULL ) 
	{
		CString cMsg = vFormat ( "Cannot open file7 %s", cRetestDataFileName );
		AfxMessageBox ( cMsg );
		output ( "%s", cMsg );
	} else {

		fprintf ( File1, "%s", RAW_DATA_HEADER_STRING );
		fprintf ( File1, "%s\n", "RetestData" );

		fclose ( File1 );
	}
}

// WriteRawDataFile() is used for writing raw data for the whole wafer at WAFER_END signal 
void WriteRawDataFile ( void )
{
	/*
	cRawDataFileName = cRawDataFileDir;
	CreateDirectory ( cRawDataFileName, NULL );

	cRawDataFileName = cRawDataFileName + vFormat ( "\\%s", DEVICE_NAME );
	CreateDirectory ( cRawDataFileName, NULL );

	cRawDataFileName = cRawDataFileName + vFormat ( "\\%s", LOT_NUM );
	cSwtFileName = cRawDataFileName;
	CreateDirectory ( cRawDataFileName, NULL );

	CString cM = WAFER_END_DATE.Mid ( 0, 2 );
	CString cD = WAFER_END_DATE.Mid ( 3, 2 );
	CString cH = WAFER_END_TIME.Mid ( 0, 2 );
	CString cN = WAFER_END_TIME.Mid ( 3, 2 );

	cRawDataFileName = cRawDataFileName + vFormat ( "\\%s_%s.data_%s%s%s%s",
													LOT_NUM,
													WFR_SLOT_ID,
													cM,cD,cH,cN );
	*/

	cRawDataFileName = cRawDataFileDir;

	if ( LOT_NUM.IsEmpty() ) LOT_NUM = "999";
	if ( LATEST_WAFER_NUM.IsEmpty() ) LATEST_WAFER_NUM = "999";
	if ( Test_flow_step.IsEmpty() ) Test_flow_step = "999";

	cRawDataFileName += vFormat ( "\\%s-%s-%s-%s", LOT_NUM, LATEST_WAFER_NUM, Test_flow_step, oi_SORT_ID );
	if(oi_RUNMODE_SELECTED == "Retest")
		cRawDataFileName += vFormat ( "-%s", "retest" );
	if(oi_RUNMODE_SELECTED == "Correlation")
		cRawDataFileName += vFormat ( "-%s", "corr" );

	if(ONLINE_DEBUG) output("DEBUG: cRawDataFileName = %s", cRawDataFileName);
	MkRawDataHeader ();
	output("<<<<<<<<<<<< RAW_DATA_HEADER_STRING >>>>>>>>>>>>\n%s\n", RAW_DATA_HEADER_STRING);

	FILE * File1;

	File1 = fopen ( cRawDataFileName, "w" );
	if ( File1 == NULL )
	{
		CString cMsg = vFormat ( "Cannot open file8 %s", cRawDataFileName );

		AfxMessageBox ( cMsg );
		output ( "%s", cMsg );
	} else {
		fprintf ( File1, "%s", RAW_DATA_HEADER_STRING );
		fprintf ( File1, "\n%s\n", "RawData" );
		for ( int i = 0; i < sDutInfoNum; i++ ) // this is total duts tested used for end of wafer computation
		{
			if ( File1 != NULL )
			{
				/*
				fprintf ( File1, "%4d%4d%4d%4d%4d%12d\n",
									sDutInfo[i].x,
									sDutInfo[i].y,
									sDutInfo[i].SoftBin,
									sDutInfo[i].DutNumber,
									sDutInfo[i].PassFail,
									sDutInfo[i].TestTime ); */

				fprintf ( File1, "%4d%4d%4d%4d%4d\n",
									sDutInfo[i].x,
									sDutInfo[i].y,
									sDutInfo[i].HardBin,
									sDutInfo[i].SoftBin,
									0 );
			}
		}
		fprintf ( File1, "%s", "DataEnd\n" );
		fclose ( File1 );
	}
}

void WriteRetestDataFileEnd ( void ) // enl 091417
{
	// Need to insert the END TIME string into the per touchdown retest data file END TIME field.
	// Used built in nextest perl library to do inline edits to the retest data file. This is far more simple than using c-code.
	CString cmdline;
	cmdline.Format("perl -p -i.bak -e \"s/End Time:/End Time:%s %s/g\" %s", WAFER_END_DATE, WAFER_END_TIME, cRetestDataFileName); 
	output("SYSTEM CMD: %s",cmdline); 
	system(cmdline);
	cmdline.Format("perl -p -i.bak -e \"eof && s/$/\\nRetestEnd/\" %s", cRetestDataFileName); 
	output("SYSTEM CMD: %s",cmdline); 
	system(cmdline);
	cmdline.Format("del /F /Q %s.bak", cRetestDataFileName); 
	output("SYSTEM CMD: %s",cmdline); 
	system(cmdline); // remove backup file
}

#endif 



int bits(__int64 val)
{
	int cnt=0;

	for( int i=0; i<(8*sizeof(__int64)); i++)
	{
		if( val & 0x1) cnt++;
		val >>= 0x1;
	}

	return cnt;
}

//---------------------------
//
// start up variable constructor
//
//---------------------------

void CheckingVariables ( void )
{
	remote_fetch ( SITE_PER_CONTROLLER_NUM, 0, FALSE );
	remote_fetch ( MAX_DUT_NUM_PER_SITE, 0, FALSE );

	if ( SITE_PER_CONTROLLER_NUM == 0 || MAX_DUT_NUM_PER_SITE == 0 )
	{
		output ( "SITE_PER_CONTROLLER_NUM or MAX_DUT_NUM_PER_SITE was ZERO" );
		fatal ( "!!! Error !!!" );
	}
}

//---------------------------
//
// prober wafermap xy calc
//
//---------------------------

void CalcXYCoordinate ( void )
{
	Hnd_PositionMinY = 1000;
	Hnd_PositionMinX = 1000;
	Hnd_PositionMaxY = -1000;
	Hnd_PositionMaxX = -1000;

	if(oDriverType == "handler")
	{
		return;
	}

	cProbeCardSiteInfo = vFormat ( "%d,", MAX_DUTS );

	int i;
	for ( i = 0; i < MAX_DUTS; i++ )
	{
		Hnd_PositionX [i] = BASE_X_COORD + Hnd_ProbeCardSiteLocationRelativeX [i];
		Hnd_PositionY [i] = BASE_Y_COORD + Hnd_ProbeCardSiteLocationRelativeY [i];
		cProbeCardSiteInfo = cProbeCardSiteInfo + vFormat ( " %d, %d,", Hnd_PositionX[i], Hnd_PositionY[i] );

		if(Hnd_PositionY[i] < Hnd_PositionMinY) Hnd_PositionMinY = Hnd_PositionY[i];
		if(Hnd_PositionX[i] < Hnd_PositionMinX) Hnd_PositionMinX = Hnd_PositionX[i];
		if(Hnd_PositionY[i] > Hnd_PositionMaxY) Hnd_PositionMaxY = Hnd_PositionY[i];
		if(Hnd_PositionX[i] > Hnd_PositionMaxX) Hnd_PositionMaxX = Hnd_PositionX[i];
	}

	remote_send ( cProbeCardSiteInfo,	0, FALSE );
	remote_send ( WMAP_FIELD_OUTLINE,	0, FALSE );

	/* enl - may implement later, but will need test program mods 
	if(TT_PROFILE) TB_Timer.StartTimer("remote_send cProbeCardSiteInfo to all sites");
	// enl 112417 - send to sites so that the sites will not need to get from the host which can have tt variance between sites
	for (int site = 0 ; site < MAX_SITES_NUM; site += SITE_PER_CONTROLLER_NUM) {
		remote_send ( cProbeCardSiteInfo,	site+1, FALSE );
		if(ONLINE_DEBUG) output("cProbeCardSiteInfo remote_send to site%d", site+1 );
	}
	if(TT_PROFILE) TB_Timer.StopTimer("remote_send cProbeCardSiteInfo to all sites - END");
	*/

}

VOID_VARIABLE( vCalcXYCoordinate, "")
{
	CalcXYCoordinate();
}

//return current x/y die coordinates tested by dut 
//range of dut is 0..MAX_DUTS-1

void get_xy( int dut, int *x, int *y)
{
	*x = Hnd_PositionX[dut];
	*y = Hnd_PositionY[dut];
}

void read_ini()
{
	CString ini = "Magnum_OI.ini";

	if(!set_values_from_file(ini))
	{
		output("could not read file %s, using default values", ini);
	}

	output("dlog_pins = %s", dlog_pins);

	if(dlog_pins=="All Pins")
	{
		 dlog = 4;
	}
	if(dlog_pins=="Passing Pins")
	{
		dlog = 3;
	}
	if(dlog_pins=="Failing Pins")
	{
		dlog = 2;
	}
	if(dlog_pins=="Headers Only")
	{
		dlog = 1;
	}

	update_controls(PROBER_DIALOG_CUSTOMER);
}


//---------------------------
//
// MAIN
//
//---------------------------
CString cOIOutput = "";

BOOL my_output_callback( char type, CString string ) {
	// ID if message was output(), warning(), or fatal()
	char *id = 0;
	if( type == 'w' ) id = "My Warning: ";
	if( type == 'f' ) id = "My Fatal: ";
	if( type == 'o' ) id = "My Output: ";
	// Display the message
	//TRACE( "%s%s", id, string ); // For Developer Studio Output only
	//output("%s%s", id, string ); // For UI output
	cOIOutput += string;
	return TRUE; // Pass string to UI
}

VOID_VARIABLE( AutoTestLoop, "" )
{
	//intercept( my_output_callback );
	//CString s; 
	//s = "c:/Log/log_%S_";
	//s += CTime::GetCurrentTime().Format("%y%m%d_%H%M%S.txt");
	//remote_set( "ui_OutputFile", s, -1, TRUE, INFINITE );

	static bool first = true;

	bool *DutsToTestArray; // This will be a unsigned __int64 if 64 or less duts
	bool ReadyToStart = FALSE; 
	unsigned int LoopCntr = 0;

	// enl 062217 - do not auto start the prober. Let operator start the prober.
	//if(TheDevice.Hnd_Start!=NULL)
	//{
	//	TheDevice.Hnd_Start();
	//}


	while ( AutoTesting )
	{
		ATimer.StartTimer("AutoTesting Start");

			if (VERBOSITY) output("Inside AutoTestLoop %d", LoopCntr++);

			if ( VERBOSITY && bGPIB_MONITOR_PAUSE == TRUE ) output ( "<COLOR=Red> !!! PAUSE !!! </COLOR>" ); 
			while ( bGPIB_MONITOR_PAUSE == TRUE ) 
			{
				remote_wait ( "IwantToBelieve", 500 );
			}
		
			// waiting auto testing start

			if(TT_PROFILE) TB_Timer.StartTimer("Hnd_Poll 1 ");
			DutsToTestArray = TheDevice.Hnd_Poll();
			if(TT_PROFILE) TB_Timer.StopTimer("Hnd_Poll 2 ");

if( OFFLINE_DEBUG ) {
			//if(!TT_PROFILE) OfflineDebug_Warning();
			output("<COLOR=Blue> DEBUG: Forcing DutsToTestArray to have active duts</COLOR>");
			for ( int i = 0; i < MAX_DUTS; i++ ) DutsToTestArray[i]=1;
}			
if( ONLINE_DEBUG ) {
			output("<COLOR=Blue> MAX_DUTS = %d : DutsToTestArray = </COLOR>\\", MAX_DUTS);
			for ( int i = 0; i < MAX_DUTS; i++ ) output("<COLOR=Blue>%d</COLOR>\\",DutsToTestArray[i]);
			output("\n");
}

			if(TT_PROFILE) TB_Timer.StartTimer("Hnd_GetInfo 1 ");
			DevInfo = TheDevice.Hnd_GetInfo();
			if(TT_PROFILE) TB_Timer.StopTimer("Hnd_GetInfo 2 ");

			// check sites status instead of hostmon.
			remote_fetch ( ui_LoadedSlotMask, -1, FALSE );
			if ( VERBOSITY ) output("ui_LoadedSlotMask = 0x%I64X", ui_LoadedSlotMask );

			// GPIB error should be quit.
			if( DevInfo.iPollResult == DEV_COMM_ERROR )
			{
				if ( VERBOSITY ) output("GPIB Error");
			}

			//
			// START OF WAFER EVENT
			//
			if( DevInfo.iPollResult == DEV_START_OF_WAFER )
			{
				if(TT_PROFILE) TB_Timer.StartTimer("DEV_START_OF_WAFER ");
				if (VERBOSITY)
					output("<COLOR=Green> <<<<< DEV_START_OF_WAFER received >>>>> </COLOR>");
				LOT_NUM = DevInfo.cLot; //A8P
				WFR_SLOT_ID = vFormat("%02d",DevInfo.iWafer);
				if(ONLINE_DEBUG) output("WFR_SLOT_ID = %s", WFR_SLOT_ID);
				oi_WAFER_ID = DevInfo.cWaferID;
				//update_control(oi_WAFER_ID); // enl 111717

				STATUS_WAFERS = DevInfo.cWaferStatus;

				CHUCK_TEMP = vFormat ( "%3.1f C",(DevInfo.fChuck_temp)/10 );				
				update_control(CHUCK_TEMP); //enl 110817 to display Prober temperature on the dialog

				WM_ORIENT = DevInfo.cFlat;
				WM_PROBER_FILE_NAME = DevInfo.cProbeCard_name;

				oi_PROBER_LOT_ID = vFormat("%s",DevInfo.cLot); //enl 112317
				if(ONLINE_DEBUG) output("oi_PROBER_LOT_ID = %s", oi_PROBER_LOT_ID);
				update_control(oi_PROBER_LOT_ID);
				if(oi_PROBER_LOT_ID.IsEmpty() && !bUseLotNumEntry) {
					output("!!! AutoTesting ERROR: PROBER LOT ID is EMPTY! LOT_NUM will be set as 999");
					//AfxMessageBox("!!! AutoTesting ERROR: PROBER LOT ID is EMPTY !!!");
					oi_PROBER_LOT_ID = vFormat("%s","PRBLOTID_9999");
					update_control(oi_PROBER_LOT_ID);
				}
				if(!bUseLotNumEntry) { //enl 112317 - If lotnumber entry in OI is disabled, Use the lot number coming from the prober 
					CString old_LOT_NUM = LOT_NUM;
					LOT_NUM = oi_PROBER_LOT_ID;
					update_variable(LOT_NUM);
					update_control(LOT_NUM);
					output("Entered LOT_NUM %s is now overwritten by oi_PROBER_LOT_ID %s", old_LOT_NUM, oi_PROBER_LOT_ID);
				} 

				remote_send ( LOT_NUM,					0, FALSE );
				remote_send ( WFR_SLOT_ID,				0, FALSE );
				remote_send ( CHUCK_TEMP,				0, FALSE );
				remote_send ( PROBE_CARD_ID,			0, FALSE );

				output("<COLOR=Blue><<< DEV_START_OF_WAFER received WFR_SLOT_ID = %s >>></COLOR>", WFR_SLOT_ID);

				LotStartTime ();
				WaferStartTime ();
				ShowWaferNumber ();

				//if (first) { //enl 102717 only execute one time
					MakeRawDataFileName();
					first = FALSE;
				//}

				//read_die_mask_file(); // enl 111717b not needed

				iTOTAL_TEST_TIME_GMT = 0;
	
				remote_send( START_OF_WAFER_EVENT, 0, TRUE, INFINITE);
	
				if ( VERBOSITY ) output("First Die");

				// enl 102617 to display Prober temperature in both OI and UI
				//line = "";
				//line.Format("%25s : %-20s","Prober Temperature", CHUCK_TEMP); tpo += line; tpo += "\r\n"; uio += line; uio += "\n";
				//output(uio);
				//oi_TEST_PROGRAM_OUTPUT = tpo;
				//update_control(oi_TEST_PROGRAM_OUTPUT);
				if(TT_PROFILE) TB_Timer.StopTimer("DEV_START_OF_WAFER2 ");
			}
	
			//
			// START OF LOT EVENT
			//
			if( DevInfo.iPollResult == DEV_START_OF_LOT )
			{
				if(TT_PROFILE) TB_Timer.StartTimer("DEV_START_OF_LOT ");
				remote_send( START_OF_LOT_EVENT, 0, TRUE, INFINITE);
				if ( VERBOSITY ) output("First Wafer");

				if(TT_PROFILE) TB_Timer.StopTimer("DEV_START_OF_LOT2");
			}
	
			//
			// LOT END EVENT
			//
			if( DevInfo.iPollResult == DEV_END_OF_LOT)
			{
				if(TT_PROFILE) TB_Timer.StartTimer("DEV_END_OF_LOT ");
				COMMENTS = "";
				update_variable( COMMENTS );
				remote_send(COMMENTS, 0, FALSE);
				update_control(COMMENTS);
	
				remote_send( END_OF_LOT_EVENT, 0, TRUE, INFINITE);
				if ( VERBOSITY ) output("Lot end");

				if(TT_PROFILE) TB_Timer.StopTimer("DEV_END_OF_LOT2");
			}
	
			//
			// WAFER END EVENT
			//
			if( DevInfo.iPollResult == DEV_END_OF_WAFER)
			{
				if(TT_PROFILE) TB_Timer.StartTimer("DEV_END_OF_WAFER ");
				if (VERBOSITY)
					output("<COLOR=Green> <<<<< DEV_END_OF_WAFER received >>>>> </COLOR>", sDutInfo[sDutInfoNum].x, sDutInfo[sDutInfoNum].y);
				bFIRST_XY_COORDINATE = FALSE;
				WaferEndTime ();
				WriteRawDataFileEnd();	
				CopyRawDataFileToServer(); // enl 112717

	           if ( VERBOSITY ) output ( "Total Test Time = %s", TOTAL_TEST_TIME_GMT );
				TEST_START_TIME_GMT = "";
	
				remote_send( END_OF_WAFER_EVENT, 0, TRUE, INFINITE);
	            if ( VERBOSITY ) output("TSK Tool:Wafer End");
	
				//wafermap_summaries();

				InitDB ();
				if(TT_PROFILE) TB_Timer.StopTimer("DEV_END_OF_WAFER2");
			}

			//
			// DEV_READY EVENT
			//
			if( DevInfo.iPollResult == DEV_READY )
			{
		FTimer.StartTimer("DEV_READY");
			
if( OFFLINE_DEBUG ) {
					output("Inside OFFLINE_DEBUG");
				///// This is just for offline debug. This should happen at Wafer Start /////
				//if(!TT_PROFILE) OfflineDebug_Warning();
				if(bFIRST) {
					WFR_SLOT_ID = vFormat("%02d", ++iWFR_SLOT_ID);
					oi_PROBER_LOT_ID = vFormat("%s","PRBLOTID_9999");
					update_control(oi_PROBER_LOT_ID);
					if(oi_PROBER_LOT_ID.IsEmpty() && !bUseLotNumEntry) {
						output("!!! AutoTesting ERROR: PROBER LOT ID is EMPTY! LOT_NUM will be set as 999");
						//AfxMessageBox("!!! AutoTesting ERROR: PROBER LOT ID is EMPTY !!!");
					}
					if(!bUseLotNumEntry) { //enl 112317 - If lotnumber entry in OI is disabled, Use the lot number coming from the prober 
						CString old_LOT_NUM = LOT_NUM;
						LOT_NUM = oi_PROBER_LOT_ID;
						update_variable(LOT_NUM);
						update_control(LOT_NUM);
						output("Entered LOT_NUM %s is now overwritten by oi_PROBER_LOT_ID %s", old_LOT_NUM, oi_PROBER_LOT_ID);
					} 
					LotStartTime ();
					WaferStartTime ();
					ShowWaferNumber ();
					MakeRawDataFileName ();

					output("<COLOR=Blue><<< DEV_START_OF_WAFER received WFR_SLOT_ID = %s >>></COLOR>", WFR_SLOT_ID);

				    //read_die_mask_file(); // enl 111717b not needed
					bFIRST = FALSE;
				}
				////////////  debug  /////////
}			

		if(TT_PROFILE) TB_Timer.StartTimer("Before run_tests 1");
				BASE_X_COORD = DevInfo.iX;
				BASE_Y_COORD = DevInfo.iY;
				update_control(BASE_X_COORD);
				update_control(BASE_Y_COORD);

				remote_send ( BASE_X_COORD,				0, FALSE );
				remote_send ( BASE_Y_COORD,				0, FALSE );
				remote_send ( LOT_NUM,					0, FALSE );
	
				//Check for first X,Y coordinate for data file 
				if ( bFIRST_XY_COORDINATE == FALSE )
				{
					WM_STARTX = BASE_X_COORD;
					WM_STARTY = BASE_Y_COORD;
					if ( VERBOSITY ) output( "WM_STARTX x=%d", WM_STARTX);
					if ( VERBOSITY ) output( "WM_STARTY y=%d", WM_STARTY);
					bFIRST_XY_COORDINATE = TRUE;
				}

				TOUCHDOWNS = vFormat("%d", DevInfo.iTouchdowns);
				update_control( TOUCHDOWNS );
				output("<COLOR=Blue> TOUCHDOWNS = %s x=%d y=%d </COLOR>", TOUCHDOWNS, BASE_X_COORD, BASE_Y_COORD);  //m8p 20171202
	
				//clear_wafermap_field(); // customer have their own wafermap tool

				CalcXYCoordinate ();
	
				// AnyReady returns TRUE if 1 or more duts are ready to test.
				ReadyToStart = AnyReady(DutsToTestArray);
		
		if(TT_PROFILE) TB_Timer.StopTimer("Before run_tests 2");
				if(ReadyToStart)
				{
					// remote_wait() Used to purge any extra start signals that
					// might have come from UI start button
					while(remote_wait("TestDone",1)!= -1){} 
		
		if(TT_PROFILE) TB_Timer.StartTimer("run_tests1");
					TestStartTime ();
		
					remote_wait ( "IwantToBelieve", 100 );

					//update_wafermap_field(); // customer have their own wafermap tool

					bTESTING_ONGOING = TRUE; // enl 110817
					run_tests();
		if(TT_PROFILE) TB_Timer.StopTimer("run_tests2");
		
		if(TT_PROFILE) TB_Timer.StartTimer("CollectDB1");
					CollectDB();
					TestEndTime ();
					SwapData_Bin_PF ();
		if(TT_PROFILE) TB_Timer.StopTimer("CollectDB2");

		if(TT_PROFILE) TB_Timer.StartTimer("Hnd_Bin1");
					TheDevice.Hnd_Bin( intbin_info, pass_fails, MAX_PH_SITES);
		if(TT_PROFILE) TB_Timer.StopTimer("Hnd_Bin2");

					bTESTING_ONGOING = FALSE; // enl 110817 - unload button will only work if all processes above are done
				} 
				else 
				{
					remote_wait ( "IwantToBelieve", 200 );
				}

				if ( VERBOSITY ) output( "Z stage is up" );


if( OFFLINE_DEBUG ) {
				// Simulate WAFER END every 10 touchdowns
				//if(!TT_PROFILE) OfflineDebug_Warning();
				output("<COLOR=Blue><<<<<<<<<< LoopCntr = %d >>>>>>></COLOR>", ++LoopCntr);
				if(LoopCntr % 10 == 0) {
				    output("<COLOR=Blue> <<<<< Simulated WAFER_END received >>>>> </COLOR>");
					WaferEndTime ();
					WriteRawDataFileEnd();
					CopyRawDataFileToServer(); // enl 112717
	
		            if ( VERBOSITY ) output ( "Total Test Time = %s", TOTAL_TEST_TIME_GMT );
					TEST_START_TIME_GMT = "";
	
					//remote_send( END_OF_WAFER_EVENT, 0, TRUE, INFINITE);
		            //if ( VERBOSITY ) output("TSK Tool:Wafer End");
	
					//wafermap_summaries();

					InitDB ();
					bFIRST = TRUE;
				}
}			
		FTimer.StopTimer("DEV_READY End");
			}

	output("%d ***cOIOutput START***",sDutInfoNum); // enl debug
	output("%s",cOIOutput); // enl debug
	output("***cOIOutput END*** %d",sDutInfoNum); // enl debug
	cOIOutput = "";

	ATimer.StopTimer("AutoTesting End");
	}

	bGPIB_MONITOR_PAUSE = FALSE;
	output ( "\n\nGPIB POLLING STOP" );
	output ( "TESTING STOP\n\n" );
}

