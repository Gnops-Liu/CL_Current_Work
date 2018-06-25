#include "tester.h"
#include "User_subroutine.h"
#include "User.h"
BOOL VPPtrimValsDone = false;
BOOL VPNtrimValsDone = false;

DWORD *ebm_dma_data_f;
DWORD *ebm_dma_data_l;
int ebm_dma_container_f;
int ebm_dma_container_l;

///////////////BGTrim///////////
double BGTrim_voltage[16][64];//max_dut() can be use?
double BGTrim_compresult[16][64];
int    BGTrim_data[16];

///////////////VR16Trim//////////////////
double VR16Trim_voltage[16];//multi dut.42

/////////////OSCTrim///////////
int OSC_compare_data[16][89];//get fre value by LEC_Compare
int OSC_Trim_data[16];

/////////////VDELTrim///////////
CArray<IntArray, IntArray>VDEL_compare_data;  // Make MSDN CArray which has bounds checking.
IntArray VDELTrim_data;

/////////////VPPTrim///////////
double PGVPPTrim_voltage[16][16];//16duts
double FlashVPPTrim_compresult[16][16];
int	VPPTrim_data[16];

///////////////VNNTrim///////////////////////
double FlashVNNTrim_voltage[16][16];
double FlashVNNTrim_compresult[16][16];
int	VNNTrim_data[16];

BOOL_VARIABLE(DBG_DO_AVERAGING, false, "Do averaging on HV FIMV voltage tests"){}
INT_VARIABLE(DBG_HV_AVG_COUNT, 10, "Number of averages to execute") 
{
	output("Setting the measurement average count to %d", DBG_HV_AVG_COUNT);
	iacc_count_set(DBG_HV_AVG_COUNT);
}
DOUBLE_VARIABLE(DBG_PAT_START_DELAY, 5, "Time after pattern start in MS"){}
DOUBLE_VARIABLE(DBG_PARTIME_DELAY, 2, "Time in ms for HV pin DELAY") {}
BOOL_VARIABLE(DBG_PRECHARGE_EXPERIMENT, false, "Set to true to precharge hv pin"){}
BOOL_VARIABLE(DBG_ALTERNATE_MEAS_METHOD, false, "Set to true to use ac_dpo_hv_partest -- more complex") {}


BOOL_VARIABLE(DBG_DO_EXTRA_POWERDOWN, true, "do extra powerdown before test"){}
UINT64_VARIABLE(ui64v_startmask, 0, ""){}
INT_VARIABLE(iv_count, 0, ""){}
BOOL_VARIABLE(DBG_USE_PIN_DC_STATE_SET, false, "Experiment"){}



void PrintActiveDuts() {
	DutNumArray adl;
	int count = active_duts_get(&adl);
	CString msg;
	CString dutName;
	output("ActiveDuts=");
	for (int i = 0; i < count; i++){
		dutName.Format("t_dut%d\t", adl.ElementAt(i) + 1);
		if ((i > 0) && ((i % 15) == 0)) msg += "\n";
		msg += dutName;
	}
	output(msg);
}
void printFailDuts() {
	return; //a8p
	SoftwareOnlyActiveDutIterator swadi;
	IntArray PassFailResults;
	while (swadi.More()){
		DutNum thisDut = active_dut_get();
		int result = result_get(thisDut);
		if (result == 0)output("DUT%d is **FAIL**", thisDut + 1);
	}
}


void test_block_header(void)
{
	tb_header(); // Start TestBlock_Timer Should be first call in Test Block, if used.
	
}

int test_block_footer(void)
{
	//output("TestBlock = %-15s Complete ", current_test_block());
	return tb_end();
}

BEFORE_TESTING_BLOCK(btb_name)
{
	FlowTimer.StartTimer();		// Start Flow Timer
	//remote_set(UI_DATALOG_SITE, 0, site_num(), TRUE);
	output("Output from BEFORE_TESTING_BLOCK, Site number %d", site_num());
	power_down();				// Call function to set ref voltages to zero
    //dps_comp_cap_set(.0000001, .001, pl_VCC);		// Assumeing 1uf decoupling cap On Vcc
	dps_comp_cap(2);
	dpo_comp_cap_set(2);
	dps_connect(pl_TST);		// Must Connect DPS pins, System SW does not do this
	dpo_connect(pl_VCC);
	dpo_hv_disconnect(pl_VNN);  // Make sure the pl_TPPAD pin is disconnected
	Delay(5 MS);

	VPPtrimValsDone = false;
	VPNtrimValsDone = false;

	measure(TRUE);			// Enables ability to retrive parametric measuements
}

AFTER_TESTING_BLOCK(atb_name)
{
	output("Output from AFTER_TESTING_BLOCK, Site number %d", site_num());
	FlowTimer.StopTimer("Total Flow ");	//Stop Flow Timer and output time
}

TEST_BLOCK(tb_BGTrim_all_test)
{
	test_block_header();
	//dpo_hv_disconnect(pl_dpohv_disconnect_pin); Delay(2 MS);
	dpo_hv_vrange_set(pl_VNN, t_dpo_default_hv_vrange);
	dpo_hv_connect(pl_VNN);

	ebm_config_set(t_ebm_data_mode, pl_SDA);
	vs_set();
	ts_10mhz();

	//vclamp(6 V, 0 V);
	measure(true);
	partime(1000 US); //tb_BGTrim_all_test

	dpo_pmu_vclamp_set(3 V, 0 V);
	dpo_vpar_high_set(3 V);
	dpo_vpar_low_set(0 V);
	dpo_ipar_force_set(0 MA);

	DutNumArray active_duts;
	int original_duts = active_duts_get(&active_duts);

	int count = active_duts_get(&ui64v_startmask);
	ebm_clear();						 //ebm config



		for (int BGTrim_data = 0; BGTrim_data < 64; BGTrim_data++)
		{
			set_udata(BG_Trim, "BG_change", BGTrim_data);

			start_pattern(BG_Trim);

			partest(pass_nivl, pl_TST);	// start pattern, delay(2), partest = 27 ms
			BG_save_trim_value(BGTrim_data);	//5ms
			stop_pattern();
		}
	active_duts_enable(active_duts, true);

#ifdef display_datalog
	for (int dut = 0; dut <= 16; dut++)
	{
		CString s = vFormat("BGTrim_scan:	%d", dut + 1);
		for (int i = 0; i <= 63; i++)
		{
			s += vFormat("	%6.4f", BGTrim_voltage[dut][i] * 0.001*0.001);
		}
		output(s);
	}
#endif

	BG_write_trim_data();//write_BG_Trim
	return test_block_footer();
}



TEST_BLOCK(tb_FlashTrimming_PG_VPP_test_Lvcc)//***
{
	tb_header();
	vs_set();
	ts_10mhz();
	vclamp(12 V, 0 V, pl_VPP);
	partime(DBG_PARTIME_DELAY MS);
	//dpo_hv_disconnect(pl_dpohv);
	ipar_force(0 MA, pl_VPP);
	vpar_high(10.44 V, pl_VPP);
	vpar_low(9.74 V, pl_VPP);

	//set_udata(VR1215_pullhi, "pullhi_change", 0x60);	//VR1215_pullhi_0000
	//funtest(VR1215_pullhi, finish);

	DutNumArray active_duts;
	int original_duts = active_duts_get(&active_duts);
	int count = active_duts_get(&ui64v_startmask);
	output("\n   ***mg  There are currently %d active DUTs", count);
	output("  ***mg  The starting active DUT mask is 0x%016I64x", ui64v_startmask);
	//dpo_hv_connect(pl_TPPAD);
	for (int PGVPP_Trim_data = 0; PGVPP_Trim_data < 16; PGVPP_Trim_data++)
	{
		set_udata(PGVPP_tirm, "PGVPP_change", PGVPP_Trim_data);
		start_pattern(PGVPP_tirm);
		Delay(DBG_PAT_START_DELAY MS);
		partest(pass_nivl, pl_VPP);
		tp_pdatalog(pl_VPP, ForceIMeasureV);
		stop_pattern();
		PGVPP_save_trim_value(PGVPP_Trim_data);
	}
#ifdef display_datalog
	for (int dut = 0; dut <= 16; dut++)
	{
		CString s = vFormat("FlashVPPTrim_scan:	%d", dut + 1);
		for (int i = 0; i <= 15; i++)
		{
			s += vFormat("	%6.3f", PGVPPTrim_voltage[dut][i] * 0.001*0.001);
		}
		output(s);
	}
#endif

	hv_disconnect(pl_VPP);  // HVpin is forcing 0V unless otherwise programmed, this might not be good for DUT in all cases

	return test_block_footer();
}




TEST_BLOCK(tb_OSC_Trim_OSC_72MHZ)//****
{
	test_block_header();
	power_down();
	Delay(5 MS);
	vs_set();
	ts_10mhz();
	ebm_address_pointer_reset();

	funtest(OSC_Trim_72, finish);
	tp_fdatalog(pl_SDA);

	return test_block_footer();
}

TEST_BLOCK(tb_VR16_trim)               //****
{
	test_block_header();
	power_down();
	Delay(5 MS);
	vs_set();
	ts_10mhz();
	ebm_address_pointer_reset();
	ipar_force(0);
	vpar_high(1.815 V);
	vpar_low(1.515 V);

	funtest(VR16_trim, finish);
	partest(pass_nivl, pl_DVDD_1P5);

	for (int VR16Trim_voltage = 0; VR16Trim_voltage < 16; VR16Trim_voltage++)
	{
		VR16_save_trim_value(VR16Trim_voltage);	//5ms
	}

#ifdef display_datalog
	for (int dut = 0; dut <= 16; dut++)
	{
		CString s = vFormat("VR16Trim_scan:	%d", dut + 1);
		s += vFormat("	%6.4f", VR16Trim_voltage[dut] * 0.001*0.001);
		output(s);
	}
#endif
	return test_block_footer();
}



