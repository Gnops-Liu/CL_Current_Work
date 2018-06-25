// This file has been automatically generated by the pattern compiler.
// DO NOT EDIT!

#ifndef MAGNUM2
#define MAGNUM2
#endif 

#define PATCOM_OUTPUT
#include "tester.h"
#include "CP_CLK_SEL_MAG2.h"

#ifndef PATTERN_INSTRUCTION
#error PATTERN_INSTRUCTION not #defined ("tester.h" should not have "#pragma once").
#endif



/************ pattern "CP_CLK_SEL" ************/

PATTERN_INITIAL_CONDITIONS( CP_CLK_SEL )   /* C Code to set initial conditions */
{
}

PATTERN_INSTRUCTIONS( CP_CLK_SEL )   /* Microcode */
{
}

PATTERN_VAR_UINSTS( CP_CLK_SEL )   /* Microinstructions that use/manipulate VAR */
{
	PATTERN_VAR_UINST( CP_CLK_SEL, -1, 0, vt_NC )
}

PATTERN_VERSIONS( CP_CLK_SEL )   /* Version of the compiler output */
{
	PATTERN_VERSION( PATTERN_VAR_GOSUB, 1 )
}

PATTERN_USED_TSETS( CP_CLK_SEL )   /* TSETS used by this pattern */
{
	PATTERN_USED_TSET( TSET1 )
}

PATTERN_USED_VIHHS( CP_CLK_SEL )   /* VIHH used by this pattern */
{
	PATTERN_USED_VIHH( VIHH1 )
}

PATTERN_ATTRIBUTES( CP_CLK_SEL )   /* Pattern attributes */
{
	PATTERN_ATTRIBUTE( LOGIC )
	PATTERN_ATTRIBUTE( SINGLE )
}

PATTERN_HW_REQUIREMENTS( CP_CLK_SEL )   /* Hardware requirements */
{
	PATTERN_HW_REQUIREMENT( mag, 2 )
}

PATTERN( CP_CLK_SEL )   /* Process the pattern specific information */
{
	INITIAL_CONDITIONS( CP_CLK_SEL )
	INSTRUCTIONS( CP_CLK_SEL )
	VAR_UINSTS( CP_CLK_SEL )
	VERSIONS( CP_CLK_SEL )
	USED_TSETS( CP_CLK_SEL )
	USED_VIHHS( CP_CLK_SEL )
	ATTRIBUTES( CP_CLK_SEL )
	HW_REQUIREMENTS( CP_CLK_SEL )
}



/************ data global to this file ************/

LOGIC_VECTORS( CP_CLK_SEL )   /* Logic vectors prescrambled according to PINASSIGNMENTS */
{
	LOGIC_VECTOR_MAG2( NZ3182, "CP_CLK_SEL_MAG2/NZ3182.hlh" )
	LOGIC_VECTOR_INDEX( "CP_CLK_SEL_MAG2/CP_CLK_SEL_MAG2.bkm" )
}
