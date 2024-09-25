#include "sort.h"

void swap_elements(int *first, int *second);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_elements - Exchange the values of two integers in an array.
 * @first: The first integer whose value will be swapped.
 * @second: The second integer whose value will be swapped.
 */
void swap_elements(int *first, int *second)
{
    int tmp;

    tmp = *first;
    *first = *second;
    *second = tmp;
}

/**
 * lomuto_partition - Arrange a portion of an array of integers using
 *                    the Lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the entire array.
 * @left: The starting index of the portion to arrange.
 * @right: The ending index of the portion to arrange.
 *
 * Return: The final index of the pivot after partitioning.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
    int *pivot, above, below;

    pivot = array + right;
    for (above = below = left; below < right; below++)
    {
        if (array[below] < *pivot)
        {
            if (above < below)
            {
                swap_elements(array + below, array + above);
                print_array(array, size);
            }
            above++;
        }
    }

    if (array[above] > *pivot)
    {
        swap_elements(array + above, pivot);
        print_array(array, size);
    }

    return (above);
}

/**
 * lomuto_sort - Recursively implement the quicksort algorithm.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 * @left: The starting index of the array partition to sort.
 * @right: The ending index of the array partition to sort.
 *
 * Description: Utilizes the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
    int part;

    if (right - left > 0)
    {
        part = lomuto_partition(array, size, left, right);
        lomuto_sort(array, size, left, part - 1);
        lomuto_sort(array, size, part + 1, right);
    }
}

/**
 * quick_sort - Sort an array of integers in ascending order
 *              using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Employs the Lomuto partition scheme and prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    lomuto_sort(array, size, 0, size - 1);
}
