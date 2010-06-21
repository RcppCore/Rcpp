
// Simple timer class based on atimer.h / atimer.cxx found a few years ago at 
//     http://www.cs.uiowa.edu/~sriram/30/fall03/ 
//     and attributed to Amir Elaguizy while under GPL
// That class site is still preserved. Also has a link to a simpler class at duke.edu

#ifndef TIMER_H
#define TIMER_H

#include <sys/timex.h>			// Probably implies Linux-only ...

int timeval_subtract (struct timeval *result, struct timeval *x, struct timeval *y);

class Timer {
public:
	Timer() { 
		start_t.time.tv_sec = 0; 
		start_t.time.tv_usec = 0; 
		end_t.time.tv_sec = 0; 
		end_t.time.tv_usec = 0;
		myCumulative = 0; 
		myElapsed = 0; 
	}
      
	void Start()  {
		ntp_gettime(&start_t);
	}

	void Stop() {
		ntptimeval result;

		ntp_gettime(&end_t);
		timeval_subtract(&result.time, &end_t.time, &start_t.time);

		// Calculate elapsed time in seconds
		myElapsed = (result.time.tv_sec + (result.time.tv_usec / 1000000.0)); 
		myCumulative += myElapsed;
	}

	void Reset() {
		end_t.time.tv_sec = 0;
		end_t.time.tv_usec = 0;
		start_t.time.tv_sec = 0;
		start_t.time.tv_usec = 0;
		myElapsed = 0;
		myCumulative = 0;
	}

	double ElapsedTime()  {
		return myElapsed;
	}

	double CumulativeTime() { 
		return myCumulative;
	}


private:
	ntptimeval start_t, end_t;
	double myElapsed;
	double myCumulative;

	int timeval_subtract (struct timeval *result, struct timeval *x, struct timeval *y) {
		// NOTE: THIS FUNCTION IS GNU CODE AND IS USED UNDER THE GPL.
		// Purpose:
		//   Put the result of subtraction of x & y into result
		//
		// Arguments:
		//   result - the container for the result of subtraction
		//   x - the ending time
		//   y - the starting time
		// 
		// Return value:
		//   0 if result is positive (normal state)
		//   1 if result is negative (error state)
		
		// Perform the carry for the later subtraction by updating y.
		if (x->tv_usec < y->tv_usec) {
			int nsec = (y->tv_usec - x->tv_usec) / 1000000 + 1;
			y->tv_usec -= 1000000 * nsec;
			y->tv_sec += nsec;
		}
		if (x->tv_usec - y->tv_usec > 1000000) {
			int nsec = (x->tv_usec - y->tv_usec) / 1000000;
			y->tv_usec += 1000000 * nsec;
			y->tv_sec -= nsec;
		}
	
		// Compute the time remaining to wait.
		//    tv_usec is certainly positive.
		result->tv_sec = x->tv_sec - y->tv_sec;
		result->tv_usec = x->tv_usec - y->tv_usec;
		
		// Return 1 if result is negative. 
		return x->tv_sec < y->tv_sec;
	}
};

#endif

