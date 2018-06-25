#include "tester.h"
#include "User_subroutine.h"
#include "User.h"

CSTRING_VARIABLE(CASE_FOLDER,"",""){}
BOOL_VARIABLE(UI_CREATE_DATALOG_FILE_FLAG, 1, "UI_Create_Datalog_File_Flag")
{
	if (UI_CREATE_DATALOG_FILE_FLAG)
	{
		remote_set(UI_DATALOG_SITE, 1, site_num(), TRUE, INFINITE);
		remote_set(UI_DATALOG_HOST, 1, site_num(), TRUE, INFINITE);
	}
	else
	{
		remote_set(UI_DATALOG_SITE, 0, site_num(), TRUE, INFINITE);
		remote_set(UI_DATALOG_HOST, 0, site_num(), TRUE, INFINITE);
	}
}

BOOL_VARIABLE(UI_DATALOG_SITE, 0, "")
{
	if (UI_DATALOG_SITE)
	{
		CString s1, s2, s3;
		int x, y;
		s2 = remote_get(CASE_FOLDER, 0, FALSE, 50);
		TPEGetCurrentXY(t_dut1, &x, &y);
		s3.Format("/site%d_X%d_Y%d", site_num(), x, y);
		s1 = s2 + s3 + CTime::GetCurrentTime().Format("_%y.%m.%d_%H.%M.%S.txt");

		remote_set("ui_OutputFile", s1, -1, TRUE, INFINITE);
		remote_set("ui_ClearAtTestStart", 1, -1, TRUE, INFINITE);

		s1.ReleaseBuffer();
		s2.ReleaseBuffer();
		s3.ReleaseBuffer();
		output("[Tip 0002] UI_site_datalog opened");
	}
	else
	{
		output("[Tip 0001] UI_site_datalog closed");
	}
}

BOOL_VARIABLE(UI_DATALOG_HOST,0, "")
{
	if (UI_DATALOG_HOST)
	{
		CString s1, s2, s3;
		SiteMask slave_sites_mask(0x0);
		output("[Tip 0004] UI_host_datalog opened");
		s1 = CTime::GetCurrentTime().Format("D:/Log/%y.%m.%d");
		//===============================Create 1st level folder=====================================================
		if (_access(s1,00)!= 00)
		{
			output("<COLOR=MAROON>Today's Log folder is created now</COLOR>");
			CString str1 = "md ";
			str1 += s1;
			char *str2 = str1.GetBuffer(str1.GetLength());
			str1.ReleaseBuffer();
			system(str2);
		}
		else
			output("<COLOR=MAROON>Today's Log folder have already created</COLOR>");
		//==============================Create 2nd level folder===========================================================
		if (LOT_NUM == "")
		{
			output("<COLOR=MAROON>There is no LotID read into TP, Maybe you are in UI mode!!</COLOR>");
			s2 = s1 + CTime::GetCurrentTime().Format("/Demo_%H.%M");
		}
		else
		{
			output("<COLOR=MAROON>Successfully get the LotID!!</COLOR>");
			s3.Format("/%s_", LOT_NUM);
			s2 = s1 + s3 + CTime::GetCurrentTime().Format("%H.%M");
		}
		//==========================save down the Case_folder's Path=========================================================
		CASE_FOLDER = s2;
		char *Case_folder = CASE_FOLDER.GetBuffer(CASE_FOLDER.GetLength());
		output("Host datalog would be saved in \"%s\"", Case_folder);
		//===========================Create host datalog file name ==========================================================
		CString f = "/HOST.TXT";
		s2 += f;

		remote_set("ui_OutputFile", s2, -1, TRUE, INFINITE);
		remote_set("ui_ClearAtTestStart", 1, -1, TRUE, INFINITE);

		s1.ReleaseBuffer();
		s2.ReleaseBuffer();
		s3.ReleaseBuffer();
	}
	else
		output("[Tip 0004] UI_host_datalog closed");
}

#ifdef need_to_be_delete
INT_VARIABLE(PRTF_COUNTER, 0, "Print_dut_count")
{
	CString str1;
	int x, y;
	int index = 0;
	str1.Format("D:/Log/Colins/Zx297100/summary/%s_%s_trims.xls", LOT_NUM, WFR_SLOT_ID);
	output("D:/Log/Colins/Zx297100/summary/%s_%s_trims.xls", LOT_NUM, WFR_SLOT_ID);

	SoftwareOnlyActiveDutIterator Duts_Loop;
	while (Duts_Loop.More())
	{
		DutNum dut = active_dut_get();
		if (site_num() == 2 && dut == 0)		index = 1;
		else if (site_num() == 2 && dut == 1)	index = 2;
		else if (site_num() == 3 && dut == 0)	index = 3;
		else if (site_num() == 3 && dut == 1)	index = 4;
		else if (site_num() == 4 && dut == 0)	index = 5;
		else	index = 0;
		TPEGetCurrentXY(dut, &x, &y);
		PRTF_COUNTER++;
		fileout.open(str1, ios::app);
		fileout << index << '\t';
		fileout << x << '\t' << y << '\t';
		fileout << setw(2) << setfill('0') << dec;
		//fileout << MAIN_BGP.record[dut];
		fileout << '\t';
		for (int i = 0; i < 16; i++)
		{
			fileout << '\t';
		//	fileout << MAIN_BGP.logout[i][dut];
		}
		fileout << endl;
		fileout.close();
	}
	str1.ReleaseBuffer();
}
#endif