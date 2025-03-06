// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

// https://www.techiedelight.com/implement-strcpy-function-c/
char *strcpy(char *destination, const char *source)
{
    if (destination == NULL) {
        return NULL;
    }

    char *ptr = destination;

    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';

    return ptr;
}

// https://www.techiedelight.com/implement-strncpy-function-c/
char *strncpy(char *destination, const char *source, size_t len)
{
    size_t i;
    char *temp;
    temp = destination;
    for (i = 0; i < len; i++)
        *destination++ = *source++;
    return temp;
}

// https://www.techiedelight.com/implement-strcat-function-c/
char *strcat(char *destination, const char *source)
{
    char* ptr = destination + strlen(destination);

    while (*source != '\0') {
        *ptr++ = *source++;
    }

    *ptr = '\0';

    return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
    char* ptr = destination + strlen(destination);

    while (*source != '\0' && len != 0) {
        *ptr++ = *source++;
        len = len - 1;
    }

    *ptr = '\0';

    return destination;
}

int strcmp(const char *str1, const char *str2)
{
    while (*str1 && *str1 == *str2) {
        str1 = str1 + 1;
        str2 = str2 + 1;
    }
    return *str1 - *str2;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
    while (len > 0 && *str1 && (*str1 == *str2)) {
        str1 = str1 + 1;
        str2 = str2 + 1;
        len = len - 1;
    }
    if (len == 0)
        return 0;
    else
        return *str1 - *str2;
}

size_t strlen(const char *str)
{
    size_t len = 0;
    while (str[len] != '\0')
        len = len + 1;
    return len;
}

char *strchr(const char *str, int c)
{
    while (*str != '\0') {
        if (*str == c)
            return (char *)str;
        str = str + 1;
    }
    return NULL;
}

char *strrchr(const char *str, int c)
{
    char *var = NULL;
    while (*str != '\0') {
        if (*str == c)
            var = (char *)str;
        str = str + 1;
    }
    return var;
}

// https://stackoverflow.com/questions/49131175/recreate-the-strstr-function
char *strstr(const char *haystack, const char *needle)
{
    size_t n = strlen(needle);
    while (*haystack)
        if (!memcmp(haystack++, needle, n))
            return (char *)(haystack - 1);
    return 0;
}

char *strrstr(const char *haystack, const char *needle)
{
    for (const char *ptr = haystack + strlen(haystack) - 1; ptr >= haystack; ptr--) {
        if (*ptr == needle[strlen(needle) - 1] && strncmp(ptr - (strlen(needle) - 1), needle, strlen(needle)) == 0)
            return (char *)(ptr - (strlen(needle) - 1));
    }
    return NULL;
}

void *memcpy(void *destination, const void *source, size_t len)
{
    while (len != 0) {
        *(char *)destination++ = *(char *)source++;
        len = len - 1;
    }
    return destination;
}

void *memmove(void *destination, const void *source, size_t len)
{
    unsigned char *dest = (unsigned char *)destination;
    const unsigned char *src = (const unsigned char *)source;
    if (dest > src && dest < src + len) {
        dest = dest + len;
        src = src + len;
        while (len != 0) {
            *--dest = *--src;
            len = len - 1;
        }
    } else {
        while (len != 0) {
            *dest++ = *src++;
            len = len - 1;
        }
    }
    return destination;
}

// https://aticleworld.com/memcmp-in-c/
int memcmp(const void *ptr1, const void *ptr2, size_t len)
{
    unsigned char *p = (unsigned char *)ptr1;
    unsigned char *q =  (unsigned char *)ptr2;
    int charCompareStatus = 0;
    if (ptr1 == ptr2)
        return charCompareStatus;
    while (len > 0)
    {
        if (*p != *q)
        {
            charCompareStatus = (*p >*q)?1:-1;
            break;
        }
        len--;
        p++;
        q++;
    }
    return charCompareStatus;
}

void *memset(void *source, int value, size_t len)
{
    while (len != 0) {
        *(char *)source++ = value;
        len = len - 1;
    }
    return source;
}
