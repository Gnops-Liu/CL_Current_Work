#include "tester.h"


// Setup timing functions 
void ts_20_Mhz() { // 20 Mhz   T=50NS
	cycle(	TSET1,  50 NS);
	settime(TSET1, GPIO0, NRZ, 0 NS);
	settime(TSET1, GPIO1, RTZ, 25 NS, 50 NS);
	settime(TSET1, GPIO2, NRZ, 0 NS);
	settime(TSET1, GPIO3, NRZ, 0 NS);
	settime(TSET1, GPIO4, NRZ, 0 NS);
	settime(TSET1, GPIO5, STROBE, 25 NS, 25 NS);
}

