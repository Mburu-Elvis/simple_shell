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
	char *abs_path1 = NULL;
	int i = 0;

	token = strtok(path1, delims);
	if (strcmp(token, "exit") == 0)
	{
		free(patih1);
		free(abs_path1);
		free(av);
		exit(0);
	}
	if (access(token, F_OK) == 0)
	{
		while (token != NULL)
		{
			av[i] = strdup(token);
			token = strtok(NULL, delims);
			i++;
		}
	}
	else
	{
		abs_path1 = make_path(token);
		token = strdup(abs_path1);
		while (token != NULL)
		{
			av[i] = strdup(token);
			if (strcmp(token, abs_path1) == 0)
				free(token);
			token = strtok(NULL, delims);
			i++;
		}
	}
	av[i] = NULL;
	free(abs_path1);
	free(path1);
	return (av);
}
