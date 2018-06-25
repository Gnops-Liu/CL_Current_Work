#include "tester.h"
#include "user.h"

HOST_BEGIN_BLOCK( my_host_block_name )
{
	//CString s;
	//s = CTime::GetCurrentTime().Format("D:/Log/%y%m%d_%H%M%S");
	//CString t = "NZ3182_HOST.TXT";
	//s += t;
	//remote_set("ui_OutputFile", s, -1, TRUE, INFINITE);

	//output("%s Rev 1",remote_get("ui_TestProgName",-1));
	//output("Executing on the host");
}

#if 0
// Activate AutoTDR later.....

BOOL_VARIABLE(TDR_EXECUTE, FALSE, 0) {}

void read_tpgm_ini()
{
	CString ini = "C:\\nextest\\_production\\tpgm.ini";

	if(!set_values_from_file(ini))
	{
		output("could not read file %s, using default values", ini);
	}
}

TDR_BLOCK(tdr) {
	
	read_tpgm_ini();

	//if(message_box("<<< TDR WILL START >>> \nClick OK to do TDR\nClick CANCEL to skip TDR ",MB_OKCANCEL) == IDCANCEL)
	//	return;

	if(!TDR_EXECUTE) return;

	CString msg; // For readability in this documentation
	// TDR min/max limits (reused later)
	double min_limit = 0 NS;
	double max_limit = 10.0 NS;
	// db_tdr() performs TDR on the pin list = pl_all_pins
	output("Executing db_tdr()...");
	BOOL tdr_OK = db_tdr(pl_all_pins,min_limit,max_limit);

	HDTesterPin tpin;
	if(! tdr_OK) {
		output("Bad TDR measurement(s) on Site- %d",site_num());
		int index;
		for(index = 0;pin_info(pl_all_pins,index,&tpin); // See pin_info()
		++index) {
			double result = db_get_tdr(tpin); // db_get_tdr()
			if(result == 0)
			output(" Bad pin => %s",testerpin_name(tpin));
		}
		// See Note:. The next 4 statements are not needed using
		// software release h3.5.xx using Magnum 1/2/2x.
		msg = "db_tdr() returned FALSE on Site-";
		msg += vFormat("%d\n",site_num());
		msg += "See messages in site window";
		msg += "UI will be exited after clicking OK to prevent program loading";
		//message_box(msg,ID_OK); // Display msg in dialog
		message_box(msg,MB_OK);
		remote_set( "ui_Exit", 0, -1, TRUE, INFINITE );
	}
	else{// db_tdr() returned TRUE
		// Check measured TDR values against user limits
		BOOL ok = TRUE;
		//min_limit = 1.4 NS;
		//max_limit = 3.5 NS;
		// Use default for now. Can change later
		min_limit = 0 NS;
		max_limit = 10 NS;
		int index;
		for(index = 0;
		pin_info(pl_all_pins,index,&tpin); // See pin_info()
		++index) {
			double result = db_get_tdr(tpin); // db_get_tdr()
			if((result < min_limit) || (result > max_limit)) {
				ok = FALSE;
				msg = vFormat("Bad TDR value on site- %d",site_num());
				msg += vFormat(", tester pin: %s.",
				testerpin_name(tpin));
				msg += "See messages in site window";
				msg += "UI will be exited after clicking OK to prevent program loading";
				output("msg");
				//message_box(msg,ID_OK); // Display msg in dialog
				message_box(msg,MB_OK);
				remote_set( "ui_Exit", 0, -1, TRUE, INFINITE );
			}
		}
		if(ok){ // Program DUT board EEPROM
			BOOL EE_write_OK = db_write_tdr();

			if(! EE_write_OK) { // The EEPROM write had an error...
				msg = "TDR write to DUT board EEPROM failed on site-";
				msg += vFormat("%d\n",site_num());
				msg += "See messages in site window";
				msg += "UI will be exited after clicking OK to prevent program loading";
				output("%s",msg);
				//message_box(msg,ID_OK); // Display msg in dialog
				message_box(msg,MB_OK);
				remote_set( "ui_Exit", 0, -1, TRUE, INFINITE );
			}
		}
	}
}
#endif