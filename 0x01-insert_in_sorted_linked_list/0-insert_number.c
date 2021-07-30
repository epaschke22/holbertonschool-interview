#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - inserts node into linked between the correct values
 * @head: pointer to head of linked list
 * @number: value to be added into list
 * Return: node added, or null if failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *tmphead = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	if (*head == NULL)
	{
		if (*head == NULL)
		*head = new;
		return (*head);
	}
	if (number < tmphead->n)
	{
		new->next = tmphead;
		*head = new;
		return (*head);
	}
	while (tmphead != NULL)
	{
		if (tmphead->next == NULL)
		{
			tmphead->next = new;
			new->next = NULL;
			return (new);
		}
		if (tmphead->next->n > number)
		{
			new->next = tmphead->next;
			tmphead->next = new;
			return (new);
		}
		tmphead = tmphead->next;
	}
	return (NULL);
}
