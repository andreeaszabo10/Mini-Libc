// SPDX-License-Identifier: BSD-3-Clause

#include <time.h>
#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int nanosleep(const struct timespec *a, struct timespec *b) {
    int ret = syscall(35, a, b);

    if (ret < 0) {
       errno = -ret;
       return -1;
    }

    return ret;
}
