#include "malloc.h"


#define SS sizeof(size_t)

#define PS sysconf(_SC_PAGESIZE)



/**
* align_ptr - func
* @ptr: void *
* Return: void *
*/
void *align_ptr(void *ptr)
{
	intptr_t adv = 0;

	adv = 8 - ((intptr_t)ptr % 8);
	return ((void *)((intptr_t)ptr + adv));
}


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
	if ((intptr_t)next_mem % 8)
		next_mem = align_ptr(next_mem);
	dif = (intptr_t)lim - (intptr_t)next_mem;
	if ((size_t)dif < (size + SS))
		if (brk((void *)((intptr_t)lim + PS)) == -1)
			return (NULL);
	header = (size_t *)next_mem;
	*header = size;
	cur_mem = (void *)((intptr_t)next_mem + SS);
	next_mem = (void *)((intptr_t)cur_mem + size);
	return (cur_mem);
}


/**
* exact_malloc - func
* @size: size_t
* Return: void *
*/
void *exact_malloc(size_t size)
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
