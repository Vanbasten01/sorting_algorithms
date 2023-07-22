#include "sort.h"
/**
 *selection_sort - a function that sort an array using
 *the selection sort algorithm.
 *@array: the array to be sorted.
 *@size: the size of the array.
 *Return: void.
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min;

	if (!array || size == 0)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			swap(&array[i], &array[min]);
			print_array(array, size);
		}
	}
}

/**
 *swap - a function that swaps two integers.
 *@a: first integer.
 *@b: second integer to swap.
 *Return: void.
 */
void swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
