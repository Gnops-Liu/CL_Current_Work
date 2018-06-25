#include "../patterns.h"                                                
PATTERN( ADC_Test_Out_Vts, logic )                                          
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
  
% VEC     10X000X,TS3		  
% RPT 10  10X100X,TS3		
% VEC     10X110X,TS3		//STROBE
% VEC     10X101X,TS3		
% VEC     10X101X,TS3		
% VEC     10X100X,TS3		
% VEC     10X100X,TS3		
% VEC     10X101X,TS3		//ADCCtrl mode
% VEC     10X100X,TS3		//ADCEn 
% VEC     10X100X,TS3		//ADCStart
% VEC     10X100X,TS3		//ADCBuff0
% VEC     10X100X,TS3		//ADCBuff1 
% VEC     10X100X,TS3		//TbgEn
% RPT 16  10X10XX,TS3		//
% VEC     10X10XX,TS3		//ADCDone 
% VEC     10X10XX,TS3		//ADCDat0
% VEC     10X10XX,TS3		//ADCDat1
% VEC     10X10XX,TS3		//ADCDat2
% VEC     10X10XX,TS3		//ADCDat3
% VEC     10X10XX,TS3		//ADCDat4
% VEC     10X10XX,TS3		//ADCDat5
% VEC     10X10XX,TS3		//ADCDat6
% VEC     10X10XX,TS3		//ADCDat7
% VEC     10X10XX,TS3		//ADCDat8
% VEC     10X10XX,TS3		//ADCDat9
% VEC     10X110X,TS3		//STROBE------------
% VEC     10X101X,TS3		
% VEC     10X101X,TS3		
% VEC     10X100X,TS3		
% VEC     10X100X,TS3		
% VEC     10X101X,TS3		//ADCCtrl mode
% VEC     10X101X,TS3		//ADCEn 
% VEC     10X101X,TS3		//ADCStart
% VEC     10X100X,TS3		//ADCBuff0
% VEC     10X100X,TS3		//ADCBuff1 
% VEC     10X101X,TS3		//TbgEn
% RPT 16  10X10XX,TS3		//
% VEC     10X10XX,TS3		//ADCDone 
% VEC     10X10XX,TS3		//ADCDat0
% VEC     10X10XX,TS3		//ADCDat1
% VEC     10X10XX,TS3		//ADCDat2
% VEC     10X10XX,TS3		//ADCDat3
% VEC     10X10XX,TS3		//ADCDat4
% VEC     10X10XX,TS3		//ADCDat5
% VEC     10X10XX,TS3		//ADCDat6
% VEC     10X10XX,TS3		//ADCDat7
% VEC     10X10XX,TS3		//ADCDat8
% VEC     10X10XX,TS3		//ADCDat9
% RPT 2   10X10XX,TS3		
% VEC     10X10XX,TS3		//ADCDone 
% VEC     10X10LX,TS3		//ADCDat0-----------91
% VEC     10X10LX,TS3		//ADCDat1
% VEC     10X10LX,TS3		//ADCDat2
% VEC     10X10LX,TS3		//ADCDat3
% VEC     10X10LX,TS3		//ADCDat4
% VEC     10X10LX,TS3		//ADCDat5
% VEC     10X10LX,TS3		//ADCDat6
% VEC     10X10LX,TS3		//ADCDat7
% VEC     10X10LX,TS3		//ADCDat8
% VEC     10X10LX,TS3		//ADCDat9 data0-----100
% RPT 2   10X10XX,TS3		
% VEC     10X10XX,TS3		//ADCDone 
% VEC     10X10LX,TS3		//ADCDat0-----------104
% VEC     10X10LX,TS3		//ADCDat1
% VEC     10X10LX,TS3		//ADCDat2
% VEC     10X10LX,TS3		//ADCDat3
% VEC     10X10LX,TS3		//ADCDat4
% VEC     10X10LX,TS3		//ADCDat5
% VEC     10X10LX,TS3		//ADCDat6
% VEC     10X10LX,TS3		//ADCDat7
% VEC     10X10LX,TS3		//ADCDat8
% VEC     10X10LX,TS3		//ADCDat9 data1------113
% RPT 2   10X10XX,TS3		
% VEC     10X10XX,TS3		//ADCDone 
% VEC     10X10LX,TS3		//ADCDat0------------117
% VEC     10X10LX,TS3		//ADCDat1
% VEC     10X10LX,TS3		//ADCDat2
% VEC     10X10LX,TS3		//ADCDat3
% VEC     10X10LX,TS3		//ADCDat4
% VEC     10X10LX,TS3		//ADCDat5
% VEC     10X10LX,TS3		//ADCDat6
% VEC     10X10LX,TS3		//ADCDat7
% VEC     10X10LX,TS3		//ADCDat8
% VEC     10X10LX,TS3		//ADCDat9 data2------126                
% RPT 2   10X10XX,TS3		
% VEC     10X10XX,TS3		//ADCDone 
% VEC     10X10LX,TS3		//ADCDat0------------130
% VEC     10X10LX,TS3		//ADCDat1
% VEC     10X10LX,TS3		//ADCDat2
% VEC     10X10LX,TS3		//ADCDat3
% VEC     10X10LX,TS3		//ADCDat4
% VEC     10X10LX,TS3		//ADCDat5
% VEC     10X10LX,TS3		//ADCDat6
% VEC     10X10LX,TS3		//ADCDat7
% VEC     10X10LX,TS3		//ADCDat8
% VEC     10X10LX,TS3		//ADCDat9 data3------139                
% RPT 2   10X10XX,TS3		
% VEC     10X10XX,TS3		//ADCDone 
% VEC     10X10LX,TS3		//ADCDat0------------143
% VEC     10X10LX,TS3		//ADCDat1
% VEC     10X10LX,TS3		//ADCDat2
% VEC     10X10LX,TS3		//ADCDat3
% VEC     10X10LX,TS3		//ADCDat4
% VEC     10X10LX,TS3		//ADCDat5
% VEC     10X10LX,TS3		//ADCDat6
% VEC     10X10LX,TS3		//ADCDat7
% VEC     10X10LX,TS3		//ADCDat8
% VEC     10X10LX,TS3		//ADCDat9 data4------152             
% RPT 2   10X10XX,TS3		
% VEC     10X10XX,TS3		//ADCDone 
% VEC     10X10LX,TS3		//ADCDat0------------156
% VEC     10X10LX,TS3		//ADCDat1
% VEC     10X10LX,TS3		//ADCDat2
% VEC     10X10LX,TS3		//ADCDat3
% VEC     10X10LX,TS3		//ADCDat4
% VEC     10X10LX,TS3		//ADCDat5
% VEC     10X10LX,TS3		//ADCDat6
% VEC     10X10LX,TS3		//ADCDat7
% VEC     10X10LX,TS3		//ADCDat8
% VEC     10X10LX,TS3		//ADCDat9 data5------165              
% RPT 2   10X10XX,TS3		
% VEC     10X10XX,TS3		//ADCDone 
% VEC     10X10LX,TS3		//ADCDat0------------169
% VEC     10X10LX,TS3		//ADCDat1
% VEC     10X10LX,TS3		//ADCDat2
% VEC     10X10LX,TS3		//ADCDat3
% VEC     10X10LX,TS3		//ADCDat4
% VEC     10X10LX,TS3		//ADCDat5
% VEC     10X10LX,TS3		//ADCDat6
% VEC     10X10LX,TS3		//ADCDat7
% VEC     10X10LX,TS3		//ADCDat8
% VEC     10X10LX,TS3		//ADCDat9 data6-------178                
% RPT 2   10X10XX,TS3		
% VEC     10X10XX,TS3		//ADCDone 
% VEC     10X10LX,TS3		//ADCDat0-------------182
% VEC     10X10LX,TS3		//ADCDat1
% VEC     10X10LX,TS3		//ADCDat2
% VEC     10X10LX,TS3		//ADCDat3
% VEC     10X10LX,TS3		//ADCDat4
% VEC     10X10LX,TS3		//ADCDat5
% VEC     10X10LX,TS3		//ADCDat6
% VEC     10X10LX,TS3		//ADCDat7
% VEC     10X10LX,TS3		//ADCDat8
% VEC     10X10LX,TS3		//ADCDat9 data7--------191                
% RPT 2   10X10XX,TS3		
% VEC     10X10XX,TS3		//ADCDone 
% VEC     10X10LX,TS3		//ADCDat0--------------195
% VEC     10X10LX,TS3		//ADCDat1
% VEC     10X10LX,TS3		//ADCDat2
% VEC     10X10LX,TS3		//ADCDat3
% VEC     10X10LX,TS3		//ADCDat4
% VEC     10X10LX,TS3		//ADCDat5
% VEC     10X10LX,TS3		//ADCDat6
% VEC     10X10LX,TS3		//ADCDat7
% VEC     10X10LX,TS3		//ADCDat8
% VEC     10X10LX,TS3		//ADCDat9 data8--------204
% RPT 2   10X10XX,TS3		
% VEC     10X10XX,TS3		//ADCDone 
% VEC     10X10LX,TS3		//ADCDat0--------------208
% VEC     10X10LX,TS3		//ADCDat1
% VEC     10X10LX,TS3		//ADCDat2
% VEC     10X10LX,TS3		//ADCDat3
% VEC     10X10LX,TS3		//ADCDat4
% VEC     10X10LX,TS3		//ADCDat5
% VEC     10X10LX,TS3		//ADCDat6
% VEC     10X10LX,TS3		//ADCDat7
% VEC     10X10LX,TS3		//ADCDat8
% VEC     10X10LX,TS3		//ADCDat9 data9--------217                
% VEC     10X10XX,TS3		//---------------------218
VAR DONE
                                              