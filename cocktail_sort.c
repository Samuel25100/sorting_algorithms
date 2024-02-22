#include "sort.h"
/**
 *
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *next, *start, *end, *last_swapped;
	int swapped = 1;

	if (*list == NULL || list == NULL)
		return;

	start = NULL;
	end = NULL;
	current = *list;
	next = current->next;
	last_swapped = NULL;
	while (swapped)
	{
		swapped = 0; 
		while (next != end && next != NULL)
		{
			if (next != NULL && current->n > next->n)
			{
				next->prev = current->prev;
				if (current->prev != NULL)
					current->prev->next = next;
				else
					*list = next;
				current->next = next->next;
				if (next->next != NULL)
					next->next->prev = current;
				else
					*list = next;
				current->prev = next;
				next->next = current;
				if (current->next != end)
				{
					next = current->next;
				}
				else if (current->next == end)
				{
					last_swapped = current;
					next = current;
					current = next->prev;
					swapped++;
					break;

				}
				/*printf("Hello world\n");*/
				swapped++;

			}
			else
			{
				current = next;
				if (next->next != NULL)
					next = next->next;

			}
		}
		if (swapped == 0)
			break;
		end = last_swapped;
		swapped = 0;
		while (current != start && current != NULL)
		{
			if (current->n > next->n)
			{
				next->prev = current->prev;
				if(current->prev != NULL)
					current->prev->next = next;
				current->next = next->next;
				if (next->next != NULL)
					next->next->prev = current;
				current->prev = next;
				next->next = current;
				if (next->prev != start)
					current = next->prev;
				else
				{
					last_swapped = next;
					next = current->next;
					swapped++;
					break;
				}
				swapped++;

			}
			else
			{
				next = current;
				current = next->prev;
			}
			
		}
		start = last_swapped;
	}
}
