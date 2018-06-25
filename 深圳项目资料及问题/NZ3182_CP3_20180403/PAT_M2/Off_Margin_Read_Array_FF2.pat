#include "../patterns.h"
PATTERN( Off_Margin_Read_Array_FF2, logic )
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

%RPT 1000       101000,TS2
%RPT 1000       101100,TS2
%VEC            101110,TS2
%VEC            101101,TS2
%VEC            101100,TS2
%VEC            101101,TS2
%VEC            101100,TS2
%VEC            101101,TS2
%VEC            101100,TS2
%VEC            101100,TS2
%VEC            101101,TS2
%RPT 100        10110X,TS2
%VEC            10110X,TS2

%RPT 1000       10X000,TS1
%RPT 1000       10X100,TS1
%VEC            10X110,TS1
%VEC            10X101,TS1
%VEC            10X100,TS1
%VEC            10X100,TS1
%VEC            10X100,TS1
%VEC            10X100,TS1
%VEC            10X101,TS1
%RPT 100        10X10X,TS1
%VEC            10X10X,TS1       

%RPT 1000       10X000,TS1  
%RPT 1000       10X100,TS1 
%VEC            10X110,TS1    //STROBE
%VEC            10X100,TS1 
%VEC            10X101,TS1 
%VEC            10X101,TS1 
%VEC            10X100,TS1 
%VEC            10X100,TS1    //BistCmd
%VEC            10X101,TS1    //Bist Set0
%VEC            10X100,TS1    //Bist Set1
%VEC            10X100,TS1    //Bist Set2
%VEC            10X101,TS1    //Bist Set3  
%VEC            10X100,TS1    //Bist Set4 10010 	Bist Reset
%RPT 20         10X10X,TS1 
%VEC            10X110,TS1    //STROBE
%VEC            10X100,TS1 
%VEC            10X101,TS1 
%VEC            10X101,TS1 
%VEC            10X100,TS1 
%VEC            10X100,TS1    //BistCmd
%VEC            10X101,TS1    //Bist Set0
%VEC            10X100,TS1    //Bist Set1
%VEC            10X101,TS1    //Bist Set2
%VEC            10X100,TS1    //Bist Set3          
%VEC            10X100,TS1    //Bist Set4  10100 Off Margin Read ff       
%RPT 1500000    10X10X,TS1      //150ms
%VEC            10X110,TS1    //STROBE
%VEC            10X100,TS1 
%VEC            10X101,TS1 
%VEC            10X101,TS1 
%VEC            10X100,TS1 
%VEC            10X100,TS1    //BistCmd
%VEC            10X101,TS1    //Bist Set0
%VEC            10X100,TS1    //Bist Set1
%VEC            10X101,TS1    //Bist Set2
%VEC            10X100,TS1    //Bist Set3          
%VEC            10X100,TS1    //Bist Set4  10100 Off Margin Read ff  
%RPT 3          10X10X,TS1   
%VEC            10X10L,TS1  
%VEC            10L10H,TS1  
%VEC            10L10L,TS1  
%VEC            10L10H,TS1 
%VEC            10L10L,TS1  
%VEC            10L10L,TS1  
%VEC            10H10H,TS1 
%VEC            10H10L,TS1  
%VEC            10H10H,TS1 
%VEC            10H10L,TS1  
%VEC            10H10H,TS1 
%VEC            10H10L,TS1  
%VEC            10L10H,TS1 
%VEC            10L10L,TS1  
%VEC            10X10H,TS1 
%VEC            10X10L,TS1  
%VEC            10X10H,TS1 

%VEC            10X10H,TS1               
%RPT 3          10X10X,TS1 
%VEC            10X10X,TS1                                                                                                                                     
VAR DONE                                               