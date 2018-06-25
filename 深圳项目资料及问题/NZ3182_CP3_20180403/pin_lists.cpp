#include "tester.h"

// ********************************************
// ****  Pin Lists                        *****
// ********************************************
PINLIST(pl_IOPINS)
{
	PINS(CMS_PAD, GPIO6_PAD, GPIO5_PAD, GPIO4_PAD, GPIO3_PAD, VDD_PAD, VPP_PAD, XT0_PAD)
	PINS5(XT1_PAD, ADC_PAD, COM0_PAD, SEG0_PAD, PWRWAKE_PAD)
}

PINLIST(pl_IOPINS_NO_XT1)
{
	PINS(CMS_PAD, GPIO6_PAD, GPIO5_PAD, GPIO4_PAD, GPIO3_PAD, VDD_PAD, VPP_PAD, XT0_PAD)
		PINS4(ADC_PAD, COM0_PAD, SEG0_PAD, PWRWAKE_PAD)
}

PINLIST(pl_IOPINS_NO_GPIO4)
{
	PINS7(CMS_PAD, GPIO6_PAD, GPIO5_PAD, GPIO3_PAD, VDD_PAD, VPP_PAD, XT0_PAD)
	PINS5(XT1_PAD, ADC_PAD, COM0_PAD, SEG0_PAD, PWRWAKE_PAD)
}

PINLIST(pl_IOPINS_NO_PWRWAKE)
{
	PINS(CMS_PAD, GPIO6_PAD, GPIO5_PAD, GPIO4_PAD, GPIO3_PAD, VDD_PAD, VPP_PAD, XT0_PAD)
	PINS4(XT1_PAD, ADC_PAD, COM0_PAD, SEG0_PAD)
}

PINLIST(pl_IOPINS_NO_GPIO4_XT1)
{
	PINS7(CMS_PAD, GPIO6_PAD, GPIO5_PAD, GPIO3_PAD, VDD_PAD, VPP_PAD, XT0_PAD)
	PINS4(ADC_PAD, COM0_PAD, SEG0_PAD, PWRWAKE_PAD)
}

PINLIST(pl_IOPINS_NO_GPIO4_XT1_CMS)
{
	PINS6(GPIO6_PAD, GPIO5_PAD, GPIO3_PAD, VDD_PAD, VPP_PAD, XT0_PAD)
	PINS4(ADC_PAD, COM0_PAD, SEG0_PAD, PWRWAKE_PAD)
}

PINLIST(pl_IOPINS_NO_GPIO4_XT1_CMS_PWRWAKE)
{
	PINS6(GPIO6_PAD, GPIO5_PAD, GPIO3_PAD, VDD_PAD, VPP_PAD, XT0_PAD)
	PINS3(ADC_PAD, COM0_PAD, SEG0_PAD)
}

PINLIST(pl_PATTERN_PIN)
{
	PINS6(VDD_PAD, CMS_PAD, XT1_PAD, GPIO4_PAD, GPIO5_PAD, GPIO6_PAD)		
}


//PINLIST(pl_OSPINS)
//{
//	PINS7(CMS_PAD, GPIO6_PAD, GPIO5_PAD, GPIO4_PAD, GPIO3_PAD, VPP_PAD, XT0_PAD)
//	PINS4(XT1_PAD, ADC_PAD, COM0_PAD, SEG0_PAD)
//}

PINLIST(pl_OSPINS)
{
	PINS7(CMS_PAD, GPIO6_PAD, GPIO5_PAD, GPIO4_PAD, GPIO3_PAD, VPP_PAD, XT0_PAD)
	PINS3(XT1_PAD, ADC_PAD, COM0_PAD)
}

PINLIST(pl_LEAK_PINS)
{
	PINS4(GPIO6_PAD, GPIO5_PAD, GPIO4_PAD, GPIO3_PAD)
}

PINLIST(pl_ATPG_PINS)
{
	PINS6(VDD_PAD, GPIO3_PAD, GPIO4_PAD, GPIO5_PAD, GPIO6_PAD, CMS_PAD)
}


PINLIST(pl_EOT_PINS)
{
	PINS6(VDD_PAD, CMS_PAD, XT1_PAD, GPIO4_PAD, GPIO5_PAD, GPIO6_PAD)
}

//PINLIST( pl_VSS_PAD ){ PINS1( VSS_PAD ) }
PINLIST(pl_CMS_PAD){ PINS1(CMS_PAD) }
PINLIST(pl_GPIO6_PAD){ PINS1(GPIO6_PAD) }
PINLIST(pl_GPIO5_PAD){ PINS1(GPIO5_PAD) }
PINLIST(pl_GPIO4_PAD){ PINS1(GPIO4_PAD) }
PINLIST(pl_GPIO3_PAD){ PINS1(GPIO3_PAD) }
PINLIST(pl_VPP_PAD){ PINS1(VPP_PAD) }
PINLIST(pl_PWRWAKE_PAD){ PINS1(PWRWAKE_PAD) }
PINLIST(pl_XT0_PAD){ PINS1(XT0_PAD) }
PINLIST(pl_XT1_PAD){ PINS1(XT1_PAD) }
PINLIST(pl_ADC_PAD){ PINS1(ADC_PAD) }
PINLIST(pl_COM0_PAD){ PINS1(COM0_PAD) }
PINLIST(pl_SEG0_PAD){ PINS1(SEG0_PAD) }

PINLIST(pl_VDD_PAD){ PINS1(VDD_PAD) }
PINLIST(pl_VDD){ PINS1(VDD) }


