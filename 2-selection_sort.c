#include "sort.h"
void swap(int *array, int index0, int index1);
/**
 * selection_sort - sort array using selection sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	unsigned long int i, min_ind, j;

	for (i = 0; i < (size - 1); i++)
	{
	min_ind = i;
		for (j = i + 1; j < size; j++)
		{
		if (array[j] < array[min_ind])
			min_ind = j;
		}
	if (min_ind != i)
	{
	swap(array, min_ind, i);
	print_array(array, size);
	}
	}
}
/**
 * swap - swap two value
 * @array: pointer to the array
 * @index0: index to value of an array
 * @index1: index to value of an other array
 * Return: void
 */
void swap(int *array, int index0, int index1)
{
	int temp;

	temp = array[index0];
	array[index0] = array[index1];
	array[index1] = temp;
}
