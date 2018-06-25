/***********************************************************************/
// Datalog.cpp
// version 2.1  -  10/20/2010
/***********************************************************************/

#include "tester.h"
#include "math.h"  //  needed for fabs()
#define Datalog_control 0

EXTERN_INT_VARIABLE( dlog ) ;

extern DutNumArray active_duts;
DutNumArray save_active_duts;

// Get the dut pin number that was set in PIN_ASSIGNMENT
extern CString get_dut_pin_number(DutPin *);

// Pass/Fail Definition
char *PFStateString[] = { "FAIL", "PASS" };

/***********************************************************************/
// Converts the measured results into a string with units and multiplier
/***********************************************************************/

CString cnvt_result(double value, e_log_type log_type){
	CString cstr;

	switch (log_type) {
	case LOG_V:	 // convert to voltage
		if (fabs(value) >= (1 V)) {
			cstr.Format("%8.3f v", value / (1 V));
		}
		else {
			cstr.Format("%8.0f mv", value / (1 MV));
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
}  // end of cnvt_result

double* Dpo_HV_Result(PinList *pPinList)
{
	CString LineBfr;
	CString OutBfr;
	OutBfr.Empty();
	extern double result_temp[12];
	// determine the what type of test was just run
	e_log_type log_type;
	switch (parametric_mode()) {
	case 0:	log_type = LOG_I; break;
	case 2:	log_type = LOG_I; break;
	case 1:	log_type = LOG_V; break;
	default: output("Invalid parametric mode : %d", parametric_mode());
	}

	// Print header info
#if Datalog_control
	output("TestBlock = %-15s   TestNumber = %d", current_test_block(), test_number());
#endif
	if (dlog > 1) {
		if (measure() == TRUE) {
			LineBfr.Format("------------------------------------------------- \n"); OutBfr += LineBfr;
			LineBfr.Format("-------------------------------------------------\n"); OutBfr += LineBfr;
			LineBfr.Format("Tester      Pin          Pin     Pin     Measured\n"); OutBfr += LineBfr;
			LineBfr.Format(" Pin        Name         Number  Result  Value   \n"); OutBfr += LineBfr;
			LineBfr.Format("-------------------------------------------------\n"); OutBfr += LineBfr;
		}
		else {
			LineBfr.Format("-----------------------------------------\n"); OutBfr += LineBfr;
			LineBfr.Format("Tester      Pin          Pin     Pin     \n"); OutBfr += LineBfr;
			LineBfr.Format(" Pin        Name         Number  Result  \n"); OutBfr += LineBfr;
			LineBfr.Format("-----------------------------------------\n"); OutBfr += LineBfr;
		}
	}  // end of if(dlog>1)
	SoftwareOnlyActiveDutIterator so_active_loop;
	while (so_active_loop.More()) {
		DutNum dut_num = active_dut_get();

		CArray<double, double> meas_results;
		CArray<PFState, PFState> pf_results;

		// check the pinlist for either dps pins or signal pins

		DpoHv_meas(meas_results);	// get the measured results for this dut
		DpoHv_pf(pf_results);

		LineBfr.Format("Dut %d : %s\n", dut_num + 1, result_get(dut_num) ? "PASS" : "FAIL");
		OutBfr += LineBfr;

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
				LineBfr.Format("%-10s   %-10s   %-5s	%4s  %s\n", tpin_name, pin_name, get_dut_pin_number(dpin),
					pf_results[meas_index] ? "PASS" : "FAIL",
					cnvt_result(meas_results[meas_index], log_type));
				OutBfr += LineBfr;
				result_temp[dut_num] = meas_results[meas_index] / (1 V);
			}

			else
			{
				LineBfr.Format("%-10s   %-10s   %-5s	%4s\n", tpin_name, pin_name, get_dut_pin_number(dpin),
					pf_results[meas_index] ? "PASS" : "FAIL");
				OutBfr += LineBfr;
			}
			++meas_index;
#if Datalog_control
			output("%d:Result = %f V", dut_num, result_temp[dut_num]);
#endif
		}

		ASSERT(meas_index == meas_results.GetSize());
	} // End SW only iterator
#if Datalog_control
	output("%s", OutBfr);
#endif
	return result_temp;
}

double* Dpo_HV_Result(PinList *pPinList, char c)
{
	CString LineBfr;
	CString OutBfr;
	OutBfr.Empty();
	extern double result_temp[12];
	// determine the what type of test was just run
	e_log_type log_type;
	switch (parametric_mode()) {
	case 0:	log_type = LOG_I; break;
	case 2:	log_type = LOG_I; break;
	case 1:	log_type = LOG_V; break;
	default: output("Invalid parametric mode : %d", parametric_mode());
	}

	// Print header info
#if Datalog_control
	output("TestBlock = %-15s   TestNumber = %d", current_test_block(), test_number());
#endif
	if (dlog > 1) {
		if (measure() == TRUE) {
			LineBfr.Format("------------------------------------------------- \n"); OutBfr += LineBfr;
			LineBfr.Format("-------------------------------------------------\n"); OutBfr += LineBfr;
			LineBfr.Format("Tester      Pin          Pin     Pin     Measured\n"); OutBfr += LineBfr;
			LineBfr.Format(" Pin        Name         Number  Result  Value   \n"); OutBfr += LineBfr;
			LineBfr.Format("-------------------------------------------------\n"); OutBfr += LineBfr;
		}
		else {
			LineBfr.Format("-----------------------------------------\n"); OutBfr += LineBfr;
			LineBfr.Format("Tester      Pin          Pin     Pin     \n"); OutBfr += LineBfr;
			LineBfr.Format(" Pin        Name         Number  Result  \n"); OutBfr += LineBfr;
			LineBfr.Format("-----------------------------------------\n"); OutBfr += LineBfr;
		}
	}  // end of if(dlog>1)
	SoftwareOnlyActiveDutIterator so_active_loop;
	while (so_active_loop.More()) {
		DutNum dut_num = active_dut_get();

		CArray<double, double> meas_results;
		CArray<PFState, PFState> pf_results;

		// check the pinlist for either dps pins or signal pins

		DpoHv_meas(meas_results);	// get the measured results for this dut
		DpoHv_pf(pf_results);

		LineBfr.Format("Dut %d : %s\n", dut_num + 1, result_get(dut_num) ? "PASS" : "FAIL");
		OutBfr += LineBfr;

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
				LineBfr.Format("%-10s   %-10s   %-5s	%4s  %s\n", tpin_name, pin_name, get_dut_pin_number(dpin),
					pf_results[meas_index] ? "PASS" : "FAIL",
					cnvt_result(meas_results[meas_index], log_type));
				OutBfr += LineBfr;
				result_temp[dut_num] = meas_results[meas_index] / (1 MA);
			}

			else
			{
				LineBfr.Format("%-10s   %-10s   %-5s	%4s\n", tpin_name, pin_name, get_dut_pin_number(dpin),
					pf_results[meas_index] ? "PASS" : "FAIL");
				OutBfr += LineBfr;
			}
			++meas_index;
#if Datalog_control
			output("%d:Result = %f MA", dut_num, result_temp[dut_num]);
#endif
		}

		ASSERT(meas_index == meas_results.GetSize());
	} // End SW only iterator
#if Datalog_control
	output("%s", OutBfr);
#endif
	return result_temp;
}

double* HV_Result(PinList *pPinList)
{
	CString LineBfr;
	CString OutBfr;
	OutBfr.Empty();
	extern double result_temp[12];
	// determine the what type of test was just run
	e_log_type log_type;
	switch (parametric_mode()) {
	case 0:	log_type = LOG_I; break;
	case 2:	log_type = LOG_I; break;
	case 1:	log_type = LOG_V; break;
	default: output("Invalid parametric mode : %d", parametric_mode());
	}

	// Print header info
#if Datalog_control
	output("TestBlock = %-15s   TestNumber = %d", current_test_block(), test_number());
#endif
	if (dlog > 1) {
		if (measure() == TRUE) {
			LineBfr.Format("------------------------------------------------- \n"); OutBfr += LineBfr;
			LineBfr.Format("-------------------------------------------------\n"); OutBfr += LineBfr;
			LineBfr.Format("Tester      Pin          Pin     Pin     Measured\n"); OutBfr += LineBfr;
			LineBfr.Format(" Pin        Name         Number  Result  Value   \n"); OutBfr += LineBfr;
			LineBfr.Format("-------------------------------------------------\n"); OutBfr += LineBfr;
		}
		else {
			LineBfr.Format("-----------------------------------------\n"); OutBfr += LineBfr;
			LineBfr.Format("Tester      Pin          Pin     Pin     \n"); OutBfr += LineBfr;
			LineBfr.Format(" Pin        Name         Number  Result  \n"); OutBfr += LineBfr;
			LineBfr.Format("-----------------------------------------\n"); OutBfr += LineBfr;
		}
	}  // end of if(dlog>1)
	SoftwareOnlyActiveDutIterator so_active_loop;
	while (so_active_loop.More()) {
		DutNum dut_num = active_dut_get();

		CArray<double, double> meas_results;
		CArray<PFState, PFState> pf_results;

		// check the pinlist for either dps pins or signal pins

		Hv_meas(meas_results);	// get the measured results for this dut
		Hv_pf(pf_results);

		LineBfr.Format("Dut %d : %s\n", dut_num + 1, result_get(dut_num) ? "PASS" : "FAIL");
		OutBfr += LineBfr;

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
				LineBfr.Format("%-10s   %-10s   %-5s	%4s  %s\n", tpin_name, pin_name, get_dut_pin_number(dpin),
					pf_results[meas_index] ? "PASS" : "FAIL",
					cnvt_result(meas_results[meas_index], log_type));
				OutBfr += LineBfr;
				result_temp[dut_num] = meas_results[meas_index] / (1 V);
			}

			else
			{
				LineBfr.Format("%-10s   %-10s   %-5s	%4s\n", tpin_name, pin_name, get_dut_pin_number(dpin),
					pf_results[meas_index] ? "PASS" : "FAIL");
				OutBfr += LineBfr;
			}
			++meas_index;
#if Datalog_control
			output("%d:Result = %f V", dut_num, result_temp[dut_num]);
#endif
		}

		ASSERT(meas_index == meas_results.GetSize());
	} // End SW only iterator
#if Datalog_control
	output("%s", OutBfr);
#endif
	return result_temp;
}


/***********************************************************************/
// Functional Datalog
// This function returns the failing pins for a functional memory
// or logic test pattern.  The error status is acquired from the
// PE rather than from the ECR.
/***********************************************************************/
void fdatalog(PinList* pPinList)
{
	TesterPin tpin;
	DutPin * dpin;
	CString pin_name;
	PFState pass_fail;


	if (dlog == 0) {  // datalog off
		return;
	}

	CString LineBfr;
	CString OutBfr;
	OutBfr.Empty();

	SoftwareOnlyActiveDutIterator so_active_loop;
	while (so_active_loop.More())
	{
		DutNum dut_num = active_dut_get();




		LineBfr.Format("Dut %2d : %s \\", dut_num + 1, result_get(dut_num) ? "PASS" : "FAIL");
		OutBfr += LineBfr;
		pin_info(pPinList, 0, &dpin);	// get the first pin of the pinlist
		pin_info(dpin, dut_num, &tpin);			// get the tester channel based on DutPin
		// create a temporary pinlist with only one pin
		PinList *pPin = pinlist_create(&tpin, 1);
		pass_fail = test_pin(pPin);
		pinlist_destroy(pPin);
		pin_name = resource_name(dpin);
		LineBfr.Format("<%s>%c", pin_name, pass_fail ? 'P' : 'F'); OutBfr += LineBfr;

		// Loop through all pins and look for pass/fail
		for (int pin_index = 1; pin_info(pPinList, pin_index, &dpin); pin_index++) {

			pin_info(dpin, dut_num, &tpin);			// get the tester channel based on DutPin

			// create a temporary pinlist with only one pin
			PinList *pPin = pinlist_create(&tpin, 1);
			pass_fail = test_pin(pPin);
			pinlist_destroy(pPin);

			pin_name = resource_name(dpin);
			LineBfr.Format("%c", pass_fail ? 'P' : 'F'); OutBfr += LineBfr;
		}
		LineBfr.Format("<%s> \n", pin_name); OutBfr += LineBfr;
	}	// End SO active dut iterator
	output("%s", OutBfr);
}

double abslt(double temp)
{
	if (temp < 0)
		return (-temp);
	else
		return temp;
}
