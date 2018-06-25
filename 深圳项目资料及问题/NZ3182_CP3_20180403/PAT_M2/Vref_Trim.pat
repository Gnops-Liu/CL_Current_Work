#include "../patterns.h"                                                
PATTERN( Vref_Trim, logic )  
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
                 
                 
                 
%RPT 1000           10X000,TS1 
%RPT 1000           10X100,TS1
%VEC                10X110,TS1   //STROBE
%VEC                10X100,TS1
%VEC                10X101,TS1
%VEC                10X101,TS1
%VEC                10X101,TS1
%VEC                10X100,TS1   //BGCtrl mode
%VEC                10X101,TS1   //BGEn
%VEC                10X100,TS1   //Temp0 
%VEC                10X100,TS1   //Temp1
%VEC                10X100,TS1   //Temp2
%VEC                10X101,TS1   //Temp3 
          
%VEC                10X100,TS1,EBM_ENABLE		   //vref0 vref_trim_st: 
%VEC                10X100,TS1,EBM_ENABLE,EBM_INC  //vref1
%VEC                10X100,TS1,EBM_ENABLE,EBM_INC  //vref2
%VEC                10X101,TS1,EBM_ENABLE,EBM_INC  //vref3

%RPT 10             10X10X,TS1 
%VEC                10X10X,TS1
VAR DONE
                                                                                                                                    
                                                                   