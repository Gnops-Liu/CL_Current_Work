#include "macro.h"

PATTERN(BG_Trim )
	@{
		//xmain(xaddr);
		//ymain(yaddr);
		amain(0x00000);
		count(1, 501 - 3);			// wait time
		count(3, 90000-3);			// powr on
		count(60,50000000-1);           //measure time
		count(5, 1000 - 1);           //wait 100ns
		dmain(0x0);					   // always 0
	@}

	%	SubPowerOn	
%	pModeIn(tset1, 0x60)
%	chips cs_po                          
    pinfunc  PS_D31,tset1  
	 
%	 BitIn0(cs_wr, tset1)
%	 BitIn1(cs_wr, tset1)
%	 BitIn1(cs_wr, tset1)

%    BitIn1(cs_wr, tset1)
%	 BitIn0(cs_wr, tset1)
%	 BitIn0(cs_wr, tset1)
%	 BitIn0(cs_wr, tset1)
%	 BitIn0(cs_wr, tset1)
%	 BitIn0(cs_wr, tset1)

%	 BitIn1(cs_wr, tset1)
%	 BitIn0(cs_wr, tset1)
%	 BitIn0(cs_wr, tset1)
%	 BitIn1(cs_wr, tset1)
%	 BitIn0(cs_wr, tset1)
%	 BitIn1(cs_wr, tset1)
%	 BitIn1(cs_wr, tset1)
%	 BitIn1(cs_wr, tset1)


       
%	 BitIn0(cs_wr, tset1)
%	 BitIn0(cs_wr, tset1)
%	 BitIn1(cs_wr, tset1)

%	 BitIn1(cs_wr, tset1)
%	 BitIn0(cs_wr, tset1)
%	 BitIn0(cs_wr, tset1)
%	 BitIn0(cs_wr, tset1)
%	 BitIn0(cs_wr, tset1)
%	 BitIn0(cs_wr, tset1)

% BG_change:
	bg_trim(cs_wr, tset1, 0x000000)
%   Wait_100US


PATTERN(OSC_Trim_72)
@{
		//xmain(xaddr);
		//ymain(yaddr);
		amain(0x00000);
		count(1, 501 - 3);			// wait time
		count(3, 90000 - 3);			// powr on
		count(60, 50000000 - 1);           //measure time
		count(5, 1000 - 1);           //wait 100ns
		count(6, 56010 - 3);           //wait 100ns
		dmain(0x0);					   // always 0
		@}
	%	SubPowerOn
		% pModeIn(tset1, 0x60)
		% chips cs_po
		pinfunc  PS_D31, tset1

		% BitIn0(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)

		% BitIn1(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)

		% BitIn1(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)  //AUTO_OSC_HLMTL_END



		 % BitIn0(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)

		% BitIn0(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)

	    % BitIn1(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)  //AUTO_OSC_HLMTH_END


		% BitIn0(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)

		% BitIn1(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)

	    % BitIn1(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)  //AUTO_OSC_LLMTL_END

		% BitIn0(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)

		% BitIn0(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)

	    % BitIn0(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)  //AUTO_OSC_LLMTH_END

	    % BitIn1(cs_wr, tset1) //OSC_TRIM
		% BitIn0(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
        % Wait_5600US


		% BitIn0(cs_wr, tset1)  //read osc trim
		% BitIn1(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)

		% BitIn0(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)

	    % BitIn0(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn0(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)
		% BitIn1(cs_wr, tset1)  //AUTO_OSC_LLMTH_END
		% Wait_100US
		% ReadOut_OSC(tset1)

		
		PATTERN(VR16_trim )
	@{
		//xmain(xaddr);
		//ymain(yaddr);
		amain(0x00000);
		count(1, 501 - 3);			// wait time
		count(3, 90000-3);			// powr on
		count(60,50000000-1);           //measure time
		count(5, 1000 - 1);           //wait 100ns
		dmain(0x0);					   // always 0
	@}

	%	SubPowerOn	
%	pModeIn(tset1, 0x60)
%	chips cs_po                          
    pinfunc  PS_D31,tset1  
	 
%	 BitIn0(cs_wr, tset1)
%	 BitIn1(cs_wr, tset1)
%	 BitIn1(cs_wr, tset1)

%    BitIn1(cs_wr, tset1)
%	 BitIn0(cs_wr, tset1)
%	 BitIn0(cs_wr, tset1)
%	 BitIn0(cs_wr, tset1)
%	 BitIn0(cs_wr, tset1)
%	 BitIn0(cs_wr, tset1)

%	 BitIn0(cs_wr, tset1)
%	 BitIn0(cs_wr, tset1)
%	 BitIn1(cs_wr, tset1)
%	 BitIn1(cs_wr, tset1)
%	 BitIn0(cs_wr, tset1)
%	 BitIn1(cs_wr, tset1)
%	 BitIn1(cs_wr, tset1)
%	 BitIn1(cs_wr, tset1)


% Wait_5600US
% Wait_5600US
% Wait_5600US
% Wait_5600US
% Wait_5600US
% Wait_5600US


 PATTERN( PGVPP_tirm )
	@{ 
		xmain(0x00);		
		ymain(0x000);
		xbase(0x01);		
		ybase(0x0);
		xfield(0x02);		
		yfield(0x0);
		count(1, 501 - 3);	// wait time
		count(2, 30000-3);  // powr on
		 
	
		count(58,100060000);
		dmain(0x0);			// always 0
	@}
% SubPowerOn
% pModeIn(tset1, 0x60)

% CMD_IN(cs_wr, tset1, 0x59)
% AddressIn(cs_wr, tset1)
% DataIn32(cs_wr,tset1,0x00000000)
% PGVPP_change:
  trim_first(cs_wr,tset1,0x0)

% CMD_IN(cs_wr, tset1, 0x59)
% AddressIn01(cs_wr, tset1)
%DataIn(cs_wr,tset1,0x000000000)

% CMD_IN(cs_wr, tset1, 0x59)
% AddressIn02(cs_wr, tset1)
%DataIn(cs_wr,tset1,0x080000000)

% CMD_IN(cs_wr, tset1, 0xA5)
% AddressIn(cs_wr, tset1)
%DataIn(cs_wr,tset1,0x0800000000)

% Wait_5600US
% Wait_5600US
% Wait_5600US
% Wait_5600US
% Wait_5600US
% Wait_5600US
% CMD_IN(cs_wr, tset1, 0xb1)
% CMD_IN(cs_wr, tset1, 0xc1)
% pinfunc PS_D0,adhiz
   mar done


   PATTERN( PGVNN_tirm )
	@{ 
		xmain(0x00);		
		ymain(0x000);
		xbase(0x01);		
		ybase(0x0);
		xfield(0x02);		
		yfield(0x0);
		count(1, 501 - 3);	// wait time
		count(2, 30000-3);  // powr on
	
		count(58,100060000);
		dmain(0x0);			// always 0
	@}
%	SubPowerOn
% pModeIn(tset1, 0x60)

% CMD_IN(cs_wr, tset1, 0x59)
% AddressIn(cs_wr, tset1)
% DataIn16H(cs_wr,tset1,0x0000) 
% PGVNN_trim:
   trim_middle(cs_wr,tset1,0x0)
% DataIn16L(cs_wr,tset1,0x0000)

% CMD_IN(cs_wr, tset1, 0x59)
% AddressIn01(cs_wr, tset1)
%DataIn(cs_wr,tset1,0x000000000)

% CMD_IN(cs_wr, tset1, 0x59)
% AddressIn02(cs_wr, tset1)
%DataIn(cs_wr,tset1,0x040000000)

% CMD_IN(cs_wr, tset1, 0xa5)
% AddressIn(cs_wr, tset1)
%DataIn(cs_wr,tset1,0x000000000)
% Wait_5600US
% Wait_5600US
% Wait_5600US
% Wait_5600US
% Wait_5600US
% Wait_5600US
% CMD_IN(cs_wr, tset1, 0xb1)
% CMD_IN(cs_wr, tset1, 0xc1)

//%Meas_Loop:
//   datgen  mainmain,invsns
//chips cs_wr
//	pinfunc PS_D0,tset1
//	count count58,decr,aon
//	 mar cjmpnz,Meas_Loop
% pinfunc PS_D0,adhiz
   mar done



PATTERN( ERVPP_tirm )
	@{ 
		xmain(0x00);		
		ymain(0x000);
		xbase(0x01);		
		ybase(0x0);
		xfield(0x02);		
		yfield(0x0);
		count(1, 501 - 3);	// wait time
		count(2, 30000-3);  // powr on
		 
	
		count(58,100060000);
		dmain(0x0);			// always 0
	@}
% SubPowerOn
% pModeIn(tset1, 0x60)

% CMD_IN(cs_wr, tset1, 0x59)
% AddressIn(cs_wr, tset1)
% DataIn(cs_wr,tset1,0x000000000)

% CMD_IN(cs_wr, tset1, 0x59)
% AddressIn01(cs_wr, tset1)
% DataIn32(cs_wr,tset1,0x00000000)
% ERVPP_change:
  trim_first(cs_wr,tset1,0x0)

% CMD_IN(cs_wr, tset1, 0x59)
% AddressIn02(cs_wr, tset1)
%DataIn(cs_wr,tset1,0x080000000)

% CMD_IN(cs_wr, tset1, 0xA7)
% AddressIn(cs_wr, tset1)

% Wait_5600US
% Wait_5600US
% Wait_5600US
% Wait_5600US
% Wait_5600US
% Wait_5600US
% CMD_IN(cs_wr, tset1, 0xb1)
% CMD_IN(cs_wr, tset1, 0xc1)
% pinfunc PS_D0,adhiz
   mar done

   PATTERN( ERVNN_tirm )
	@{ 
		xmain(0x00);		
		ymain(0x000);
		xbase(0x01);		
		ybase(0x0);
		xfield(0x02);		
		yfield(0x0);
		count(1, 501 - 3);	// wait time
		count(2, 30000-3);  // powr on
	
		count(58,100060000);
		dmain(0x0);			// always 0
	@}
%	SubPowerOn
% pModeIn(tset1, 0x60)

% CMD_IN(cs_wr, tset1, 0x59)
% AddressIn(cs_wr, tset1)
%DataIn(cs_wr,tset1,0x000000000)

% CMD_IN(cs_wr, tset1, 0x59)
% AddressIn01(cs_wr, tset1)
% DataIn16H(cs_wr,tset1,0x0000) 
% ERVNN_trim:
   trim_middle(cs_wr,tset1,0x0)
% DataIn16L(cs_wr,tset1,0x0000)

% CMD_IN(cs_wr, tset1, 0x59)
% AddressIn02(cs_wr, tset1)
%DataIn(cs_wr,tset1,0x080000000)


% CMD_IN(cs_wr, tset1, 0xa5)
% AddressIn(cs_wr, tset1)

% Wait_5600US
% Wait_5600US
% Wait_5600US
% Wait_5600US
% Wait_5600US
% Wait_5600US
% CMD_IN(cs_wr, tset1, 0xb1)
% CMD_IN(cs_wr, tset1, 0xc1)

//%Meas_Loop:
//   datgen  mainmain,invsns
//chips cs_wr
//	pinfunc PS_D0,tset1
//	count count58,decr,aon
//	 mar cjmpnz,Meas_Loop
% pinfunc PS_D0,adhiz
   mar done


   PATTERN( IREF_tirm )
	@{ 
		xmain(0x00);		
		ymain(0x000);
		xbase(0x01);		
		ybase(0x0);
		xfield(0x02);		
		yfield(0x0);
		count(1, 501 - 3);	// wait time
		count(2, 30000-3);  // powr on
		 
	
		count(58,100060000);
		dmain(0x0);			// always 0
	@}
% SubPowerOn
% pModeIn(tset1, 0x60)

% CMD_IN(cs_wr, tset1, 0x59)
% AddressIn(cs_wr, tset1)
%DataIn(cs_wr,tset1,0x000000000)

% CMD_IN(cs_wr, tset1, 0x59)
% AddressIn01(cs_wr, tset1)
%DataIn(cs_wr,tset1,0x000000000)

% CMD_IN(cs_wr, tset1, 0x59)
% AddressIn01(cs_wr, tset1)
% DataIn32(cs_wr,tset1,0x08000000)
% IREF_change:
  trim_first(cs_wr,tset1,0x0)

% CMD_IN(cs_wr, tset1, 0xA5)
% AddressIn(cs_wr, tset1)
%DataIn(cs_wr,tset1,0x0000000000)

% Wait_5600US
% Wait_5600US
% Wait_5600US
% Wait_5600US
% Wait_5600US
% Wait_5600US
% CMD_IN(cs_wr, tset1, 0xb1)
% CMD_IN(cs_wr, tset1, 0xc1)
% pinfunc PS_D0,adhiz
   mar done