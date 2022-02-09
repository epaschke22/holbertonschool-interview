#include "list.h"

/**
 * add_node_end - Adds node to end of double circular linked list
 * @list: A pointer to the head of the linkd list
 * @str: string to copy into new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new, *tmphead = *list, *last;

	if (str == NULL)
		return (NULL);

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	new->str = str;
	new->next = new;
	new->prev = new;

	if (tmphead == NULL)
		*list = new;
	else
	{
		last = tmphead->prev;
		last->next = new;
		tmphead->prev = new;
		new->prev = last;
		new->next = tmphead;
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
	List *new, *tmphead = *list, *last;

	if (str == NULL)
		return (NULL);

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	new->str = str;
	new->next = new;
	new->prev = new;

	if (tmphead == NULL)
		*list = new;
	else
	{
		last = tmphead->prev;
		last->next = new;
		tmphead->prev = new;
		new->next = tmphead;
		new->prev = last;
		*list = new;
	}
	return (new);
}
