#include "sort.h"
/**
 *
 *
 *
 *
 */
void radix_sort(int *array, size_t size)
{
	int max = array[0];
	int i;

	if (!array || size <= 1)
		return;

	for (i = 1; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	for (i = 1; max / i > 0 ; i = i * 10)
	{
		countsort(array, size, i);
		print_array(array, size);
	}
}


void countsort(int *array, size_t size, int exp)
{
	int *count, *sorted_arr, i;

	count = malloc(sizeof(int) * 10);
	if (!count)
		return;
	for (i = 0; i <= 9; i++)
		count[i] = 0;


	for (i = 0; i < (int)size; i++)
		count[(array[i] / exp) % 10]++;
	for (i = 1; i <= 9; i++)
		count[i] += count[i - 1];
	sorted_arr = malloc(sizeof(int) * size);
	if (!sorted_arr)
	{
		free(count);
		return;
	}
	for (i = (int)size - 1; i >= 0; i--)
	{
		sorted_arr[count[((array[i] / exp) % 10)] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted_arr[i];

	free(count);
	free(sorted_arr);
}
