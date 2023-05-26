#include "main.h"

#define BUF_SIZE 1024

size_t _getline(char **lineptr, size_t *n)
{
	size_t new_size = 0;
	size_t index = 0;
	int c;

	while (1)
	{
		c = _getchar();

		if (c == '\n')
		{
			(*lineptr)[index] = '\n';
			index++;
			(*lineptr)[index] = '\0';
			return (index);
		}

		if (c == EOF)
			return (-1);

		(*lineptr)[index] = (char)c;
		index++;

		if (index >= *n)
		{
			new_size += BUF_SIZE;
			*n = new_size;
			*lineptr = _realloc(*lineptr, sizeof(char) * index, new_size);
			if (*lineptr == NULL)
				return (-1);
		}
	}

}

int _getchar(void)
{
	char buffer[BUF_SIZE];
	static ssize_t rd = 0;
	static int bu_p = 0;

       if (bu_p >= rd)
       {
		rd = read(STDIN_FILENO, buffer, BUF_SIZE);
		bu_p = 0;
		if (rd <= 0)
			return (EOF);
       }

	return ((int)buffer[bu_p++]);
}

void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	char *ptr_cpy = (char *)ptr;
	void *new_mem;
	char *new_cpy;

	if (ptr_cpy == NULL)
	{
		ptr_cpy = malloc(new_size);
		return (ptr);
	}

	if (new_size == 0 && ptr_cpy != NULL)
	{
		free(ptr_cpy);
		return(ptr);
	}
	ptr_cpy = ptr;
	new_mem = malloc(new_size);
	if (new_mem == NULL)
		return (NULL);

	new_cpy = new_mem;
	mem_cpy(new_cpy, ptr_cpy, old_size);
	if (new_cpy == NULL)
		return (NULL);

	free(ptr);
	return (new_mem);
}

void *mem_cpy(void *dest, void *src, size_t n)
{
	size_t i;
	char *dest_cpy = (char *)dest;
	char *src_cpy = (char *)src;

	if (dest_cpy == NULL)
		return (NULL);

	for (i = 0; i < n; i++)
		dest_cpy[i] = src_cpy[i];

	return (dest);
}
