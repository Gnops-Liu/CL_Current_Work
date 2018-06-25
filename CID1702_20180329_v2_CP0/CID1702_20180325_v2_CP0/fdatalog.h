
#define MAX_DUTS 128

typedef enum {
  ForceVMeasureI,
  ForceIMeasureV
} IVMeasType;

extern bool dlog_func;

extern FILE *fp_dut[];

//find bug created by Edgar's Debug
void tp_pdatalog( PinList *pPinList, IVMeasType meas_type); //call after a parametric test
void tp_fdatalog( PinList* pPinList );

void dlogfileopenallactive(void);					// Put in BTB, after IgnoreDutsEnable
void dlogcloseallopen(void);						// Put in ATB
void dlogheaderallopen(void);						// Put in BTB, just after DlogFileOpenAllActive
void dlogtblkheaderallactive(CString TblkName);		// Put at the start of each test block
void dlogtestresults();
void create_datalog_folder();

BOOL check_dlog_enable( char type, CString dlog_info);

EXTERN_INT_VARIABLE( DLog_vector_count ) ;	

EXTERN_BOOL_VARIABLE( fdlog)

int tb_header( void );
int tb_end( bool flag = 1);