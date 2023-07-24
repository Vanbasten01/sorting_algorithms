#include "sort.h"
/**
 *
 *
 *
 *
 */
void counting_sort(int *array, size_t size)
{
	size_t i, j, max;
	int *count, *sorted_arr;

	if (!array || size <= 1)
		return;
	max = (size_t)array[0];
	for (i = 1; i < size; i++)
	{
		if ((size_t)array[i] > max)
			max = array[i];
	}
	count = (int *)malloc((max + 1) * sizeof(int));
	if (!count)
		return;
	for (i = 0; i < max + 1; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		for (j = 0; j < max + 1; j++)
			if (array[i] == (int)j)
				count[j]++;
	for (i = 1; i < max + 1; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	sorted_arr = malloc(size * sizeof(int));
	if (!sorted_arr)
	{
		free(count);
		return;
	}
	for (i = 0; i < size; i++)
	{
		sorted_arr[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = sorted_arr[i];
	free(count);
	free(sorted_arr);
}
