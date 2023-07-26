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

struct pathlist
{
    char *exe_path;
    nodeptr next;
};
typedef struct pathlist pathlist;
nodeptr listpath();
char **absolute_path(char *path);

#endif
