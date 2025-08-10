#include "sort.h"

/**
 * insertion_sort_list - Sort a doubly linked list of integers,
 *							in ascending order.
 * @list: Double pointer to the head of the list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev;

	if (!list || !*list || !(*list)->next)
		return;

	curr = (*list)->next;
	while (curr)
	{
		prev = curr->prev;
		while (prev && prev->n > curr->n)
		{

			if (prev->prev)
				prev->prev->next = curr;
			else
				*list = curr;

			if (curr->next)
				curr->next->prev = prev;

			prev->next = curr->next;
			curr->prev = prev->prev;
			curr->next = prev;
			prev->prev = curr;

			print_list(*list);

			prev = curr->prev;
		}
		curr = curr->next;
	}
}
