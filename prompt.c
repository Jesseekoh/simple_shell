#include "main.h"

/**
* prompt - prompt the shell for command
* @arg: argument vector
* @env: environment variable
*/
void prompt(char **arg, char **env)
{
	char **av, *tmp;
	size_t n = 0;
	ssize_t read;
	path_t *head = NULL;

	link_path(&head);
	while (1)
	{
		char *buffer = NULL;

		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		/* allocate memory for the buffer */
		read = getline(&buffer, &n, stdin);
		if (read == -1)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}

		av = creat_av(av, buffer, read);
		if (av == NULL)
		{
			free(buffer);
			free_av(av);
			exit(EXIT_FAILURE);
		}
		
		if (is_space(av[0]) == 1)
		{
			is_exit(av, buffer, head);
			if (is_env(av) != 0)
			{
				if (is_path(av[0]) == 1)
				{
					tmp = av[0];
					av[0] = process_cmd(av[0], head);
					if (isatty(STDIN_FILENO) == 0)
						is_file(av, buffer, arg);
					if (check_file(av, arg, env) == 0)
						free(tmp);
				}
				else
				{
					if (isatty(STDIN_FILENO) == 0)
						is_file(av, buffer, arg);
					run_cmd(av, arg, env);
				}
			}
		}
		free(buffer);
		free_av(av);
	}
}

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
