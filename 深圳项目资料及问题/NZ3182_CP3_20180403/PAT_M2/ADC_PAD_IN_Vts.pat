#include "../patterns.h"                                                
PATTERN( ADC_PAD_IN_Vts, logic )                                          
%%VECDEF VDD_PAD, CMS_PAD, XT1_PAD, GPIO4_PAD, GPIO5_PAD, GPIO6_PAD     
                                                                        
//     		VCXGGG                                                  
//     		DMTPPP                                                  
//     		DS1III                                                  
//     		___OOO                                                  
//     		PPP456                                                  
//     		AAA___                                                  
//     		DDDPPP                                                  
//     		   AAA                                                  
//     		   DDD  
           
% RPT 1000  10X000,TS1		  
% RPT 1000  10X100,TS1		
% VEC       10X110,TS1		   //STROBE
% VEC       10X100,TS1		
% VEC       10X101,TS1		
% VEC       10X101,TS1		
% VEC       10X100,TS1		
% VEC       10X101,TS1		   //TestSWSel mode
% VEC       10X101,TS1		   //SW0 
% VEC       10X100,TS1		   //SW1
% VEC       10X100,TS1		   //SW2
% VEC       10X100,TS1		   //SW3  
% VEC       10X100,TS1		   //SW3  5¡¯b00001£eVTS
% VEC       10X100,TS1		   //Sel0
% VEC       10X101,TS1		   //Sel1
% VEC       10X100,TS1		   //Sel2  3`b 010 ADC PAD
% RPT 10    10X10X,TS1		 
% VEC       10X10X,TS1	
VAR DONE	
                                          