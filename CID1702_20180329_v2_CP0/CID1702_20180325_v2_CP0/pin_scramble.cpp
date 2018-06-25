#define TESTER_H "tester.h"
#include TESTER_H


// ***********************************
// ****  Pin Scramble Maps file  *****
// ***********************************

#define SCRAMBLEAl(S_PIN)         \
	SCRAMBLE(SDA, S_PIN)             \
	SCRAMBLE(CLK, t_cs1)             \
	SCRAMBLE(RESET, t_cs2)            
      

PIN_SCRAMBLE(pin_scramble_name)
{


	SCRAMBLE_MAP(PS_A0)	{ SCRAMBLEAl(t_x0) }
	SCRAMBLE_MAP(PS_A1)	{ SCRAMBLEAl(t_x1) }
	SCRAMBLE_MAP(PS_A2)	{ SCRAMBLEAl(t_x2) }
	SCRAMBLE_MAP(PS_A3)	{ SCRAMBLEAl(t_x3) }
	SCRAMBLE_MAP(PS_A4)	{ SCRAMBLEAl(t_x4) }
	SCRAMBLE_MAP(PS_A5)	{ SCRAMBLEAl(t_x5) }

	SCRAMBLE_MAP(PS_A6)	{ SCRAMBLEAl(t_y0) }
	SCRAMBLE_MAP(PS_A7)	{ SCRAMBLEAl(t_y1) }
	SCRAMBLE_MAP(PS_A8)	{ SCRAMBLEAl(t_y2) }
	SCRAMBLE_MAP(PS_A9)	{ SCRAMBLEAl(t_y3) }
	SCRAMBLE_MAP(PS_A10)	{ SCRAMBLEAl(t_y4) }
	SCRAMBLE_MAP(PS_A11)	{ SCRAMBLEAl(t_y5) }
	SCRAMBLE_MAP(PS_A12)	{ SCRAMBLEAl(t_y6) }
	SCRAMBLE_MAP(PS_A13)	{ SCRAMBLEAl(t_y7) }
	SCRAMBLE_MAP(PS_A14)	{ SCRAMBLEAl(t_y8) }
	SCRAMBLE_MAP(PS_A15)	{ SCRAMBLEAl(t_y9) }

	SCRAMBLE_MAP(PS_A16)	{ SCRAMBLEAl(t_y10) }
	SCRAMBLE_MAP(PS_A17)	{ SCRAMBLEAl(t_y11) }
	SCRAMBLE_MAP(PS_A18)	{ SCRAMBLEAl(t_y12) }
	SCRAMBLE_MAP(PS_A19)	{ SCRAMBLEAl(t_y13) }
	SCRAMBLE_MAP(PS_A20)	{ SCRAMBLEAl(t_y14) }
	SCRAMBLE_MAP(PS_A21)	{ SCRAMBLEAl(t_y15) }
	SCRAMBLE_MAP(PS_A22)	{ SCRAMBLEAl(t_y16) }
	SCRAMBLE_MAP(PS_A23)	{ SCRAMBLEAl(t_y17) }

	SCRAMBLE_MAP(PS_D0)	{ SCRAMBLEAl(t_d0) }
	SCRAMBLE_MAP(PS_D1)	{ SCRAMBLEAl(t_d1) }
	SCRAMBLE_MAP(PS_D2)	{ SCRAMBLEAl(t_d2) }
	SCRAMBLE_MAP(PS_D3)	{ SCRAMBLEAl(t_d3) }
	SCRAMBLE_MAP(PS_D4)	{ SCRAMBLEAl(t_d4) }
	SCRAMBLE_MAP(PS_D5)	{ SCRAMBLEAl(t_d5) }
	SCRAMBLE_MAP(PS_D6)	{ SCRAMBLEAl(t_d6) }
	SCRAMBLE_MAP(PS_D7)	{ SCRAMBLEAl(t_d7) }

	SCRAMBLE_MAP(PS_D8)	{ SCRAMBLEAl(t_d8) }
	SCRAMBLE_MAP(PS_D9)	{ SCRAMBLEAl(t_d9) }
	SCRAMBLE_MAP(PS_D10)	{ SCRAMBLEAl(t_d10) }
	SCRAMBLE_MAP(PS_D11)	{ SCRAMBLEAl(t_d11) }
	SCRAMBLE_MAP(PS_D12)	{ SCRAMBLEAl(t_d12) }
	SCRAMBLE_MAP(PS_D13)	{ SCRAMBLEAl(t_d13) }
	SCRAMBLE_MAP(PS_D14)	{ SCRAMBLEAl(t_d14) }
	SCRAMBLE_MAP(PS_D15)	{ SCRAMBLEAl(t_d15) }
	SCRAMBLE_MAP(PS_D16)	{ SCRAMBLEAl(t_d16) }
	SCRAMBLE_MAP(PS_D17)	{ SCRAMBLEAl(t_d17) }

	SCRAMBLE_MAP(PS_D18)	{ SCRAMBLEAl(t_d18) }
	SCRAMBLE_MAP(PS_D19)	{ SCRAMBLEAl(t_d19) }
	SCRAMBLE_MAP(PS_D20)	{ SCRAMBLEAl(t_d20) }
	SCRAMBLE_MAP(PS_D21)	{ SCRAMBLEAl(t_d21) }
	SCRAMBLE_MAP(PS_D22)	{ SCRAMBLEAl(t_d22) }
	SCRAMBLE_MAP(PS_D23)	{ SCRAMBLEAl(t_d23) }
	SCRAMBLE_MAP(PS_D24)	{ SCRAMBLEAl(t_d24) }
	SCRAMBLE_MAP(PS_D25)	{ SCRAMBLEAl(t_d25) }

	SCRAMBLE_MAP(PS_D26)	{ SCRAMBLEAl(t_d26) }
	SCRAMBLE_MAP(PS_D27)	{ SCRAMBLEAl(t_d27) }
	SCRAMBLE_MAP(PS_D28)	{ SCRAMBLEAl(t_d28) }
	SCRAMBLE_MAP(PS_D29)	{ SCRAMBLEAl(t_d29) }
	SCRAMBLE_MAP(PS_D30)	{ SCRAMBLEAl(t_d30) }
	SCRAMBLE_MAP(PS_D31)	{ SCRAMBLEAl(t_d31) }
	SCRAMBLE_MAP(PS_D32)	{ SCRAMBLEAl(t_d32) }
	SCRAMBLE_MAP(PS_D33)	{ SCRAMBLEAl(t_d33) }
	SCRAMBLE_MAP(PS_D34)	{ SCRAMBLEAl(t_d34) }
	SCRAMBLE_MAP(PS_D35)	{ SCRAMBLEAl(t_d35) }

	SCRAMBLE_MAP(PS_D36)	{
		SCRAMBLE(SDA, t_lvm)             
			SCRAMBLE(CLK, t_lvm)
			SCRAMBLE(RESET, t_lvm)
	}
}