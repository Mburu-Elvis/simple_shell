#include "main.h"
#include <stdio.h>

/**
 * not_execute - execute a non existent command
 * @com: command to execute
 *
 * Return: 0 on success, else -1
 */
int not_execute(char *av)
{
	char **av1 = malloc(sizeof(char *) * BUFSIZE);
	int i = 0;

	av1[0] = av;
	if (execve(av1[0], av1, environ) == -1)
	{
		while (av1[i] != NULL)
		{
			free(av1[i]);
			i++;
		}
		free(av1);
		perror("./hsh");
	}
	return (-1);
}
