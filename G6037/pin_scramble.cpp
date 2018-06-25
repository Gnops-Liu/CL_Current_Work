#define TESTER_H "tester.h"
#include TESTER_H

#define PS_GPIB5_BYTE(num) 			 \
SCRAMBLE_MAP(PS##num)				 \
{									 \
	SCRAMBLE(GPIO4, t_cs1);			 \
	SCRAMBLE(GPIO5, t_d##num);		 \
}									 \


// ***********************************
// ****  Pin Scramble Maps file  *****
// ***********************************

PIN_SCRAMBLE(ps_eflash) 
{
//SCRAMBLE MAP 1-8
	SCRAMBLE_MAP(PS8)	
	{
		SCRAMBLE(GPIO4, t_cs1);
		SCRAMBLE(GPIO5, t_d0);
	}
	SCRAMBLE_MAP(PS1)
	{
		SCRAMBLE(GPIO4, t_cs1);
		SCRAMBLE(GPIO5, t_d1);
	}
	SCRAMBLE_MAP(PS2)
	{
		SCRAMBLE(GPIO4, t_cs1);
		SCRAMBLE(GPIO5, t_d2);
	}
	SCRAMBLE_MAP(PS3)
	{
		SCRAMBLE(GPIO4, t_cs1);
		SCRAMBLE(GPIO5, t_d3);
	}
	SCRAMBLE_MAP(PS4)
	{
		SCRAMBLE(GPIO4, t_cs1);
		SCRAMBLE(GPIO5, t_d4);
	}
	SCRAMBLE_MAP(PS5)
	{
		SCRAMBLE(GPIO4, t_cs1);
		SCRAMBLE(GPIO5, t_d5);
	}
	SCRAMBLE_MAP(PS6)
	{
		SCRAMBLE(GPIO4, t_cs1);
		SCRAMBLE(GPIO5, t_d6);
	}
	SCRAMBLE_MAP(PS7)
	{
		SCRAMBLE(GPIO4, t_cs1);
		SCRAMBLE(GPIO5, t_d7);
	}






	//PS_GPIB5_BYTE(1)
	//PS_GPIB5_BYTE(2)
	//PS_GPIB5_BYTE(3)
	//PS_GPIB5_BYTE(4)
	//PS_GPIB5_BYTE(5)
	//PS_GPIB5_BYTE(6)
	//PS_GPIB5_BYTE(7)
//	SCRAMBLE_MAP(PS2)	{
//		SCRAMBLE(eFlash_sclk,	t_cs1)
//		SCRAMBLE(eFlash_sce,	t_cs2)
//		SCRAMBLE(eFlash_porstn, t_cs3)
//		SCRAMBLE(pmu_rst,		t_cs4)
//		SCRAMBLE(pmu_cs,		t_cs5)
////		SCRAMBLE(eFlash_sio_i,  t_cs6)
//		SCRAMBLE(eFlash_sio_i,	t_d23)
//	}
//	SCRAMBLE_MAP(PS3)	{
//		SCRAMBLE(eFlash_sclk, t_cs1)
//		SCRAMBLE(eFlash_sce, t_cs2)
//		SCRAMBLE(eFlash_porstn, t_cs3)
//		SCRAMBLE(pmu_rst, t_cs4)
//		SCRAMBLE(pmu_cs, t_cs5)
////		SCRAMBLE(eFlash_sio_i,  t_cs6)
//		SCRAMBLE(eFlash_sio_i, t_d15)
//	}
//	SCRAMBLE_MAP(PS4)	{
//		SCRAMBLE(eFlash_sclk,	t_cs1)
//		SCRAMBLE(eFlash_sce,	t_cs2)
//		SCRAMBLE(eFlash_porstn, t_cs3)
//		SCRAMBLE(pmu_rst,		t_cs4)
//		SCRAMBLE(pmu_cs,		t_cs5)
//		SCRAMBLE(eFlash_sio_i,	t_cs6)
//		SCRAMBLE(eFlash1_sio_o, t_d15)
//	}
//	SCRAMBLE_MAP(PS5)	{
//		SCRAMBLE(eFlash_sclk,	t_cs1)
//		SCRAMBLE(eFlash_sce,	t_cs2)
//		SCRAMBLE(eFlash_porstn, t_cs3)
//		SCRAMBLE(pmu_rst,		t_cs4)
//		SCRAMBLE(pmu_cs,		t_cs5)
//		SCRAMBLE(eFlash_sio_i,	t_cs6)
//		SCRAMBLE(eFlash2_sio_o, t_d15)
//	}
//	SCRAMBLE_MAP(PS6)	{
//		SCRAMBLE(eFlash_sclk,	t_cs1)
//		SCRAMBLE(eFlash_sce,	t_cs2)
//		SCRAMBLE(eFlash_porstn, t_cs3)
//		SCRAMBLE(pmu_rst,		t_cs4)
//		SCRAMBLE(pmu_cs,		t_cs5)
//		SCRAMBLE(eFlash_sio_i,  t_cs6)
//		SCRAMBLE(pmu_rxd,		t_d9)
//	}
//	SCRAMBLE_MAP(PS7)	{
//		SCRAMBLE(eFlash_sclk,	t_cs1)
//		SCRAMBLE(eFlash_sce,	t_cs2)
//		SCRAMBLE(eFlash_porstn, t_cs3)
//		SCRAMBLE(pmu_rst,		t_cs4)
//		SCRAMBLE(pmu_cs,		t_cs5)
//		SCRAMBLE(eFlash_sio_i,  t_cs6)
//		SCRAMBLE(pmu_rxd,		t_d17)
//	}
//	SCRAMBLE_MAP(PS8)	{
//		SCRAMBLE(eFlash_sclk, t_cs1)
//		SCRAMBLE(eFlash_sce, t_cs2)
//		SCRAMBLE(eFlash_porstn, t_cs3)
//		SCRAMBLE(pmu_rst, t_cs4)
//		SCRAMBLE(pmu_cs, t_cs5)
//		SCRAMBLE(eFlash_sio_i, t_cs6)
//		SCRAMBLE(pmu_txd, t_d17)
//	}
//	SCRAMBLE_MAP(PS9)	{
//		SCRAMBLE(eFlash_sclk, t_cs1)
//		SCRAMBLE(eFlash_sce, t_cs2)
//		SCRAMBLE(eFlash_porstn, t_cs3)
//		SCRAMBLE(pmu_rst, t_cs4)
//		SCRAMBLE(pmu_cs, t_cs5)
//		SCRAMBLE(eFlash_sio_i, t_cs6)
//		SCRAMBLE(pmu_rxd, t_d0)
//	}
//	SCRAMBLE_MAP(PS30)	{
//		SCRAMBLE(eFlash_sclk,	t_lvm)
//		SCRAMBLE(eFlash_sce,	t_lvm)
//		SCRAMBLE(eFlash_porstn, t_lvm)
//		SCRAMBLE(pmu_rst,		t_lvm)
//		SCRAMBLE(pmu_cs,		t_lvm)
//		SCRAMBLE(pmu_txd,		t_lvm)
//	}
//	SCRAMBLE_MAP(PS64)	{
//		SCRAMBLE(eFlash_sclk,	t_cs1)
//		SCRAMBLE(eFlash_sce,	t_cs2)
//		SCRAMBLE(eFlash_porstn, t_cs3)
//		SCRAMBLE(pmu_rst,		t_cs4)
//		SCRAMBLE(pmu_cs,		t_cs5)
//		SCRAMBLE(eFlash_sio_i,	t_cs6)
//	}
}