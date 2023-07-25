#include "sort.h"
/**
 *cocktail_sort_list - a function that sorts a doubly linked list
 *using the Cocktail Sort algorithm.
 *@list: the doubly linked list to be sorted.
 *Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp;
	int count = 1, end = 0, start = 0, i;

	if (!list)
		return;
	end = size_counter(list);
	tmp = *list;
	while (count == 1)
	{
		for (i = end ; i > start; i--)
		{
			if (tmp->n > tmp->next->n)
			{
				swap_nodes(list, tmp, tmp->next);
				print_list(*list);
				count = 1;
			}
			else
				tmp = tmp->next;
		}
		count = 0;
		for (i = end; i > start; i--)
		{
			if (tmp->n < tmp->prev->n)
			{
				swap_nodes(list, tmp->prev, tmp);
				print_list(*list);
				count = 1;
			}
			else
				tmp = tmp->prev;
		}
		start++;
	}
}
/**
 *swap_nodes - a funtion that swaps two adjacent nodes.
 *@head: the head the linked list.
 *@a: the first node to be swaped.
 *@b: the second node to be swaped.
 *Return: void.
 */
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
/**
 *size_counter - a function that returns the size of the linked list.
 *@head: the head pointer.
 *Return: size of the linked list;
 */
int size_counter(listint_t **head)
{
	int size = 0;
	listint_t *temp = *head;

	while (temp->next)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

