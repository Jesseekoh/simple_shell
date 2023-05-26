#include "main.h"

void is_exit(char **av, path_t *head, char *buffer)
{
	if (_strcmp(av[0], "exit") == 0)
	{
		free(av);
		free(buffer);
		free_head(head);
		dprintf(STDOUT_FILENO, "%s\n", "exit");
		exit(EXIT_SUCCESS);
	}

	return;
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
