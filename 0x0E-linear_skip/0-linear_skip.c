#include "search.h"

/**
 * linear_skip - looking through SLL with express lane
 * @list: point to head of list
 * @value: value to search for
 * Return: point to node with matching value, else NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *lastindex, *current;
	int found = 0;

	if (list == NULL)
		return (NULL);
	while (list->express != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				list->express->index, list->express->n);
		if (value > list->express->n)
			list = list->express;
		else
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
					list->index, list->express->index);
			found = 1;
			break;
		}
	}
	current = list;
	if (found == 0)
	{
		lastindex = current;
		while (lastindex->next != NULL)
			lastindex = lastindex->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
				current->index, lastindex->index);
	}
	while (current != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
		if (current->n == value)
			return (current);
		current = current->next;
	}
	return (NULL);
}
