#include "tester.h"


// Setup timing functions
DOUBLE_VARIABLE(TS_20MHZ_period, 200, ""){}
void ts_20_Mhz() { // 20 Mhz   T=50NS
	cycle(TSET1, TS_20MHZ_period NS);
	settime(TSET1, GPIO4, RTZ, 0.25*TS_20MHZ_period NS, 0.75 * TS_20MHZ_period NS);
	settime(TSET1, GPIO5, NRZ, 0);
	settime(TSET1, GPIO5, STROBE, 0.65 * TS_20MHZ_period NS, 0.65 * TS_20MHZ_period NS);
}

