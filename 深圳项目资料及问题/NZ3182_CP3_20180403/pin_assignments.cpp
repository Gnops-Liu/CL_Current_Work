#define TESTER_H "tester.h"
#include TESTER_H

// *********************************************************
// *****  Pin Assignment Table and Current Share file  *****
// *********************************************************

static CMap < DutPin *, DutPin *, CString, CString > dut_pin_info;

DUT_PIN(VSS_PAD) { }
DUT_PIN(CMS_PAD) { }
DUT_PIN(GPIO6_PAD) { }
DUT_PIN(GPIO5_PAD) { }
DUT_PIN(GPIO4_PAD) { }
DUT_PIN(GPIO3_PAD) { }
DUT_PIN(VPP_PAD) { }
DUT_PIN(PWRWAKE_PAD) { }
DUT_PIN(VDD_PAD) { } //CH
DUT_PIN(VDD) { }  //DPS
DUT_PIN(XT0_PAD) { }
DUT_PIN(XT1_PAD) { }
DUT_PIN(ADC_PAD) { }
DUT_PIN(COM0_PAD) { }
DUT_PIN(SEG0_PAD) { }


PIN_ASSIGNMENTS(NZ3182)
{
	/*					DUT pin			   DUT1	     */
	/*	-------	  ------    -------	  -------	 */

		
		ASSIGN_2DUT(	CMS_PAD,			a_1	,		b_1		)
		ASSIGN_2DUT(	GPIO6_PAD,			a_2	,		b_2		)
		ASSIGN_2DUT(	GPIO5_PAD,			a_3	,		b_3		)
		ASSIGN_2DUT(	GPIO4_PAD,			a_4	,		b_4		)
		ASSIGN_2DUT(	GPIO3_PAD,			a_5	,		b_5		)
		ASSIGN_2DUT(	VPP_PAD,			a_6	,		b_6		)
		ASSIGN_2DUT(	PWRWAKE_PAD,		a_7	,		b_7		)
		ASSIGN_2DUT(	VDD_PAD,			a_8	,		b_8		)
		ASSIGN_2DUT(	XT0_PAD,			a_9	,		b_9		)
		ASSIGN_2DUT(	XT1_PAD,			a_10,		b_10	)
		ASSIGN_2DUT(	ADC_PAD,			a_11,		b_11	)
		ASSIGN_2DUT(	COM0_PAD, 			a_12,		b_12	)
		ASSIGN_2DUT(	SEG0_PAD, 			a_13,		b_13	)
			   
		ASSIGN_2DUT(	VDD,				a_dps1a,	b_dps1a	)

		

}


// return the package pin number for this dutpin
CString get_dut_pin_number( DutPin * dpin ) {
	return dut_pin_info[ dpin ];
}