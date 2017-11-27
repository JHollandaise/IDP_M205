#include <ctime>
#include "global.h"

void Wait(const float& time)
{   // Wait by the specified amount of time
    clock_t t1 = clock();

    // Wait until the time has elapsed
    while (float(clock() - t1)/CLOCKS_PER_SEC < time) {};
}