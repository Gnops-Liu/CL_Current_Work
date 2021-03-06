// This file has been automatically generated by the pattern compiler.
// DO NOT EDIT!

#ifndef MAGNUM2
#define MAGNUM2
#endif 

#define PATCOM_OUTPUT
#include "tester.h"
#include "VDDLDO_Code10_MAG2.h"

#ifndef PATTERN_INSTRUCTION
#error PATTERN_INSTRUCTION not #defined ("tester.h" should not have "#pragma once").
#endif



/************ pattern "VDDLDO_Code10" ************/

PATTERN_INITIAL_CONDITIONS( VDDLDO_Code10 )   /* C Code to set initial conditions */
{
}

PATTERN_INSTRUCTIONS( VDDLDO_Code10 )   /* Microcode */
{
}

PATTERN_VAR_UINSTS( VDDLDO_Code10 )   /* Microinstructions that use/manipulate VAR */
{
	PATTERN_VAR_UINST( VDDLDO_Code10, -1, 0, vt_NC )
}

PATTERN_VERSIONS( VDDLDO_Code10 )   /* Version of the compiler output */
{
	PATTERN_VERSION( PATTERN_VAR_GOSUB, 1 )
}

PATTERN_USED_TSETS( VDDLDO_Code10 )   /* TSETS used by this pattern */
{
	PATTERN_USED_TSET( TSET1 )
}

PATTERN_USED_VIHHS( VDDLDO_Code10 )   /* VIHH used by this pattern */
{
	PATTERN_USED_VIHH( VIHH1 )
}

PATTERN_ATTRIBUTES( VDDLDO_Code10 )   /* Pattern attributes */
{
	PATTERN_ATTRIBUTE( LOGIC )
	PATTERN_ATTRIBUTE( SINGLE )
}

PATTERN_HW_REQUIREMENTS( VDDLDO_Code10 )   /* Hardware requirements */
{
	PATTERN_HW_REQUIREMENT( mag, 2 )
}

PATTERN( VDDLDO_Code10 )   /* Process the pattern specific information */
{
	INITIAL_CONDITIONS( VDDLDO_Code10 )
	INSTRUCTIONS( VDDLDO_Code10 )
	VAR_UINSTS( VDDLDO_Code10 )
	VERSIONS( VDDLDO_Code10 )
	USED_TSETS( VDDLDO_Code10 )
	USED_VIHHS( VDDLDO_Code10 )
	ATTRIBUTES( VDDLDO_Code10 )
	HW_REQUIREMENTS( VDDLDO_Code10 )
}



/************ data global to this file ************/

LOGIC_VECTORS( VDDLDO_Code10 )   /* Logic vectors prescrambled according to PINASSIGNMENTS */
{
	LOGIC_VECTOR_MAG2( NZ3182, "VDDLDO_Code10_MAG2/NZ3182.hlh" )
	LOGIC_VECTOR_INDEX( "VDDLDO_Code10_MAG2/VDDLDO_Code10_MAG2.bkm" )
}
