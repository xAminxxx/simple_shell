#include "simple_shell.h"

/**
 * check_delimit - checks if the character is delimeter
 * @ch: the character to check
 * @del: the delimeter
 * Return: 1 if true or 0 if false
 */
int check_delimit(char ch, char *del)
{
	while (*del)
		if (*del++ == ch)
			return (1);
	return (0);
}

