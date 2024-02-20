#include "sort.h"
/**
 * shell_sort - sort elements using shell sort algorithm
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
		gap = gap * 3 + 1;
	}
	while (gap > 0)
	{
		for (j = gap; j < size_; j++)
		{
			i = 0;
			while (i < size_)
			{
				if (i + gap < size_ && array[i] > array[i + gap])
				{
					temp = array[i];
					array[i] = array[i + gap];
					array[i + gap] = temp;
					if (i - gap >= 0 && array[i] > array[i - gap])
					{
						temp = array[i];
						array[i] = array[i - gap];
						array[i - gap] = temp;
					}
				}
				i++;
			}
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
