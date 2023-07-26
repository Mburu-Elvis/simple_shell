#include "main.h"
#include <string.h>
#include <stdlib.h>

nodeptr listpath()
{
    nodeptr head = malloc(sizeof(pathlist));
    nodeptr temp = head;
    char *token, *dir, *path;

    path = getenv("PATH");
    dir = strdup(path);
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
    head = temp;
    free(dir);
    return (head);
}