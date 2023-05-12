#include "main.h"

/**
 * execute - Execute command
 * @arg: argument passed to the program
 * @argv: argument vector
 */
void execute(char **arg, char **argv)
{
	int wstatus;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(arg[0], arg, NULL) == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&wstatus);
	}
}
/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	char *arg[] = {NULL, NULL};
	int i;
	char *string = NULL;
	size_t n = 0;

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "C_shell$ ", 9);

		string = malloc(sizeof(char) * n);
		if (string == NULL)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
		if (getline(&string, &n, stdin) == -1)
		{
			free(string);
			exit(EXIT_SUCCESS);
		}

		i = 0;
		while (string[i])
		{
			if (string[i] == '\n')
				string[i] = 0;

			i++;
		}
		arg[0] = string;

		execute(arg, argv);
		free(string);
	}
	free(string);
	return (0);
}
