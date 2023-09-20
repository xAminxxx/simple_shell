#include "simple_shell.h"

/**
 * ptr_free - frees the pointer and returns the address to NULL.
 * @p: pointer's address
 * Return: 1 if it is free, 0 if not.
 */
int ptr_free(void **p)
{
	if (*p && p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}
