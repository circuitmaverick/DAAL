#include "exectime.h"
#include<time.h>

clock_t __start, __end;

void start() {  __start = clock();  }
void stop() {    __end = clock();    }
void reset() {  __start = 0;    __end = 0;  }

double getTime(timeunits tu) {
    double duration = ((double)(__end - __start))/CLOCKS_PER_SEC;
    switch (tu)
    {
    case ns:    return duration*1e9;
    case ms:    return duration*1e3;
    case s:
    default:    return duration;
    }
    return duration;
}