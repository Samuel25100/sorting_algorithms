#include "sort.h"
/**
 * insertion_sort_list - function that applies insertion algorithm
 * @list: address of a pointer that contanins the address of a node pointer
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *back;
	int value;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		value = current->n;
		back = current->prev;
		while (back != NULL && back->n > value)
		{
			current->prev = back->prev;
			if (back->prev != NULL)
				back->prev->next = current;
			else
				*list = current;
			back->next = current->next;
			if (current->next != NULL)
				current->next->prev = back;
			back->prev = current;
			current->next = back;
			print_list((const listint_t *)*list);
			if (current->prev != NULL)
			{
				back = current->prev;
				current = back->next;
			}
			else
				break;
		}
		current = current->next;
	}
}
