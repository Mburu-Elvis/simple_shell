#include "main.h"

/**
 * make_path - function to create an absoulte path
 * @str: token to create an absolute path if present
 *
 * Return: on SUCCESS absolute_path, else NULL
 */
char *make_path(char *str)
{
        nodeptr head, temp;
	char *abs_path;

        head = listpath();
        temp = head;

        while (head->next != NULL && head->exe_path != NULL)
        {
                abs_path = malloc(strlen(head->exe_path) + strlen(str) + 2);
                strcpy(abs_path, head->exe_path);
                strcat(abs_path, "/");
                strcat(abs_path, str);
                if (access(abs_path, F_OK) == 0)
                {
                        head = temp;
                        free_list(head);
                        return (abs_path);
                }
                head = head->next;
                free(abs_path);
        }
	head = temp;
	free_list(head);
	return (str);
}
