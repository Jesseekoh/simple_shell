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
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "#cisfun$ ", 9);

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
		if (isatty(STDIN_FILENO) == 0)
			is_file(av, buffer, arg);

		run_cmd(av, arg, env);
	}
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
		exit(EXIT_FAILURE);
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
