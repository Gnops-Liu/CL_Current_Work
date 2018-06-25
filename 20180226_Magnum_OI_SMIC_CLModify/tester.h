// When this program is run, it can take on different "personalities" depending
// on the command-line arguments it is run with.  These "personalities" include
// site-mode, host-mode, and tool-mode.
//
// Normally, all of this is invisible if you start programs from UI.
// For site-mode and host-mode, the only time you see these command-line arguments
// is when running in site-debug mode and host-debug mode, respectively.
//
// To run this in tool-mode, simply type in a "-t" in the "Program arguments"
// edit box of the "Debug" tab of the "Build/Settings" dialog.
//
#include "TestProgApp/public.h"
#include "TestTimer.h"
