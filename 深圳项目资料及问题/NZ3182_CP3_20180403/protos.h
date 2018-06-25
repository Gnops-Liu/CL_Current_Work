static enum Channel_Type{
	CT_all = 0,
	CT_dps,
	CT_hv,
	CT_dpo,
	CT_dpo_hv
};


#define TS1 TSET1
#define TS2 TSET2
#define TS3 TSET3
#define DUTNUM 2

void power_down(void);
void rst_lvl(void);
void func_lvl(void);
void otpLo_lvl(void);
void otpHi_lvl(void);
void vihl_lvl(void);
void Trim_lvl(void);
void ramist_lvl(void);
void Istand_lvl(void);
void ADC_lvl(void);


// timing.cpp
void ts_default(void);
void ts_std(void);
void ts_std1(void);
void ts_Trim(void);
void ts_ramist(void);
void ts_Istand(void);
void ts_ADC(void);






