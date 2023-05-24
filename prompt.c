#include "main.h"

/**
* prompt - prompt the shell for command
* @arg: argument vector
* @env: environment variable
*/
void prompt(char **arg, char **env)
{
	char **av;
	char *buffer = NULL;
	size_t n = 0;
	ssize_t read;
	int i;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "#cisfun$ ", 9);

		/* allocate memory for the buffer */
		read = getline(&buffer, &n, stdin);
		if (read == -1)
		{
			free(buffer);
			free_av(av);
			exit(EXIT_SUCCESS);
		}
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
				buffer[i] = 0;

			i++;
		}
		av = creat_av(av, buffer, read);
		if (av == NULL)
		{
			free(buffer);
			free_av(av);
			exit(EXIT_FAILURE);
		}

		run_cmd(av, arg, env);
	}
	free(buffer);
	free_av(av);
}

/**
* run_cmd - execute the command
* @av: argument vector
* @arg: argument vector form the bash shell
* @env: environment vector
*/
void run_cmd(char **av, char **arg, char **env)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror(arg[0]);
		exit(127);
	}
	if (pid == 0)
	{
		if (execve(av[0], av, env) == -1)
		{
			perror(arg[0]);
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}
}
/**
* free_av - free argument vector
* @av: argument vector
*/
void free_av(char **av)
{
	int i = 0;

	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
