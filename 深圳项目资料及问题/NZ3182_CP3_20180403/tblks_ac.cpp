#include "tester.h"

// ******************************
// *****  Test Blocks file  *****
// ******************************
// 
//stuff scr1;


extern BOOL test_result;
//BOOL test_result;
//extern Elapsed test_time;

extern IntArray r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15;	// To store local test results
extern IntArray r16, r17, r18, r19, r20, r21, r22, r23, r24, r25;	// To store local test results
extern  void tp_fdatalog(PinList*);

//***********VDDLDO Trim**************************
double vddldo_meas[DUTNUM][32] = { 0 };
double delta_vddldo[DUTNUM][32] = { 0 };
double delta_vddldo_min[DUTNUM] = { 0 };
double vddldo_post[DUTNUM] = { 0 };
double vddldo_1p8_meas[DUTNUM][32] = { 0 };
double delta_vddldo_1p8[DUTNUM][32] = { 0 };
double delta_vddldo_1p8_min[DUTNUM] = { 0 };
double vddldo_1p8_post[DUTNUM] = { 0 };
//unsigned int vddldo_trim_value_tmp = 0;
//unsigned int vddldo_1p8_trim_value_tmp =  0 ;
unsigned int vddldo_trim_value[DUTNUM] = { 0 };
unsigned int vddldo_1p8_trim_value[DUTNUM] = { 0 };
//**********Vref Trim*******************************
unsigned int vref_trim_value[DUTNUM] = { 0 };
double vref_post[DUTNUM] = { 0 };
double vref_meas[DUTNUM][32] = { 0 };

//***********OSC2M_Trim************************************
double osc2m_meas[DUTNUM][32] = { 0 };
double delta_osc2m[DUTNUM][32] = { 0 };
double delta_osc2m_min[DUTNUM] = { 0 };
double osc2m_post[DUTNUM] = { 0 };
//unsigned int osc2m_trim_value_tmp =  0 ;
unsigned int osc2m_trim_value[DUTNUM] = { 0 };

//ADC  VTS 
int average_vts_adc_out[DUTNUM] = { 0 };

//IP TRIM data array
unsigned int LDO2D2_data[DUTNUM][5] = { 0 };
unsigned int LDO1D8_data[DUTNUM][5] = { 0 };
unsigned int VERF_data[DUTNUM][4] = { 0 };
unsigned int OSC_data[DUTNUM][4] = { 0 };
unsigned int VTS_data[DUTNUM][10] = { 0 };
unsigned int CRC_data[DUTNUM][8] = { 0 };
unsigned int CRC_value[DUTNUM] = { 0 };

int Con_Bin_Dec(unsigned int ll[9])    // crc data conveter
{
	int i, j = 0;
	for (i = 7; i >= 0; i--)
	{
		if (ll[7 - i] == 1)
			j += pow(2.0, i);    
	}
	return j;
}

void GetVDDLDOValue(int CodeNumber )
{
	double dut_Number[DUTNUM];
	CArray<double, double> meas_results;
	SoftwareOnlyActiveDutIterator lec_loop1;
//	CArray<double, double> meas_results;
	while (lec_loop1.More())//loop,then save trim value
	{
		DutNum dut_num = active_dut_get();
		//DpoHv_meas(meas_results);
		Pin_meas(meas_results);
		dut_Number[dut_num] = meas_results[0];
		vddldo_meas[dut_num][CodeNumber] = dut_Number[dut_num];
		output("VDDLDO Trim dut %d Code %2d: %6.3f V", dut_num+1, CodeNumber, vddldo_meas[dut_num][CodeNumber] * 0.001*0.001);
		//output("\n");
		
	}
	output("\n");

	//output("VDDLDO Trim Code %2d: %6.3f V",  CodeNumber, vddldo_meas[CodeNumber] * 0.001*0.001);
}

void GetVrefValue(int CodeNumber)
{
	double dut_Number[DUTNUM];
	CArray<double, double> meas_results;
	SoftwareOnlyActiveDutIterator lec_loop1;
	while (lec_loop1.More())//loop,then save trim value
	{
		DutNum dut_num = active_dut_get();
		Pin_meas(meas_results);
		dut_Number[dut_num] = meas_results[0];
		vref_meas[dut_num][CodeNumber] = dut_Number[dut_num];
		output("Vref Trim dut %d Code %2d: %6.3f V", dut_num + 1, CodeNumber, vref_meas[dut_num][CodeNumber] * 0.001*0.001);
	}
	output("\n");
}

void GetOSC2MfValue(int CodeNumber)
{
	double dut_Number[DUTNUM];
	CArray<double, double> meas_results;
	SoftwareOnlyActiveDutIterator lec_loop1;
	while (lec_loop1.More())//loop,then save trim value
	{
		DutNum dut_num = active_dut_get();
		pin_frequency_meas_get(meas_results);
		//output("OSC2M Trim Code %2d: %6.6f M", CodeNumber, meas_results[0] / 1000000);
		dut_Number[dut_num] = meas_results[0];
		osc2m_meas[dut_num][CodeNumber] = dut_Number[dut_num];

		output("OSC2M Trim dut %d Code %2d:  %6.6f M", dut_num + 1, CodeNumber, osc2m_meas[dut_num][CodeNumber] / 1000000);
	}
	output("\n");
}

//********Get the best trim code***********************************
void GetTrimCode()
{
	double dut_Number[DUTNUM] = {0};
	//CArray<double, double> meas_results;
	SoftwareOnlyActiveDutIterator lec_loop2;
	CArray<double, double> meas_results;
	while (lec_loop2.More())//loop,then save trim value
	{
		DutNum dut_num = active_dut_get();
	
		for (int i = 1; i < 18; i++)
		{
			delta_vddldo[dut_num][i] = fabs(2200000 - vddldo_meas[dut_num][i]);
			delta_vddldo_1p8[dut_num][i] = fabs(1800000 - vddldo_meas[dut_num][i]);
			if (i == 1)
			{
				delta_vddldo_min[dut_num] = delta_vddldo[dut_num][i];
				vddldo_trim_value[dut_num] = i;
				vddldo_post[dut_num] = vddldo_meas[dut_num][i];
				delta_vddldo_1p8_min[dut_num] = delta_vddldo_1p8[dut_num][i];
				vddldo_1p8_trim_value[dut_num] = i;
				vddldo_1p8_post[dut_num] = vddldo_meas[dut_num][i];

			}

			else if (i > 1)
			{
				if (delta_vddldo[dut_num][i] < delta_vddldo_min[dut_num])
				{
					delta_vddldo_min[dut_num] = delta_vddldo[dut_num][i];
					vddldo_trim_value[dut_num] = i;
					vddldo_post[dut_num] = vddldo_meas[dut_num][i];

				}
				if (delta_vddldo_1p8[dut_num][i] < delta_vddldo_1p8_min[dut_num])
				{
					delta_vddldo_1p8_min[dut_num] = delta_vddldo_1p8[dut_num][i];
					vddldo_1p8_trim_value[dut_num] = i;
					vddldo_1p8_post[dut_num] = vddldo_meas[dut_num][i];

				}
			}
		}

		output("vddldo trim dut %d code is:  %2d,  Trim value is: %6.3f V ", dut_num+1, vddldo_trim_value[dut_num], vddldo_post[dut_num] * 0.001*0.001);
		//output("\n");
	}
	output("\n");
	//output("vddldo trim code is:  %2d,  Trim value is: %6.3f V ", vddldo_trim_value, vddldo_post[dut_num] * 0.001*0.001);
	//output("vddldo_1p8 trim code is:  %2d,  Trim value is: %6.3f V ", vddldo_1p8_trim_value, vddldo_1p8_post*0.001*0.001);
}

//************************EBM********************************************************
void LDOVDDTrimDataToEBM()
{
	ebm_config_set(t_ebm_data_mode, pl_GPIO6_PAD);
	ebm_address_reg_set(t_ebm_start_addr, 0x0);
	ebm_clear();
/*	ebm_address_reg_set(t_ebm_addr_2, 0x17);                                                                                                       
	ebm_address_reg_set(t_ebm_addr_3, 0x33);*/                                                                                                       
	DWordArray inputcode;
	double dut_Number[DUTNUM] = {0};
	//CArray<double, double> meas_results;
	SoftwareOnlyActiveDutIterator lec_loop3;
	//CArray<double, double> meas_results;
	while (lec_loop3.More())//loop,then save trim value
	{
		DutNum dut_num = active_dut_get();
		//output("DutNum: dut%d : vddldo_trim_value is %d. \n", dut_num + 1, vddldo_trim_value[dut_num]);
		if (vddldo_trim_value[dut_num] % 16 % 8 % 4 % 2 / 1)
		{
			inputcode.Add(0x01);
			//output("inputcode bit0: %d. \n", 1);
		}
		else
		{
			inputcode.Add(0x00);
			//output("inputcode bit0: %d. \n", 0);
		}
		if (vddldo_trim_value[dut_num] % 16 % 8 % 4 / 2)
		{
			inputcode.Add(0x01);
			//output("inputcode bit1: %d. \n", 1);
		}
		else
		{
			inputcode.Add(0x00);
			//output("inputcode bit1: %d. \n", 0);
		}
		if (vddldo_trim_value[dut_num] % 16 % 8 / 4)
		{
			inputcode.Add(0x01);
			//output("inputcode bit2: %d. \n", 1);
		}
		else
		{
			inputcode.Add(0x00);
			//output("inputcode bit2: %d. \n", 0);
		}
		if (vddldo_trim_value[dut_num] % 16 / 8)
		{
			inputcode.Add(0x01);
			//output("inputcode bit3: %d. \n", 1);
		}
		else
		{
			inputcode.Add(0x00);
			//output("inputcode bit3: %d. \n", 0);
		}
		if (vddldo_trim_value[dut_num] / 16)
		{
			inputcode.Add(0x01);
			//output("inputcode bit4: %d. \n", 1);
		}
		else
		{
			inputcode.Add(0x00);
			//output("inputcode bit4: %d. \n", 0);
		}


		ebm_write(dut_num, pl_GPIO6_PAD, 0x0, 5, inputcode);
		inputcode.RemoveAll();
	}

}

void LDOVDD1p8TrimDataToEBM()
{
	ebm_config_set(t_ebm_data_mode, pl_GPIO6_PAD);
	ebm_address_reg_set(t_ebm_start_addr, 0x0);
	ebm_clear();
	/*	ebm_address_reg_set(t_ebm_addr_2, 0x17);
	ebm_address_reg_set(t_ebm_addr_3, 0x33);*/
	DWordArray inputcode;
	double dut_Number[DUTNUM] = { 0 };
	//CArray<double, double> meas_results;
	SoftwareOnlyActiveDutIterator lec_loop3;
	//CArray<double, double> meas_results;
	while (lec_loop3.More())//loop,then save trim value
	{
		DutNum dut_num = active_dut_get();
		//output("DutNum: dut%d : vddldo_trim_value is %d. \n", dut_num + 1, vddldo_trim_value[dut_num]);
		if (vddldo_1p8_trim_value[dut_num] % 16 % 8 % 4 % 2 / 1)
		{
			inputcode.Add(0x01);
			//output("inputcode bit0: %d. \n", 1);
		}
		else
		{
			inputcode.Add(0x00);
			//output("inputcode bit0: %d. \n", 0);
		}
		if (vddldo_1p8_trim_value[dut_num] % 16 % 8 % 4 / 2)
		{
			inputcode.Add(0x01);
			//output("inputcode bit1: %d. \n", 1);
		}
		else
		{
			inputcode.Add(0x00);
			//output("inputcode bit1: %d. \n", 0);
		}
		if (vddldo_1p8_trim_value[dut_num] % 16 % 8 / 4)
		{
			inputcode.Add(0x01);
			//output("inputcode bit2: %d. \n", 1);
		}
		else
		{
			inputcode.Add(0x00);
			//output("inputcode bit2: %d. \n", 0);
		}
		if (vddldo_1p8_trim_value[dut_num] % 16 / 8)
		{
			inputcode.Add(0x01);
			//output("inputcode bit3: %d. \n", 1);
		}
		else
		{
			inputcode.Add(0x00);
			//output("inputcode bit3: %d. \n", 0);
		}
		if (vddldo_1p8_trim_value[dut_num] / 16)
		{
			inputcode.Add(0x01);
			//output("inputcode bit4: %d. \n", 1);
		}
		else
		{
			inputcode.Add(0x00);
			//output("inputcode bit4: %d. \n", 0);
		}


		ebm_write(dut_num, pl_GPIO6_PAD, 0x0, 5, inputcode);
		inputcode.RemoveAll();
	}

}

void VrefTrimDataToEBM()
{
	ebm_config_set(t_ebm_data_mode, pl_GPIO6_PAD);
	ebm_address_reg_set(t_ebm_start_addr, 0x0);
	ebm_clear();
	/*	ebm_address_reg_set(t_ebm_addr_2, 0x17);
	ebm_address_reg_set(t_ebm_addr_3, 0x33);*/
	DWordArray inputcode;
	double dut_Number[DUTNUM] = { 0 };
	//CArray<double, double> meas_results;
	SoftwareOnlyActiveDutIterator lec_loop3;
	//CArray<double, double> meas_results;
	while (lec_loop3.More())//loop,then save trim value
	{
		DutNum dut_num = active_dut_get();
		//output("DutNum: dut%d : vddldo_trim_value is %d. \n", dut_num + 1, vddldo_trim_value[dut_num]);
		if (vref_trim_value[dut_num]  % 8 % 4 % 2 / 1)
		{
			inputcode.Add(0x01);
			//output("inputcode bit0: %d. \n", 1);
		}
		else
		{
			inputcode.Add(0x00);
			//output("inputcode bit0: %d. \n", 0);
		}
		if (vref_trim_value[dut_num]  % 8 % 4 / 2)
		{
			inputcode.Add(0x01);
			//output("inputcode bit1: %d. \n", 1);
		}
		else
		{
			inputcode.Add(0x00);
			//output("inputcode bit1: %d. \n", 0);
		}
		if (vref_trim_value[dut_num] % 8 / 4)
		{
			inputcode.Add(0x01);
			//output("inputcode bit2: %d. \n", 1);
		}
		else
		{
			inputcode.Add(0x00);
			//output("inputcode bit2: %d. \n", 0);
		}
		if (vref_trim_value[dut_num] / 8)
		{
			inputcode.Add(0x01);
			//output("inputcode bit3: %d. \n", 1);
		}
		else
		{
			inputcode.Add(0x00);
			//output("inputcode bit3: %d. \n", 0);
		}

		ebm_write(dut_num, pl_GPIO6_PAD, 0x0, 4, inputcode);
		inputcode.RemoveAll();
	}

}

void OSCTrimDataToEBM()
{
	ebm_config_set(t_ebm_data_mode, pl_GPIO6_PAD);
	ebm_address_reg_set(t_ebm_start_addr, 0x0);
	ebm_clear();
	/*	ebm_address_reg_set(t_ebm_addr_2, 0x17);
	ebm_address_reg_set(t_ebm_addr_3, 0x33);*/
	DWordArray inputcode;
	double dut_Number[DUTNUM] = { 0 };
	//CArray<double, double> meas_results;
	SoftwareOnlyActiveDutIterator lec_loop3;
	//CArray<double, double> meas_results;
	while (lec_loop3.More())//loop,then save trim value
	{
		DutNum dut_num = active_dut_get();
		//output("DutNum: dut%d : vddldo_trim_value is %d. \n", dut_num + 1, vddldo_trim_value[dut_num]);
		if (osc2m_trim_value[dut_num] % 8 % 4 % 2 / 1)
		{
			inputcode.Add(0x01);
			//output("inputcode bit0: %d. \n", 1);
		}
		else
		{
			inputcode.Add(0x00);
			//output("inputcode bit0: %d. \n", 0);
		}
		if (osc2m_trim_value[dut_num] % 8 % 4 / 2)
		{
			inputcode.Add(0x01);
			//output("inputcode bit1: %d. \n", 1);
		}
		else
		{
			inputcode.Add(0x00);
			//output("inputcode bit1: %d. \n", 0);
		}
		if (osc2m_trim_value[dut_num] % 8 / 4)
		{
			inputcode.Add(0x01);
			//output("inputcode bit2: %d. \n", 1);
		}
		else
		{
			inputcode.Add(0x00);
			//output("inputcode bit2: %d. \n", 0);
		}
		if (osc2m_trim_value[dut_num] / 8)
		{
			inputcode.Add(0x01);
			//output("inputcode bit3: %d. \n", 1);
		}
		else
		{
			inputcode.Add(0x00);
			//output("inputcode bit3: %d. \n", 0);
		}

		ebm_write(dut_num, pl_GPIO6_PAD, 0x0, 4, inputcode);
		inputcode.RemoveAll();
	}

}

void Get_IP_TRIM_DATA()
{

	unsigned int a[DUTNUM][8] = { 0 };
	unsigned int b[DUTNUM][8] = { 0 };
	unsigned int c[DUTNUM][8] = { 0 };
	unsigned int d[DUTNUM][8] = { 0 };

	unsigned int aa[DUTNUM] = { 0 };
	unsigned int bb[DUTNUM] = { 0 };
	unsigned int cc[DUTNUM] = { 0 };
	unsigned int dd[DUTNUM] = { 0 };


	//DWordArray InputData;
	SoftwareOnlyActiveDutIterator TRIMDATA_loop;
	while (TRIMDATA_loop.More())//loop,then save trim value
	{
		DutNum dut_num = active_dut_get();

		//VDDLDO 2.2 V
		if (vddldo_trim_value[dut_num] % 16 % 8 % 4 % 2 / 1)
		{
			//inputcode.Add(0x01);
			//output("inputcode bit0: %d. \n", 1);
			LDO2D2_data[dut_num][0] = 1;
		}
		else
		{
			//inputcode.Add(0x00);
			//output("inputcode bit0: %d. \n", 0);
			LDO2D2_data[dut_num][0] = 0;
		}
		if (vddldo_trim_value[dut_num] % 16 % 8 % 4 / 2)
		{
			//inputcode.Add(0x01);
			//output("inputcode bit1: %d. \n", 1);
			LDO2D2_data[dut_num][1] = 1;
		}
		else
		{
			//inputcode.Add(0x00);
			//output("inputcode bit1: %d. \n", 0);
			LDO2D2_data[dut_num][1] = 0;
		}
		if (vddldo_trim_value[dut_num] % 16 % 8 / 4)
		{
			//inputcode.Add(0x01);
			//output("inputcode bit2: %d. \n", 1);
			LDO2D2_data[dut_num][2] = 1;
		}
		else
		{
			//inputcode.Add(0x00);
			//output("inputcode bit2: %d. \n", 0);
			LDO2D2_data[dut_num][2] = 0;
		}
		if (vddldo_trim_value[dut_num] % 16 / 8)
		{
			//inputcode.Add(0x01);
			//output("inputcode bit3: %d. \n", 1);
			LDO2D2_data[dut_num][3] = 1;
		}
		else
		{
			//inputcode.Add(0x00);
			//output("inputcode bit3: %d. \n", 0);
			LDO2D2_data[dut_num][3] = 0;
		}
		if (vddldo_trim_value[dut_num] / 16)
		{
			//inputcode.Add(0x01);
			//output("inputcode bit4: %d. \n", 1);
			LDO2D2_data[dut_num][4] = 1;
		}
		else
		{
			//inputcode.Add(0x00);
			//output("inputcode bit4: %d. \n", 0);
			LDO2D2_data[dut_num][4] = 0;
		}

		//VDD LDO 1.8 V
		if (vddldo_1p8_trim_value[dut_num] % 16 % 8 % 4 % 2 / 1)
		{
			//inputcode.Add(0x01);
			//output("inputcode bit0: %d. \n", 1);
			LDO1D8_data[dut_num][0] = 1;
		}
		else
		{
			//inputcode.Add(0x00);
			//output("inputcode bit0: %d. \n", 0);
			LDO1D8_data[dut_num][0] = 0;
		}
		if (vddldo_1p8_trim_value[dut_num] % 16 % 8 % 4 / 2)
		{
			//inputcode.Add(0x01);
			//output("inputcode bit1: %d. \n", 1);
			LDO1D8_data[dut_num][1] = 1;
		}
		else
		{
			//inputcode.Add(0x00);
			//output("inputcode bit1: %d. \n", 0);
			LDO1D8_data[dut_num][1] = 0;
		}
		if (vddldo_1p8_trim_value[dut_num] % 16 % 8 / 4)
		{
			//inputcode.Add(0x01);
			//output("inputcode bit2: %d. \n", 1);
			LDO1D8_data[dut_num][2] = 1;
		}
		else
		{
			//inputcode.Add(0x00);
			//output("inputcode bit2: %d. \n", 0);
			LDO1D8_data[dut_num][2] = 0;
		}
		if (vddldo_1p8_trim_value[dut_num] % 16 / 8)
		{
			//inputcode.Add(0x01);
			//output("inputcode bit3: %d. \n", 1);
			LDO1D8_data[dut_num][3] = 1;
		}
		else
		{
			//inputcode.Add(0x00);
			//output("inputcode bit3: %d. \n", 0);
			LDO1D8_data[dut_num][3] = 0;
		}
		if (vddldo_1p8_trim_value[dut_num] / 16)
		{
			//inputcode.Add(0x01);
			//output("inputcode bit4: %d. \n", 1);
			LDO1D8_data[dut_num][4] = 1;
		}
		else
		{
			//inputcode.Add(0x00);
			//output("inputcode bit4: %d. \n", 0);
			LDO1D8_data[dut_num][4] = 0;
		}

		//Vref 0.9 V
		if (vref_trim_value[dut_num] % 8 % 4 % 2 / 1)
		{
			VERF_data[dut_num][0] = 1;
		}
		else
		{
			VERF_data[dut_num][0] = 0;
		}
		if (vref_trim_value[dut_num] % 8 % 4 / 2)
		{
			VERF_data[dut_num][1] = 1;
		}
		else
		{
			VERF_data[dut_num][1] = 0;
		}
		if (vref_trim_value[dut_num] % 8 / 4)
		{
			VERF_data[dut_num][2] = 1;
		}
		else
		{
			VERF_data[dut_num][2] = 0;
		}
		if (vref_trim_value[dut_num] / 8)
		{
			VERF_data[dut_num][3] = 1;
		}
		else
		{
			VERF_data[dut_num][3] = 0;
		}

		//osc trim 2M
		if (osc2m_trim_value[dut_num] % 8 % 4 % 2 / 1)
		{
			OSC_data[dut_num][0] = 1;
		}
		else
		{
			OSC_data[dut_num][0] = 0;
		}

		if (osc2m_trim_value[dut_num] % 8 % 4 / 2)
		{
			OSC_data[dut_num][1] = 1;
		}
		else
		{
			OSC_data[dut_num][1] = 0;
		}

		if (osc2m_trim_value[dut_num] % 8 / 4)
		{
			OSC_data[dut_num][2] = 1;
		}
		else
		{
			OSC_data[dut_num][2] = 0;
		}

		if (osc2m_trim_value[dut_num] / 8)
		{
			OSC_data[dut_num][3] = 1;
		}
		else
		{
			OSC_data[dut_num][3] = 0;
		}

		//Vts 0.84 v---need modify spec
		if (average_vts_adc_out[dut_num] % 1024 % 512 % 128 % 64 % 32 % 16 % 8 % 4 % 2 / 1)
		{
			VTS_data[dut_num][0] = 1;
		}
		else
		{
			VTS_data[dut_num][0] = 0;
		}

		if (average_vts_adc_out[dut_num] % 1024 % 512 % 128 % 64 % 32 % 16 % 8 % 4 / 2 )
		{
			VTS_data[dut_num][1] = 1;
		}
		else
		{
			VTS_data[dut_num][1] = 0;
		}

		if (average_vts_adc_out[dut_num] % 1024 % 512 % 128 % 64 % 32 % 16 % 8 / 4)
		{
			VTS_data[dut_num][2] = 1;
		}
		else
		{
			VTS_data[dut_num][2] = 0;
		}

		if (average_vts_adc_out[dut_num] % 1024 % 512 % 128 % 64 % 32 % 16 / 8 )
		{
			VTS_data[dut_num][3] = 1;
		}
		else
		{
			VTS_data[dut_num][3] = 0;
		}

		if (average_vts_adc_out[dut_num] % 1024 % 512 % 128 % 64 % 32 / 16 )
		{
			VTS_data[dut_num][4] = 1;
		}
		else
		{
			VTS_data[dut_num][4] = 0;
		}

		if (average_vts_adc_out[dut_num] % 1024 % 512 % 128 % 64 / 32 )
		{
			VTS_data[dut_num][5] = 1;
		}
		else
		{
			VTS_data[dut_num][5] = 0;
		}

		if (average_vts_adc_out[dut_num] % 1024 % 512 % 128 / 64 )
		{
			VTS_data[dut_num][6] = 1;
		}
		else
		{
			VTS_data[dut_num][6] = 0;
		}

		if (average_vts_adc_out[dut_num] % 1024 % 512 / 128)
		{
			VTS_data[dut_num][7] = 1;
		}
		else
		{
			VTS_data[dut_num][7] = 0;
		}

		if (average_vts_adc_out[dut_num] % 1024 / 512)
		{
			VTS_data[dut_num][8] = 1;
		}
		else
		{
			VTS_data[dut_num][8] = 0;
		}

		if (average_vts_adc_out[dut_num] / 1024 )
		{
			VTS_data[dut_num][9] = 1;
		}
		else
		{
			VTS_data[dut_num][9] = 0;
		}

		//unsigned int LDO2D2_data[DUTNUM][5] = { 0 };
		//unsigned int LDO1D8_data[DUTNUM][5] = { 0 };
		//unsigned int VERF_data[DUTNUM][4] = { 0 };
		//unsigned int OSC_data[DUTNUM][4] = { 0 };
		//unsigned int VTS_data[DUTNUM][10] = { 0 };
		//unsigned int CRC_data[DUTNUM][8] = { 0 };
		a[dut_num][0] = 1;	a[dut_num][1] = 0;	a[dut_num][2] = 0;	a[dut_num][3] = 0;
		b[dut_num][0] = 1;	b[dut_num][1] = 1;	b[dut_num][2] = 1;	b[dut_num][3] = LDO2D2_data[dut_num][0];
		c[dut_num][0] = 1;	c[dut_num][1] = 1;	c[dut_num][2] = 1;	c[dut_num][3] = 1;
		d[dut_num][0] = 1;	d[dut_num][1] = 1;	d[dut_num][2] = 1;	d[dut_num][3] = LDO1D8_data[dut_num][0];

		a[dut_num][4] = VERF_data[dut_num][0];		a[dut_num][5] = VERF_data[dut_num][1];
		b[dut_num][4] = LDO2D2_data[dut_num][1];	b[dut_num][5] = LDO2D2_data[dut_num][2];
		c[dut_num][4] = OSC_data[dut_num][0];		c[dut_num][5] = OSC_data[dut_num][1];
		d[dut_num][4] = LDO1D8_data[dut_num][1];	d[dut_num][5] = LDO1D8_data[dut_num][2];

		a[dut_num][6] = VERF_data[dut_num][2];		a[dut_num][7] = VERF_data[dut_num][3];
		b[dut_num][6] = LDO2D2_data[dut_num][3];	b[dut_num][7] = LDO2D2_data[dut_num][4];
		c[dut_num][6] = OSC_data[dut_num][2];		c[dut_num][7] = OSC_data[dut_num][3];
		d[dut_num][6] = LDO1D8_data[dut_num][3];	d[dut_num][7] = LDO1D8_data[dut_num][4];

		aa[dut_num] = Con_Bin_Dec(a[dut_num]);
		bb[dut_num] = Con_Bin_Dec(b[dut_num]);
		cc[dut_num] = Con_Bin_Dec(c[dut_num]);
		dd[dut_num] = Con_Bin_Dec(d[dut_num]);

		CRC_value[dut_num] = aa[dut_num] ^ bb[dut_num] ^ cc[dut_num] ^ dd[dut_num] ^ 249 ^ 90;

		// GET CRC DATA
		if (CRC_value[dut_num]  % 128 % 64 % 32 % 16 % 8 % 4 % 2 / 1)
		{
			CRC_data[dut_num][0] = 1;
		}
		else
		{
			CRC_data[dut_num][0] = 0;
		}

		if (CRC_value[dut_num] % 128 % 64 % 32 % 16 % 8 % 4 / 2)
		{
			CRC_data[dut_num][1] = 1;
		}
		else
		{
			CRC_data[dut_num][1] = 0;
		}

		if (CRC_value[dut_num] % 128 % 64 % 32 % 16 % 8 / 4 )
		{
			CRC_data[dut_num][2] = 1;
		}
		else
		{
			CRC_data[dut_num][2] = 0;
		}

		if (CRC_value[dut_num] % 128 % 64 % 32 % 16 / 8 )
		{
			CRC_data[dut_num][3] = 1;
		}
		else
		{
			CRC_data[dut_num][3] = 0;
		}

		if (CRC_value[dut_num] % 128 % 64 % 32 / 16)
		{
			CRC_data[dut_num][4] = 1;
		}
		else
		{
			CRC_data[dut_num][4] = 0;
		}

		if (CRC_value[dut_num] % 128 % 64 / 32 )
		{
			CRC_data[dut_num][5] = 1;
		}
		else
		{
			CRC_data[dut_num][5] = 0;
		}

		if (CRC_value[dut_num] % 128 / 64 )
		{
			CRC_data[dut_num][6] = 1;
		}
		else
		{
			CRC_data[dut_num][6] = 0;
		}

		if (CRC_value[dut_num] /128 )
		{
			CRC_data[dut_num][7] = 1;
		}
		else
		{
			CRC_data[dut_num][7] = 0;
		}

	}

}

void IP_TRIM_WRITE_EBM()
{
	//unsigned int LDO2D2_data[DUTNUM][5] = { 0 };
	//unsigned int LDO1D8_data[DUTNUM][5] = { 0 };
	//unsigned int VERF_data[DUTNUM][4] = { 0 };
	//unsigned int OSC_data[DUTNUM][4] = { 0 };
	//unsigned int VTS_data[DUTNUM][10] = { 0 };
	//unsigned int CRC_data[DUTNUM][8] = { 0 };
	ebm_config_set(t_ebm_data_mode, pl_GPIO6_PAD);
	ebm_address_reg_set(t_ebm_start_addr, 0x0);
	ebm_clear();

	DWordArray inputcode_all;
	SoftwareOnlyActiveDutIterator lec_loop;
	
	while (lec_loop.More())//loop,then save trim value
	{
		DutNum dut_num = active_dut_get();
		//ldo 2.2 v
		for (int i = 0; i < 5; i++)
		{
			if (LDO2D2_data[dut_num][i]==1)
			{
				inputcode_all.Add(0x01);
			}
			else
			{
				inputcode_all.Add(0x00);
			}
		}
		
		//osc 2M
		for (int i = 0; i < 4; i++)
		{
			if (OSC_data[dut_num][i] == 1)
			{
				inputcode_all.Add(0x01);
			}
			else
			{
				inputcode_all.Add(0x00);
			}
		}

		//CRC DATA
		for (int i = 0; i < 8; i++)
		{
			if (CRC_data[dut_num][i] == 1)
			{
				inputcode_all.Add(0x01);
			}
			else
			{
				inputcode_all.Add(0x00);
			}
		}

		//VTS DATA
		for (int i = 0; i < 10; i++)
		{
			if (VTS_data[dut_num][i] == 1)
			{
				inputcode_all.Add(0x01);
			}
			else
			{
				inputcode_all.Add(0x00);
			}
		}

		//LDO 1.8 V
		for (int i = 0; i < 5; i++)
		{
			if (LDO1D8_data[dut_num][i] == 1)
			{
				inputcode_all.Add(0x01);
			}
			else
			{
				inputcode_all.Add(0x00);
			}
		}
		ebm_write(dut_num, pl_GPIO6_PAD, 0x0, 32, inputcode_all);
		inputcode_all.RemoveAll();
	}
}


TEST_BLOCK(tb_Enter_Eot)
{
	//partime(1 MS);
	tb_header();
//	Delay(50 MS);
	//pin_connect(pl_IOPINS);
	ts_std1();
	func_lvl();	
	ptu_connect(pl_CMS_PAD);
	ptu_connect(pl_PWRWAKE_PAD);
	ptu_vpar_force_set(0 V, pl_CMS_PAD);
	ptu_vpar_force_set(3.1 V, pl_PWRWAKE_PAD);
	//setpin(pl_CMS_PAD, VIL);
	//setpin(pl_VDD_PAD, VIH);
	//setpin(pl_PWRWAKE_PAD, VIH);
	//Delay(10 MS);
	funtest(EOT_INIT_CLK, finish);	
	funtest(CmdTest, finish);
//	funtest(Off_Margin_Read_Array_FF2, finish);
	tp_fdatalog(pl_PATTERN_PIN);	
	return tb_end();
}

TEST_BLOCK(tb_Off_Margin_Read_Array_FF_Std)
{
	//partime(10 MS);
	tb_header();
	//ptu_vpar_force_set(0 V, pl_CMS_PAD);
	//ptu_vpar_force_set(0 V, pl_PWRWAKE_PAD);
	//ptu_disconnect(pl_CMS_PAD);
	//ptu_disconnect(pl_PWRWAKE_PAD);

	//ts_std();
	//func_lvl();
	//setpin(pl_CMS_PAD, VIL);
	//setpin(pl_PWRWAKE_PAD, VIH);
	//Delay(10 MS);
	funtest(POWER_CHANGE, finish);
	funtest(CP_CLK_SEL, finish);
	func_lvl();
	ptu_vpar_force_set(0 V, pl_CMS_PAD);
	ptu_vpar_force_set(3.1 V, pl_PWRWAKE_PAD);
	Delay(10 MS);

	funtest(Off_Margin_Read_Array_FF, finish);	
//	funtest(Off_Margin_Read_Array_FF2, finish);
	tp_fdatalog(pl_PATTERN_PIN);
	power_down();
	return tb_end();
}

TEST_BLOCK(tb_VDDLDO_Trim)
{
	tb_header();
	output("\n\nTestBlock:tb_VDDLDO_Trim");
	pin_connect(pl_IOPINS);
	ptu_connect(pl_CMS_PAD);
//	ptu_connect(pl_VDD_PAD);
	ptu_connect(pl_PWRWAKE_PAD);

	ts_Trim();
	Trim_lvl();
	//setpin(pl_CMS_PAD, VIL);
	//setpin(pl_VDD_PAD, VIH);
	ptu_vpar_force_set(0 V, pl_CMS_PAD);
//	ptu_vpar_force_set(3.3 V, pl_VDD_PAD);
	ptu_vpar_force_set(3.1 V, pl_PWRWAKE_PAD);
	
	ipar_force(0 UA);
	vpar_high(5 V);
	vpar_low(0 V);
	vclamp(7 V, -2 V);
	measure(TRUE);
	Delay(3 MS);

	funtest(EOT_INIT_CLK, finish);
	funtest(CP_CLK_SEL, finish);
	funtest(VDDLDO_OUT, finish);
	funtest(VDDLDO_Default, finish);
	Delay(10 MS);

	//start_pattern(VDDLDO_Code1);
	//Delay(120 MS);
	//partest(pass_nivl, pl_ADC_PAD);
	//GetVddloValue(1);
	//stop_pattern();


	funtest(VDDLDO_Code1, finish);
	Delay(10 MS);	
	partest(pass_nivl, pl_ADC_PAD);
	GetVDDLDOValue(1);

	funtest(VDDLDO_Code2, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	GetVDDLDOValue(2);

	funtest(VDDLDO_Code3, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	GetVDDLDOValue(3);

	funtest(VDDLDO_Code4, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	GetVDDLDOValue(4);

	funtest(VDDLDO_Code5, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	GetVDDLDOValue(5);

	funtest(VDDLDO_Code6, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	GetVDDLDOValue(6);

	funtest(VDDLDO_Code7, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	GetVDDLDOValue(7);

	funtest(VDDLDO_Code8, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	GetVDDLDOValue(8);

	funtest(VDDLDO_Code9, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	GetVDDLDOValue(9);

	funtest(VDDLDO_Code10, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	GetVDDLDOValue(10);

	funtest(VDDLDO_Code11, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	GetVDDLDOValue(11);

	funtest(VDDLDO_Code12, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	GetVDDLDOValue(12);

	funtest(VDDLDO_Code13, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	GetVDDLDOValue(13);

	funtest(VDDLDO_Code14, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	GetVDDLDOValue(14);

	funtest(VDDLDO_Code15, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	GetVDDLDOValue(15);

	funtest(VDDLDO_Code16, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	GetVDDLDOValue(16);

	funtest(VDDLDO_Code17, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	GetVDDLDOValue(17);
	GetTrimCode();

	//SoftwareOnlyActiveDutIterator lec_loop5;
	//while (lec_loop5.More())//loop,then save trim value                                                                                               
	//{
	//	DutNum dut = active_dut_get();
	//	if (vddldo_post[dut] > 2090000 && vddldo_post[dut] < 2310000)
	//	{
	//		result_set(dut, 1);
	//	}
	//	else result_set(dut, 0);
	//}

	LDOVDDTrimDataToEBM(); 
	Delay(3 MS);
//	ebm_config_set(t_ebm_data_mode, pl_GPIO6_PAD);
//	ebm_address_pointer_reset();
//	Delay(1 MS);
	funtest(VDDLDO_2D2_Trim, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);

	CArray<double, double> meas_results2;
	double dut_Number21[DUTNUM] = {0};
	SoftwareOnlyActiveDutIterator lec_loop21;
	//	CArray<double, double> meas_results;
	while (lec_loop21.More())//loop,then save trim value
	{
		DutNum dut_num2 = active_dut_get();
		//DpoHv_meas(meas_results);
		Pin_meas(meas_results2);
		dut_Number21[dut_num2] = meas_results2[0];
		
		output("VDDLDO Trim dut %d : %6.3f V", dut_num2 + 1,  dut_Number21[dut_num2] * 0.001*0.001);
		//output("\n");
		//	DutNum dut = active_dut_get();
		if (dut_Number21[dut_num2] > 2090000 && dut_Number21[dut_num2] < 2310000)
			{
				result_set(dut_num2, 1);
			}
		else result_set(dut_num2, 0);

	}
	output("\n");
	


//	tp_fdatalog(pl_PATTERN_PIN);
	return tb_end();
}

TEST_BLOCK(tb_VDDLDO_1D8_Trim)
{
	//partime(10 MS);
	tb_header();
	output("\n\nTestBlock:tb_VDDLDO_1D8_Trim");
	//output("vddldo_1p8 trim code is:  %2d,  Trim value is: %6.3f V ", vddldo_1p8_trim_value[dut1D8], vddldo_1p8_post[dut1D8] * 0.001*0.001);
	SoftwareOnlyActiveDutIterator lec_loop6;
	while (lec_loop6.More())//loop,then save trim value                                                                                               
	{
		DutNum dut1D8 = active_dut_get();
		//output("\n\nTestBlock:tb_VDDLDO_1D8_Trim");
		output("vddldo_1p8 trim dut %d code is:  %2d,  Trim value is: %6.3f V ", dut1D8+1, vddldo_1p8_trim_value[dut1D8], vddldo_1p8_post[dut1D8] * 0.001*0.001);
		//output("\n");
		if (vddldo_1p8_post[dut1D8] > 1700000 && vddldo_1p8_post[dut1D8] < 1900000)
		{
			result_set(dut1D8, 1);
		}
		else result_set(dut1D8, 0);
	}
	output("\n");
	return tb_end();
}

TEST_BLOCK(tb_Vref_Trim)
{
	
	tb_header();
	output("\n\nTestBlock:tb_Vref_Trim");
	double delta_vref[DUTNUM][32] = { 0 };
	double delta_vref_min[DUTNUM] = { 0 };
	//unsigned int vref_trim_value_tmp = 0;

	//char ValueName[] = "Vref";
	//LDOVDDTrimDataToEBM();
	//ebm_config_set(t_ebm_data_mode, pl_GPIO6_PAD);
	//ebm_address_pointer_reset();
	//Delay(1 MS);
	//funtest(VDDLDO_2D2_Trim, finish);

	LDOVDDTrimDataToEBM();
	Delay(3 MS);
	funtest(VDDLDO_2D2_Trim, finish);


	funtest(Vref_OUT, finish);
	funtest(Vref_Default, finish);
	Delay(10 MS);

	funtest(Vref_emulation_trim_Code5, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	GetVrefValue(5);

	funtest(Vref_emulation_trim_Code6, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	GetVrefValue(6);

	funtest(Vref_emulation_trim_Code7, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	GetVrefValue(7);

	funtest(Vref_emulation_trim_Code8, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	GetVrefValue(8);

	funtest(Vref_emulation_trim_Code9, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	GetVrefValue(9);

	funtest(Vref_emulation_trim_Code10, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	GetVrefValue(10);

	funtest(Vref_emulation_trim_Code11, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	GetVrefValue(11);

	funtest(Vref_emulation_trim_Code12, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	GetVrefValue(12);

	double dut_Number[DUTNUM] = { 0 };
	//CArray<double, double> meas_results;
	SoftwareOnlyActiveDutIterator lec_loop2;
	CArray<double, double> meas_results;
	while (lec_loop2.More())//loop,then save trim value
	{
		DutNum dut_num = active_dut_get();
		for (int i = 5; i < 13; i++)
		{
			delta_vref[dut_num][i] = fabs(900000 - vref_meas[dut_num][i]);
			if (i == 5)
			{
				delta_vref_min[dut_num] = delta_vref[dut_num][i];
				vref_trim_value[dut_num] = i;
				vref_post[dut_num] = vref_meas[dut_num][i];
			}

			else if (i > 5)
			{
				if (delta_vref[dut_num][i] < delta_vref_min[dut_num])
				{
					delta_vref_min[dut_num] = delta_vref[dut_num][i];
					vref_trim_value[dut_num] = i;
					vref_post[dut_num] = vref_meas[dut_num][i];
				}
			}

		}
		output("DUT%d Verf trim code is:  %2d,  Trim value is: %6.3f V ", dut_num + 1, vref_trim_value[dut_num], vref_post[dut_num] * 0.001*0.001);
		if (vref_post[dut_num] > 890000 && vref_post[dut_num] < 910000)
		{
			result_set(dut_num, 1);
		}
		else result_set(dut_num, 0);
	}
	output("\n");
//	power_down();
	return tb_end();
}

TEST_BLOCK(tb_OSC2M_Trim)
{
	//partime(10 MS);
	tb_header();
	output("\n\nTestBlock:tb_OSC2M_Trim");
	funtest(OSC2M_Default, finish);
	Delay(10 MS);

	vol(1.65 V, pl_GPIO6_PAD);
	voh(2.0 V, pl_GPIO6_PAD);
	funtest(OSC2M_Trim_Code8, finish);
	Delay(10 MS);
	test_result = pin_frequency_meas(pl_GPIO6_PAD, t_pin_freq_meas_80);
	GetOSC2MfValue(8);	
	
	funtest(OSC2M_Trim_Code9, finish);
	Delay(10 MS);
	test_result = pin_frequency_meas(pl_GPIO6_PAD, t_pin_freq_meas_80);
	GetOSC2MfValue(9);
	

	funtest(OSC2M_Trim_Code10, finish);
	Delay(10 MS);
	test_result = pin_frequency_meas(pl_GPIO6_PAD, t_pin_freq_meas_80);
	GetOSC2MfValue(10);
	

	funtest(OSC2M_Trim_Code11, finish);
	Delay(10 MS);
	test_result = pin_frequency_meas(pl_GPIO6_PAD, t_pin_freq_meas_80);
	GetOSC2MfValue(11);
	

	funtest(OSC2M_Trim_Code12, finish);
	Delay(10 MS);
	test_result = pin_frequency_meas(pl_GPIO6_PAD, t_pin_freq_meas_80);
	GetOSC2MfValue(12);	

	funtest(OSC2M_Trim_Code13, finish);
	Delay(10 MS);
	test_result = pin_frequency_meas(pl_GPIO6_PAD, t_pin_freq_meas_80);
	GetOSC2MfValue(13);

	double dut_Number[DUTNUM] = { 0 };
	//CArray<double, double> meas_results;
	SoftwareOnlyActiveDutIterator lec_loop2;
	CArray<double, double> meas_results;
	while (lec_loop2.More())//loop,then save trim value
	{
		DutNum dut_num = active_dut_get();
		for (int i = 8; i < 14; i++)
		{
			delta_osc2m[dut_num][i] = fabs(1995000 - osc2m_meas[dut_num][i]);
			if (i == 8)
			{
				delta_osc2m_min[dut_num] = delta_osc2m[dut_num][i];
				osc2m_trim_value[dut_num] = i;
				osc2m_post[dut_num] = osc2m_meas[dut_num][i];
			}

			else if (i > 5)
			{
				if (delta_osc2m[dut_num][i] < delta_osc2m_min[dut_num])
				{
					delta_osc2m_min[dut_num] = delta_osc2m[dut_num][i];
					osc2m_trim_value[dut_num] = i;
					osc2m_post[dut_num] = osc2m_meas[dut_num][i];
				}
			}

		}
		output("DUT %2d OSC2M trim code is:  %2d,  Trim value is: %6.6f M ", dut_num + 1, osc2m_trim_value[dut_num], osc2m_post[dut_num] / 1000000);
		if (osc2m_post[dut_num] > 1895000 && osc2m_post[dut_num] < 2095000)
		{
			result_set(dut_num, 1);
		}
		else result_set(dut_num, 0);
	}
	output("\n");
	power_down();
	
	return tb_end();
}

TEST_BLOCK(tb_ADC_Test)
{
	//partime(10 MS);
	tb_header();
	output("\n\nTestBlock:tb_ADC_Test");
	//int temp[DUTNUM][50] = { 0 };
	int average_adc_out[DUTNUM] = { 0 };
	int Data[DUTNUM][10][10] = { 0 };
	int adc_out[DUTNUM][5] = { 0 };
	float adc_out_volt[DUTNUM][5] = { 0 };
	ts_ADC();
	ADC_lvl();
	//func_lvl();
	ptu_connect(pl_CMS_PAD);
	ptu_connect(pl_PWRWAKE_PAD);
	ptu_vpar_force_set(0 V, pl_CMS_PAD);
	ptu_vpar_force_set(3.1 V, pl_PWRWAKE_PAD);
	//ipar_force(0 UA);
	//vpar_high(5 V);
	//vpar_low(0 V);
	//vclamp(7 V, -2 V);
	//measure(TRUE);
	Delay(5 MS);

	funtest(EOT_INIT_CLK, finish);
	funtest(CP_CLK_SEL, finish);

	OSCTrimDataToEBM();
	Delay(3 MS);
	funtest(OSC2M_Trim, finish);
	//vol(1.65 V, pl_GPIO6_PAD);
	//voh(2.4 V, pl_GPIO6_PAD);
	//test_result = pin_frequency_meas(pl_GPIO6_PAD, t_pin_freq_meas_80);
	//GetOSC2MfValue(0);

	//funtest(VDDLDO_OUT, finish);
	//funtest(VDDLDO_Default, finish);
	LDOVDDTrimDataToEBM();
	Delay(3 MS);
	funtest(VDDLDO_2D2_Trim, finish);
	//Delay(10 MS);
	//partest(pass_nivl, pl_ADC_PAD);
	//GetVDDLDOValue(0);
	//output("\n");

	//funtest(Vref_OUT, finish);
	//funtest(Vref_Default, finish);
	VrefTrimDataToEBM();
	Delay(3 MS);
	funtest(Vref_Trim, finish);
	//Delay(10 MS);
	//partest(pass_nivl, pl_ADC_PAD);
	//GetVrefValue(0);
	//output("\n");

	funtest(ADC_PAD_IN, finish);
	Delay(3 MS);
	//tp_fdatalog(pl_PATTERN_PIN);

	lec_config_set(pl_GPIO6_PAD);
	lec_mode_set(t_lec_mode_5, t_lec_vcount1, t_lec_vcount4, t_lec_vcount_na, t_lec_vcount_na);// lec_mode set
	disconnect(pl_ADC_PAD);
	Delay(2 MS);
	ptu_connect(pl_ADC_PAD);
	Delay(2 MS);
	int k = 0;
	double volt = 0.0;
	DutNumArray duts;
	int dut_count;
	DoubleArray dnlResults1;
	DoubleArray dnlResults2;
	DoubleArray dnlResults3;
	DoubleArray dnlResults4;
	dnlResults1.SetSize(DUTNUM);
	dnlResults2.SetSize(DUTNUM);
	dnlResults3.SetSize(DUTNUM);
	dnlResults4.SetSize(DUTNUM);
	
	
	for ( k = 0; k < 4; k++)
	{ 
		
		//lec_config_set(pl_GPIO6_PAD);
		//lec_mode_set(t_lec_mode_5, t_lec_vcount1, t_lec_vcount4, t_lec_vcount_na, t_lec_vcount_na);// lec_mode set
		output("\n\nForce %6.3f V to ADC_PAD ", 0.5 + 0.1*k);
		volt = 0.5 + 0.1*k;
		ptu_vpar_force_set(volt V, pl_ADC_PAD);
		Delay(5 MS);
		funtest(ADC_Test_Out, LEC_first_vectors);
		//LecEntryArray2 class
		LecEntryArray2 lec_ADCArr;        //for store lec_scan result
		// dut_loop class
		SoftwareOnlyActiveDutIterator lec_ADCLoop;
		int count;
		

		while (lec_ADCLoop.More())
		{
			//current active dut
			DutNum dut_num = active_dut_get();
			output("DutNum is:  %d ", dut_num);
			int i = 0;
			count = 0;
			count = lec_scan(0, 1200, 0xff, 0x00, 1200, lec_ADCArr); //max range-16777216
			//for (i = 0; i < 1145; i++)
			//{
			//	output("adc_out_data is:  %d ", lec_ADCArr[i].data_lo);
			//}

			adc_out[dut_num][0] = 0;
			adc_out[dut_num][1] = 0;
			adc_out[dut_num][2] = 0;
			adc_out[dut_num][3] = 0;
			adc_out[dut_num][4] = 0;
			average_adc_out[dut_num] = 0;
	



			for (i = 0; i < 10; i++)
			{
				adc_out[dut_num][0] += lec_ADCArr[1080 + i].data_lo *(int)pow(2, i);

			}
			output("adc_out_data0 is:  %d ", adc_out[dut_num][0]);

			for (i = 0; i < 10; i++)
			{
				adc_out[dut_num][1] += lec_ADCArr[1093 + i].data_lo *(int)pow(2, i);

			}
			output("adc_out_data1 is:  %d ", adc_out[dut_num][1]);

			for (i = 0; i < 10; i++)
			{
				adc_out[dut_num][2] += lec_ADCArr[1106 + i].data_lo *(int)pow(2, i);

			}
			output("adc_out_data2 is:  %d ", adc_out[dut_num][2]);

			for (i = 0; i < 10; i++)
			{
				adc_out[dut_num][3] += lec_ADCArr[1119 + i].data_lo *(int)pow(2, i);

			}
			output("adc_out_data3 is:  %d ", adc_out[dut_num][3]);

			for (i = 0; i < 10; i++)
			{
				adc_out[dut_num][4] += lec_ADCArr[1132 + i].data_lo *(int)pow(2, i);

			}
			output("adc_out_data4 is:  %d ", adc_out[dut_num][4]);

			average_adc_out[dut_num] = (adc_out[dut_num][0] + adc_out[dut_num][1] + adc_out[dut_num][2] + adc_out[dut_num][3] + adc_out[dut_num][4]) / 5;
			adc_out_volt[dut_num][k] = average_adc_out[dut_num] * (vref_post[dut_num] * 0.001*0.001) / 1024;
			output("adc_out_volt is:  %6.3f V ", adc_out_volt[dut_num][k]);

			dnlResults1[dut_num] = adc_out_volt[dut_num][0];
			dnlResults2[dut_num] = adc_out_volt[dut_num][1];
			dnlResults3[dut_num] = adc_out_volt[dut_num][2];
			dnlResults4[dut_num] = adc_out_volt[dut_num][3];
		}	
	}

	test_result = vartest(pass_varil, dnlResults1, 0.66, 0.71);   //Need to define right limits.
	dut_count = results_get(&r1);
	test_result = vartest(pass_varil, dnlResults2, 0.71, 0.75);   //Need to define right limits.
	dut_count = results_get(&r2);
	test_result = vartest(pass_varil, dnlResults3, 0.76, 0.80);   //Need to define right limits.
	dut_count = results_get(&r3);
	test_result = vartest(pass_varil, dnlResults4, 0.81, 0.85);   //Need to define right limits.
	dut_count = results_get(&r4);

	for (int i = 0; i<dut_count; i++)r1[i] = r1[i] && r2[i] && r3[i] && r4[i];
	results_set(r1);

//	power_down();
	return tb_end();
}

TEST_BLOCK(tb_TS_Test1)
{
	//partime(10 MS);
	tb_header();
	ipar_force(0 UA);
	vpar_high(0.7 V);
	vpar_low(0.6 V);
	vclamp(2 V, 0 V);
	output("\n\nTestBlock:tb_TS_Test1");	
	funtest(Vts_OUT, finish);
	funtest(TS_On, finish);
	Delay(10 MS);
	partest(pass_nivl, pl_ADC_PAD);
	tp_pdatalog(pl_ADC_PAD, ForceIMeasureV);
	
	return tb_end();
}

TEST_BLOCK(tb_TS_Test2)
{
	//partime(10 MS);
	tb_header();
	output("\n\nTestBlock:tb_TS_Test2");
	int vts_temp[DUTNUM][100] = { 0 };
	int Data[DUTNUM][10][10] = { 0 };
	int vts_adc_out[DUTNUM][10] = { 0 };
	double vts_out_volt[DUTNUM] = { 0.0 };
//	int average_vts_adc_out[DUTNUM] = { 0 };
//	char vts_adc_out_wr[DUTNUM][10][2], vts_adc_out_rd[DUTNUM][10][2];
	int dut_count;
	DoubleArray dnlResults5;
	dnlResults5.SetSize(DUTNUM);


	funtest(TS_On, finish);
	funtest(ADC_PAD_IN_Vts, finish);
	Delay(10 MS);
	lec_config_set(pl_GPIO6_PAD);
	lec_mode_set(t_lec_mode_5, t_lec_vcount1, t_lec_vcount4, t_lec_vcount_na, t_lec_vcount_na);// lec_mode set
	funtest(ADC_Test_Out_Vts, LEC_first_vectors);
	LecEntryArray2 lec_VTSArr;        //for store lec_scan result
	// dut_loop class
	SoftwareOnlyActiveDutIterator lec_VTSLoop;
	int count;


	while (lec_VTSLoop.More())
	{
		//current active dut
		DutNum dut_num = active_dut_get();
		output("DutNum is:  %d ", dut_num);
		int i = 0;
		count = 0;
		count = lec_scan(0, 220, 0xff, 0x00, 220, lec_VTSArr); //max range-16777216
		//for (i = 0; i < 218; i++)
		//{
		//	output("adc_out_data is:  %d ", lec_ADCArr[i].data_lo);
		//}

		vts_adc_out[dut_num][0] = 0;
		vts_adc_out[dut_num][1] = 0;
		vts_adc_out[dut_num][2] = 0;
		vts_adc_out[dut_num][3] = 0;
		vts_adc_out[dut_num][4] = 0;
		average_vts_adc_out[dut_num] = 0;




		for (i = 0; i < 10; i++)
		{
			vts_adc_out[dut_num][0] += lec_VTSArr[90 + i].data_lo *(int)pow(2, i);

		}
		output("adc_out_data0 is:  %d ", vts_adc_out[dut_num][0]);

		for (i = 0; i < 10; i++)
		{
			vts_adc_out[dut_num][1] += lec_VTSArr[103 + i].data_lo *(int)pow(2, i);

		}
		output("adc_out_data1 is:  %d ", vts_adc_out[dut_num][1]);

		for (i = 0; i < 10; i++)
		{
			vts_adc_out[dut_num][2] += lec_VTSArr[116 + i].data_lo *(int)pow(2, i);

		}
		output("adc_out_data2 is:  %d ", vts_adc_out[dut_num][2]);

		for (i = 0; i < 10; i++)
		{
			vts_adc_out[dut_num][3] += lec_VTSArr[142 + i].data_lo *(int)pow(2, i);

		}
		output("adc_out_data3 is:  %d ", vts_adc_out[dut_num][3]);

		for (i = 0; i < 10; i++)
		{
			vts_adc_out[dut_num][4] += lec_VTSArr[155 + i].data_lo *(int)pow(2, i);

		}
		output("adc_out_data4 is:  %d ", vts_adc_out[dut_num][4]);

		average_vts_adc_out[dut_num] = (vts_adc_out[dut_num][0] + vts_adc_out[dut_num][1] + vts_adc_out[dut_num][2] + vts_adc_out[dut_num][3] + vts_adc_out[dut_num][4]) / 5;
		vts_out_volt[dut_num] = average_vts_adc_out[dut_num] * (vref_post[dut_num] * 0.001*0.001) / 1024;
		output("adc_out_volt is:  %6.3f V ", vts_out_volt[dut_num]);
		dnlResults5[dut_num] = vts_out_volt[dut_num];

	}
	test_result = vartest(pass_varil, dnlResults5, 0.8, 0.9);  //Need to define right limits.
	dut_count = results_get(&r1);
	results_set(r1);

	power_down();
	return tb_end();
}

TEST_BLOCK(tb_IP_Trim_Write_Test)
{
	//partime(10 MS);
	tb_header();
	output("\n\nTestBlock:tb_IP_Trim_Write_Test");
	ts_std1();
	func_lvl();
	ptu_connect(pl_CMS_PAD);
	ptu_connect(pl_PWRWAKE_PAD);
	ptu_connect(pl_VPP_PAD);
	ptu_vpar_force_set(0 V, pl_CMS_PAD);
	ptu_vpar_force_set(3.1 V, pl_PWRWAKE_PAD);

	
	VrefTrimDataToEBM();
	funtest(EOT_INIT_CLK, finish);
	funtest(POWER_CHANGE, finish);
	funtest(CP_CLK_SEL, finish);
	Delay(5 MS);
	funtest(IP_Trim_Write1, finish);
	ptu_vpar_force_set(7.45 V, pl_VPP_PAD);
	IP_TRIM_WRITE_EBM();
	Delay(5 MS);
	funtest(IP_Trim_Write2, finish);
	ptu_vpar_force_set(0 V, pl_VPP_PAD);
	Delay(5 MS);
	funtest(IP_Trim_Read, finish);
	tp_fdatalog(pl_PATTERN_PIN);
	VrefTrimDataToEBM();
	Delay(5 MS);
	funtest(IP_Trim_Read_Vref, finish);
	tp_fdatalog(pl_PATTERN_PIN);
	power_down();

	return tb_end();
}

TEST_BLOCK(tb_load_ucode)
{
	
	tb_header();
	output("\n\nTestBlock:tb_load_ucode");
	pin_connect(pl_IOPINS);
	ptu_connect(pl_CMS_PAD);
	//ptu_connect(pl_VDD_PAD);
	ptu_connect(pl_PWRWAKE_PAD);
	ts_std();
	func_lvl();
	//setpin(pl_CMS_PAD, VIL);
	//setpin(pl_VDD_PAD, VIH);
	//setpin(pl_PWRWAKE_PAD, VIH);
	ptu_vpar_force_set(0 V, pl_CMS_PAD);
	//ptu_vpar_force_set(3.3 V, pl_VDD_PAD);
	ptu_vpar_force_set(3.1 V, pl_PWRWAKE_PAD);
	Delay(5 MS);

	funtest(EOT_INIT_CLK, finish);
	funtest(CmdTest, finish);
	funtest(POWER_CHANGE, finish);
	funtest(CP_CLK_SEL, finish);
	Delay(10 MS);

	ptu_connect(pl_VPP_PAD);
	ptu_vpar_force_set(7.45 V, pl_VPP_PAD);
	Delay(10 MS);
	funtest(write_normal, finish);
	ptu_vpar_force_set(0 V, pl_VPP_PAD);
	ptu_disconnect(pl_VPP_PAD);
	Delay(10 MS);
	funtest(read_normal, finish);
	tp_fdatalog(pl_PATTERN_PIN);
	power_down();
	return tb_end();
}

TEST_BLOCK(tb_idd_ramist)
{
	tb_header();
	power_down();
	pin_connect(pl_XT1_PAD);
	pin_connect(pl_PWRWAKE_PAD);
	pin_connect(pl_CMS_PAD);
		
	ts_ramist();
	ramist_lvl();
	partime(10 MS);
	ptu_connect(pl_PWRWAKE_PAD);
	ptu_connect(pl_CMS_PAD);
	
	ptu_vpar_force_set(3.0 V, pl_PWRWAKE_PAD);
	ptu_vpar_force_set(3.0 V, pl_CMS_PAD);
	measure(TRUE);
	Delay(5 MS);

	start_pattern(XT1_CLK1);
	//Delay(5 MS);
	dps(3.0 V, pl_VDD);
	dps_current_high(14 UA, pl_VDD);
	dps_current_low(7 UA, pl_VDD);	
	Delay(5 MS);
	test_supply(pass_nicl, pl_VDD);
	tp_pdatalog(pl_VDD, ForceVMeasureI);
	stop_pattern();

	start_pattern(XT1_CLK1);
	ptu_vpar_force_set(0 V, pl_PWRWAKE_PAD);
	Delay(50 MS);
	ptu_vpar_force_set(3.0 V, pl_PWRWAKE_PAD);
	Delay(50 MS);
//	dps(3.0 V, pl_VDD);
	Delay(50 MS);
	dps_current_high(500 NA, pl_VDD);
	dps_current_low(0 NA, pl_VDD);
	test_supply(pass_nicl, pl_VDD);
	tp_pdatalog(pl_VDD, ForceVMeasureI);
	stop_pattern();

	power_down();
	return tb_end();
}


TEST_BLOCK(tb_Istand_Test)
{
	tb_header();
	ts_Istand();
	Istand_lvl();
	pin_connect(pl_IOPINS);
	ptu_connect(pl_CMS_PAD);
	ptu_connect(pl_PWRWAKE_PAD);
	ptu_vpar_force_set(0 V, pl_CMS_PAD);
	ptu_vpar_force_set(3.0 V, pl_PWRWAKE_PAD);
	Delay(10 MS);
	

	funtest(EOT_INIT_CLK, finish);
	funtest(CmdTest, finish);
	funtest(Halver_on, finish);

	vih(1.6 V, pl_XT1_PAD);
	Delay(10 MS);
	start_pattern(EotStandby_Mode);
	//disconnect(pl_IOPINS_NO_GPIO4_XT1_CMS_PWRWAKE);
	Delay(100 MS);
	dps_current_high(500 NA, pl_VDD, range1);
	dps_current_low(0 NA, pl_VDD, range1);
	test_supply(pass_nicl, pl_VDD);
	tp_pdatalog(pl_VDD, ForceVMeasureI);
	stop_pattern();

	power_down();
	return tb_end();
}


TEST_BLOCK(tb_Write_CP3_GDFLG_Test)
{
	tb_header();
	output("\n\nTestBlock:tb_Write_CP3_GDFLG_Test");
	ts_std1();
	func_lvl();
	ptu_connect(pl_CMS_PAD);
	ptu_connect(pl_PWRWAKE_PAD);
	ptu_vpar_force_set(0 V, pl_CMS_PAD);
	ptu_vpar_force_set(3.1 V, pl_PWRWAKE_PAD);
	Delay(5 MS);
	funtest(EOT_INIT_CLK, finish);
	funtest(CmdTest, finish);
	funtest(POWER_CHANGE, finish);
	funtest(CP_CLK_SEL, finish);
	Delay(10 MS);

	ptu_connect(pl_VPP_PAD);
	ptu_vpar_force_set(7.45 V, pl_VPP_PAD);
	Delay(10 MS);
	funtest(Write_CP3_GDFLG, finish);
	ptu_vpar_force_set(0 V, pl_VPP_PAD);
	ptu_disconnect(pl_VPP_PAD);

	Delay(10 MS);
	funtest(Read_CP3_GDFLG, finish);
	tp_fdatalog(pl_PATTERN_PIN);
	power_down();

	return tb_end();
}

