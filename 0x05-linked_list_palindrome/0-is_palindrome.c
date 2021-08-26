#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * recursive - checks if singly linked list is a palindrome
 * @left: left pointer
 * @right: right pointer
 * Return: 1 if palindrome, else 0
 */
int recursive(listint_t **left, listint_t *right)
{
	int check1, check2;

	if (right == NULL)
		return (1);

	check1 = recursive(left, right->next);
	if (check1 == 0)
		return (0);

	if (right->n == (*left)->n)
		check2 = 1;
	else
		check2 = 0;

	*left = (*left)->next;
	return (check2);
}

/**
 * is_palindrome - checks if singly linked list is a palindrome
 * @head: input list
 * Return: 1 if palindrome, else 0
 */
int is_palindrome(listint_t **head)
{
	int count = 0;
	listint_t *h = *head;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	if (count == 0 || count == 1)
		return (1);
	return (recursive(head, *head));
}
