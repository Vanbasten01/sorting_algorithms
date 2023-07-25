#include "sort.h"
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
/**
 *
 *
 *
 *
 */
void heap_sort(int *array, size_t size)
{
	int i;
	size_t array_size = size;

	if (!array || size <= 1)
		return;

	for (i = (int)size / 2 - 1; i >= 0; i--)
		heapfy(array, size, i, array_size);

	for (i = size - 1; i >= 1; i--)
	{
		swap(&array[i], &array[0]);
		print_array(array, array_size);
		heapfy(array, i, 0, array_size);
	}
}
/**
 *
 *
 *
 *
 */
void heapfy(int *array, size_t size, int i, size_t array_size)
{
	int largest = i, left = 2 * i + 1, right = 2 * i + 2;

	if (left < (int)size && array[left] > array[largest])
		largest = left;
	if (right < (int)size && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, array_size);
		heapfy(array, size, largest, array_size);
	}

}
