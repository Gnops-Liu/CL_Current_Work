#include "tester.h"

AFTER_TESTING_BLOCK(test_complete) {
	output("Output from AFTER_TESTING_BLOCK, Site number %d", site_num());
	CString temp= "D:\\Summary";
	TB.Fileout(temp);
	FlowTimer.StopTimer("Total Flow ");	//Stop Flow Timer and output time
	remote_set("ui_Close", 1, -1, TRUE, INFINITE);
}

