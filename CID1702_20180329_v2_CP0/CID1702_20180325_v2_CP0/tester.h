// *************************
// ***** tester.h file *****
// *************************
#include "TestProgApp/public.h"  // moved above #include <afxwin.h> for conversion MSDev 6.0 -> MSDev 2013

#include <afxwin.h>
// from MSDev 6.0, removed for MSDev 2013:  #pragma warning( disable: 4244 )	// conversion from const double to float

#include "protos.h"
#include "pin_lists.h"
#include "fdatalog.h"
#include "timer.h"
#include "driver.h"
#include "User_Var.h"
#include "TestTimer.h"
#include "global.h"
#include "patcom_generated_includes.h"

#define VERBOSE 1
extern DWORD *ebm_dma_data_f;
extern DWORD *ebm_dma_data_l;
extern int ebm_dma_container_f;
extern int ebm_dma_container_l;
/////////////////////////////////////
void BG_ebm_dma(void);
void VPPVNN_ebm_dma(void);
void VDEL_ebm_dma(void);
void OSC_ebm_dma(void);
/////////////////////////////////////
///////////////BGTrim///////////
static CString global_path;
extern double BGTrim_voltage[16][64];//max_dut() can be use?
extern double BGTrim_compresult[16][64];
extern int BGTrim_data[16];//multi dut.42
/////////////////////////////////
extern int OSC_compare_data[16][89];//get fre value by LEC_Compare
extern int OSC_Trim_data[16];
extern double VR16Trim_voltage[16];
/////////////////////////////////
//extern double VDELTrim_voltage[16];
extern CArray<IntArray, IntArray>VDEL_compare_data;  // Make MSDN CArray which has bounds checking.
//extern int VDEL_compare_data[42][15];
extern IntArray VDELTrim_data;
/////////////VPPTrim///////////
extern double PGVPPTrim_voltage[16][16];//42duts
extern double FlashVPPTrim_compresult[16][16];
extern int	VPPTrim_data[16];
//////////////////////////////////////
extern double FlashVNNTrim_voltage[16][16];
extern double FlashVNNTrim_compresult[16][16];
extern int	VNNTrim_data[16];
/////////////////////////////////////// 
//#define SumDut_1
#define SumDut_16//
#define display_datalog
///////////////////////////////////
void  get_value(int tester_resouce);
void  BG_save_trim_value(int trim_nuber);
void  VR16_save_trim_value(double trim_nuber);
void  PGVPP_save_trim_value(int trim_number);
void  ERVPP_save_trim_value(int trim_number);
void  PGVNN_save_trim_value(int trim_number);
void  ERVNN_save_trim_value(int trim_number);
//////////////////////////////////////////
void BGTrim_loop(int BGTrim_data);
void OSCTrim_loop(int OSCTrim_data);
void OSCwrite_ebm_data(void);
void VDELTrim_loop(int VEDLTrim_data);
void VPPTrim_loop(int VPPTrim_data);
void VNNTrim_loop(int VPPTrim_data);
///////////////////////////////////////////
void BG_write_trim_data();
void VPPVNN_write_data_EBM(void);//write data to ebm
void OSC_write_trim_data(int dut);
void VDEL_write_trim_data();
/////////////////every_any////////////////////////
void LEC_Compare(int trim_number);
void relay_loop_trim(int relay);
void relay_loop_measurement(int relay);
void relay_loop(int relay);
/////////////////////tester_ebm///////////////
void EBM_all_clear(void);
void WrEBM_1IO(Int64Array &_ebmBuf, PinList *pl_EBM_1, int eAddr, int WrNBit);
void WrEBM_func(int eArray[], int _Size, PinList *pl_EBM_1, int eAddr);
///////////////////////////////////
# define eSize1 sizeof(eArray1)/sizeof(eArray1[0])
///////////////////////////////////
EXTERN_UINT64_VARIABLE(ui64v_startmask);
EXTERN_INT_VARIABLE(iv_count);
