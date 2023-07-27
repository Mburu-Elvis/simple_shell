#include "main.h"

/**
 * list_path - create a linked of absolute paths
 *
 * Return: head pointer
 */
nodeptr listpath(void)
{
	nodeptr head = malloc(sizeof(pathlist));
	nodeptr temp = head;
	char *token, *dir, *path;

	path = getenv("PATH");
	dir = path;
	if (dir != NULL)
	{
		token = strtok(dir, ":");
		while (token != NULL)
	{
		head->exe_path = strdup(token);
		if (head->exe_path == NULL)
		return (NULL);
		head->next = malloc(sizeof(pathlist));
		if (head->next == NULL)
		return (NULL);
		head = head->next;
		token = strtok(NULL, ":");
	}
		head->exe_path = NULL;
		head->next = NULL;
	}
	free(dir);
	head = temp;
	return (head);
}
