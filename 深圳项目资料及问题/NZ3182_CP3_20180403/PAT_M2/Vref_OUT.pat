#include "../patterns.h"                                                
PATTERN( Vref_OUT, logic )                                          
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
                           
                 
                 
%RPT 1000       10X000,TS1	
%RPT 1000       10X100,TS1	
%VEC            10X110,TS1	//STROBE
%VEC            10X100,TS1	
%VEC            10X101,TS1	
%VEC            10X101,TS1	
%VEC            10X100,TS1	
%VEC            10X101,TS1	//TestSWSel mode
%VEC            10X100,TS1	//SW0 
%VEC            10X101,TS1	//SW1
%VEC            10X100,TS1	//SW2
%VEC            10X100,TS1	//SW3       
%VEC            10X100,TS1	//SW3  5¡¯b000010£ºVBUF_ADC
%VEC            10X101,TS1	//Sel0
%VEC            10X100,TS1	//Sel1
%VEC            10X100,TS1	//Sel2 
%RPT 10         10X10X,TS1	
%VEC            10X110,TS1	//STROBE
%VEC            10X101,TS1	
%VEC            10X101,TS1	
%VEC            10X100,TS1	
%VEC            10X100,TS1	
%VEC            10X101,TS1	//ADC Ctrl mode
%VEC            10X100,TS1	//ADCEn  
%VEC            10X100,TS1	//ADCStart
%VEC            10X100,TS1	//ADC Buff0
%VEC            10X100,TS1	//ADC Buff1
%VEC            10X101,TS1	//TbgEn
%RPT 10         10X10X,TS1	
%VEC            10X10X,TS1
VAR DONE	
                                                                                                                                    
                                                                 