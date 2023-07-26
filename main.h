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

void free_av(char **av);
char *_strcpy(char *dest, char *string);
void run_cmd(char *argv[], char **arg, char **env);
unsigned int _strlen(char *string);
int av_len(char *buffer);
char **creat_av(char **av, char *buffer, ssize_t read);
void prompt(char **arg, char **env);
void is_file(char **av, char *buffer, char **arg);
int is_space(char *args);

#endif
