// SPDX-License-Identifier: BSD-3-Clause

#include <time.h>
#include <stdlib.h>

unsigned int sleep(unsigned int seconds) {
    struct timespec a, b;

    a.tv_sec = seconds;
    a.tv_nsec = 0;

    if (nanosleep(&a, &b) == -1) {
        return b.tv_sec;
    }

    return 0;
}
