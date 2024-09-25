#include "sort.h"

/**
 * swap_elements - Exchange two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @first_node: A pointer to the first node to swap.
 * @second_node: The second node to swap.
 */
void swap_elements(listint_t **head, listint_t **first_node, listint_t *second_node)
{
    (*first_node)->next = second_node->next;
    if (second_node->next != NULL)
        second_node->next->prev = *first_node;
    second_node->prev = (*first_node)->prev;
    second_node->next = *first_node;
    if ((*first_node)->prev != NULL)
        (*first_node)->prev->next = second_node;
    else
        *head = second_node;
    (*first_node)->prev = second_node;
    *first_node = second_node->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Outputs the list after each swap operation.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *iterator, *insertion, *temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    for (iterator = (*list)->next; iterator != NULL; iterator = temp)
    {
        temp = iterator->next;
        insertion = iterator->prev;
        while (insertion != NULL && iterator->n < insertion->n)
        {
            swap_elements(list, &insertion, iterator);
            print_list((const listint_t *)*list);
        }
    }
}
