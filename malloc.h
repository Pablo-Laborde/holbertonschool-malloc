#ifndef MALLOC_H
#define MALLOC_H


/* Macros */
#define SS sizeof(size_t)
#define PS sysconf(_SC_PAGESIZE)



/* Libraries */
#include <stdio.h>

#include <unistd.h>


/* Functions prototypes */
void *naive_malloc(size_t size);
void *exact_malloc(size_t size);

void *_malloc(size_t size);

void _free(void *ptr);


#endif
