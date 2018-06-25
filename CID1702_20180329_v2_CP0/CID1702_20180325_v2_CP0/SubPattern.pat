#include "macro.h"


PATTERN( sub_wait_50us )              //count1,  850
%Wait_loop1:							
	chips	cs_wait					
	pinfunc	PS_D7, tset1, adhiz						
	count	count1, decr, aon		
	mar		cjmpnz, Wait_loop1 			
					
%	chips	cs_wait						
	pinfunc PS_D7, tset1						
	mar		return


PATTERN(sub_wait_100us)              //count1,  850
	% Wait_loop1:
	chips	cs_wait
		pinfunc	PS_D7, tset1, adhiz
		count	count5, decr, aon
		mar		cjmpnz, Wait_loop1

	%	chips	cs_wait
	pinfunc PS_D7, tset1
	mar		return

	PATTERN(sub_wait_5600us)              //count1,  850
	% Wait_loop1:
	chips	cs_wait
	pinfunc	PS_D7, tset1, adhiz
	count	count6, decr, aon
	mar		cjmpnz, Wait_loop1

	%chips	cs_wait
	pinfunc PS_D7, tset1
	mar		return


PATTERN( sub_wait_time )              
%Wait_loop2:							
	chips	cs_wait					
	pinfunc	PS_D7, tset1, adhiz						
	count	count2, decr, aon		
	mar		cjmpnz, Wait_loop2 			
					
%	chips	cs_wait						
	pinfunc PS_D7, tset1						
	mar		return

PATTERN( sub_xaddr_inc )              
%Xaddr_inc:	
  xalu  xmain, xcare, con, increment, dxmain, oxmain
  yalu  ymain, xcare, coff, hold, dymain, oymain
  chips	cs_hold					
  pinfunc	PS_D31, tset1, adhiz						
  count	count3, decr, aon		 			
  mar cjmpnz,	Xaddr_inc
				
%	chips	cs_hold						
	pinfunc PS_D31, tset1						
	mar		return

	PATTERN( sub_wait_1sec )              
%Wait_loop2:							
	chips	cs_wait					
	pinfunc	PS_D7, tset1, adhiz						
	count	count11, decr, aon		
	mar		cjmpnz, Wait_loop2 			
					
%	chips	cs_wait						
	pinfunc PS_D7, tset1						
	mar		return

	PATTERN( sub_powr_on )			//count3, 30000-3
%power_loop:
	chips	cs_wr
	pinfunc PS_D0, tset1
	datgen  mainmain, invsns
	count	count3, decr, aon	
	mar		cjmpnz, power_loop
%	chips	cs_wr
	pinfunc PS_D0, tset1
	datgen  mainmain, invsns
	mar		return	