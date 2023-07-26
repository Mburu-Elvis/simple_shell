#include "main.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

extern char **environ;
int main(int argc, char **argv)
{
    size_t n = 0;
    int i = 0, j = 0;
    char *buf = NULL, *token, **av;
    char *delims = " \n", *abs_path = NULL;
    pid_t child = -1;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(1, "#cisfun$ ", 9);
        j = getline(&buf, &n, stdin);
        if (j == -1)
        {c
            return (0);
        }
        av = absolute_path(buf);
        i = 0;
        child = fork();
        if (child == 0)
        {
            if (execve(av[0], av, environ) == -1)
            {
                perror(argv[0]);
            }
        }
        else
        {
            wait(NULL);
        }
    }
    while (av[i] != NULL)
    {
        free(av[i]);
        i++;
    }
    free(buf);
    return (0);
}