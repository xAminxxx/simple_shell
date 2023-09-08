#include "simple_shell.h"

/**
 * com_str - compare two strings
 * @str1: string 1
 * @str2: string 2
 * Return: negative, positive or zero
 */
int com_str(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}
/**
 * length_str - it prints the string's length
 * @str: string
 * Return: number presenting string's length.
 */
int length_str(char *str)
{
	int l = 0;

	if (!str)
		return (0);
	while (*str++)
		l++;
	return (l);
}

/**
 * concat_str -function that concatenates two strings
 * @destination: the destination buff
 * @source: the source buff
 * Return: pointer
 */
char *concat_str(char *destination, char *source)
{
	char *dest = destination;

	while (*destination)
		destination++;
	while (*source)
		*destination++ = *source++;
	*destination = *source;
	return (dest);
}

/**
 * check_start - checks if substring starts with hay
 * @hay: string
 * @substring: the string to find
 * Return: NULL or the address of next char of hay.
 */
int check_start(const char *substring, const char *hay)
{
	while (*substring)
		if (*substring++ != *hay++)
			return (NULL);
	return ((char *)hay);
}
