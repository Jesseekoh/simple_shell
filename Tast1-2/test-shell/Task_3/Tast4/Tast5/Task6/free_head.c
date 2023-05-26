#include "main.h"

void free_head(path_t *head)
{
        path_t *tmp;

        while (head != NULL)
        {
                tmp = head;
                head = head->next;
                free(tmp);
        }
}

