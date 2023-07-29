#include "main.h"

/**
 * make_path - function to create an absoulte path
 * @av1: list of tokens
 *
 * Return: on SUCCESS absolute_path, else NULL
 */
char **make_path(char **av1)
{
	nodeptr head, temp;
	char *abs_path;

	if (access(av1[0], F_OK) == 0)
		return (av1);
	head = listpath();
	temp = head;
	while (head->next != NULL && head->exe_path != NULL)
	{
		abs_path = malloc(strlen(head->exe_path) + strlen(av1[0]) + 2);
		strcpy(abs_path, head->exe_path);
		strcat(abs_path, "/");
		strcat(abs_path, av1[0]);
		if (access(abs_path, F_OK) == 0)
		{
			head = temp;
			free_list(head);
			free(av1[0]);
			av1[0] = abs_path;
			return (av1);
		}
		head = head->next;
		free(abs_path);
	}
	head = temp;
	free_list(head);
	return (av1);
}
