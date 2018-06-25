#include "stdafx.h"
#include "AB003_J_4S_V04_userprog.h"
/*=========================================
 |   Devolop : zhangwei                   |
 |   Version : AB003_J_4S_V04             |
 |   Date    :                            |
 ==========================================*/

bool bPass[MAX_TESTING_SITE];

	long INIT_ST=0,INIT_SP;
	long VERSION8_ST,VERSION8_SP;
	long SLEEP_ST,SLEEP_SP;
	long PORT_ST,PORT_SP;
	long ROMJ_ST,ROMJ_SP;
	long RAM_ST,RAM_SP;
	long BLANKCHK_ST,BLANKCHK_SP;
	long AUDEC_ST,AUDEC_SP;
	long CPU_ST,CPU_SP;
	long PERI_ST,PERI_SP;
	long CLK_RST_LPWR_ST,CLK_RST_LPWR_SP;
	long DDAC_ST,DDAC_SP;
	long SDC_ST,SDC_SP;
	long DISP12_ST,DISP12_SP;
	long DISP13_ST,DISP13_SP;
	long DISP14_ST,DISP14_SP;
	long LVDWDT_ST,LVDWDT_SP;
	long ADC_ST,ADC_SP;
	long USB_ST,USB_SP;
	long PLL_ST,PLL_SP;
	long IRTC_ST,IRTC_SP;
	long HTC_ST,HTC_SP;
	long ADAC_AMUX_ST,ADAC_AMUX_SP;
	long ADAC_LHRL_ST,ADAC_LHRL_SP;
	long ADAC_LLRH_ST,ADAC_LLRH_SP;
	long LOFC_ST,LOFC_SP;

	double vddio[8]={0},vdd[8]={0},avdd_hp[8]={0};
	double p12[8]={0},p16[8]={0},p17[8]={0},p30[8]={0},p31[8]={0},p33[8]={0};
	double vcm[8]={0},p23[8]={0},p24[8]={0},p25[8]={0},p26[8]={0},p27[8]={0};
	double dacl_lhrl[8]={0},dacr_lhrl[8]={0};
	double dacl_llrh[8]={0},dacr_llrh[8]={0};

	int i;
	int nCurActiveSite[8]={0,0,0,0,0,0,0,0};
	int nX[8],nY[8];
	double gpib_x[8],gpib_y[8];

	void get_gpib_xy(void);

void System_Init(void)
{
   //<--- load pattern
	INIT_SP=peb.LoadPattern(INIT_ST,"INIT.PTN"); 

	VERSION8_ST=INIT_SP+1;
	VERSION8_SP=peb.LoadPattern(VERSION8_ST,"VERSION8_01.PTN"); 

	SLEEP_ST=VERSION8_SP+1;
	SLEEP_SP=peb.LoadPattern(SLEEP_ST,"SLEEP_04.PTN"); 

	PORT_ST=SLEEP_SP+1;
	PORT_SP=peb.LoadPattern(PORT_ST,"PORT_01.PTN"); 

	ROMJ_ST=PORT_SP+1;
	ROMJ_SP=peb.LoadPattern(ROMJ_ST,"ROMJ_01.PTN");

   	RAM_ST=ROMJ_SP+1;
	RAM_SP=peb.LoadPattern(RAM_ST,"RAM_01.PTN");

	BLANKCHK_ST=RAM_SP+1;
	BLANKCHK_SP=peb.LoadPattern(BLANKCHK_ST,"BLANKCHK_02.PTN");

	AUDEC_ST=BLANKCHK_SP+1;
	AUDEC_SP=peb.LoadPattern(AUDEC_ST,"AUDEC_03.PTN"); 

   	CPU_ST=AUDEC_SP+1;
	CPU_SP=peb.LoadPattern(CPU_ST,"CPU_01.PTN");

	PERI_ST=CPU_SP+1;
	PERI_SP=peb.LoadPattern(PERI_ST,"PERI_02.PTN"); 

	CLK_RST_LPWR_ST=PERI_SP+1;
	CLK_RST_LPWR_SP=peb.LoadPattern(CLK_RST_LPWR_ST,"CLK_RST_LPWR_03.PTN"); 

	DDAC_ST=CLK_RST_LPWR_SP+1;
	DDAC_SP=peb.LoadPattern(DDAC_ST,"DDAC_01.PTN"); 

    SDC_ST=DDAC_SP+1;
	SDC_SP=peb.LoadPattern(SDC_ST,"SDC_03.PTN");

	DISP12_ST=SDC_SP+1;
	DISP12_SP=peb.LoadPattern(DISP12_ST,"DISP12_02.PTN"); 

	DISP13_ST=DISP12_SP+1;
	DISP13_SP=peb.LoadPattern(DISP13_ST,"DISP13_06.PTN"); 

	DISP14_ST=DISP13_SP+1;
	DISP14_SP=peb.LoadPattern(DISP14_ST,"DISP14_06.PTN"); 

	LVDWDT_ST=DISP14_SP+1;
	LVDWDT_SP=peb.LoadPattern(LVDWDT_ST,"LVDWDT_03.PTN"); 

	ADC_ST=LVDWDT_SP+1;
	ADC_SP=peb.LoadPattern(ADC_ST,"ADC_06.PTN"); 

	USB_ST=ADC_SP+1;
	USB_SP=peb.LoadPattern(USB_ST,"USB_01.PTN");

    PLL_ST=USB_SP+1;
	PLL_SP=peb.LoadPattern(PLL_ST,"PLL_02.PTN");	

    IRTC_ST=PLL_SP+1;
	IRTC_SP=peb.LoadPattern(IRTC_ST,"IRTC_01.PTN");	

	HTC_ST=IRTC_SP+1;
	HTC_SP=peb.LoadPattern(HTC_ST,"HTC_6M5.PTN"); 

	ADAC_AMUX_ST=HTC_SP+1;
	ADAC_AMUX_SP=peb.LoadPattern(ADAC_AMUX_ST,"ADAC_AMUX_02.PTN"); 

	ADAC_LHRL_ST=ADAC_AMUX_SP+1;
	ADAC_LHRL_SP=peb.LoadPattern(ADAC_LHRL_ST,"ADAC_LHRL_02.PTN"); 

	ADAC_LLRH_ST=ADAC_LHRL_SP+1;
	ADAC_LLRH_SP=peb.LoadPattern(ADAC_LLRH_ST,"ADAC_LLRH_02.PTN"); 

    LOFC_ST=ADAC_LLRH_SP+1;
	LOFC_SP=peb.LoadPattern(LOFC_ST,"LOFC_03.PTN");	

	//<--- Setting Level
	peb.SetPinLevel("PATTERN_PIN","3.3V");
	peb.SetPinLevel("X32KI","1.8V");
//	peb.SetPinLevel("P46","6.7V");

	//<--- Setting Pin Mode
	peb.SetPinMode("PATTERN_PIN","NRZ");
	peb.SetPinMode("P00","RZ");

	//<--- Setting Period
	peb.SetTimingSetPeriod("0",20000);
	peb.SetTimingSetPeriod("1",100);
	peb.SetTimingSetPeriod("2",10000);

	//<--- Setting Pin Edge
	peb.SetTimingSetPinEdge("0","PATTERN_PIN","TS0_NRZ");
	peb.SetTimingSetPinEdge("0","P00","TS0_RZ");

	peb.SetTimingSetPinEdge("1","PATTERN_PIN","TS1_NRZ");
	peb.SetTimingSetPinEdge("1","P00","TS1_RZ");

	peb.SetTimingSetPinEdge("2","PATTERN_PIN","TS2_NRZ");
	peb.SetTimingSetPinEdge("2","P00","TS2_RZ");
	}

void System_Exit(void)
{
	}

void Device_Init(void)
{
	get_gpib_xy();
	}

void Device_Eot(void)
{	
	//<--- Setting Level
	peb.SetPinLevel("PATTERN_PIN","3.3V");
	peb.SetPinLevel("X32KI","1.8V");

	//<--- Setting Pin Mode
	peb.SetPinMode("PATTERN_PIN","NRZ");
	peb.SetPinMode("P00","RZ");

	//<--- Setting Period
	peb.SetTimingSetPeriod("0",20000);
	peb.SetTimingSetPeriod("1",100);
	peb.SetTimingSetPeriod("2",10000);

	//<--- Setting Pin Edge
	peb.SetTimingSetPinEdge("0","PATTERN_PIN","TS0_NRZ");
	peb.SetTimingSetPinEdge("0","P00","TS0_RZ");

	peb.SetTimingSetPinEdge("1","PATTERN_PIN","TS1_NRZ");
	peb.SetTimingSetPinEdge("1","P00","TS1_RZ");

	peb.SetTimingSetPinEdge("2","PATTERN_PIN","TS2_NRZ");
	peb.SetTimingSetPinEdge("2","P00","TS2_RZ");

	//<--- Run Pattern	
	peb.SetTestPatternOption(INIT_ST,INIT_ST,1,false);
	peb.TestPattern(INIT_ST,INIT_SP,bPass);

	dps.FV("LDO_IN",0,150e-3,dps.V_RNG_8V,dps.I_RNG_200MA,true,0);
	util.dlyms(10);
	dps.FV("LDO_IN",0,2e-3,dps.V_RNG_8V,dps.I_RNG_2MA,true,0);
	peb.SetDCLRelay("ALL_PIN",false);
	peb.SetPMURelay("ALL_PIN",false);

    peb.SetTestLogOption(false);
	util.dlyms(10);
	}

void Device_Eow(void)
{

	}

void OS(void)
{
    //<--- POWER ON		
	dps.FV("LDO_IN",0,150e-3,dps.V_RNG_4V,dps.I_RNG_200MA,true,0);
	util.dlyms(10);

	//<-- PPMU FI=100uA
	peb.ppmu.FISetting("OS_P",100e-6,CPmu::I_RNG_4MA, 4, -2,1);
	peb.ppmu.MVSetting("OS_P",1);
	peb.ppmu.Trig();
	PG_VALUE FI_Val1;
 	util.GetMeasValue("OS_P",FI_Val1);
	util.TestLog("OS_P",FI_Val1);

	//<-- PPMU FI=200uA
	peb.ppmu.FISetting("OS_POWER_P",200e-6,CPmu::I_RNG_4MA, 3, -2,10);
	peb.ppmu.MVSetting("OS_POWER_P",1);
	peb.ppmu.Trig();
	PG_VALUE FI_Val2;
 	util.GetMeasValue("OS_POWER_P",FI_Val2);
	util.TestLog("OS_POWER_P",FI_Val2);

	//<--- POWER OFF
	dps.FV("LDO_IN",0,150e-3,dps.V_RNG_4V,dps.I_RNG_200MA,false,0);
	util.dlyms(10);

	//<-- PPMU FI=-100uA
	peb.ppmu.FISetting("OS_N",-600e-6,CPmu::I_RNG_4MA, 3, -2,1);
	peb.ppmu.MVSetting("OS_N",1);
	peb.ppmu.Trig();
	PG_VALUE FI_Val3;
 	util.GetMeasValue("OS_N",FI_Val3);
	util.TestLog("OS_N",FI_Val3);

	//<-- PPMU FI=-200uA
	peb.ppmu.FISetting("OS_POWER_N",-200e-6,CPmu::I_RNG_4MA, 3, -2,10);
	peb.ppmu.MVSetting("OS_POWER_N",1);
	peb.ppmu.Trig();
	PG_VALUE FI_Val4;
 	util.GetMeasValue("OS_POWER_N",FI_Val4);
	util.TestLog("OS_POWER_N",FI_Val4);
	}

void CURRENT(void)
{
	peb.SetDCLRelay("PATTERN_PIN",true);	
	dps.FV("LDO_IN",5.0,150e-3,dps.V_RNG_8V,dps.I_RNG_200MA,true,0);
	util.dlyms(10);

    //<--- Run Pattern	
	peb.SetTestPatternOption(VERSION8_ST,VERSION8_ST,1,false);
	peb.TestPattern(VERSION8_ST,VERSION8_SP,bPass);
	util.FuncLog(true,bPass);
	util.dlyms(10);

	//<--- Test VDDIO
	peb.ppmu.FI("VDDIO",0,CPmu::I_RNG_40UA,4,0);
	util.dlyms(2);
	peb.ppmu.MV("VDDIO",1);
	util.GetMeasValue("VDDIO",vddio);
	util.TestLog("VDDIO",vddio);
	peb.SetPMURelay("VDDIO",false);

	//<--- Test VDD
	peb.ppmu.FI("VDD",0,CPmu::I_RNG_40UA,4,0);
	util.dlyms(2);
	peb.ppmu.MV("VDD",1);
	util.GetMeasValue("VDD",vdd);
	util.TestLog("VDD",vdd);
	peb.SetPMURelay("VDD",false);

	//<--- Test AVDD_HP
	peb.ppmu.FI("AVDD_HP",0,CPmu::I_RNG_40UA,4,0);
	util.dlyms(2);
	peb.ppmu.MV("AVDD_HP",1);
	util.GetMeasValue("AVDD_HP",avdd_hp);
	util.TestLog("AVDD_HP",avdd_hp);
	peb.SetPMURelay("AVDD_HP",false);

	//<--- Test VDD50_DIDD
	dps.FV("LDO_IN",5.0,18e-3,dps.V_RNG_8V,dps.I_RNG_20MA,true,0);
	util.dlyms(20);
	dps.MI("LDO_IN",10);

	double didd[8],didd_mA[8];	
	util.GetMeasValue("LDO_IN",didd);

	for (int i=0;i<8;i++)
	{
		didd_mA[i]=didd[i]*1e3;
		}
	util.TestLog("DIDD",didd_mA);
	}

void SLEEP(void)
{

	//<--- Setting Level
	peb.SetPinLevel("PATTERN_PIN","3.3V");
	peb.SetPinLevel("X32KI","1.8V");

	//<--- Setting Pin Mode
	peb.SetPinMode("PATTERN_PIN","NRZ");
	peb.SetPinMode("P00","RZ");

	//<--- Setting Period
	peb.SetTimingSetPeriod("0",20000);
	peb.SetTimingSetPeriod("1",100);
	peb.SetTimingSetPeriod("2",10000);

	//<--- Setting Pin Edge
	peb.SetTimingSetPinEdge("0","PATTERN_PIN","TS0_NRZ");
	peb.SetTimingSetPinEdge("0","P00","TS0_RZ");

	peb.SetTimingSetPinEdge("1","PATTERN_PIN","TS1_NRZ");
	peb.SetTimingSetPinEdge("1","P00","TS1_RZ");

	peb.SetTimingSetPinEdge("2","PATTERN_PIN","TS2_NRZ");
	peb.SetTimingSetPinEdge("2","P00","TS2_RZ");

	//<--- Run Pattern	
	peb.SetTestPatternOption(INIT_ST,INIT_ST,1,false);
	peb.TestPattern(INIT_ST,INIT_SP,bPass);

	dps.FV("LDO_IN",0,150e-3,dps.V_RNG_8V,dps.I_RNG_200MA,true,0);
	util.dlyms(10);
	dps.FV("LDO_IN",0,2e-3,dps.V_RNG_8V,dps.I_RNG_2MA,true,0);
	peb.SetDCLRelay("ALL_PIN",false);
	peb.SetPMURelay("ALL_PIN",false);

    peb.SetTestLogOption(false);
	util.dlyms(10);

	peb.SetDCLRelay("PATTERN_PIN",true);	
	dps.FV("LDO_IN",5.0,150e-3,dps.V_RNG_8V,dps.I_RNG_200MA,true,0);
	util.dlyms(10);
	
	//<--- Run Pattern	
	peb.SetTestPatternOption(SLEEP_ST,SLEEP_ST,1,false);
	peb.TestPattern(SLEEP_ST,SLEEP_SP,bPass);
	util.FuncLog(true,bPass);

	dps.FV("LDO_IN",5.0,1.8e-3,dps.V_RNG_8V,dps.I_RNG_2MA,true,5);
    util.dlyms(20);
	dps.MI("LDO_IN",10);

	double sidd[8],sidd_uA[8];
	util.GetMeasValue("LDO_IN",sidd);

	for (int i=0;i<8;i++)
	{
		sidd_uA[i]=sidd[i]*1e6;
		}
	util.TestLog("SIDD",sidd_uA);
	}

void POWERON(void)
{
	peb.SetDCLRelay("PATTERN_PIN",true);	
	dps.FV("LDO_IN",5.0,150e-3,dps.V_RNG_8V,dps.I_RNG_200MA,true,0);
	util.dlyms(20);
	}

void PORT(void)
{
    //<--- Run Pattern	
	peb.SetTestPatternOption(PORT_ST,PORT_ST,1,false);
	peb.TestPattern(PORT_ST,PORT_SP,bPass);
	util.FuncLog(true,bPass);
	}

void ROMJ(void)
{

	//<--- Setting Period
//	peb.SetTimingSetPeriod("1",4000);

//	peb.SetTimingSetPinEdge("1","PATTERN_PIN","TS1_NRZ_2");
//	peb.SetTimingSetPinEdge("1","P00","TS1_RZ_2");

    //<--- Run Pattern	
	peb.SetTestPatternOption(ROMJ_ST,ROMJ_ST,1,false);
	peb.TestPattern(ROMJ_ST,ROMJ_SP,bPass);
	util.FuncLog(true,bPass);

	//<--- Setting Period
//	peb.SetTimingSetPeriod("1",100);

//	peb.SetTimingSetPinEdge("1","PATTERN_PIN","TS1_NRZ");
//	peb.SetTimingSetPinEdge("1","P00","TS1_RZ");
	}

void RAM(void)
{
    //<--- Run Pattern	
	peb.SetTestPatternOption(RAM_ST,RAM_ST,1,false);
	peb.TestPattern(RAM_ST,RAM_SP,bPass);
	util.FuncLog(true,bPass);
	}

void BLANKCHK(void)
{
    //<--- Run Pattern	
	peb.SetTestPatternOption(BLANKCHK_ST,BLANKCHK_ST,1,false);
	peb.TestPattern(BLANKCHK_ST,BLANKCHK_SP,bPass);
	util.FuncLog(true,bPass);
	}

void AUDEC(void)
{
    //<--- Run Pattern	
	peb.SetTestPatternOption(AUDEC_ST,AUDEC_ST,1,false);
	peb.TestPattern(AUDEC_ST,AUDEC_SP,bPass);
	util.FuncLog(true,bPass);
	}

void CPU(void)
{
    //<--- Run Pattern	
	peb.SetTestPatternOption(CPU_ST,CPU_ST,1,false);
	peb.TestPattern(CPU_ST,CPU_SP,bPass);
	util.FuncLog(true,bPass);
	}

void PERI(void)
{
    //<--- Run Pattern	
	peb.SetTestPatternOption(PERI_ST,PERI_ST,1,false);
	peb.TestPattern(PERI_ST,PERI_SP,bPass);
	util.FuncLog(true,bPass);
	}

void CLK_RST_LPWR(void)
{
    //<--- Run Pattern	
	peb.SetTestPatternOption(CLK_RST_LPWR_ST,CLK_RST_LPWR_ST,1,false);
	peb.TestPattern(CLK_RST_LPWR_ST,CLK_RST_LPWR_SP,bPass);
	util.FuncLog(true,bPass);
	}

void DDAC(void)
{
    //<--- Run Pattern	
	peb.SetTestPatternOption(DDAC_ST,DDAC_ST,1,false);
	peb.TestPattern(DDAC_ST,DDAC_SP,bPass);
	util.FuncLog(true,bPass);
	}

void SDC(void)
{
    //<--- Run Pattern	
	peb.SetTestPatternOption(SDC_ST,SDC_ST,1,false);
	peb.TestPattern(SDC_ST,SDC_SP,bPass);
	util.FuncLog(true,bPass);
	}

void DISP12(void)
{
    //<--- Run Pattern	
	peb.SetTestPatternOption(DISP12_ST,DISP12_ST,1,false);
	peb.TestPattern(DISP12_ST,DISP12_SP,bPass);
	util.FuncLog(true,bPass);
	util.dlyms(10);

	//<--- Test P16
	peb.ppmu.FI("P16",-0.0000005,CPmu::I_RNG_40UA,4,0);
	util.dlyms(1);
	peb.ppmu.MV("P16",1);
	util.GetMeasValue("P16",p16);
	util.TestLog("P16",p16);
	peb.SetPMURelay("P16",false);

	//<--- Test P33
	peb.ppmu.FI("P33",0,CPmu::I_RNG_40UA,4,0);
	util.dlyms(1);
	peb.ppmu.MV("P33",1);
	util.GetMeasValue("P33",p33);
	util.TestLog("P33",p33);
	peb.SetPMURelay("P33",false);
	}

void DISP13(void)
{
	//<--- Setting Level
	peb.SetPinLevel("PATTERN_PIN","DISP13_VOHL");
	peb.SetPinLevel("X32KI","1.8V");
	util.dlyms(5);

    //<--- Run Pattern	
	peb.SetTestPatternOption(DISP13_ST,DISP13_ST,1,false);
	peb.TestPattern(DISP13_ST,DISP13_SP,bPass);
	util.FuncLog(true,bPass);
	util.dlyms(10);

	//<--- Test P12
	peb.ppmu.FI("P12",0,CPmu::I_RNG_40UA,4,0);
	util.dlyms(1);
	peb.ppmu.MV("P12",1);
	util.GetMeasValue("P12",p12);
	util.TestLog("P12",p12);
	peb.SetPMURelay("P12",false);

	//<--- Test P17
	peb.ppmu.FI("P17",0,CPmu::I_RNG_40UA,4,0);
	util.dlyms(1);
	peb.ppmu.MV("P17",1);
	util.GetMeasValue("P17",p17);
	util.TestLog("P17",p17);
	peb.SetPMURelay("P17",false);

	//<--- Test P30
	peb.ppmu.FI("P30",0,CPmu::I_RNG_40UA,4,0);
	util.dlyms(1);
	peb.ppmu.MV("P30",1);
	util.GetMeasValue("P30",p30);
	util.TestLog("P30",p30);
	peb.SetPMURelay("P30",false);

	//<--- Setting Level
	peb.SetPinLevel("PATTERN_PIN","3.3V");
	peb.SetPinLevel("X32KI","1.8V");
	util.dlyms(5);
	}

void DISP14(void)
{
	//<--- Setting Level
	peb.SetPinLevel("PATTERN_PIN","DISP14_VOHL");
	peb.SetPinLevel("X32KI","1.8V");
	util.dlyms(5);

    //<--- Run Pattern	
	peb.SetTestPatternOption(DISP14_ST,DISP14_ST,1,false);
	peb.TestPattern(DISP14_ST,DISP14_SP,bPass);
	util.FuncLog(true,bPass);
	util.dlyms(10);

	//<--- Test P16
	peb.ppmu.FI("P16",0,CPmu::I_RNG_40UA,4,0);
	util.dlyms(1);
	peb.ppmu.MV("P16",1);
	util.GetMeasValue("P16",p16);
	util.TestLog("P16",p16);
	peb.SetPMURelay("P16",false);

	//<--- Test P17
	peb.ppmu.FI("P17",0,CPmu::I_RNG_40UA,4,0);
	util.dlyms(1);
	peb.ppmu.MV("P17",1);
	util.GetMeasValue("P17",p17);
	util.TestLog("P17",p17);
	peb.SetPMURelay("P17",false);

	//<--- Test P31
	peb.ppmu.FI("P31",0,CPmu::I_RNG_40UA,4,0);
	util.dlyms(1);
	peb.ppmu.MV("P31",1);
	util.GetMeasValue("P31",p31);
	util.TestLog("P31",p31);
	peb.SetPMURelay("P31",false);

	//<--- Setting Level
	peb.SetPinLevel("PATTERN_PIN","3.3V");
	peb.SetPinLevel("X32KI","1.8V");
	util.dlyms(5);
	}

void LVDWDT(void)
{
    //<--- Run Pattern	
	peb.SetTestPatternOption(LVDWDT_ST,LVDWDT_ST,1,false);
	peb.TestPattern(LVDWDT_ST,LVDWDT_SP,bPass);
	util.FuncLog(true,bPass);
	}

void ADC(void)
{
    //<--- Run Pattern	
	peb.SetTestPatternOption(ADC_ST,ADC_ST,1,false);
	peb.TestPattern(ADC_ST,ADC_SP,bPass);
	util.FuncLog(true,bPass);
	}

void USB(void)
{
    //<--- Run Pattern	
	peb.SetTestPatternOption(USB_ST,USB_ST,1,false);
	peb.TestPattern(USB_ST,USB_SP,bPass);
	util.FuncLog(true,bPass);
	}

void PLL(void)
{
    //<--- Run Pattern	
	peb.SetTestPatternOption(PLL_ST,PLL_ST,1,false);
	peb.TestPattern(PLL_ST,PLL_SP,bPass);
	util.FuncLog(true,bPass);
	}

void IRTC(void)
{
    //<--- Run Pattern	
	peb.SetTestPatternOption(IRTC_ST,IRTC_ST,1,false);
	peb.TestPattern(IRTC_ST,IRTC_SP,bPass);
	util.FuncLog(true,bPass);
	}

void HTC(void)
{
    //<--- Run Pattern	
	peb.SetTestPatternOption(HTC_ST,HTC_ST,1,false);
	peb.TestPattern(HTC_ST,HTC_SP,bPass);
	util.FuncLog(true,bPass);
	}

void ADAC_AMUX(void)
{
    //<--- Run Pattern	
	peb.SetTestPatternOption(ADAC_AMUX_ST,ADAC_AMUX_ST,1,false);
	peb.TestPattern(ADAC_AMUX_ST,ADAC_AMUX_SP,bPass);
	util.FuncLog(true,bPass);
	util.dlyms(10);

	//<--- Test VCM
	peb.ppmu.FI("VCM",0,CPmu::I_RNG_40UA,4,0);
	util.dlyms(2);
	peb.ppmu.MV("VCM",1);
	util.GetMeasValue("VCM",vcm);
	util.TestLog("VCM",vcm);
	peb.SetPMURelay("VCM",false);

	//<--- Test P16
	peb.ppmu.FI("P23",0,CPmu::I_RNG_40UA,4,0);
	util.dlyms(2);
	peb.ppmu.MV("P23",1);
	util.GetMeasValue("P23",p23);
	util.TestLog("P23",p23);
	peb.SetPMURelay("P23",false);

	peb.ppmu.FI("P24",0,CPmu::I_RNG_40UA,4,0);
	util.dlyms(2);
	peb.ppmu.MV("P24",1);
	util.GetMeasValue("P24",p24);
	util.TestLog("P24",p24);
	peb.SetPMURelay("P24",false);

	peb.ppmu.FI("P25",0,CPmu::I_RNG_40UA,4,0);
	util.dlyms(2);
	peb.ppmu.MV("P25",1);
	util.GetMeasValue("P25",p25);
	util.TestLog("P25",p25);
	peb.SetPMURelay("P25",false);

	peb.ppmu.FI("P26",0,CPmu::I_RNG_40UA,4,0);
	util.dlyms(2);
	peb.ppmu.MV("P26",1);
	util.GetMeasValue("P26",p26);
	util.TestLog("P26",p26);
	peb.SetPMURelay("P26",false);

	peb.ppmu.FI("P27",0,CPmu::I_RNG_40UA,4,0);
	util.dlyms(2);
	peb.ppmu.MV("P27",1);
	util.GetMeasValue("P27",p27);
	util.TestLog("P27",p27);
	peb.SetPMURelay("P27",false);
	}

void ADAC_LHRL(void)
{
    //<--- Run Pattern	
	peb.SetTestPatternOption(ADAC_LHRL_ST,ADAC_LHRL_ST,1,false);
	peb.TestPattern(ADAC_LHRL_ST,ADAC_LHRL_SP,bPass);
	util.FuncLog(true,bPass);

    //<--- Run Pattern	CYCLE ON
	peb.SetTestPatternOption(ADAC_LHRL_SP,ADAC_LHRL_SP,1,true);
	peb.TestPattern(ADAC_LHRL_SP,ADAC_LHRL_SP,bPass);
	util.dlyms(10);

	//<--- Test DACLO
	peb.ppmu.FI("DACLO",0,CPmu::I_RNG_40UA,4,0);
	util.dlyms(2);
	peb.ppmu.MV("DACLO",1);
	util.GetMeasValue("DACLO",dacl_lhrl);
	util.TestLog("DACL_LHRL",dacl_lhrl);
	peb.SetPMURelay("DACLO",false);

	//<--- Test DACRO
	peb.ppmu.FI("DACRO",0,CPmu::I_RNG_40UA,4,0);
	util.dlyms(2);
	peb.ppmu.MV("DACRO",1);
	util.GetMeasValue("DACRO",dacr_lhrl);
	util.TestLog("DACR_LHRL",dacr_lhrl);
	peb.SetPMURelay("DACRO",false);

    //<--- Run Pattern	 CYCLE OFF
	peb.SetTestPatternOption(ADAC_LHRL_SP,ADAC_LHRL_SP,1,false);
	peb.TestPattern(ADAC_LHRL_SP,ADAC_LHRL_SP,bPass);
	}

void ADAC_LLRH(void)
{
    //<--- Run Pattern	
	peb.SetTestPatternOption(ADAC_LLRH_ST,ADAC_LLRH_ST,1,false);
	peb.TestPattern(ADAC_LLRH_ST,ADAC_LLRH_SP,bPass);
	util.FuncLog(true,bPass);

    //<--- Run Pattern	CYCLE ON
	peb.SetTestPatternOption(ADAC_LLRH_SP,ADAC_LLRH_SP,1,true);
	peb.TestPattern(ADAC_LLRH_SP,ADAC_LLRH_SP,bPass);
	util.dlyms(10);

	//<--- Test DACLO
	peb.ppmu.FI("DACLO",0,CPmu::I_RNG_40UA,4,0);
	util.dlyms(2);
	peb.ppmu.MV("DACLO",1);
	util.GetMeasValue("DACLO",dacl_llrh);
	util.TestLog("DACL_LLRH",dacl_llrh);
	peb.SetPMURelay("DACLO",false);

	//<--- Test DACRO
	peb.ppmu.FI("DACRO",0,CPmu::I_RNG_40UA,4,0);
	util.dlyms(2);
	peb.ppmu.MV("DACRO",1);
	util.GetMeasValue("DACRO",dacr_llrh);
	util.TestLog("DACR_LLRH",dacr_llrh);
	peb.SetPMURelay("DACRO",false);

    //<--- Run Pattern	 CYCLE OFF
	peb.SetTestPatternOption(ADAC_LLRH_SP,ADAC_LLRH_SP,1,false);
	peb.TestPattern(ADAC_LLRH_SP,ADAC_LLRH_SP,bPass);
	}

void LOFC(void)
{
    //<--- Run Pattern	
	peb.SetTestPatternOption(LOFC_ST,LOFC_ST,1,false);
	peb.TestPattern(LOFC_ST,LOFC_SP,bPass);
	util.FuncLog(true,bPass);
	}

void get_gpib_xy(void)
{
    for(i=0;i<8;i++)
    {
		nX[i]=0;
		nY[i]=0;
		}

	util.Trim_GetDieXY(1,nX[0],nY[0]);
    for(i=0;i<7;i++)
    {
		nX[i+1]=nX[i]+1;
		nY[i+1]=nY[i]+1;
		}

    for(i=0;i<8;i++)
    {
		gpib_x[i]=nX[i];
		gpib_y[i]=nY[i];
		}
	}

void X(void)
{
	util.TestLog("X",gpib_x);
	}

void Y(void)
{
	util.TestLog("Y",gpib_y);
	}
