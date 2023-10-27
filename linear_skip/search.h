#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

/**
 * struct skiplist_s - Singly linked list with an express lane
 * @n: Integer
 * @index: index of node in the list
 * @next: pointer to the next node
 * @express: pointer to the next node in the express lane
 * Description: singly linked list with node structure with an express lane
 * for Holberton Society
*/

typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);
skiplist_t *linear_skip(skiplist_t *head, int value);

#endif /* _SEARCH_H_ */
