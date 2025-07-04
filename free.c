#include "malloc.h"



/**
* _free - func
* @ptr: void *
*/
void _free(void *ptr)
{
	if (ptr)
		*((size_t *)((intptr_t)ptr - SS)) = 1;
}
