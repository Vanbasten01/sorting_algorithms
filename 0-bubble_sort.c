#include "sort.h"
/**
 *bubble_sort - a function that sorts an array using
 *the bubble sort algorithm.
 *@array: the array to be sorted.
 *@size: the size of the array.
 *Return: void.
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

