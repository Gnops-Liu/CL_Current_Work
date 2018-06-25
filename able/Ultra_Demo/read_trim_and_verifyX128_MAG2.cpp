// This file has been automatically generated by the pattern compiler.
// DO NOT EDIT!

#ifndef MAGNUM2
#define MAGNUM2
#endif 

#define PATCOM_OUTPUT
#include "tester.h"
#include "read_trim_and_verifyX128_MAG2.h"

#ifndef PATTERN_INSTRUCTION
#error PATTERN_INSTRUCTION not #defined ("tester.h" should not have "#pragma once").
#endif



/************ pattern "p_read_trim_and_verifyX128" ************/

PATTERN_INITIAL_CONDITIONS( p_read_trim_and_verifyX128 )   /* C Code to set initial conditions */
{
	count(1, 0);		//For common loop
	count(2, 8);		//spi address bits -2
	count(3, 16);		//spi data bits -2
	count(4, 14);		//stb data bits - 2 
	count(5, 5);		//stb data bits - 3
	count(6, 6);		//stb cmd bits -2
	count(7, 22);		//stb cmd bits -1
	count(8, 0);		//common delay
	count(10, 9);
	dmain(0x0);
	
}

PATTERN_INSTRUCTIONS( p_read_trim_and_verifyX128 )   /* Microcode */
{
	/* 0 */
	PATTERN_INSTRUCTION(0x800070EC,0x00000018,0x03E60000,0x02000000,0x00010000,0x6181883F,0x00000000,0x34043400,0x000010D0)
	PATTERN_INSTRUCTION(0x000070F8,0x0008000C,0x00000000,0x08000000,0x00010000,0x6181883F,0x00000000,0x34043400,0x000010D0)
	PATTERN_INSTRUCTION(0x8000700C,0x00000018,0x4E230000,0x02000000,0x00010000,0x6199883F,0x00000000,0x34043400,0x000010D0)
	PATTERN_INSTRUCTION(0x00007018,0x0018000C,0x00000000,0x08000000,0x00010000,0x6199883F,0x00000000,0x34043400,0x000010D0)
	PATTERN_INSTRUCTION(0x00000018,0x00000018,0x03020000,0x00000000,0x00010001,0x6199883F,0x00000000,0x34043400,0x870010D0)
	PATTERN_INSTRUCTION(0x00000078,0x00000018,0x20150000,0x00000000,0x00010000,0x6199883F,0x00000000,0x34043400,0x870010D0)
	PATTERN_INSTRUCTION(0x0000000C,0x00000018,0x00000000,0x02000000,0x40010002,0x61980802,0x00000000,0x34043400,0x000010D0)
	PATTERN_INSTRUCTION(0x00003078,0x8038000C,0x00000000,0x08000000,0x40010002,0x61980802,0x00000000,0x34043400,0xBC0010D0)
	PATTERN_INSTRUCTION(0x000000EC,0x00000018,0x00000000,0x02000000,0x40010003,0x61980802,0x00000000,0x34043400,0x000010D0)
	PATTERN_INSTRUCTION(0x000030F8,0x8048000C,0x00000000,0x08000000,0x40010003,0x61980802,0x00000000,0x34043400,0xBC0010D0)
	/* 10 */
	PATTERN_INSTRUCTION(0x800070EC,0x00000018,0x10000000,0x02000000,0x00010000,0x6198083F,0x00000000,0x34043400,0x000010D0)
	PATTERN_INSTRUCTION(0x000070F8,0x0058000C,0x00000000,0x08000000,0x00010000,0x6198083F,0x00000000,0x34043400,0x000010D0)
	PATTERN_INSTRUCTION(0x8000700C,0x00000018,0x4E1E0000,0x02000000,0x00010000,0x6198083F,0x00000000,0x34043400,0x000010D0)
	PATTERN_INSTRUCTION(0x0070700E,0x0068000C,0x00000000,0x08000000,0x00010000,0x6198083F,0x00000000,0x34043400,0x000010D0)
	PATTERN_INSTRUCTION(0x00000018,0x0070000E,0x00000020,0x00000000,0x00010080,0x00000000,0x00000000,0x34043400,0x000010D0)
}

PATTERN_LABELS( p_read_trim_and_verifyX128 )   /* List of all labels with their associated microinstructions */
{
	PATTERN_LABEL( 1, "bg_setup1_start" )
	PATTERN_LABEL( 3, "bg_setup2_start" )
	PATTERN_LABEL( 7, "enter_serial_testmode_datal" )
	PATTERN_LABEL( 9, "enter_serial_testmode_datah" )
	PATTERN_LABEL( 11, "label_name_dummy_start" )
	PATTERN_LABEL( 13, "delay2_start" )
}

PATTERN_MAR_RELOC_UINSTS( p_read_trim_and_verifyX128 )   /* Microinstructions that need MAR address relocated */
{
	PATTERN_MAR_RELOC_UINST( 1 )
	PATTERN_MAR_RELOC_UINST( 3 )
	PATTERN_MAR_RELOC_UINST( 7 )
	PATTERN_MAR_RELOC_UINST( 9 )
	PATTERN_MAR_RELOC_UINST( 11 )
	PATTERN_MAR_RELOC_UINST( 13 )
	PATTERN_MAR_RELOC_UINST( 14 )
}

PATTERN_MAR_FUNCB_UINSTS( p_read_trim_and_verifyX128 )   /* Instructions requiring MAR_FUNCB fixup */
{
	PATTERN_MAR_FUNCB_UINST( 14, p_read_trim_and_verifyX128, 14 )
	PATTERN_MAR_FUNCB_UINST( 1, p_read_trim_and_verifyX128, 1 )
	PATTERN_MAR_FUNCB_UINST( 3, p_read_trim_and_verifyX128, 3 )
	PATTERN_MAR_FUNCB_UINST( 7, p_read_trim_and_verifyX128, 7 )
	PATTERN_MAR_FUNCB_UINST( 9, p_read_trim_and_verifyX128, 9 )
	PATTERN_MAR_FUNCB_UINST( 11, p_read_trim_and_verifyX128, 11 )
	PATTERN_MAR_FUNCB_UINST( 13, p_read_trim_and_verifyX128, 13 )
	PATTERN_MAR_FUNCB_UINST( 0, p_read_trim_and_verifyX128, -1 )
	PATTERN_MAR_FUNCB_UINST( 2, p_read_trim_and_verifyX128, -1 )
	PATTERN_MAR_FUNCB_UINST( 10, p_read_trim_and_verifyX128, -1 )
	PATTERN_MAR_FUNCB_UINST( 12, p_read_trim_and_verifyX128, -1 )
}

PATTERN_COUNTER_UINSTS( p_read_trim_and_verifyX128 )   /* Instructions requiring Counter func/addr fixup */
{
	PATTERN_COUNTER_UINST( 0, p_read_trim_and_verifyX128, -1 )
	PATTERN_COUNTER_UINST( 1, p_read_trim_and_verifyX128, 1 )
	PATTERN_COUNTER_UINST( 2, p_read_trim_and_verifyX128, -1 )
	PATTERN_COUNTER_UINST( 3, p_read_trim_and_verifyX128, 3 )
	PATTERN_COUNTER_UINST( 7, p_read_trim_and_verifyX128, 7 )
	PATTERN_COUNTER_UINST( 9, p_read_trim_and_verifyX128, 9 )
	PATTERN_COUNTER_UINST( 10, p_read_trim_and_verifyX128, -1 )
	PATTERN_COUNTER_UINST( 11, p_read_trim_and_verifyX128, 11 )
	PATTERN_COUNTER_UINST( 12, p_read_trim_and_verifyX128, -1 )
	PATTERN_COUNTER_UINST( 13, p_read_trim_and_verifyX128, 13 )
}

PATTERN_VERSIONS( p_read_trim_and_verifyX128 )   /* Version of the compiler output */
{
	PATTERN_VERSION( PATTERN_VAR_GOSUB, 1 )
}

PATTERN_USED_TSETS( p_read_trim_and_verifyX128 )   /* TSETS used by this pattern */
{
	PATTERN_USED_TSET( TSET1 )
}

PATTERN_USED_VIHHS( p_read_trim_and_verifyX128 )   /* VIHH used by this pattern */
{
	PATTERN_USED_VIHH( VIHH1 )
}

PATTERN_ATTRIBUTES( p_read_trim_and_verifyX128 )   /* Pattern attributes */
{
	PATTERN_ATTRIBUTE( MEM )
	PATTERN_ATTRIBUTE( SINGLE )
}

PATTERN_HW_REQUIREMENTS( p_read_trim_and_verifyX128 )   /* Hardware requirements */
{
	PATTERN_HW_REQUIREMENT( mag, 2 )
}

PATTERN( p_read_trim_and_verifyX128 )   /* Process the pattern specific information */
{
	INITIAL_CONDITIONS( p_read_trim_and_verifyX128 )
	INSTRUCTIONS( p_read_trim_and_verifyX128 )
	LABELS( p_read_trim_and_verifyX128 )
	MAR_RELOC_UINSTS( p_read_trim_and_verifyX128 )
	MAR_FUNCB_UINSTS( p_read_trim_and_verifyX128 )
	COUNTER_UINSTS( p_read_trim_and_verifyX128 )
	VERSIONS( p_read_trim_and_verifyX128 )
	USED_TSETS( p_read_trim_and_verifyX128 )
	USED_VIHHS( p_read_trim_and_verifyX128 )
	ATTRIBUTES( p_read_trim_and_verifyX128 )
	HW_REQUIREMENTS( p_read_trim_and_verifyX128 )
}
