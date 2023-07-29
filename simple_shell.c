#include  <stdio.h>
#include "main.h"

/**
* main - min function
*
* Return: 0
*/
int main(void)
{
	size_t n = 0;
	int j = 0, i = 0;
	char *buf = NULL,  **av1;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "#cisfun$ ", 9);
		j = getline(&buf, &n, stdin);
		if (j == -1)
		{
			free(buf);
			return (0);
		}
		av1 = absolute_path(buf);
		av1 = make_path(av1);
		if (av1 != NULL)
		{
			execve_call(av1);
		}
		for (i = 0; av1[i] != NULL; i++)
			free(av1[i]);
		free(av1);
	}
	free(buf);
	return (0);
}
