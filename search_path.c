#include "main.h"

/**
* absolute_path - searches for absolute path.
* @path: char pointer to be searched
* Return: a char pointer.
*/
char **absolute_path(char *path)
{
	nodeptr head = malloc(sizeof(pathlist));
	char **av = malloc(sizeof(char *) * BUFSIZE), *path1 = strdup(path),
	*token, *delims = " \n";
	char *abs_path = NULL;
	nt i = 0, status = 0;

	token = strtok(path1, delims);
	if (strcmp(token, "exit") == 0)
		exit(0);
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
		head = listpath();
		while (head != NULL && head->exe_path != NULL)
		{
			abs_path = malloc(strlen(head->exe_path) + strlen(token) + 2);
			strcpy(abs_path, head->exe_path);
			strcat(abs_path, "/");
			strcat(abs_path, token);
			if (access(abs_path, F_OK) == 0)
			{
				av[i] = abs_path;
				status = 1;
				i++;
				break;
			}
			head = head->next;
		}
		if (status == 0)
		{
			av[i] = strdup(token);
			i++;
		}
		token = strtok(NULL, delims);
		while (token != NULL)
		{
			av[i] = strdup(token);
			token = strtok(NULL, delims)
			i++;
		}
	}
	av[i] = NULL;
	return (av);
}
