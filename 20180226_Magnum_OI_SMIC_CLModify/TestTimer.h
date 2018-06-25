#ifndef _TT_DEFS_
#define _TT_DEFS_

// Be sure to add    #include "TestTimer.h" to tester.h		
// D. Fox 2/5/2002
// Dfox  4/7/2008 Modified for test times. verified to 20+ hours
// Dfox  4/9/2008 Fixed round off error in freq calculation

class TEST_TIMER
{
	private:
		__int64 freq; 

		double TotalTime; 
		__int64 OverheadTime;
		__int64 StartCount; 
		__int64 StopCount;


		int Verbosity;

	public:
		TEST_TIMER() // Constructor
		{
			Verbosity = 3;
			//Verbosity = 9;
//			Init();
		}

		~TEST_TIMER() // destructor
		{

		}

		void Init()
		{
			LARGE_INTEGER LI_Freq;
			QueryPerformanceFrequency(&LI_Freq);
			freq = LI_Freq.QuadPart;
			if(Verbosity == 9)
				output("TEST_TIMER: freq = %ld",freq);
			StartTimer("Init");
			StopTimer("Init");
			OverheadTime =(StopCount-StartCount) / freq;
			//output("Overhead Time = %f", OverheadTime);
		}

		// Call StartTimer() just prior to area to be measured
		void StartTimer(CString Str)
		{
			LARGE_INTEGER LI_Start;
//			output("Running the all new and improved TEST_TIMER class");
			int QPC_ret = QueryPerformanceCounter(&LI_Start);
			StartCount = LI_Start.QuadPart;
			if(Verbosity == 9)
			{
				output("<COLOR=GREEN>TEST_TIMER : %s StartCount = %ld</COLOR>", Str, StartCount);
			}
		}
		// Pass this function a "string" that will output with the time
		double StopTimer(CString Str)
		{
			LARGE_INTEGER LI_Stop;
			int QPC_ret = QueryPerformanceCounter(&LI_Stop);
			StopCount = LI_Stop.QuadPart;
			TotalTime = (double)(StopCount-StartCount);
			TotalTime = (double)((double)(StopCount-StartCount) / (double)freq);
			TotalTime = TotalTime - OverheadTime;
			if(Verbosity == 9)
				output("Total Time 2 = %f Sec", TotalTime);
			if(Verbosity > 2)
			{
				//output("TEST_TIMER: %s\tTime = %f Sec", Str, TotalTime );
				output("<COLOR=RED>TEST_TIMER: %s\tTime = %f Sec</COLOR>", Str, TotalTime);
			}
			return(TotalTime);		
		}

		// If set to less than 3 output from StopTimer() will be disabled
		void SetVerbosity(int Val)
		{
			Verbosity = Val;
		}

};

 extern TEST_TIMER TB_Timer; 
 extern TEST_TIMER FTimer;
 extern TEST_TIMER ATimer;

#endif