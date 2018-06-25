// This file has been automatically generated by the pattern compiler.
// DO NOT EDIT!

#ifndef MAGNUM2
#define MAGNUM2
#endif 

#define PATCOM_OUTPUT
#include "tester.h"
#include "IP_Trim_Write2_MAG2.h"

#ifndef PATTERN_INSTRUCTION
#error PATTERN_INSTRUCTION not #defined ("tester.h" should not have "#pragma once").
#endif



/************ pattern "IP_Trim_Write2" ************/

PATTERN_INITIAL_CONDITIONS( IP_Trim_Write2 )   /* C Code to set initial conditions */
{
//mg
	ebm_address_pointer_reset();
  
}

PATTERN_INSTRUCTIONS( IP_Trim_Write2 )   /* Microcode */
{
}

PATTERN_VAR_UINSTS( IP_Trim_Write2 )   /* Microinstructions that use/manipulate VAR */
{
	PATTERN_VAR_UINST( IP_Trim_Write2, -1, 0, vt_NC )
}

PATTERN_VERSIONS( IP_Trim_Write2 )   /* Version of the compiler output */
{
	PATTERN_VERSION( PATTERN_VAR_GOSUB, 1 )
}

PATTERN_USED_TSETS( IP_Trim_Write2 )   /* TSETS used by this pattern */
{
	PATTERN_USED_TSET( TSET1 )
}

PATTERN_USED_VIHHS( IP_Trim_Write2 )   /* VIHH used by this pattern */
{
	PATTERN_USED_VIHH( VIHH1 )
}

PATTERN_ATTRIBUTES( IP_Trim_Write2 )   /* Pattern attributes */
{
	PATTERN_ATTRIBUTE( LOGIC )
	PATTERN_ATTRIBUTE( SINGLE )
}

PATTERN_HW_REQUIREMENTS( IP_Trim_Write2 )   /* Hardware requirements */
{
	PATTERN_HW_REQUIREMENT( mag, 2 )
	PATTERN_HW_REQUIREMENT( ebm, 1 )
}

PATTERN( IP_Trim_Write2 )   /* Process the pattern specific information */
{
	INITIAL_CONDITIONS( IP_Trim_Write2 )
	INSTRUCTIONS( IP_Trim_Write2 )
	VAR_UINSTS( IP_Trim_Write2 )
	VERSIONS( IP_Trim_Write2 )
	USED_TSETS( IP_Trim_Write2 )
	USED_VIHHS( IP_Trim_Write2 )
	ATTRIBUTES( IP_Trim_Write2 )
	HW_REQUIREMENTS( IP_Trim_Write2 )
}



/************ data global to this file ************/

LOGIC_VECTORS( IP_Trim_Write2 )   /* Logic vectors prescrambled according to PINASSIGNMENTS */
{
	LOGIC_VECTOR_MAG2( NZ3182, "IP_Trim_Write2_MAG2/NZ3182.hlh" )
	LOGIC_VECTOR_INDEX( "IP_Trim_Write2_MAG2/IP_Trim_Write2_MAG2.bkm" )
}
