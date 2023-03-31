#include "lists.h"

/**
 * insert_node - Inserts a node into a sorted singly linked list
 * @head: Double pointer to the head node of the list
 * @number: Number to be inserted
 *
 * Return: The address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, *current;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	/* Fill the fields of the new node */
	new_node->n = number;
	new_node->next = NULL;

	/* Handle the case of an empty list */
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	/* Traverse the list to find the correct position to insert the new node */
	current = *head;
	while (current->next != NULL && current->next->n < number)
		current = current->next;

	/* Insert the new node */
	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}
