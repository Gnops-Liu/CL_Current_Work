#include "tester.h"
#include "COF_ToolBox.h"

// *********************************************
// *****  Sequence and Binning Table file  *****
// *********************************************
PASS_BIN(pass_bin,			1,	1)
FAIL_BIN(continuity_bin,	2,	201)
FAIL_BIN(BG_trim_fail,		3,	301)

SEQUENCE_TABLE(Final_Test)
{
	SEQUENCE_TABLE_INIT
	SMIC_TEST(tb_continuity_io,		_NEXT, continuity_bin);
	SMIC_TEST(tb_continuity_dps,	_NEXT, continuity_bin);
	SMIC_TEST(tb_BG_Trim,			_NEXT, pass_bin);
	COF_SWITCH_BOARD()
	//BINLS
	LINK_TO_BIN(pass_bin)
	LINK_TO_BIN(continuity_bin)
	LINK_TO_BIN(BG_trim_fail)
}

