#include "../patterns.h"                                                
PATTERN( EotStandby_Mode, logic )                                          
%%VECDEF VDD_PAD, CMS_PAD, XT1_PAD, GPIO4_PAD, GPIO5_PAD, GPIO6_PAD     
                                                                        
//		   VCXGGG                                                  
//		   DMTPPP                                                  
//		   DS1III                                                  
//		   ___OOO                                                  
//		   PPP456                                                  
//		   AAA___                                                  
//		   DDDPPP                                                  
//		      AAA                                                  
//		      DDD                                     
                 
%RPT 1000          101000,TS2	  
%RPT 1000          101100,TS2	
%VEC               101110,TS2	 //STROBE
%VEC               101101,TS2	
%VEC               101100,TS2	
%VEC               101101,TS2	
%VEC               101100,TS2	
%VEC               101101,TS2	 //OtpMode
%VEC               101100,TS2	 //EotStorage
%VEC               101101,TS2	 //EotStandby
%VEC               101100,TS2	 //EotPowerChange 
STARTLOOP 1000
%VEC               10110X,TS2
%RPT 99999         10110X,TS2
%VEC               10110X,TS2
ENDLOOP
%VEC               10110X,TS2
VAR DONE
 