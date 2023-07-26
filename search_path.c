#include <sys/stat.h>
#include <unistd.h>
#include "main.h"
#include <stdlib.h>

char **absolute_path(char *path)
{
    nodeptr head = malloc(sizeof(pathlist));
    struct stat ffile;
    char **av = malloc(sizeof(char *) * BUFSIZE), *path1 = strdup(path), *token, *delims = " \n";
    char *abs_path = NULL;
    int i = 0, status = 0;

    token = strtok(path1, delims);
    if (strcmp(token, "exit"))
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
        while (head != NULL)
        {
            abs_path = malloc(strlen(head->exe_path) + strlen(token) + 2);
            strcpy(abs_path, head->exe_path);
            strcat(abs_path, "/");
            strcat(abs_path, token);
            if (access(abs_path, F_OK) == 0)
            {
                av[i] = abs_path;
                status = 1;
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
            token = strtok(NULL, delims);
            i++;
        }
    }
    av[i] = NULL;

    return (av);
}
//     if (access(path1, F_OK) == 0)
//         return (path1);
//     else
//     {
//         if (head != NULL)
//         {
//             head = listpath();
//             while (head != NULL)
//             {
//                 abs_path = strdup(head->exe_path);
//                 abs_path = strcat(abs_path, "/");
//                 abs_path = strcat(abs_path, path1);
//                 if (stat(abs_path, &ffile) == 0)
//                 {
//                     return (abs_path);
//                 }
//                 else
//                     head = head->next;
//                 if (head->exe_path == NULL && head->next == NULL)
//                     break;
//             }
//         }
//     }

//     return (NULL);
// }