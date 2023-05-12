#include "lists.h"

/**
 * check_cycle - function to detect if a cycle is present
 * in a linked list, using "floyd and tortoise trick"
 * @list: pointer to head node
 * Return: 0 for no cycle detected
 * 1 for cycle detected!
 */

int check_cycle(listint_t *list)
{
	listint_t *fast = list;

	if (!list || !list->next)
		return (0);

	while (fast && fast->next)
	{
		list = list->next;
		fast = fast->next->next;
		if (fast == list)
			return (1);
	}
	return (0);
}
