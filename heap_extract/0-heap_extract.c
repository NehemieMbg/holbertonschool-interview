#include "binary_trees.h"

/**
 * heapify_down - fix the heap to be Max again
 * @root: double pointer to root node
*/

void heapify_down(binary_tree_t **root)
{
	binary_tree_t *node = *root, *child = NULL;
	int tmp = 0;

	while (1)
	{
		/* means we are at the rightmost of complete BT (heap)*/
		if (!node->left)
			break;
		if (!node->right)
			child = node->left;
		else
			child = node->left->n > node->right->n ?
				node->left : node->right;
			/* if true min-heap property is satisfied*/
		if (node->n >= child->n)
			break;
		tmp = node->n;
		node->n = child->n;
		child->n = tmp;
		/* follow the child an repeat checks */
		node = child;
	}
}

/**
 * mappify_the_tree - creates a bit-string map of heap
 * thanks to retrieval of its "size"
 * @val: the value to convert
 * @base: the base used
 * Return: the map str
*/

char *mappify_the_tree(int val, int base)
{
	char *TOKENS = "01", *ptr;
	static char buff[64];

	ptr = &buff[sizeof(buff)];
	*--ptr = 0;
	do {
		*--ptr = TOKENS[(val % base)];
		val /= base;
	} while (val);

	return (ptr);
}

/**
 * get_size - computes the size of the max heap
 * @root: pointer to root node to let's goo
 * Return: the size or 0
*/

int get_size(heap_t *root)
{
	if (!root)
		return (0);

	return (1 + get_size(root->left) + get_size(root->right));
}


/**
 * heap_extract - extract root of min-heap
 * @root: double pointer to root node
 * Don't lose your head yoy sleepy howlowww
 * Return: the extracted value, or 0
*/

int heap_extract(heap_t **root)
{
	heap_t *curr = NULL;
	int extract = 0, i = 0, len = 0;
	char *roadmap = NULL;

	if (!root || !*root)
		return (0);

	extract = (*root)->n;
	curr = *root;

	len = get_size(curr);
	if (len == 1)
	{
		free(*root);
		*root = NULL;
		return (extract);
	}
	roadmap = mappify_the_tree(len, 2);
	for (i = 1; roadmap[i]; i++)
		curr = roadmap[i] == '1' ? curr->right : curr->left;
	(*root)->n = curr->n;
	/* 'free' the last level-order node we found according to left-right */
	if (curr->parent->left == curr)
		curr->parent->left = NULL;
	else
		curr->parent->right = NULL;
	free(curr);
	heapify_down(root);
	return (extract);
}
