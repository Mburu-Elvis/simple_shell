#include <stdio.h>
#include "main.h"

/**
 * main - the main program of the shell
 * @argc: number of arguments
 * @argv: array of strings of arguments passed
 *
 * Return: 0 on SUCCESS, else status
 */
int main(int argc, char **argv)
{
	size_t n = 0;
	int i = 0, j = 0;
	char *buf = malloc(sizeof(char) * 1024), *token = NULL;
	char *delims = " \n", **av;
	pid_t child = 1;

	(void)argc;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "#cisfun$ ", 9);
		j = getline(&buf, &n, stdin);
		if (j == -1)
			return (0);
		av = malloc(sizeof(char) * 1024);
		token = strtok(buf, delims);
		av[i] = strdup(token);
		i++;
		av[i] = NULL;
		i = 0;
		child = fork();
		if (child == 0)
		{
			if (execve(av[0], av, environ) == -1)
				perror(argv[0]);
			while (av[i] != NULL)
			{
				free(av[i]);
				i++;
			}
		}
		else
			wait(NULL);
	}
	free(buf);
	return (0);
}
