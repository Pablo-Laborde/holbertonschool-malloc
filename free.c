#include "malloc.h"



#define SS sizeof(size_t)



/**
* _free - func
* @ptr: void *
*/
void _free(void *ptr)
{
	if (ptr)
		*((char *)((intptr_t)ptr - 1)) = 1;
}
