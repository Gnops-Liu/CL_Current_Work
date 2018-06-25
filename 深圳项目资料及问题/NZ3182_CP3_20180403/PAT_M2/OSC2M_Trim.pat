#include "../patterns.h"                                                
PATTERN( OSC2M_Trim, logic )  
@{//mg
	ebm_address_pointer_reset();
  
@}                                        
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
   
                 
% RPT 1000          10X000,TS1	 
% RPT 1000          10X100,TS1	
% VEC               10X110,TS1	//STROBE
% VEC               10X101,TS1	
% VEC               10X101,TS1	
% VEC               10X100,TS1	
% VEC               10X101,TS1	
% VEC               10X100,TS1	//OSC2M mode
% VEC               10X101,TS1	//OSCEN 

% VEC				10X100,TS1,EBM_ENABLE		  	//OSC TRIM0--osc2m_trim_st::
% VEC               10X100,TS1,EBM_ENABLE,EBM_INC 	//OSC TRIM1
% VEC               10X100,TS1,EBM_ENABLE,EBM_INC 	//OSC TRIM2
% VEC               10X101,TS1,EBM_ENABLE,EBM_INC 	//OSC TRIM3--osc2m_trim_sp::  

% RPT 10            10X10X,TS1	
% VEC               10X10X,TS1	
VAR DONE
                                                                                                                                    
                   
                                                  