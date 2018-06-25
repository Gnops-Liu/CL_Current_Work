#include "tester.h"


// ******************************
// *****  Test Blocks file  *****
// ******************************
// 

TEST_BLOCK(tb_BG_Trim)
{
	TB.header();
	vs_std();
	ts_20_Mhz();
	ptu_connect(VDDH_IO);
	ptu_vpar_force_set(5.0 V, VDDH_IO);
	test_number(1);
	Delay(10 MS);


	funtest(p_BG,finish);
	return TB.end();
}





//*********************************************
TEST_BLOCK(tb_demo)
{
	TB.header();

	power_down();
	
	ptu_connect(pl_GPIO0);
	test_number(99);
	ptu_vpar_force_set(0.4 V, pl_GPIO0);

	results_set(PASS);
	return TB.end();
}



TEST_BLOCK(tb_demo2)
{
	TB.header();
	int Cad[12];
	for (int i = 0; i < 12; i++)
	{
		Cad[i] = 521;
	}
	CString label1 = "Cad";
	CString label2 = "Cad2";
	TB.value(label1, Cad);
	TB.value(label2, Cad);
	results_set(PASS);
	return TB.end();
}

TEST_BLOCK(tb_demo1)
{
	TB.header();
	char *  Cad[12];
	static char * time[12];
	for (int i = 0; i < 12; i++)
	{
		Cad[i] = "hello";
	}
// example 1
	SoftwareOnlyActiveDutIterator loop;
	while (loop.More(TRUE))
	{
		DutNum dut = active_dut_get();
		CString buffer = CTime::GetCurrentTime().Format("%y.%m.%d_%H.%M.%S");
		time[dut] = CString2Char(buffer);
	}
// example 2
	CString buffer = CTime::GetCurrentTime().Format("%y.%m.%d_%H.%M.%S");
	for (int i = 0; i < 12; i++)
	{
		time[i] = CString2Char(buffer);
	}
//example 3
	int demo[12];
	CString buffer12[12];
	while (loop.More(TRUE))
	{
		DutNum dut = active_dut_get();
		demo[dut] = dut;
	}
	for (int i = 0; i < 12; i++)
	{
		buffer12[i] = (buffer + Int2CString(demo[i]));
		time[i] = CString2Char(buffer12[i]);
	}
// example 4
	while (loop.More(TRUE))
	{
		DutNum dut = active_dut_get();
		buffer12[dut] = CTime::GetCurrentTime().Format("%y.%m.%d_%H.%M.%S");
		time[dut] = CString2Char(buffer12[dut]);
	}

//end
	output(time[0]);

	CString hello = "hello";
	CString label1 = "Ca";
	CString label2 = "time";
	TB.value(label1, Cad);
	TB.value(label2, time);
	
	results_set(PASS);
	return TB.end();
}



