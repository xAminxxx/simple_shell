#include "simple_shell.h"
/**
 * _dup - multiplicate a string
 * @word: the string to multiplicate
 * Return: multiplicated word's pointer 
 */
char *_dup(const char *word)
{
        int len = 0;
        char *result;

        if (word == NULL)
                return (NULL);
        while (*word++)
                len++;
        result = malloc(sizeof(char) * (length + 1));
        if (!result)
                return (NULL);
        for (len++; len--;)
                result[len] = *--word;
        return (result);
}

/**
 * _cpy - copy a word
 * @pasted: the copied txt
 * @copied: the source to copy from 
 * Return: the copied txt's pointer
 */
char *_cpy(char *pasted, char *copied)
{
	int i = 0;

	if (pasted == copied || copied == 0)
		return (pasted);
	while (copied[i])
	{
		pasted[i] = copied[i];
		i++;
	}
	pasted[i] = 0;
	return (pasted);
}


/**
 *_view - prints a str input
 *@txt: the string to be printed
 *
 * Return: Nothing
 */
void _view(char *txt)
{
	int i = 0;

	if (!txt)
		return;
	while (txt[i] != '\0')
	{
		_putchr(txt[i]);
		i++;
	}
}

/**
 * _putchr - stdout the caractere a
 * @a: The character to print
 * Return: On success 1.
 * On error, -1 is returned
 */
int _putchr(char a)
{
	static int i;
	static char buff[W_BUFF_SIZE];

	if (a == BUFF_FLUSH || i >= W_BUFF_SIZE)
	{
		write(1, buff, i);
		i = 0;
	}
	if (a != BUF_FLUSH)
		buff[i++] = a;
	return (1);
}
