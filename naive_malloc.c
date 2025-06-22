#include "malloc.h"


#define SS sizeof(size_t)

#define KB 1024
#define MB (KB * 1024)



/**
* naive_malloc - func
* @size: size_t
* Return: void *
*/
void *naive_malloc(size_t size)
{
	static void *next_mem;
	void *lim = NULL, *cur_mem = NULL;
	intptr_t dif = 0;
	size_t *header = NULL;

	lim = sbrk(0);
	if (!next_mem)
		next_mem = lim;
	dif = (intptr_t)lim - (intptr_t)next_mem;
	if ((size_t)dif < (size + SS))
		if (brk((void *)((intptr_t)lim + SS + size)) == -1)
			return (NULL);
	header = (size_t *)next_mem;
	*header = size;
	cur_mem = (void *)((intptr_t)next_mem + SS);
	next_mem = (void *)((intptr_t)cur_mem + size);
	return (cur_mem);
}
