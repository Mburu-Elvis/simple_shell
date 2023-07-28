#ifndef _MAIN_H
#define _MAIN_H

#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

#define BUFSIZE 1024
typedef struct pathlist *nodeptr;

/**
* struct pathlist - structure for path.
* @exe_path: absolute path.
* @next: the next node pointer.
*/
struct pathlist
{
	char *exe_path;
	nodeptr next;
};
typedef struct pathlist pathlist;
nodeptr listpath(void);
char **absolute_path(char *path);
void free_list(nodeptr head);
int execve_call(char **av);
int non_path(char *str);
char *make_path(char *str);

#endif
