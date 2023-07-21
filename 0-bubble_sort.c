#include "sort.h"
/**
 *
 *
 *
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;

	if (!array || size == 0)
		return;

	for (i = size - 1; i > 0; i--)
	{
		for (j = 1; j < size; j++)
		{
			if (array[j - 1] > array[j])
			{
				swap(&array[j - 1], &array[j]);
				print_array(array, size);
			}
		}
	}
}
/**
 *
 *
 *
 */
void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

