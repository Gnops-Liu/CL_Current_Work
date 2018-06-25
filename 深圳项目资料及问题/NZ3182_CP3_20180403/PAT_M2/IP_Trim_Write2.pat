#include "../patterns.h"                                                
PATTERN( IP_Trim_Write2, logic )
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

% RPT 10000    10X10X,TS1		 	//ip_trim_write2_st::                 
% VEC          10X110,TS1		  //STROBE
% VEC          10X101,TS1		
% VEC          10X100,TS1		
% VEC          10X101,TS1		
% VEC          10X100,TS1		
% VEC          10X100,TS1		  //Prog mode
% VEC          10X100,TS1,EBM_ENABLE		 		  //Data0 LDOTrim0---vddldo_trim_wr::
% VEC          10X100,TS1,EBM_ENABLE,EBM_INC		  //Data1 LDOTrim1
% VEC          10X101,TS1,EBM_ENABLE,EBM_INC		  //Data2 LDOTrim2
% VEC          10X100,TS1,EBM_ENABLE,EBM_INC		  //Data3 LDOTrim3
% VEC          10X101,TS1,EBM_ENABLE,EBM_INC		  //Data4 LDOTrim4
% VEC          10X101,TS1		  //Data5                
% VEC          10X101,TS1		  //Data6
% VEC          10X101,TS1		  //Data7   
% RPT 10000    10X10X,TS1		
% VEC          10X110,TS1		  //STROBE
% VEC          10X101,TS1		
% VEC          10X100,TS1		
% VEC          10X101,TS1		
% VEC          10X100,TS1		
% VEC          10X100,TS1		  //Prog mode
% VEC    	   10X100,TS1,EBM_ENABLE,EBM_INC		  //Data0 OSCTrim0---osc2M_trim_wr::
% VEC          10X100,TS1,EBM_ENABLE,EBM_INC		  //Data1 OSCTrim1
% VEC          10X100,TS1,EBM_ENABLE,EBM_INC		  //Data2 OSCTrim2
% VEC          10X101,TS1,EBM_ENABLE,EBM_INC		  //Data3 OSCTrim3
% VEC          10X101,TS1		  //Data4 
% VEC          10X101,TS1		  //Data5                
% VEC          10X101,TS1		  //Data6
% VEC          10X101,TS1		  //Data7   
% RPT 10000    10X10X,TS1		
% VEC          10X110,TS1		  //STROBE
% VEC          10X101,TS1		
% VEC          10X100,TS1		
% VEC          10X101,TS1		
% VEC          10X100,TS1		
% VEC          10X100,TS1		  //Prog mode
% VEC     	   10X101,TS1,EBM_ENABLE,EBM_INC		  //Data0 TrimCRC0---trimcrc_wr::
% VEC          10X101,TS1,EBM_ENABLE,EBM_INC		  //Data1 TrimCRC1
% VEC          10X101,TS1,EBM_ENABLE,EBM_INC		  //Data2 TrimCRC2
% VEC          10X101,TS1,EBM_ENABLE,EBM_INC		  //Data3 TrimCRC3
% VEC          10X101,TS1,EBM_ENABLE,EBM_INC		  //Data4 TrimCRC4
% VEC          10X101,TS1,EBM_ENABLE,EBM_INC		  //Data5 TrimCRC5               
% VEC          10X101,TS1,EBM_ENABLE,EBM_INC		  //Data6 TrimCRC6
% VEC          10X101,TS1,EBM_ENABLE,EBM_INC		  //Data7 TrimCRC7  
% RPT 10000    10X10X,TS1		     
% VEC          10X110,TS1		  //STROBE---vts adc out
% VEC          10X100,TS1		
% VEC          10X101,TS1		
% VEC          10X100,TS1		
% VEC          10X100,TS1		
% VEC          10X100,TS1		  //Addr mode
% VEC          10X100,TS1		  //Addr0 
% VEC          10X100,TS1		  //Addr1
% VEC          10X101,TS1		  //Addr2
% VEC          10X101,TS1		  //Addr3
% VEC          10X101,TS1		  //Addr4
% VEC          10X101,TS1		  //Addr5
% VEC          10X101,TS1		  //Addr6
% VEC          10X101,TS1		  //Addr7
% VEC          10X101,TS1		  //Addr8
% VEC          10X101,TS1		  //Addr9
% VEC          10X101,TS1		  //Addr10
% VEC          10X101,TS1		  //Addr11
% VEC          10X101,TS1		  //Addr12
% VEC          10X101,TS1		  //Addr13
% VEC          10X100,TS1		  //Addr14
% VEC          10X101,TS1		  //Addr15 0xBFFC
% RPT 10       10X10X,TS1		                  
% VEC          10X110,TS1		  //STROBE
% VEC          10X101,TS1		
% VEC          10X100,TS1		
% VEC          10X101,TS1		
% VEC          10X100,TS1		
% VEC          10X100,TS1		  //Prog mode
% VEC 		   10X101,TS1,EBM_ENABLE,EBM_INC		  //Data0 --- vts_wr1::
% VEC          10X101,TS1,EBM_ENABLE,EBM_INC		  //Data1 
% VEC          10X101,TS1,EBM_ENABLE,EBM_INC		  //Data2 
% VEC          10X101,TS1,EBM_ENABLE,EBM_INC		  //Data3 
% VEC          10X101,TS1,EBM_ENABLE,EBM_INC		  //Data4 
% VEC          10X101,TS1,EBM_ENABLE,EBM_INC		  //Data5              
% VEC          10X101,TS1,EBM_ENABLE,EBM_INC		  //Data6 
% VEC          10X101,TS1,EBM_ENABLE,EBM_INC		  //Data7 
% RPT 10000    10X10X,TS1		                  
% VEC          10X110,TS1		  //STROBE
% VEC          10X101,TS1		
% VEC          10X100,TS1		
% VEC          10X101,TS1		
% VEC          10X100,TS1		
% VEC          10X100,TS1		  //Prog mode
% VEC 		   10X101,TS1,EBM_ENABLE,EBM_INC		  //Data0 --- vts_wr2:: 
% VEC          10X101,TS1,EBM_ENABLE,EBM_INC		  //Data1 
% VEC          10X101,TS1		  //Data2 
% VEC          10X101,TS1		  //Data3 
% VEC          10X101,TS1		  //Data4 
% VEC          10X101,TS1		  //Data5              
% VEC          10X101,TS1		  //Data6 
% VEC          10X101,TS1		  //Data7 
% RPT 10000    10X10X,TS1		                  
% VEC          10X110,TS1		  //STROBE --- rtc trim
% VEC          10X101,TS1		
% VEC          10X100,TS1		
% VEC          10X101,TS1		
% VEC          10X100,TS1		
% VEC          10X100,TS1		  //Prog mode
% VEC		   10X100,TS1		  //Data0 RTCTrim0---rtc_trim_wr::
% VEC          10X101,TS1		  //Data1 RTCTrim1
% VEC          10X100,TS1		  //Data2 RTCTrim2
% VEC          10X101,TS1		  //Data3 
% VEC          10X101,TS1		  //Data4 
% VEC          10X101,TS1		  //Data5              
% VEC          10X101,TS1		  //Data6 
% VEC          10X101,TS1		  //Data7 
% RPT 10000    10X10X,TS1		
% VEC          10X110,TS1		  //STROBE
% VEC          10X100,TS1		
% VEC          10X101,TS1		
% VEC          10X100,TS1		
% VEC          10X100,TS1		
% VEC          10X100,TS1		  //Addr mode
% VEC          10X101,TS1		  //Addr0 
% VEC          10X100,TS1		  //Addr1
% VEC          10X100,TS1		  //Addr2
% VEC          10X100,TS1		  //Addr3
% VEC          10X101,TS1		  //Addr4
% VEC          10X101,TS1		  //Addr5
% VEC          10X101,TS1		  //Addr6
% VEC          10X101,TS1		  //Addr7
% VEC          10X101,TS1		  //Addr8
% VEC          10X101,TS1		  //Addr9
% VEC          10X101,TS1		  //Addr10
% VEC          10X101,TS1		  //Addr11
% VEC          10X101,TS1		  //Addr12
% VEC          10X101,TS1		  //Addr13
% VEC          10X100,TS1		  //Addr14
% VEC          10X101,TS1		  //Addr15 0xBFF1
% RPT 10       10X10X,TS1		                  
% VEC          10X110,TS1		  //STROBE
% VEC          10X101,TS1		
% VEC          10X100,TS1		
% VEC          10X101,TS1		
% VEC          10X100,TS1		
% VEC          10X100,TS1		  //Prog mode
% VEC          10X101,TS1		  //Data0 
% VEC          10X100,TS1		  //Data1 
% VEC          10X100,TS1		  //Data2 
% VEC          10X100,TS1		  //Data3 
% VEC          10X100,TS1		  //Data4 
% VEC          10X100,TS1		  //Data5              
% VEC          10X100,TS1		  //Data6 
% VEC          10X100,TS1		  //Data7  0x01
% RPT 10000    10X10X,TS1		         
% VEC          10X110,TS1		  //STROBE----Bias Trim
% VEC          10X100,TS1		
% VEC          10X101,TS1		
% VEC          10X100,TS1		
% VEC          10X100,TS1		
% VEC          10X100,TS1		  //Addr mode
% VEC          10X100,TS1		  //Addr0 
% VEC          10X101,TS1		  //Addr1
% VEC          10X101,TS1		  //Addr2
% VEC          10X101,TS1		  //Addr3
% VEC          10X101,TS1		  //Addr4
% VEC          10X100,TS1		  //Addr5
% VEC          10X101,TS1		  //Addr6
% VEC          10X101,TS1		  //Addr7
% VEC          10X101,TS1		  //Addr8
% VEC          10X101,TS1		  //Addr9
% VEC          10X101,TS1		  //Addr10
% VEC          10X101,TS1		  //Addr11
% VEC          10X101,TS1		  //Addr12
% VEC          10X101,TS1		  //Addr13
% VEC          10X100,TS1		  //Addr14
% VEC          10X101,TS1		  //Addr15 0xBFDE
% RPT 10       10X10X,TS1		                  
% VEC          10X110,TS1		  //STROBE
% VEC          10X101,TS1		
% VEC          10X100,TS1		
% VEC          10X101,TS1		
% VEC          10X100,TS1		
% VEC          10X100,TS1		  //Prog mode
% VEC          10X101,TS1		  //Data0 
% VEC          10X100,TS1		  //Data1 
% VEC          10X100,TS1		  //Data2 
% VEC          10X101,TS1		  //Data3 
% VEC          10X101,TS1		  //Data4 
% VEC          10X101,TS1		  //Data5              
% VEC          10X101,TS1		  //Data6 
% VEC          10X101,TS1		  //Data7  0xF9
% RPT 10000    10X10X,TS1		                    
% VEC          10X110,TS1		  //STROBE----LDO1P8 Trim
% VEC          10X100,TS1		
% VEC          10X101,TS1		
% VEC          10X100,TS1		
% VEC          10X100,TS1		
% VEC          10X100,TS1		  //Addr mode
% VEC          10X101,TS1		  //Addr0 
% VEC          10X101,TS1		  //Addr1
% VEC          10X101,TS1		  //Addr2
% VEC          10X101,TS1		  //Addr3
% VEC          10X101,TS1		  //Addr4
% VEC          10X100,TS1		  //Addr5
% VEC          10X101,TS1		  //Addr6
% VEC          10X101,TS1		  //Addr7
% VEC          10X101,TS1		  //Addr8
% VEC          10X101,TS1		  //Addr9
% VEC          10X101,TS1		  //Addr10
% VEC          10X101,TS1		  //Addr11
% VEC          10X101,TS1		  //Addr12
% VEC          10X101,TS1		  //Addr13
% VEC          10X100,TS1		  //Addr14
% VEC          10X101,TS1		  //Addr15 0xBFDF
% RPT 10       10X10X,TS1		                
% VEC          10X110,TS1		  //STROBE
% VEC          10X101,TS1		
% VEC          10X100,TS1		
% VEC          10X101,TS1		
% VEC          10X100,TS1		
% VEC          10X100,TS1		  //Prog mode
% VEC	 	   10X101,TS1,EBM_ENABLE,EBM_INC		  //Data0---vddldo_1p8_trim_wr:: 
% VEC          10X101,TS1,EBM_ENABLE,EBM_INC		  //Data1 
% VEC          10X100,TS1,EBM_ENABLE,EBM_INC		  //Data2 
% VEC          10X100,TS1,EBM_ENABLE,EBM_INC		  //Data3 
% VEC          10X100,TS1,EBM_ENABLE,EBM_INC		  //Data4 
% VEC          10X101,TS1		  //Data5              
% VEC          10X101,TS1		  //Data6 
% VEC          10X101,TS1		  //Data7  0xE3
% RPT 10000    10X10X,TS1		                   
% VEC	 				 10X10X,TS1		  //ip_trim_write2_sp::
                                                                                                                                    
VAR DONE