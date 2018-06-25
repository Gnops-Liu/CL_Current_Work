#define TESTER_H "tester.h"
#include TESTER_H

// *********************************************************
// *****  Pin Assignment Table and Current Share file  *****
// *********************************************************


#define  NUM_DUTS 16

static CMap < DutPin *, DutPin *, CString, CString > dut_pin_info;
DUT_PIN(CLK)      { }                       
DUT_PIN(SDA)      { }                       
DUT_PIN(TST)      { }                       
DUT_PIN(RESET)    { }                       
DUT_PIN(VCC)      { }                   
DUT_PIN(DVDD_1P5) { }                       
DUT_PIN(VPP)      { }                   
DUT_PIN(VNN)      { }                   

HOB_ASSIGNMENTS(SA8_DPO2){
	//***************   PMN  HSB     MOD_TYPE  INSTANCE
	    ASSIGN_OPTION_MODULE(1, t_hsb1, t_dpo_module, 1)
		ASSIGN_OPTION_MODULE(2, t_hsb1, t_dpo_module, 2)
		ASSIGN_OPTION_MODULE(3, t_hsb2, t_dpo_module, 1)
		ASSIGN_OPTION_MODULE(4, t_hsb2, t_dpo_module, 2)
		ASSIGN_OPTION_MODULE(5, t_hsb3, t_dpo_module, 1)
		ASSIGN_OPTION_MODULE(6, t_hsb3, t_dpo_module, 2)
		ASSIGN_OPTION_MODULE(7, t_hsb4, t_dpo_module, 1)
		ASSIGN_OPTION_MODULE(8, t_hsb4, t_dpo_module, 2)
}

PIN_ASSIGNMENTS(pn_102) {
	add(obj, CLK, NUM_DUTS, a_33, b_33, a_37, b_37, a_41, b_41, a_45, b_45, a_49, b_49, a_53, b_53, a_57, b_57, a_61, b_61);
	add(obj, SDA, NUM_DUTS, a_2, b_2, a_6, b_6, a_10, b_10, a_14, b_14, a_18, b_18, a_22, b_22, a_26, b_26, a_30, b_30);
	add(obj, RESET, NUM_DUTS, a_1, b_1, a_5, b_5, a_9, b_9, a_13, b_13, a_17, b_17, a_21, b_21, a_25, b_25, a_29, b_29);
	add(obj, DVDD_1P5, NUM_DUTS, a_3, b_3, a_7, b_7, a_11, b_11, a_15, b_15, a_19, b_19, a_23, b_23, a_27, b_27, a_31, b_31);



	add(obj, VNN, NUM_DUTS, a_dpohv1, b_dpohv1, a_dpohv2, b_dpohv2, a_dpohv3, b_dpohv3, a_dpohv4, b_dpohv4, a_dpohv5, b_dpohv5, a_dpohv6, b_dpohv6, a_dpohv7, b_dpohv7, a_dpohv8, b_dpohv8);
	add(obj, VPP, NUM_DUTS, a_hv1, b_hv1, a_hv2, b_hv2, a_hv3, b_hv3, a_hv4, b_hv4, a_hv5, b_hv5, a_hv6, b_hv6, a_hv7, b_hv7, a_hv8, b_hv8);
	add(obj, TST, NUM_DUTS, a_dps1a, b_dps1a, a_dps1b, b_dps1b, a_dps2a, b_dps2a, a_dps2b, b_dps2b, a_dps3a, b_dps3a, a_dps3b, b_dps3b, a_dps4a, b_dps4a, a_dps4b, b_dps4b);
	add(obj, VCC, NUM_DUTS, a_dpo1, b_dpo1, a_dpo2, b_dpo2, a_dpo3, b_dpo3, a_dpo4, b_dpo4, a_dpo5, b_dpo5, a_dpo6, b_dpo6, a_dpo7, b_dpo7, a_dpo8, b_dpo8);
}

CString get_dut_pin_number(DutPin * dpin) {
	return dut_pin_info[dpin];
}