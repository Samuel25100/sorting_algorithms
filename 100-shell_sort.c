#include "sort.h"
/**
 * shell_sort - sorts elements using shell sort algo
 * @array: address of the array
 * @size: size of the array
 *
 */
void shell_sort(int *array, size_t size)
{
	int gap, temp, j, i;
	int size_ = size;

	if (array == NULL || size < 2)
		return;
	gap = 1;

	while (gap < size_ / 3)
	{
		gap = 3 * gap + 1;
	}
	while (gap > 0)
	{
		for (j = gap; j < size_; j++)
		{
			for (i = j - gap; i >= 0; i = i - gap)
			{
				if (array[i + gap] < array[i])
				{
					temp = array[i];
					array[i] = array[i + gap];
					array[i + gap] = temp;
				}
				else
					break;
			}
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
