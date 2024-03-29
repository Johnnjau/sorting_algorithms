#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                        in ascending order using insertion sort algorithm
 * listint_t: List integer
 @ list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current;
    listint_t *temp;

    current = (*list)->next;

    while (current != NULL)
    {
        temp = current->next;

        while (current->prev != NULL && current->prev->n > current->n)
        {
            current->prev->next = current->next;
            if (current->next != NULL)
                current->next->prev = current->prev;

            current->next = current->prev;
            current->prev = current->prev->prev;
            current->next->prev = current;

            if (current->prev != NULL)
                current->prev->next = current;
            else
                *list = current;
            print_list(*list);
        }

        current = temp;
    }
}

