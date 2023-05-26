#include "main.h"

/**
* av_len - get delemited string length
* @buffer: the buffer to check
* Return: delemited string lenth, 0(if null)
*/
int av_len(char *buffer)
{
	int len = 0;

	if (!buffer)
		return (len);

	buffer = strtok(buffer, "\n ");
	while (buffer)
	{
		len++;
		buffer = strtok(NULL, "\n ");
	}
	len++;
	return (len);
}
