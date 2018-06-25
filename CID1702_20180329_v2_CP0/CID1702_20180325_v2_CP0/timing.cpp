#include "tester.h"


// Setup timing functions 

INT_VARIABLE(timing, 30, "timing")
{}
void ts_10mhz(void) {

	edge_strobe(pl_SDA, true);
	cycle(TSET1, timing NS);

	settime(TSET1, pl_RESET, NRZ, 0.01*timing NS);
	settime(TSET1, pl_CLK, RTZ, timing*0.1 NS, timing*0.6 NS);
	settime(TSET1, pl_SDA, NRZ, 0.01*timing NS);
	settime(TSET1, pl_SDA, STROBE, timing*0.8 NS);

}






