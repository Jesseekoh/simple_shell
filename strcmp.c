#include "main.h"

int _strcmp(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] == str2[i])
	{
		i++;

		if ((str1[i] == '\0') && (str2[i] == '\0'))
			return (0);

	}
	return (1);
}

int is_path(char *string)
{
	while (*string)
	{
		if (*string == '/')
			return (0);

		string++;
	}
	return (1);
}
/**
 * _strcat - concatenate two string with a backslash at middle
 * @st1: first string
 * @st2: second string
 * Return: catenated string
 */
char *_strcat(char *st1, char *st2)
{
	char *result;
	int len, i , j;

	len = _strlen(st1) + _strlen(st2);

	result = malloc(sizeof(char) * (len + 2));
	if (result == NULL)
	{
		return (NULL);
	}

	for (i = 0; st1[i]; i++)
		result[i] = st1[i];

	result[i] = '/';

	i += 1;
	for (j = 0; st2[j]; i++, j++)
		result[i] = st2[j];

	result[i] = '\0';
	return (result);	
}
