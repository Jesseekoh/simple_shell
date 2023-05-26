#include "main.h"

void free_head(path_t *head)
{
	path_t *tmp, *next;

	tmp = head;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}
