#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: The variable integers stored in the node
 * @prev: Pointers pointing to the previous elements in the list
 * @next: Pointers pointing to the next elements in the list
 */
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int partition(int *array, int lo, int hi, size_t size);
void sort(int *array, int lo, int hi, size_t size);
void swap(int *x, int *y);
void shell_sort(int *array, size_t size);

#endif
