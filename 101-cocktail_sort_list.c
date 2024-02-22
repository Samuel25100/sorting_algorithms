#include "sort.h"
/**
 * forward_pass - function that performs forward pass of list
 * @list: address of pointer to a list
 * @current: address of pointer to current node
 * @next: address of pointer to next node
 * @end: address of pointer to end node
 * @last_swapped: last swapped node addres
 * @swapped: value representing wether swapp happened or not
 *
 */
void forward_pass(listint_t **list, listint_t **current, listint_t **next,
		listint_t **end, listint_t **last_swapped, int *swapped)
{
	*swapped = 0;
	while (*next != *end && *next != NULL)
	{
		if (*next != NULL && (*current)->n > (*next)->n)
		{
			(*next)->prev = (*current)->prev;
			if ((*current)->prev != NULL)
				(*current)->prev->next = *next;
			else
				*list = *next;
			(*current)->next = (*next)->next;
			if ((*next)->next != NULL)
				(*next)->next->prev = *current;
			(*current)->prev = *next;
			(*next)->next = *current;
			if ((*current)->next != *end)
				*next = (*current)->next;
			else if ((*current)->next == *end)
			{
				*last_swapped = *current;
				*next = *current;
				*current = (*next)->prev;
				(*swapped)++;
				print_list((const listint_t *)*list);
				break;
			}
			(*swapped)++;
			print_list((const listint_t *)*list);
		}
		else
		{
			*current = *next;
			if ((*next)->next != NULL)
				*next = (*next)->next;

		}

	}
}
/**
 * backward_pass - function that performs back pass of a list
 * @list: address of pointer to a list
 * @current: address of pointer to current nodes
 * @next: address of pointer to next node
 * @start: node of the start node
 * @last_swapped: last swapped node address
 * @swapped: value reprenting the existence of swap
 *
 */
void backward_pass(listint_t **list, listint_t **current, listint_t **next,
		listint_t **start, listint_t **last_swapped, int *swapped)
{

	while ((*current) != *start && *current != NULL)
	{
		if ((*current)->n > (*next)->n)
		{
			(*next)->prev = (*current)->prev;
			if ((*current)->prev != NULL)
				(*current)->prev->next = *next;
			(*current)->next = (*next)->next;
			if ((*next)->next != NULL)
				(*next)->next->prev = *current;
			(*current)->prev = *next;
			(*next)->next = *current;
			if ((*next)->prev != *start)
				*current = (*next)->prev;
			else
			{
				*last_swapped = *next;
				*next = (*current)->next;
			}
			(*swapped)++;
			print_list((const listint_t *)*list);

		}
		else
		{
			listint_t *temp = (*current)->prev;
			*next = *current;
			*current = temp;

		}
	}
	if (*start != NULL && (*start)->prev == NULL)
		*list = *start;
}

/**
 * cocktail_sort_list - function that performs conctail sort
 * @list: addres of the first node
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *next, *start, *end, *last_swapped;
	int swapped = 1;

	if (*list == NULL || list == NULL)
		return;

	start = *list;
	end = NULL;
	current = *list;
	next = current->next;
	while (swapped)
	{
		swapped = 0;
		forward_pass(list, &current, &next, &end, &last_swapped, &swapped);
		if (swapped == 0)
			break;
		if (last_swapped != NULL)
			end = last_swapped;
		swapped = 0;
		backward_pass(list, &current, &next, &start, &last_swapped, &swapped);
		if (last_swapped == NULL)
			start = last_swapped;
	}
}
