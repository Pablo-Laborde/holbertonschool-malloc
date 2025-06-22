#include "malloc.h"


#define KB 1024
#define MB (KB * 1024)



/**
* naive_malloc - func
* @size: size_t
* Return: void *
*/
void *naive_malloc(size_t size)
{
	void *start_break = NULL, *available_mem = NULL;
	intptr_t address = 0;
	size_t  *header = NULL;

	start_break = sbrk(0);
	address = (intptr_t)start_break + sizeof(size_t);
	available_mem = (void *)address;
	address += size;
	if (brk((void *)address) == -1)
		return (NULL);
	header = (size_t *)start_break;
	*header = size;
	return (available_mem);
}
