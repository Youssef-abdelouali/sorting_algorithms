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
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Outputs the array after each swap operation.
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, len = size;
    bool bubbly = false;

    if (array == NULL || size < 2)
        return;

    while (bubbly == false)
    {
        bubbly = true;
        for (i = 0; i < len - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap_values(array + i, array + i + 1);
                print_array(array, size);
                bubbly = false;
            }
        }
        len--;
    }
}
