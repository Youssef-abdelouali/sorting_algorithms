#include "sort.h"

void merge_subarray(int *subarray, int *buffer, size_t start, size_t mid,
        size_t end);
void merge_sort_recursive(int *subarray, int *buffer, size_t start, size_t end);
void merge_sort(int *array, size_t size);

/**
 * merge_subarray - Combine and sort two contiguous segments of an integer array.
 * @subarray: The subarray containing the segments to merge.
 * @buffer: A temporary buffer used to store the merged results.
 * @start: The starting index of the first segment.
 * @mid: The ending index of the first segment and the starting index of the second.
 * @end: The ending index of the second segment.
 */
void merge_subarray(int *subarray, int *buffer, size_t start, size_t mid,
        size_t end)
{
    size_t left_index, right_index, buffer_index = 0;

    printf("Merging...\n[left]: ");
    print_array(subarray + start, mid - start);

    printf("[right]: ");
    print_array(subarray + mid, end - mid);

    for (left_index = start, right_index = mid; left_index < mid && right_index < end; buffer_index++)
        buffer[buffer_index] = (subarray[left_index] < subarray[right_index]) ? subarray[left_index++] : subarray[right_index++];
    for (; left_index < mid; left_index++)
        buffer[buffer_index++] = subarray[left_index];
    for (; right_index < end; right_index++)
        buffer[buffer_index++] = subarray[right_index];
    for (left_index = start, buffer_index = 0; left_index < end; left_index++)
        subarray[left_index] = buffer[buffer_index++];

    printf("[Done]: ");
    print_array(subarray + start, end - start);
}

/**
 * merge_sort_recursive - Recursively apply the merge sort algorithm.
 * @subarray: The subarray to sort using merge sort.
 * @buffer: A temporary buffer to hold sorted results.
 * @start: The starting index of the subarray.
 * @end: The ending index of the subarray.
 */
void merge_sort_recursive(int *subarray, int *buffer, size_t start, size_t end)
{
    size_t mid;

    if (end - start > 1)
    {
        mid = start + (end - start) / 2;
        merge_sort_recursive(subarray, buffer, start, mid);
        merge_sort_recursive(subarray, buffer, mid, end);
        merge_subarray(subarray, buffer, start, mid, end);
    }
}

/**
 * merge_sort - Sort an array of integers in ascending order using the merge sort algorithm.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Implements a top-down merge sort approach.
 */
void merge_sort(int *array, size_t size)
{
    int *buffer;

    if (array == NULL || size < 2)
        return;

    buffer = malloc(sizeof(int) * size);
    if (buffer == NULL)
        return;

    merge_sort_recursive(array, buffer, 0, size);

    free(buffer);
}
