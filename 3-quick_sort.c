#include "sort.h"
/**
 * partition - a function for dividing the array uisng pivot
 * @array: address of the array
 * @start: begining of the array
 * @end: end of the array
 * @size: size of the array
 *
 * Return: the index of the array
 */
int partition(int *array, int start, int end, int size)
{
	int pivot = array[end];
	int partition_index = start, i, temp;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			if (i != partition_index)
			{
				temp = array[partition_index];
				array[partition_index] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
			partition_index++;
		}

	}
	if (partition_index != end)
	{
		temp = array[partition_index];
		array[partition_index] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
	return (partition_index);
}
/**
 * quick_sort_rec - recurssion call for quick sort
 * @array: address of the array passed
 * @start: begining of the array
 * @end: end index of the array
 * @size: size of the array
 *
 */
void quick_sort_rec(int *array, int start, int end, int size)
{
	if (start < end)
	{
		int p_index = partition(array, start, end, size);

		quick_sort_rec(array, start, p_index - 1, size);
		quick_sort_rec(array, p_index + 1, end, size);
	}
}
/**
 * quick_sort - function that accepts array and size
 * @array: address of the array
 * @size: size of the array
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_rec(array, 0, size - 1, size);
}
