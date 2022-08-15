#include "sort.h"

/**
 * list_len - retrieve length of a list
 * @list: head of list
 *
 * Return: length
 */
size_t list_len(listint_t *list)
{
	size_t len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

/**
 * switch_nodes - switching nodes
 * @list: head of list
 * @p: pointer to node
 */
void switch_nodes(listint_t **list, listint_t **p)
{
	listint_t *one, *two, *three, *four;

	one = (*p)->prev;
	two = *p;
	three = (*p)->next;
	four = (*p)->next->next;
	two->next = four;
	if (four)
		four->prev = two;
	three->next = two;
	three->prev = two->prev;
	if (one)
		one->next = three;
	else
		*list = three;
	two->prev = three;
	*p = three;
}

/**
 *  cocktail_sort_list - sorting a doubly linked list using
 * the cocktail sort algorithm
 * @list: double pointer to list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *p;
	int sorting = 0;

	if (!list || !*list || list_len(*list) < 2)
		return;
	p = *list;
	while (!sorting)
	{
		sorting = 1;
		while (p->next)
		{
			if (p->n > p->next->n)
			{
				sorting = 0;
				switch_nodes(list, &p);
				print_list(*list);
			}
			else
				p = p->next;
		}
		if (sorting)
			break;
		p = p->prev;
		while (p->prev)
		{
			if (p->n < p->prev->n)
			{
				sorting = 0;
				p = p->prev;
				switch_nodes(list, &p);
				print_list(*list);
			}
			else
				p = p->prev;
		}
	}
}
