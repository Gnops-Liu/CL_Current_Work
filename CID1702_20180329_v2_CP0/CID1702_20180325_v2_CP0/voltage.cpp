#include "tester.h"

// voltage sets

void power_down()
{
	dps(0 V, pl_dps);
	hv_voltage_set(0 V, pl_hv);      //VPP
	dpo_voltage_set(0 V, pl_dpo);    //VDD18
	dpo_hv_voltage_set(0 V, pl_dpohv);    //VNN
	vil(0 V, pl_all_pins);
	vih(0 V, pl_all_pins);
	vol(0 V, pl_all_pins);
	voh(0 V, pl_all_pins);
	vz(0 V,  pl_all_pins);
	iol(0 A, pl_all_pins);
	ioh(0 A, pl_all_pins);
}
DOUBLE_VARIABLE(vol_set, 3.3, "voltage")
{}



void vs_set_H()
{
	dpo_voltage_set(3 V, pl_dpo); //VCC
	vih(1.8 V, pl_all_pins);
	vil(0 V, pl_all_pins);

	dps(1.32 V, pl_dps);           //TST

	vih(1.815 V, pl_DVDD_1P5);     //VDD15
	vil(0 V,     pl_DVDD_1P5);

	vol(1.5 V);
	voh(1.5 V);
	vz(1.5 V, pl_all_pins);
	iol(1 MA, pl_all_pins);
	ioh(1 MA, pl_all_pins);

}

void vs_set()
{
	dpo_voltage_set(3 V, pl_dpo); //VCC
	vih(1.8 V, pl_all_pins);
	vil(0 V, pl_all_pins);

	dps(1.32 V, pl_dps);           //TST

	vih(1.515 V, pl_DVDD_1P5);     //VDD15
	vil(0 V, pl_DVDD_1P5);

	vol(1.5 V);
	voh(1.5 V);
	vz(1.5 V, pl_all_pins);
	iol(1 MA, pl_all_pins);
	ioh(1 MA, pl_all_pins);

}

void vs_set_L()
{
	dpo_voltage_set(3 V, pl_dpo); //VCC
	vih(1.8 V, pl_all_pins);
	vil(0 V, pl_all_pins);

	dps(1.32 V, pl_dps);           //TST

	vih(1.515 V, pl_DVDD_1P5);     //VDD15
	vil(0 V, pl_DVDD_1P5);

	vol(1.5 V);
	voh(1.5 V);
	vz(1.5 V, pl_all_pins);
	iol(1 MA, pl_all_pins);
	ioh(1 MA, pl_all_pins);

}
//void v_2v()
//{
//	dps(2.5 V, pl_power);
//	vih(2.5 V);
//	vil(0 V);
//	vol(1 V);
//	voh(1.5 V);
//	vz(1 V, pl_io_pins);
//	iol(1 MA, pl_io_pins);
//	ioh(1 MA, pl_io_pins);
//	measure(TRUE);
//}
//void v_3v()
//{
//	dps(vol_set V, pl_power);
//	vih(vol_set V);
//	vil(0 V);
//	vol(0.5*vol_set V);
//	voh(0.5*vol_set V);
//	vz(0.2*vol_set V, pl_io_pins);
//	iol(5 MA, pl_io_pins);
//	ioh(5 MA, pl_io_pins);
//	measure(TRUE);
//}
