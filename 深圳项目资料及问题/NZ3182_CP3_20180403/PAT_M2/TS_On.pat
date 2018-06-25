#include "../patterns.h"                                                
PATTERN( TS_On, logic )                                          
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
% VEC       10X101,TS1		
% VEC       10X101,TS1		
% VEC       10X101,TS1		
% VEC       10X101,TS1		
% VEC       10X100,TS1		   //TS Ctrl mode
% VEC       10X101,TS1		   //TsEn 
% RPT 100   10X10X,TS1		 
% VEC       10X10X,TS1		
VAR DONE
                                               