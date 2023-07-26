#include <stdio.h>
#include "main.h"

/**
 * main - the main program of the shell
 *
 * Return: 0 on SUCCESS, else status
 */
int main(void)
{
	size_t n = 0;
	int i = 0, j = 0, k;
	char *buf = NULL, *token, *delims = " \n", **av;
	pid_t child = 1;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "#cisfun$ ", 9);
		j = getline(&buf, &n, stdin);
		if (j == -1)
		{
			free(buf);
			break;
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
		i = 0;
		child = fork();
		if (child == 0)
		{
			if (execve(av[0], av, environ) == -1)
				perror("./hsh");
		}
		else
			wait(NULL);
		for (k = 0; av[k] != NULL; k++)
			free(av[i]);
		free(av);
	}
	free(buf);
	return (0);
}
