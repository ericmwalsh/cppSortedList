#include <time.h> 
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include "SortedList.h"
using namespace std;


void insertAllWords(char * fileName, SortedArrayList * inp);
bool findAllWords(char * fileName, SortedArrayList * inp);
void removeAllWords(char * fileName, SortedArrayList * inp);
void insertAllWords(char * fileName, SortedLinkedList * inp);
bool findAllWords(char * fileName, SortedLinkedList * inp);
void removeAllWords(char * fileName, SortedLinkedList * inp);

 // there is only old version of time, so .h is needed
// defines CLOCKS_PER_SEC and CLK_TCK

class PCTimer
{
public:

    PCTimer();
    void start();
    void stop();
    void reset();
    bool isRunning() const;
    double lapTime() const; // elapsed time without stopping
    double elapsedTime() const; // since last start
    double cumulativeTime() const; // total over all start/stops
    double granularity() const;
private:
    bool amRunning;
    clock_t myStartTime;
    clock_t myElapsed;
    clock_t myCumulative;
};

inline PCTimer :: PCTimer() 
    : amRunning(false), myElapsed(0), myCumulative(0)
{
}

inline void PCTimer :: start()
{
    if ( amRunning )
        cerr << "attempt to start an already running stopwatch" << endl;
    else
    {
        amRunning = true;
        myStartTime = clock();
    }
}

inline void PCTimer :: stop()
{
    if ( ! amRunning )
        cerr << "attempt to stop a non-running stopwatch" << endl;
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