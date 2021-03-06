void TPEGetCurrentXY(int dut, int *xcord, int *ycord);
void process_test_results(TestBin* current_test_bin, int sbin, int hbin, PFState pf);

CString get_flow_name();

class Bin {
	public:
	CString name;
	int sbin;
	int	hbin;
	PFState result;
	CString data;				
	CString repair_data;
	CString s_cat;				
	CString s_tbr;	
};

class Die_Crd {
public:
	int x, y;
};

extern void Get_LotNum();
EXTERN_BOOL_VARIABLE( FK1 ); 
EXTERN_BOOL_VARIABLE( FK2 ); 
EXTERN_BOOL_VARIABLE( FK3 ); 
EXTERN_BOOL_VARIABLE( FK4 ); 
EXTERN_BOOL_VARIABLE( FK5 ); 
EXTERN_BOOL_VARIABLE( FK6 ); 
EXTERN_BOOL_VARIABLE( FK7 ); 
EXTERN_BOOL_VARIABLE( FK8 ); 
EXTERN_BOOL_VARIABLE( FK9 ); 
EXTERN_BOOL_VARIABLE( FK10); 
EXTERN_BOOL_VARIABLE( FK11); 
EXTERN_BOOL_VARIABLE( FK12); 
EXTERN_BOOL_VARIABLE( FK13); 
EXTERN_BOOL_VARIABLE( FK14); 
EXTERN_BOOL_VARIABLE( FK15); 
EXTERN_BOOL_VARIABLE( FK16); 

EXTERN_CSTRING_VARIABLE( LOT_NUM);
EXTERN_CSTRING_VARIABLE( WRF_START_TIME) ;
EXTERN_CSTRING_VARIABLE( WRF_START_DATE) ;
EXTERN_CSTRING_VARIABLE( WRF_END_TIME) ;
EXTERN_CSTRING_VARIABLE( WRF_END_DATE) ;
EXTERN_CSTRING_VARIABLE( WFR_SLOT_ID) ;
EXTERN_CSTRING_VARIABLE( WRF_END_TIME_GMT);
EXTERN_CSTRING_VARIABLE( WRF_START_TIME_GMT) ;
EXTERN_CSTRING_VARIABLE( WRF_START_DATETIME) ;  
EXTERN_CSTRING_VARIABLE( RESULTS_STR);  
EXTERN_CSTRING_VARIABLE( DLOG_FILE_PATH) ;
EXTERN_CSTRING_VARIABLE( FLOW_NAME); 
EXTERN_CSTRING_VARIABLE( CHUCK_TEMP) ;
EXTERN_CSTRING_VARIABLE( OPERATOR_ID);
EXTERN_CSTRING_VARIABLE( DEVICE_NAME) ;
EXTERN_CSTRING_VARIABLE( COMMENTS) ;
EXTERN_CSTRING_VARIABLE( USER_C) ;
EXTERN_CSTRING_VARIABLE( PROGRAM_NAME) ;
EXTERN_CSTRING_VARIABLE( PROGRAM_PATH) ;
EXTERN_CSTRING_VARIABLE( PROBE_CARD_ID) ;

EXTERN_ONEOF_VARIABLE( oDriverType);

EXTERN_BOOL_VARIABLE( tp_fdlog );
EXTERN_BOOL_VARIABLE( para );	
EXTERN_BOOL_VARIABLE( func ) ;	
EXTERN_BOOL_VARIABLE( lvm ) ;	
EXTERN_BOOL_VARIABLE( user );

EXTERN_INT_VARIABLE( dlog ) ;
EXTERN_INT_VARIABLE ( SITE_PER_CONTROLLER_NUM ) ;
EXTERN_INT_VARIABLE ( MAX_DUT_NUM_PER_SITE ) ;
EXTERN_INT_VARIABLE ( MAX_SITES_NUM ) ;	
EXTERN_INT_VARIABLE(  TesterID) ;
EXTERN_INT_VARIABLE(  SerialNum ) ;

EXTERN_INT64_VARIABLE( iv_init_dut_mask);

extern bool dlog_func;

