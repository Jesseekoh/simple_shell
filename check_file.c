#include "main.h"

/**
 * check_file - check if a file is valid
 * @av: argument vector
 * @arg: command line argument
 * @env: environmental variablei
 * Return: 0(success) 1(error)
 */
int check_file(char **av, char **arg, char **env)
{
	struct stat st;

	if (stat(av[0], &st) == 0)
	{
		run_cmd(av, arg, env);
		return (0);
	}
	else
	{
		perror(arg[0]);
		return (1);
	}
}
