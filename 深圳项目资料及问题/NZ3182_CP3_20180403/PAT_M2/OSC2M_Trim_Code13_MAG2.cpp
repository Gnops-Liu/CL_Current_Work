// This file has been automatically generated by the pattern compiler.
// DO NOT EDIT!

#ifndef MAGNUM2
#define MAGNUM2
#endif 

#define PATCOM_OUTPUT
#include "tester.h"
#include "OSC2M_Trim_Code13_MAG2.h"

#ifndef PATTERN_INSTRUCTION
#error PATTERN_INSTRUCTION not #defined ("tester.h" should not have "#pragma once").
#endif



/************ pattern "OSC2M_Trim_Code13" ************/

PATTERN_INITIAL_CONDITIONS( OSC2M_Trim_Code13 )   /* C Code to set initial conditions */
{
}

PATTERN_INSTRUCTIONS( OSC2M_Trim_Code13 )   /* Microcode */
{
}

PATTERN_VAR_UINSTS( OSC2M_Trim_Code13 )   /* Microinstructions that use/manipulate VAR */
{
	PATTERN_VAR_UINST( OSC2M_Trim_Code13, -1, 0, vt_NC )
}

PATTERN_VERSIONS( OSC2M_Trim_Code13 )   /* Version of the compiler output */
{
	PATTERN_VERSION( PATTERN_VAR_GOSUB, 1 )
}

PATTERN_USED_TSETS( OSC2M_Trim_Code13 )   /* TSETS used by this pattern */
{
	PATTERN_USED_TSET( TSET1 )
}

PATTERN_USED_VIHHS( OSC2M_Trim_Code13 )   /* VIHH used by this pattern */
{
	PATTERN_USED_VIHH( VIHH1 )
}

PATTERN_ATTRIBUTES( OSC2M_Trim_Code13 )   /* Pattern attributes */
{
	PATTERN_ATTRIBUTE( LOGIC )
	PATTERN_ATTRIBUTE( SINGLE )
}

PATTERN_HW_REQUIREMENTS( OSC2M_Trim_Code13 )   /* Hardware requirements */
{
	PATTERN_HW_REQUIREMENT( mag, 2 )
}

PATTERN( OSC2M_Trim_Code13 )   /* Process the pattern specific information */
{
	INITIAL_CONDITIONS( OSC2M_Trim_Code13 )
	INSTRUCTIONS( OSC2M_Trim_Code13 )
	VAR_UINSTS( OSC2M_Trim_Code13 )
	VERSIONS( OSC2M_Trim_Code13 )
	USED_TSETS( OSC2M_Trim_Code13 )
	USED_VIHHS( OSC2M_Trim_Code13 )
	ATTRIBUTES( OSC2M_Trim_Code13 )
	HW_REQUIREMENTS( OSC2M_Trim_Code13 )
}



/************ data global to this file ************/

LOGIC_VECTORS( OSC2M_Trim_Code13 )   /* Logic vectors prescrambled according to PINASSIGNMENTS */
{
	LOGIC_VECTOR_MAG2( NZ3182, "OSC2M_Trim_Code13_MAG2/NZ3182.hlh" )
	LOGIC_VECTOR_INDEX( "OSC2M_Trim_Code13_MAG2/OSC2M_Trim_Code13_MAG2.bkm" )
}
