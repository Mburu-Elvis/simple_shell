#include "main.h"

/**
* absolute_path - searches for absolute path.
* @path: char pointer to be searched
* Return: a char pointer to a linked list
*/
char **absolute_path(char *path)
{
	char **av = malloc(sizeof(char *) * BUFSIZE), *path1 = strdup(path),
	*token, *delims = " \n";
	int i = 0;

	token  = strtok(path1, delims);
	while (token != NULL)
	{
		av[i] = token;
		token  = strtok(NULL, delims);
		i++;
	}
	av[i] = NULL;
	handle_builtins(av);
	return (av);
}
