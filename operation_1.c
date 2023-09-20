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

/**
 * str_to_int - to convert a string to an integer
 * @str: the string to convert
 * Return: 0 if there is no integers int the string, result otherwise
 */
int str_to_int(char *str)
{
	int i, s = 1, f = 0, result;
	unsigned int res = 0;

	for (i = 0; str[i] != '\0' && f != 2; i++)
	{
		if (str[i] == '-')
			s *= -1;
		if (str[i] >= '0' && str[i] <= '9')
		{
			f = 1;
			res *= 10;
			res += (str[i] - '0');
		}
		else if (f ==1)
			f = 2;
	}

	if (s == 1)
		result = -res;
	else
		result = res;
	
	return (result);
}

/**
 * check_alpa - checks if the character is alphabetic 
 * @ch: the character to check
 * Retunr: 1 if the character is alphabetic or 0 if it isn't
 */
int check_alpha(char ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')
			return (1);
	else
			return (0);
}
