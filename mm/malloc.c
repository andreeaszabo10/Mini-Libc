// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>
#include <internal/mm/mem_list.h>
#include <string.h>

size_t ptrsize(void *ptr)
{
    return mem_list_find(ptr)->len;
}

void *malloc(size_t size)
{
    void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    mem_list_add(ptr, size);
    return ptr;
}

void free(void *ptr)
{
    size_t size = ptrsize(ptr);
	mem_list_del(ptr);
	munmap(ptr, size);
}

void *realloc(void *ptr, size_t size)
{
    void *new = malloc(size);
    memcpy(new, ptr, ptrsize(ptr));
    free(ptr);
    return new;
}

void *calloc(size_t nmemb, size_t size)
{
    void *ptr = malloc(nmemb * size);
    memset(ptr, 0, nmemb * size);
    return ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    void *new = malloc(nmemb * size);
    memcpy(new, ptr, ptrsize(ptr));
    free(ptr);
    return new;
}
