#ifndef USER_SUBROUTINE_H
#define USER_SUBROUTINE_H
struct buffer{
	double distance[12];	//keep the mini distance of 12 dut. update 16 times
	double logout[16][12];	//keep the total trim test result, use it for datalog or scanning
	double result[12];		//keep the test result of 12 dut. update 16 times
	double temp[12];		//calculate the distance of12 dut, update 16 times
	int	record[12];			//keep the best trim code, update 16 times
	double target;			//keep the target of trim 

	void Clear_All()
	{
		for (int i = 0; i < 12; i++)
		{
			distance[i] = 537;
			result[i] = 537;
			temp[i] = 537;
			record[i] = 537;
			for (int j = 0; j < 16; j++)
			{
				logout[j][i] = 537;
			}
		}
		target = 0;
	}
};

class stuff{
public:
	int main_bg_code[12],
		prog_vnn_code[12],
		prog_vpp_code[12],
		erase_vpp_code[12];
	double	main_bg_volts[12],
			prog_vnn_volts[12],
			prog_vpp_volts[12],
			erase_vpp_volts[12];
	void clean_all()
	{
		for (int i = 0; i < 12; i++)
		{
			main_bg_code[i] = 0;
			prog_vnn_code[i] = 0;
			prog_vpp_code[i] = 0;
			erase_vpp_code[i] = 0;
			prog_vnn_volts[i] = 0;
			prog_vpp_volts[i] = 0;
			erase_vpp_volts[i] = 0;
			main_bg_volts[i] = 0;
		}
	}
};

class Verify_Stuff{
public:
	int Main_bgX32[12];
	int Sdn_bgX32[12];
	int Main_bg_BKP[12];
	int Sdn_bg_BKP[12];
	
	int PVNN[12];
	int PVNNX128[12];
	int PVPP[12];
	int PVPPX128[12];
	int EVPP[12];
	int EVPPX128[12];

	long x_orgn[12];
	long y_orgn[12];
	long x_bkp[12];
	long y_bkp[12];

	long lot_code[12];

	long slot_bkp[12];
	long lot_bkp[12];

	bool Demo_flag1[12];
	bool Demo_flag2[12];
	void clear_all()
	{
		for (int i = 0; i < 12; i++)
		{
			Main_bgX32[i] = 0;
			Sdn_bgX32[i] = 0;
			Main_bg_BKP[i] = 0;
			Sdn_bg_BKP[i] = 0;
			
			PVNN[i] = 0;
			PVNNX128[i] = 0;
			PVPP[i] = 0;
			PVPPX128[i] = 0;
			EVPP[i] = 0;
			EVPPX128[i] = 0;
			
			x_orgn[i] = 0;
			y_orgn[i] = 0;
			x_bkp[i] = 0;
			y_bkp[i] = 0;
			
			lot_code[i] = 0;
			
			slot_bkp[i] = 0;
			lot_bkp[i] = 0;

			Demo_flag1[i] = 0;
			Demo_flag2[i] = 0;
		}
	}
};

class Margin_Record
{
public:
	bool E1_std_5V[12];
	bool E1_std_1V[12];
	bool E1_std_1p4V[12];
	bool E1_std_1p5V[12];
	bool E1_std_1p6V[12];
	bool E1_std_1p7V[12];
	bool E1_std_1p8V[12];

	bool E2_std_5V[12];
	bool E2_std_1V[12];
	bool E2_std_1p4V[12];
	bool E2_std_1p5V[12];
	bool E2_std_1p6V[12];
	bool E2_std_1p7V[12];
	bool E2_std_1p8V[12];

	bool E1_spec_5V[2][12];
	bool E1_spec_1V[2][12];
	bool E1_spec_1p4V[2][12];
	bool E1_spec_1p5V[2][12];
	bool E1_spec_1p6V[2][12];
	bool E1_spec_1p7V[2][12];
	bool E1_spec_1p8V[2][12];

	void clear_all()
	{
		for (int i = 0; i < 12; i++)
		{
			E1_std_5V[i]	 = 0;
			E1_std_1V[i]	 = 0;
			E1_std_1p4V[i]	 = 0;
			E1_std_1p5V[i]	 = 0;
			E1_std_1p6V[i]	 = 0;
			E1_std_1p7V[i]	 = 0;
			E1_std_1p8V[i]	 = 0;

			E2_std_5V[i] = 0;
			E2_std_1V[i] = 0;
			E2_std_1p4V[i] = 0;
			E2_std_1p5V[i] = 0;
			E2_std_1p6V[i] = 0;
			E2_std_1p7V[i] = 0;
			E2_std_1p8V[i] = 0;

			E1_spec_5V[1][i] = 0;
			E1_spec_1V[1][i] = 0;
			E1_spec_1p4V[1][i] = 0;
			E1_spec_1p5V[1][i] = 0;
			E1_spec_1p6V[1][i] = 0;
			E1_spec_1p7V[1][i] = 0;
			E1_spec_1p8V[1][i] = 0;

			E1_spec_5V[2][i] = 0;
			E1_spec_1V[2][i] = 0;
			E1_spec_1p4V[2][i] = 0;
			E1_spec_1p5V[2][i] = 0;
			E1_spec_1p6V[2][i] = 0;
			E1_spec_1p7V[2][i] = 0;
			E1_spec_1p8V[2][i] = 0;
		}
	}
};


extern struct buffer MAIN_BGP, SDN_BGP, VREF;
extern struct buffer MAIN_BGP2, SDN_BGP2, VREF2;
extern struct buffer ERA_VPP;
extern struct buffer ERA_VPP2;
extern struct buffer PROG_VPP, PROG_VNN;
extern struct buffer PROG_VPP2, PROG_VNN2;
extern struct buffer OSC;
extern struct buffer OSC2;
extern struct buffer REF_C;
extern struct buffer REF_C2;
//cp0 special
static long Die_count = 0;
static long Volt_count = 0;
static bool flag_trimbin = 0;
static bool flag_trimvolt = 0;

extern void MyStartTimer(CString str);
extern void MyStopTimer(CString str);
extern void judge_test_result(struct buffer temp, double torlerance);
extern void clean_trim_register(long *reg);

extern void getin_file();
extern void tb_Summary();

extern int two(int temp);

extern void config_optrim(long int* op_trim_reg, int i, int locat_b3, int locat_b2, int locat_b1, int locat_b0);
extern void contact_solution(void);
extern void clear_buffer(void);
extern int judge_location(int temp);
extern long int counter_register(int reg, int length);
extern long int* shift_register(int locat_x, int bit_x, long int* reg);
extern long int shift_register(int locat_x, int bit_x, long int reg);
extern long int* MSB_modification(long int* op_trim_reg, int length);
extern long int MSB_modification(long int op_trim_reg, int length);
extern void raw_optrim(long int* op_trim_reg, int i, int locat_b2, int locat_b1, int locat_b0);
extern void raw_optrim(long int* op_trim_reg, int i, int locat_b3, int locat_b2, int locat_b1, int locat_b0);
extern void raw_optrim_MSB(long int* op_trim_reg, int i, int locat_b2, int locat_b1, int locat_b0);
extern void raw_optrim_MSB(long int* op_trim_reg, int i, int locat_b3, int locat_b2, int locat_b1, int locat_b0);
extern long int complex_optrim(int i, int locat_b3, int locat_b2, int locat_b1, int locat_b0);
extern long int complex_optrim_MSB(int i, int locat_b3, int locat_b2, int locat_b1, int locat_b0);
extern long int spec_optrim_MSB(int i, int locat_b3, int locat_b2, int locat_b1, int locat_b0);

extern void Mianbgp_partset();
extern void Sdnbgp_partset();
extern void Program_Vnn_partset();
extern void Program_Vpp_partset();
extern void Erase_Vpp_partest();

extern long int address_merge(int y, int x);





#endif