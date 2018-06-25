#include "tester.h"

// voltage sets
DOUBLE_VARIABLE(VCCMAX, 5.00, "VoltSet VCCMAX") { }
DOUBLE_VARIABLE(LVCC, 5.00, "VoltSet VCCMIN") { }
DOUBLE_VARIABLE(NVCC, 5.00, "VoltSet VCCNOM") { }
DOUBLE_VARIABLE(HVCC, 5.00, "VoltSet VCCMAX") { }

void power_down()
{
	dps(0 V, pl_VDD);
	dps_disconnect(pl_VDD);
	vih(0);
	vil(0);
	voh(0);
	vol(0);
	vihh(0);
	ioh(0);
	iol(0);
	vz(0);
//	Delay(10 MS);
	disconnect(pl_IOPINS);
	ptu_disconnect(pl_CMS_PAD);
	ptu_disconnect(pl_VDD_PAD);
	ptu_disconnect(pl_PWRWAKE_PAD);
//	Delay(10 MS);
}

void rst_lvl()
{
	//dps(0 V, pl_VDD);
	vih(0);
	vil(0);
	voh(0);
	vol(0);
	vihh(0);
	ioh(0 );
	iol(0 );
	vz(0);

}


void func_lvl()
{
	dps_connect(pl_VDD);
	pin_connect(pl_IOPINS);
	disconnect(pl_VDD_PAD);

	dps(3.3 V, pl_VDD);
	vih(3.3 V, pl_IOPINS_NO_PWRWAKE);
	vil(0.0 V, pl_IOPINS_NO_PWRWAKE);
	voh(2.4 V, pl_IOPINS_NO_PWRWAKE);
	vol(0.6 V, pl_IOPINS_NO_PWRWAKE);

	vih(3.1 V, pl_PWRWAKE_PAD);
	vil(0.0 V, pl_PWRWAKE_PAD);
	voh(2.4 V, pl_PWRWAKE_PAD);
	vol(0.6 V, pl_PWRWAKE_PAD);
	ioh(0 );
	iol(0 );
	vz(1.65 V, pl_IOPINS);

}

void ADC_lvl()
{
	dps_connect(pl_VDD);
	pin_connect(pl_IOPINS);
	disconnect(pl_VDD_PAD);

	dps(3.3 V, pl_VDD);
	vih(3.3 V, pl_IOPINS_NO_PWRWAKE);
	vil(0.0 V, pl_IOPINS_NO_PWRWAKE);
	voh(2.4 V, pl_IOPINS_NO_PWRWAKE);
	vol(0.6 V, pl_IOPINS_NO_PWRWAKE);

	vih(3.1 V, pl_PWRWAKE_PAD);
	vil(0.0 V, pl_PWRWAKE_PAD);
	voh(2.4 V, pl_PWRWAKE_PAD);
	vol(0.6 V, pl_PWRWAKE_PAD);
	ioh(0);
	iol(0);
	vz(1.65 V, pl_IOPINS);

}

void Trim_lvl()
{
	dps_connect(pl_VDD);
	pin_connect(pl_IOPINS);
	disconnect(pl_VDD_PAD);
	dps(3.3 V, pl_VDD);
	vih(3.3 V, pl_IOPINS);
	vil(0.0 V, pl_IOPINS);
	voh(2.4 V, pl_IOPINS);
	vol(0.6 V, pl_IOPINS);
	ioh(0);
	iol(0);
	vz(1.65 V, pl_IOPINS);

}

void otpLo_lvl()
{
	dps_connect(pl_VDD);
	pin_connect(pl_IOPINS);
	disconnect(pl_VDD_PAD);
	dps(2.0 V, pl_VDD);
	vih(2.0 V);
	vil(0 V);
	voh(1.0 V);
	vol(0.6 V);
	ioh(0);
	iol(0);
	vz(1.0 V, pl_IOPINS);

}

void otpHi_lvl()
{
	dps_connect(pl_VDD);
	pin_connect(pl_IOPINS);
	disconnect(pl_VDD_PAD);
	dps(3.6 V, pl_VDD);
	vih(3.6 V);
	vil(0 V);
	voh(2.8 V);
	vol(0.6 V);
	ioh(0);
	iol(0);
	vz(1.8 V, pl_IOPINS);

}

void vihl_lvl()
{
	dps_connect(pl_VDD);
	pin_connect(pl_IOPINS);
	disconnect(pl_VDD_PAD);
	dps(2.31 V, pl_VDD);
	vih(2.31 V);
	vil(0.99 V);
	voh(2.8 V);
	vol(0.6 V);
	ioh(0);
	iol(0);
	vz(1.15 V, pl_IOPINS);

}

void ramist_lvl()
{
	dps_connect(pl_VDD);
	pin_connect(pl_IOPINS);
	disconnect(pl_VDD_PAD);
	dps(0.0 V, pl_VDD);
	vih(3.0 V, pl_CMS_PAD);
	vil(0.0 V, pl_CMS_PAD);
	voh(2.4 V, pl_CMS_PAD);
	vol(0.6 V, pl_CMS_PAD);

	vih(1.7 V, pl_XT1_PAD);
	vil(0.0 V, pl_XT1_PAD);
	voh(2.4 V, pl_XT1_PAD);
	vol(0.6 V, pl_XT1_PAD);

	vih(3.0 V, pl_PWRWAKE_PAD);
	vil(0.0 V, pl_PWRWAKE_PAD);
	voh(2.4 V, pl_PWRWAKE_PAD);
	vol(0.6 V, pl_PWRWAKE_PAD);
	ioh(0);
	iol(0);
	vz(1.5 V, pl_CMS_PAD);
	vz(0.85 V, pl_XT1_PAD);

}

void Istand_lvl()
{
	dps_connect(pl_VDD);
	pin_connect(pl_IOPINS);
	disconnect(pl_VDD_PAD);
	dps(3.0 V, pl_VDD);
	vih(2.9 V, pl_IOPINS_NO_PWRWAKE);
	vil(0.0 V, pl_IOPINS_NO_PWRWAKE);
	voh(2.4 V, pl_IOPINS_NO_PWRWAKE);
	vol(0.6 V, pl_IOPINS_NO_PWRWAKE);

	vih(2.7 V, pl_PWRWAKE_PAD);
	vil(0.0 V, pl_PWRWAKE_PAD);
	voh(2.4 V, pl_PWRWAKE_PAD);
	vol(0.6 V, pl_PWRWAKE_PAD);
	ioh(0);
	iol(0);
	vz(1.5 V, pl_IOPINS);

}



