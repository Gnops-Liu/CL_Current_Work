#include "../patterns.h"                                                
PATTERN( IP_Trim_Read, logic ) 
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



% RPT 1000        10X000,TS1		
% RPT 1000        10X100,TS1		
% VEC             10X110,TS1		  //STROBE
% VEC             10X101,TS1		
% VEC             10X101,TS1		
% VEC             10X101,TS1		
% VEC             10X100,TS1		
% VEC             10X100,TS1		  //EncDecEn mode
% VEC             10X100,TS1		  //DownLoadKey 
% VEC             10X101,TS1		  //EncDecEn
% RPT 10          10X10X,TS1		                    
% VEC             10X110,TS1		  //STROBE
% VEC             10X101,TS1		
% VEC             10X101,TS1		
% VEC             10X100,TS1		
% VEC             10X100,TS1		
% VEC             10X100,TS1		  //Read MODE Sel
% VEC             10X100,TS1		  //Mode0
% VEC             10X100,TS1		  //MOde1 00 User Read
% RPT 10          10X10X,TS1		  
% VEC             10X110,TS1		  //STROBE
% VEC             10X100,TS1		
% VEC             10X101,TS1		
% VEC             10X100,TS1		
% VEC             10X100,TS1		
% VEC             10X100,TS1		  //Addr mode
% VEC             10X101,TS1		  //Addr0 
% VEC             10X101,TS1		  //Addr1
% VEC             10X101,TS1		  //Addr2
% VEC             10X100,TS1		  //Addr3
% VEC             10X101,TS1		  //Addr4
% VEC             10X101,TS1		  //Addr5
% VEC             10X101,TS1		  //Addr6
% VEC             10X101,TS1		  //Addr7
% VEC             10X101,TS1		  //Addr8
% VEC             10X101,TS1		  //Addr9
% VEC             10X101,TS1		  //Addr10
% VEC             10X101,TS1		  //Addr11
% VEC             10X101,TS1		  //Addr12
% VEC             10X101,TS1		  //Addr13
% VEC             10X100,TS1		  //Addr14
% VEC             10X101,TS1		  //Addr15 0xBFF7
% RPT 10          10X10X,TS1		            
% VEC             10X110,TS1		  //STROBE
% VEC             10X100,TS1		
% VEC             10X100,TS1		
% VEC             10X101,TS1		
% VEC             10X100,TS1		
% VEC             10X100,TS1		  //Read mode 
% RPT 9           10X10X,TS1		  //WITE 8CYCLE    
% VEC             10X10X,TS1		  //Dout0   vref trim0-----vref_trim_rd::
% VEC             10X10X,TS1		  //Dout1   vref trim1
% VEC             10X10X,TS1		  //Dout2   vref trim2
% VEC             10X10X,TS1		  //Dout3   vref trim3
% VEC             10X10X,TS1		  //Dout4   Temp0     
% VEC             10X10X,TS1		  //Dout5   Temp1     
% VEC             10X10X,TS1		  //Dout6   Temp2     
% VEC             10X10X,TS1		  //Dout7   Temp3     
% RPT 10          10X10X,TS1		   
% VEC             10X110,TS1		  //STROBE
% VEC             10X100,TS1		
% VEC             10X100,TS1		
% VEC             10X101,TS1		
% VEC             10X100,TS1		
% VEC             10X100,TS1		  //Read mode 
% RPT 9           10X10X,TS1		    
% VEC			  10X10L,TS1,EBM_ENABLE				  //Dout0   LDOTrim0-----vddldo_trim_rd::
% VEC             10X10L,TS1,EBM_ENABLE,EBM_INC		  //Dout1   LDOTrim1
% VEC             10X10H,TS1,EBM_ENABLE,EBM_INC		  //Dout2   LDOTrim2
% VEC             10X10L,TS1,EBM_ENABLE,EBM_INC		  //Dout3   LDOTrim3
% VEC             10X10H,TS1,EBM_ENABLE,EBM_INC		  //Dout4   LDOTrim4
% VEC             10X10H,TS1		  //Dout5   
% VEC             10X10H,TS1		  //Dout6   
% VEC             10X10H,TS1		  //Dout7   
% RPT 10          10X10X,TS1		 
% VEC             10X110,TS1		  //STROBE
% VEC             10X100,TS1		
% VEC             10X100,TS1		
% VEC             10X101,TS1		
% VEC             10X100,TS1		
% VEC             10X100,TS1		  //Read mode 
% RPT 9           10X10X,TS1		    
% VEC			  10X10L,TS1,EBM_ENABLE,EBM_INC		  //Dout0   OSCTrim0---osc2M_trim_rd::
% VEC             10X10L,TS1,EBM_ENABLE,EBM_INC		  //Dout1   OSCTrim1
% VEC             10X10L,TS1,EBM_ENABLE,EBM_INC		  //Dout2   OSCTrim2
% VEC             10X10H,TS1,EBM_ENABLE,EBM_INC		  //Dout3   OSCTrim3
% VEC             10X10H,TS1		  //Dout4   
% VEC             10X10H,TS1		  //Dout5   
% VEC             10X10H,TS1		  //Dout6   
% VEC             10X10H,TS1		  //Dout7   
% RPT 10          10X10X,TS1		
% VEC             10X110,TS1		  //STROBE
% VEC             10X100,TS1		
% VEC             10X100,TS1		
% VEC             10X101,TS1		
% VEC             10X100,TS1		
% VEC             10X100,TS1		  //Read mode 
% RPT 9           10X10X,TS1		    
% VEC 			  10X10H,TS1,EBM_ENABLE,EBM_INC		  //Dout0   TrimCRC0---trimcrc_rd::
% VEC             10X10H,TS1,EBM_ENABLE,EBM_INC		  //Dout1   TrimCRC1
% VEC             10X10H,TS1,EBM_ENABLE,EBM_INC		  //Dout2   TrimCRC2
% VEC             10X10H,TS1,EBM_ENABLE,EBM_INC		  //Dout3   TrimCRC3
% VEC             10X10H,TS1,EBM_ENABLE,EBM_INC		  //Dout4   TrimCRC4
% VEC             10X10H,TS1,EBM_ENABLE,EBM_INC		  //Dout5   TrimCRC5
% VEC             10X10H,TS1,EBM_ENABLE,EBM_INC		  //Dout6   TrimCRC6
% VEC             10X10H,TS1,EBM_ENABLE,EBM_INC		  //Dout7   TrimCRC7
% RPT 10          10X10X,TS1		
% VEC             10X110,TS1		  //STROBE-----vts adc out
% VEC             10X100,TS1		
% VEC             10X101,TS1		
% VEC             10X100,TS1		
% VEC             10X100,TS1		
% VEC             10X100,TS1		  //Addr mode
% VEC             10X100,TS1		  //Addr0 
% VEC             10X100,TS1		  //Addr1
% VEC             10X101,TS1		  //Addr2
% VEC             10X101,TS1		  //Addr3
% VEC             10X101,TS1		  //Addr4
% VEC             10X101,TS1		  //Addr5
% VEC             10X101,TS1		  //Addr6
% VEC             10X101,TS1		  //Addr7
% VEC             10X101,TS1		  //Addr8
% VEC             10X101,TS1		  //Addr9
% VEC             10X101,TS1		  //Addr10
% VEC             10X101,TS1		  //Addr11
% VEC             10X101,TS1		  //Addr12
% VEC             10X101,TS1		  //Addr13
% VEC             10X100,TS1		  //Addr14
% VEC             10X101,TS1		  //Addr15 0xBFFC
% RPT 10          10X10X,TS1		
% VEC             10X110,TS1		  //STROBE
% VEC             10X100,TS1		
% VEC             10X100,TS1		
% VEC             10X101,TS1		
% VEC             10X100,TS1		
% VEC             10X100,TS1		  //Read mode 
% RPT 9           10X10X,TS1		    
% VEC    		  10X10H,TS1,EBM_ENABLE,EBM_INC		  //Dout0 --- vts_rd1:: 
% VEC             10X10H,TS1,EBM_ENABLE,EBM_INC		  //Dout1  
% VEC             10X10H,TS1,EBM_ENABLE,EBM_INC		  //Dout2  
% VEC             10X10H,TS1,EBM_ENABLE,EBM_INC		  //Dout3  
% VEC             10X10H,TS1,EBM_ENABLE,EBM_INC		  //Dout4  
% VEC             10X10H,TS1,EBM_ENABLE,EBM_INC		  //Dout5   
% VEC             10X10H,TS1,EBM_ENABLE,EBM_INC		  //Dout6   
% VEC             10X10H,TS1,EBM_ENABLE,EBM_INC		  //Dout7   
% RPT 10          10X10X,TS1		
% VEC             10X110,TS1		  //STROBE
% VEC             10X100,TS1		
% VEC             10X100,TS1		
% VEC             10X101,TS1		
% VEC             10X100,TS1		
% VEC             10X100,TS1		  //Read mode 
% RPT 9           10X10X,TS1		    
% VEC    		  10X10H,TS1,EBM_ENABLE,EBM_INC		  //Dout0 --- vts_rd2:: 
% VEC             10X10H,TS1,EBM_ENABLE,EBM_INC		  //Dout1  
% VEC             10X10H,TS1		  //Dout2  
% VEC             10X10H,TS1		  //Dout3  
% VEC             10X10H,TS1		  //Dout4  
% VEC             10X10H,TS1		  //Dout5   
% VEC             10X10H,TS1		  //Dout6   
% VEC             10X10H,TS1		  //Dout7   
% RPT 10          10X10X,TS1		
% VEC             10X110,TS1		  //STROBE----rtc read
% VEC             10X100,TS1		
% VEC             10X100,TS1		
% VEC             10X101,TS1		
% VEC             10X100,TS1		
% VEC             10X100,TS1		  //Read mode 
% RPT 9           10X10X,TS1		    
% VEC			  10X10L,TS1		  //Dout0   RTCTrim0---rtc_trim_rd::
% VEC             10X10H,TS1		  //Dout1   RTCTrim1
% VEC             10X10L,TS1		  //Dout2   RTCTrim2
% VEC             10X10H,TS1		  //Dout3   
% VEC             10X10H,TS1		  //Dout4   
% VEC             10X10H,TS1		  //Dout5   
% VEC             10X10H,TS1		  //Dout6   
% VEC             10X10H,TS1		  //Dout7   
% RPT 10          10X10X,TS1		
% VEC             10X110,TS1		  //STROBE
% VEC             10X100,TS1		
% VEC             10X101,TS1		
% VEC             10X100,TS1		
% VEC             10X100,TS1		
% VEC             10X100,TS1		  //Addr mode
% VEC             10X101,TS1		  //Addr0 
% VEC             10X100,TS1		  //Addr1
% VEC             10X100,TS1		  //Addr2
% VEC             10X100,TS1		  //Addr3
% VEC             10X101,TS1		  //Addr4
% VEC             10X101,TS1		  //Addr5
% VEC             10X101,TS1		  //Addr6
% VEC             10X101,TS1		  //Addr7
% VEC             10X101,TS1		  //Addr8
% VEC             10X101,TS1		  //Addr9
% VEC             10X101,TS1		  //Addr10
% VEC             10X101,TS1		  //Addr11
% VEC             10X101,TS1		  //Addr12
% VEC             10X101,TS1		  //Addr13
% VEC             10X100,TS1		  //Addr14
% VEC             10X101,TS1		  //Addr15 0xBFF1
% RPT 10          10X10X,TS1		                    
% VEC             10X110,TS1		  //STROBE
% VEC             10X100,TS1		
% VEC             10X100,TS1		
% VEC             10X101,TS1		
% VEC             10X100,TS1		
% VEC             10X100,TS1		  //Read mode 
% RPT 9           10X10X,TS1		    
% VEC             10X10H,TS1		  //Dout0   
% VEC             10X10L,TS1		  //Dout1   
% VEC             10X10L,TS1		  //Dout2   
% VEC             10X10L,TS1		  //Dout3   
% VEC             10X10L,TS1		  //Dout4   
% VEC             10X10L,TS1		  //Dout5   
% VEC             10X10L,TS1		  //Dout6   
% VEC             10X10L,TS1		  //Dout7   0x01
% RPT 10          10X10X,TS1		
% VEC             10X110,TS1		  //STROBE----Bias Trim Read
% VEC             10X100,TS1		
% VEC             10X101,TS1		
% VEC             10X100,TS1		
% VEC             10X100,TS1		
% VEC             10X100,TS1		  //Addr mode
% VEC             10X100,TS1		  //Addr0 
% VEC             10X101,TS1		  //Addr1
% VEC             10X101,TS1		  //Addr2
% VEC             10X101,TS1		  //Addr3
% VEC             10X101,TS1		  //Addr4
% VEC             10X100,TS1		  //Addr5
% VEC             10X101,TS1		  //Addr6
% VEC             10X101,TS1		  //Addr7
% VEC             10X101,TS1		  //Addr8
% VEC             10X101,TS1		  //Addr9
% VEC             10X101,TS1		  //Addr10
% VEC             10X101,TS1		  //Addr11
% VEC             10X101,TS1		  //Addr12
% VEC             10X101,TS1		  //Addr13
% VEC             10X100,TS1		  //Addr14
% VEC             10X101,TS1		  //Addr15 0xBFDE
% RPT 10          10X10X,TS1		                          
% VEC             10X110,TS1		  //STROBE
% VEC             10X100,TS1		
% VEC             10X100,TS1		
% VEC             10X101,TS1		
% VEC             10X100,TS1		
% VEC             10X100,TS1		  //Read mode 
% RPT 9           10X10X,TS1		    
% VEC             10X10H,TS1		  //Dout0   
% VEC             10X10L,TS1		  //Dout1   
% VEC             10X10L,TS1		  //Dout2   
% VEC             10X10H,TS1		  //Dout3   
% VEC             10X10H,TS1		  //Dout4   
% VEC             10X10H,TS1		  //Dout5   
% VEC             10X10H,TS1		  //Dout6   
% VEC             10X10H,TS1		  //Dout7   0xF9
% RPT 10          10X10X,TS1		
% VEC             10X110,TS1		  //STROBE  ---VDDLDO 1p8 trim read
% VEC             10X100,TS1		
% VEC             10X100,TS1		
% VEC             10X101,TS1		
% VEC             10X100,TS1		
% VEC             10X100,TS1		  //Read mode 
% RPT 9           10X10X,TS1		    
% VEC			  10X10H,TS1,EBM_ENABLE,EBM_INC		  //Dout0---vddldo_1p8_trim_rd::   
% VEC             10X10H,TS1,EBM_ENABLE,EBM_INC		  //Dout1   
% VEC             10X10L,TS1,EBM_ENABLE,EBM_INC		  //Dout2   
% VEC             10X10L,TS1,EBM_ENABLE,EBM_INC		  //Dout3   
% VEC             10X10L,TS1,EBM_ENABLE,EBM_INC		  //Dout4   
% VEC             10X10H,TS1		  //Dout5   
% VEC             10X10H,TS1		  //Dout6   
% VEC             10X10H,TS1		  //Dout7   0xE3
% RPT 10          10X10X,TS1		
% VEC             10X10X,TS1		
VAR DONE                                            