#include "tester.h"
#include "CL_DLL.h"
CDriver Adventurer_Peter;

//Definition of CDriver
CDriver::CDriver()
{
	output("");
}

CDriver::~CDriver()
{
	FreeLibrary(DLL_Instance);
	global_type = Vain;
}

void CDriver::install()
{
	DLL_Instance = ::LoadLibrary(DLL_Path);
	if (DLL_Instance == NULL) fatal("!!! Can't Open DLL File!!!");
	CDynload();
}

void CDriver::Change_DLL(CString Path, dType type)
{
	DLL_Path = Path;
	FreeLibrary(DLL_Instance);
	Set_Type(type);
	install();
}
void CDriver::Set_DLL(CString Path)
{
	output(Path);
	DLL_Path = Path;
}

CString CDriver::Get_DLL()
{
	return DLL_Path;
}

void CDriver::Set_Type(dType type)
{
	global_type = type;
}

int CDriver::Get_Type()
{
	return global_type;
}

void CDriver::CDynload()
{
	switch (global_type)
	{
	case CL_DLL:
		Fun_CL_DLL(); break;
	default:
		fatal("!!!No related functions is loaded in, maybe you forget the related Fun_CL_DLl()!!!"); break;
	}
}

void CDriver::Fun_CL_DLL()
{
	//Create Entry point
	CL_Add = (PCL_Add)(GetProcAddress(DLL_Instance, "Add"));
	if (CL_Add == NULL)
		fatal("!!!Can't link to 'Add' of CL_DLL!!!");

	CL_Version = (PCL_Version)(GetProcAddress(DLL_Instance, "Version"));
	if (CL_Version == NULL)
		fatal("!!!Can't link to 'Version' of CL_DLL!!!");

	CL_Build_Treasure_Box = (PCL_Build_Treasure_Box)(GetProcAddress(DLL_Instance, "Build_Treasure_Box"));
	if (CL_Build_Treasure_Box == NULL)
		fatal("!!!Can't link to 'Build_Treasure_Box' of CL_DLL!!!");

	CL_Destroy_Treasure_Box = (PCL_Destroy_Treasure_Box)(GetProcAddress(DLL_Instance, "Destroy_Treasure_Box"));
	if (CL_Destroy_Treasure_Box == NULL)
		fatal("!!!Can't link to 'Destroy_Treasure_Box' of CL_DLL!!!");

	CL_Rebuild_Treasure_Box = (PCL_Rebuild_Treasure_Box)(GetProcAddress(DLL_Instance, "Rebuild_Treasure_Box"));
	if (CL_Rebuild_Treasure_Box == NULL)
		fatal("!!!Can't link to 'Rebuild_Treasure_Box' of CL_DLL!!!");

	CL_Treasure_save_int = (PCL_Treasure_save_int)(GetProcAddress(DLL_Instance, "Treasure_save_int"));
	if (CL_Treasure_save_int == NULL)
		fatal("!!!Can't link to 'Treasure_save_int' of CL_DLL!!!");

	CL_Treasure_save_double = (PCL_Treasure_save_double)(GetProcAddress(DLL_Instance, "Treasure_save_double"));
	if (CL_Treasure_save_double == NULL)
		fatal("!!!Can't link to 'Treasure_save_double' of CL_DLL!!!");

	CL_Treasure_save_string = (PCL_Treasure_save_string)(GetProcAddress(DLL_Instance, "Treasure_save_string"));
	if (CL_Treasure_save_string == NULL)
		fatal("!!!Can't link to 'Treasure_save_string' of CL_DLL!!!");

	CL_Treasure_save_bool = (PCL_Treasure_save_bool)(GetProcAddress(DLL_Instance, "Treasure_save_bool"));
	if (CL_Treasure_save_bool == NULL)
		fatal("!!!Can't link to 'Treasure_save_double' of CL_DLL!!!");

	CL_Treasure_save_hex = (PCL_Treasure_save_hex)(GetProcAddress(DLL_Instance, "Treasure_save_hex"));
	if (CL_Treasure_save_hex == NULL)
		fatal("!!!Can't link to 'Treasure_save_hex' of CL_DLL!!!");

	CL_Peek_Treasure = (PCL_Peek_Treasure)(GetProcAddress(DLL_Instance, "Peek_Treasure"));
	if (CL_Peek_Treasure == NULL)
		fatal("!!!Can't link to 'Peek_Treasure' of CL_DLL!!!");

	CL_Treasure_Dig = (PCL_Treasure_Dig)(GetProcAddress(DLL_Instance, "Treasure_Dig"));
	if (CL_Treasure_Dig == NULL)
		fatal("!!!Can't link to 'Treasure_Dig' of CL_DLL!!!");
}

//====================================================================================


int Add(int a, int b)
{
	return Adventurer_Peter.CL_Add(a, b);
}

void Build_Treasure_Box(int depth)
{
	Adventurer_Peter.CL_Build_Treasure_Box(depth);
}

void Destroy_Treasure_Box()
{
	Adventurer_Peter.CL_Destroy_Treasure_Box();
}

void Rebuild_Treasure_Box(int depth)
{
	Adventurer_Peter.CL_Rebuild_Treasure_Box(depth);
}

void Treasure_save(char* label, int coin)
{
	Adventurer_Peter.CL_Treasure_save_int(label, coin);
}

void Treasure_save(char* label, double coin)
{
	Adventurer_Peter.CL_Treasure_save_double(label, coin);
}

void Treasure_save(char* label, char* coin)
{
	Adventurer_Peter.CL_Treasure_save_string(label, coin);
}

void Treasure_save(char* label, bool coin)
{
	Adventurer_Peter.CL_Treasure_save_bool(label, coin);
}

void Treasure_save(char* label, long coin)
{
	Adventurer_Peter.CL_Treasure_save_hex(label, coin);
}

bool Treasure_Dig(char * Path)
{
	return Adventurer_Peter.CL_Treasure_Dig(Path);
}

void Peek_Treasure()
{
	Adventurer_Peter.CL_Peek_Treasure();
}
