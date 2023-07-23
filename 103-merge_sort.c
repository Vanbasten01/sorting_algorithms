#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - two arrays merger
 * @left: left array
 * @right: right array
 * @store: the destination array
 * @nl: length of the lef array
 * @nr: length of the right array
 */
void merge(int *left, int *right, int *store, int nl, int nr)
{
	int l = 0, r = 0, pos = 0;

	for (; l < nl && r < nr;)
	{
		if (left[l] < right[r])
		{
			store[pos] = left[l];
			l++;
		}
		else
		{
			store[pos] = right[r];
			r++;
		}
		pos++;
	}

	for (; l < nl; l++, pos++)
		store[pos] = left[l];
	for (; r < nr; r++, pos++)
		store[pos] = right[r];

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, nl);
	printf("[right]: ");
	print_array(right, nr);
	printf("[done]: ");
	print_array(store, nl + nr);
}

/**
 * merge_sort - the method to sort an array using merge sort
 * @arr: the array to sort
 * @size: the size of the array
 */
void merge_sort(int *arr, size_t size)
{
	size_t mid = size / 2;
	int *sides[] = { NULL, NULL };
	size_t tmp;
	size_t l;

	if (size <= 1)
		return;

	for (tmp = 0; tmp < 2; tmp++)
	{
		sides[tmp] = malloc(((tmp == 0 ? mid : size - mid) + 1) * sizeof(int));
	}

	if (!sides[0] || !sides[1])
		exit(98);

	for (l = 0; l < mid; l++)
		sides[0][l] = arr[l];

	for (tmp = 0, l = mid; l < size; l++, tmp++)
		sides[1][tmp] = arr[l];

	merge_sort(sides[0], mid);
	merge_sort(sides[1], size - mid);

	merge(sides[0], sides[1], arr, mid, size - mid);

	for (tmp = 0; tmp < 2; tmp++)
	{
		free(sides[tmp]);
	}
}
