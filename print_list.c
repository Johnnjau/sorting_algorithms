#include <stdio.h>
#include "sort.h"

/**
 * print_list - prints the elements of a linked list of integers
 *
 * @list: pointer to the head of the linked list
 *
 * Return: void
 */
void print_list(const listint_t *list)
{
	int counter = 0;

	while (list != NULL)
	{
		if (counter > 0)
		{
			printf(", ");
		}
		printf("%d", list->n);
		counter++;
		list = list->next;
	}
	printf("\n");
}
