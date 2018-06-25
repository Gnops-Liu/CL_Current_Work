#include "../patterns.h"
PATTERN( ADC_Test_Out, logic )
%%VECDEF VDD_PAD, CMS_PAD, XT1_PAD, GPIO4_PAD, GPIO5_PAD, GPIO6_PAD, ADC_PAD
		
//     		VCXGGG
//     		DMTPPP
//     		DS1III
//     		___OOO
//     		PPP456
//     		AAA___
//     		DDDPPP
//     		   AAA
//     		   DDD  
             
                 
                 
% VEC                10X0001,TS3		  
% RPT 1000           10X1001,TS3		
% VEC                10X1101,TS3		//STROBE
% VEC                10X1011,TS3		         
% VEC                10X1011,TS3		         
% VEC                10X1001,TS3		         
% VEC                10X1001,TS3		         
% VEC                10X1011,TS3		//ADCCtrl mode       
% VEC                10X1001,TS3		//ADCEn             
% VEC                10X1001,TS3		//ADCStart           
% VEC                10X1001,TS3		//ADCBuff0           
% VEC                10X1001,TS3		//ADCBuff1           
% VEC                10X1001,TS3		//TbgEn            
% RPT 16             10X10X1,TS3		//            
% VEC                10X10X1,TS3		//ADCDone            
% VEC                10X10X1,TS3		//ADCDat0            
% VEC                10X10X1,TS3		//ADCDat1            
% VEC                10X10X1,TS3		//ADCDat2            
% VEC                10X10X1,TS3		//ADCDat3            
% VEC                10X10X1,TS3		//ADCDat4            
% VEC                10X10X1,TS3		//ADCDat5            
% VEC                10X10X1,TS3		//ADCDat6            
% VEC                10X10X1,TS3		//ADCDat7            
% VEC                10X10X1,TS3		//ADCDat8            
% VEC                10X10X1,TS3		//ADCDat9  
% VEC                10X1101,TS3		//STROBE****************
% VEC                10X1011,TS3		         
% VEC                10X1011,TS3		         
% VEC                10X1001,TS3		         
% VEC                10X1001,TS3		         
% VEC                10X1011,TS3		//ADCCtrl mode       
% VEC                10X1011,TS3		//ADCEn             
% VEC                10X1011,TS3		//ADCStart           
% VEC                10X1001,TS3		//ADCBuff0           
% VEC                10X1001,TS3		//ADCBuff1           
% VEC                10X1011,TS3		//TbgEn            
% RPT 16             10X10X1,TS3		//            
% VEC                10X10X1,TS3		//ADCDone   1067          
% VEC                10X10X1,TS3		//ADCDat0	1068	           
% VEC                10X10X1,TS3		//ADCDat1   1069         
% VEC                10X10X1,TS3		//ADCDat2   1070         
% VEC                10X10X1,TS3		//ADCDat3   1071         
% VEC                10X10X1,TS3		//ADCDat4   1072         
% VEC                10X10X1,TS3		//ADCDat5   1073         
% VEC                10X10X1,TS3		//ADCDat6   1074         
% VEC                10X10X1,TS3		//ADCDat7   1075         
% VEC                10X10X1,TS3		//ADCDat8   1076         
% VEC                10X10X1,TS3		//ADCDat9   1077         
% RPT 2              10X10X1,TS3		
% VEC                10X10X1,TS3		//ADCDone   1080         
% VEC                10X10L1,TS3		//ADCDat0   1081--         
% VEC                10X10L1,TS3		//ADCDat1   1082         
% VEC                10X10L1,TS3		//ADCDat2   1083         
% VEC                10X10L1,TS3		//ADCDat3   1084         
% VEC                10X10L1,TS3		//ADCDat4   1085         
% VEC                10X10L1,TS3		//ADCDat5   1086         
% VEC                10X10L1,TS3		//ADCDat6   1087         
% VEC                10X10L1,TS3		//ADCDat7   1088         
% VEC                10X10L1,TS3		//ADCDat8   1089         
% VEC                10X10L1,TS3		//ADCDat9 data0	1090
% RPT 2              10X10X1,TS3		
% VEC                10X10X1,TS3		//ADCDone	1093
% VEC                10X10L1,TS3		//ADCDat0	1094--
% VEC                10X10L1,TS3		//ADCDat1
% VEC                10X10L1,TS3		//ADCDat2
% VEC                10X10L1,TS3		//ADCDat3
% VEC                10X10L1,TS3		//ADCDat4
% VEC                10X10L1,TS3		//ADCDat5
% VEC                10X10L1,TS3		//ADCDat6
% VEC                10X10L1,TS3		//ADCDat7
% VEC                10X10L1,TS3		//ADCDat8
% VEC                10X10L1,TS3		//ADCDat9 data1	1103
% RPT 2              10X10X1,TS3		
% VEC                10X10X1,TS3		//ADCDone	1106
% VEC                10X10L1,TS3		//ADCDat0	1107--
% VEC                10X10L1,TS3		//ADCDat1
% VEC                10X10L1,TS3		//ADCDat2
% VEC                10X10L1,TS3		//ADCDat3
% VEC                10X10L1,TS3		//ADCDat4
% VEC                10X10L1,TS3		//ADCDat5
% VEC                10X10L1,TS3		//ADCDat6
% VEC                10X10L1,TS3		//ADCDat7
% VEC                10X10L1,TS3		//ADCDat8
% VEC                10X10L1,TS3		//ADCDat9 data2	1116
% RPT 2              10X10X1,TS3		
% VEC                10X10X1,TS3		//ADCDone	1119 
% VEC                10X10L1,TS3		//ADCDat0	1120--
% VEC                10X10L1,TS3		//ADCDat1
% VEC                10X10L1,TS3		//ADCDat2
% VEC                10X10L1,TS3		//ADCDat3
% VEC                10X10L1,TS3		//ADCDat4
% VEC                10X10L1,TS3		//ADCDat5
% VEC                10X10L1,TS3		//ADCDat6
% VEC                10X10L1,TS3		//ADCDat7
% VEC                10X10L1,TS3		//ADCDat8
% VEC                10X10L1,TS3		//ADCDat9 data3	1129
% RPT 2              10X10X1,TS3		
% VEC                10X10X1,TS3		//ADCDone	1132
% VEC                10X10L1,TS3		//ADCDat0	1133--
% VEC                10X10L1,TS3		//ADCDat1
% VEC                10X10L1,TS3		//ADCDat2
% VEC                10X10L1,TS3		//ADCDat3
% VEC                10X10L1,TS3		//ADCDat4
% VEC                10X10L1,TS3		//ADCDat5
% VEC                10X10L1,TS3		//ADCDat6
% VEC                10X10L1,TS3		//ADCDat7
% VEC                10X10L1,TS3		//ADCDat8
% VEC                10X10L1,TS3		//ADCDat9 data4		1142               
% RPT 2              10X10X1,TS3		
% VEC                10X10X1,TS3		
VAR DONE                                                 