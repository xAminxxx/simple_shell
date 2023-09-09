#include "main.h"

/**
 * m_free - deallocates the memory.
 * @ss: string of strings
 */

void m_free(char **ss)
{
	char **v = ss;

	if (!ss)
		return;
	while (*ss)
		free(*ss++);
	free(v);
}

/**
 * m_setting - fills a block of memory with a particular value.
 * @m: pointer of the memory
 * @v: value
 * @num: number of bytes to be filled
 * Return: m
 */
char *m_setting(char *m, char v, unsigned int num)
{
	unsigned int count;

	for (count = 0; count < num; count++)
		m[count] = v;
	return (m);
}

/**
 * re_allo - reallocates the memory.
 * @r: pointer.
 * @prev_s: size of the previous memory.
 * @new_s: size of the new memory.
 */
void *re_allo(void *r, unsigned int new_s, unsigned int prev_s)
{
	char *ptr;

	if (!r)
		return (malloc(new_s));
	if (!new_s)
		return (free(r), NULL);
	if (new_s == prev_s)
		return (r);

	ptr = malloc(new_s);
	if (!ptr)
		return (NULL);
	prev_s = prev_s < new_s ? prev_s : new_s;
	while (prev_s--)
		ptr[prev_s] = ((char *)r)[prev_s];
	free(r);
	return (ptr);
}
