#include "sort.h"

/**
 * get_maximum - Finds the maximum value in an array of integers.
 * @array: Pointer to the array of integers.
 * @size: The number of elements in the array.
 *
 * Return: The largest integer in the array.
 */
int get_maximum(int *array, int size)
{
	int maximum, index;

	for (maximum = array[0], index = 1; index < size; index++)
	{
		if (array[index] > maximum)
			maximum = array[index];
	}

	return (maximum);
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: Pointer to the array of integers.
 * @size: The number of elements in the array.
 *
 * Description: After building the counting array, it prints the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, maximum, index;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;

	maximum = get_maximum(array, size);
	count = malloc(sizeof(int) * (maximum + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	/* Initialize the count array */
	for (index = 0; index < (maximum + 1); index++)
		count[index] = 0;

	/* Count the occurrences of each integer in the array */
	for (index = 0; index < (int)size; index++)
		count[array[index]] += 1;

	/* Update the count array to contain cumulative totals */
	for (index = 0; index < (maximum + 1); index++)
		count[index] += count[index - 1];

	/* Print the count array */
	print_array(count, maximum + 1);

	/* Sort the array by placing elements in their correct positions */
	for (index = 0; index < (int)size; index++)
	{
		sorted[count[array[index]] - 1] = array[index];
		count[array[index]] -= 1;
	}

	/* Copy the sorted array back into the original array */
	for (index = 0; index < (int)size; index++)
		array[index] = sorted[index];

	free(sorted);
	free(count);
}
