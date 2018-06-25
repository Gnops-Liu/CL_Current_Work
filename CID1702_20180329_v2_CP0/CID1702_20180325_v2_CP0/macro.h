
#include "global.h"

//                SCLK/ RST/ SCE/ LDO18_EN /TEST_MOD1 /TEST_MOD2

#define cs_po     cs1pt,cs2t  
#define cs_hold   cs1f, cs2f
#define cs_erase  cs1pt,cs2f  
#define cs_hold   cs1f, cs2f        //no clock
#define cs_wait   cs1pt,cs2f
#define  cs_wr    cs1pt,cs2f
#define  cs_rd    cs1pt,cs2f

#define BitIn0(CS, TS)                       \n\
	chips CS                               \n\
	pinfunc PS_D0, TS                           \n\
    datgen mainmain               

#define BitIn1(CS, TS)                       \n\
	chips CS                               \n\
	pinfunc PS_D0, TS                           \n\
	datgen mainmain,invsns            

#define pBitIn(CS,PS,TS)                       \n\
	chips CS                               \n\
	pinfunc PS, TS                           \n\
	datgen jamjam                    

#define CMD_IN(CS, TS, DAT)                                \n\
    chips	CS							\n	\
	pinfunc	PS_D7, TS					\n	\
	datgen	jamjam, udatajam			\n	\
	udata	DAT							\n	\
	%	pBitIn(CS, PS_D6, TS)			\n  \
	%	pBitIn(CS, PS_D5, TS)			\n  \
	%	pBitIn(CS, PS_D4, TS)			\n  \
	%	pBitIn(CS, PS_D3, TS)			\n  \
	%	pBitIn(CS, PS_D2, TS)			\n  \
	%	pBitIn(CS, PS_D1, TS)			\n  \
	%	pBitIn(CS, PS_D0, TS)

#define DataIn(CS,TS,DAT)               \n \
	chips	CS							\n	\
	pinfunc	PS_D35, TS					\n	\
	datgen	jamjam, udatajam			\n	\
	udata	DAT							\n	\
	%	pBitIn(CS, PS_D34, TS)			\n  \
	%	pBitIn(CS, PS_D23, TS)			\n  \
	%	pBitIn(CS, PS_D32, TS)			\n  \
	%	pBitIn(CS, PS_D31, TS)			\n  \
	%	pBitIn(CS, PS_D30, TS)			\n  \
	%	pBitIn(CS, PS_D29, TS)			\n  \
	%	pBitIn(CS, PS_D28, TS)			\n  \
	%	pBitIn(CS, PS_D27, TS)			\n  \
	%	pBitIn(CS, PS_D26, TS)			\n  \
	%	pBitIn(CS, PS_D25, TS)			\n  \
	%	pBitIn(CS, PS_D24, TS)			\n  \
	%	pBitIn(CS, PS_D23, TS)			\n  \
	%	pBitIn(CS, PS_D22, TS)			\n  \
	%	pBitIn(CS, PS_D21, TS)			\n  \
	%	pBitIn(CS, PS_D20, TS)			\n  \
	%	pBitIn(CS, PS_D19, TS)			\n  \
	%	pBitIn(CS, PS_D18, TS)			\n  \
	%	pBitIn(CS, PS_D17, TS)			\n  \
	%	pBitIn(CS, PS_D16, TS)			\n  \
	%	pBitIn(CS, PS_D15, TS)			\n  \
	%	pBitIn(CS, PS_D14, TS)			\n  \
	%	pBitIn(CS, PS_D13, TS)			\n  \
	%	pBitIn(CS, PS_D12, TS)			\n  \
	%	pBitIn(CS, PS_D11, TS)			\n  \
	%	pBitIn(CS, PS_D10, TS)			\n  \
	%	pBitIn(CS, PS_D9, TS)			\n  \
	%	pBitIn(CS, PS_D8, TS)			\n  \
	%	pBitIn(CS, PS_D7, TS)			\n  \
	%	pBitIn(CS, PS_D6, TS)			\n  \
	%	pBitIn(CS, PS_D5, TS)			\n  \
	%	pBitIn(CS, PS_D4, TS)			\n  \
	%	pBitIn(CS, PS_D3, TS)			\n  \
	%	pBitIn(CS, PS_D2, TS)			\n  \
	%	pBitIn(CS, PS_D1, TS)			\n  \
	%	pBitIn(CS, PS_D0, TS)

////////////////////wait time//////////////
#define dummy0(TS)                        \n\
	chips cs_wr                          \n\
    pinfunc  PS_D31,TS                  \n\
	datgen mainmain
#define dummy1(TS)                        \n\
	chips cs_wr                          \n\
	pinfunc  PS_D31, TS, adhiz          \n\
	datgen mainmain,invsns

#define Dummy8(TS)                         \n\
	    dummy1(TS)                         \n\
    %   dummy1(TS)                         \n\
	%   dummy1(TS)                         \n\
	%   dummy1(TS)                         \n\
	%   dummy1(TS)                         \n\
	%   dummy1(TS)                         \n\
	%   dummy1(TS)                         \n\
	%   dummy1(TS)        

#define Dummy9(TS)                         \n\
	    dummy1(TS)                         \n\
    %   dummy1(TS)                         \n\
	%   dummy1(TS)                         \n\
	%   dummy1(TS)                         \n\
	%   dummy1(TS)                         \n\
	%   dummy1(TS)                         \n\
	%   dummy1(TS)                         \n\
	%   dummy1(TS)                         \n\
	%   dummy1(TS) 

#define Dummy32(TS)                        \n\
	dummy0(TS)                             \n\
    %	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                            \n\
	%	dummy0(TS)                             \n\
	%	dummy0(TS)                           

#define Wait_50US                        \n\
	chips   cs_wait                        \n\
	pinfunc PS_D0,tset1                 \n\
	datgen  mainmain,invsns                  \n\
	mar gosub,sub_wait_50us


#define Wait_100US                        \n\
	chips   cs_wait                        \n\
	pinfunc PS_D0,tset1                 \n\
	datgen  mainmain,invsns                  \n\
	mar gosub,sub_wait_100us

#define Wait_5600US                        \n\
	chips   cs_wait                        \n\
	pinfunc PS_D0,tset1                 \n\
	datgen  mainmain,invsns                  \n\
	mar gosub,sub_wait_5600us


#define Wait_Time                        \n\
	chips   cs_wait                        \n\
	pinfunc PS_D0, tset1                \n\
	datgen  mainmain, invsns                  \n\
	mar gosub, sub_wait_time
#define Wait_1sec                           \n\
	chips   cs_wait                        \n\
	pinfunc PS_D0, tset1, adhiz             \n\
	datgen  mainmain, invsns                  \n\
	mar gosub, sub_wait_1sec

////////////////////////////Read//////////////////////////


#define pBitOut_nocare(PS,TS)                                 \n\
chips  cs_rd                                                   \n\
pinfunc PS,TS,adhiz                                   

#define pBitOut(PS,TS)                                 \n\
chips  cs_rd                                       \n\
datgen jamjam                                        \n\
pinfunc PS,TS,adhiz                                   \n\
mar read

//*************************read odd number*****************

#define ReadOut_odd(TS,DAT)                         \n\
  chips cs_rd                                       \n\
  pinfunc PS_D35,TS,adhiz                               \n\
  datgen jamjam ,udatajam                               \n\
  udata   DAT                                            \n\
  mar read                                               \n\
%  pBitOut_nocare(PS_D34, TS)                             \n\
%  pBitOut(PS_D33, TS)                                   \n\
%  pBitOut_nocare(PS_D32, TS)                                   \n\
%  pBitOut(PS_D31, TS)                                   \n\
%  pBitOut_nocare(PS_D30, TS)                             \n\
%  pBitOut(PS_D29, TS)                                   \n\
%  pBitOut_nocare(PS_D28, TS)                                   \n\
%  pBitOut(PS_D27, TS)                                   \n\
%  pBitOut_nocare(PS_D26, TS)                                   \n\
%  pBitOut(PS_D25, TS)                                   \n\
%  pBitOut_nocare(PS_D24, TS)                                   \n\
%  pBitOut(PS_D23, TS)                                   \n\
%  pBitOut_nocare(PS_D22, TS)                                   \n\
%  pBitOut(PS_D21, TS)                                   \n\
%  pBitOut_nocare(PS_D20, TS)                                   \n\
%  pBitOut(PS_D19, TS)                                   \n\
%  pBitOut_nocare(PS_D18, TS)                                   \n\
%  pBitOut(PS_D17, TS)                                   \n\
%  pBitOut_nocare(PS_D16, TS)                                   \n\
%  pBitOut(PS_D15, TS)                                   \n\
%  pBitOut_nocare(PS_D14, TS)                                   \n\
%  pBitOut(PS_D13, TS)                                   \n\
%  pBitOut_nocare(PS_D12, TS)                                   \n\
%  pBitOut(PS_D11, TS)                                   \n\
%  pBitOut_nocare(PS_D10, TS)                                   \n\
%  pBitOut(PS_D9, TS)                                   \n\
%  pBitOut_nocare(PS_D8, TS)                                   \n\
%  pBitOut(PS_D7, TS)                                   \n\
%  pBitOut_nocare(PS_D6, TS)                                   \n\
%  pBitOut(PS_D5, TS)                                   \n\
%  pBitOut_nocare(PS_D4, TS)                                   \n\
%  pBitOut(PS_D3, TS)                                   \n\
%  pBitOut_nocare(PS_D2, TS)                                   \n\
%  pBitOut(PS_D1, TS)                                   \n\
%  pBitOut_nocare(PS_D0, TS)

//**************read even number**********************

#define ReadOut_even(TS,DAT)                                     \n\
chips cs_rd                                       \n\
pinfunc PS_D35,TS,adhiz                               \n\
datgen jamjam ,udatajam                               \n\
udata   DAT                                             \n\
%  pBitOut(PS_D34, TS)                                   \n\
%  pBitOut_nocare(PS_D33, TS)                                   \n\
%  pBitOut(PS_D32, TS)                                   \n\
%  pBitOut_nocare(PS_D31, TS)                                   \n\
%  pBitOut(PS_D30, TS)                                   \n\
%  pBitOut_nocare(PS_D29, TS)                                   \n\
%  pBitOut(PS_D28, TS)                                   \n\
%  pBitOut_nocare(PS_D27, TS)                                   \n\
%  pBitOut(PS_D26, TS)                                   \n\
%  pBitOut_nocare(PS_D25, TS)                                   \n\
%  pBitOut(PS_D24, TS)                                   \n\
%  pBitOut_nocare(PS_D23, TS)                                   \n\
%  pBitOut(PS_D22, TS)                                   \n\
%  pBitOut_nocare(PS_D21, TS)                                   \n\
%  pBitOut(PS_D20, TS)                                   \n\
%  pBitOut_nocare(PS_D19, TS)                                   \n\
%  pBitOut(PS_D18, TS)                                   \n\
%  pBitOut_nocare(PS_D17, TS)                                   \n\
%  pBitOut(PS_D16, TS)                                   \n\
%  pBitOut_nocare(PS_D15, TS)                                   \n\
%  pBitOut(PS_D14, TS)                                   \n\
%  pBitOut_nocare(PS_D13, TS)                                   \n\
%  pBitOut(PS_D12, TS)                                   \n\
%  pBitOut_nocare(PS_D11, TS)                                   \n\
%  pBitOut(PS_D10, TS)                                   \n\
%  pBitOut_nocare(PS_D9, TS)                                   \n\
%  pBitOut(PS_D8, TS)                                   \n\
%  pBitOut_nocare(PS_D7, TS)                                   \n\
%  pBitOut(PS_D6, TS)                                   \n\
%  pBitOut_nocare(PS_D5, TS)                                   \n\
%  pBitOut(PS_D4, TS)                                   \n\
%  pBitOut_nocare(PS_D3, TS)                                   \n\
%  pBitOut(PS_D2, TS)                                   \n\
%  pBitOut_nocare(PS_D1, TS)                                   \n\
%  pBitOut(PS_D0, TS)


#define ReadOut(TS,DAT)                                     \n\
  chips cs_rd                                       \n\
  pinfunc PS_D35,TS,adhiz                               \n\
  datgen jamjam ,udatajam                               \n\
  udata   DAT                                            \n\
  mar read                                               \n\
%  pBitOut(PS_D34, TS)                                   \n\
%  pBitOut(PS_D33, TS)                                   \n\
%  pBitOut(PS_D32, TS)                                   \n\
%  pBitOut(PS_D31, TS)                                   \n\
%  pBitOut(PS_D30, TS)                                   \n\
%  pBitOut(PS_D29, TS)                                   \n\
%  pBitOut(PS_D28, TS)                                   \n\
%  pBitOut(PS_D27, TS)                                   \n\
%  pBitOut(PS_D26, TS)                                   \n\
%  pBitOut(PS_D25, TS)                                   \n\
%  pBitOut(PS_D24, TS)                                   \n\
%  pBitOut(PS_D23, TS)                                   \n\
%  pBitOut(PS_D22, TS)                                   \n\
%  pBitOut(PS_D21, TS)                                   \n\
%  pBitOut(PS_D20, TS)                                   \n\
%  pBitOut(PS_D19, TS)                                   \n\
%  pBitOut(PS_D18, TS)                                   \n\
%  pBitOut(PS_D17, TS)                                   \n\
%  pBitOut(PS_D16, TS)                                   \n\
%  pBitOut(PS_D15, TS)                                   \n\
%  pBitOut(PS_D14, TS)                                   \n\
%  pBitOut(PS_D13, TS)                                   \n\
%  pBitOut(PS_D12, TS)                                   \n\
%  pBitOut(PS_D11, TS)                                   \n\
%  pBitOut(PS_D10, TS)                                   \n\
%  pBitOut(PS_D9, TS)                                   \n\
%  pBitOut(PS_D8, TS)                                   \n\
%  pBitOut(PS_D7, TS)                                   \n\
%  pBitOut(PS_D6, TS)                                   \n\
%  pBitOut(PS_D5, TS)                                   \n\
%  pBitOut(PS_D4, TS)                                   \n\
%  pBitOut(PS_D3, TS)                                   \n\
%  pBitOut(PS_D2, TS)                                   \n\
%  pBitOut(PS_D1, TS)                                   \n\
%  pBitOut(PS_D0, TS)                               

#define ReadOut_nocare(TS)                           \n\
	chips cs_rd                                       \n\
	pinfunc PS_D35, TS, adhiz                               \n\
	%  pBitOut_nocare(PS_D34, TS)                                   \n\
	%  pBitOut_nocare(PS_D33, TS)                                   \n\
	%  pBitOut_nocare(PS_D32, TS)                                   \n\
	%  pBitOut_nocare(PS_D31, TS)                                   \n\
	%  pBitOut_nocare(PS_D30, TS)                                   \n\
	%  pBitOut_nocare(PS_D29, TS)                                   \n\
	%  pBitOut_nocare(PS_D28, TS)                                   \n\
	%  pBitOut_nocare(PS_D27, TS)                                   \n\
	%  pBitOut_nocare(PS_D26, TS)                                   \n\
	%  pBitOut_nocare(PS_D25, TS)                                   \n\
	%  pBitOut_nocare(PS_D24, TS)                                   \n\
	%  pBitOut_nocare(PS_D23, TS)                                   \n\
	%  pBitOut_nocare(PS_D22, TS)                                   \n\
	%  pBitOut_nocare(PS_D21, TS)                                   \n\
	%  pBitOut_nocare(PS_D20, TS)                                   \n\
	%  pBitOut_nocare(PS_D19, TS)                                   \n\
	%  pBitOut_nocare(PS_D18, TS)                                   \n\
	%  pBitOut_nocare(PS_D17, TS)                                   \n\
	%  pBitOut_nocare(PS_D16, TS)                                   \n\
	%  pBitOut_nocare(PS_D15, TS)                                   \n\
	%  pBitOut_nocare(PS_D14, TS)                                   \n\
	%  pBitOut_nocare(PS_D13, TS)                                   \n\
	%  pBitOut_nocare(PS_D12, TS)                                   \n\
	%  pBitOut_nocare(PS_D11, TS)                                   \n\
	%  pBitOut_nocare(PS_D10, TS)                                   \n\
	%  pBitOut_nocare(PS_D9, TS)                                   \n\
	%  pBitOut_nocare(PS_D8, TS)                                   \n\
	%  pBitOut_nocare(PS_D7, TS)                                   \n\
	%  pBitOut_nocare(PS_D6, TS)                                   \n\
	%  pBitOut_nocare(PS_D5, TS)                                   \n\
	%  pBitOut_nocare(PS_D4, TS)                                   \n\
	%  pBitOut_nocare(PS_D3, TS)                                   \n\
	%  pBitOut_nocare(PS_D2, TS)                                   \n\
	%  pBitOut_nocare(PS_D1, TS)                                   \n\
	%  pBitOut_nocare(PS_D0, TS)

//////////////////////////////addr////////////////////////////
#define AddressIn_bit(CS,PS,TS)                 \n\
	xalu xmain, xcare, coff, hold, dxmain, oxmain     \n\
	yalu ymain, xcare, coff, hold, dymain, oymain     \n\
	datgen mainmain                              \n\
	chips CS                                   \n\
	pinfunc PS, TS


    #define AddressIn(CS,TS)                  \n\
	AddressIn_bit(CS, PS_A23, TS)			\n  \
	%	AddressIn_bit(CS, PS_A22, TS)			\n  \
	%	AddressIn_bit(CS, PS_A21, TS)			\n  \
	%	AddressIn_bit(CS, PS_A20, TS)			\n  \
	%	AddressIn_bit(CS, PS_A19, TS)			\n  \
	%	AddressIn_bit(CS, PS_A18, TS)			\n  \
	%	AddressIn_bit(CS, PS_A17, TS)			\n  \
	%	AddressIn_bit(CS, PS_A16, TS)			\n  \
	%	AddressIn_bit(CS, PS_A15, TS)			\n  \
	%	AddressIn_bit(CS, PS_A14, TS)			\n  \
	%	AddressIn_bit(CS, PS_A13, TS)			\n  \
	%	AddressIn_bit(CS, PS_A12, TS)			\n  \
	%	AddressIn_bit(CS, PS_A11, TS)			\n  \
	%	AddressIn_bit(CS, PS_A10, TS)			\n  \
	%	AddressIn_bit(CS, PS_A9, TS)			\n  \
	%	AddressIn_bit(CS, PS_A8, TS)			\n  \
	%	AddressIn_bit(CS, PS_A7, TS)			\n  \
	%	AddressIn_bit(CS, PS_A6, TS)           \n\
	%   AddressIn_bit(CS, PS_A5, TS)			\n  \
	%	AddressIn_bit(CS, PS_A4, TS)			\n  \
	%	AddressIn_bit(CS, PS_A3, TS)			\n  \
	%	AddressIn_bit(CS, PS_A2, TS)			\n  \
	%	AddressIn_bit(CS, PS_A1, TS)			\n  \
	%	AddressIn_bit(CS, PS_A0, TS)




#define AddressIn_bit1(CS,PS,TS)                 \n\
	xalu xmain, xcare, coff, hold, dxmain, oxmain     \n\
	yalu ymain, xcare, coff, hold, dymain, oymain     \n\
	datgen mainmain,invsns                            \n\
	chips CS                                   \n\
	pinfunc PS, TS


#define AddressIn_nvr0(CS,TS)                  \n\
	AddressIn_bit1(CS, PS_A23, TS)			\n  \
	%	AddressIn_bit(CS, PS_A22, TS)			\n  \
	%	AddressIn_bit(CS, PS_A21, TS)			\n  \
	%	AddressIn_bit(CS, PS_A20, TS)			\n  \
	%	AddressIn_bit(CS, PS_A19, TS)			\n  \
	%	AddressIn_bit(CS, PS_A18, TS)			\n  \
	%	AddressIn_bit(CS, PS_A17, TS)			\n  \
	%	AddressIn_bit(CS, PS_A16, TS)			\n  \
	%	AddressIn_bit(CS, PS_A15, TS)			\n  \
	%	AddressIn_bit(CS, PS_A14, TS)			\n  \
	%	AddressIn_bit(CS, PS_A13, TS)			\n  \
	%	AddressIn_bit(CS, PS_A12, TS)			\n  \
	%	AddressIn_bit(CS, PS_A11, TS)			\n  \
	%	AddressIn_bit(CS, PS_A10, TS)			\n  \
	%	AddressIn_bit(CS, PS_A9, TS)			\n  \
	%	AddressIn_bit(CS, PS_A8, TS)			\n  \
	%	AddressIn_bit(CS, PS_A7, TS)			\n  \
	%	AddressIn_bit(CS, PS_A6, TS)           \n\
	%   AddressIn_bit(CS, PS_A5, TS)			\n  \
	%	AddressIn_bit(CS, PS_A4, TS)			\n  \
	%	AddressIn_bit(CS, PS_A3, TS)			\n  \
	%	AddressIn_bit(CS, PS_A2, TS)			\n  \
	%	AddressIn_bit(CS, PS_A1, TS)			\n  \
	%	AddressIn_bit(CS, PS_A0, TS)

#define Xaddr_inc8(TS)                     \n\
   chips cs_hold                          \n\
   pinfunc PS_D31, tset1, adhiz               \n\
   mar  gosub,sub_xaddr_inc


#define pByteInbybit(CS, PS, TS)	\n  \
	chips	CS						\n	\
	pinfunc	PS, TS					\n	\
	datgen	jamjam
	

#define	pByteIn(CS, TS, DAT)			\n	\
	chips	CS							\n	\
	pinfunc	PS_D7, TS					\n	\
	datgen	jamjam, udatajam			\n	\
	udata	DAT							\n	\
	%	pByteInbybit(CS, PS_D6, TS)			\n  \
	%	pByteInbybit(CS, PS_D5, TS)			\n  \
	%	pByteInbybit(CS, PS_D4, TS)			\n  \
	%	pByteInbybit(CS, PS_D3, TS)			\n  \
	%	pByteInbybit(CS, PS_D2, TS)			\n  \
	%	pByteInbybit(CS, PS_D1, TS)			\n  \
	%	pByteInbybit(CS, PS_D0, TS)

#define pModeIn(TS, DAT)				\n  \
		BitIn0(cs_po, TS)			\n  \
	%	BitIn1(cs_wr, TS)			\n  \
	%	BitIn1(cs_wr, TS)			\n  \
	%	BitIn1(cs_po, TS)			\n  \
	%	BitIn1(cs_wr, TS)			\n  \
	%	BitIn0(cs_po, TS)			\n  \
	%	pByteIn(cs_wr, TS, DAT)

#define SubPowerOn					\n  \
	chips	cs_wr					\n  \
	pinfunc PS_D0, tset1			\n  \
	datgen  mainmain, invsns        \n  \
	mar		gosub, sub_powr_on

#define bg_trim(CS, TS, DAT)				\n  \
	chips	CS							\n	\
	pinfunc	PS_D0, TS					\n	\
	datgen	jamjam, udatajam			\n	\
	udata	DAT							\n	\
	%	chips	CS							\n	\
	pinfunc	PS_D0, TS					\n	\
	datgen	jamjam						\n	\
	%	chips	CS							\n	\
	pinfunc	PS_D0, TS					\n	\
	datgen	jamjam						\n  \
	%	pByteInbybit(CS, PS_D1, TS)			\n  \
	%	pByteInbybit(CS, PS_D2, TS)			\n  \
	%	pByteInbybit(CS, PS_D3, TS)			\n  \
	%	pByteInbybit(CS, PS_D4, TS)			\n  \
	%	pByteInbybit(CS, PS_D5, TS)   \n  \
    %   BitIn0(cs_wr, tset1)  \n  \
    %   BitIn0(cs_wr, tset1)

#define pBitOut_osc(TS)                                 \n\
chips  cs_rd                                       \n\
datgen mainmain ,invsns                             \n\
pinfunc PS_D1,TS,adhiz                                   \n\
mar read

#define ReadOut_OSC(TS)                         \n\
chips cs_rd                                       \n\
pinfunc PS_D0,TS,adhiz                             \n\
%  pBitOut_osc(TS)                             \n\
%  pBitOut_nocare(PS_D2, TS)                                   \n\
%  pBitOut_nocare(PS_D3, TS)                                   \n\
%  pBitOut_nocare(PS_D4, TS)                                   \n\
%  pBitOut_nocare(PS_D5, TS)                                   \n\
%  pBitOut_nocare(PS_D6, TS)                                   \n\
%  pBitOut_nocare(PS_D7, TS)                                   \n\


#define DataIn32(CS,TS,DAT)               \n \
	chips	CS							\n	\
	pinfunc	PS_D35, TS					\n	\
	datgen	jamjam, udatajam			\n	\
	udata	DAT							\n	\
	%	pBitIn(CS, PS_D34, TS)			\n  \
	%	pBitIn(CS, PS_D23, TS)			\n  \
	%	pBitIn(CS, PS_D32, TS)			\n  \
	%	pBitIn(CS, PS_D31, TS)			\n  \
	%	pBitIn(CS, PS_D30, TS)			\n  \
	%	pBitIn(CS, PS_D29, TS)			\n  \
	%	pBitIn(CS, PS_D28, TS)			\n  \
	%	pBitIn(CS, PS_D27, TS)			\n  \
	%	pBitIn(CS, PS_D26, TS)			\n  \
	%	pBitIn(CS, PS_D25, TS)			\n  \
	%	pBitIn(CS, PS_D24, TS)			\n  \
	%	pBitIn(CS, PS_D23, TS)			\n  \
	%	pBitIn(CS, PS_D22, TS)			\n  \
	%	pBitIn(CS, PS_D21, TS)			\n  \
	%	pBitIn(CS, PS_D20, TS)			\n  \
	%	pBitIn(CS, PS_D19, TS)			\n  \
	%	pBitIn(CS, PS_D18, TS)			\n  \
	%	pBitIn(CS, PS_D17, TS)			\n  \
	%	pBitIn(CS, PS_D16, TS)			\n  \
	%	pBitIn(CS, PS_D15, TS)			\n  \
	%	pBitIn(CS, PS_D14, TS)			\n  \
	%	pBitIn(CS, PS_D13, TS)			\n  \
	%	pBitIn(CS, PS_D12, TS)			\n  \
	%	pBitIn(CS, PS_D11, TS)			\n  \
	%	pBitIn(CS, PS_D10, TS)			\n  \
	%	pBitIn(CS, PS_D9, TS)			\n  \
	%	pBitIn(CS, PS_D8, TS)			\n  \
	%	pBitIn(CS, PS_D7, TS)			\n  \
	%	pBitIn(CS, PS_D6, TS)			\n  \
	%	pBitIn(CS, PS_D5, TS)			\n  \
	%	pBitIn(CS, PS_D4, TS)			



#define DataIn16H(CS,TS,DAT)               \n \
	chips	CS							\n	\
	pinfunc	PS_D35, TS					\n	\
	datgen	jamjam, udatajam			\n	\
	udata	DAT							\n	\
	%	pBitIn(CS, PS_D34, TS)			\n  \
	%	pBitIn(CS, PS_D23, TS)			\n  \
	%	pBitIn(CS, PS_D32, TS)			\n  \
	%	pBitIn(CS, PS_D31, TS)			\n  \
	%	pBitIn(CS, PS_D30, TS)			\n  \
	%	pBitIn(CS, PS_D29, TS)			\n  \
	%	pBitIn(CS, PS_D28, TS)			\n  \
	%	pBitIn(CS, PS_D27, TS)			\n  \
	%	pBitIn(CS, PS_D26, TS)			\n  \
	%	pBitIn(CS, PS_D25, TS)			\n  \
	%	pBitIn(CS, PS_D24, TS)			\n  \
	%	pBitIn(CS, PS_D23, TS)			\n  \
	%	pBitIn(CS, PS_D22, TS)			\n  \
	%	pBitIn(CS, PS_D21, TS)			\n  \
	%	pBitIn(CS, PS_D20, TS)			

#define DataIn16L(CS,TS,DAT)               \n \
	chips	CS							\n	\
	pinfunc	PS_D15, TS					\n	\
	datgen	jamjam, udatajam			\n	\
	udata	DAT							\n	\
%	pBitIn(CS, PS_D14, TS)			\n  \
%	pBitIn(CS, PS_D13, TS)			\n  \
%	pBitIn(CS, PS_D12, TS)			\n  \
%	pBitIn(CS, PS_D11, TS)			\n  \
%	pBitIn(CS, PS_D10, TS)			\n  \
%	pBitIn(CS, PS_D9, TS)			\n  \
%	pBitIn(CS, PS_D8, TS)			\n  \
%	pBitIn(CS, PS_D7, TS)			\n  \
%	pBitIn(CS, PS_D6, TS)			\n  \
%	pBitIn(CS, PS_D5, TS)			\n  \
%	pBitIn(CS, PS_D4, TS)           \n  \
%   pBitIn(CS, PS_D3, TS)			\n  \
%	pBitIn(CS, PS_D2, TS)			\n  \
%	pBitIn(CS, PS_D1, TS)			\n  \
%	pBitIn(CS, PS_D0, TS)			

#define trim_first(CS,TS,DAT)             \n \
	chips	CS							\n	\
	pinfunc	PS_D3, TS					\n	\
	datgen	jamjam, udatajam			\n	\
	udata	DAT							\n	\
	%	pBitIn(CS, PS_D2, TS)			\n  \
	%	pBitIn(CS, PS_D1, TS)			\n  \
	%	pBitIn(CS, PS_D0, TS)

#define trim_middle(CS,TS,DAT)             \n \
	chips	CS							\n	\
	pinfunc	PS_D19, TS					\n	\
	datgen	jamjam, udatajam			\n	\
	udata	DAT							\n	\
	%	pBitIn(CS, PS_D18, TS)			\n  \
	%	pBitIn(CS, PS_D17, TS)			\n  \
	%	pBitIn(CS, PS_D16, TS)



#define Address01_In(CS,PS,TS)                 \n\
	xalu xmain, xcare, coff, hold, dxmain, oxbase    \n\
	yalu ymain, xcare, coff, hold, dymain, oybase     \n\
	chips CS                                   \n\
	pinfunc PS, TS


#define AddressIn01(CS,TS)                  \n\
	    Address01_In(CS, PS_A23, TS)			\n  \
	%	Address01_In(CS, PS_A22, TS)			\n  \
	%	Address01_In(CS, PS_A21, TS)			\n  \
	%	Address01_In(CS, PS_A20, TS)			\n  \
	%	Address01_In(CS, PS_A18, TS)			\n  \
	%	Address01_In(CS, PS_A17, TS)			\n  \
	%	Address01_In(CS, PS_A16, TS)			\n  \
	%	Address01_In(CS, PS_A15, TS)			\n  \
	%	Address01_In(CS, PS_A14, TS)			\n  \
	%	Address01_In(CS, PS_A13, TS)			\n  \
	%	Address01_In(CS, PS_A12, TS)			\n  \
	%	Address01_In(CS, PS_A11, TS)			\n  \
	%	Address01_In(CS, PS_A10, TS)			\n  \
	%	Address01_In(CS, PS_A9, TS)			\n  \
	%	Address01_In(CS, PS_A8, TS)			\n  \
	%	Address01_In(CS, PS_A7, TS)			\n  \
	%	Address01_In(CS, PS_A6, TS)           \n\
	%   Address01_In(CS, PS_A5, TS)			\n  \
	%	Address01_In(CS, PS_A4, TS)			\n  \
	%	Address01_In(CS, PS_A3, TS)			\n  \
	%	Address01_In(CS, PS_A2, TS)			\n  \
	%	Address01_In(CS, PS_A1, TS)			\n  \
	%	Address01_In(CS, PS_A0, TS)

#define Address02_In(CS,PS,TS)                 \n\
	xalu xmain, xcare, coff, hold, dxmain, oxfield    \n\
	yalu ymain, xcare, coff, hold, dymain, oyfield    \n\
	chips CS                                   \n\
	pinfunc PS, TS


#define AddressIn02(CS,TS)                  \n\
	    Address02_In(CS, PS_A23, TS)			\n  \
	%	Address02_In(CS, PS_A22, TS)			\n  \
	%	Address02_In(CS, PS_A21, TS)			\n  \
	%	Address02_In(CS, PS_A20, TS)			\n  \
	%	Address02_In(CS, PS_A18, TS)			\n  \
	%	Address02_In(CS, PS_A17, TS)			\n  \
	%	Address02_In(CS, PS_A16, TS)			\n  \
	%	Address02_In(CS, PS_A15, TS)			\n  \
	%	Address02_In(CS, PS_A14, TS)			\n  \
	%	Address02_In(CS, PS_A13, TS)			\n  \
	%	Address02_In(CS, PS_A12, TS)			\n  \
	%	Address02_In(CS, PS_A11, TS)			\n  \
	%	Address02_In(CS, PS_A10, TS)			\n  \
	%	Address02_In(CS, PS_A9, TS)			\n  \
	%	Address02_In(CS, PS_A8, TS)			\n  \
	%	Address02_In(CS, PS_A7, TS)			\n  \
	%	Address02_In(CS, PS_A6, TS)           \n\
	%   Address02_In(CS, PS_A5, TS)			\n  \
	%	Address02_In(CS, PS_A4, TS)			\n  \
	%	Address02_In(CS, PS_A3, TS)			\n  \
	%	Address02_In(CS, PS_A2, TS)			\n  \
	%	Address02_In(CS, PS_A1, TS)			\n  \
	%	Address02_In(CS, PS_A0, TS)