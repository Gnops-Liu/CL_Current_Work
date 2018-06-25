#include "pat_macro.h"

PATTERN(P_Read_Rom)
@{
@}
Read_2DBit(0x88,0x00,0x5A,0X98,0X89,0X01,0X01,0X16)
wirte_2CBit(0x88,0x00,0x51,0x4b)
%mar	done
pinfunc adhiz
