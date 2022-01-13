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
	head1 = head->next;
	head2 = head->next->next;
	while (head2 && head2->next)
	{
		if (head1 == head2)
			break;
		head1 = head1->next;
		head2 = head2->next->next;
	}
	if (head1 != head2)
		return (NULL);
	head1 = head;
	while (head1 != head2)
	{
		head1 = head1->next;
		head2 = head2->next;
	}
	return (head1);
}
