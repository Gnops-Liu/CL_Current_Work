#include "tester.h"
#include "Driver.h"
#include "Automation.h"
#include "dialog.h"
#include "ProbeCardSites.h"
#include "wafermap.h"

CString WAFERMAP_FILE_PATH;

FILE * File1;

int SoftBinResults[MAX_SIZE][MAX_SIZE] = {0};
int HardBinResults[MAX_SIZE][MAX_SIZE] = {0};
int DutNumbers[MAX_SIZE ][MAX_SIZE] = {0};

int SoftBinCnts[MAX_BINS]={0};
int HardBinCnts[MAX_BINS]={0};

void generate_wafermap( int x_start, int x_stop, int x_inc, int x_offset, int y_start, int y_stop, int y_inc, int y_offset, int results[MAX_SIZE][MAX_SIZE]);
void generate_summary(int BinCnts[MAX_BINS]);

EXTERN_CSTRING_VARIABLE ( RAW_DATA_HEADER_STRING )

ONEOF_VARIABLE( WM_ORIGIN, "TOP_LEFT, BOTTOM_LEFT, TOP_RIGHT, BOTTOM_RIGHT", ""){}

void wafermap_summaries()
{  
	int i;  
	int ymin = MAX_SIZE-1,ymax =-100,xmin=MAX_SIZE-1, xmax =-100; //set min, max to max,min values possible
	int y_start, y_stop, x_start, x_stop, y_inc, x_inc, x_offset=0, y_offset=0;
	bool doSoftMap=false, doHardMap=false, doSiteMap=true;

	output("**********generating wafermap**********");
  
	WAFERMAP_FILE_PATH =  cRawDataFileName;
	WAFERMAP_FILE_PATH.Replace( "data", "waf");

	File1 = fopen ( WAFERMAP_FILE_PATH, "w" );
	if ( File1 == NULL )
	{
		CString cMsg = vFormat ( "Cannot open file11 %s", WAFERMAP_FILE_PATH );
		AfxMessageBox ( cMsg );
		return; 
	}

	//init arrays to all 0's
	memset( SoftBinResults, 0, sizeof(int)*MAX_SIZE*MAX_SIZE);
	memset( HardBinResults, 0, sizeof(int)*MAX_SIZE*MAX_SIZE);
	memset( DutNumbers, 0, sizeof(int)*MAX_SIZE*MAX_SIZE);
	memset( SoftBinCnts, 0, sizeof(int)*MAX_BINS);
	memset( HardBinCnts, 0, sizeof(int)*MAX_BINS);

	//calculate min and max
	for ( i = 0; i < sDutInfoNum; i++ )
	{
		if(sDutInfo[i].y < ymin) ymin = sDutInfo[i].y;
		if(sDutInfo[i].y > ymax) ymax = sDutInfo[i].y;
		if(sDutInfo[i].x < xmin) xmin = sDutInfo[i].x;
		if(sDutInfo[i].x > xmax) xmax = sDutInfo[i].x;
	}

	y_offset = ymin < 0 ? -ymin: 0;
	x_offset = xmin < 0 ? -xmin: 0;

	for ( i = 0; i < sDutInfoNum; i++ )
	{
		SoftBinResults[sDutInfo[i].x+x_offset][sDutInfo[i].y+y_offset] = sDutInfo[i].SoftBin;
		HardBinResults[sDutInfo[i].x+x_offset][sDutInfo[i].y+y_offset] = sDutInfo[i].HardBin;
		DutNumbers[sDutInfo[i].x+x_offset][sDutInfo[i].y+y_offset] = sDutInfo[i].DutNumber+1;

		SoftBinCnts[sDutInfo[i].SoftBin]++;
		HardBinCnts[sDutInfo[i].HardBin]++;

		if(sDutInfo[i].SoftBin) doSoftMap = true;
		if(sDutInfo[i].HardBin) doHardMap = true;
	}

	output("WM_ORIGIN=%s", WM_ORIGIN);

	if(WM_ORIGIN=="BOTTOM_LEFT")
	{
		y_start	= ymax;
		y_stop	= ymin;
		y_inc	= -1;
		x_start = xmin;
		x_stop	= xmax;
		x_inc	= 1;  
	}
	if(WM_ORIGIN=="TOP_LEFT")
	{
		y_start	= ymin;
		y_stop	= ymax;
		y_inc	= 1;
		x_start = xmin;
		x_stop	= xmax;
		x_inc	= 1;    
	}
	if(WM_ORIGIN=="BOTTOM_RIGHT")
	{
		y_start	= ymax;
		y_stop	= ymin;
		y_inc	= -1;
		x_start = xmax;
		x_stop	= xmin;
		x_inc	= -1;
	}
	if(WM_ORIGIN=="TOP_RIGHT")
	{
		y_start	= ymin;
		y_stop	= ymax;
		y_inc	= 1;
		x_start = xmax;
		x_stop	= xmin;
		x_inc	= -1;
	}

	//write header
	fprintf ( File1, "Rev 1 Jan 2010 \n" );
	fprintf ( File1, "%s\n", RAW_DATA_HEADER_STRING );

	//Hard Bin Wafermap

	if(doHardMap)
	{
	  	fprintf( File1, "\n\nHard Bin Wafer Map\n\n");

			generate_wafermap( x_start, x_stop, x_inc, x_offset, y_start, y_stop, y_inc, y_offset, HardBinResults);
	}

	//SoftBin Wafermap

	if(doSoftMap)
	{
	  	fprintf( File1, "\n\nSoft Bin Wafer Map\n\n");

			generate_wafermap( x_start, x_stop, x_inc, x_offset, y_start, y_stop, y_inc, y_offset, SoftBinResults);
	}

	if(doSiteMap)
	{
	  	fprintf( File1, "\n\nSite Map\n\n");

			generate_wafermap( x_start, x_stop, x_inc, x_offset, y_start, y_stop, y_inc, y_offset, DutNumbers);
	}

	//Hard Bins Summary
	if(doHardMap)
	{
	  	fprintf( File1, "\n\nCategories Summary\n\n");
	
		generate_summary( HardBinCnts );
	}

	//Soft Bins Summary
	if(doSoftMap)
	{
	  	fprintf( File1, "\n\nSoft Bin Summary\n\n");
	
		generate_summary( SoftBinCnts );
	}

	fclose ( File1 );
}

void generate_wafermap( int x_start, int x_stop, int x_inc, int x_offset, int y_start, int y_stop, int y_inc, int y_offset, int results[MAX_SIZE][MAX_SIZE])
{
	int x_coord, y_coord;

	for(y_coord =y_start; y_inc > 0 ? y_coord <= y_stop : y_coord >= y_stop ; y_coord += y_inc )
	{
		fprintf( File1, "%2d |", y_coord );
	
		for(x_coord =x_start; x_inc > 0 ? x_coord <= x_stop : x_coord >= x_stop ; x_coord += x_inc )
		{  
			if(results[x_coord+x_offset][y_coord+y_offset]== 0)
			{
				fprintf( File1, "   ");
			}
			else
			{
	   			fprintf( File1, "%3d", results[x_coord+x_offset][y_coord+y_offset] );  		
			}
		}
	
		fprintf( File1, "\n");	
	}
	
	for(x_coord =x_start; x_inc > 0 ? x_coord <= x_stop : x_coord >= x_stop ; x_coord += x_inc )
	{                  
		if(x_coord==x_start) fprintf( File1, "    ");
		fprintf( File1, "---");
		if(x_coord==x_stop) fprintf( File1, "\n    ");
	}

	for(x_coord =x_start; x_inc > 0 ? x_coord <= x_stop : x_coord >= x_stop ; x_coord += x_inc )
	{                  
		fprintf( File1, "%3d", x_coord );
	}
	
	fprintf( File1, "\n\n\n");
}

void generate_summary(int BinCnts[MAX_BINS])
{
		fprintf( File1, "    ======================================\n");
		fprintf( File1, "    Bin      Devices      Actual Yield    \n");
		fprintf( File1, "    ======================================\n");
							 
		for(int i=0; i <MAX_BINS; i++)
		{
			if(BinCnts[i] !=0) 
			{	 
				fprintf( File1, "   %3d%15d%12.2f%\n",  i, BinCnts[i], ((BinCnts[i] *1.0)/(sDutInfoNum*1.0)*100));
		    }
		}
	
		fprintf( File1, "    ======================================\n");
		fprintf( File1, "\n     Total Dice Tested    : %d\n", sDutInfoNum);
	
	    fprintf( File1, "\n\n\n");
}

void update_wafermap_field( )
{
	if(bWMAP_TOOL)
	{
		//wmap_die_set( wmap_die_field, Hnd_PositionMinX, Hnd_PositionMinY, Hnd_PositionMaxX-Hnd_PositionMinX+1, Hnd_PositionMaxY-Hnd_PositionMinY+1, PS_SOLID, RGB(0,0,255) );
		remote_set("update_wafermap_field", 0, 0, TRUE);
	}
}

void clear_wafermap_field( )
{
	static bool first = true;

	if(bWMAP_TOOL)
	{
		remote_set("clear_wafermap_field", 0, 0, TRUE);
	}
}

