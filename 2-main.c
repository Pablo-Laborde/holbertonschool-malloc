#include "malloc.h"


int main(void)
{
	int i = 0;
	void *ptrs[3];

	for (; i < 3; i++)
	{
		ptrs[i] = _malloc(8192);
		printf("%d: %p\n", i, ptrs[i]);
	}
	for (i = 0; i < 3; i++)
		_free(ptrs[i]);
	for (i = 0; i < 3; i++)
	{
		ptrs[i] = _malloc(8192);
		printf("%d: %p\n", i, ptrs[i]);
	}
	for (i = 0; i < 3; i++)
		_free(ptrs[i]);
	return (0);
}