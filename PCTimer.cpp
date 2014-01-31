#include "PCTimer.h"
#include <iostream>

inline PCTimer :: PCTimer() 
    : amRunning(false), myElapsed(0), myCumulative(0)
{
}

inline void PCTimer :: start()
{
    if ( amRunning )
        std::cerr << "attempt to start an already running stopwatch" << std::endl;
    else
    {
        amRunning = true;
        myStartTime = clock();
    }
}

inline void PCTimer :: stop()
{
    if ( ! amRunning )
        std::cerr << "attempt to stop a non-running stopwatch" << std::endl;
    else
    {
        clock_t myEndTime = clock();
        myElapsed = myEndTime - myStartTime;
        myCumulative += myElapsed;            
        amRunning = false;
    }
}

inline void PCTimer :: reset()
{
    amRunning = false;
    myElapsed = 0;
    myCumulative = 0;
}
   
inline bool PCTimer :: isRunning() const
{
    return amRunning;
}

inline double PCTimer :: lapTime() const
{
    return amRunning ? (double)(clock() - myStartTime) / CLOCKS_PER_SEC : 0.0;
}

inline double PCTimer :: elapsedTime() const
{
    return amRunning ? 0.0 : (double)myElapsed / CLOCKS_PER_SEC;
}

inline double PCTimer :: cumulativeTime() const
{
    return ((double)myCumulative / CLOCKS_PER_SEC) + lapTime();  
}

inline double PCTimer :: granularity() const
{
    return 1.0 / CLOCKS_PER_SEC;
}

/* Example of use
 
#include "PCTimer.h"
#include <iostream.h>

int main()
{
	PCTimer t;
	t.start();
	for (int i=0, j; i<1000000000; i++)
		j++;
	t.stop();
	cout << t.elapsedTime() << endl;
}

*/
