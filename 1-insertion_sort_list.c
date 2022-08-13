#include "sort.h"

/**
 * len_list - checks and returns the
 * length of a list
 * @h: pointer to the list
 *
 * Return: length of list
 */
int len_list(listint_t *x)
{
	int l = 0;

	while (x)
	{
		l++;
		x = x->next;
	}
	return (l);
}

/**
 * insertion_sort_list - Using the Insert Sort algorithm to sort a list
 * @list: double pointer to the list to sort
 * 
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *one = NULL;
	listint_t *two = NULL, *three = NULL, *four = NULL;

	if (!list || !(*list) || len_list(*list) < 2)
		return;

	current = *list;

	while (current)
	{
		if (current->prev && current->n < current->prev->n)
		{
			one = current->prev->prev;
			two = current->prev;
			three = current;
			four = current->next;

			two->next = four;
			if (four)
				four->prev = two;
			three->next = two;
			three->prev = one;
			if (one)
				one->next = three;
			else
				*list = three;
			two->prev = three;
			current = *list;
			print_list(*list);
			continue;
		}
		else
			current = current->next;
	}
}
