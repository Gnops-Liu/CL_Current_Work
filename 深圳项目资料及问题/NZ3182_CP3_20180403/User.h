#include <iostream>
#include <fstream>
#include <iomanip>
#include <afx.h>
#include <io.h>
//#include "CL_DLL.h"
using namespace std;
static ofstream fileout;


#define need_to_be_delete
//For User_Subroutine
extern int folder_existed(CString fn);
