#include <stdio.h>
#include "main.h"

/**
 * main - the main program of the shell
 *
 * Return: 0 on SUCCESS, else status
 */
int main(int argc, char **argv)
{
	size_t n = 0;
	ssize_t j = 0;
	int i = 0, k;
	char *buf = NULL, *token, *delims = " \n", **av;
	pid_t child = 1;

	(void)argc;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "#cisfun$ ", 9);
		j = getline(&buf, &n, stdin);
		if (j == -1)
		{
			free(buf);
			return (1);
		}
		av = malloc(sizeof(char *) * 1024);
		token = strtok(buf, delims);
		while (token != NULL)
		{
			av[i] = strdup(token);
			token = strtok(NULL, delims);
			i++;
		}
		av[i] = NULL;
		child = fork();
		if (child == 0)
		{
			if (execve(av[0], av, NULL) == -1)
				perror(argv[0]);
			_exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
			for (k = 0; av[k] != NULL; k++)
				free(av[k]);
			free(av);
			j = 0;
			i = 0;
		}
	}
	free(buf);
	return (0);
}
