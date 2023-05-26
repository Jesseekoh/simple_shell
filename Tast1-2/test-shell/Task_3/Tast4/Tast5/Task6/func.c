#include "main.h"
/**
* creat_av - creat argument vector
* @read: element read from stdin
* @buffer: string read from stdout
* @av: argument vector
* Return: pointer to an array of string
*/
char **creat_av(char *buffer)
{
	char **av;
	int token, i;
	char *string = NULL, *buffer_copy = NULL;

	buffer_copy = malloc(sizeof(char) * (_strlen(buffer) + 1));
	if (buffer_copy == NULL)
		return (NULL);

	/* make a copy of the buffer */
	_strcpy(buffer_copy, buffer);

	token = av_len(buffer_copy);

	/* allocate memory to contain the argument vector */
	av = malloc(sizeof(char *) * token);
	if (av == NULL)
	{
		free(buffer);
		free(buffer_copy);
		return (NULL);
	}

	string = strtok(buffer, " \n");
	i = 0;
	while (string)
	{
		av[i] = malloc(sizeof(char) * (_strlen(string) + 1));
                if (av[i] == NULL)
                {
                        free(buffer_copy);
                        free(av);
                        return (NULL);
                }
		_strcpy(av[i], string);
		string = strtok(NULL, " \n");
		i++;
	}
	av[i] = NULL;
	free(buffer_copy);
	return (av);
}
