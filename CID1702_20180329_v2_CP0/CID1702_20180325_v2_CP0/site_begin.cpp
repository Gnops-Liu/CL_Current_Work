#include "tester.h"
#include "User.h"

// *****************************************************
// *****  CONFIGURATION and SITE_BEGIN_BLOCK file  *****
// *****************************************************
// 
// Specify tables and maps using the CONFIGURATION macro and
// fill in your SITE_BEGIN_BLOCK in this file.  If you have only
// a single type of each table, you may omit the CONFIGURATION
// macro and the system software will automatically select the
// single tables.  The SITE_BEGIN_BLOCK is used for one-time
// hardware and software initializations.  Before executing
// the SITE_BEGIN_BLOCK, the system software sets the tester
// hardware to its default state.
//
// Examples of the CONFIGURATION macro and the SITE_BEGIN_BLOCK
// are below.
// 
// CONFIGURATION( boot_block_tsop )
// {
//		USE_PIN_ASSIGNMENTS( tsop );
//		USE_PIN_SCRAMBLE( tsop );
//		USE_VIHH_MAPS( boot_block );
//		USE_SEQUENCE_TABLE( boot_block );
// }
//
// SITE_BEGIN_BLOCK( boot_block )
// {
//		/*  Put hardware and software initializations here. */
// }
//
// Enter your CONFIGURATION macros and SITE_BEGIN_BLOCK below.
// ********************************************************

TEST_TIMER TB_Timer; 
TEST_TIMER FlowTimer;

//extern CDriver Adventurer_Peter;
CONFIGURATION( tp_auto_flow )
{
}

SITE_BEGIN_BLOCK( sbb )
{
	
	numx(6);
	numy(11);
	x_fast_axis(true);



	//Here we select 36, cause our data bit is 32
	data_reg_width(36);
	cs_polarity_set(t_cs1, true);
	cs_polarity_set(t_cs2, true);

	edge_strobe(pl_SDA, true);

	ecr_config_set(numx(), numy(), pl_SDA);

	TB_Timer.Init();
	FlowTimer.Init();
	output("Executing on the Site");
}
