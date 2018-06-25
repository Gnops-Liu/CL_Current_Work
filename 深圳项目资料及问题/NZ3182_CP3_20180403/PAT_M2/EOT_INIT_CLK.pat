#include "../patterns.h"
PATTERN( EOT_INIT_CLK, logic )
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


%VEC		101XXX, TS2 , PS1   
%RPT 6000   101XXX, TS2	, PS1
%VEC        101XXX,	TS2	, PS1
%VEC		101XXX,	TS2	, PS1
VAR DONE                                       