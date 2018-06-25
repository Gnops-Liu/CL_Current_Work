#include "tester.h"

// ********************************************
// ****  Pin Lists                        *****
// ********************************************

PINLIST(pl_CLK)	{ PINS1(CLK) }
PINLIST(pl_SDA)	{ PINS1(SDA) }
PINLIST(pl_DVDD_1P5)	{ PINS1(DVDD_1P5) }
PINLIST(pl_RESET)	{ PINS1(RESET) }

PINLIST(pl_TST) { PINS1(TST) }
PINLIST(pl_VCC) { PINS1(VCC) }
PINLIST(pl_VPP) { PINS1(VPP) }
PINLIST(pl_VNN) { PINS1(VNN) }

PINLIST(pl_dps) {
	INCLUDE_PINLIST(pl_TST)
}
PINLIST(pl_dpo) {
	INCLUDE_PINLIST(pl_VCC)
}
PINLIST(pl_dpohv) {
	INCLUDE_PINLIST(pl_VNN)
}
PINLIST(pl_hv) {
	INCLUDE_PINLIST(pl_VPP)
}

PINLIST(pl_all_pins) {
	INCLUDE_PINLIST(pl_CLK)
	INCLUDE_PINLIST(pl_SDA)
	INCLUDE_PINLIST(pl_RESET)
}
PINLIST(pl_VDD15) {
		INCLUDE_PINLIST(pl_DVDD_1P5)
}
PINLIST(pl_ebm_dma_write_f)
{
	/*  PINS_OF_1DUT(SDA, t_dut1)
		PINS_OF_1DUT(SDA, t_dut2)
		PINS_OF_1DUT(SDA, t_dut3)
		PINS_OF_1DUT(SDA, t_dut4)
		PINS_OF_1DUT(SDA, t_dut5)
		PINS_OF_1DUT(SDA, t_dut6)
		PINS_OF_1DUT(SDA, t_dut7)
		PINS_OF_1DUT(SDA, t_dut8)*/

	
}
PINLIST(pl_ebm_dma_write_l)
{
	/*PINS_OF_1DUT(SDA, t_dut9)
		PINS_OF_1DUT(SDA, t_dut10)
		PINS_OF_1DUT(SDA, t_dut11)
		PINS_OF_1DUT(SDA, t_dut12)
		PINS_OF_1DUT(SDA, t_dut13)
		PINS_OF_1DUT(SDA, t_dut14)
		PINS_OF_1DUT(SDA, t_dut15)
		PINS_OF_1DUT(SDA, t_dut16)*/

}