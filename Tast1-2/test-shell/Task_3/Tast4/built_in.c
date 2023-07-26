#include "main.h"

void is_exit(char **av)
{
	if (_strcmp(av[0], "exit") == 0)
	{
		write(0, "exit", 5);
		/*dprintf(STDOUT_FILENO, "%s\n", "exit");*/
		exit(EXIT_SUCCESS);
	}

	return;
}
