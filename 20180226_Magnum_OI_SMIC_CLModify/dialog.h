EXTERN_ONEOF_VARIABLE( oDriverType) 
EXTERN_ONEOF_VARIABLE( dlog_pins)
EXTERN_CSTRING_VARIABLE( Test_flow_step )
EXTERN_ONEOF_VARIABLE( oi_SORT_ID )

EXTERN_CSTRING_VARIABLE( TOUCHDOWNS	)
EXTERN_CSTRING_VARIABLE( STATUS_WAFERS) 
EXTERN_CSTRING_VARIABLE( DEVICE_NAME) 
EXTERN_CSTRING_VARIABLE( LOT_NUM) 
EXTERN_CSTRING_VARIABLE( WFR_SLOT_ID) 
EXTERN_CSTRING_VARIABLE( PROGRAM_NAME) 
EXTERN_CSTRING_VARIABLE( PROBE_CARD_ID	) 
EXTERN_CSTRING_VARIABLE( TEST_PROGRAM_DIR)
EXTERN_CSTRING_VARIABLE( FLOW_NAME) 
EXTERN_CSTRING_VARIABLE( LOT_NUM) 
EXTERN_CSTRING_VARIABLE( LATEST_WAFER_NUM) 
EXTERN_CSTRING_VARIABLE( SWT_DIR) 
__declspec(dllexport) EXTERN_CSTRING_VARIABLE( DRIVER_DLL_DIR) 

EXTERN_VOID_VARIABLE ( vPause ) 
EXTERN_VOID_VARIABLE( vLoad)
EXTERN_VOID_VARIABLE( AutoProbe)
EXTERN_VOID_VARIABLE( datalog_button )
EXTERN_VOID_VARIABLE( vHnd_UnloadWafer )
EXTERN_VOID_VARIABLE( vHnd_LoadWafer )
EXTERN_VOID_VARIABLE( vHnd_ZUp )
EXTERN_VOID_VARIABLE( vHnd_ZDown )
EXTERN_VOID_VARIABLE( vHnd_Move )
EXTERN_VOID_VARIABLE( StopAutoProbe )
EXTERN_VOID_VARIABLE( vHnd_Move_to_first ); 

EXTERN_VOID_VARIABLE( vWaferMap )
EXTERN_VOID_VARIABLE( vProbeCardMap )

EXTERN_BOOL_VARIABLE(  para ) 
EXTERN_BOOL_VARIABLE(  func ) 
EXTERN_BOOL_VARIABLE(  user ) 
EXTERN_BOOL_VARIABLE(  fdlog ) 
EXTERN_BOOL_VARIABLE( lvm )
EXTERN_BOOL_VARIABLE( shmoo )
EXTERN_BOOL_VARIABLE( search )
EXTERN_BOOL_VARIABLE ( bWMAP_TOOL ) 

EXTERN_INT_VARIABLE(  dlog) 
EXTERN_INT_VARIABLE(  iX) 
EXTERN_INT_VARIABLE(  iY) 

EXTERN_DIALOG( PROBER_DIALOG_CUSTOMER ) 
EXTERN_DIALOG( SELECT_TEST_PROGRAM ) 
EXTERN_DIALOG( SELECT_DRIVER_DLL ) 
EXTERN_DIALOG( SELECT_SWT ) 
EXTERN_DIALOG( DOUBLE_CHECK ) 
EXTERN_DIALOG( DATALOG_DIALOG ) 

EXTERN_INT_VARIABLE(oi_PASS) 
EXTERN_INT_VARIABLE(oi_FAIL) 
EXTERN_INT_VARIABLE(oi_TESTED) 
EXTERN_CSTRING_VARIABLE(oi_PASS_YIELD) 
EXTERN_CSTRING_VARIABLE(oi_FAIL_YIELD) 
EXTERN_ONEOF_VARIABLE(oi_RUNMODE_SELECTED) 

EXTERN_CSTRING_VARIABLE(PRODUCT_ID_chk) 
EXTERN_CSTRING_VARIABLE(LOT_ID_chk) 
EXTERN_CSTRING_VARIABLE(TEST_PROGRAM_chk) 
EXTERN_CSTRING_VARIABLE(RUNMODESELECTED_chk) 
EXTERN_CSTRING_VARIABLE(oi_PROBER_LOT_ID)
EXTERN_CSTRING_VARIABLE(oi_WAFER_ID)

EXTERN_BOOL_VARIABLE ( bUseLotNumEntry ) 

void disable_manual_buttons();
void enable_manual_buttons();


