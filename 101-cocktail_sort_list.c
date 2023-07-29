#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list
 * @list: list to be sorted
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int sw;

	if (!list || !(*list) || !(*list)->next)
		return;
	do {
		sw = 0;
		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap(list, current, current->next);
				print_list(*list);
				sw = 1;
			}
		}
		if (sw == 0)
			break;
		sw = 0;

		for (current = *list; current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap(list, current->prev, current);
				print_list(*list);
				sw = 1;
			}
		}
	} while (sw);
}

/**
 * swap - swaps two nodes in a doubly linked list
 *
 * @list: given list
 * @one: first node
 * @two: second node
 *
 */

void swap(listint_t **list, listint_t *one, listint_t *two)
{
	if (one->prev)
		one->prev->next = two;
	else
		*list = two;
	if (two->next)
		two->next->prev = one;
	one->next = two->next;
	two->prev = one->prev;
	two->next = one;
	one->prev = two;
}
