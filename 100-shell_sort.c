#include "sort.h"

/**
 * swap_elements - Exchange the values of two integers in an array.
 * @first: The first integer to swap.
 * @second: The second integer to swap.
 */
void swap_elements(int *first, int *second)
{
	int tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending order
 *              using the Shell sort algorithm.
 * @array: The array of integers to sort.
 * @size: The total number of elements in the array.
 *
 * Description: Implements the Knuth interval sequence for gap calculation.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, outer, inner;

	if (array == NULL || size < 2)
		return;

	/* Generate the initial gap size using the Knuth sequence. */
	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	/* Perform the shell sort with decreasing gap sizes. */
	for (; gap >= 1; gap /= 3)
	{
		for (outer = gap; outer < size; outer++)
		{
			inner = outer;
			/* Swap elements if they are out of order based on the gap. */
			while (inner >= gap && array[inner - gap] > array[inner])
			{
				swap_elements(array + inner, array + (inner - gap));
				inner -= gap;
			}
		}
		/* Print the array after each iteration of gap-based sorting. */
		print_array(array, size);
	}
}
