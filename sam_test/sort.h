#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>

	/*Structs*/
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/*Functions*/

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
/*Sorting Algorithm 0*/
void bubble_sort(int *array, size_t size);
/*Sorting Algorithm 1*/
void insertion_sort_list(listint_t **list);
int insert_array(listint_t **list, int *array);
void print_arr_tolist(int *array, listint_t **list);
/*Sorting Algorithm 2*/
void selection_sort(int *array, size_t size);
/*Sorting Algorithm 3*/
void quick_sort(int *array, size_t size);
#endif
