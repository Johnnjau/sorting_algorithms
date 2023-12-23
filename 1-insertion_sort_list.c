#include "sort.h"
/**
 * insertion_sort_list - arranges doubly linked list of integers in
 * ascending order
 * @list: doubly linked list of integers
 * swap_node: swaps two adjacent nodes in a linked list.
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	/* implementation of the insertion_sort_list function that calls swap_node */
	listint_t *node, *new, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (node = (*list)->next; node != NULL; node = tmp)
	{
		tmp = node->next;
		new = node->prev;
		while (new != NULL && node->n < new->n)
		{
			void swap_node(listint_t **h, listint_t **n1, listint_t *n2);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * swap_node - swaps two adjacent nodes in a linked list.
 * @h: pointer to a pointer to the head of the lined
 * @n1: first node pointer
 * @n2: second node pointer
 * Return: void
 */

void swap_node(listint_t **h, listint_t **n1, listint_t *n2)
{
	/* implementation of the swap_node function */
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

