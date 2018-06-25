//User_Subroutine.h(c)
//Editor:Colin Liu
//Start Time:2017/10/29
//In order to add more cpp function in test program, The best way is to isolate User_code from M2 characterastic compiling process
//So there should be two different compiling lines and in tblc_ac using both.
#include "User.h"
#include "User_subroutine.h"
#include "tester.h"

Verify_Stuff Treas_Vrf;
Margin_Record Treas_Mrg;
/***************************************
*SN:		folder_existed
*Format:	int folder_existed(char *fn)
*Parameter: fn>>file's name
*returns:	0 >>This file is not existed
*			1 >>This file is existed
****************************************/
int folder_existed(CString fn)
{
	return (_access(fn, 00) == 00);
}

void get_slaves_mask(SiteMask *mask)
{
	*mask = 0x0;
	int slave_site = site_num() + 1;
	int i;
	for (i = 2; i <= sites_per_controller(); ++i)
		(*mask) |= (1 << (slave_site++ - 1));
}

void tb_Summary()
{
	int x; int y;
	Get_LotNum();
	SoftwareOnlyActiveDutIterator loop1;
	while (loop1.More(TRUE))
	{
		DutNum dut = active_dut_get();
		TPEGetCurrentXY(dut, &x, &y);

		Treasure_save("Site", site_num());
		Treasure_save("Dut", dut);
		Treasure_save("AddrX", x);
		Treasure_save("AddrY", y);
		//Trimming
		Treasure_save("[TRIM]Main_BG(32)code", MAIN_BGP.record[dut]);
		Treasure_save("[TRIM]SDN_BG(32)code", SDN_BGP.record[dut]);
		Treasure_save("[TRIM]Prog_VNN(32)code", PROG_VNN.record[dut]);
		Treasure_save("[TRIM]Prog_VNN(128)code", PROG_VNN2.record[dut]);
		Treasure_save("[TRIM]Erase_VPP(32)code", ERA_VPP.record[dut]);
		Treasure_save("[TRIM]Erase_VPP(128)code", ERA_VPP2.record[dut]);
		Treasure_save("[TRIM]Prog_VPP(32)code", PROG_VPP.record[dut]);
		Treasure_save("[TRIM]Prog_VPP(128)code", PROG_VPP2.record[dut]);


		if ((MAIN_BGP.record[dut] != 537) && (MAIN_BGP.record[dut] != -1))
			Treasure_save("[TRIM]Main_BG(32)value", MAIN_BGP.logout[MAIN_BGP.record[dut]][dut]);
		else
			Treasure_save("[TRIM]Main_BG(32)value", 537);

		if ((SDN_BGP.record[dut] != 537) && (SDN_BGP.record[dut] != -1))
			Treasure_save("[TRIM]SDN_BG(32)value", SDN_BGP.logout[SDN_BGP.record[dut]][dut]);
		else
			Treasure_save("[TRIM]SDN_BG(32)value", 537);

		if ((ERA_VPP.record[dut] != 537) && (ERA_VPP.record[dut] != -1)) 
			Treasure_save("[TRIM]Erase_VPP(32)value", ERA_VPP.logout[ERA_VPP.record[dut]][dut]);
		else
			Treasure_save("[TRIM]Erase_VPP(32)value", 537);

		if ((ERA_VPP2.record[dut] != 537) && (ERA_VPP2.record[dut] != -1))
			Treasure_save("[TRIM]Erase_VPP(128)value", ERA_VPP2.logout[ERA_VPP2.record[dut]][dut]);
		else
			Treasure_save("[TRIM]Erase_VPP(128)value", 537);

		if ((PROG_VPP.record[dut] != 537) && (PROG_VPP.record[dut] != -1))
			Treasure_save("[TRIM]Prog_VPP(32)value", PROG_VPP.logout[PROG_VPP.record[dut]][dut]);
		else
			Treasure_save("[TRIM]Prog_VPP(32)value", 537);

		if ((PROG_VPP2.record[dut] != 537) && (PROG_VPP2.record[dut] != -1))
			Treasure_save("[TRIM]Prog_VPP(128)value", PROG_VPP2.logout[PROG_VPP2.record[dut]][dut]);
		else
			Treasure_save("[TRIM]Prog_VPP(128)value", 537);

		if ((PROG_VNN.record[dut] != 537) && (PROG_VNN.record[dut] != -1))
			Treasure_save("[TRIM]Prog_VNN(32)value", PROG_VNN.logout[PROG_VNN.record[dut]][dut]);
		else
			Treasure_save("[TRIM]Prog_VNN(32)value", 537);

		if ((PROG_VNN2.record[dut] != 537) && (PROG_VNN2.record[dut] != -1))
			Treasure_save("[TRIM]Prog_VNN(128)value", PROG_VNN2.logout[PROG_VNN2.record[dut]][dut]);
		else
			Treasure_save("[TRIM]Prog_VNN(128)value", 537);

		////Scanning
		Treasure_save("[Scanning]Main_BG(32)code0", MAIN_BGP.logout[0][dut]);
		Treasure_save("[Scanning]Main_BG(32)code1", MAIN_BGP.logout[1][dut]);
		Treasure_save("[Scanning]Main_BG(32)code2", MAIN_BGP.logout[2][dut]);
		Treasure_save("[Scanning]Main_BG(32)code3", MAIN_BGP.logout[3][dut]);
		Treasure_save("[Scanning]Main_BG(32)code4", MAIN_BGP.logout[4][dut]);
		Treasure_save("[Scanning]Main_BG(32)code5", MAIN_BGP.logout[5][dut]);
		Treasure_save("[Scanning]Main_BG(32)code6", MAIN_BGP.logout[6][dut]);
		Treasure_save("[Scanning]Main_BG(32)code7", MAIN_BGP.logout[7][dut]);
		Treasure_save("[Scanning]Main_BG(32)code8", MAIN_BGP.logout[8][dut]);
		Treasure_save("[Scanning]Main_BG(32)code9", MAIN_BGP.logout[9][dut]);
		Treasure_save("[Scanning]Main_BG(32)code10", MAIN_BGP.logout[10][dut]);
		Treasure_save("[Scanning]Main_BG(32)code11", MAIN_BGP.logout[11][dut]);
		Treasure_save("[Scanning]Main_BG(32)code12", MAIN_BGP.logout[12][dut]);
		Treasure_save("[Scanning]Main_BG(32)code13", MAIN_BGP.logout[13][dut]);
		Treasure_save("[Scanning]Main_BG(32)code14", MAIN_BGP.logout[14][dut]);
		Treasure_save("[Scanning]Main_BG(32)code15", MAIN_BGP.logout[15][dut]);

		Treasure_save("[Scanning]Sdn_BG(32)code0", SDN_BGP.logout[0][dut]);
		Treasure_save("[Scanning]Sdn_BG(32)code1", SDN_BGP.logout[1][dut]);
		Treasure_save("[Scanning]Sdn_BG(32)code2", SDN_BGP.logout[2][dut]);
		Treasure_save("[Scanning]Sdn_BG(32)code3", SDN_BGP.logout[3][dut]);
		Treasure_save("[Scanning]Sdn_BG(32)code4", SDN_BGP.logout[4][dut]);
		Treasure_save("[Scanning]Sdn_BG(32)code5", SDN_BGP.logout[5][dut]);
		Treasure_save("[Scanning]Sdn_BG(32)code6", SDN_BGP.logout[6][dut]);
		Treasure_save("[Scanning]Sdn_BG(32)code7", SDN_BGP.logout[7][dut]);

		Treasure_save("[Scanning]Erase_vpp(32)code0", ERA_VPP.logout[0][dut]);
		Treasure_save("[Scanning]Erase_vpp(32)code1", ERA_VPP.logout[1][dut]);
		Treasure_save("[Scanning]Erase_vpp(32)code2", ERA_VPP.logout[2][dut]);
		Treasure_save("[Scanning]Erase_vpp(32)code3", ERA_VPP.logout[3][dut]);
		Treasure_save("[Scanning]Erase_vpp(32)code4", ERA_VPP.logout[4][dut]);
		Treasure_save("[Scanning]Erase_vpp(32)code5", ERA_VPP.logout[5][dut]);
		Treasure_save("[Scanning]Erase_vpp(32)code9", ERA_VPP.logout[9][dut]);
		Treasure_save("[Scanning]Erase_vpp(32)code10", ERA_VPP.logout[10][dut]);
		Treasure_save("[Scanning]Erase_vpp(32)code11", ERA_VPP.logout[11][dut]);

		Treasure_save("[Scanning]Erase_vpp(128)code0", ERA_VPP2.logout[0][dut]);
		Treasure_save("[Scanning]Erase_vpp(128)code1", ERA_VPP2.logout[1][dut]);
		Treasure_save("[Scanning]Erase_vpp(128)code2", ERA_VPP2.logout[2][dut]);
		Treasure_save("[Scanning]Erase_vpp(128)code3", ERA_VPP2.logout[3][dut]);
		Treasure_save("[Scanning]Erase_vpp(128)code4", ERA_VPP2.logout[4][dut]);
		Treasure_save("[Scanning]Erase_vpp(128)code5", ERA_VPP2.logout[5][dut]);
		Treasure_save("[Scanning]Erase_vpp(128)code9", ERA_VPP2.logout[9][dut]);
		Treasure_save("[Scanning]Erase_vpp(128)code10", ERA_VPP2.logout[10][dut]);
		Treasure_save("[Scanning]Erase_vpp(128)code11", ERA_VPP2.logout[11][dut]);

		Treasure_save("[Scanning]PROG_VPP(32)code0",  PROG_VPP.logout[0][dut]);
		Treasure_save("[Scanning]PROG_VPP(32)code1",  PROG_VPP.logout[1][dut]);
		Treasure_save("[Scanning]PROG_VPP(32)code2",  PROG_VPP.logout[2][dut]);
		Treasure_save("[Scanning]PROG_VPP(32)code3",  PROG_VPP.logout[3][dut]);
		Treasure_save("[Scanning]PROG_VPP(32)code4",  PROG_VPP.logout[4][dut]);
		Treasure_save("[Scanning]PROG_VPP(32)code5",  PROG_VPP.logout[5][dut]);
		Treasure_save("[Scanning]PROG_VPP(32)code9",  PROG_VPP.logout[9][dut]);
		Treasure_save("[Scanning]PROG_VPP(32)code10", PROG_VPP.logout[10][dut]);
		Treasure_save("[Scanning]PROG_VPP(32)code11", PROG_VPP.logout[11][dut]);

		Treasure_save("[Scanning]PROG_VPP(128)code0",  PROG_VPP2.logout[0][dut]);
		Treasure_save("[Scanning]PROG_VPP(128)code1",  PROG_VPP2.logout[1][dut]);
		Treasure_save("[Scanning]PROG_VPP(128)code2",  PROG_VPP2.logout[2][dut]);
		Treasure_save("[Scanning]PROG_VPP(128)code3",  PROG_VPP2.logout[3][dut]);
		Treasure_save("[Scanning]PROG_VPP(128)code4",  PROG_VPP2.logout[4][dut]);
		Treasure_save("[Scanning]PROG_VPP(128)code5",  PROG_VPP2.logout[5][dut]);
		Treasure_save("[Scanning]PROG_VPP(128)code9",  PROG_VPP2.logout[9][dut]);
		Treasure_save("[Scanning]PROG_VPP(128)code10", PROG_VPP2.logout[10][dut]);
		Treasure_save("[Scanning]PROG_VPP(128)code11", PROG_VPP2.logout[11][dut]);

		Treasure_save("[Scanning]PROG_VNN(32)code0",  PROG_VNN.logout[0][dut]);
		Treasure_save("[Scanning]PROG_VNN(32)code1",  PROG_VNN.logout[1][dut]);
		Treasure_save("[Scanning]PROG_VNN(32)code2",  PROG_VNN.logout[2][dut]);
		Treasure_save("[Scanning]PROG_VNN(32)code3",  PROG_VNN.logout[3][dut]);
		Treasure_save("[Scanning]PROG_VNN(32)code4",  PROG_VNN.logout[4][dut]);
		Treasure_save("[Scanning]PROG_VNN(32)code5",  PROG_VNN.logout[5][dut]);
		Treasure_save("[Scanning]PROG_VNN(32)code6",  PROG_VNN.logout[6][dut]);
		Treasure_save("[Scanning]PROG_VNN(32)code7",  PROG_VNN.logout[7][dut]);
		Treasure_save("[Scanning]PROG_VNN(32)code9",  PROG_VNN.logout[9][dut]);
		Treasure_save("[Scanning]PROG_VNN(32)code10", PROG_VNN.logout[10][dut]);
		Treasure_save("[Scanning]PROG_VNN(32)code11", PROG_VNN.logout[11][dut]);
		Treasure_save("[Scanning]PROG_VNN(32)code12", PROG_VNN.logout[12][dut]);
									   
		Treasure_save("[Scanning]PROG_VNN(128)code0",  PROG_VNN2.logout[0][dut]);
		Treasure_save("[Scanning]PROG_VNN(128)code1",  PROG_VNN2.logout[1][dut]);
		Treasure_save("[Scanning]PROG_VNN(128)code2",  PROG_VNN2.logout[2][dut]);
		Treasure_save("[Scanning]PROG_VNN(128)code3",  PROG_VNN2.logout[3][dut]);
		Treasure_save("[Scanning]PROG_VNN(128)code4",  PROG_VNN2.logout[4][dut]);
		Treasure_save("[Scanning]PROG_VNN(128)code5",  PROG_VNN2.logout[5][dut]);
		Treasure_save("[Scanning]PROG_VNN(128)code6",  PROG_VNN2.logout[6][dut]);
		Treasure_save("[Scanning]PROG_VNN(128)code7",  PROG_VNN2.logout[7][dut]);
		Treasure_save("[Scanning]PROG_VNN(128)code9",  PROG_VNN2.logout[9][dut]);
		Treasure_save("[Scanning]PROG_VNN(128)code10", PROG_VNN2.logout[10][dut]);
		Treasure_save("[Scanning]PROG_VNN(128)code11", PROG_VNN2.logout[11][dut]);
		Treasure_save("[Scanning]PROG_VNN(128)code12", PROG_VNN2.logout[12][dut]);
		//VERIFY
		Treasure_save("[Verify]MAIN_BG", Treas_Vrf.Main_bgX32[dut]);
		Treasure_save("[Backup]MAIN_BG", Treas_Vrf.Main_bg_BKP[dut]);

		Treasure_save("[Verify]SDN_BG", Treas_Vrf.Sdn_bgX32[dut]);
		Treasure_save("[Backup]SDN_BG", Treas_Vrf.Sdn_bg_BKP[dut]);

		Treasure_save("[Verify]PVNN(32)", Treas_Vrf.PVNN[dut]);
		Treasure_save("[Verify]PVNN(128)", Treas_Vrf.PVNNX128[dut]);

		Treasure_save("[Verify]PVPP(32)", Treas_Vrf.PVPP[dut]);
		Treasure_save("[Verify]PVPP(128)", Treas_Vrf.PVPPX128[dut]);

		Treasure_save("[Verify]EVPP(32)", Treas_Vrf.EVPP[dut]);
		Treasure_save("[Verify]EVPP(128)", Treas_Vrf.EVPPX128[dut]);
		
		Treasure_save("[Verify]lot_num(hex)", Treas_Vrf.lot_code[dut]);
		Treasure_save("[Backup]lot_num(hex)", Treas_Vrf.lot_bkp[dut]);

		Treasure_save("[Backup]slot_num(hex)", Treas_Vrf.slot_bkp[dut]);

		Treasure_save("[Verify]X_addr", Treas_Vrf.x_orgn[dut]);
		Treasure_save("[Backup]X_addr", Treas_Vrf.x_bkp[dut]);

		Treasure_save("[Verify]Y_addr", Treas_Vrf.y_orgn[dut]);
		Treasure_save("[Backup]Y_addr", Treas_Vrf.y_bkp[dut]);

		Treasure_save("[128]Margin 5V", Treas_Mrg.E1_std_5V[dut]);
		Treasure_save("[128]Margin 1.0V", Treas_Mrg.E1_std_1V[dut]);
		Treasure_save("[128]Margin 1.4V", Treas_Mrg.E1_std_1p4V[dut]);
		Treasure_save("[128]Margin 1.5V", Treas_Mrg.E1_std_1p5V[dut]);
		Treasure_save("[128]Margin 1.6V", Treas_Mrg.E1_std_1p6V[dut]);
		Treasure_save("[128]Margin 1.7V", Treas_Mrg.E1_std_1p7V[dut]);
		Treasure_save("[128]Margin 1.8V", Treas_Mrg.E1_std_1p8V[dut]);

		Treasure_save("[32]Margin 5V",	 Treas_Mrg.E2_std_5V[dut]);
		Treasure_save("[32]Margin 1.0V", Treas_Mrg.E2_std_1V[dut]);
		Treasure_save("[32]Margin 1.4V", Treas_Mrg.E2_std_1p4V[dut]);
		Treasure_save("[32]Margin 1.5V", Treas_Mrg.E2_std_1p5V[dut]);
		Treasure_save("[32]Margin 1.6V", Treas_Mrg.E2_std_1p6V[dut]);
		Treasure_save("[32]Margin 1.7V", Treas_Mrg.E2_std_1p7V[dut]);
		Treasure_save("[32]Margin 1.8V", Treas_Mrg.E2_std_1p8V[dut]);

		Treasure_save("[128]Margin 5V(-3)", Treas_Mrg.E1_spec_5V[0][dut]);
		Treasure_save("[128]Margin 1.0V(-3)", Treas_Mrg.E1_spec_1V[0][dut]);
		Treasure_save("[128]Margin 1.4V(-3)", Treas_Mrg.E1_spec_1p4V[0][dut]);
		Treasure_save("[128]Margin 1.5V(-3)", Treas_Mrg.E1_spec_1p5V[0][dut]);
		Treasure_save("[128]Margin 1.6V(-3)", Treas_Mrg.E1_spec_1p6V[0][dut]);
		Treasure_save("[128]Margin 1.7V(-3)", Treas_Mrg.E1_spec_1p7V[0][dut]);
		Treasure_save("[128]Margin 1.8V(-3)", Treas_Mrg.E1_spec_1p8V[0][dut]);

		Treasure_save("[128]Margin 5V(-6)", Treas_Mrg.E1_spec_5V[1][dut]);
		Treasure_save("[128]Margin 1.0V(-6)", Treas_Mrg.E1_spec_1V[1][dut]);
		Treasure_save("[128]Margin 1.4V(-6)", Treas_Mrg.E1_spec_1p4V[1][dut]);
		Treasure_save("[128]Margin 1.5V(-6)", Treas_Mrg.E1_spec_1p5V[1][dut]);
		Treasure_save("[128]Margin 1.6V(-6)", Treas_Mrg.E1_spec_1p6V[1][dut]);
		Treasure_save("[128]Margin 1.7V(-6)", Treas_Mrg.E1_spec_1p7V[1][dut]);
		Treasure_save("[128]Margin 1.8V(-6)", Treas_Mrg.E1_spec_1p8V[1][dut]);
}
	CString str1;
	str1.Format("D:\\Log\\Treasure\\%s_%s_site%d_CP0.csv", LOT_NUM, WFR_SLOT_ID, site_num());
	char *Path = str1.GetBuffer(str1.GetLength());
	Treasure_Dig(Path);
}



//EFLASH ZX297100 SPECIAL
#define EBM_DATALOG 0

#ifdef need_to_be_delete
void contact_solution()
{
	SoftwareOnlyActiveDutIterator loops;
	while (loops.More())
	{
		DutNum dut = active_dut_get();
		if (result_get(dut) == 0)
		{
			MAIN_BGP.logout[MAIN_BGP.record[dut]][dut] = 999;
		}
	}
}
#endif

void clear_buffer()
{
	MAIN_BGP.Clear_All();
	SDN_BGP.Clear_All();
	VREF.Clear_All();
	ERA_VPP.Clear_All();
	PROG_VPP.Clear_All();
	PROG_VNN.Clear_All();
	OSC.Clear_All();
	REF_C.Clear_All();
	MAIN_BGP2.Clear_All();
	SDN_BGP2.Clear_All();
	VREF2.Clear_All();
	ERA_VPP2.Clear_All();
	PROG_VPP2.Clear_All();
	PROG_VNN2.Clear_All();
	OSC2.Clear_All();
	REF_C2.Clear_All();
}

void config_optrim(long int* op_trim_reg, int i, int locat_b3, int locat_b2, int locat_b1, int locat_b0)
{
	bool bit0, bit1, bit2, bit3;

	if ((i & 8) == 8)	bit3 = 1;
	else			bit3 = 0;

	if ((i & 4) == 4)	bit2 = 1;
	else			bit2 = 0;

	if ((i & 2) == 2) bit1 = 1;
	else			bit1 = 0;

	if ((i & 1) == 1) bit0 = 1;
	else			bit0 = 0;

	shift_register(locat_b0, bit0, op_trim_reg);
	shift_register(locat_b1, bit1, op_trim_reg);
	shift_register(locat_b2, bit2, op_trim_reg);
	shift_register(locat_b3, bit3, op_trim_reg);
}

void MyStartTimer(CString str)
{
	CString str1 = "";
	CString str2 = " Start from:";
	str1 += str;
	str1 += str2;
	str1 += CTime::GetCurrentTime().Format("<COLOR = GREEN>%H:%M:%S<COLOR = BLACK>");
	output(str1);
}

void MyStopTimer(CString str)
{
	CString str1 = "";
	CString str2 = " Stop at:";
	str1 += str;
	str1 += str2;
	str1 += CTime::GetCurrentTime().Format("<COLOR = RED>%H:%M:%S<COLOR = BLACK>");
	output(str1);
}



void ecr_set_for(PinList *pl)
{
	ecr_all_clear();
	ecr_addr_initialize();
	ecr_config_set(numx(), numy(), pl);
}


void judge_test_result(struct buffer temp, double torlerance)
{
	SoftwareOnlyActiveDutIterator Active_Duts_loop_for_judge;
	while (Active_Duts_loop_for_judge.More())
	{
		DutNum dut = active_dut_get();
		if (temp.distance[dut] > torlerance)
		{
			result_set(dut, false);
			MAIN_BGP.distance[dut] = 999;
			SDN_BGP.distance[dut] = 999;
			VREF.distance[dut] = 999;
			ERA_VPP.distance[dut] = 999;
			PROG_VPP.distance[dut] = 999;
			PROG_VNN.distance[dut] = 999;
			OSC.distance[dut] = 999;
			REF_C.distance[dut] = 999;
			MAIN_BGP2.distance[dut] = 999;
			SDN_BGP2.distance[dut] = 999;
			VREF2.distance[dut] = 999;
			ERA_VPP2.distance[dut] = 999;
			PROG_VPP2.distance[dut] = 999;
			PROG_VNN2.distance[dut] = 999;
			OSC2.distance[dut] = 999;
			REF_C2.distance[dut] = 999;
		}
		else 
			result_set(dut, true);
	}
}

void clean_trim_register(long *reg)
{
	reg[0] = 0;
	reg[1] = 0;
	reg[2] = 0;
}


//basic tools
int two(int temp)
{
	int buffer = 1;
	if (temp == 0)
		return 1;
	else//temp = 3
	{
		for (int i = 0; i < temp; i++)   
		{
			buffer = buffer * 2;
		}
		return buffer;
	}
}


//several kinds of initialization
void ecr_addr_initialize()
{
	xmain(0);
	ymain(0);
}

void PointFailure_initialize(PointFailure *buffer, int length)
{
	for (int i = 0; i < length; i++)
	{
		buffer[i].row = 0;
		buffer[i].col = 0;
		buffer[i].data = 0;
	}
}

//EBM setup subroutine 
/*
*
*  Use to save different single value for every different Dut
*  Pay attention to use it with softwareonly***
*
*/
void EBM_save_single_value(long int* reg_pointer, int length, PinList* PL, DutNum dut)
{
	DWordArray EBM_Data, EBM_Read;
	IntArray results;
	//config the EBM
	SoftwareOnlyActiveDutIterator Active_Duts_Loop1;


	EBM_Data.Add(*reg_pointer);
	ebm_column_write(dut, PL, 0x0, length, EBM_Data);

#if EBM_DATALOG/*Read data back from EBM and Compare(FOR DEBUG)*/
	DutPin* PIN;
	SoftwareOnlyActiveDutIterator Active_Duts_Loop2;
	for (int i = 0; pin_info(PL, i, &PIN); i++)
	{
		ebm_column_read(dut, PIN, 0x0, length, EBM_Read);
		output("Dut%d.%s:\t%08X", dut, resource_name(PIN), EBM_Read.GetAt(0));
	}
#endif
	//EBM is a pre increment operation.
	ebm_address_reg_set(t_ebm_start_addr, 16 * 1024 - 1);
}

/*
*
*  Use to save same single value to every Dut
*
*/
void EBM_save_single_value(long int* reg_pointer, int length, PinList* PL)
{
	DWordArray EBM_Data, EBM_Read;
	IntArray results;
	//config the EBM
	SoftwareOnlyActiveDutIterator Active_Duts_Loop1;

	//Store data for EBM
	while (Active_Duts_Loop1.More())
	{
		DutNum dut = active_dut_get();
		EBM_Data.Add(*reg_pointer);
		ebm_column_write(dut, PL, 0x0, length, EBM_Data);
	}
#if EBM_DATALOG/*Read data back from EBM and Compare(FOR DEBUG)*/
	DutPin* PIN;
	SoftwareOnlyActiveDutIterator Active_Duts_Loop2;
	while (Active_Duts_Loop2.More())
	{
		DutNum dut = active_dut_get();
		for (int i = 0; pin_info(PL, i, &PIN); i++)
		{
			ebm_column_read(dut, PIN, 0x0, length, EBM_Read);
			output("Dut%d.%s:\t%08X", dut, resource_name(PIN), EBM_Read.GetAt(0));
		}
	}
#endif
	//EBM is a pre increment operation.
	ebm_address_reg_set(t_ebm_start_addr, 16 * 1024 - 1);
}

/*
*
*ZX297100 special, use to scanning trim code
*
*/
void EBM_setup_for_scan(long int* op_trim_reg, PinList* PL)
{
	DWordArray EBM_Data[12], EBM_Read[12];
	IntArray results;

	//Store data for EBM
	SoftwareOnlyActiveDutIterator Active_Duts_Loop1;
	while (Active_Duts_Loop1.More())
	{
		DutNum dut = active_dut_get();
		EBM_Data[dut].Add(op_trim_reg[0]);
		EBM_Data[dut].Add(op_trim_reg[1]);
		EBM_Data[dut].Add(op_trim_reg[2]);
		ebm_column_write(dut, PL, 0x0, 96, EBM_Data[dut]);
	}

#if EBM_DATALOG//Read data back from EBM and Compare(FOR DEBUG)
	//SoftwareOnlyActiveDutIterator Active_Duts_Loop2;
	//while (Active_Duts_Loop2.More())
	//{
	//	DutNum dut = active_dut_get();
	//	ebm_column_read(dut, eFlash_sio_i, 0x0, 96, EBM_Read[dut]);
	//	output("Dut:%d\t%8x\t%8x\t%8x", dut, EBM_Read[dut].GetAt(0), EBM_Read[dut].GetAt(1), EBM_Read[dut].GetAt(2));
	//}

#endif
	//EBM is a pre increment operation. 
	ebm_address_reg_set(t_ebm_start_addr, 16 * 1024 - 1);
}

void EBM_setup_for_scan(long int* op_trim_reg, PinList* PL, DutNum dut)
{
	DWordArray EBM_Data[12], EBM_Read[12];
	IntArray results;

	//Store data for EBM
	EBM_Data[dut].Add(op_trim_reg[0]);
	EBM_Data[dut].Add(op_trim_reg[1]);
	EBM_Data[dut].Add(op_trim_reg[2]);
	ebm_column_write(dut, PL, 0x0, 96, EBM_Data[dut]);


#if EBM_DATALOG//Read data back from EBM and Compare(FOR DEBUG)
	SoftwareOnlyActiveDutIterator Active_Duts_Loop2;
	while (Active_Duts_Loop2.More())
	{
		DutNum dut = active_dut_get();
		ebm_column_read(dut, eFlash_sio_i, 0x0, 96, EBM_Read[dut]);
		output("Dut:%d\t%8x\t%8x\t%8x", dut, EBM_Read[dut].GetAt(0), EBM_Read[dut].GetAt(1), EBM_Read[dut].GetAt(2));
	}

#endif
	//EBM is a pre increment operation. 
	ebm_address_reg_set(t_ebm_start_addr, 16 * 1024 - 1);
}

/*
*
*  Use to set the trim code which will be saved into device
*
*/
void EBM_setup_for_save(long int* op_trim_reg, PinList* PL)
{
	DWordArray EBM_Data[12], EBM_Read[12];
	IntArray results;

	//Store data for EBM
	SoftwareOnlyActiveDutIterator Active_Duts_Loop1;
	while (Active_Duts_Loop1.More())
	{
		DutNum dut = active_dut_get();
		EBM_Data[dut].Add(op_trim_reg[dut]);
		ebm_column_write(dut, pl_eflash_inputs, 0x0, 32, EBM_Data[dut]);
	}

#if EBM_DATALOG/*Read data back from EBM and Compare(FOR DEBUG)*/
	SoftwareOnlyActiveDutIterator Active_Duts_Loop2;
	while (Active_Duts_Loop2.More())
	{
		DutNum dut = active_dut_get();
		ebm_column_read(dut, eFlash_sio_i, 0x0, 32, EBM_Read[dut]);
		output("Dut:%d\t%08X", dut, EBM_Read[dut].GetAt(0));
	}
#endif
	//EBM is a pre increment operation.
	ebm_address_reg_set(t_ebm_start_addr, 16 * 1024 - 1);
}

/*
*
*	Use to save the address
*
*/
void EBM_save_address(long int EBM_register, PinList* PL)
{
	DWordArray EBM_Data[12], EBM_Read[12];
	IntArray results;
	//config the EBM

	SoftwareOnlyActiveDutIterator Active_Duts_Loop1;
	while (Active_Duts_Loop1.More())
	{
		DutNum dut = active_dut_get();
		EBM_Data[dut].Add(EBM_register);
		ebm_column_write(dut, pl_eflash_inputs, 0x0, 24, EBM_Data[dut]);
	}
	ebm_address_reg_set(t_ebm_start_addr, 16 * 1024 - 1);
}

//optrim calculation subroutines
int judge_location(int temp)
{
	if (temp < 32)		return 0;
	else if (temp < 64)	return 1;
	else if (temp < 96)	return 2;
	else
	{
		output("<COLOR=RED>[ERROR!!]Something wrong happened in optrim");
		return 3;
	}
}

long int address_merge(int y, int x)
{
	long int result;
	long int temp;
	temp = y << numx();
	result = x | temp;
	return result;
}

long int counter_register(int reg, int length)
{
	long int result = 0;
	int mask;
	for (int i = 0; i < length; i++)
	{
		mask = two(i);
		if ((reg & mask) == mask)
			result |= !mask;
		else
			result |= mask;
	}
	return result;
}

long int* shift_register(int locat_x, int bit_x, long int* reg)
{
	long int temp = 1;
	switch (judge_location(locat_x))
	{
	case 0:
		if (bit_x == 1)
		{
			temp = temp << locat_x;
			reg[0] |= temp;
			return reg;
		}
		else
			return reg;
		break;
	case 1:
		if (bit_x == 1)
		{
			temp = temp << (locat_x - 32);
			reg[1] |= temp;
			return reg;
		}
		else
			return reg;
		break;
	case 2:
		if (bit_x == 2)
		{
			temp = temp << (locat_x - 64);
			reg[2] |= temp;
			return reg;
		}
		else
			return reg;
		break;
	}
	return reg;
}

long int shift_register(int locat_x, int bit_x, long int reg)
{
	long int temp = 1;
	if (bit_x == 1)
	{
		temp = temp << locat_x;
		reg |= temp;
		return reg;
	}
	else
		return reg;
}

long int* MSB_modification(long int* op_trim_reg, int length)
{
	long int temp[3];
	long int bit_temp;

	temp[0] = op_trim_reg[0]; temp[1] = op_trim_reg[1]; temp[2] = op_trim_reg[2];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < length; j++)
		{
			bit_temp = two((length - 1) - j);
			if ((temp[i] & bit_temp) == bit_temp)
			{
				op_trim_reg[i] = op_trim_reg[i] | two(j);
			}
			else
			{
				op_trim_reg[i] = op_trim_reg[i] & (~two(j));
			}
		}
	}

	return op_trim_reg;

}

long int MSB_modification(long int op_trim_reg, int length)
{
	long int temp;
	long int bit_temp;
	temp = op_trim_reg;
	for (int j = 0; j < length; j++)
	{
		bit_temp = two((length - 1) - j);
		if ((temp & bit_temp) == bit_temp)
		{
			op_trim_reg = op_trim_reg | two(j);
		}
		else
		{
			op_trim_reg = op_trim_reg & (~two(j));
		}
	}
	temp = op_trim_reg;
	return temp;
}

void raw_optrim(long int* op_trim_reg, int i, int locat_b2, int locat_b1, int locat_b0)
{
	bool bit0, bit1, bit2;
	op_trim_reg[0] = 0;
	op_trim_reg[1] = 0;
	op_trim_reg[2] = 0;

	if ((i & 4) == 4)	bit2 = 1;
	else			bit2 = 0;

	if ((i & 2) == 2) bit1 = 1;
	else			bit1 = 0;

	if ((i & 1) == 1) bit0 = 1;
	else			bit0 = 0;

	shift_register(locat_b0, bit0, op_trim_reg);
	shift_register(locat_b1, bit1, op_trim_reg);
	shift_register(locat_b2, bit2, op_trim_reg);
	//output("<COLOR=BLUE>[%d]reg1:%08x\t reg2:%08x\t reg3:%08x ", i, op_trim_reg[0], op_trim_reg[1], op_trim_reg[2]);
}

void raw_optrim(long int* op_trim_reg, int i, int locat_b3, int locat_b2, int locat_b1, int locat_b0)
{
	bool bit0, bit1, bit2, bit3;
	op_trim_reg[0] = 0;
	op_trim_reg[1] = 0;
	op_trim_reg[2] = 0;

	if ((i & 8) == 8)	bit3 = 1;
	else			bit3 = 0;

	if ((i & 4) == 4)	bit2 = 1;
	else			bit2 = 0;

	if ((i & 2) == 2) bit1 = 1;
	else			bit1 = 0;

	if ((i & 1) == 1) bit0 = 1;
	else			bit0 = 0;

	shift_register(locat_b0, bit0, op_trim_reg);
	shift_register(locat_b1, bit1, op_trim_reg);
	shift_register(locat_b2, bit2, op_trim_reg);
	shift_register(locat_b3, bit3, op_trim_reg);
	//output("<COLOR=BLUE>[%d]reg1:%08x\t reg2:%08x\t reg3:%08x ", i, op_trim_reg[0], op_trim_reg[1], op_trim_reg[2]);

}

void raw_optrim_MSB(long int* op_trim_reg, int i, int locat_b2, int locat_b1, int locat_b0)
{
	bool bit0, bit1, bit2;
	op_trim_reg[0] = 0;
	op_trim_reg[1] = 0;
	op_trim_reg[2] = 0;

	if ((i & 4) == 4)	bit2 = 1;
	else			bit2 = 0;

	if ((i & 2) == 2) bit1 = 1;
	else			bit1 = 0;

	if ((i & 1) == 1) bit0 = 1;
	else			bit0 = 0;

	shift_register(locat_b0, bit0, op_trim_reg);
	shift_register(locat_b1, bit1, op_trim_reg);
	shift_register(locat_b2, bit2, op_trim_reg);
	//output("<COLOR=BLUE>[%d]reg1:%08x\t reg2:%08x\t reg3:%08x ", i, op_trim_reg[0], op_trim_reg[1], op_trim_reg[2]);
	MSB_modification(op_trim_reg, 32);
}

void raw_optrim_MSB(long int* op_trim_reg, int i, int locat_b3, int locat_b2, int locat_b1, int locat_b0)
{
	bool bit0, bit1, bit2, bit3;
	op_trim_reg[0] = 0;
	op_trim_reg[1] = 0;
	op_trim_reg[2] = 0;

	if ((i & 8) == 8)	bit3 = 1;
	else			bit3 = 0;

	if ((i & 4) == 4)	bit2 = 1;
	else			bit2 = 0;

	if ((i & 2) == 2) bit1 = 1;
	else			bit1 = 0;

	if ((i & 1) == 1) bit0 = 1;
	else			bit0 = 0;

	shift_register(locat_b0, bit0, op_trim_reg);
	shift_register(locat_b1, bit1, op_trim_reg);
	shift_register(locat_b2, bit2, op_trim_reg);
	shift_register(locat_b3, bit3, op_trim_reg);
	//output("<COLOR=BLUE>[%d]reg1:%08x\t reg2:%08x\t reg3:%08x ", i, op_trim_reg[0], op_trim_reg[1], op_trim_reg[2]);
	MSB_modification(op_trim_reg, 32);
	//output("<COLOR=RED>[%d]reg1:%08x\t reg2:%08x\t reg3:%08x ", i, op_trim_reg[0], op_trim_reg[1], op_trim_reg[2]);
}

long int complex_optrim(int i, int locat_b3, int locat_b2, int locat_b1, int locat_b0)
{
	DutNum dut = active_dut_get();
	bool bit0, bit1, bit2, bit3;

	long int result = 0;
	long int op_trim_reg = 0;
	long int _op_trim_reg = !op_trim_reg;
	op_trim_reg = 0;
	if ((i & 8) == 8)	bit3 = 1;
	else				bit3 = 0;

	if ((i & 4) == 4)	bit2 = 1;
	else			bit2 = 0;

	if ((i & 2) == 2) bit1 = 1;
	else			bit1 = 0;

	if ((i & 1) == 1) bit0 = 1;
	else			bit0 = 0;

	op_trim_reg = shift_register(locat_b0, bit0, op_trim_reg);
	op_trim_reg = shift_register(locat_b1, bit1, op_trim_reg);
	op_trim_reg = shift_register(locat_b2, bit2, op_trim_reg);
	op_trim_reg = shift_register(locat_b3, bit3, op_trim_reg);
	//output("<COLOR=BLUE>[DUT%d] trim:%08x ", dut, op_trim_reg);

	_op_trim_reg = counter_register(op_trim_reg, 16);

	result = _op_trim_reg << 16;
	result |= op_trim_reg;
	//output("<COLOR=BLUE>[DUT%d] !trim:%08x ", dut+1, result);
	return result;
}

long int spec_optrim_MSB(int i, int locat_b3, int locat_b2, int locat_b1, int locat_b0)
{
	DutNum dut = active_dut_get();
	bool bit0, bit1, bit2, bit3;

	long int result = 0;
	long int op_trim_reg = 0x02;
	long int _op_trim_reg = 0;

	if ((i & 8) == 8)	bit3 = 1;
	else				bit3 = 0;

	if ((i & 4) == 4)	bit2 = 1;
	else			bit2 = 0;

	if ((i & 2) == 2) bit1 = 1;
	else			bit1 = 0;

	if ((i & 1) == 1) bit0 = 1;
	else			bit0 = 0;

	op_trim_reg = shift_register(locat_b0, bit0, op_trim_reg);
	op_trim_reg = shift_register(locat_b1, bit1, op_trim_reg);
	op_trim_reg = shift_register(locat_b2, bit2, op_trim_reg);
	op_trim_reg = shift_register(locat_b3, bit3, op_trim_reg);
	//output("<COLOR=BLUE>[DUT%d] trim:%08x ", dut, op_trim_reg);

	_op_trim_reg = counter_register(op_trim_reg, 16);

	result = _op_trim_reg << 16;
	result |= op_trim_reg;
	result = MSB_modification(result, 32);
	//output("<COLOR=BLUE>[DUT%d] trim:%08x ", dut+1, result);
	return result;
}

long int complex_optrim_MSB(int i, int locat_b3, int locat_b2, int locat_b1, int locat_b0)
{
	DutNum dut = active_dut_get();
	bool bit0, bit1, bit2, bit3;

	long int result = 0;
	long int op_trim_reg = 0;
	long int _op_trim_reg = 0;
	op_trim_reg = 0;
	if ((i & 8) == 8)	bit3 = 1;
	else				bit3 = 0;

	if ((i & 4) == 4)	bit2 = 1;
	else			bit2 = 0;

	if ((i & 2) == 2) bit1 = 1;
	else			bit1 = 0;

	if ((i & 1) == 1) bit0 = 1;
	else			bit0 = 0;

	op_trim_reg = shift_register(locat_b0, bit0, op_trim_reg);
	op_trim_reg = shift_register(locat_b1, bit1, op_trim_reg);
	op_trim_reg = shift_register(locat_b2, bit2, op_trim_reg);
	op_trim_reg = shift_register(locat_b3, bit3, op_trim_reg);
	//output("<COLOR=BLUE>[DUT%d] trim:%08x ", dut, op_trim_reg);

	_op_trim_reg = counter_register(op_trim_reg, 16);

	result = _op_trim_reg << 16;
	result |= op_trim_reg;
	result = MSB_modification(result, 32);
	//output("<COLOR=BLUE>[DUT%d] trim:%08x ", dut+1, result);
	return result;
}


//partest setup subroutine
void Mianbgp_partset()
{
	dpo_hv_voltage_set(0 V, pl_dpohv);
	dpo_hv_disconnect(pl_dpohv);
	dpo_hv_vrange_set(t_dpo_default_hv_vrange);
	Delay(10 MS);
	dpo_hv_connect(pl_dpohv);
	dpo_hv_ipar_force_set(0 A, pl_vref_test);
	dpo_hv_vpar_high(1.32 V, pl_vref_test);
	dpo_hv_vpar_low(1.08 V, pl_vref_test);
	dpo_hv_vclamp_set(7 V, 0 V, pl_vref_test);
	partime(10 MS);
	measure(true);
}

void Sdnbgp_partset()
{
	dpo_hv_voltage_set(0 V, pl_dpohv);
	dpo_hv_disconnect(pl_dpohv);
	dpo_hv_vrange_set(t_dpo_default_hv_vrange);
	Delay(10 MS);
	dpo_hv_connect(pl_dpohv);
	dpo_hv_ipar_force_set(0 A, pl_vref_test);
	dpo_hv_vpar_high(1.32 V, pl_vref_test);
	dpo_hv_vpar_low(1.08 V, pl_vref_test);
	dpo_hv_vclamp_set(7 V, 0 V, pl_vref_test);
	partime(10 MS);
	measure(true);
}

void Program_Vnn_partset()
{
	dpo_hv_voltage_set(0 V, pl_dpohv);
	dpo_hv_disconnect(pl_dpohv);
	dpo_hv_vrange_set(t_dpo_negative_hv_vrange);
	Delay(10 MS);
	dpo_hv_connect(pl_dpohv);
	dpo_hv_ipar_force_set(0 A, pl_vnn);
	dpo_hv_vpar_high(-3 V, pl_vnn);
	dpo_hv_vpar_low(-7 V, pl_vnn);
	dpo_hv_vclamp_set(0 V, -14 V, pl_vnn);
	partime(10 MS);
	measure(true);
}

void Program_Vpp_partset()
{
	dpo_hv_voltage_set(0 V, pl_dpohv);
	dpo_hv_disconnect(pl_dpohv);
	dpo_hv_vrange_set(t_dpo_default_hv_vrange);
	Delay(10 MS);
	dpo_hv_connect(pl_dpohv);
	dpo_hv_ipar_force_set(0 A, pl_vpp);
	dpo_hv_vpar_high(12 V, pl_vpp);
	dpo_hv_vpar_low(9 V, pl_vpp);
	dpo_hv_vclamp_set(14 V, 0 V, pl_vpp);
	partime(10 MS);
	measure(true);
}

void Erase_Vpp_partest()
{
	dpo_hv_voltage_set(0 V, pl_dpohv);
	dpo_hv_disconnect(pl_dpohv);
	dpo_hv_vrange_set(t_dpo_default_hv_vrange);
	Delay(10 MS);
	dpo_hv_connect(pl_dpohv);
	dpo_hv_ipar_force_set(0 A, pl_vpp);
	dpo_hv_vpar_high(12 V, pl_vpp);
	dpo_hv_vpar_low(9 V, pl_vpp);
	dpo_hv_vclamp_set(14 V, 0 V, pl_vpp);
	partime(10 MS);
	measure(true);
}

