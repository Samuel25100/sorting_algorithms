#include "sort.h"
/**
 * insertion_sort_list - sorts doubly linked list
 * @list: pointer holding the address of the head pointer
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *back;
	int value;
	/* it first checks 1) if the strucutre is null 2) if the head pointer is NUll 3) if the structure only contains one Node
	 * in which case sorting is not needed
	 *
	 */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	
	/**for this am going to use two node pointers for the selection sort..the current node starts from 2nd node and compares itself with the previous one
	 *
	 */
	current = (*list)->next;
	while (current != NULL)
	{
		/**
		 * I will assign value so that the current node value to check wether it is smaller or not from the previous node value
		 */
		value = current->n;
		back = current->prev;
		/**back node starts from the begining of the node and is compared with value
		 */
		/**we will alway check if the value before current node pointer is smaller than the back node pointer value
		 * we will enusre that when our node reaches the begining of the node using back != NULL
		 */
		while (back != NULL && back->n > value)
		{
			/**
			 * current prev will be back prev
			 * but we must also check back->prev->next is not null and if not we make it point to current
			 */
			current->prev = back->prev;
			if (back->prev != NULL)
				back->prev->next = current;
			else
				/**here we are just assigning and correcting the head of the oringinal *list that is passed
				 */
				*list = current;
			/**we also modify back's next node to modify to current next
			 * but we will check if current next is not null and if not we make sure the node after currnet previous is back
			 */
			back->next = current->next;
			if (current->next != NULL)
				current->next->prev = back;
			/**
			 * here we change back previous to be current because now current will be infront of back
			 * and also current next will not be back because back will be next curren
			 */
			back->prev = current;
			current->next = back;
			/*after swapping we must move our back one more node back for backtracking because we have to compare the value with other previous
			 * values for that we make back is current previous and current will be back next just to make it tigh
			 */
			if (current->prev != NULL)
			{
				back = current->prev;
				current = back->next;
			}
			else
				/**this means the current has been swapped al the way to the begining and so we break out
				 */
				break;
		}
		/**
		 * we assging current to move to next to move it forward
		 */
		/**checking for every iteration**/
		print_list((const listint_t *)*list);
		current = current->next;
	}
}
