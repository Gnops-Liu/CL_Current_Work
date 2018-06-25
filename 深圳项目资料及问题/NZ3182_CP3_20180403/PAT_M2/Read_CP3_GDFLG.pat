#include "../patterns.h"                                                
PATTERN( Read_CP3_GDFLG, logic )                                          
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


% RPT 1000      10X000,TS1		 
% RPT 1000      10X100,TS1		
% VEC           10X110,TS1		  //STROBE
% VEC           10X101,TS1		
% VEC           10X101,TS1		
% VEC           10X101,TS1		
% VEC           10X100,TS1		
% VEC           10X100,TS1		  //EncDecEn mode
% VEC           10X100,TS1		  //DownLoadKey 
% VEC           10X101,TS1		  //EncDecEn
% RPT 10        10X10X,TS1		                   
% VEC           10X110,TS1		  //STROBE
% VEC           10X101,TS1		
% VEC           10X101,TS1		
% VEC           10X100,TS1		
% VEC           10X100,TS1		
% VEC           10X100,TS1		  //Read MODE Sel
% VEC           10X100,TS1		  //Mode0
% VEC           10X100,TS1		  //MOde1 00 User Read
% RPT 10        10X10X,TS1		  
% VEC           10X110,TS1		  //STROBE
% VEC           10X100,TS1		
% VEC           10X101,TS1		
% VEC           10X100,TS1		
% VEC           10X100,TS1		
% VEC           10X100,TS1		  //Addr mode
% VEC           10X101,TS1		  //Addr0 
% VEC           10X101,TS1		  //Addr1
% VEC           10X101,TS1		  //Addr2
% VEC           10X101,TS1		  //Addr3
% VEC           10X101,TS1		  //Addr4
% VEC           10X101,TS1		  //Addr5
% VEC           10X101,TS1		  //Addr6
% VEC           10X101,TS1		  //Addr7
% VEC           10X101,TS1		  //Addr8
% VEC           10X101,TS1		  //Addr9
% VEC           10X101,TS1		  //Addr10
% VEC           10X101,TS1		  //Addr11
% VEC           10X101,TS1		  //Addr12
% VEC           10X101,TS1		  //Addr13
% VEC           10X100,TS1		  //Addr14
% VEC           10X101,TS1		  //Addr15 0xBFFF
% RPT 10        10X10X,TS1		            
% VEC           10X110,TS1		  //STROBE
% VEC           10X100,TS1		
% VEC           10X100,TS1		
% VEC           10X101,TS1		
% VEC           10X100,TS1		
% VEC           10X100,TS1		  //Read mode 
% RPT 9         10X10X,TS1		  //WITE 8CYCLE    
% VEC           10X10H,TS1		  //Dout0   
% VEC           10X10H,TS1		  //Dout1   
% VEC           10X10L,TS1		  //Dout2   
% VEC           10X10L,TS1		  //Dout3   
% VEC           10X10H,TS1		  //Dout4   
% VEC           10X10H,TS1		  //Dout5   
% VEC           10X10L,TS1		  //Dout6   
% VEC           10X10L,TS1		  //Dout7   0x5A
% RPT 10        10X10X,TS1		   
% VEC           10X10X,TS1		
VAR DONE
                                                                                                                           
          
                                          