// This file has been automatically generated by the pattern compiler.
// DO NOT EDIT!

#ifndef MAGNUM2
#define MAGNUM2
#endif 

#define PATCOM_OUTPUT
#include "tester.h"
#include "OSC2M_Trim_MAG2.h"

#ifndef PATTERN_INSTRUCTION
#error PATTERN_INSTRUCTION not #defined ("tester.h" should not have "#pragma once").
#endif



/************ pattern "OSC2M_Trim" ************/

PATTERN_INITIAL_CONDITIONS( OSC2M_Trim )   /* C Code to set initial conditions */
{
//mg
	ebm_address_pointer_reset();
  
}

PATTERN_INSTRUCTIONS( OSC2M_Trim )   /* Microcode */
{
}

PATTERN_VAR_UINSTS( OSC2M_Trim )   /* Microinstructions that use/manipulate VAR */
{
	PATTERN_VAR_UINST( OSC2M_Trim, -1, 0, vt_NC )
}

PATTERN_VERSIONS( OSC2M_Trim )   /* Version of the compiler output */
{
	PATTERN_VERSION( PATTERN_VAR_GOSUB, 1 )
}

PATTERN_USED_TSETS( OSC2M_Trim )   /* TSETS used by this pattern */
{
	PATTERN_USED_TSET( TSET1 )
}

PATTERN_USED_VIHHS( OSC2M_Trim )   /* VIHH used by this pattern */
{
	PATTERN_USED_VIHH( VIHH1 )
}

PATTERN_ATTRIBUTES( OSC2M_Trim )   /* Pattern attributes */
{
	PATTERN_ATTRIBUTE( LOGIC )
	PATTERN_ATTRIBUTE( SINGLE )
}

PATTERN_HW_REQUIREMENTS( OSC2M_Trim )   /* Hardware requirements */
{
	PATTERN_HW_REQUIREMENT( mag, 2 )
	PATTERN_HW_REQUIREMENT( ebm, 1 )
}

PATTERN( OSC2M_Trim )   /* Process the pattern specific information */
{
	INITIAL_CONDITIONS( OSC2M_Trim )
	INSTRUCTIONS( OSC2M_Trim )
	VAR_UINSTS( OSC2M_Trim )
	VERSIONS( OSC2M_Trim )
	USED_TSETS( OSC2M_Trim )
	USED_VIHHS( OSC2M_Trim )
	ATTRIBUTES( OSC2M_Trim )
	HW_REQUIREMENTS( OSC2M_Trim )
}



/************ data global to this file ************/

LOGIC_VECTORS( OSC2M_Trim )   /* Logic vectors prescrambled according to PINASSIGNMENTS */
{
	LOGIC_VECTOR_MAG2( NZ3182, "OSC2M_Trim_MAG2/NZ3182.hlh" )
	LOGIC_VECTOR_INDEX( "OSC2M_Trim_MAG2/OSC2M_Trim_MAG2.bkm" )
}
