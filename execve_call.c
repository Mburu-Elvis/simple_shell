#include "main.h"
#include <stdio.h>

/**
 * execve_call - execute viable commands
 * @av: list of arguments
 *
 * Return: 0 on success, else -1
 */
int execve_call(char **av)
{
	pid_t child = fork();

	if (child == 0)
	{
		execve(av[0], av, environ);
	}
	else
		wait(NULL);
	return (0);
}
