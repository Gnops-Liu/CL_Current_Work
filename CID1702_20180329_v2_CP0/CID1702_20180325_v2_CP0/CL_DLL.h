#define STUFF_EXPORT extern "C" __declspec(dllexport)
#define STUFF_IMPORT			__declspec(dllimport)
//CL_DLL class
typedef int(*PCL_Add)(int, int);
typedef void(*PCL_Build_Treasure_Box)(int);
typedef void(*PCL_Destroy_Treasure_Box)(void);
typedef void(*PCL_Rebuild_Treasure_Box)(int);
typedef void(*PCL_Treasure_save_int)(char*, int);
typedef void(*PCL_Treasure_save_double)(char*, double);
typedef void(*PCL_Treasure_save_string)(char*, char*);
typedef void(*PCL_Treasure_save_bool)(char*, bool);
typedef void(*PCL_Treasure_save_hex)(char*, long);
typedef void(*PCL_Peek_Treasure)(void);
typedef bool(*PCL_Treasure_Dig)(char *);
typedef void(*PCL_Version)(void);

class CDriver
{
	HINSTANCE	DLL_Instance;
	CString		DLL_Path;
public:
	enum dType
	{
		Vain, CL_DLL
	};
	int global_type = Vain;

	CDriver();
	virtual ~CDriver();

	virtual void install();
	virtual void CDriver::Change_DLL(CString Path, dType type);
	virtual void Set_DLL(CString Path);
	virtual CString Get_DLL();
	virtual void Set_Type(dType type);
	virtual int Get_Type();
	virtual void CDynload();

	//open area
	virtual void Fun_CL_DLL();


	//CL_DLL
	PCL_Add							CL_Add;
	PCL_Version						CL_Version;
	PCL_Build_Treasure_Box			CL_Build_Treasure_Box;
	PCL_Destroy_Treasure_Box		CL_Destroy_Treasure_Box;
	PCL_Rebuild_Treasure_Box		CL_Rebuild_Treasure_Box;
	PCL_Treasure_save_int			CL_Treasure_save_int;
	PCL_Treasure_save_double		CL_Treasure_save_double;
	PCL_Treasure_save_string		CL_Treasure_save_string;
	PCL_Treasure_save_bool			CL_Treasure_save_bool;
	PCL_Peek_Treasure				CL_Peek_Treasure;
	PCL_Treasure_Dig				CL_Treasure_Dig;
	PCL_Treasure_save_hex			CL_Treasure_save_hex;
};

extern void Build_Treasure_Box(int depth);
extern void Destroy_Treasure_Box();
extern void Rebuild_Treasure_Box(int depth);
extern void Treasure_save(char* label, int coin);
extern void Treasure_save(char* label, double coin);
extern void Treasure_save(char* label, char* coin);
extern void Treasure_save(char* label, bool coin);
extern void Treasure_save(char* label, long coin);
extern bool Treasure_Dig(char* Path);
extern void Peek_Treasure(void);
extern void Last_Treasure();