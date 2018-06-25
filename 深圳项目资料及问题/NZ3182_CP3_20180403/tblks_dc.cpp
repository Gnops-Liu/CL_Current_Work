#include "tester.h"
//#include "User_subroutine.h"
// ******************************
// *****  Test Blocks file  *****
// ******************************

//extern BOOL test_result;
BOOL test_result;
//extern Elapsed test_time;

extern IntArray r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15;	// To store local test results
extern IntArray r16, r17, r18, r19, r20, r21, r22, r23, r24, r25;	// To store local test results

int LogFlag = 1;

BEFORE_TESTING_BLOCK(NZ3182_BEFORE)
{
	if (LogFlag == 1)
	{
		CreatDatalogName();
		LogFlag = 0;
	}
	//remote_set(UI_DATALOG_SITE, 0, site_num(), TRUE);
	output("Output from BEFORE_TESTING_BLOCK, Site number %d", site_num());
	FlowTimer.StartTimer();
	//	total_time.ResetTime();
	reset_error();
	data_strobe(0xffffffff);
	edge_strobe(pl_IOPINS, TRUE);
	//dps_connect(pl_VDD);
	pin_connect();
	//dps_comp_cap(1);
	measure(TRUE);
	ecr_all_clear();
	power_down();
	ptu_vclamp_set(3.5 V, 0.0 V, pl_IOPINS);
	ptu_vclamp_enable(true, pl_IOPINS);
	//	clear_dut_bins();
	//	test_time.ResetTime();
}



AFTER_TESTING_BLOCK(NZ3182_AFTER) {
	output("Output from AFTER_TESTING_BLOCK, Site number %d", site_num());
	//site_show_bins();
	power_down();
	FlowTimer.StopTimer("Total Flow ");	//Stop Flow Timer and output time
} // end of TEST_BLOCK( test_complete )

TEST_BLOCK(tb_OS)
{
	tb_header();
	int dut_count;
	power_down();
	back_voltage(0.0 V);
	back_voltage_enable(TRUE);
	//partime(1 MS);
	measure(TRUE);

	ipar_force(-100 UA);
	vpar_high(-0.2 V);
	vpar_low(-1.2 V);
	vclamp(7 V, -2 V);
	test_result = partest(pass_nivl, pl_OSPINS);
	tp_pdatalog(pl_OSPINS, ForceIMeasureV);
	dut_count = results_get(&r1);

	ipar_force(-100 UA);
	vpar_high(-0.2 V);
	vpar_low(-1.2 V);
	vclamp(7 V, -2 V);

	test_result = partest(pass_nivl, pl_VDD);
	tp_pdatalog(pl_VDD, ForceIMeasureV);
	dut_count = results_get(&r2);
	for (int i = 0; i<dut_count; i++)r1[i] = r1[i] && r2[i] && r3[i] && r4[i];
	results_set(r1);
	
	back_voltage_enable(false);
	return tb_end(0);
}

