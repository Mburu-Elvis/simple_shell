#include "main.h"

/**
 * free_list - function to free a linked list
 * @head: pointer to the first node
 *
 * Return: nothing
 */
void free_list(nodeptr head)
{
	nodeptr temp = NULL;

	while (head != NULL)
	{
		temp = head->next;
		free(head->exe_path);
		free(head);
		head = temp;
	}
}
