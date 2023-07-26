#include  <stdio.h>
#include "main.h"

int main(int argc, char **argv)
{
    size_t n = 0;
    int i = 0, j = 0;
    char *buf = NULL,  **av;
    pid_t child = -1;

    (void)argc;
    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(1, "#cisfun$ ", 9);
        j = getline(&buf, &n, stdin);
        if (j == -1)
        {
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
	    while (av[i] != NULL)
	    {
		    free(av[i]);i++;
	    }
	    free(av);
        }
        else
        {
            wait(NULL);
        }
    }
    free(buf);
    return (0);
}
