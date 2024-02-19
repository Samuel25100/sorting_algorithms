#include "sort.h"
void swap(int *array, int index0, int index1);
/**
 * bubble_sort - bubble sort the input array
 * @array: the array to be sorted
 * @size: size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	unsigned long int i, j, flag;

	for (i = 0; i < (size - 1); i++)
	{
	flag = 0;
		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
			swap(array, j, j + 1);
			flag = 1;
			print_array(array, size);
			}
		}
	if (flag == 0)
		break;
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
