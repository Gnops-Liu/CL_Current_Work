void power_down(void);
void vs_set(void);
#define DUTS_PER_SITE       16

extern DutNumArray still_active_dut;
extern DWORD still_active_dut_dword;


extern void ecr_addr_initialize();
extern void PointFailure_initialize(PointFailure *buffer, int length);

extern void EBM_setup_for_scan(long int* op_trim_reg, PinList* PL);
extern void EBM_setup_for_scan(long int* op_trim_reg, PinList* PL, DutNum dut);
extern void EBM_setup_for_save(long int* op_trim_reg, PinList* PL);
extern void EBM_save_address(long int EBM_register, PinList* PL);
extern void EBM_save_single_value(long int* reg_pointer, int length, PinList* PL);
extern void EBM_save_single_value(long int* reg_pointer, int length, PinList* PL, DutNum dut);
extern void ecr_set_for(PinList *pl);

extern void vs_set(double v_set);
extern void vs_set_H();
extern void vs_set_L();
void  ts_10mhz(void);

//void  ts_17mhz(void);
//void  ts_19mhz(void);
//void  ts_20mhz(void);
extern int Prog_Wait;
extern int read_count;