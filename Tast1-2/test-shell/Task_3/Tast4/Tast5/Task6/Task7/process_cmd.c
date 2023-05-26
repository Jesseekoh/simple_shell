#include "main.h"

char *process_cmd(char *pathname, path_t *tmp)
{
	DIR *dir;
	char *path = pathname, *result, *dir_path;
	struct dirent *entity;

	if (is_path(pathname) == 0)
		return (pathname);

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
