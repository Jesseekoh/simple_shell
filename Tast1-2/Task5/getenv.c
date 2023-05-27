#include "main.h"

/**
 * _getenv - get the value of an environment variable
 * @name: the variable name
 * Return: value else NULL
 */
char *_getenv(const char *name)
{
	char *string, *value;
	char **environ_c;

	if (!name)
		return (NULL);

	environ_c = environ;
	while (*environ_c)
	{
		const char *tmp = name;

		string = *environ_c;
		while (*string == *tmp)
		{
			string++;
			tmp++;
			if (*tmp == '\0')
			{
				string++;
				value = string;
				return (value);
			}
		}
		environ_c++;
	}
	return (NULL);
}
