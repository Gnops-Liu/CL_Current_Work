#include "../patterns.h"                                                
PATTERN( Halver_on, logic )                                          
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
                 

%RPT 1000     101X100,TS2	
%VEC          101X110,TS2	//strobe
%VEC          101X101,TS2	
%VEC          101X100,TS2	
%VEC          101X101,TS2	
%VEC          101X101,TS2	
%VEC          101X100,TS2	//CrystalOSC Ctrl mode
%VEC          101X100,TS2	//CrysEn  0:enable
%VEC          101X101,TS2	//HalEn   1:enable
%VEC          101X100,TS2	//PowCtrl0
%VEC          101X100,TS2	//PowCtrl1
%VEC          101X101,TS2	//PowCtrl2
%VEC          101X100,TS2	//Crys PowOff
%RPT 1638     101X10X,TS2	//wait 50ms      
%VEC          101XXXX,TS2	
VAR DONE
                                                                                                                                       
                                                 