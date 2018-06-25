#include "tester.h"
#include "math.h"  //  needed for fabs()	//this is newest datalog	--Laura
CString DatalogFileName;
CString sa_tag;

void CreatDatalogName()
{
	//-----JY debug start------------------------------------------------------------


	CTime ttime = CTime::GetCurrentTime();
	CString DatalogFileDir = "D:\\Datalogs";
	//CString DatalogFileName;
	CString Datalog_DATE;
	CString Datalog_TIME;
	CString cMsg;
	int SANum = 0;
	SANum = site_num();
	//Start Time : 2017 / 09 / 10 18 : 51 : 51
	//	End Time : 2017 / 09 / 10 20 : 10 : 22

	// month:day:year 
	cMsg = vFormat("%04d", ttime.GetYear());
	cMsg += vFormat("%02d", ttime.GetMonth());
	cMsg += vFormat("%02d", ttime.GetDay());

	Datalog_DATE = cMsg;

	//hour:minitus:second
	cMsg = vFormat("%02d", ttime.GetHour());
	cMsg += vFormat("%02d", ttime.GetMinute());
	cMsg += vFormat("%02d", ttime.GetSecond());

	Datalog_TIME = cMsg;

	//------------------------------------------------------------------------------------------------------------------


	DatalogFileName = DatalogFileDir + vFormat("\\%s", "NZ3182"); // enl 112717		
	CreateDirectory(DatalogFileDir, NULL);
	CreateDirectory(DatalogFileName, NULL);


	CString cTimeStamp = vFormat("%s_%s", Datalog_DATE, Datalog_TIME);
	DatalogFileName += vFormat("\\NZ3182_Lot_%s_%s", LOT_NUM, cTimeStamp);
		switch (SANum)
		{
			case 1:DatalogFileName += "_SA01.txt"; break;
			case 2:DatalogFileName += "_SA02.txt"; break;
			case 3:DatalogFileName += "_SA03.txt"; break;
			case 4:DatalogFileName += "_SA04.txt"; break;
			case 5:DatalogFileName += "_SA05.txt"; break;
			default:DatalogFileName += "_error.txt"; break;
		}
	//DatalogFileName += ".txt";
	sa_tag = vFormat("<SAVEAS=%s>", DatalogFileName);
	//output("DatalogFile %s created  Successfully!%s", DatalogFileName, sa_tag);
	


	//--------------------------------------------------------------------------------------------------------------
}

void OutputLogtoFile()
{
	output("%s", sa_tag);
}
	//-----JY debug end--------------------------------------------------------------


void flag(int i)
{
	output("flag%d", i);
}

BOOL_VARIABLE(forced_pass, FALSE, "forced_pass")
{
	if (OnHost())
	{
		for (int isite = 1; isite <= MAX_SITES_NUM; isite += SITE_PER_CONTROLLER_NUM)
		{
			remote_send(forced_pass, isite, TRUE);
		}
	}

	if (forced_pass)
		results_force(1);
	else
		results_force(-1); // return to normal operations

	output("Site%d result_force set based on forced_pass = %d", site_num(), forced_pass);

};


#define HOST	0

//DWORD active_dut_mask;
UINT64 active_dut_mask;

IntArray r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15;	// To store local test results
IntArray r16, r17, r18, r19, r20, r21, r22, r23, r24, r25;	// To store local test results




IntArray FailCnt, FailCntHi;

DutNumArray tp_save_active_duts;

//unsigned long curr_dut_mask;
UINT64	curr_dut_mask;

//LecEntryArray2 lec_ary;

FILE *fp_dut[MAX_DUTS];

bool dlog_func = FALSE;
bool DlogOpen[MAX_DUTS];  // Flag to mark duts with open files



// Datalog Verbosity Control
// 0: off			
// 1: header only
// 2: Datalog fail pins			
// 3: Datalog pass pins			
// 4: Datalog pass & fail pins 
INT_VARIABLE(dlog, 1, "Datalog_switch")
{
	if (OnHost())
	{
		for (int isite = 1; isite <= MAX_SITES_NUM; isite += SITE_PER_CONTROLLER_NUM)
		{
			remote_send(dlog, isite, TRUE);
		}
	}

	if (dlog == 0)
	{
		remote_set("dlog_verbosity", "Off", site_num(), TRUE);
	}
	if (dlog == 1)
	{
		remote_set("dlog_verbosity", "Header Only", site_num(), TRUE);
	}
	if (dlog == 2)
	{
		remote_set("dlog_verbosity", "Failing Pins", site_num(), TRUE);
	}
	if (dlog == 3)
	{
		remote_set("dlog_verbosity", "Passing Pins", site_num(), TRUE);
	}
	if (dlog == 4)
	{
		remote_set("dlog_verbosity", "Passing & Failing Pins", site_num(), TRUE);
	}
};
INT_VARIABLE(DLog_vector_count, 10, "DLog_vector_count") { };

//NOTE: Debug by Colin here: form FALSE -> TRUE
BOOL_VARIABLE(para, TRUE, "para")
{
	if (OnHost())
	{
		for (int isite = 1; isite <= MAX_SITES_NUM; isite += SITE_PER_CONTROLLER_NUM)
		{
			remote_send(para, isite, TRUE);
		}
	}
};
//NOTE: Debug by Colin here: form FALSE -> TRUE
BOOL_VARIABLE(func, TRUE, "func")
{
	if (OnHost())
	{
		for (int isite = 1; isite <= MAX_SITES_NUM; isite += SITE_PER_CONTROLLER_NUM)
		{
			remote_send(func, isite, TRUE);
		}
	}
};
BOOL_VARIABLE(lvm, FALSE, "lvm")
{
	if (OnHost())
	{
		for (int isite = 1; isite <= MAX_SITES_NUM; isite += SITE_PER_CONTROLLER_NUM)
		{
			remote_send(lvm, isite, FALSE);
		}
	}
};
BOOL_VARIABLE(user, FALSE, "user")
{
	if (OnHost())
	{
		for (int isite = 1; isite <= MAX_SITES_NUM; isite += SITE_PER_CONTROLLER_NUM)
		{
			remote_send(user, isite, FALSE);
		}
	}
};
BOOL_VARIABLE(shmoo, FALSE, "shmoo")
{
	if (OnHost())
	{
		for (int isite = 1; isite <= MAX_SITES_NUM; isite += SITE_PER_CONTROLLER_NUM)
		{
			remote_send(shmoo, isite, FALSE);
		}
	}
};
BOOL_VARIABLE(search, FALSE, "search")
{
	if (OnHost())
	{
		for (int isite = 1; isite <= MAX_SITES_NUM; isite += SITE_PER_CONTROLLER_NUM)
		{
			remote_send(search, isite, FALSE);
		}
	}
};
BOOL_VARIABLE(tp_fdlog, FALSE, "tp_fdlog")
{
	if (OnHost())
	{
		if (tp_fdlog)
		{
			create_datalog_folder();
		}
	}
};
BOOL_VARIABLE(fdlog, FALSE, "fdlog")
{
	remote_set(tp_fdlog, fdlog, site_num(), TRUE);
};

ONEOF_VARIABLE(dlog_verbosity, "Off, Header Only, Failing Pins, Passing Pins, Passing & Failing Pins", ""){};

/***********************************************************************/
// Converts the measured results into a string with units and multiplier
/***********************************************************************/

CString tp_cnvt_result(double value, e_log_type log_type){
	CString cstr;

	switch (log_type) {
	case LOG_V:	 // convert to voltage
		if (fabs(value) >= (1 V)) {
			cstr.Format("%8.3f v", value / (1 V));
		}
		else {
			cstr.Format("%8.3f mv", value / (1 MV));
		}
		break;
	case LOG_I:  // convert to current
		if (fabs(value) >= (1 MA)) {
			cstr.Format("%8.3f ma", value / (1 MA));
		}
		else if (fabs(value) >= (1 UA)) {
			cstr.Format("%8.3f ua", value / (1 UA));
		}
		else {
			cstr.Format("%8.0f na", value / (1 NA));
		}
		break;
	case LOG_T: break;
	default:	cstr.Format("#############");
	}

	return (cstr);
}  // end of tp_cnvt_result

void tp_pdatalog(PinList *pPinList, IVMeasType meas_type) //call after a parametric test
{
	dlog_func = true;


	remote_fetch(dlog, HOST, FALSE, INFINITE);
	remote_fetch(para, HOST, FALSE, INFINITE);

	if (dlog < 1)	return;

	if (para == FALSE)
	{
		dlog_func = false;
		return;
	}

	// determine the what type of test was just run
	e_log_type log_type, frc_type;
	switch (parametric_mode()) {
	case 0:	log_type = LOG_I; frc_type = LOG_V; break;
	case 2:	log_type = LOG_I; frc_type = LOG_V; break;
	case 1:	log_type = LOG_V; frc_type = LOG_I; break;
	default: output("Invalid parametric mode : %d", parametric_mode());
	}

	// Print header info
	if (dlog > 1) output("TestBlock = %-15s   TestNumber = %d", current_test_block(), test_number());

	if (dlog > 1) {
		if (measure() == TRUE) {
			output("----------------------------------------------------------------------------------");
			output("Tester  Pin                      Pin         Force            Low         High            Measured");
			output("Pin    Name                    Result       Value            Limit       Limit            Value   ");
			output("----------------------------------------------------------------------------------");
		}
		else {
			output("---------------------------------");
			output("Tester      Pin          Pin     ");
			output(" Pin        Name         Result  ");
			output("---------------------------------");
		}
	}  // end of if(dlog>1)
	// Loop over each active dut in turn
	int count = active_duts_get(&tp_save_active_duts);
	for (int ix = 0; ix<count; ix++) {
		DutNum dut_num = tp_save_active_duts[ix];
		active_duts_enable(dut_num);		// enable only one dut

		// Print header info

		CArray<double, double> meas_results;
		CArray<PFState, PFState> pf_results;

		// check the pinlist for either dps pins or signal pins
		if (all_dps(pPinList)){
			Dps_meas(meas_results);	// get the measured results for this dut
			Dps_pf(pf_results);
		}
		else if (all_hv(pPinList)) {
			Hv_pf(pf_results);
			if (measure()) Hv_meas(meas_results);
		}
		else if (all_dpo(pPinList))
		{
			Dpo_meas(meas_results);
			Dpo_pf(pf_results);
		}
		else if (all_dpohv(pPinList))
		{
			DpoHv_meas(meas_results);
			DpoHv_pf(pf_results);
			//flag(3);
		}
		else {
			Pin_meas(meas_results);	// get the measured results for this dut
			Pin_pf(pf_results);
		}
		if (dlog > 1) output("Dut %d : %s", dut_num + 1, result_get(dut_num) ? "<COLOR=Green>PASS</COLOR>" : "<COLOR=Red>FAIL</COLOR>");

		int meas_index = 0;

		// Loop through all dut pins
		DutPin * dpin;
		for (int dpi = 0; pin_info(pPinList, dpi, &dpin); ++dpi) {

			// Get the HDTesterPin for this dut
			HDTesterPin tpin;
			pin_info(dpin, dut_num, &tpin);
			if (tpin == t_na)
				continue;

			CString pin_name = resource_name(dpin);
			CString tpin_name = testerpin_name(tpin);

			if (measure())
			{
				if (no_dps(pPinList) && no_dpo(pPinList) && no_dpohv(pPinList))
				{
					switch (dlog)
					{
					case 0:
					case 1:
						break;
					case 2: //FAIL Only
						if (!pf_results[meas_index])
							output("%-10s\t%-10s\t\t%4s\t\t%s\t%s\t%s\t%s", tpin_name, pin_name,
							"<COLOR=Red>FAIL</COLOR>",
							frc_type == LOG_I ? tp_cnvt_result(ipar_force(dpin), frc_type) : tp_cnvt_result(vpar_force(dpin), frc_type),
							frc_type == LOG_I ? tp_cnvt_result(vpar_low(dpin), log_type) : tp_cnvt_result(ipar_low(dpin), log_type),
							frc_type == LOG_I ? tp_cnvt_result(vpar_high(dpin), log_type) : tp_cnvt_result(ipar_high(dpin), log_type),
							tp_cnvt_result(meas_results[meas_index], log_type));
						break;
					case 3: //PASS only
						if (pf_results[meas_index])
							output("%-10s\t%-10s\t\t%4s\t\t%s\t%s\t%s\t%s", tpin_name, pin_name,
							"<COLOR=Green>PASS</COLOR>",
							frc_type == LOG_I ? tp_cnvt_result(ipar_force(dpin), frc_type) : tp_cnvt_result(vpar_force(dpin), frc_type),
							frc_type == LOG_I ? tp_cnvt_result(vpar_low(dpin), log_type) : tp_cnvt_result(ipar_low(dpin), log_type),
							frc_type == LOG_I ? tp_cnvt_result(vpar_high(dpin), log_type) : tp_cnvt_result(ipar_high(dpin), log_type),
							tp_cnvt_result(meas_results[meas_index], log_type));
						break;
					case 4: //All
						output("%-10s\t%-10s\t\t%4s\t\t%s\t%s\t%s\t%s", tpin_name, pin_name,
							pf_results[meas_index] ? "<COLOR=Green>PASS</COLOR>" : "<COLOR=Red>FAIL</COLOR>",
							frc_type == LOG_I ? tp_cnvt_result(ipar_force(dpin), frc_type) : tp_cnvt_result(vpar_force(dpin), frc_type),
							frc_type == LOG_I ? tp_cnvt_result(vpar_low(dpin), log_type) : tp_cnvt_result(ipar_low(dpin), log_type),
							frc_type == LOG_I ? tp_cnvt_result(vpar_high(dpin), log_type) : tp_cnvt_result(ipar_high(dpin), log_type),
							tp_cnvt_result(meas_results[meas_index], log_type));
						break;
					}
				}
				else if (all_dpohv(pPinList))
				{
					//flag(4);
					switch (dlog)
					{
					case 0:
					case 1:
						break;
					case 2: //FAIL Only
						if (!pf_results[meas_index])
							output("%-10s\t%-10s\t\t%4s\t\t%s\t%s\t%s\t%s", tpin_name, pin_name,
							"<COLOR=Red>FAIL</COLOR>",
							frc_type == LOG_I ? tp_cnvt_result(dpo_hv_ipar_force_get(dpin), frc_type) : tp_cnvt_result(dpo_hv_voltage_get(dpin), frc_type),
							frc_type == LOG_I ? tp_cnvt_result(dpo_hv_vpar_low_get(dpin), log_type) : tp_cnvt_result(dpo_hv_ipar_low_get(dpin), log_type),
							frc_type == LOG_I ? tp_cnvt_result(dpo_hv_vpar_high_get(dpin), log_type) : tp_cnvt_result(dpo_hv_ipar_high_get(dpin), log_type),
							tp_cnvt_result(meas_results[meas_index], log_type));
						break;
					case 3: //PASS only
						if (pf_results[meas_index])
							output("%-10s\t%-10s\t\t%4s\t\t%s\t%s\t%s\t%s", tpin_name, pin_name,
							"<COLOR=Green>PASS</COLOR>",
							frc_type == LOG_I ? tp_cnvt_result(dpo_hv_ipar_force_get(dpin), frc_type) : tp_cnvt_result(dpo_hv_voltage_get(dpin), frc_type),
							frc_type == LOG_I ? tp_cnvt_result(dpo_hv_vpar_low_get(dpin), log_type) : tp_cnvt_result(dpo_hv_ipar_low_get(dpin), log_type),
							frc_type == LOG_I ? tp_cnvt_result(dpo_hv_vpar_high_get(dpin), log_type) : tp_cnvt_result(dpo_hv_ipar_high_get(dpin), log_type),
							tp_cnvt_result(meas_results[meas_index], log_type));
						break;
					case 4: //All
						output("%-10s\t%-10s\t\t%4s\t\t%s\t%s\t%s\t%s", tpin_name, pin_name,
							pf_results[meas_index] ? "<COLOR=Green>PASS</COLOR>" : "<COLOR=Red>FAIL</COLOR>",
							frc_type == LOG_I ? tp_cnvt_result(dpo_hv_ipar_force_get(dpin), frc_type) : tp_cnvt_result(dpo_hv_voltage_get(dpin), frc_type),
							frc_type == LOG_I ? tp_cnvt_result(dpo_hv_vpar_low_get(dpin), log_type) : tp_cnvt_result(dpo_hv_ipar_low_get(dpin), log_type),
							frc_type == LOG_I ? tp_cnvt_result(dpo_hv_vpar_high_get(dpin), log_type) : tp_cnvt_result(dpo_hv_ipar_high_get(dpin), log_type),
							tp_cnvt_result(meas_results[meas_index], log_type));
						break;
					}
				}

				else if (all_dpo(pPinList))
				{
					switch (dlog)
					{
					case 0:
					case 1:
						break;
					case 2: //FAIL Only
						if (!pf_results[meas_index])
							output("%-10s\t%-10s\t\t%4s\t\t%s\t%s\t%s\t%s", tpin_name, pin_name,
							"<COLOR=Red>FAIL</COLOR>",
							frc_type == LOG_I ? tp_cnvt_result(dpo_ipar_force_get(dpin), frc_type) : tp_cnvt_result(dpo_voltage_get(dpin), frc_type),
							frc_type == LOG_I ? tp_cnvt_result(dpo_voltage_low_get(dpin), log_type) : tp_cnvt_result(dpo_current_low_get(dpin), log_type),
							frc_type == LOG_I ? tp_cnvt_result(dpo_voltage_high_get(dpin), log_type) : tp_cnvt_result(dpo_current_high_get(dpin), log_type),
							tp_cnvt_result(meas_results[meas_index], log_type));
						break;
					case 3: //PASS only
						if (pf_results[meas_index])
							output("%-10s\t%-10s\t\t%4s\t\t%s\t%s\t%s\t%s", tpin_name, pin_name,
							"<COLOR=Green>PASS</COLOR>",
							frc_type == LOG_I ? tp_cnvt_result(dpo_ipar_force_get(dpin), frc_type) : tp_cnvt_result(dpo_voltage_get(dpin), frc_type),
							frc_type == LOG_I ? tp_cnvt_result(dpo_voltage_low_get(dpin), log_type) : tp_cnvt_result(dpo_current_low_get(dpin), log_type),
							frc_type == LOG_I ? tp_cnvt_result(dpo_voltage_high_get(dpin), log_type) : tp_cnvt_result(dpo_current_high_get(dpin), log_type),
							tp_cnvt_result(meas_results[meas_index], log_type));
						break;
					case 4: //All
						output("%-10s\t%-10s\t\t%4s\t\t%s\t%s\t%s\t%s", tpin_name, pin_name,
							pf_results[meas_index] ? "<COLOR=Green>PASS</COLOR>" : "<COLOR=Red>FAIL</COLOR>",
							frc_type == LOG_I ? tp_cnvt_result(dpo_ipar_force_get(dpin), frc_type) : tp_cnvt_result(dpo_voltage_get(dpin), frc_type),
							frc_type == LOG_I ? tp_cnvt_result(dpo_voltage_low_get(dpin), log_type) : tp_cnvt_result(dpo_current_low_get(dpin), log_type),
							frc_type == LOG_I ? tp_cnvt_result(dpo_voltage_high_get(dpin), log_type) : tp_cnvt_result(dpo_current_high_get(dpin), log_type),
							tp_cnvt_result(meas_results[meas_index], log_type));
						break;
					}
				}
				else
				{
					if (dlog > 1)
						output("%-10s\t%-10s\t\t%4s\t\t%s\t%s\t%s\t%s", tpin_name, pin_name,
						pf_results[meas_index] ? "<COLOR=Green>PASS</COLOR>" : "<COLOR=Red>FAIL</COLOR>",
						//bugs here  add judgement
						tp_cnvt_result(meas_type == 0 ? dps(dpin) : ipar_force(dpin), frc_type),
						//bugs here(change dps_current_low( dpin ) to vpar_low(dpin))  ----colin
						tp_cnvt_result(meas_type == 0 ? ipar_low(dpin) : vpar_low(dpin), log_type),
						tp_cnvt_result(meas_type == 0 ? ipar_high(dpin) : vpar_high(dpin), log_type),
						tp_cnvt_result(meas_results[meas_index], log_type));
				}
			}
			else{
				if (dlog > 1)
					output("%-10s   %-10s   %4s", tpin_name, pin_name,
					pf_results[meas_index] ? "<COLOR=Green>PASS</COLOR>" : "<COLOR=Red>FAIL</COLOR>");
			}

			++meas_index;
		}

		ASSERT(meas_index == meas_results.GetSize());
	}

	// restore original duts
	active_duts_enable(tp_save_active_duts);

	dlog_func = false;
}

/***********************************************************************/
// Functional Datalog
// This function returns the failing pins for a functional memory
// or logic test pattern.  The error status is acquired from the
// PE rather than from the ECR.
/***********************************************************************/
void tp_fdatalog(PinList* pPinList)
{
	TesterPin tpin;
	HDTesterPin hd_tpin;
	DutPin * dpin;
	DutNum	dut_num;
	CString pin_name;
	PFState pass_fail;

	dlog_func = true;

	remote_fetch(dlog, HOST, FALSE, INFINITE);
	remote_fetch(func, HOST, FALSE, INFINITE);

	if (func == FALSE)
	{
		dlog_func = false;
		return;
	}

	int count = active_duts_get(&tp_save_active_duts);  // get a list of active devices

	if (test_pin(pPinList))
	{
		if (dlog > 1) output("TestBlock:%-15s TestNumber:%-3d <COLOR=Green>PASSed</COLOR>", current_test_block(), test_number());
	}
	else
	{
		for (int ix = 0; ix<count; ix++) {
			dut_num = tp_save_active_duts[ix];

			if (dlog > 1) output("Dut %d : %s\n", tp_save_active_duts[ix] + 1, result_get(tp_save_active_duts[ix]) ? "<COLOR=Green>PASS</COLOR>" : "<COLOR=Red>FAIL</COLOR>");

			// Loop through all pins and look for pass/fail
			for (int pin_index = 0; pin_info(pPinList, pin_index, &dpin); pin_index++) {

				pin_info(dpin, dut_num, &tpin);			// get the tester channel based on DutPin

				if (tpin == t_na)
					continue;

				CString pin_name = resource_name(dpin);
				CString tpin_name = testerpin_name(tpin);

				// create a temporary pinlist with only one pin
				PinList *pPin = pinlist_create(&tpin, 1);
				pass_fail = test_pin(pPin);
				pinlist_destroy(pPin);

				pin_info(dpin, dut_num, &hd_tpin);			// get the tester channel based on DutPin
				CString hd_tpin_name = testerpin_name(hd_tpin);

				pin_name = resource_name(dpin);

				switch (dlog)
				{
				case 0:
				case 1:
					break;
				case 2:	//Fail Only
					if (pass_fail == FAIL)
					{
						output("Pin = %6s, tester channel = %s  %s", pin_name,
							hd_tpin_name,
							"<COLOR=Red>FAIL</COLOR>");
					}
					break;
				case 3:	//Pass Only
					if (pass_fail == PASS)
					{
						output("Pin = %6s, tester channel = %s  %s", pin_name,
							hd_tpin_name,
							"<COLOR=Green>PASS</COLOR>");
					}
					break;
				case 4:	//All
					output("Pin = %6s, tester channel = %s  %s", pin_name,
						hd_tpin_name,
						pass_fail ? "<COLOR=Green>PASS</COLOR>" : "<COLOR=Red>FAIL</COLOR>");
					break;
				}
			}
		}
	}

	dlog_func = false;
}

/***********************************************************************/
// Print a datalog header containing vertical PinList names.
// Number of lines used to print names is set here via MAX_HEADER
// Each line is indented the same amount, based on arg2.
/***********************************************************************/

void print_pin_banner(int dut, PinList* pins, int indent)
{
	const int MAX_HEADER = 12;
	TesterPin tpin;
	PEBoard board;
	int channel;
	int dpinNum;
	LPCTSTR dpinName;

	for (int header_line = MAX_HEADER - 1; header_line > 0; header_line--)
	{
		CString header = "";
		BOOL print_header = FALSE;
		for (int i = 0; i < indent; i++)
			header = vFormat("%s%c", header, ' ');
		for (int pin_index = dut; pin_info(pins, pin_index, &tpin, &board, &channel);
			pin_index += max_dut() + 1)
		{
			pin_info(pins, pin_index, 0, &dpinNum, &dpinName); // get pin name
			int pin_name_length = (int)strlen(dpinName);
			if (pin_name_length - header_line < 0) {
				header = vFormat("%s%c", header, ' ');
			}
			else {
				header = vFormat("%s%c", header, dpinName[pin_name_length - header_line]);
				print_header = TRUE;
			}  // end of if
		}  // end of for

		if (print_header)
		{
			output("%s", header);
		}
	}  // end of for
}  // END OF FUNCTION PRINT_PIN_BANNER

void tp_vdatalog(Pattern* funtest_pattern, PinList* pPinList)
{
	CString msg;
	ActiveDutIterator ActiveDutLoop;

	dlog_func = true;

	remote_fetch(dlog, HOST, FALSE, INFINITE);
	remote_fetch(func, HOST, FALSE, INFINITE);

	if (func == FALSE)
	{
		dlog_func = false;
		return;
	}

	// If pinlist not pure signal pins abort /w error
	if (!no_dps(pPinList)) {
		msg = "ERROR: pin list passed to fdatalog() contains\n";
		msg += "       one or more DPS pins.\n";
		msg += "       Output from vdatalog() isn't valid.";
		output("%s", msg);
		dlog_func = false;
		return;
	}

	const int VINDENT = 29;

	output("TestBlock:%-15s TestNumber:%-3d     funtest( %-15s )    %s",
		current_test_block(), test_number(), resource_name(funtest_pattern),
		test_pin(pPinList) ? "<COLOR=Green>PASSed</COLOR>" : "<COLOR=Red>FAILed</COLOR>");

	if (!test_pin(pPinList)) {

		while (ActiveDutLoop.More())
		{
			DutNum CurrentDut = active_dut_get();
			int dut = CurrentDut - t_dut1;

			// Output banner with pin names written vertically
			print_pin_banner(dut, pPinList, VINDENT);
			output("DUT FAIL PATTERN    OFFSET");

			// Get failing VAR
			int failing_var = errvar();

			// Get name of failing pattern and offset
			DWORD var_offset = -1;
			Pattern* pattern_name;
			CString pattern_string = "";
			if (!find_var(failing_var, &pattern_name, &var_offset)) {
				output("ERROR: Invalid vector address");
				dlog_func = false;
				return;
			}
			else {
				pattern_string = resource_name(pattern_name);
			}

			CString fail_line = vFormat("%-4d %-15.15s %-7d ", dut + 1, pattern_string, var_offset);

			TesterPin tpin;
			for (int pin_index = dut; pin_info(pPinList, pin_index, &tpin, 0, 0);
				pin_index += max_dut() + 1)

				switch (vecdata(failing_var, tpin))
			{
				case drive_lo:	fail_line += '0';
					break;
				case drive_hi:	fail_line += '1';
					break;
				case tristate:	fail_line += 'X';
					break;
				case strobe_lo:	fail_line += 'L';
					break;
				case strobe_hi:	fail_line += 'H';
					break;
				default:		fail_line += '?';
					break;
			}  //  end of switch/for

			output("%s", fail_line);

			// Output a "^" under each failing pin
			fail_line = "";
			BOOL pass_fail;
			//		int dpinNum;
			//		LPCTSTR dpinName;
			for (int i = 0; i < VINDENT; i++) {
				fail_line = vFormat("%s%c", fail_line, ' ');
			}
			for (int pin_index = dut; pin_info(pPinList, pin_index, &tpin, 0, 0);
				pin_index += max_dut() + 1)
			{
				//			pin_info( pPinList, pin_index, 0, &dpinNum, &dpinName );

				PinList *pPin = pinlist_create(&tpin, 1);
				pass_fail = test_pin_first_error(pPin);
				pinlist_destroy(pPin);

				if (pass_fail == PASS) {
					fail_line = vFormat("%s%c", fail_line, ' ');
				}
				else {
					fail_line = vFormat("%s%c", fail_line, '^');
				}
			} //  end of for

			output("%s", fail_line);
		} //while

	}  // end of if

	dlog_func = false;

}  // END OF FUNCTION VDATALOG


void display_test_results(bool flag)
{
	DutNumArray active_duts;
	CString sTb = "";
	CString sTt = "";
	CString str_results = "";

	int count = active_duts_get(&curr_dut_mask);

	if (count != 0)
	{
		if ((r1[0] != -1) || (r2[0] != -1) || (r3[0] != -1) || (r4[0] != -1) || (r5[0] != -1) ||
			(r6[0] != -1) || (r7[0] != -1) || (r8[0] != -1) || (r9[0] != -1) || (r10[0] != -1) ||
			(r11[0] != -1) || (r12[0] != -1) || (r13[0] != -1) || (r14[0] != -1) || (r15[0] != -1) ||
			(r16[0] != -1) || (r17[0] != -1) || (r18[0] != -1) || (r19[0] != -1) || (r20[0] != -1) ||
			(r21[0] != -1) || (r22[0] != -1) || (r23[0] != -1) || (r24[0] != -1) || (r25[0] != -1))
		{
			for (int dut = 0; dut < count; ++dut)
			{
				//	output("combining results %d", dut);
				r1[dut] = r1[dut] && r2[dut] && r3[dut] && r4[dut] && r5[dut]
					&& r6[dut] && r7[dut] && r8[dut] && r9[dut] && r10[dut]
					&& r11[dut] && r12[dut] && r13[dut] && r14[dut] && r15[dut]
					&& r16[dut] && r17[dut] && r18[dut] && r19[dut] && r20[dut]
					&& r21[dut] && r22[dut] && r23[dut] && r24[dut] && r25[dut];
			}
			//for (int dut = 0; dut < count; ++dut)
			///{
			//	output("Combined Test Result dut %d = %d",  (active_duts[dut] + 1), r1[dut]);
			//}
			results_set(r1);

		}

		int count = active_duts_get(&curr_dut_mask);
		// loop through all the active duts
		count = active_duts_get(&active_duts);
		UINT64 curr_dut_fail_mask = 0;
		for (int ix = 0; ix<count; ix++) {
			if (result_get(active_duts[ix]) == FAIL) {
				curr_dut_fail_mask |= (UINT64)0x01 << (int)active_duts[ix];
			}
		}

		//output("curr_dut_fail_mask =0x%I64x", curr_dut_fail_mask);
		//output("curr_dut_mask =0x%I64x", curr_dut_mask);
		//output("max_dut() =%d", max_dut());
		sTb.Format("%-25s  ", current_test_block());
		for (int dut = 0; dut <= max_dut(); dut++) {
			if (curr_dut_fail_mask & ((UINT64)0x1 << dut)) str_results += "<COLOR=Red>F </COLOR>";
			else (curr_dut_mask &((UINT64)0x1 << dut)) ? str_results += "<COLOR=Green>P </COLOR>" : str_results += "- ";
		}
		sTt.Format("%-10f  ", TB_Timer.StopTimer(""));

		str_results = sTb + sTt + str_results;

		if (dlog>0 ) output(str_results);
	}//end of count check
}

/***********************************************************************/
// Return a string, containing vector source tokens for the pinlist arg,
// from the specified vector.
/***********************************************************************/

CString get_vector_tokens(PinList* plist, int vect, __int64 lecdata_lo, __int64 lecdata_hi)
{
	DutPin *tpin; // for processing individual DUT pins of pinlist
	HDTesterPin tpin1;
	__int64 fbit, fbit_hi;
	CString output_line = "";
	BOOL fpin_search;

	fbit = fbit_hi = 0x1;  //  Initialize Dut Pin Index Mask

	for (int pin_index = 0; pin_info(plist, pin_index, &tpin); ++pin_index)
	{
		//is it a failing pin ?
		pin_info(plist, pin_index, &tpin1);

		if (pin_index < 64)
		{
			// Check Fail Status
			fpin_search = TRUE;
			if (fbit & lecdata_lo)
			{
				fpin_search = FALSE;  //  Failure detected
			}
			fbit <<= 1;  //  Advance Dut Pin Index Mask		
		}
		else
		{
			// Check Fail Status
			fpin_search = TRUE;
			if (fbit_hi & lecdata_hi)
			{
				fpin_search = FALSE;  //  Failure detected
			}
			fbit_hi <<= 1;  //  Advance Dut Pin Index Mask				
		}

		switch (vecdata(vect, tpin))	// ID vector token type for this pin
		{								// and add to string
		case drive_lo:		if (fpin_search)
		{
			output_line += '0';
		}
							else
							{
								output_line += "<COLOR=Red>0</COLOR>";
							}
							break;
		case drive_hi:		if (fpin_search)
		{
			output_line += '1';
		}
							else
							{
								output_line += "<COLOR=Red>1</COLOR>";
							}
							break;
		case tristate:		if (fpin_search)
		{
			output_line += 'X';
		}
							else
							{
								output_line += "<COLOR=Red>X</COLOR>";
							}
							break;
		case strobe_lo:		if (fpin_search)
		{
			output_line += 'L';
		}
							else
							{
								output_line += "<COLOR=Red>L</COLOR>";
							}
							break;
		case strobe_hi:		if (fpin_search)
		{
			output_line += 'H';
		}
							else
							{
								output_line += "<COLOR=Red>H</COLOR>";
							}
							break;
		case strobe_valid:	if (fpin_search)
		{
			output_line += 'V';
		}
							else
							{
								output_line += "<COLOR=Red>V</COLOR>";
							}
							break;
		case strobe_mid:	if (fpin_search)
		{
			output_line += 'Z';
		}
							else
							{
								output_line += "<COLOR=Red>Z</COLOR>";
							}
							break;
		default:			if (fpin_search)
		{
			output_line += '?';
		}
							else
							{
								output_line += "<COLOR=Red>?</COLOR>";
							}
		}  //  end of switch
	}  //  END OF FOR

	return (output_line);
}  // END OF FUNCTION GET_VECTOR_TOKENS

/***********************************************************************/
// Create a string with a '^' positioned under each failing pin
// Fail token generator based on datalog ( arg1 ) and 
// fail ( arg 2 ) pinlist.
/***********************************************************************/

CString get_failing_tokens(PinList* pdtlg, __int64 lecdata_lo, __int64 lecdata_hi, int line_indent)
{
	CString output_line = "";
	HDTesterPin tpin1;
	__int64 fbit, fbit_hi;
	BOOL fpin_search;

	// Pad line with spaces to align with pin headers
	for (int i = 0; i < line_indent; i++) {
		output_line += ' ';
	}

	// Loop: for each pin in datalog pinlist...
	fbit = fbit_hi = 0x1;  //  Initialize Dut Pin Index Mask
	for (int pin_idx1 = 0; pin_info(pdtlg, pin_idx1, &tpin1); pin_idx1++)
	{
		if (testerpin_name(tpin1) < "b_1")
		{
			// Check Fail Status
			fpin_search = TRUE;
			if (fbit & lecdata_lo)
			{
				fpin_search = FALSE;  //  Failure detected
			}
			fbit <<= 1;  //  Advance Dut Pin Index Mask

			if (fpin_search)
			{
				// PASS = 0 : ECR data = 1 for fail
				output_line += ' ';
			}
			else
			{
				// FAIL
				output_line += "<COLOR=Red><B>^</COLOR></B>";
			}  //  END OF IF
		}
		else
		{
			// Check Fail Status
			fpin_search = TRUE;
			if (fbit_hi & lecdata_hi)
			{
				fpin_search = FALSE;  //  Failure detected
			}
			fbit_hi <<= 1;  //  Advance Dut Pin Index Mask

			if (fpin_search)
			{
				// PASS = 0 : ECR data = 1 for fail
				output_line += ' ';
			}
			else
			{
				// FAIL
				output_line += "<COLOR=Red><B>^</COLOR></B>";
			}  //  END OF IF
		}
	}  //  END OF FOR

	return (output_line);
}  //  END OF FUNCTION GET_FAILING_TOKENS

#if 0
void LEC_FailCnts(PinList* pPinList, int fcount)
{
	DutPin * dpin;
	HDTesterPin tpin;
	int p_idx, p_idx_hi, bit;
	__int64 bitmask;

	FailCnt.SetSize(64);
	FailCntHi.SetSize(64);

	for (int idx = 0; idx<64; idx++)
	{
		FailCnt[idx] = 0;
		FailCntHi[idx] = 0;
	}

	for (int i = 0; i<fcount; i++)
	{
		if (lec_ary[i].data_lo)
		{
			for (bit = 0; bit<64; bit++)
			{
				bitmask = (__int64)0x1 << bit;

				if (lec_ary[i].data_lo & bitmask)
				{
					FailCnt[bit]++;
				}
			}
		}
		if (lec_ary[i].data_hi)
		{
			for (bit = 0; bit<64; bit++)
			{
				bitmask = (__int64)0x1 << bit;

				if (lec_ary[i].data_hi & bitmask)
				{
					FailCntHi[bit]++;
				}
			}
		}
	}

	output("<U>%-4s</U>%6s<U>%-5s</U>%5s<U>%-7s</U>", "DPin", " ", "TChan", " ", "FailCnt");

	for (p_idx = 0, p_idx_hi = 0; pin_info(pPinList, p_idx, &dpin); p_idx++)
	{
		pin_info(pPinList, p_idx, &tpin);

		if (testerpin_name(tpin) < "b_1")
		{
			if (FailCnt[p_idx])
			{
				output("%-10s%-10s%-10d", resource_name(dpin), testerpin_name(tpin), FailCnt[p_idx]);
			}
		}
		else
		{
			if (FailCntHi[p_idx_hi])
			{
				output("%-10s%-10s%-10d", resource_name(dpin), testerpin_name(tpin), FailCntHi[p_idx_hi]);
			}
			p_idx_hi++;
		}
	}
}

/***********************************************************************/
// LEC Datalog Report function
// Local structure used to access first fail vector status, datalog
// pinlist, and maximum fail count for LEC_report function
/***********************************************************************/

void LEC_datalog(Pattern* funtest_pattern, PinList* pPinList)
{
	// Number of spaces consumed by VAR value at start of each vector line
	const int VAR_FIELD_WIDTH = 9;

	// Setup pointer back to lec_dtlg structure
	Pattern* pattern_name;
	CString msg;
	CString patname_str = "";
	DWORD pat_rel_var;
	__int64 fp_mask, fp_mask_hi;
	HDTesterPin tdp;
	int lrpt_idx, soad_idx, fcount;

	dlog_func = true;

	remote_fetch(dlog, HOST, FALSE, INFINITE);
	remote_fetch(lvm, HOST, FALSE, INFINITE);
	remote_fetch(DLog_vector_count, HOST, FALSE, INFINITE);

	if (lvm == FALSE)
	{
		dlog_func = false;
		return;
	}

	// If pinlist not pure signal pins abort /w error
	if (!no_dps(pPinList)) {
		msg = "ERROR: pin list passed to LEC_datalog() contains\n";
		msg += "       one or more DPS pins.\n";
		msg += "       Output from LEC_datalog() isn't valid.";
		output("%s", msg);
		dlog_func = false;
		return;
	}

	output("TestBlock:%-15s TestNumber:%-3d     funtest( %-15s )    %s\n",
		current_test_block(), test_number(), resource_name(funtest_pattern),
		test_pin(pPinList) ? "<COLOR=Green>PASSed</COLOR>" : "<COLOR=Red>FAILed</COLOR>");


	if (!test_pin(pPinList))
	{
		//  Generate Mask and execute Scan
		fp_mask = fp_mask_hi = 0x0;
		for (lrpt_idx = 0; pin_info(pPinList, lrpt_idx, &tdp); lrpt_idx++)
		{
			if (testerpin_name(tdp) < "b_1")
			{
				if (fp_mask == 0x0)
				{
					fp_mask = 0x1;  //  Initialize Mask
				}
				else
				{
					fp_mask = (fp_mask << 1) + 0x1;  //  Shift Left
				}
			}
			else
			{
				if (fp_mask_hi == 0x0)
				{
					fp_mask_hi = 0x1;  //  Initialize Mask
				}
				else
				{
					fp_mask_hi = (fp_mask_hi << 1) + 0x1;  //  Shift Left
				}
			}
		}
		if (fp_mask == 0x0) {
			output("ERROR: pin list fail mask is zero!");
			dlog_func = false;
			return;
		}

		ActiveDutIterator lec_adi;
		while (lec_adi.More()) {
			soad_idx = active_dut_get() + 1;

			fcount = lec_scan(t_hsb1, 0, 0x3ffff8, fp_mask, fp_mask_hi, 0x3ffff9, lec_ary);  //  Scan

			if (fcount != 0)
			{

				output("<B><H5>DUT %d</B></H5>\n", soad_idx);

				LEC_FailCnts(pPinList, fcount);

				// Output banner with pin names written vertically, and properly indented
				print_pin_banner(soad_idx - 1, pPinList, 2 * VAR_FIELD_WIDTH);

				output("%-*s\\", VAR_FIELD_WIDTH, "VAR");
				output("%-*s", VAR_FIELD_WIDTH, "OFFSET");

				if (fcount < DLog_vector_count)
				{
					DLog_vector_count = fcount;
				}

				for (lrpt_idx = 0; lrpt_idx < DLog_vector_count; lrpt_idx++) {

					// Validate abs_var
					// which is loaded into tester memory and 
					// a valid offset into the pattern_name, if not then
					// return false and we're done
					if (!find_var(lec_ary[lrpt_idx].var, &pattern_name, &pat_rel_var)) {
						output("ERROR: Invalid vector address");
						break;  //  FOR loop break
					}

					// Based on VAR, get name of failing pattern to print in header
					patname_str = resource_name(pattern_name);

					// Print Fail Vector Information
					// For each value read from ECR, print 2 lines:
					// 1st = vector info, 2nd = ^ fail tokens

					// Begin constructing 1st line of output. First element is
					// absolute vector address. Second element is
					// vector number relative to this pattern
					CString output_line = vFormat("%-*d", VAR_FIELD_WIDTH, lec_ary[lrpt_idx].var);
					output_line += vFormat("%-*d", VAR_FIELD_WIDTH, pat_rel_var);

					// Add pattern data tokens for each pin
					output_line += get_vector_tokens(pPinList, lec_ary[lrpt_idx].var, lec_ary[lrpt_idx].data_lo, lec_ary[lrpt_idx].data_hi);
					output("%s", output_line);

				}  //  END OF FOR - FCOUNT

			}  // END OF IF - FCOUNT
			else {
				output("LEC scan return zero failures");
			}
		}  //  END OF WHILE
	}

	dlog_func = false;

}  // END OF FUNCTION LEC_REPORT
#endif

CString remove_tags(CString tagged)
{
	CString tagless, fail_line;
	bool vec_fail = false;

	tagless = fail_line = tagged;

	if (tagless.Replace("<COLOR=Red>H</COLOR>", "H"))
	{
		fail_line.Replace("<COLOR=Red>H</COLOR>", "^");
		vec_fail = true;
	}

	if (tagless.Replace("<COLOR=Red>L</COLOR>", "L"))
	{
		fail_line.Replace("<COLOR=Red>L</COLOR>", "^");
		vec_fail = true;
	}

	tagless.Replace("<COLOR=Green>", "");
	tagless.Replace("<COLOR=Red>", "");
	tagless.Replace("</COLOR>", "");

	tagless.Replace("<B>", "");
	tagless.Replace("</B>", "");

	tagless.Replace("<U>", "");
	tagless.Replace("</U>", "");

	tagless.Replace("<H5>", "");
	tagless.Replace("</H5>", "");

	if (vec_fail)
	{
		for (int i = 0; i<fail_line.GetLength(); i++)
		{
			if (fail_line[i] != '^')
			{
				fail_line.SetAt(i, ' ');
			}
		}

		tagless += vFormat("%s\n", fail_line);
	}

	return tagless;
}

BOOL check_dlog_enable(char type, CString dlog_info)
{
	if (type == 'o')
	{
		if (dlog_func || user)
		{
			if (tp_fdlog)
			{
				if (current_test_block() != "tp_ATB")
				{
					DutNumArray duts;

					int cnt = active_duts_get(&duts);

					for (int i = 0; i<cnt; i++)
					{
						DutNum Dut = duts[i];

						if (DlogOpen[Dut])
						{
							fprintf(fp_dut[Dut], "%s: %s", current_test_block(), remove_tags(dlog_info));
						}
					}
				}
			}
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}

	return TRUE;
}

int dlogfileopen(int Dut, int x_coord, int y_coord)
{
	remote_fetch(DLOG_FILE_PATH, 0, FALSE);

	CString FullName = DLOG_FILE_PATH;
	char LogFileName[256];

	if (oDriverType == "prober")
	{
		sprintf(LogFileName, "\\\\\\%s_%s_%s_Site%d_Dut%d_X%dY%d.txt", LOT_NUM, WFR_SLOT_ID, FLOW_NAME, site_num(), Dut + 1, x_coord, y_coord);
	}
	else
	{
		sprintf(LogFileName, "\\\\\\%s_%s_Site%d_Dut%d.txt", LOT_NUM, FLOW_NAME, site_num(), Dut + 1);
	}
	FullName += LogFileName;

	if ((fp_dut[Dut] = fopen(FullName, "a")) == NULL)
	{
		output("Problem opening (dut %d) file %s", Dut + 1, FullName);
		return(1);
	}

	return(0);
}


void dlogclose(int Dut)
{
	if (fclose(fp_dut[Dut]) != 0)
	{
		output("*************ERROR closing file***************");
	};
}

void dlogheader(int Dut)
{
	int x, y;

	TPEGetCurrentXY(Dut, &x, &y);

	fprintf(fp_dut[Dut], "$  Test Station: Magnum II                        $ Wafer Lot: %s\n", LOT_NUM);
	fprintf(fp_dut[Dut], "$ X=%d, Y=%d, Site=%d \n", x, y, site_num());
}

void dlogfileopenallactive(void)
{
	int x, y;

	remote_fetch(tp_fdlog, 0, FALSE);

	if (tp_fdlog == FALSE)
	{
		return;
	}

	for (int cntr = 0; cntr <= max_dut(); cntr++)
	{
		DlogOpen[cntr] = false;
	}

	SoftwareOnlyActiveDutIterator ActiveList;
	while (ActiveList.More())
	{
		DutNum Dut = active_dut_get();

		TPEGetCurrentXY((int)Dut, &x, &y);

		DlogOpen[Dut] = true;
		dlogfileopen(Dut, x, y);
	}

}

void dlogcloseallopen(void)
{
	float time = (float)stopseqcntr();

	//output("Overall Test Time = %f Seconds\n %s", time, sa_tag);
	output("Overall Test Time = %f Seconds\n", time);
	OutputLogtoFile();
	if (tp_fdlog == FALSE)
	{
		return;
	}

	for (int cntr = 0; cntr <= max_dut(); cntr++)
	{
		if (DlogOpen[cntr])
		{
			fprintf(fp_dut[cntr], "Overall Test Time = %f Seconds", time);
			fclose(fp_dut[cntr]);
			DlogOpen[cntr] = false;
		}
	}
}

void dlogheaderallopen(void)
{

	if (tp_fdlog == FALSE)
	{
		return;
	}

	for (int DutCntr = 0; DutCntr <= max_dut(); DutCntr++)
	{
		if (DlogOpen[DutCntr])
			dlogheader(DutCntr);
	}
}

void dlogtblkheaderallactive(CString TblkName)
{
	int x, y;

	SoftwareOnlyActiveDutIterator ActiveList;
	while (ActiveList.More())
	{
		DutNum Dut = active_dut_get();

		TPEGetCurrentXY((int)Dut, &x, &y);

		if (user&&tp_fdlog) fprintf(fp_dut[Dut], "+=================================================================================+\n");
		if (user&&tp_fdlog) fprintf(fp_dut[Dut], "| %s  X %d, Y %d \n", TblkName, x, y);
		if (user&&tp_fdlog) fprintf(fp_dut[Dut], "+=================================================================================+\n");
	}

}

void dlogtestresults()
{
	dlog_func = TRUE;

	if (dlog) output("Test %s, time = %f Seconds", current_test_block(), stopcntr());

	dlog_func = FALSE;
}

void create_datalog_folder()
{
	if (tp_fdlog)
	{
		CString CMDLine = "D:\\Datalogs";
		CFileFind finder;

		if (finder.FindFile(CMDLine) == false)
		{
			if (!CreateDirectory(CMDLine, NULL))
			{
				output("Creating Directory failed %s", CMDLine);
				tp_fdlog = false;
				return;
			}
			else
			{
				output("Directory %s created  Successfully!", CMDLine);
			}
		}

		CMDLine += vFormat("\\Lot%s", LOT_NUM);

		if (finder.FindFile(CMDLine) == false)
		{
			if (!CreateDirectory(CMDLine, NULL))
			{
				output("Creating Directory failed %s", CMDLine);
				tp_fdlog = false;
				return;
			}
			else
			{
				output("Directory %s created  Successfully!", CMDLine);
			}
		}

		DLOG_FILE_PATH = CMDLine;
		output("DLOG_FILE_PATH  = %s", DLOG_FILE_PATH);
	}
}

int tb_header(void)
{

	TB_Timer.StartTimer();

	DutNumArray active_duts1;
	int count = active_duts_get(&active_duts1);

	int tmp = active_duts_get(&active_dut_mask);
	curr_dut_mask = active_dut_mask;

	if (count != 0)
	{
		results_get(&r1);	//	initialize Test result arrays
		results_get(&r2);
		results_get(&r3);
		results_get(&r4);
		results_get(&r5);
		results_get(&r6);
		results_get(&r7);
		results_get(&r8);
		results_get(&r9);
		results_get(&r10);
		results_get(&r11);
		results_get(&r12);
		results_get(&r13);
		results_get(&r14);
		results_get(&r15);
		results_get(&r16);
		results_get(&r17);
		results_get(&r18);
		results_get(&r19);
		results_get(&r20);
		results_get(&r21);
		results_get(&r22);
		results_get(&r23);
		results_get(&r24);
		results_get(&r25);
	}
	//active_duts_enable(0x3ffffffffff);	//laura add

	return TRUE;
}

void text_down_coordinate(void)
{
	int x, y;
	SoftwareOnlyActiveDutIterator ActiveList;
	output("+=sign for text_down_coordinate======================================");
	while (ActiveList.More())
	{
		DutNum Dut = active_dut_get();

		TPEGetCurrentXY((int)Dut, &x, &y);
		output("|SFTDC Dut:%02d  X %d, Y %d \n", Dut, x, y);
	}
	output("+====================================================================");
}


int tb_end(bool flag)
{
	display_test_results(flag);
	//TB_Timer.StopTimer(" TB Time ="); // transferred to display_test_results()
	return MULTI_DUT;
}