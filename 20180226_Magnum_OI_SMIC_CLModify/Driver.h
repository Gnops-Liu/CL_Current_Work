// Driver.h: CDriver 
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRIVER_H__B589D777_1B21_4D65_A12F_3D2B59EB6A49__INCLUDED_)
#define AFX_DRIVER_H__B589D777_1B21_4D65_A12F_3D2B59EB6A49__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef enum _dev_event {
  DEV_NOT_READY,
  DEV_READY,
  DEV_START_OF_WAFER,
  DEV_END_OF_WAFER,
  DEV_START_OF_LOT,
  DEV_END_OF_LOT,
  DEV_COMM_ERROR
} DEV_EVENT;

struct devinfo
{
	int		iGpibPad;
	char	cID[180];			// prober name
	char	cLot[80];				// lot name
	char	cWaferID[80];			// wafer name
	char	cFlat[2];				// flat direction news
	char	cProbeCard_name[18];	// probe card name

	int		iWafer;					// wafer number under testing
	int		iTotalWafers;			// total wafer number
	int		iX;						// wafermap x coordination
	int		iY;						// wafermap y coordination
	int		iXdim;					// x size um
	int		iYdim;					// y size um
	int		iFlat;					// flat direction 0,90,180,270,other
	char	cProbeCard_num[1280];		// probe card multi site number

	float	fChuck_temp;			// chuck temperature degree

	DEV_EVENT		iPollResult;				

	char	cWaferStatus[80];
	int		iTouchdowns;
};

typedef devinfo (*HND_GETINFO)(void);
typedef BOOL (*HND_INIT)();
typedef bool *(*HND_POLL)(void);
typedef BOOL (*HND_SET)(LPCTSTR);
typedef BOOL (*HND_BIN)(int *,int *, int );
typedef LPCTSTR (*HND_QUERY)(LPCTSTR);
typedef int (*HND_LOADWAFER)(void);
typedef int (*HND_UNLOADWAFER)(void);
typedef void (*HND_ALARM)(LPCTSTR);
typedef int (*HND_ZUP)(void);
typedef int (*HND_ZDOWN)(void);
typedef int (*HND_MOVE)(int, int);
typedef int (*HND_MOVE_TO_FIRST)();
typedef int (*HND_START)();

class CDriver  
{


	HINSTANCE		hDllInstance;

	CString			cDllFileName;

	CString				cType;

public:
	CDriver();
	virtual ~CDriver();

	virtual void init();
	virtual void ChangeDLL( CString cName );
	virtual void SetDLL( CString cName );
	virtual CString GetDLL();
	virtual void SetType( CString cType);
	virtual CString GetType();

	HND_GETINFO		Hnd_GetInfo;
	HND_INIT		Hnd_Init;
	HND_POLL		Hnd_Poll;
	HND_SET			Hnd_Set;
	HND_BIN			Hnd_Bin;
	HND_QUERY		Hnd_Query;
	HND_LOADWAFER	Hnd_LoadWafer;
	HND_UNLOADWAFER	Hnd_UnloadWafer;
	HND_ALARM		Hnd_Alarm;
	HND_ZUP			Hnd_ZUp;
	HND_ZDOWN		Hnd_ZDown;
	HND_MOVE		Hnd_Move;
	HND_MOVE_TO_FIRST	Hnd_Move_to_first;
	HND_START		Hnd_Start;
};

#endif // !defined(AFX_DRIVER_H__B589D777_1B21_4D65_A12F_3D2B59EB6A49__INCLUDED_)
