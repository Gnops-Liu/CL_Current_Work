#include "tester.h"
#include "Driver.h"
#include "Automation.h"
#include "dialog.h"
#include "wafermap.h"

BOOL_VARIABLE( bDIE_MASK_FILE, FALSE, "" ){};
BOOL_VARIABLE( bDISABLE_DUPLICATE_DIE, FALSE, "" ) {}

int die_mask[MAX_SIZE][MAX_SIZE] = {0};

CArray<DutInfo,DutInfo> sMaskInfo;

int sMaskInfoNum;
int x_offset, y_offset;

void read_die_mask_file()
{
	CStdioFile die_mask_file;
	CFileFind finder;
	CString filename, folder, line;
	int ymin = MAX_SIZE-1,xmin=MAX_SIZE-1; 

	remote_fetch( bDIE_MASK_FILE, 0, FALSE);

	if(bDIE_MASK_FILE==FALSE)
	{
		return;
	}

	cRawDataFileName = cRawDataFileDir;
	cRawDataFileName += vFormat ( "\\%s", DEVICE_NAME );
	cRawDataFileName += vFormat ( "\\%s", LOT_NUM );
	folder = cRawDataFileName;
	cRawDataFileName += vFormat("\\%s_%s.data_*", LOT_NUM, WFR_SLOT_ID);

	sMaskInfoNum = 0;

	//find file in folder

	BOOL bWorking = finder.FindFile( cRawDataFileName );

	if(bWorking==FALSE)
	{
		CString msg = vFormat("read_die_mask_file: Error !!! no %s file", cRawDataFileName);
		AfxMessageBox ( msg );
		fatal ( "USER TOOL shut down" );
	}

	while(bWorking)
	{
		bWorking = finder.FindNextFile();

		filename = folder + vFormat("\\%s", finder.GetFileName());

		output("read_die_mask_file filename = %s", filename);

		if(die_mask_file.Open( filename, CFile::modeRead))
		{
			while(die_mask_file.ReadString(line))
			{
				DutInfo dieInfo;

				line.TrimLeft();

				if(sscanf( line, "%d%d%*d%*d%d%*d", &dieInfo.x, &dieInfo.y, &dieInfo.PassFail)==3)
				{
					sMaskInfo.Add(dieInfo);

					if(sMaskInfo[sMaskInfoNum].y < ymin) ymin = sMaskInfo[sMaskInfoNum].y;
					if(sMaskInfo[sMaskInfoNum].x < xmin) xmin = sMaskInfo[sMaskInfoNum].x;

					sMaskInfoNum++;
				}
			}
			die_mask_file.Close();
		}
	}

	y_offset = ymin < 0 ? -ymin: 0;
	x_offset = xmin < 0 ? -xmin: 0;

	memset( die_mask, 1, sizeof(int)*MAX_SIZE*MAX_SIZE);

	for ( int i = 0; i < sMaskInfoNum; i++ )
	{
		die_mask[sMaskInfo[i].x+x_offset][sMaskInfo[i].y+y_offset] = sMaskInfo[i].PassFail;
	}

}

bool already_tested( int x, int y)
{
	bool flag = false;

	if(bDISABLE_DUPLICATE_DIE==FALSE)
	{
		return false;
	}

	for ( int i = 0; i < sDutInfoNum; i++ )
	{
		if ( ( x == sDutInfo[i].x ) && ( y == sDutInfo[i].y ) )
		{
			flag = true;
			break;
		}
	}
	
	return flag;
}

bool die_mask_enabled( int x, int y)
{
	bool flag = false;

	if(bDIE_MASK_FILE==FALSE)
	{
		return true;
	}

	if(die_mask[x+x_offset][y+y_offset])
	{
		flag = true;
	}

	output("x=%d, y=%d, flag=%d", x, y, flag);
	
	return flag;
}

bool get_mask( int x, int y)
{
	bool enable = false;

	if(die_mask_enabled(x,y) && !already_tested( x, y))
	{
		enable = true;
	}

	return enable;
}


