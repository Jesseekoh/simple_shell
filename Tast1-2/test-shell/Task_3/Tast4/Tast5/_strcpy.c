#include "main.h"

/**
* _strcpy - copy a string
* @string: string to copy
* @dest: destination string
* Return: pointer to the copied string or Null
*/
char *_strcpy(char *dest, char *string)
{
	int i;

	if (!string)
		return (NULL);


	i = 0;
	while (string[i])
	{
		dest[i] = string[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
