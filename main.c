#include "main.h"

/**
* main - Entry point
* @argc: argument count
* @argv: argument vector
* @env: environment variable
* Return: always 0
*/
int main(int argc, char **argv, char **env)
{
	if (argc == 1)
		prompt(argv, env);

	return (0);
}
