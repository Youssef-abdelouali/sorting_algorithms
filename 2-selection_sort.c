#include "sort.h"

/**
 * swap_values - Exchange the values of two integers in an array.
 * @first: The first integer whose value will be swapped.
 * @second: The second integer whose value will be swapped.
 */
void swap_values(int *first, int *second)
{
    int tmp;

    tmp = *first;
    *first = *second;
    *second = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers to be sorted.
 * @size: The total number of elements in the array.
 *
 * Description: Outputs the array after each swap operation.
 */
void selection_sort(int *array, size_t size)
{
    int *min;
    size_t i, j;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        min = array + i;
        for (j = i + 1; j < size; j++)
            min = (array[j] < *min) ? (array + j) : min;

        if ((array + i) != min)
        {
            swap_values(array + i, min);
            print_array(array, size);
        }
    }
}
