#include "sort.h"
#include <stdlib.h>

/**
 * quick_sort - using the quick sort algorithm with the Hoare partition scheme,
 * sorts an array of integers in ascending order
 * @array: an array of integers to be sorted
 * @size: size of the array
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/* Create a stack for storing partition indexes */
	int stack[size];
	int top = -1;
	int lo = 0, hi = size - 1;

	/* Keep popping from stack until it is empty */
	while (top >= 0)
	{
		/* Pop hi and lo */
		hi = stack[top--];
		lo = stack[top--];

		/* Partiton array and get the partition index */
		int p = hoare.partition(array, lo, hi, size);

		/*
		 * If there are elements on the left side of the pivot, push the
		 * left side to stack for sorting later
		 */
		if (p - 1 > lo)
		{
			stack[++top] = lo;
			stack[++top] = p - 1;
		}

		/*
		 * If there are elements on the right hand side of the pivot, push the
		 * right side to stack for sorting later
		*/
		if (p + 1 < hi)
		{
			stack[++top] = p + 1;
			stack[++top] = hi;
		}
	}
}

/**
 * hoare_partition - partition the array of integers using the Hoare scheme
 * @array: the array of integers to partition
 * @lo: starting index of the partition to be sorted
 * @hi: ending index of the partition to be sorted
 * @size: size of the array
 *
 * Return: index of the pivot
 */

int hoare_partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[lo + (hi - lo) / 2];
	int i = lo - 1, j = hi + 1;

	while (1)
	{
		/* Find the element on the left side to swap with the pivot */
		do {
			j--;
		} while (array[i] < pivot);

		/* Find the element on the right side to swap with the pivot */
		do {
			j--;
		} while (array[j] > pivot;

		/* If the indexes cross, we have found the final position of the pivot */
		if (i >= j)
			return (j);

		/* Swap the elements at i and j */
		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * partition - splitting the array into lo and hi
 * using the insertion sort algorithm
 * @array: the array of integers to sort
 * @lo: starting index of the partition to be sorted
 * @hi: ending index of the partition to be sorted
 * Return: index of the pivot
 */

int partition(int *array, int lo, int hi)
{
	int pivot = array[hi];
	int i = lo - 1, j;

	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, hi - lo + 1);
			}
		}
	}

	if (array[i + 1] != array[hi])
	{
		swap(&array[i + 1], &array[hi]);
		print_array(array, hi - lo + 1);
	}

	return (i + 1);
}

/**
 * swap - swaps two integers in the array
 * @x: pointer to the first integer to swap
 * @y: pointer to the second integer to swap
 */
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

