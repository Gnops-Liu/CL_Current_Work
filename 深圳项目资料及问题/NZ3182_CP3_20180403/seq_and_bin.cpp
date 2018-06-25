#include "tester.h"
//#define SQC_ONLY_READ
// *********************************************
// *****  Sequence and Binning Table file  *****
// *********************************************
//------------------------------------------------------------------------------------------------------------------
//extern void process_test_results(TestBin* current_test_bin, int bin_num, int int_bin);

TEST_BIN(PASS_BIN)			{ process_test_results(current_test_bin, 1, 1, PASS); }
TEST_BIN(BIN2)				{ process_test_results(current_test_bin, 2, 2, FAIL); }
TEST_BIN(BIN3)				{ process_test_results(current_test_bin, 3, 3, FAIL); }
TEST_BIN(BIN4)				{ process_test_results(current_test_bin, 4, 4, FAIL); }
TEST_BIN(BIN5)				{ process_test_results(current_test_bin, 5, 5, FAIL); }
TEST_BIN(BIN6)				{ process_test_results(current_test_bin, 6, 6, FAIL); }
TEST_BIN(BIN7)				{ process_test_results(current_test_bin, 7, 7, FAIL); }
TEST_BIN(BIN8)				{ process_test_results(current_test_bin, 8, 8, FAIL); }
TEST_BIN(BIN9)				{ process_test_results(current_test_bin, 9, 9, FAIL); }
TEST_BIN(BIN10)				{ process_test_results(current_test_bin, 10, 10, FAIL); }
TEST_BIN(BIN11)				{ process_test_results(current_test_bin, 11, 11, FAIL); }
TEST_BIN(BIN12)				{ process_test_results(current_test_bin, 12, 12, FAIL); }
TEST_BIN(BIN13)				{ process_test_results(current_test_bin, 13, 13, FAIL); }
TEST_BIN(BIN14)				{ process_test_results(current_test_bin, 14, 14, FAIL); }
TEST_BIN(BIN15)				{ process_test_results(current_test_bin, 15, 15, FAIL); }
TEST_BIN(BIN16)				{ process_test_results(current_test_bin, 16, 16, FAIL); }
TEST_BIN(BIN17)				{ process_test_results(current_test_bin, 17, 17, FAIL); }
TEST_BIN(BIN18)				{ process_test_results(current_test_bin, 18, 18, FAIL); }
TEST_BIN(BIN19)				{ process_test_results(current_test_bin, 19, 19, FAIL); }
TEST_BIN(BIN20)				{ process_test_results(current_test_bin, 20, 18, FAIL); }
TEST_BIN(BIN21)				{ process_test_results(current_test_bin, 21, 19, FAIL); }
TEST_BIN(BIN22)				{ process_test_results(current_test_bin, 22, 19, FAIL); }
TEST_BIN(BIN23)				{ process_test_results(current_test_bin, 23, 19, FAIL); }
TEST_BIN(BIN24)				{ process_test_results(current_test_bin, 24, 19, FAIL); }
TEST_BIN(BIN25)				{ process_test_results(current_test_bin, 25, 19, FAIL); }
TEST_BIN(BIN26)				{ process_test_results(current_test_bin, 26, 19, FAIL); }
TEST_BIN(BIN27)				{ process_test_results(current_test_bin, 27, 19, FAIL); }
TEST_BIN(BIN28)				{ process_test_results(current_test_bin, 28, 20, FAIL); }
TEST_BIN(BIN29)				{ process_test_results(current_test_bin, 29, 20, FAIL); }
TEST_BIN(BIN30)				{ process_test_results(current_test_bin, 30, 20, FAIL); }
TEST_BIN(BIN31)				{ process_test_results(current_test_bin, 31, 21, FAIL); }


SEQUENCE_TABLE(NZ3183_CP3)
{
	SEQUENCE_TABLE_INIT

		// These two test blocks are just samples
		//CALL( message )
		//CALL( dialogs )
		TEST(tb_OS,									 NEXT,		 l_BIN17)
		TEST(tb_Enter_Eot,							 NEXT,		 l_BIN18)
		TEST(tb_Off_Margin_Read_Array_FF_Std,		 NEXT,		 l_BIN20)
		TEST(tb_VDDLDO_Trim,						 NEXT,		 l_BIN21)
		TEST(tb_VDDLDO_1D8_Trim,					 NEXT,		 l_BIN21)
		TEST(tb_Vref_Trim,							 NEXT,		 l_BIN22)
		TEST(tb_OSC2M_Trim,							 NEXT,		 l_BIN23)
		TEST(tb_ADC_Test,							 NEXT,		 l_BIN24)
		TEST(tb_TS_Test1,							 NEXT,		 l_BIN25)
		TEST(tb_TS_Test2,							 NEXT,		 l_BIN26)
		TEST(tb_IP_Trim_Write_Test,					 NEXT,		 l_BIN27)
		
		TEST(tb_load_ucode,				   			 NEXT,		 l_BIN28)
		TEST(tb_idd_ramist,							 NEXT,		 l_BIN29)
		TEST(tb_Istand_Test,						 NEXT,		 l_BIN30)
		TEST(tb_Write_CP3_GDFLG_Test,				 NEXT,		 l_BIN31)
		
		//TEST(tb_DDAC_01,			NEXT, l_BIN9)
		//TEST(tb_SDC_03,				NEXT, l_BIN9)
		//TEST(tb_DISP12_02,			NEXT, l_BIN11)
		//TEST(tb_DISP13_06,			NEXT, l_BIN11)
		//TEST(tb_DISP14_06,			NEXT, l_BIN11)
		//TEST(tb_LVDWDT_03,			NEXT, l_BIN12)
		//TEST(tb_ADC_06,				NEXT, l_BIN12)
		//TEST(tb_USB_01,				NEXT, l_BIN13)
		//TEST(tb_PLL_02,				NEXT, l_BIN14)
		//TEST(tb_IRTC_01,			NEXT, l_BIN15)
		//TEST(tb_HTC_6M5,			NEXT, l_BIN16)
		//TEST(tb_ADAC_AMUX_02,		NEXT, l_BIN17)
		//TEST(tb_ADAC_LHRL_02,		NEXT, l_BIN17)
		//TEST(tb_ADAC_LLRH_02,		NEXT, l_BIN17)
		//TEST(tb_LOFC_03,			NEXT, l_BIN18)
		//TEST(tb_55aa_isp_01,		NEXT, l_BIN19)
		//TEST(tb_55aa_isr_01,		NEXT, l_BIN24)
		//TEST(tb_55aa_isr_nor_01,	NEXT, l_BIN25)
		STOP(PASS_BIN)



		BINL(l_BIN2,  BIN2, STOP)
		BINL(l_BIN3,  BIN3, STOP)
		BINL(l_BIN4,  BIN4, STOP)
		BINL(l_BIN5,  BIN5, STOP)
		BINL(l_BIN6,  BIN6, STOP)
		BINL(l_BIN7,  BIN7, STOP)
		BINL(l_BIN8,  BIN8, STOP)
		BINL(l_BIN9,  BIN9, STOP)
		BINL(l_BIN10, BIN10, STOP)
		BINL(l_BIN11, BIN11, STOP)
		BINL(l_BIN12, BIN12, STOP)
		BINL(l_BIN13, BIN13, STOP)
		BINL(l_BIN14, BIN14, STOP)
		BINL(l_BIN15, BIN15, STOP)
		BINL(l_BIN16, BIN16, STOP)
		BINL(l_BIN17, BIN17, STOP)
		BINL(l_BIN18, BIN18, STOP)
		BINL(l_BIN19, BIN19, STOP)
		BINL(l_BIN20, BIN20, STOP)
		BINL(l_BIN21, BIN21, STOP)
		BINL(l_BIN22, BIN22, STOP)
		BINL(l_BIN23, BIN23, STOP)
		BINL(l_BIN24, BIN24, STOP)
		BINL(l_BIN25, BIN25, STOP)
		BINL(l_BIN26, BIN26, STOP)
		BINL(l_BIN27, BIN27, STOP)
		BINL(l_BIN28, BIN28, STOP)
		BINL(l_BIN29, BIN29, STOP)
		BINL(l_BIN30, BIN30, STOP)
		BINL(l_BIN31, BIN31, STOP)


}
