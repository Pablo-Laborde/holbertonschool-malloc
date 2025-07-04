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

	adv = (!((intptr_t)ptr % 8)) ? 0 : 8 - ((intptr_t)ptr % 8);
	return ((void *)((intptr_t)ptr + adv));
}


/**
* expand_limit - func
* @size: size_t
* @dif: intptr_t
* Return: int
*/
int expand_limit(size_t size, intptr_t dif)
{
	void *lim = NULL;
	size_t times = 0;

	lim = sbrk(0);
	times = (size - dif) / PS + 1;
	if (brk((void *)((intptr_t)lim + PS * times)) == -1)
		return (0);
	return (1);
}


/**
* mem_head - func
* @chunk: void *
* @size: size_t
* Return: void *
*/
void *mem_head(void *chunk, size_t size)
{
	*(size_t *)chunk = size;
	*(char *)((intptr_t)chunk + SS) = 0;
	return ((void *)((intptr_t)chunk + SS + 1));
}


/**
* scan_free - func
* @first_chunk: void *
* @end: void *
* @size: size_t *
* Return: void *
*/
void *scan_free(void *first_chunk, void *end, size_t size)
{
	void *a = first_chunk, *b = NULL;
	size_t free_size = 0;

	while (a != end)
	{
		b = a;
		free_size = 0;
		while (*((char *)((intptr_t)b + SS)))
		{
			free_size += *((size_t *)((intptr_t)b));
			if (free_size >= size)
				return (mem_head(a, free_size));
			b = (void *)((intptr_t)b + (size_t *)((intptr_t)b) + SS + 1);
			free_size += SS + 1;
		}
		a = (void *)((intptr_t)a + *(size_t *)((intptr_t)a) + SS + 1);
	}
	return (NULL);
}


/**
* _malloc - func
* @size: size_t
* Return: void *
*/
void *_malloc(size_t size)
{
	static void *end, *first_chunk;
	void *lim = NULL, *mem = NULL;
	intptr_t dif = 0;
	size_t bk = size, hd = SS + 1;

	lim = sbrk(0);
	if (!end)
	{
		end = align_ptr(lim);
		first_chunk = end;
	}
	bk += (!((bk + hd) % 8)) ? 0 : 8 - (bk + hd) % 8;
	mem = scan_free(first_chunk, end, bk);
	if (!mem)
	{
		dif = (intptr_t)lim - (intptr_t)end;
		if (((size_t)dif < (bk + hd)) && !expand_limit(bk + hd, dif))
			return (NULL);
		mem = mem_head(end, bk);
	}
	end = (void *)((intptr_t)mem + bk);
	return (mem);
}
