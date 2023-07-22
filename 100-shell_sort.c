#include "sort.h"
/**
 * shell_sort - a function that sorts an array using
 * shell sort algorithm .
 * @array: the array to be sorted.
 * @size: the size of the array.
 * Return: Void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (!array || size <= 1)
		return;

	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		gap /= 3;
		print_array(array, size);
	}
}
