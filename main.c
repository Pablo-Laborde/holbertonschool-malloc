#include "malloc.h"



/**
* main - func
* Return: int
*/
int main(void)
{
	void *pos = NULL, *lim = NULL, *dif = NULL, *lim2 = NULL;

	lim = sbrk(0);
	printf("current break: %p\n", lim);

	pos = naive_malloc(24);
	dif = (void *)((intptr_t)pos - (intptr_t)lim);
	printf("pos: %p\n", (void *)dif);

	lim2 = sbrk(0);
	printf("current break: %p\n", (void *)((intptr_t)lim2 - (intptr_t)lim));

	pos = naive_malloc(24);
	dif = (void *)((intptr_t)pos - (intptr_t)lim);
	printf("pos: %p\n", (void *)dif);

	pos = naive_malloc(24);
	dif = (void *)((intptr_t)pos - (intptr_t)lim);
	printf("pos: %p\n", (void *)dif);

	return(0);
}
