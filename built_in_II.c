#include "shell.h"
/**
 * _alias_bin - the alias builtin
 * @inpt: containing arguments to maintain function prototypes
 *  Return: Always 0
 */
int _alias_bin(inpt_t *inpt)
{
	int i = 0;
	char *var = NULL;
	lst_t *nd = NULL;

	if (inpt->argu == 1)
	{
		nd = inpt->alias;
		while (nd)
		{
			print_alias(nd);
			nd = nd->next;
		}
		return (0);
	}
	for (i = 1; inpt->argu[i]; i++)
	{
		var = _chrfind(inpt->argu[i], '=');
		if (var)
			set_alias(inpt, inpt->argu[i]);
		else
			print_alias(node_starts_with(inpt->alias, inpt->argu[i], '='));
	}

	return (0);
}
/**
 * _history_bin - print the history list
 * @inpt: containing arguments to maintain function prototypes.
 *  Return: Always 0
 */
int _history_bin(inpt_t *inpt)
{
	print_list(inpt->history);
	return (0);
}

/**
 * unset_alias_bin - unsets alias to string
 * @inpt: containing arguments to maintain function prototypes.
 * @txt: containing the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias_bin(inpt_t *inpt, char *txt)
{
	char *a, b;
	int ret;

	a = _chrfind(txt, '=');
	if (!a)
		return (1);
	b = *a;
	*a = 0;
	ret = delete_node_at_index(&(inpt->alias),
		get_node_index(inpt->alias, node_starts_with(inpt->alias, txt, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias_bin - sets alias to string
 * @info: containing arguments to maintain function prototypes.
 * @txt: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias_bin(inpt_t *inpt, char *txt)
{
	char *a;

	a = _chrfind(txt, '=');
	if (!a)
		return (1);
	if (!*++a)
		return (unset_alias_bin(inpt, txt));

	unset_alias_bin(inpt, txt);
	return (add_node_end(&(inpt->alias), txt, 0) == NULL);
}

/**
 * print_alias_bin - prints an alias string
 * @nd: the alias nd
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias_bin(lst_t *nd)
{
	char *a = NULL, *b = NULL;

	if (nd)
	{
		a = _chrfind(nd->txt, '=');
		for (b = nd->txt; b <= a; b++)
			_putchar(*b);
		_putchr('\'');
		_view(a + 1);
		_view("'\n");
		return (0);
	}
	return (1);
}
