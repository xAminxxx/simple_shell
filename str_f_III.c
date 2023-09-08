#include "simple_shell.h"
/**
 **_limconcat - limited concatenation
 *@txt1: 1st string
 *@txt2: 2nd string
 *@max: maximum bytes to be used
 *Return: the concatenated string
 */
char *_limconcat(char *txt1, char *txt2, int max)
{
        int i, j;
        char *a = txt1;

        i = 0;
        j = 0;
        while (txt1[i] != '\0')
                i++;
        while (txt2[j] != '\0' && j < n)
        {
                txt1[i] = txt2[j];
                i++;
                j++;
        }
        if (j < max)
                txt1[i] = '\0';
        return (a);
}
/**
 **_limcpy - limited copies
 *@txt2: the destination to be pasted in
 *@txt1: the source txt 
 *@max: maximum copied txt
 *Return: the copied txt
 */
char *_limcpy(char *txt2, char *txt1, int max)
{
	int i, j;
	char *a = txt2;

	i = 0;
	while (txt1[i] != '\0' && i < max - 1)
	{
		txt2[i] = txt1[i];
		i++;
	}
	if (i < max)
	{
		j = i;
		while (j < max)
		{
			txt2[j] = '\0';
			j++;
		}
	}
	return (a);
}

/**
 **_chrfind - find a char in a string 
 *@txt: the string 
 *@chr: the character to look for
 *Return: return the pointer to the memory txt
 */
char *_chrfind(char *txt, char chr)
{
	do {
		if (*txt == chr)
			return (txt);
	} while (*txt++ != '\0');

	return (NULL);
}
