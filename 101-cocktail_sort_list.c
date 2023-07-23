#include "sort.h"
/**
 *
 *
 *
 *
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp;
	int count = 1, end = 0, start = 0, holder;

	if (!list)
		return;
	tmp = *list;
	while (tmp->next)
	{
		tmp = tmp->next;
		end++;
	}
	tmp = *list;
	holder = end;
	while (count == 1)
	{
		end = holder;
		while (end > start)
		{
			if (tmp->n > tmp->next->n)
			{
				swap_nodes(list, tmp, tmp->next);
				print_list(*list);
				count = 1;
			}
			else
				tmp = tmp->next;
			end--;		
		}
		count = 0;
		end = holder;
		while (end > start)
		{
			if (tmp->n < tmp->prev->n)
			{
				swap_nodes(list, tmp->prev, tmp);
				print_list(*list);
				count = 1;
			}
			else
				tmp = tmp->prev;
			end--;
		}
		start++;
	}
}

void swap_nodes(listint_t **head, listint_t *a, listint_t *b)
{
	listint_t *tmp;

	tmp = a->prev;
	if (tmp)
		tmp->next = b;
	if (b->next)
		b->next->prev = a;
	if (tmp == NULL)
		*head = b;
	a->next = b->next;
	b->next = a;
	a->prev = b;
	b->prev = tmp;
}
