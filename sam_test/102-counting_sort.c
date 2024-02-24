#include "sort.h"
/**
 * counting_sort - sort the array data using counting sort algorithm
 * @array: data to be sort
 * @size: size of array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *c, *temp, max, i;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;
	for (i = 0; i < (int)size; i++)
	{
	if (array[i] > max)
		max = array[i];
	}

	c = malloc(sizeof(int) * (max + 1));
	if (c == NULL)
	{
		free(temp);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		c[i] = 0;
	for (i = 0; i < (int)size; i++)
		c[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		c[i] += c[i - 1];
	print_array(c, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		temp[c[array[i]] - 1] = array[i];
		c[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = temp[i];

	free(temp);
	free(c);
}
