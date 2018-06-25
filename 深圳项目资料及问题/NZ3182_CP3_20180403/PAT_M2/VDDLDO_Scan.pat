SET_DEC_FILE "NZ3182_CP.dec" 
HEADER               
        VDD_PAD,CMS_PAD,XT1_PAD,GPIO4_PAD,GPIO5_PAD,GPIO6_PAD; 
                     
SPM_PATTERN ( VDDLDO_Scan) { 
                     
                     
//
//               VCXGGG
//               DMTPPP
//               DS1III
//               ___OOO
//               PPP456
//               AAA___
//               DDDPPP
//                  AAA
//                  DDD
//                
//                
//                
//               
                 
                 
                 
vddldo_scan_st::*10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X100*;   //LDOTrim0 
                *10X100*;   //LDOTrim1
                *10X100*;   //LDOTrim2
                *10X100*;   //LDOTrim3
                *10X100*;   //LDOTrim4
vddldo_shift::  *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X00

                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X101*;   //LDOTrim0 
                *10X100*;   //LDOTrim1
                *10X100*;   //LDOTrim2
                *10X100*;   //LDOTrim3
                *10X100*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X01
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X100*;   //LDOTrim0 
                *10X101*;   //LDOTrim1
                *10X100*;   //LDOTrim2
                *10X100*;   //LDOTrim3
                *10X100*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X02
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X101*;   //LDOTrim0 
                *10X101*;   //LDOTrim1
                *10X100*;   //LDOTrim2
                *10X100*;   //LDOTrim3
                *10X100*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X03
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X100*;   //LDOTrim0 
                *10X100*;   //LDOTrim1
                *10X101*;   //LDOTrim2
                *10X100*;   //LDOTrim3
                *10X100*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X04
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X101*;   //LDOTrim0 
                *10X100*;   //LDOTrim1
                *10X101*;   //LDOTrim2
                *10X100*;   //LDOTrim3
                *10X100*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X05
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X100*;   //LDOTrim0 
                *10X101*;   //LDOTrim1
                *10X101*;   //LDOTrim2
                *10X100*;   //LDOTrim3
                *10X100*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X06
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X101*;   //LDOTrim0 
                *10X101*;   //LDOTrim1
                *10X101*;   //LDOTrim2
                *10X100*;   //LDOTrim3
                *10X100*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X07
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X100*;   //LDOTrim0 
                *10X100*;   //LDOTrim1
                *10X100*;   //LDOTrim2
                *10X101*;   //LDOTrim3
                *10X100*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X08
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X101*;   //LDOTrim0 
                *10X100*;   //LDOTrim1
                *10X100*;   //LDOTrim2
                *10X101*;   //LDOTrim3
                *10X100*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X09
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X100*;   //LDOTrim0 
                *10X101*;   //LDOTrim1
                *10X100*;   //LDOTrim2
                *10X101*;   //LDOTrim3
                *10X100*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X0A
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X101*;   //LDOTrim0 
                *10X101*;   //LDOTrim1
                *10X100*;   //LDOTrim2
                *10X101*;   //LDOTrim3
                *10X100*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X0B
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X100*;   //LDOTrim0 
                *10X100*;   //LDOTrim1
                *10X101*;   //LDOTrim2
                *10X101*;   //LDOTrim3
                *10X100*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X0C
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X101*;   //LDOTrim0 
                *10X100*;   //LDOTrim1
                *10X101*;   //LDOTrim2
                *10X101*;   //LDOTrim3
                *10X100*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X0D
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X100*;   //LDOTrim0 
                *10X101*;   //LDOTrim1
                *10X101*;   //LDOTrim2
                *10X101*;   //LDOTrim3
                *10X100*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X0E
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X101*;   //LDOTrim0 
                *10X101*;   //LDOTrim1
                *10X101*;   //LDOTrim2
                *10X101*;   //LDOTrim3
                *10X100*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X0F
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X100*;   //LDOTrim0 
                *10X100*;   //LDOTrim1
                *10X100*;   //LDOTrim2
                *10X100*;   //LDOTrim3
                *10X101*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X10
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X101*;   //LDOTrim0 
                *10X100*;   //LDOTrim1
                *10X100*;   //LDOTrim2
                *10X100*;   //LDOTrim3
                *10X101*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X11                
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X100*;   //LDOTrim0 
                *10X101*;   //LDOTrim1
                *10X100*;   //LDOTrim2
                *10X100*;   //LDOTrim3
                *10X101*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X12
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X101*;   //LDOTrim0 
                *10X101*;   //LDOTrim1
                *10X100*;   //LDOTrim2
                *10X100*;   //LDOTrim3
                *10X101*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X13
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X100*;   //LDOTrim0 
                *10X100*;   //LDOTrim1
                *10X101*;   //LDOTrim2
                *10X100*;   //LDOTrim3
                *10X101*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X14
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X101*;   //LDOTrim0 
                *10X100*;   //LDOTrim1
                *10X101*;   //LDOTrim2
                *10X100*;   //LDOTrim3
                *10X101*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X15
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X100*;   //LDOTrim0 
                *10X101*;   //LDOTrim1
                *10X101*;   //LDOTrim2
                *10X100*;   //LDOTrim3
                *10X101*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X16
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X101*;   //LDOTrim0 
                *10X101*;   //LDOTrim1
                *10X101*;   //LDOTrim2
                *10X100*;   //LDOTrim3
                *10X101*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X17
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X100*;   //LDOTrim0 
                *10X100*;   //LDOTrim1
                *10X100*;   //LDOTrim2
                *10X101*;   //LDOTrim3
                *10X101*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X18
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X101*;   //LDOTrim0 
                *10X100*;   //LDOTrim1
                *10X100*;   //LDOTrim2
                *10X101*;   //LDOTrim3
                *10X101*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X19
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X100*;   //LDOTrim0 
                *10X101*;   //LDOTrim1
                *10X100*;   //LDOTrim2
                *10X101*;   //LDOTrim3
                *10X101*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X1A
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X101*;   //LDOTrim0 
                *10X101*;   //LDOTrim1
                *10X100*;   //LDOTrim2
                *10X101*;   //LDOTrim3
                *10X101*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X1B
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X100*;   //LDOTrim0 
                *10X100*;   //LDOTrim1
                *10X101*;   //LDOTrim2
                *10X101*;   //LDOTrim3
                *10X101*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X1C
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X101*;   //LDOTrim0 
                *10X100*;   //LDOTrim1
                *10X101*;   //LDOTrim2
                *10X101*;   //LDOTrim3
                *10X101*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X1D
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X100*;   //LDOTrim0 
                *10X101*;   //LDOTrim1
                *10X101*;   //LDOTrim2
                *10X101*;   //LDOTrim3
                *10X101*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X1E
                
                *10X000*TS1,RPT 1000;  
                *10X100*RPT 1000;
                *10X110*;   //STROBE
                *10X101*;
                *10X100*;
                *10X100*;
                *10X100*;
                *10X101*;   //LDOCtrl mode
                *10X101*;   //LDOTrim0 
                *10X101*;   //LDOTrim1
                *10X101*;   //LDOTrim2
                *10X101*;   //LDOTrim3
                *10X101*;   //LDOTrim4
                *10X101*;   //LDOOpt0
                *10X101*;   //LDOOpt1
                *10X100*;   //LDOOpt2
                *10X10X*RPT 10; 
                *10X10X*STOP;        //0X1F
                

}                                                  