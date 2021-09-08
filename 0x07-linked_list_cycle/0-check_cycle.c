#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - checks if there is a cycle in a linked list
 * @list: pointer to head of list
 * Return: 1 if cycle else 0
 */
int check_cycle(listint_t *list)
{
	listint_t *pointer1, *pointer2;

	pointer1 = list;
	pointer2 = list;
	while (pointer2->next != NULL)
	{
		pointer1 = pointer1->next;
		pointer2 = pointer2->next;
		if (pointer2->next == NULL)
			break;
		pointer2 = pointer2->next;
		if (pointer1 == pointer2)
			return (1);
	}
	return (0);
}
