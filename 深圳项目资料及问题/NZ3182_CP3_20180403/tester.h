// *************************
// ***** tester.h file *****
// *************************
#include "TestProgApp/public.h"  // moved above #include <afxwin.h> for conversion MSDev 6.0 -> MSDev 2013

#include <afxwin.h>
// from MSDev 6.0, removed for MSDev 2013:  #pragma warning( disable: 4244 )	// conversion from const double to float

#include "protos.h"
#include "pin_lists.h"
#include "fdatalog.h"
#include "timer.h"
#include "driver.h"
#include "User_Var.h"
#include "TestTimer.h"

#include "patcom_generated_includes.h"

#define VERBOSE 1



