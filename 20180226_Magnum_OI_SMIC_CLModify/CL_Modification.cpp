//
// Following func is modified by Colin Liu[CN],@2017.12.11
// Force on add function and Improve MganumII OI for tsk.
//
//
#include "tester.h"
#include "tester.h"
#include "resource.h"
#include "Driver.h"
#include "Automation.h"
#include "dialog.h"
#include "Magnum_OI.h"
#include "wafermap.h"
#include <math.h>
#include <io.h>


void  build_relationship(CString SourceStr_Group, CString ResultStr_Group, CString SourceStr, CString *ResultStr)
{
//PART 1: Judge the TP number of TP_Group
	CString Buffer = SourceStr_Group;
	char * buffer = SourceStr_Group.GetBuffer(SourceStr_Group.GetLength());
	CArray<int, int> SourceStr_locate;
	CStringArray SR_Group;
	CStringArray RS_Group;
	int record = 0;
	
	while (Buffer.Find(',') != -1)
	{
		SourceStr_locate.Add(Buffer.Find(','));
		Buffer.SetAt(Buffer.Find(','), ' ');

	}
	SourceStr_locate.Add(SourceStr_Group.GetLength());

	for (int i = 0; i < SourceStr_locate.GetSize()-1; i++)
	{
		SR_Group.Add("");
		for (int j = SourceStr_locate.GetAt(i)+1; j < SourceStr_locate.GetAt(i + 1); j++)
		{
			SR_Group.ElementAt(i) += buffer[j];
		}
		output(SR_Group.GetAt(i));
		if (SR_Group.ElementAt(i) == SourceStr)
		{
			record = i;
		}
	}
	output("you have select %d tp", record);
//PART 2: Affect
	Buffer = ResultStr_Group;
	buffer = ResultStr_Group.GetBuffer(ResultStr_Group.GetLength());
	SourceStr_locate.RemoveAll();
	while (Buffer.Find(',') != -1)
	{
		SourceStr_locate.Add(Buffer.Find(','));
		Buffer.SetAt(Buffer.Find(','), ' ');
	}
	SourceStr_locate.Add(ResultStr_Group.GetLength());

	for (int i = 0; i < SourceStr_locate.GetSize() - 1; i++)
	{
		RS_Group.Add("");
		for (int j = SourceStr_locate.GetAt(i) + 1; j < SourceStr_locate.GetAt(i + 1); j++)
		{
			RS_Group.ElementAt(i) += buffer[j];
		}
		output(RS_Group.GetAt(i));
	}
	*ResultStr = RS_Group.ElementAt(record);
	output("Now you have selected %s", *ResultStr);

}

void check_server()
{
	CString Checking_Path = "Y:\\Engineering";
	if (_access(Checking_Path, 00) != 00)
		fatal("[M2 OI] Server disconnect");
}