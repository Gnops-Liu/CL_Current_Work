#define MAX_SIZE 200
#define MAX_BINS 1024

extern int SoftBinCnts[];

void wafermap_summaries();
void update_wafermap_tool( int x, int y, CString name);
void update_wafermap_field();
void clear_wafermap_field();
void wmap_callback(int x, int y);

EXTERN_ONEOF_VARIABLE( WM_ORIGIN)
