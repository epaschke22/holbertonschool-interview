#include "list.h"

/**
* add_node_end - adds a new node at the end of a linked list
* @list: the head node of list to add to
* @str: the string for new node
*
* Return: the new node or NULL
*/
List *add_node_end(List **list, char *str)
{
    // if string is null then return
    if (str == NULL)
        return (NULL);

    // create a new node
    List *new_node = malloc(sizeof(List));
    if (new_node == NULL)
        return (NULL);

    new_node->str = strdup(str);

    // if the list is empty
    if (*list == NULL)
    {
        // set the next and prev pointers to the new_node
        new_node->next = new_node->prev = new_node;
        *list = new_node;
    } else
    {
        /* set the next and prev pointers to the correct nodes */
        new_node->next = *list;
		new_node->prev = (*list)->prev;
		((*list)->prev)->next = new_node;
		(*list)->prev = new_node;
    }

    return (new_node);
}
/**
* add_node_begin - adds a new node at the beginning of a linked list
* @list: pointer to head of list to add to
* @str: the new string to add to list
*
* Return: the new node or NULL
*/
List *add_node_begin(List **list, char *str)
{
    if (str == NULL)
        return (NULL);

    // create a new node
    List *new_node = malloc(sizeof(List));
    if (new_node == NULL)
        return (NULL);

    new_node->str = strdup(str);

    // if the list is empty
    if (*list == NULL)
    {
        // set the next and prev pointers to the new_node
        new_node->next = new_node->prev = new_node;
        *list = new_node;
    } else
    {
        /* set the next and prev pointers to the correct nodes */
        new_node->next = *list;
		new_node->prev = (*list)->prev;
		((*list)->prev)->next = new_node;
		(*list)->prev = new_node;
		*list = new_node;
    }

    return (new_node);
}