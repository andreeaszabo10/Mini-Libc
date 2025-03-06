// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>

int puts(const char *str)
{
    int len = 0;
    while (str[len] != '\0')
        len = len + 1;
    if (write(1, str, len) == -1)
        return -1;
    if (write(1, "\n", 1) == -1)
        return -1;
    return len;
}
