#include "malloc.h"



#define SS sizeof(size_t)


/**
* _free - func
* @ptr: void *
*/
void _free(void *ptr)
{
	void *aux = NULL;

	if (ptr)
	{
		aux = (void *)((intptr_t)ptr - SS);
		*((size_t *)aux) = 0;
	}
}
