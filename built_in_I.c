#include "simple_shell.h"
/**
 * _changer - changes the current directory of the process
 * @inpt: maintaining constant function prototype.
 *  Return: null
 */
int _changer(inpt_t *inpt)
{
	char **arg;

	arg = info->argu;
	_puts("the function is not implemented yet \n");
	if (0)
		_puts(*arg);
	return (0);
}
/**
 * _quit - leave the shell
 * @inpt: maintaining constant function prototype.
 *  Return: quit with a status
 *         (0) if info.argu[0] != "exit"
 */
int _quit(inpt_t *inpt)
{
	int quitchecking;

	if (inpt->argu[1])
	{
		quitchecking = _erratoi(inpt->argu[1]);
		if (exitcheck == -1)
		{
			inpt->stat = 2;
			print_error(inpt, "invaliable number: ");
			_eputs(inpt->argu[1]);
			_eputchar('\n');
			return (1);
		}
		inpt->nb_err = _erratoi(inpt->argu[1]);
		return (-2);
	}
	inpt->nb_err = -1;
	return (-2);
}

/**
 * _cd_changer - changes the current directory of the process
 * @inpt: maintaining constant function prototype
 *  Return: Always 0
 */
int _cd_changer(inpt_t *inpt)
{
	char *res, *direct, buff[1024];
	int ret;

	res = getcwd(buff, 1024);
	if (!res)
		_view("failure msg here<<\n");
	if (!inpt->argu[1])
	{
		direct = _getenv(inpt, "HOME=");
		if (!direct)
			ret = chdir((direct = _getenv(inpt, "PWD=")) ? direct : "/");
		else
			ret = chdir(direct);
	}
	else if (_strcmp(inpt->argu[1], "-") == 0)
	{
		if (!_getenv(inpt, "OLDPWD="))
		{
			_view(res);
			_putchr('\n');
			return (1);
		}
		_view(_getenv(info, "OLDPWD=")), _putchr('\n');
		ret = chdir((direct = _getenv(inpt, "OLDPWD=")) ? direct : "/");
	}
	else
		ret = chdir(inpt->argu[1]);
	if (ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(inpt->argu[1]), _eputchr('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
