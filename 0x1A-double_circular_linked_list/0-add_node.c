#include "list.h"

/**
 * add_node_end - Adds node to end of double circular linked list
 * @list: A pointer to the head of the linkd list
 * @str: string to copy into new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
    List *new, *tmphead = *list, *current = *list;

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
        while (current->next != tmphead)
            current = current->next;
        tmphead->prev = new;
        new->prev = current;
        current->next = new;
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
    List *new, *tmphead = *list, *last = *list;

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
        while (last->next != tmphead)
            last = last->next;
        new->next = tmphead;
        new->prev = last;
        tmphead->prev = new;
        last->next = new;
        *list = new;
    }
    return (new);
}
