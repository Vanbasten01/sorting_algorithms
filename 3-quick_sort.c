#include "sort.h"
/**
 *_lomuto - a function to do the partition of the array
 *using lomuto partition algorithm.
 *@arr: the array to be partitioned.
 *@low: the index of the first element of the array's part to be partitioned.
 *@high: the index of the last  element of the array's part to be partitioned.
 *@size: the size of the whole array.
 *Return: the index of the pivot.
 */
unsigned int _lomuto(int *arr, int low, int high, size_t size)
{
	int current, i;
	int pivot;


	pivot = arr[high];
	current = low - 1;

	for (i = low; i <=  high; i++)
	{
		if (arr[i] <= pivot)
		{
			current++;
			if (i != current)
			{
				swap(&arr[i], &arr[current]);
				print_array(arr, size);
			}
		}
	}
	return (current);
}
/**
 *quicksort - it is kind of wrapper of quick_sort function.
 *@array: the array to be sorted.
 *@low: the index of the first element of the array's part to be sorted.
 *@high: the index of the last  element of the array's part to be sorted.
 *@size: the size of the whole array.
 *Return: void.
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = _lomuto(array, low, high, size);
		if (pivot_idx > 0)
			quicksort(array, low, pivot_idx - 1, size);
		quicksort(array, pivot_idx + 1, high, size);
	}
}

/**
 *quick_sort - a function that sorts an array using
 *the Quick sort algorithm.
 *@array: the array to be sorted.
 *@size: the size of the array.
 *Return: void.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size == 0)
		return;
	quicksort(array, 0, size - 1, size);
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
