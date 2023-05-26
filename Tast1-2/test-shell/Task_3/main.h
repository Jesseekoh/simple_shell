#ifndef MAIN_H
#define MAIN_H

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

extern char **environ;

/**
* struct path - structure for the path link list
* @path_dir: Contain each directory form the path
* @next: link to the next path
*/
	typedef struct path
	{
		char *path_dir;
		struct path *next;
	} path_t;

/* All Functions prototype*/
void free_head(path_t *head);
void link_path(path_t **head);
char *process_cmd(char *pathname, path_t *head);
int _strcmp(char *str1, char *str2);
int is_path(char *string);
char *_strcat(char *st1, char *st2);
char *_getenv(const char *name);
char *get_args(char **arg);
void free_av(char **av);
char *_strcpy(char *dest, char *string);
void run_cmd(char *argv[], char **arg, char **env);
unsigned int _strlen(char *string);
int av_len(char *buffer);
char **creat_av(char *buffer);
void prompt(char **arg, char **env);

#endif
