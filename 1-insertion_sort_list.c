#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 * @list: double pointer to head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *std, *ustd, *tmp;

	if (!list || !*list || !(*list)->next)
		return;

	std = (*list)->next;
	ustd = std;

	while (ustd != NULL)
	{
		while (ustd->prev != NULL && ustd->prev->n > ustd->n)
		{
			tmp = ustd->prev;
			ustd->prev = tmp->prev;

			if (tmp->prev != NULL)
				tmp->prev->next = ustd;

			tmp->next = ustd->next;

			if (ustd->next != NULL)
				ustd->next->prev = tmp;

			ustd->next = tmp;
			tmp->prev = ustd;

			if (ustd->prev == NULL)
				(*list) = ustd;

			print_list(*list);
		}

		ustd = ustd->next;
	}
}
