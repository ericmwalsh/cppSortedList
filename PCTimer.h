#include <time.h>
//#include <iostream>
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
