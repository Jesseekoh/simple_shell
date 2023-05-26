#include "main.h"

/**
* _strlen - Get the length of a string
* @string: The string to check
* Return: string length or 0 if null
*/
unsigned int _strlen(char *string)
{
	unsigned int len = 0;

	if (!string)
		return (len);

	while (string[len])
		len++;

	return (len);
}
