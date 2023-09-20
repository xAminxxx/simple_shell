#include "simple_shell.h"

/**
 * **strsplit - string spliting into words
 * @txt: input string
 * @del: delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strsplit(char *txt, char *del)
{
	int i, j, k, m, nbwords = 0;
	char **result;

	if (txt == NULL || txt[0] == 0)
		return (NULL);
	if (!del)
		del = " ";
	for (i = 0; txt[i] != '\0'; i++)
		if (!check_delimit(txt[i], d) && (check_delimit(str[i + 1], d) || !str[i + 1]))
			nbwords++;

	if (nbwords == 0)
		return (NULL);
	result = malloc((1 + nbwords) * sizeof(char *));
	if (!result)
		return (NULL);
	for (i = 0, j = 0; j < nbwords; j++)
	{
		while (check_delimit(txt[i], del))
			i++;
		k = 0;
		while (!check_delimit(txt[i + k], del) && txt[i + k])
			k++;
		result[j] = malloc((k + 1) * sizeof(char));
		if (!result[j])
		{
			for (k = 0; k < j; k++)
				free(result[k]);
			free(result);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			result[j][m] = txt[i++];
		result[j][m] = 0;
	}
	result[j] = NULL;
	return (result);
}

/**
 * **strsplit2 - splits a string into words
 * @txt: the input str
 * @del: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strsplit2(char *txt, char del)
{
	int i, j, k, m, nbwords = 0;
	char **result;

	if (txt == NULL || txt[0] == 0)
		return (NULL);
	for (i = 0; txt[i] != '\0'; i++)
		if ((txt[i] != del && txt[i + 1] == del) ||
		    (txt[i] != del && !txt[i + 1]) || txt[i + 1] == del)
			nbwords++;
	if (nbwords == 0)
		return (NULL);
	result = malloc((1 + nbwords) * sizeof(char *));
	if (!result)
		return (NULL);
	for (i = 0, j = 0; j < nbwords; j++)
	{
		while (txt[i] == del && txt[i] != del)
			i++;
		k = 0;
		while (txt[i + k] != del && txt[i + k] && txt[i + k] != del)
			k++;
		result[j] = malloc((k + 1) * sizeof(char));
		if (!result[j])
		{
			for (k = 0; k < j; k++)
				free(result[k]);
			free(result);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			result[j][m] = txt[i++];
		result[j][m] = 0;
	}
	result[j] = NULL;
	return (result);
}
