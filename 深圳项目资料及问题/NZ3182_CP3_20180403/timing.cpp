#include "tester.h"


void ts_default()
{

	cycle(TS1, 100 NS);
	settime(TS1, pl_IOPINS_NO_GPIO4, NRZ, 0 NS);
	settime(TS1, pl_IOPINS_NO_GPIO4, STROBE, 80.0 NS, 80.0 NS);

	settime(TS1, pl_GPIO4_PAD, RTZ, 50.0 NS, 100 NS);
	settime(TS1, pl_GPIO4_PAD, STROBE, 80.0 NS, 80.0 NS);


	cycle(TS2, 30.518 US);
	settime(TS2, pl_IOPINS_NO_GPIO4, NRZ, 0 US);
	settime(TS2, pl_IOPINS_NO_GPIO4, STROBE, 28.0 US, 28.0 US);

	settime(TS2, pl_GPIO4_PAD, RTZ, 15.23 US, 30.518 US);
	settime(TS2, pl_GPIO4_PAD, STROBE, 28.0 US, 28.0 US);
	
}

void ts_std()
{

	cycle(TS1, 100 NS);
	settime(TS1, pl_IOPINS_NO_GPIO4, NRZ, 0 NS);
	settime(TS1, pl_IOPINS_NO_GPIO4, STROBE, 40.0 NS, 40.0 NS);

	settime(TS1, pl_GPIO4_PAD, RTZ, 50.0 NS, 100 NS);
	settime(TS1, pl_GPIO4_PAD, STROBE, 40.0 NS, 40.0 NS);


	cycle(TS2, 30.518 US);
	settime(TS2, pl_IOPINS_NO_GPIO4_XT1_CMS, NRZ, 0 US);
	settime(TS2, pl_IOPINS_NO_GPIO4_XT1_CMS, STROBE, 28.0 US, 28.0 US);

	settime(TS2, pl_GPIO4_PAD, RTZ, 15.23 US, 30.518 US);
	settime(TS2, pl_GPIO4_PAD, STROBE, 28.0 US, 28.0 US);

	settime(TS2, pl_XT1_PAD, RTZ, 15.23 US, 30.518 US);
	settime(TS2, pl_XT1_PAD, STROBE, 28.0 US, 28.0 US);

	settime(TS2, pl_CMS_PAD, NRZ, 0 US);
	settime(TS2, pl_CMS_PAD, STROBE, 28.0 US, 28.0 US);

}

void ts_std1()
{

	cycle(TS1, 200 NS);
	settime(TS1, pl_IOPINS_NO_GPIO4, NRZ, 0 NS);
	settime(TS1, pl_IOPINS_NO_GPIO4, STROBE, 80.0 NS, 80.0 NS);

	settime(TS1, pl_GPIO4_PAD, RTZ, 100.0 NS,200 NS);
	settime(TS1, pl_GPIO4_PAD, STROBE, 80.0 NS, 80.0 NS);


	cycle(TS2, 30.518 US);
	settime(TS2, pl_IOPINS_NO_GPIO4_XT1_CMS, NRZ, 0 US);
	settime(TS2, pl_IOPINS_NO_GPIO4_XT1_CMS, STROBE, 28.0 US, 28.0 US);

	settime(TS2, pl_GPIO4_PAD, RTZ, 15.23 US, 30.518 US);
	settime(TS2, pl_GPIO4_PAD, STROBE, 28.0 US, 28.0 US);

	settime(TS2, pl_XT1_PAD, RTZ, 15.23 US, 30.518 US);
	settime(TS2, pl_XT1_PAD, STROBE, 28.0 US, 28.0 US);

	settime(TS2, pl_CMS_PAD, NRZ, 0 US);
	settime(TS2, pl_CMS_PAD, STROBE, 28.0 US, 28.0 US);

}

void ts_Trim()
{

	cycle(TS1, 100 NS);
	settime(TS1, pl_IOPINS_NO_GPIO4, NRZ, 0 NS);
	settime(TS1, pl_IOPINS_NO_GPIO4, STROBE, 80.0 NS, 80.0 NS);

	settime(TS1, pl_GPIO4_PAD, RTZ, 50.0 NS, 100 NS);
	settime(TS1, pl_GPIO4_PAD, STROBE, 80.0 NS, 80.0 NS);


	cycle(TS2, 30.518 US);
	settime(TS2, pl_IOPINS_NO_GPIO4_XT1_CMS, NRZ, 0 US);
	settime(TS2, pl_IOPINS_NO_GPIO4_XT1_CMS, STROBE, 28.0 US, 28.0 US);

	settime(TS2, pl_GPIO4_PAD, RTZ, 15.23 US, 30.518 US);
	settime(TS2, pl_GPIO4_PAD, STROBE, 28.0 US, 28.0 US);

	settime(TS2, pl_XT1_PAD, RTZ, 15.23 US, 30.518 US);
	settime(TS2, pl_XT1_PAD, STROBE, 28.0 US, 28.0 US);

}

void ts_ramist()
{

	cycle(TS1, 30.518 US);
	settime(TS1, pl_IOPINS_NO_XT1, NRZ, 0 NS);
	settime(TS1, pl_IOPINS_NO_XT1, STROBE, 10.0 US, 10.0 US);

	settime(TS1, pl_XT1_PAD, RTZ, 15.23 US, 30.518 US);
	settime(TS1, pl_XT1_PAD, STROBE, 10.0 US, 10.0 US);


	cycle(TS2, 30.518 US);
	settime(TS2, pl_IOPINS_NO_XT1, NRZ, 0 US);
	settime(TS2, pl_IOPINS_NO_XT1, STROBE, 28.0 US, 28.0 US);

	settime(TS2, pl_XT1_PAD, RTZ, 15.23 US, 30.518 US);
	settime(TS2, pl_XT1_PAD, STROBE, 28.0 US, 28.0 US);

}

void ts_Istand()
{

	cycle(TS1, 30.518 US);
	settime(TS1, pl_IOPINS_NO_GPIO4_XT1, NRZ, 0 NS);
	settime(TS1, pl_IOPINS_NO_GPIO4_XT1, STROBE, 10.0 US, 10.0 US);

	settime(TS1, pl_GPIO4_PAD, RTZ, 15.23 US, 30.518 US);
	settime(TS1, pl_GPIO4_PAD, STROBE, 10.0 US, 10.0 US);
	settime(TS1, pl_XT1_PAD, RTZ, 15.23 US, 30.518 US);
	settime(TS1, pl_XT1_PAD, STROBE, 28.0 US, 28.0 US);


	cycle(TS2, 30.518 US);
	settime(TS2, pl_IOPINS_NO_GPIO4_XT1, NRZ, 0 NS);
	settime(TS2, pl_IOPINS_NO_GPIO4_XT1, STROBE, 10.0 US, 10.0 US);

	settime(TS2, pl_GPIO4_PAD, RTZ, 15.23 US, 30.518 US);
	settime(TS2, pl_GPIO4_PAD, STROBE, 28.0 US, 28.0 US);

	settime(TS2, pl_XT1_PAD, RTZ, 15.23 US, 30.518 US);
	settime(TS2, pl_XT1_PAD, STROBE, 28.0 US, 28.0 US);

}

void ts_ADC()
{

	//cycle(TS1, 100 NS);
	//settime(TS1, pl_IOPINS_NO_GPIO4, NRZ, 0 NS);
	//settime(TS1, pl_IOPINS_NO_GPIO4, STROBE, 80.0 NS, 80.0 NS);

	//settime(TS1, pl_GPIO4_PAD, RTZ, 50.0 NS, 100 NS);
	//settime(TS1, pl_GPIO4_PAD, STROBE, 80.0 NS, 80.0 NS);

	cycle(TS1, 200 NS);
	settime(TS1, pl_IOPINS_NO_GPIO4, NRZ, 0 NS);
	settime(TS1, pl_IOPINS_NO_GPIO4, STROBE, 160.0 NS, 160.0 NS);

	settime(TS1, pl_GPIO4_PAD, RTZ, 50.0 NS, 100 NS);
	settime(TS1, pl_GPIO4_PAD, STROBE, 160.0 NS, 160.0 NS);


	cycle(TS2, 30.518 US);
	settime(TS2, pl_IOPINS_NO_GPIO4_XT1, NRZ, 0 US);
	settime(TS2, pl_IOPINS_NO_GPIO4_XT1, STROBE, 28.0 US, 28.0 US);

	settime(TS2, pl_GPIO4_PAD, RTZ, 15.23 US, 30.518 US);
	settime(TS2, pl_GPIO4_PAD, STROBE, 28.0 US, 28.0 US);

	settime(TS2, pl_XT1_PAD, RTZ, 15.23 US, 30.518 US);
	settime(TS2, pl_XT1_PAD, STROBE, 28.0 US, 28.0 US);

	cycle(TS3, 33 US);
	settime(TS3, pl_IOPINS_NO_GPIO4_XT1, NRZ, 0 US);
	settime(TS3, pl_IOPINS_NO_GPIO4_XT1, STROBE, 5.0 US, 5.0 US);

	settime(TS3, pl_GPIO4_PAD, RTZ, 16.5 US, 33 US);
	settime(TS3, pl_GPIO4_PAD, STROBE, 5.0 US, 5.0 US);

	settime(TS3, pl_XT1_PAD, RTZ, 16.5 US, 33 US);
	settime(TS3, pl_XT1_PAD, STROBE, 5.0 US, 5.0 US);

}



