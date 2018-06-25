#include "../patterns.h"
PATTERN( POWER_CHANGE, logic )
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
VAR DONE                                                