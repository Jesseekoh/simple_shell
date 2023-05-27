#include "main.h"

/**
 * process_cmd - processes command and returns the path of
 * the command
 * @pathname: pathname
 * @head: head
 * Return: string
 */
char *process_cmd(char *pathname, path_t *head)
{
	DIR *dir;
	char *path = pathname, *result, *dir_path;
	struct dirent *entity;
	path_t *tmp;

	if (is_path(pathname) == 0)
		return (pathname);

	tmp = head;
	while (tmp)
	{
		path = pathname;
		dir = opendir(tmp->path_dir);
		if (dir != NULL)
		{
			entity = readdir(dir);

			dir_path = tmp->path_dir;
			while (entity != NULL)
			{
				if (_strcmp(entity->d_name, path) == 0)
				{

					result = _strcat(dir_path, path);
					closedir(dir);
					return (result);
				}

				entity = readdir(dir);
			}
			closedir(dir);
		}
		tmp = tmp->next;
	}
	return (path);
}
