#include "main.h"

/**
 * is_exit - check if command is exit
 * @av: argument vector
 * @buffer: argument passed to the progamm
 * @head: first node in the path link list
 */
void is_exit(char **av, char *buffer, path_t *head)
{
	if (_strcmp(av[0], "exit") == 0)
	{
		free_head(head);
		free(buffer);
		exit(EXIT_SUCCESS);
	}

}

int is_env(char **av)
{
	char **env_c;

	if (_strcmp(av[0], "env") == 0)
	{
		env_c = environ;
		while (*env_c)
		{
			dprintf(STDOUT_FILENO, "%s\n", *env_c);
			env_c++;
		}

		return (0);
	}

	return (1);
}
