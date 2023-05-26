#include "main.h"

/**
 * is_space - check if argument is space
 * @args: argument
 * Return: 0(success) 1(failure)
 */
int is_space(char *args)
{
	if (args == NULL)
		return (0);

	return (1);
}

/**
 * is_file - check if the file exits
 * @av: name of file and its agument
 * @buffer: text from getline
 * @arg: command line argument
 */
void is_file(char **av, char *buffer, char **arg)
{
	struct stat st;

	if (stat(av[0], &st) == -1)
	{
		free(buffer);
		free_av(av);
		perror(arg[0]);
		exit(127);
	}
}
