#include "sort.h"
/**
 *insertion_sort_list - a function that sort a doubly linked
 *list using Insertion sort algirithm.
 *@list: the doubly linked list to be sorted.
 *Return: void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *unsorted, *tosort;

	if ((!list) || !(*list) || !(*list)->next)
		return;

	unsorted = (*list)->next;
	while (unsorted)
	{
		tosort = unsorted;
		unsorted = unsorted->next;

		while (tosort->prev && (tosort->prev->n > tosort->n))
		{
			tosort->prev->next = tosort->next;
			if (tosort->next)
				tosort->next->prev = tosort->prev;
			tosort->next = tosort->prev;
			tosort->prev = tosort->prev->prev;
			tosort->next->prev = tosort;
			if (tosort->prev)
				tosort->prev->next = tosort;
			else
				*list = tosort;
			print_list(*list);
		}
	}
}
