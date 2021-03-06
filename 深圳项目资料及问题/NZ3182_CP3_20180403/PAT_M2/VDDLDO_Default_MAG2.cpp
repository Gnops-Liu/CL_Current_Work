// This file has been automatically generated by the pattern compiler.
// DO NOT EDIT!

#ifndef MAGNUM2
#define MAGNUM2
#endif 

#define PATCOM_OUTPUT
#include "tester.h"
#include "VDDLDO_Default_MAG2.h"

#ifndef PATTERN_INSTRUCTION
#error PATTERN_INSTRUCTION not #defined ("tester.h" should not have "#pragma once").
#endif



/************ pattern "VDDLDO_Default" ************/

PATTERN_INITIAL_CONDITIONS( VDDLDO_Default )   /* C Code to set initial conditions */
{
}

PATTERN_INSTRUCTIONS( VDDLDO_Default )   /* Microcode */
{
}

PATTERN_VAR_UINSTS( VDDLDO_Default )   /* Microinstructions that use/manipulate VAR */
{
	PATTERN_VAR_UINST( VDDLDO_Default, -1, 0, vt_NC )
}

PATTERN_VERSIONS( VDDLDO_Default )   /* Version of the compiler output */
{
	PATTERN_VERSION( PATTERN_VAR_GOSUB, 1 )
}

PATTERN_USED_TSETS( VDDLDO_Default )   /* TSETS used by this pattern */
{
	PATTERN_USED_TSET( TSET1 )
}

PATTERN_USED_VIHHS( VDDLDO_Default )   /* VIHH used by this pattern */
{
	PATTERN_USED_VIHH( VIHH1 )
}

PATTERN_ATTRIBUTES( VDDLDO_Default )   /* Pattern attributes */
{
	PATTERN_ATTRIBUTE( LOGIC )
	PATTERN_ATTRIBUTE( SINGLE )
}

PATTERN_HW_REQUIREMENTS( VDDLDO_Default )   /* Hardware requirements */
{
	PATTERN_HW_REQUIREMENT( mag, 2 )
}

PATTERN( VDDLDO_Default )   /* Process the pattern specific information */
{
	INITIAL_CONDITIONS( VDDLDO_Default )
	INSTRUCTIONS( VDDLDO_Default )
	VAR_UINSTS( VDDLDO_Default )
	VERSIONS( VDDLDO_Default )
	USED_TSETS( VDDLDO_Default )
	USED_VIHHS( VDDLDO_Default )
	ATTRIBUTES( VDDLDO_Default )
	HW_REQUIREMENTS( VDDLDO_Default )
}



/************ data global to this file ************/

LOGIC_VECTORS( VDDLDO_Default )   /* Logic vectors prescrambled according to PINASSIGNMENTS */
{
	LOGIC_VECTOR_MAG2( NZ3182, "VDDLDO_Default_MAG2/NZ3182.hlh" )
	LOGIC_VECTOR_INDEX( "VDDLDO_Default_MAG2/VDDLDO_Default_MAG2.bkm" )
}
