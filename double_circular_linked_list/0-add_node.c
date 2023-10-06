#include "list.h"

/**
 * add_node_end - add new node at the end
 * of doubly circular linked list
 * @list: double pointer to head of linked list
 * @str: pointer to string to add in the node
 */

List *add_node_end(List **list, char *str)
{
	List *last = NULL;
	List *new = malloc(sizeof(List));
	if (!new)
		return (fprintf(stderr, "Failed to alloc memory for your new node\
		go buy some RAM\n"),
				NULL);
	new->str = strdup(str);
	if (!new->str)
		return (fprintf(stderr, "Duplication of your string failed, it must be too long "), NULL);

	if (*list)
	{
		last = (*list)->prev;
		last->next = new;
		new->prev = last;
		new->next = (*list);
		(*list)->prev = new;
	}
	/* else, dog bites its own tail */
	(*list) = new;
	new->prev = new->next = new;

	return (new);
}

/**
 * add_node_begin - add new node at the beginning
 * of doubly circular linked list
 * @list: double pointer to head of linked list
 * @str: pointer to string to add in the node
 */

List *add_node_begin(List **list, char *str)
{
	List *first = NULL;
	List *new = malloc(sizeof(List));
	if (!new)
		return (fprintf(stderr, "Failed to alloc memory for your new node\
		go buy some RAM\n"),
				NULL);
	new->str = strdup(str);
	if (!new->str)
		return (fprintf(stderr, "Duplication of your string failed, it must be too long "), NULL);
	if (!(*list))
	{
		*list = new;
		new->prev = new->next = new;
	}
	/* else, who is the first ?*/
	first = (*list);
	new->prev = first->prev;
	new->next = first;
	first->prev->next = new;
	first->prev = new;

	*list = new;

	return (new);
}
