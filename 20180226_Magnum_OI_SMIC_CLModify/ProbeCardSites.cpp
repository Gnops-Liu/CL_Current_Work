#include "tester.h"
#include "Driver.h"
#include "Automation.h"

EXTERN_INT_VARIABLE ( MAX_DUTS )	// it will be auto calculated


int Hnd_ProbeCardSiteLocationRelativeX[D_SITES_IN_PROBER];
int Hnd_ProbeCardSiteLocationRelativeY[D_SITES_IN_PROBER];
int Hnd_PositionX[D_SITES_IN_PROBER];
int Hnd_PositionY[D_SITES_IN_PROBER];

extern devinfo	DevInfo;

int IntCompare(const void* pElem1, const void* pElem2) { return *(const int*)pElem1 - *(const int*)pElem2; }

// debug function.
void Printout_ProbeCardMap ( int iSwt_MaxDutNum )
{
	int site[D_SITES_IN_PROBER];	// for debug;
	int x, y;
	int relx[D_SITES_IN_PROBER], rely[D_SITES_IN_PROBER];	// for debug

// init
	for ( x = 0; x < D_SITES_IN_PROBER; x++ )
	{
		site [x] = 0;
		relx [x] = Hnd_ProbeCardSiteLocationRelativeX[x];
		rely [x] = Hnd_ProbeCardSiteLocationRelativeY[x];
	}

	qsort ( relx, iSwt_MaxDutNum, sizeof *relx, IntCompare );
	qsort ( rely, iSwt_MaxDutNum, sizeof *rely, IntCompare );

//	output ( "relx max = %d, min = %d", relx[iSwt_MaxDutNum-1], relx[0] );
//	output ( "rely max = %d, min = %d", rely[iSwt_MaxDutNum-1], rely[0] );

	int iSizeofX = relx[iSwt_MaxDutNum - 1] - relx[0];
	int iSizeofY = rely[iSwt_MaxDutNum - 1] - rely[0];

	int iMinX = abs(relx[0]);
	int iMinY = abs(rely[0]);

//	output ( "size of x, minx = %d, %d", iSizeofX, iMinX );
//	output ( "size of y, minx = %d, %d", iSizeofY, iMinY );

	output ( "ProbeCardInfo Tester DUT Map # = [X][Y]" );
	for ( int i = 0; i < iSwt_MaxDutNum; i++ ) // debug
	{
		x = Hnd_ProbeCardSiteLocationRelativeX[ i ] + iMinX;
		y = Hnd_ProbeCardSiteLocationRelativeY[ i ] + iMinY;

		output ( "i, x, y = %d, %d, %d", i, x, y );

		//output("x + y * ( iSizeofX + 1 ) = %d", x + y * ( iSizeofX + 1 )); // enl debug

		site[x + y * ( iSizeofX + 1 )] = i+1;
	}

	output ( " " );
	CString cMsg;
	for ( y = 0; y < iSizeofY + 1; y++ )
	{
		cMsg = "";
		for ( x = 0; x < iSizeofX + 1; x++ )
		{
			if ( site[x + y * ( iSizeofX + 1 )] == 0 ) cMsg += "   ,";
			else {
				cMsg += vFormat ( "%3d,", site[x + y * ( iSizeofX + 1 )] );
			}
		}
		output ( "%s", cMsg );
	}
	output ( " " );
}

void Read_ProbeCardSiteInfo ( void )
{
	/*static CString cPCMultiNo = -1;*/
	static CString cPCMultiNo = "-1";
	CString cTemp;

//	strcpy ( ProbeInfo.cProbeCard_num, "U0");	// for debugact
//                                         1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18   19   20   21   22   23   24   25   26   27   28   29   30   31   32   33   34   35   36   37   38   39   40   41   42   43   44   45   46   47   48   49   50   51   52   53   54   55   56   57   58   59   50
//	strcpy ( ProbeInfo.cProbeCard_num, "CL@@@@ `B`C `D`C @A`C @B@@ @B`C `C@@ @A@@ `A@@ `A`C `C`C @@`C `D@@ `B@@ `E`C `E@@ `F@@ `F`C `H@@ `K@@ `G@@ `G`C `H`3 `L`3 `I@@ `J`C `J@@ `I`C `L@@ `K`C `I`I `H`F `I`F `K`F `K`I `L`F `G`I `L`I `F`F `G`F `J`I `J`F `E`I `H`I `F`I `E`F `D`I `C`F `B`I `A`F `C`I @B`I `D`F @A`F `A`I `B`F @@`I @@`F @A`I @B`F");	// for debugact
//	strcpy ( ProbeInfo.cProbeCard_num, "CL@@@@`B`C`D`C@A`C@B@@@B`C`C@@@A@@`A@@`A`C`C`C@@`C`D@@`B@@`E`C`E@@`F@@`F`C`H@@`K@@`G@@`G`C`H`3`L`3`I@@`J`C`J@@`I`C`L@@`K`C`I`I`H`F`I`F`K`F`K`I`L`F`G`I`L`I`F`F`G`F`J`I`J`F`E`I`H`I`F`I`E`F`D`I`C`F`B`I`A`F`C`I@B`I`D`F@A`F`A`I`B`F@@`I@@`F@A`I@B`F");	// for debugact

	if ( strlen ( DevInfo.cProbeCard_num ) < 3 )
	{
		output ( "Probe Card Multi Site No. = %s", DevInfo.cProbeCard_num );
		if ( cPCMultiNo == (CString)DevInfo.cProbeCard_num ) return;

		cPCMultiNo = (CString)DevInfo.cProbeCard_num;
		cTemp = vFormat ( "[%s]", cPCMultiNo );
	
		CString cFileName = "c:\\nextest\\drivers\\tsk_database.txt";

		FILE * File1;
		File1 = fopen ( cFileName, "r" );

		if ( File1 == NULL ) 
		{
			output ( "cannot open File10 in %s", cFileName );
			AfxMessageBox ( "cannot open p/c multi site info file" );
			fatal ( "User Tool closed" );
		}
	
		char moji[256];

		CString cMsg;

		int index;
		int max_index = -1;

		while ( (int)fgets( moji, 255, File1 ) != NULL )
		{
			cMsg = (CString)moji;

			if ( cMsg.Find ( cTemp, 0 ) != -1 ) 
			{
				output ( "find %s", cTemp );

				index = 0;
				while ( (int)fgets( moji, 255, File1 ) != NULL )
				{
					cMsg = (CString)moji;

					if ( cMsg.Find ( "[", 0 ) != -1 )	break; 

					if ( ! (index % 2) )
					{
						Hnd_ProbeCardSiteLocationRelativeX[index/2] = atoi ( cMsg );
//						output ( "index %d , X = %d", index , Hnd_ProbeCardSiteLocationRelativeX[index] );
					} else {
						Hnd_ProbeCardSiteLocationRelativeY[index/2] = atoi ( cMsg );
//						output ( "index %d , Y = %d", index , Hnd_ProbeCardSiteLocationRelativeY[index] );
					}

					index++;
				}

				max_index = index / 2;

				break;
			}
		}
		fclose ( File1 );

		if ( max_index == -1 )
		{
			AfxMessageBox ( "Error !!! There is no Dut# coordination in DataBase." );
			fatal ( "USER TOOL shut down by setting error" );
		} else {
//			output ( "max_index = %d", max_index );
		}

		int i,j;
		// check values
		for ( i = 0; i < max_index - 1; i++ )
		{
			for ( j = 0; j < max_index - 1; j++ )
			{
				if ( i == j ) continue;
				if ( Hnd_ProbeCardSiteLocationRelativeX[i] == Hnd_ProbeCardSiteLocationRelativeX[j] &&
					 Hnd_ProbeCardSiteLocationRelativeY[i] == Hnd_ProbeCardSiteLocationRelativeY[j] )
				{
					output ( "Error !!! There is same Dut# coordination in Setting." );
					output ( "Dut#[%d] and Dut#[%d] have same coordinate [%d][%d]",
											i,
											j,
											Hnd_ProbeCardSiteLocationRelativeX[i],
											Hnd_ProbeCardSiteLocationRelativeY[i] );

					AfxMessageBox ( "Error !!! There is same Dut# coordination in Setting." );
					fatal ( "USER TOOL shut down by setting error" );
				}
			}
		}
	} else {

		output ( "Probe Card Multi Site No. = %s", DevInfo.cProbeCard_num );
		if ( cPCMultiNo == (CString)DevInfo.cProbeCard_num ) return;

		cPCMultiNo = (CString)DevInfo.cProbeCard_num;

		int iDutN = ( DevInfo.cProbeCard_num[1] & 0xF ) +
			        ( DevInfo.cProbeCard_num[0] & 0xF ) * 0x10;

		char temp1[2];
		int  iWork1;

		for ( int i = 0; i < iDutN; i++ ) 
		{
			// detect x
			strncpy(temp1,&DevInfo.cProbeCard_num[2+i*4],1);
			temp1[1]='\0';
//			output ( "char = %s", temp1 );
			iWork1 = ( (BYTE)temp1[0] & 0x1F ) * 0x10;
			if ( (BYTE)temp1[0] & 0x20 )	Hnd_ProbeCardSiteLocationRelativeX[i] = -1;
			else							Hnd_ProbeCardSiteLocationRelativeX[i] = 1;
//			output ( "data = %x %d", (BYTE)temp1[0], iWork1 );

			strncpy(temp1,&DevInfo.cProbeCard_num[3+i*4],1);
			temp1[1]='\0';
			iWork1 = iWork1 + ( (BYTE)temp1[0] & 0xF);

			Hnd_ProbeCardSiteLocationRelativeX[i] *= iWork1;
//			output ( "X %d = %d", i, iWork1 );

			// detect 7
			strncpy(temp1,&DevInfo.cProbeCard_num[4+i*4],1);
			temp1[1]='\0';
			iWork1 = ( (BYTE)temp1[0] & 0x1F ) * 0x10;
			if ( (BYTE)temp1[0] & 0x20 )	Hnd_ProbeCardSiteLocationRelativeY[i] = -1;
			else							Hnd_ProbeCardSiteLocationRelativeY[i] = 1;

			strncpy(temp1,&DevInfo.cProbeCard_num[5+i*4],1);
			temp1[1]='\0';
			iWork1 = iWork1 + ( (BYTE)temp1[0] & 0xF);

			Hnd_ProbeCardSiteLocationRelativeY[i] *= iWork1;

//			output ( "Y %d = %d", i, iWork1 );

		}
	}

	Printout_ProbeCardMap(MAX_DUTS);
}
