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
 *heap_sort - afuntion that sorts an array of integers in ascending
 *order using Heap Sort algorithm.
 *@array: a pointer to the array to be sorted.
 *@size: the size of the array.
 *Return: void.
 */
void heap_sort(int *array, size_t size)
{
	int i;
	size_t array_size = size;

	if (!array || size <= 1)
		return;

	for (i = (int)size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, array_size);

	for (i = size - 1; i >= 1; i--)
	{
		swap(&array[i], &array[0]);
		print_array(array, array_size);
		heapify(array, i, 0, array_size);
	}
}
/**
 *heapify - a function that rearranges a binary heap
 *to maintain the max heap property.
 *@array: a pointer to the array to be sorted.
 *@size: the size of the current heap.
 *@i: index of the current node to be heapefied.
 *@array_size: the total size of the original array.
 *Return: void.
 */
void heapify(int *array, size_t size, int i, size_t array_size)
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
		heapify(array, size, largest, array_size);
	}
}
