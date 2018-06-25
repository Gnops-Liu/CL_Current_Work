#include "../patterns.h"                                                
PATTERN( IP_Trim_Write1, logic )  
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

% RPT 1000	 10X000,TS1		//ip_trim_write1_st::
% RPT 1000   10X100,TS1		
% VEC        10X110,TS1		//STROBE
% VEC        10X101,TS1		
% VEC        10X101,TS1		
% VEC        10X101,TS1		
% VEC        10X100,TS1		
% VEC        10X100,TS1		//EncDecEn mode
% VEC        10X100,TS1		//DownLoadKey 
% VEC        10X101,TS1		//EncDecEn
% RPT 10     10X10X,TS1		             
% VEC        10X110,TS1		//STROBE
% VEC        10X100,TS1		
% VEC        10X101,TS1		
% VEC        10X100,TS1		
% VEC        10X100,TS1		
% VEC        10X100,TS1		//Addr mode
% VEC        10X101,TS1		//Addr0 
% VEC        10X101,TS1		//Addr1
% VEC        10X101,TS1		//Addr2
% VEC        10X100,TS1		//Addr3
% VEC        10X101,TS1		//Addr4
% VEC        10X101,TS1		//Addr5
% VEC        10X101,TS1		//Addr6
% VEC        10X101,TS1		//Addr7
% VEC        10X101,TS1		//Addr8
% VEC        10X101,TS1		//Addr9
% VEC        10X101,TS1		//Addr10
% VEC        10X101,TS1		//Addr11
% VEC        10X101,TS1		//Addr12
% VEC        10X101,TS1		//Addr13
% VEC        10X100,TS1		//Addr14
% VEC        10X101,TS1		//Addr15 0xBFF7
% RPT 10     10X10X,TS1		
% VEC        10X110,TS1		//STROBE
% VEC        10X101,TS1		
% VEC        10X100,TS1		
% VEC        10X101,TS1		
% VEC        10X100,TS1		
% VEC        10X100,TS1		//Prog mode
% VEC 		 10X100,EBM_ENABLE		 		//Data0 vref trim0--vref_trim_wr::
% VEC        10X100,EBM_ENABLE,EBM_INC		//Data1 vref trim1
% VEC        10X100,EBM_ENABLE,EBM_INC		//Data2 vref trim2
% VEC        10X101,EBM_ENABLE,EBM_INC		//Data3 vref trim3
% VEC        10X100,TS1		//Data4 Temp0
% VEC        10X100,TS1		//Data5 Temp1               
% VEC        10X100,TS1		//Data6 Temp2
% VEC        10X101,TS1		//Data7 Temp3
% RPT 3		 10X10X,TS1		//发送完指令，4个clk后，vpp必须上电；ip_trim_write1_sp::
% VEC		 10X10X,TS1	
VAR DONE