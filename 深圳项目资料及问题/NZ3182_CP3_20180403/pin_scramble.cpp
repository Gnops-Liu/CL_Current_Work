#define TESTER_H "tester.h"
#include TESTER_H


// ***********************************
// ****  Pin Scramble Maps file  *****
// ***********************************
PIN_SCRAMBLE(your_scramble_set_name)
{
	SCRAMBLE_MAP(PS1)	/*  Default pin scramble map  */
	{
			/*			DUT Pin		  Tester		*/
			/*			 Name		  Function		*/
			/*			-------		  --------		*/
			SCRAMBLE(	CMS_PAD,	   t_lvm	)
			SCRAMBLE(	GPIO6_PAD,	   t_lvm	)
			SCRAMBLE(	GPIO5_PAD,	   t_lvm	)
			SCRAMBLE(	GPIO4_PAD,	   t_lvm	)
			SCRAMBLE(	GPIO3_PAD,	   t_lvm	)
			SCRAMBLE(	VPP_PAD,	   t_lvm	)
			SCRAMBLE(	PWRWAKE_PAD,   t_lvm	)
			SCRAMBLE(	VDD_PAD,	   t_lvm	)
			SCRAMBLE(	XT0_PAD,	   t_lvm	)
			SCRAMBLE(	XT1_PAD,	   t_lvm	)
			SCRAMBLE(	ADC_PAD,	   t_lvm	)
			SCRAMBLE(	COM0_PAD, 	   t_lvm	)
			SCRAMBLE(	SEG0_PAD, 	   t_lvm	)
	}
}
