#include "main.h"

void is_exit(char **av)
{
	if (_strcmp(av[0], "exit") == 0)
	{
		dprintf(STDOUT_FILENO, "%s\n", "exit");
		exit(EXIT_SUCCESS);
	}

	return;
}
