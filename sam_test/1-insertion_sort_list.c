#include "sort.h"
/**
 * insertion_sort_list -sort doubly linked list in ascending order
 * @list: the pointer to the head of doubly linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	int ar_buf[1024], i = 0, j, n = 0, key = 0;

	n = insert_array(list, ar_buf);
	for (i = 1; i < n; i++)
	{
	key = ar_buf[i];
	j = i - 1;
	while (j >= 0 && ar_buf[j] > key)
		{
		ar_buf[j + 1] = ar_buf[j];
		j = j - 1;
		print_arr_tolist(ar_buf, list);
		print_list(*list);
		}
	ar_buf[j + 1] = key;
	print_arr_tolist(ar_buf, list);
	}
}
/**
 * insert_array - insert doubly linked list data on array
 * @list: the pointer to the head of doubly linked list
 * @array: the array to print the data on
 * Return: void
 */
int insert_array(listint_t **list, int *array)
{
	int i = 0;
	listint_t *tmp = *list;

	while (tmp)
	{
	array[i] = tmp->n;
	tmp = tmp->next;
	i++;
	}
	return (i);
}
/**
 * print_arr_tolist - print data from buffer to doubly link list
 * @array: the buffer
 * @list: the pointer to the head
 * Return: void
 */
void print_arr_tolist(int *array, listint_t **list)
{
	listint_t *tmp = *list;
	int i = 0;

	while (tmp)
	{
	tmp->n = array[i];
	tmp = tmp->next;
	i++;
	}
}
