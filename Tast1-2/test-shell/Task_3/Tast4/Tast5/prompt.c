#include "main.h"

/**
* prompt - prompt the shell for command
* @arg: argument vector
* @env: environment variable
*/
void prompt(char **arg, char **env)
{
	char **av = NULL;
	char *buffer = NULL;
	path_t *head = NULL, *tmp;

	link_path(&head);
	while (1)
	{
		tmp = head;
		if (isatty(STDIN_FILENO))
			write(1, "#cisfun$ ", 9);

		buffer = get_args(arg, head);

		av = creat_av(buffer);
		if (av == NULL)
		{
			free_head(head);
			free(buffer);
			exit(EXIT_FAILURE);
		}

		is_exit(av, head, buffer);
		if (is_env(av) != 0)
		{
			av[0] = process_cmd(av[0], tmp);
			check_file(av, arg, env);
			free(av[0]);
		}
		free(av);
		free(buffer);
	}
}

/**
 * get_args - get argument passed to the program
 * @arg: argument passed to the progam
 * @av: argument vector
 * Return: buffer
 */
char *get_args(char **arg, path_t *head)
{
	char *buffer = NULL;
	ssize_t read;
	size_t n = 0;
	int i;

	/* allocate memory for the buffer */
	buffer = malloc(sizeof(char) * n);
	if (buffer == NULL)
	{
		free(buffer);
		free_head(head);
		perror(arg[0]);
		exit(EXIT_FAILURE);
	}

	/* get argument */
	read = getline(&buffer, &n, stdin);
	if (read == -1)
	{
		free_head(head);
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			buffer[i] = 0;

		i++;
	}
	return (buffer);
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
			exit(EXIT_FAILURE);
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

/**
 * check_file - check if a file is valid
 * @av: argument vector
 * @arg: command line argument
 * @env: environmental variable
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
