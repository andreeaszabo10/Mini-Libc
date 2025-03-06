#ifndef TIME_H
#define TIME_H

#include <stddef.h>

typedef long time_t;
struct timespec {
    time_t tv_sec;
    time_t tv_nsec;
} timespec;

int nanosleep(const struct timespec *a, struct timespec *b);

#endif
