#include <malloc.h>
#include <stdio.h>
#include <math.h>
#include "tester.h"
//#include "pin_list.h"

#ifdef SumDut_16
void  get_value(int tester_resouce)
{
	double dut_Number[16];
	CArray<double, double> meas_results;
	SoftwareOnlyActiveDutIterator lec_loop2;
	while (lec_loop2.More())//loop,then save trim value
	{
		DutNum dut_num = active_dut_get();
		DpoHv_meas(meas_results);
		dut_Number[dut_num] = meas_results[0];
		output("%d", dut_Number[dut_num]);
	}
	//return;
}

void  BG_save_trim_value(int trim_number)
{
	double dut_Number[16];
	CArray<double, double> meas_results;// define array for measure result
	SoftwareOnlyActiveDutIterator lec_loop2;
	while (lec_loop2.More())//loop,then save trim value
	{
		DutNum dut_num = active_dut_get();
	//	output("***mg dut_num = %d", dut_num);
		//output("t_dut%d", dut_num + 1);
		//Hv_meas_all_pins(meas_results);//Hv_meas and Hv_meas_all_pins 
		//dpo_adc_measurements_get(TPPAD, dut_num, meas_results);
		Dps_meas(meas_results);
		//int count = meas_results.GetCount();
		//for (int z = 0; z < count; z++) output("***   meas_results[%d] = %3f", z, meas_results[z]);
		//output("***   meas_results[0] = %f", meas_results[0]);
		//for (int i = dut_num; i < 14; i = i + 2)
		//{
		//	output("i_t_dut%d", i);
		//	output("j_t_dut%d", j);
		//	dut_Number[j] = meas_results[i];//j=dut num
		//	dut_Number[j + 1] = temp = meas_results[i+1];
		//	j = j+6;
		//}
		//output("for");
//		dut_Number[dut_num] = meas_results[i + 1];
		dut_Number[dut_num] = meas_results[0];
		//output("***   dut_Number[%d] = %3.2f", dut_num, dut_Number[dut_num]);
//		i = i + 1;
//		output("***   i = %d", i);
		BGTrim_voltage[dut_num][trim_number] = dut_Number[dut_num];
		//output("***   BGTrim_voltage[%d][%d] = %3.2f", dut_num, trim_number, BGTrim_voltage[dut_num][trim_number]);
		//output("dut_Number[%d]:%d", dut_num+1, dut_Number[dut_num]);
		//output("BGTrim_voltage[%d][%d] = meas_results[%d];", dut_num, trim_number, dut_num);//dut_num=0->41
	}
}

void  VR16_save_trim_value(double trim_voltage)
{
	double dut_Number[16];
	CArray<double, double> meas_results;// define array for measure result
	SoftwareOnlyActiveDutIterator lec_loop2;
	while (lec_loop2.More())//loop,then save trim value
	{
		DutNum dut_num = active_dut_get();
		//	output("***mg dut_num = %d", dut_num);
		//output("t_dut%d", dut_num + 1);
		//Hv_meas_all_pins(meas_results);//Hv_meas and Hv_meas_all_pins 
		//dpo_adc_measurements_get(TPPAD, dut_num, meas_results);
		Pin_meas(meas_results);
		//int count = meas_results.GetCount();
		//for (int z = 0; z < count; z++) output("***   meas_results[%d] = %3f", z, meas_results[z]);
		//output("***   meas_results[0] = %f", meas_results[0]);
		//for (int i = dut_num; i < 14; i = i + 2)
		//{
		//	output("i_t_dut%d", i);
		//	output("j_t_dut%d", j);
		//	dut_Number[j] = meas_results[i];//j=dut num
		//	dut_Number[j + 1] = temp = meas_results[i+1];
		//	j = j+6;
		//}
		//output("for");
		//		dut_Number[dut_num] = meas_results[i + 1];
		dut_Number[dut_num] = meas_results[0];
		//output("***   dut_Number[%d] = %3.2f", dut_num, dut_Number[dut_num]);
		//		i = i + 1;
		//		output("***   i = %d", i);
		VR16Trim_voltage[dut_num] = dut_Number[dut_num];
		//output("***   BGTrim_voltage[%d][%d] = %3.2f", dut_num, trim_number, BGTrim_voltage[dut_num][trim_number]);
		//output("dut_Number[%d]:%d", dut_num+1, dut_Number[dut_num]);
		//output("BGTrim_voltage[%d][%d] = meas_results[%d];", dut_num, trim_number, dut_num);//dut_num=0->41
	}
}
void  PGVPP_save_trim_value(int trim_number)
{

	double dut_Number[16];
	CArray<double, double> meas_results;
	SoftwareOnlyActiveDutIterator lec_loop2;
	
	while (lec_loop2.More())//loop,then save trim value
	{
		DutNum dut_num = active_dut_get();
		Hv_meas(meas_results);
		//Hv_meas_all_pins(meas_results);//Hv_meas and Hv_meas_all_pins 
		//for (int i = dut_num; i < 14; i = i + 2)
		//{
		//	dut_Number[j] = meas_results[i];//j=dut num
		//	dut_Number[j + 1] = meas_results[i + 1];
		//	j = +6;
		//}
		dut_Number[dut_num] = meas_results[0];
		PGVPPTrim_voltage[dut_num][trim_number] = dut_Number[dut_num];
		//output("FlashVPPTrim_voltage[%d][%d] = meas_results[%d];", dut_num, trim_number, dut_num);//dut_num=0->41
	}
}

void  ERVPP_save_trim_value(int trim_number)
{

	double dut_Number[16];
	CArray<double, double> meas_results;
	SoftwareOnlyActiveDutIterator lec_loop2;

	while (lec_loop2.More())//loop,then save trim value
	{
		DutNum dut_num = active_dut_get();
		DpoHv_meas(meas_results);
		//Hv_meas_all_pins(meas_results);//Hv_meas and Hv_meas_all_pins 
		//for (int i = dut_num; i < 14; i = i + 2)
		//{
		//	dut_Number[j] = meas_results[i];//j=dut num
		//	dut_Number[j + 1] = meas_results[i + 1];
		//	j = +6;
		//}
		dut_Number[dut_num] = meas_results[0];
		PGVPPTrim_voltage[dut_num][trim_number] = dut_Number[dut_num];
		//output("FlashVPPTrim_voltage[%d][%d] = meas_results[%d];", dut_num, trim_number, dut_num);//dut_num=0->41
	}
}
void  PGVNN_save_trim_value(int trim_number)
{
	double dut_Number[16];
	CArray<double, double> meas_results;
	SoftwareOnlyActiveDutIterator lec_loop2;
	while (lec_loop2.More())//loop,then save trim value
	{
		DutNum dut_num = active_dut_get();
		DpoHv_meas(meas_results);
	
		dut_Number[dut_num] = meas_results[0];
		FlashVNNTrim_voltage[dut_num][trim_number] = dut_Number[dut_num];
		//output("FlashVNNTrim_voltage[%d][%d] = meas_results[%d];", dut_num, trim_number, dut_num);//dut_num=0->41
	}
}

void  ERVNN_save_trim_value(int trim_number)
{
	double dut_Number[16];
	CArray<double, double> meas_results;
	SoftwareOnlyActiveDutIterator lec_loop2;
	while (lec_loop2.More())//loop,then save trim value
	{
		DutNum dut_num = active_dut_get();
		DpoHv_meas(meas_results);

		dut_Number[dut_num] = meas_results[0];
		FlashVNNTrim_voltage[dut_num][trim_number] = dut_Number[dut_num];
		//output("FlashVNNTrim_voltage[%d][%d] = meas_results[%d];", dut_num, trim_number, dut_num);//dut_num=0->41
	}
}
#endif