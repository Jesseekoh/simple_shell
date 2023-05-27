#include "main.h"

/**
 * free_head - free linked list head
 * @head: head of linked list
 * Return: void
 */

void free_head(path_t *head)
{
	path_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
