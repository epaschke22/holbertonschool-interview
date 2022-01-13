#include "lists.h"

/**
 * find_listint_loop - finds lopp in linked list
 * @head: input list
 * Return: node that starts loop, else NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *head1, *head2;

	if (head == NULL || head->next == NULL)
		return (NULL);
	head1 = head;
	head2 = head->next;
	while (head2 != NULL)
	{
		if (head1 == head2)
			return (head2);
		head1 = head1->next;
		head2 = head2->next;

		if (head2 == NULL)
			break;

		if (head1 == head2)
			return (head2);
		head2 = head2->next;
	}
	return (NULL);
}
