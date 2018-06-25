#include <malloc.h>                                                                                                                                 
#include <stdio.h>                                                                                                                                  
#include <math.h>                                                                                                                                   
#include "tester.h"   


extern BOOL  VPPtrimValsDone;
extern BOOL  VPNtrimValsDone;

#ifdef SumDut_16                                                                                                                                    

void BG_write_trim_data()
{
	double subtract1 = 0;
	double subtract2 = 0;

	/////////////////////////////compare 
	#ifdef display_datalog
	CString s1 = vFormat("dut:	");
	CString s2 = vFormat("BGTrim_code:	");
	CString s3 = vFormat("BGTrim_value:	");
	#endif
	//active_duts_enable(0x3FFFFFFFFFF);
	SoftwareOnlyActiveDutIterator lec_loop2;
	while (lec_loop2.More())//loop,then save trim value                                                                                               
	{
		DutNum dut = active_dut_get();
		BGTrim_data[dut] = 0;
		for (int i = 0; i <= 63; i++)
		{
			BGTrim_compresult[dut][i] = abs(BGTrim_voltage[dut][i] - 1200000 - 2000);  //m8p
		/*	if (BGTrim_compresult[dut][i] >= 0);
			else
			{
				BGTrim_compresult[dut][i] = 0 - BGTrim_compresult[dut][i];
			}*/
			//?//BGTrim_compresult[dut][i + 64] = i;                                                                                                      
		}
		subtract2 = BGTrim_compresult[dut][0];
		for (int i = 1; i <= 63; i++)               // compare                                                                                          
		{
			subtract1 = subtract2 - BGTrim_compresult[dut][i];
			if (subtract1 >= 0)
			{
				subtract2 = BGTrim_compresult[dut][i];
			}
		}
		for (int i = 0; i <= 63; i++)
		{
			if (subtract2 - BGTrim_compresult[dut][i])
				BGTrim_data[dut]++;
			else
			{
				i = 64;
			}
		}
		//m8p output("BGTrim_data[%d]=%d     BGTrim_voltage[%d][%d]:%f", dut, BGTrim_data[dut], dut, BGTrim_data[dut], BGTrim_voltage[dut][BGTrim_data[dut]]);
		#ifdef display_datalog
		s1 += vFormat("	%d", dut + 1);
		s2 += vFormat("	%d", BGTrim_data[dut]);
		s3 += vFormat("	%6.4f", BGTrim_voltage[dut][BGTrim_data[dut]] * 0.001*0.001);
		#endif                                                                                                          
	}
	//BG_ebm_dma();
	//output(s1);
	#ifdef display_datalog
	output(s2);
	output(s3);
	#endif
}


void VPPVNN_write_data_EBM(void)
{
	/////////////////////compare                                                                                                                      
	double subtract1 = 0;
	double subtract2 = 0;
	//CString s1 = vFormat("dut_num	");
	#ifdef display_datalog
	CString s2 = vFormat("VPPTrim_code:	");
	CString s3 = vFormat("FlashVPPTrim_value:	");
	CString s4 = vFormat("VNNTrim_code:	");
	CString s5 = vFormat("FlashVNNTrim_value:	");
	#endif
	//active_duts_enable(0x3FFFFFFFFFF);
	SoftwareOnlyActiveDutIterator lec_loop2;
	while (lec_loop2.More())//loop,then save trim value                                                                                               
	{
		DutNum dut = active_dut_get();
		VPPTrim_data[dut] = 0;
		VNNTrim_data[dut] = 0;

		for (int i = 0; i <= 15; i++)
		{
			FlashVPPTrim_compresult[dut][i] = abs(PGVPPTrim_voltage[dut][i] - 10800000 - 30000);  //m8p
		/*	if (FlashVPPTrim_compresult[dut][i] >= 0);
			else
			{
				FlashVPPTrim_compresult[dut][i] = 0 - FlashVPPTrim_compresult[dut][i];
			}
			//BGTrim_compresult[i + 64] = i;  //*/                                                                                                            
		}

		subtract2 = FlashVPPTrim_compresult[dut][0];
		for (int i = 1; i <= 15; i++)               // compare                                                                                          
		{
			subtract1 = subtract2 - FlashVPPTrim_compresult[dut][i];
			if (subtract1 >= 0)
			{
				subtract2 = FlashVPPTrim_compresult[dut][i];
			}
		}
		for (int i = 0; i <= 15; i++)//*****************need to modify deeply************************************///////////////////////                
		{
			if (subtract2 - FlashVPPTrim_compresult[dut][i])
				VPPTrim_data[dut]++;
			else
			{
				i = 16;
			}
		}
		                                                                                               

		for (int i = 0; i <= 15; i++)
		{
			//FlashVNNTrim_compresult[dut][i] = abs(FlashVNNTrim_voltage[dut][i] + 3950000 + 15000);  //m8p
			FlashVNNTrim_compresult[dut][i] = abs(FlashVNNTrim_voltage[dut][i] + 3900000);		//0129 3.9V
			/*if (FlashVNNTrim_compresult[dut][i] >= 0);
			else
			{
				FlashVNNTrim_compresult[dut][i] = 0 - FlashVNNTrim_compresult[dut][i];
			}//*/
			//BGTrim_compresult[i + 64] = i;                                                                                                              
		}
		subtract2 = FlashVNNTrim_compresult[dut][0];
		for (int i = 1; i <= 15; i++)               // compare                                                                                          
		{
			subtract1 = subtract2 - FlashVNNTrim_compresult[dut][i];
			if (subtract1 >= 0)
			{
				subtract2 = FlashVNNTrim_compresult[dut][i];
			}
		}
		for (int i = 0; i <= 15; i++)
		{
			if (subtract2 - FlashVNNTrim_compresult[dut][i])
				VNNTrim_data[dut]++;
			else
			{
				i = 16;
			}
		}
		//m8p output("VNNNNNNNNNNN:%d          FlashVNNTrim_voltage:%f", VNNTrim_data[dut], FlashVNNTrim_voltage[dut][VNNTrim_data[dut]]);
//		s1 += vFormat("	%d", dut + 1);
		#ifdef display_datalog
		s2 += vFormat("	%d", VPPTrim_data[dut]);
		s3 += vFormat("	%6.4f", PGVPPTrim_voltage[dut][VPPTrim_data[dut]] * 0.001*0.001);
		s4 += vFormat("	%d", VNNTrim_data[dut]);
		s5 += vFormat("	%6.4f", FlashVNNTrim_voltage[dut][VNNTrim_data[dut]] * 0.001*0.001);
		#endif
		///////////////done////////////////////////////                                                                                                 
		/////////////////////////////ebm write/////////                                                                                                 

		/*//ebm_clear();						 //ebm config                                                                                                         
		//ebm_config_set(t_ebm_data_mode, pl_data);                                                                                                     
		ebm_address_reg_set(t_ebm_start_addr, 0x0);
		ebm_address_reg_set(t_ebm_addr_2, 0x04);
		//ebm_address_reg_set(t_ebm_addr_3, 0x0);                                                                                                       

		DWordArray inputcode0;
		//DWordArray inputcode4;                                                                                                                        

		if (VPPTrim_data[dut] % 8 % 4 % 2 / 1)
		{
			inputcode0.Add(0x01);
		}
		else
		{
			inputcode0.Add(0x00);
		}
		if (VPPTrim_data[dut] % 8 % 4 / 2)
		{
			inputcode0.Add(0x01);
		}
		else
		{
			inputcode0.Add(0x00);
		}
		if (VPPTrim_data[dut] % 8 / 4)
		{
			inputcode0.Add(0x01);
		}
		else
		{
			inputcode0.Add(0x00);
		}
		if (VPPTrim_data[dut] / 8)
		{
			inputcode0.Add(0x01);
		}
		else
		{
			inputcode0.Add(0x00);
		}
		if (VNNTrim_data[dut] % 8 % 4 % 2 / 1)
		{
			inputcode0.Add(0x01);
		}
		else
		{
			inputcode0.Add(0x00);
		}
		if (VNNTrim_data[dut] % 8 % 4 / 2)
		{
			inputcode0.Add(0x01);
		}
		else
		{
			inputcode0.Add(0x00);
		}
		if (VNNTrim_data[dut] % 8 / 4)
		{
			inputcode0.Add(0x01);
		}
		else
		{
			inputcode0.Add(0x00);
		}
		if (VNNTrim_data[dut] / 8)
		{
			inputcode0.Add(0x01);
		}
		else
		{
			inputcode0.Add(0x00);
		}
		ebm_write(dut, pl_data, 0x0, 8, inputcode0);//VPP,load_1                                                                                        
		//ebm_write(pl_data, 0x1, 1, inputcode1);                                                                                                       
		//ebm_write(pl_data, 0x2, 1, inputcode2);                                                                                                       
		//ebm_write(pl_data, 0x3, 1, inputcode3);   */                                                                                                    

		//ebm_write(dut,pl_data, 0x10, 4, inputcode4);//VNN,load_2                                                                                      
		//ebm_write(pl_data, 0x11, 1, inputcode5);                                                                                                      
		//ebm_write(pl_data, 0x12, 1, inputcode6);                                                                                                      
		//ebm_write(pl_data, 0x13, 1, inputcode7);                                                                                                      
	}
	//VPPVNN_ebm_dma();

	//funtest(PgmVPP_trim_AB, finish);                                                                                                                
	//functional_datalog(pl_data);
//	output(s1);
	#ifdef display_datalog
	output(s2);
	output(s3);
	output(s4);
	output(s5);
	#endif
	VPPtrimValsDone = true;
	VPNtrimValsDone = true;
}
void OSC_write_trim_data(int dut)
{

	int subtract1 = 0;
	int subtract2 = 0;

	int OSC_compare_result[42][89];
	/////////////////////////////compare                                                                                                              
	OSC_Trim_data[dut] = 0;//                                                                                                                         
	for (int i = 0; i < 89; i++)
	{
		OSC_compare_result[dut][i] = OSC_compare_data[dut][i] - 750;
		//output("OSC_compare_result:%d", OSC_compare_result[dut][i]);                                                                                  
		if (OSC_compare_result[dut][i] >= 0);
		else
		{
			OSC_compare_result[dut][i] = 0 - OSC_compare_result[dut][i];
		}
		//?//BGTrim_compresult[dut][i + 64] = i;                                                                                                        
	}
	subtract2 = OSC_compare_result[dut][0];
	for (int i = 1; i < 89; i++)               // compare                                                                                             
	{
		subtract1 = subtract2 - OSC_compare_result[dut][i];
		//output("subtract1:%d", subtract1);                                                                                                            
		if (subtract1 >= 0)
		{
			subtract2 = OSC_compare_result[dut][i];
		}
	}
	for (int i = 0; i < 89; i++)
	{
		if (subtract2 - OSC_compare_result[dut][i])
		{
			OSC_Trim_data[dut]++;
			//output("///////////");                                                                                                                      
			//output("%d", OSC_Trim_data[dut]);                                                                                                           
			//output("///////////");                                                                                                                      
		}

		else
		{
			i = 89;
		}
	}

}
                                                           
void OSCwrite_ebm_data(void)
{
					                                                                                                           
	ebm_config_set(t_ebm_data_mode, pl_SDA);
	ebm_address_reg_set(t_ebm_start_addr, 0x0);
                                                                                                     
	SoftwareOnlyActiveDutIterator lec_loop2;
	while (lec_loop2.More())//loop,then save trim value                                                                                               
	{
		DutNum dut_num = active_dut_get();
		DWordArray inputcode;
		if ((OSC_Trim_data[dut_num] + 8) % 64 % 32 % 16 % 8 % 4 % 2 / 1)
		{
			inputcode.Add(0x01);
		}
		else
		{
			inputcode.Add(0x00);
		}
		if ((OSC_Trim_data[dut_num] + 8) % 64 % 32 % 16 % 8 % 4 / 2)
		{
			inputcode.Add(0x01);
		}
		else
		{
			inputcode.Add(0x00);
		}
		if ((OSC_Trim_data[dut_num] + 8) % 64 % 32 % 16 % 8 / 4)
		{
			inputcode.Add(0x01);
		}
		else
		{
			inputcode.Add(0x00);
		}
		if ((OSC_Trim_data[dut_num] + 8) % 64 % 32 % 16 / 8)
		{
			inputcode.Add(0x01);
		}
		else
		{
			inputcode.Add(0x00);
		}
		if ((OSC_Trim_data[dut_num] + 8) % 64 % 32 / 16)
		{
			inputcode.Add(0x01);
		}
		else
		{
			inputcode.Add(0x00);
		}
		if ((OSC_Trim_data[dut_num] + 8) % 64 / 32)
		{
			inputcode.Add(0x01);
		}
		else
		{
			inputcode.Add(0x00);
		}
		if ((OSC_Trim_data[dut_num] + 8) / 64)
		{
			inputcode.Add(0x01);
		}
		else
		{
			inputcode.Add(0x00);
		}

		ebm_write(dut_num, pl_SDA, 0x0, 7, inputcode);
		//ebm_write(pl_data, 0x1, 1, inputcode1);                                                                                                       
		//ebm_write(pl_data, 0x2, 1, inputcode2);                                                                                                       
		//ebm_write(pl_data, 0x3, 1, inputcode3);                                                                                                       
		//ebm_write(pl_data, 0x4, 1, inputcode4);                                                                                                       
		//ebm_write(pl_data, 0x5, 1, inputcode5);                                                                                                       
		//ebm_write(pl_data, 0x6, 1, inputcode6);                                                                                                       
	}
	/////////////////////done//////////////////////                                                                                                   

	//funtest(OSCTrim_set_final, LEC_first_vectors);                  //write code                                                                    
	//functional_datalog(pl_data);                                                                                                                    
}
void VDEL_write_trim_data()
{
	/////////////////////////////ebm write/////////                                                                                                   
	ebm_clear();						 //ebm config                                                                                                             
	ebm_config_set(t_ebm_data_mode, pl_SDA);
	ebm_address_reg_set(t_ebm_start_addr, 0x0);
	//ebm_address_reg_set(t_ebm_addr_2, 0x0);                                                                                                         
	//ebm_address_reg_set(t_ebm_addr_3, 0x0); 
	#ifdef display_datalog
	CString s = vFormat("VDELrim_code:	");
	#endif
	DWordArray inputcode;
	SoftwareOnlyActiveDutIterator lec_loop2;
	while (lec_loop2.More())//loop,then save trim value                                                                                               
	{
		DutNum dut = active_dut_get();
		inputcode.RemoveAll();  // Clear the array
		if (VDELTrim_data[dut] % 8 % 4 % 2 / 1)
		{
			inputcode.Add(0x01);
		}
		else
		{
			inputcode.Add(0x00);
		}
		if (VDELTrim_data[dut] % 8 % 4 / 2)
		{
			inputcode.Add(0x01);
		}
		else
		{
			inputcode.Add(0x00);
		}
		if (VDELTrim_data[dut] % 8 / 4)
		{
			inputcode.Add(0x01);
		}
		else
		{
			inputcode.Add(0x00);
		}
		if (VDELTrim_data[dut] / 8)
		{
			inputcode.Add(0x01);
		}
		else
		{
			inputcode.Add(0x00);
		}

		//output("inputcode size is now %d dut %d value %d", inputcode.GetSize(),dut, VDELTrim_data[dut]);

		ebm_write(dut, pl_SDA, 0x0, 4, inputcode);
		//ebm_write(pl_data, 0x1, 1, inputcode1);                                                                                                       
		//ebm_write(pl_data, 0x2, 1, inputcode2);                                                                                                       
		//ebm_write(pl_data, 0x3, 1, inputcode3);                                                                                                       
		//output("VDEL code   dut%d    code%d", dut, VDELTrim_data[dut]);
	}

	/////////////////////done//////////////////////                                                                                                   
	//funtest(VDELTrim_set_final, finish);                  //write code function                                                                     
	//functional_datalog(pl_data);                                                                                                                    
}
#endif                                                                                                                                              