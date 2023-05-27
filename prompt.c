#include "main.h"

/**
* prompt - prompt the shell for command
* @arg: argument vector
* @env: environment variable
*/
void prompt(char **arg, char **env)
{
	char **av = NULL, *buffer = NULL, *tmp;
	path_t *head = NULL;

	link_path(&head);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		buffer = get_args(arg, head);
		av = creat_av(buffer);
		if (av == NULL)
		{
			free_av(av);
			free(buffer);
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
					run_cmd(av, arg, env);
				}
			}
		}
	free_av(av);
	free(buffer);
	}
}

/**
 * get_args - get argument passed to the program
 * @arg: argument passed to the progam
 * @head: first node for the path link list
 * Return: buffer
 */
char *get_args(char **arg, path_t *head)
{
	char *buffer = NULL;
	ssize_t read;
	size_t n = 0;

	/* allocate memory for the buffer */
	buffer = malloc(sizeof(char) * n);
	if (buffer == NULL)
	{
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
		free_av(av);
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
