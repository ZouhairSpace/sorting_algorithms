#include "sort.h"
#include <stdio.h>

/**
 * swap_list_node - swaps a node with its previous one in a double-linked list
 * @node: node to be swapped
 * @list: pointer to the head of the linked list
 * Return: returns a pointer to the node that was entered into it
 */
listint_t *swap_list_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev;
	listint_t *current = node;

	/*NULL, 19, 48, 9, 71, 13, NULL*/
	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}

/**
 * cocktail_sort_list - this is an implementation of cocktail sort
 * working on a double linked list
 * @list: pointer to the linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swap_done = 1;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	node = *list;
	while (swap_done == 1)
	{
		swap_done = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_list_node(node->next, list);
				swap_done = 1;
				print_list(*list);
			}
			node = node->next;
		}
		if (swap_done == 0)
			break;
		swap_done = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swap_list_node(node, list);
				swap_done = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}
