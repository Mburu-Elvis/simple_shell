#include "main.h"

/**
 * print_env - function to print envitonment
 *
 * Return: nothing
 */
void print_env(void)
{
	char **env = environ;
	int i = 0;

	while (env[i] != NULL)
	{
		write(1, env[i], strlen(env[i]));
		write(1, "\n", 1);
		i++;
	}
}
