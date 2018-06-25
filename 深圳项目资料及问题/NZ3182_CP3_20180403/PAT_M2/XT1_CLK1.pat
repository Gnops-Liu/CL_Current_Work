#include "../patterns.h"                                                
PATTERN( XT1_CLK1, logic )                                          
%%VECDEF  XT1_PAD                                                                          
    
                 
% RPT 100		 1,TS1
% VEC			 1,TS1

STARTLOOP 1000
% VEC			 1,TS1
% RPT 40000		 1,TS1
% VEC			 1,TS1
ENDLOOP

% VEC			 1,TS1 
VAR DONE
                                                                                                                                    
                   