#include "tester.h"
#include "User.h"

TEST_TIMER TB_Timer; 
TEST_TIMER FlowTimer;


CONFIGURATION( tp_auto_flow )
{
	output("Output from CONFIGURATION, Site number %d", site_num());
	USE_SEQUENCE_TABLE(NZ3183_CP3);
}

SITE_BEGIN_BLOCK( sbb )
{
	//APG Configuration functions:
	tgmode(3);
	dps_output_mode_set(pl_VDD, t_dps_independent);
	pe_driver_mode_set(t_pe_vzmode, pl_IOPINS);
	data_strobe(0xffffffff);
	edge_strobe(pl_IOPINS, TRUE);
	// AS Here t_y0 - t_y5 is enabled
	// also t_x0 - t_x9
	numy(10);
	numx(14);
	ecr_config_set(numx(), numy(), pl_IOPINS, 0x1fff, 0x7ff);
	//As here we select False because X-address is the LSB
	x_fast_axis(true);

	//Here we select 36, cause our data bit is 32
	data_reg_width(36);
	cs_polarity_set(t_cs1, true);
	cs_polarity_set(t_cs2, true);
	cs_polarity_set(t_cs3, true);
	cs_polarity_set(t_cs4, true);
	cs_polarity_set(t_cs5, true);
	cs_polarity_set(t_cs6, true);
	cs_polarity_set(t_cs7, true);
	cs_polarity_set(t_cs8, true);
	//ecr_rcm_config_set(0x1FF, 0x00);
	
	ecr_counters_config_set(t_bit_duplicates, t_address_duplicates, t_address_duplicates, t_address_duplicates);
	ecr_all_clear();
	

	TB_Timer.Init();
	FlowTimer.Init();
	output("Executing on the Site");
}
