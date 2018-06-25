#include "tester.h"
#include "User_subroutine.h"
// ******************************
// *****  Test Blocks file  *****
// ******************************


BEFORE_TESTING_BLOCK( tb_init )
{
	//Do not touch
	//remote_set(UI_DATALOG_SITE, 0, site_num(), TRUE, INFINITE);
	remote_set(UI_DATALOG_SITE, UI_CREATE_DATALOG_FILE_FLAG, site_num(), TRUE, INFINITE);


	FlowTimer.StartTimer();
	//	total_time.ResetTime();
	dps_comp_cap(1);
	dpo_comp_cap_set(1);
	reset_error();
	data_strobe(0xfffffffff);
	dps_comp_cap(1);
	//if the channel is totally independent
	dps_output_mode_set(pl_dps, t_dps_independent);
	dps_connect(pl_dps);
	hv_connect(pl_hv);
	dpo_connect(pl_dpo);
	dpo_hv_connect(pl_dpohv);

	//MyStartTimer("This touchdown start at");

	measure(TRUE);
	//power_down();
}



AFTER_TESTING_BLOCK( test_complete ) {
	//tb_Summary();
	output("Output from AFTER_TESTING_BLOCK, Site number %d", site_num());
	//site_show_bins();
	FlowTimer.StopTimer("Total Flow ");	//Stop Flow Timer and output time
} // end of TEST_BLOCK( test_complete )



TEST_BLOCK(tb_Continuity_Neg)
{
	tb_header();
	power_down();							// Set Voltages
	partime(3 MS);
	//vclamp(7 V, -2 V);						// Set vclamp because this TB forces current
	ipar_force(-100 UA);					// Set Force Value
	vpar_high(-200 MV);					// Set high Limit
	vpar_low(-1.0 V);						// Set low limit
	partest(pass_nivl, pl_all_pins);		// Execute Test
	tp_pdatalog(pl_all_pins, ForceIMeasureV);		// Output parametric results to UI site tab
	ipar_force(0 UA);

	return tb_end();
}

TEST_BLOCK(tb_Continuity_Pos)
{
	tb_header();
	power_down();							// Set Voltages
	//partime(10 MS);
	//vclamp(7 V, -2 V);						// Set vclamp because this TB forces current
	ipar_force(100 UA);					// Set Force Value
	vpar_high(1.0 V);					// Set high Limit
	vpar_low(200 MV);						// Set low limit
	partest(pass_nivl, pl_all_pins);		// Execute Test
	tp_pdatalog(pl_all_pins, ForceIMeasureV);		// Output parametric results to UI site tab
	ipar_force(0 UA);

	return tb_end();
}
TEST_BLOCK(tb_Continuity_dps)
{
	tb_header();
	power_down();
	//partime(10 MS);
	vclamp(7 V, -2 V);
	ipar_force(-100 UA);
	vpar_high(-200 MV);
	vpar_low(-1 V);
	partest(pass_nivl, pl_dps);
	tp_pdatalog(pl_dps, ForceIMeasureV);
	ipar_force(0 UA);

	return tb_end();
}

TEST_BLOCK(tb_Continuity_hv)
{

	tb_header();
	power_down();
	//partime(10 MS);
	vclamp(7 V, -2 V);
	ipar_force(-100 UA);
	vpar_high(-200 MV);
	vpar_low(-1 V);
	partest(pass_nivl, pl_hv);
	tp_pdatalog(pl_hv, ForceIMeasureV);
	ipar_force(0 UA);

	return tb_end();
}

TEST_BLOCK(tb_Continuity_dpo)
{
	tb_header();
	power_down();
	//partime(10 MS);
	dpo_pmu_vclamp_set(7 V, -2 V);
	dpo_ipar_force_set(-100 UA);
	dpo_vpar_high_set(-200 MV);
	dpo_vpar_low_set(-1 V);
	dpo_partest(pass_nivl, pl_dpo);
	tp_pdatalog(pl_dpo, ForceIMeasureV);
	ipar_force(0 UA);

	return tb_end();
}

TEST_BLOCK(tb_Continuity_dpohv)
{
	tb_header();
	power_down();
	//partime(10 MS);

	dpo_ipar_force_set(-100 UA, pl_dpohv);
	dpo_vpar_high_set(-200 MV, pl_dpohv);
	dpo_vpar_low_set(-1 V, pl_dpohv);

	dpo_hv_partest(pass_nivl, pl_dpohv);
	tp_pdatalog(pl_dpohv, ForceIMeasureV);
	ipar_force(0 UA);

	return tb_end();
}

//-----------------------------------------leakage-----------------------------------------------------------------
TEST_BLOCK(tb_leakage_low)
{
	tb_header();
	dps(3.0 V, pl_TST);							// Set  Voltages
	vpar_force(0 V);						// Set Force Value
	ipar_high(20 UA);						// Set high Limit
	ipar_low(-20 UA);						// Set low limit
	partime(10 MS);								// No Additional parametric wait time 
	back_voltage(3.0 V);
	back_voltage_enable(true);				// Enable background voltage
	partest(pass_nicl, pl_all_pins);		// Execute Test
	tp_pdatalog(pl_all_pins, ForceVMeasureI);				// Output parametric results to UI site tab
	back_voltage_enable(false);				// Disable background voltage
	return tb_end();
}

TEST_BLOCK(tb_leakage_high)
{
	tb_header();
	dps(3.0 V, pl_TST);							// Set Voltages
	vpar_force(3.0 V);						// Set Force Value
	ipar_high(20 UA);						// Set high Limit
	ipar_low(-20 UA);						// Set low limit
	partime(10 MS);								// No Additional parametric wait time 
	back_voltage(0 V);						// Set background voltage to 0 V
	back_voltage_enable(true);				// Enable background voltage
	partest(pass_nicl, pl_all_pins);		// Execute Test
	tp_pdatalog(pl_all_pins, ForceVMeasureI);				// Output parametric results to UI site tab
	back_voltage_enable(false);				// Disable background voltage
	vpar_force(0 V);                        

	return tb_end();
}

TEST_BLOCK(tb_ISBcmos_Init)
{
	tb_header();
	dps(3.0 V, pl_TST);
	vih(3.0 V);
	vil(0 V);
	voh(2 V);
	vol(0.8 V);
	iol(0 MA, pl_all_pins);
	ioh(0 MA, pl_all_pins);
	vz(1.5 V, pl_all_pins);
	 

	dps_current_high(800 UA, pl_TST);
	dps_current_low(100 UA, pl_TST);
	
	partime(10 MS);
	test_supply(pass_nicl, pl_TST);
	tp_pdatalog(pl_TST, ForceVMeasureI);
	
	return tb_end();
}





