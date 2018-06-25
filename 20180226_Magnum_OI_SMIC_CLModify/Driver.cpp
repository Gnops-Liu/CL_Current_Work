// Driver.cpp: CDriver 
//
//////////////////////////////////////////////////////////////////////
#include "tester.h"
#include "dialog.h"
#include "Driver.h"

CDriver::CDriver()
{
	//cDllFileName = "c:\\nextest\\drivers\\tsk.dll";

	// enl 110917 - need to create unique dllname to easily differentiate with other tsk dlls coming from SMIC's customers that will use their own OI
	cDllFileName = "c:\\nextest\\drivers\\tsk_mag2.dll"; 

}

CDriver::~CDriver()
{
	FreeLibrary(hDllInstance);
}

void CDriver::init()
{

	hDllInstance = ::LoadLibrary ( cDllFileName );	

	if (hDllInstance == NULL) fatal("!!! cannot open DLL file %s!!! ", cDllFileName);
																						
	Hnd_Init = (HND_INIT)(GetProcAddress(hDllInstance, "Hnd_Init"));					
	if ( Hnd_Init == NULL ) fatal ( "!!! cannot open DLL function of Hnd_Init" );		
																						
	Hnd_Poll = (HND_POLL)(GetProcAddress(hDllInstance, "Hnd_Poll"));					
	if ( Hnd_Poll == NULL ) fatal ( "!!! cannot open DLL function of Hnd_Poll" );		
																						
	Hnd_Set = (HND_SET)(GetProcAddress(hDllInstance, "Hnd_Set"));						
	if ( Hnd_Set == NULL ) fatal ( "!!! cannot open DLL function of Hnd_Set" );			
																						
	Hnd_Bin = (HND_BIN)(GetProcAddress(hDllInstance, "Hnd_Bin"));						
	if ( Hnd_Bin == NULL ) fatal ( "!!! cannot open DLL function of Hnd_Bin" );			
																						 
	Hnd_Query = (HND_QUERY)(GetProcAddress(hDllInstance, "Hnd_Query"));					
	if ( Hnd_Query == NULL ) fatal ( "!!! cannot open DLL function of Hnd_Query" );	
	
	Hnd_GetInfo = (HND_GETINFO)(GetProcAddress(hDllInstance, "Hnd_GetInfo"));			
	if ( Hnd_GetInfo == NULL ) fatal ( "!!! cannot open DLL function of Hnd_GetInfo" );	

	Hnd_Start = (HND_START)(GetProcAddress(hDllInstance, "Hnd_Start"));

	//prober only functions
	Hnd_LoadWafer = (HND_LOADWAFER)(GetProcAddress(hDllInstance, "Hnd_LoadWafer"));		
	if ( Hnd_LoadWafer == NULL )
	{
		output ( "Cannot open DLL function Hnd_LoadWafer. Loader will assume this is a handler driver and not a prober driver" );
		set_value ( oDriverType, "handler" );
	}
		
	if(oDriverType=="prober")
	{
		Hnd_UnloadWafer = (HND_UNLOADWAFER)(GetProcAddress(hDllInstance, "Hnd_UnloadWafer"));		
		if ( Hnd_UnloadWafer == NULL ) fatal ( "!!! cannot open DLL function of Hnd_UnloadWafer" );	
																									
		Hnd_Alarm = (HND_ALARM)(GetProcAddress(hDllInstance, "Hnd_Alarm"));				
		if ( Hnd_Alarm == NULL ) fatal ( "!!! cannot open DLL function of Hnd_Alarm" );

		Hnd_ZUp = (HND_ZUP)(GetProcAddress(hDllInstance, "Hnd_ZUp"));				
		if ( Hnd_ZUp == NULL ) fatal ( "!!! cannot open DLL function of Hnd_Zup" );

		Hnd_ZDown = (HND_ZUP)(GetProcAddress(hDllInstance, "Hnd_ZDown"));				
		if ( Hnd_ZDown == NULL ) fatal ( "!!! cannot open DLL function of Hnd_ZDown" );

		Hnd_Move = (HND_MOVE)(GetProcAddress(hDllInstance, "Hnd_Move"));				
		if ( Hnd_Move == NULL ) fatal ( "!!! cannot open DLL function of Hnd_Move" );

		//optional function
		Hnd_Move_to_first = (HND_MOVE_TO_FIRST)(GetProcAddress(hDllInstance, "Hnd_Move_to_first"));				
	}
}

void CDriver::ChangeDLL( CString cName )
{
	cDllFileName = cName;

	FreeLibrary(hDllInstance);
}

void CDriver::SetDLL( CString cName )
{
	cDllFileName = cName;
}

CString CDriver::GetDLL()
{
	return cDllFileName;
}

void CDriver::SetType( CString cName )
{
	cType = cName;
}

CString CDriver::GetType()
{
	return cType;
}
