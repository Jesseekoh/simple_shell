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


char *get_args(char **arg, char **av);
void free_av(char **av);
char *_strcpy(char *dest, char *string);
void run_cmd(char *argv[], char **arg, char **env);
unsigned int _strlen(char *string);
int av_len(char *buffer);
char **creat_av(char *buffer, ssize_t read);
void prompt(char **arg, char **env);

#endif
