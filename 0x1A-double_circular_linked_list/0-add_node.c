#include "list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - Adds node to end of double circular linked list
 * @list: A pointer to the head of the linkd list
 * @str: string to copy into new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new;

	if (list == NULL)
		return (NULL);

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	new->next = new;
	new->prev = new;

	if (*list == NULL)
		*list = new;
	else
	{
		new->next = *list;
		new->prev = (*list)->prev;
		(*list)->prev->next = new;
		(*list)->prev = new;
	}
	return (new);
}

/**
 * add_node_begin - Adds node to beginning of double circular linked list
 * @list: A pointer to the head of the linkd list
 * @str: string to copy into new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new;

	if (list == NULL)
		return (NULL);

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	new->next = new;
	new->prev = new;

	if (*list == NULL)
		*list = new;
	else
	{
		new->next = *list;
		new->prev = (*list)->prev;
		(*list)->prev->next = new;
		(*list)->prev = new;
		*list = new;
	}
	return (new);
}
