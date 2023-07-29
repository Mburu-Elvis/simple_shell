#include "main.h"

/**
 * handle_builtins - function to handle built in commands
 * @av: list of tokens
 *
 * Return: nothing
 */
void handle_builtins(char **av)
{
	int opt = 0;

	if (strcmp(av[0], "exit")  == 0)
	{
		if (av[1] != NULL)
			opt = atoi(av[1]);
		exit(opt);
	}
	if (strcmp(av[0], "env") == 0)
	{
		print_env();
	}
}
