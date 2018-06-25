#include "tester.h"

// *********************************************
// *****  Sequence and Binning Table file  *****
// *********************************************

SEQUENCE_TABLE(Final_Test)
{
	SEQUENCE_TABLE_INIT	
		CALL(tb_BGTrim_all_test)
		CALL(tb_FlashTrimming_PG_VPP_test_Lvcc)
	

	BIN(pass_bin,								STOP);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	BINL(Continuity_Neg_fail,                    Continuity_Neg_bin,             STOP);
	BINL(Continuity_Pos_fail,                    Continuity_Pos_bin,             STOP);
	BINL(Continuity_dps_fail,                    Continuity_dps_bin,             STOP);
	BINL(Continuity_hv_fail,                     Continuity_hv_bin,              STOP);
	BINL(Continuity_dpo_fail,                    Continuity_dpo_bin,             STOP);
	BINL(Continuity_dpohv_fail,                  Continuity_dpohv_bin,           STOP);
	BINL(leakage_low_fail,                       leakage_low_bin,                STOP);
	BINL(leakage_high_fail,                      leakage_high_bin,               STOP);
										         
										         
	BINL(SOC_Poweron_fail,                       SOC_Poweron_bin,                      STOP);
	BINL(Chip_Erase_HVcc_fail,                   Chip_Erase_HVcc_bin,                  STOP);
	BINL(ByteRd_All1_HVcc_fail,                  ByteRd_All1_HVcc_bin,                 STOP);
	BINL(ByteRd_All1_LVcc_fail,                  ByteRd_All1_LVcc_bin,                 STOP);
	BINL(Gang_program_CKBD_HVcc_fail,            Gang_program_CKBD_HVcc_bin,           STOP);
	BINL(RD_CKBD_HVcc_fail,                      RD_CKBD_HVcc_bin,                     STOP);
	BINL(RD_CKBD_LVcc_fail,                      RD_CKBD_LVcc_bin,                     STOP);
	BINL(Gang_program_ICKBD_HVcc_fail,           Gang_program_ICKBD_HVcc_bin,          STOP);

	BINL(RDAll0_HVcc_fail,                       RDAll0_HVcc_bin,                      STOP);
	BINL(RDALL0_LVcc_fail,                       RDALL0_LVcc_bin,                      STOP);
	BINL(Ext_Chip_Erase_LVcc_0P6ms_fail,         Ext_Chip_Erase_LVcc_0P6ms_bin,        STOP);
	BINL(Margin_RdAll1_HVcc_fail,                Margin_RdAll1_HVcc_bin,               STOP);
	BINL(Margin_RdAll1_LVcc_fail,                Margin_RdAll1_LVcc_bin,               STOP);
	BINL(Byte_Program_Diagonal_SVcc_fail,        Byte_Program_Diagonal_SVcc_bin,       STOP);
	BINL(Read_Diagonal_SVcc_fail,                Read_Diagonal_SVcc_bin,               STOP);
	
	BINL(Program_55_1st_row_SVcc_fail,           Program_55_1st_row_SVcc_bin,          STOP);
	BINL(Read55_1st_row_LVcc_fail,               Read55_1st_row_LVcc_bin,              STOP);
	BINL(Read55_1st_row_HVcc_fail,               Read55_1st_row_HVcc_bin,              STOP);
	BINL(Program_AA_2nd_row_SVcc_fail,           Program_AA_2nd_row_SVcc_bin,          STOP);
	BINL(ReadAA_2nd_row_HVcc_fail,               ReadAA_2nd_row_HVcc_bin,              STOP);
	BINL(ReadAA_2nd_row_LVcc_fail,               ReadAA_2nd_row_LVcc_bin,              STOP);
	BINL(Sec0_erase_fail,                        Sec0_erase_bin,                       STOP);
	BINL(SG_Stress_HVcc_1sec_fail,               SG_Stress_HVcc_1sec_bin,              STOP);
	BINL(BL_Stress_Even_HVcc_1sec_fail,          BL_Stress_Even_HVcc_1sec_bin,         STOP);
	BINL(Gang_CKBD_Chip_HVcc_8_times_fail,       Gang_CKBD_Chip_HVcc_8_times_bin,      STOP);
    BINL(GangP_CKBD_Whole_HVcc_2_times_fail,     GangP_CKBD_Whole_HVcc_2_times_bin,    STOP);
	BINL(Read_CKBD1_WholeChip_HVcc_fail,         Read_CKBD1_WholeChip_HVcc_bin,        STOP);
	BINL(Read_CKBD0_WholeChip_LVcc_fail,         Read_CKBD0_WholeChip_LVcc_bin,        STOP);
	BINL(GangP_CKBD_Whole_HVcc_4_times_fail,     GangP_CKBD_Whole_HVcc_4_times_bin,    STOP);



	BINL(Gang_ICKBD_Chip_HVcc_8_times_fail,      Gang_ICKBD_Chip_HVcc_8_times_bin,        STOP);
																				          
	BINL(RD_ICKBD_HVcc_fail,                     RD_ICKBD_HVcc_bin,                       STOP);
	BINL(RD_ICKBD_LVcc_fail,                     RD_ICKBD_LVcc_bin,                       STOP);																		          
	BINL(GangP_ICKBD_Whole_HVcc_2_times_fail,    GangP_ICKBD_Whole_HVcc_2_times_bin,      STOP);
	BINL(Read_ICKBD1_WholeChip_HVcc_fail,        Read_ICKBD1_WholeChip_HVcc_bin,          STOP);
	BINL(Read_ICKBD0_WholeChip_LVcc_fail,        Read_ICKBD0_WholeChip_LVcc_bin,          STOP);
	//BINL(GangP_ICKBD_Whole_HVcc_1_times_fail,  GangP_ICKBD_Whole_HVcc_1_times_bin,      STOP);
	BINL(GangP_ICKBD_Whole_HVcc_4_times_fail,    GangP_ICKBD_Whole_HVcc_4_times_bin,      STOP);
	BINL(Sector_erase_whole_chip_LVcc_fail,      Sector_erase_whole_chip_LVcc_bin,        STOP);
    BINL(Byte_Program_All0_LVcc_fail,            Byte_Program_All0_LVcc_bin,              STOP);
	BINL(Ext_Sector_Erase_Sec0_LVcc_fail,        Ext_Sector_Erase_Sec0_LVcc_bin,          STOP);
	BINL(Byte_Read_All1_Sec0_HVcc_fail,            Byte_Read_All1_Sec0_HVcc_bin,          STOP);
	BINL(Byte_Read_All0_Except_Sec0_LVcc_fail,     Byte_Read_All0_Except_Sec0_LVcc_bin,   STOP);
	BINL(Margin_read_All0_Lvcc_Except_Sec0_fail,   Margin_read_All0_Lvcc_Except_Sec0_bin, STOP);
	BINL(Write_CP1_pass_code_fail,                 Write_CP1_pass_code_bin,               STOP);
	BINL(Verify_CP1_pass_code_fail,                Verify_CP1_pass_code_bin,              STOP);

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//            bin name										                hbin  sbin
TEST_BIN(pass_bin)					                    { process_test_results(current_test_bin, 1, 1, PASS); }

TEST_BIN(Continuity_Neg_bin)		                    { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Continuity_Pos_bin)		                    { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Continuity_dps_bin)		                    { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Continuity_hv_bin)		                        { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Continuity_dpo_bin)		                    { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Continuity_dpohv_bin)		                    { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(leakage_low_bin)		                        { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(leakage_high_bin)		                        { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(SOC_Poweron_bin)                               { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Chip_Erase_HVcc_bin)                           { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(ByteRd_All1_HVcc_bin)                          { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(ByteRd_All1_LVcc_bin)                          { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Gang_program_CKBD_HVcc_bin)                    { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(RD_CKBD_HVcc_bin)                              { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(RD_CKBD_LVcc_bin)                              { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Gang_program_ICKBD_HVcc_bin)                   { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(RDAll0_HVcc_bin)                               { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(RDALL0_LVcc_bin)                               { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Ext_Chip_Erase_LVcc_0P6ms_bin)                 { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Margin_RdAll1_HVcc_bin)                        { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Margin_RdAll1_LVcc_bin)                        { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Byte_Program_Diagonal_SVcc_bin)                { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Read_Diagonal_SVcc_bin)                        { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Program_55_1st_row_SVcc_bin)                   { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Read55_1st_row_LVcc_bin)                       { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Read55_1st_row_HVcc_bin)                       { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Program_AA_2nd_row_SVcc_bin)                   { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(ReadAA_2nd_row_HVcc_bin)                       { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(ReadAA_2nd_row_LVcc_bin)                       { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Sec0_erase_bin)                                { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(SG_Stress_HVcc_1sec_bin)                       { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(BL_Stress_Even_HVcc_1sec_bin)                  { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Gang_CKBD_Chip_HVcc_8_times_bin)               { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(GangP_CKBD_Whole_HVcc_2_times_bin)             { process_test_results(current_test_bin, 7, 70, FAIL); }													    
TEST_BIN(Read_CKBD1_WholeChip_HVcc_bin)                 { process_test_results(current_test_bin, 7, 70, FAIL); }										                
TEST_BIN(Read_CKBD0_WholeChip_LVcc_bin)                 { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(GangP_CKBD_Whole_HVcc_4_times_bin)             { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Gang_ICKBD_Chip_HVcc_8_times_bin)              { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(RD_ICKBD_HVcc_bin)                             { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(RD_ICKBD_LVcc_bin)                             { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(GangP_ICKBD_Whole_HVcc_2_times_bin)            { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Read_ICKBD1_WholeChip_HVcc_bin)                { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Read_ICKBD0_WholeChip_LVcc_bin)                { process_test_results(current_test_bin, 7, 70, FAIL); }
//TEST_BIN(GangP_ICKBD_Whole_HVcc_1_times_bin)            { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(GangP_ICKBD_Whole_HVcc_4_times_bin)            { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Sector_erase_whole_chip_LVcc_bin)              { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Byte_Program_All0_LVcc_bin)                    { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Ext_Sector_Erase_Sec0_LVcc_bin)                { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Byte_Read_All1_Sec0_HVcc_bin)                  { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Byte_Read_All0_Except_Sec0_LVcc_bin)           { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Margin_read_All0_Lvcc_Except_Sec0_bin)         { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Write_CP1_pass_code_bin)                       { process_test_results(current_test_bin, 7, 70, FAIL); }
TEST_BIN(Verify_CP1_pass_code_bin)                      { process_test_results(current_test_bin, 7, 70, FAIL); }