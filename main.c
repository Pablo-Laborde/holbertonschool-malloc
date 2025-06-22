#include "malloc.h"



/**
* write_to - func
* @ptr: void *
*/
void write_to(void *ptr)
{
	char *str = (char *)ptr, *hol = "Holberton";
	int i = 0;

	for (; hol[i]; i++)
		str[i] = hol[i];
}


/**
* main - func
* Return: int
*/
int main(void)
{
	void *mem = NULL, *lim = NULL;
	intptr_t pos = 0, cur_break = 0, start = 0;

	lim = sbrk(0);
	printf("beginning: %p\n\n", lim);
	start = (intptr_t)sbrk(0) - (intptr_t)lim;

	mem = naive_malloc(16);
	write_to(mem);
	cur_break = (intptr_t)sbrk(0) - (intptr_t)lim;
	pos = (intptr_t)mem - (intptr_t)lim - start;
	printf("%#010lx -> %s\n", pos, (char *)mem);
	printf("current break: %p\n", (void *)cur_break);

	mem = naive_malloc(16);
	write_to(mem);
	cur_break = (intptr_t)sbrk(0) - (intptr_t)lim;
	pos = (intptr_t)mem - (intptr_t)lim - start;
	printf("%#010lx -> %s\n", pos, (char *)mem);
	printf("current break: %p\n", (void *)cur_break);

	mem = naive_malloc(16);
	write_to(mem);
	cur_break = (intptr_t)sbrk(0) - (intptr_t)lim;
	pos = (intptr_t)mem - (intptr_t)lim - start;
	printf("%#010lx -> %s\n", pos, (char *)mem);
	printf("current break: %p\n", (void *)cur_break);

	mem = naive_malloc(16);
	write_to(mem);
	cur_break = (intptr_t)sbrk(0) - (intptr_t)lim;
	pos = (intptr_t)mem - (intptr_t)lim - start;
	printf("%#010lx -> %s\n", pos, (char *)mem);
	printf("current break: %p\n", (void *)cur_break);


	return (0);
}
