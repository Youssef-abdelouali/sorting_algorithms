#include "sort.h"

void swap_node_forward(listint_t **list, listint_t **tail, listint_t **current);
void swap_node_backward(listint_t **list, listint_t **tail, listint_t **current);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_forward - Swap the current node with the next node
 *                     in a doubly-linked list of integers.
 * @list: A pointer to the head of the doubly-linked list.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @current: A pointer to the current node being swapped during the
 *           cocktail shaker algorithm traversal.
 */
void swap_node_forward(listint_t **list, listint_t **tail, listint_t **current)
{
	listint_t *next_node = (*current)->next;

	if ((*current)->prev != NULL)
		(*current)->prev->next = next_node;
	else
		*list = next_node;

	next_node->prev = (*current)->prev;
	(*current)->next = next_node->next;

	if (next_node->next != NULL)
		next_node->next->prev = *current;
	else
		*tail = *current;

	(*current)->prev = next_node;
	next_node->next = *current;
	*current = next_node;
}

/**
 * swap_node_backward - Swap the current node with the previous node
 *                      in a doubly-linked list of integers.
 * @list: A pointer to the head of the doubly-linked list.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @current: A pointer to the current node being swapped during the
 *           backward traversal of the cocktail shaker algorithm.
 */
void swap_node_backward(listint_t **list, listint_t **tail, listint_t **current)
{
	listint_t *prev_node = (*current)->prev;

	if ((*current)->next != NULL)
		(*current)->next->prev = prev_node;
	else
		*tail = prev_node;

	prev_node->next = (*current)->next;
	(*current)->prev = prev_node->prev;

	if (prev_node->prev != NULL)
		prev_node->prev->next = *current;
	else
		*list = *current;

	(*current)->next = prev_node;
	prev_node->prev = *current;
	*current = prev_node;
}

/**
 * cocktail_sort_list - Sort a doubly-linked list of integers in ascending order
 *                      using the cocktail shaker sort algorithm.
 * @list: A pointer to the head of the doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *current;
	bool swapped = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* Set tail to the last node in the list. */
	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (!swapped)
	{
		swapped = true;

		/* Traverse forward through the list and swap nodes if necessary. */
		for (current = *list; current != tail; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_node_forward(list, &tail, &current);
				print_list((const listint_t *)*list);
				swapped = false;
			}
		}

		/* Traverse backward through the list and swap nodes if necessary. */
		for (current = current->prev; current != *list; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_node_backward(list, &tail, &current);
				print_list((const listint_t *)*list);
				swapped = false;
			}
		}
	}
}
