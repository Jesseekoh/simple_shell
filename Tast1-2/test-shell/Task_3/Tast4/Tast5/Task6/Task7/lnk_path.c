#include "main.h"

/**
 * link_path - creat a link of all directories in the path variable
 * Return: the head else NULL
 */
void link_path(path_t **head)
{
	char *path;
	path_t *tmp;

	path = _getenv("PATH");
	path = strtok(path, ":");
	while (path)
	{
		path_t *new_node = malloc(sizeof(path_t));
		if (new_node == NULL)
			exit(EXIT_FAILURE);

		new_node->path_dir = path;
		new_node->next = NULL;

		if (*head == NULL)
		{
			*head = new_node;
		}
		else
		{
			tmp = *head;
			while (tmp->next != NULL)
				tmp = tmp->next;

			tmp->next = new_node;

		}
		path = strtok(NULL, ":");
	}
	return;
}
