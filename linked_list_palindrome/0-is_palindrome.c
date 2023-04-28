#include "lists.h"
#include <stddef.h>

/**
 * reverser - reverse the second half of a singly
 * linked list, useful to compare to first half, palindrom?
 * @head: pointer to head node
 * Return: the reversed linked list
 */

listint_t *reverser(listint_t *head)
{
	listint_t *swappy;

	if (head == NULL || head->next == NULL)
		return (head);

	swappy = reverser(head->next);
	head->next->next = head;
	head->next = NULL;

	return (swappy);
}
/**
 * is_palindrome - check if a linked list is palindromic
 * @head: double pointer to head node
 * Return: 1 for true, 0 for false
 */

int is_palindrome(listint_t **head)
{
	listint_t *slow = *head;
	listint_t *fast = *head;
	listint_t *half = NULL, *curr = NULL;

	/* check if empty or only one node */
	if (*head == NULL || (*head)->next == NULL)
		return (1);

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	/* if fast != NULL means LL is odd so middle is tricky, move slow one step */
	if (fast)
		slow = slow->next;

	half = reverser(slow);
	curr = *head;

	while (half != NULL)
	{
		if (curr->n != half->n)
			return (0);
		curr = curr->next;
		half = half->next;
	}
	return (1);
}
