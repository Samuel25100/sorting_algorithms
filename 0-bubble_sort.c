#include "sort.h"
/**
 * bubble_sort - function that takes array to perform bubble
 * @array: address of the array passed
 * @size: size of the array passed
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, tracker = 0;

	if (array == NULL || size < 2)
		return;
	for (j = 0; j < size - 1; j++)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				tracker++;
				print_array(array, size);
			}
		}
		if (tracker == 0)
			break;
	}
}
