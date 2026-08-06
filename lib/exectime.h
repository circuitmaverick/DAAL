#ifndef EXECTIME_H
#define EXECTIME_H

typedef enum {
    s,
    ms,
    ns
} timeunits;

void start();
void stop();
void reset();
double getTime(timeunits);

#endif