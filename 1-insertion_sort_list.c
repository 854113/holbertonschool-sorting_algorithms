#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 *
 * @list: List to sort.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp, *next;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		next = current->next;
		tmp = current->prev;

		while (tmp && current->n < tmp->n)
		{
			swap_nodes(list, current, tmp);
			print_list(*list);
			tmp = current->prev;
		}

		current = next;
	}
}

/**
 * swap_nodes - Swaps the position of two nodes of a double linked list.
 *
 * @list: List of the nodes to swap.
 * @node1: First node.
 * @node2: Second node.
 */

void swap_nodes(listint_t **list,  listint_t *node1, listint_t *node2)
{
	listint_t *tmp = node1->next;

	if (node1 == node2)
		return;
	if (node1->next == node2)
	{
		if (node1->prev)
			node1->prev->next = node2;
		if (node2->next)
			node2->next->prev = node1;
		node2->prev = node1->prev;
		node1->next = node2->next;
		node1->prev = node2;
		node2->next = node1;
	}
	else if (node2->next == node1)
	{
		swap_nodes(list, node2, node1);
	}
	else
	{
		tmp = node1->next;
		node1->next = node2->next;
		node2->next = tmp;
		tmp = node1->prev;
		node1->prev = node2->prev;
		node2->prev = tmp;
		if (node1->next)
			node1->next->prev = node1;
		if (node1->prev)
			node1->prev->next = node1;
		if (node2->next)
			node2->next->prev = node2;
		if (node2->prev)
			node2->prev->next = node2;
	}
	if (!node1->prev)
		*list = node1;
	if (!node2->prev)
		*list = node2;
}
