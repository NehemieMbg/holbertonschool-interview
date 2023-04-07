#include "binary_trees.h"

/**
 * subtree_len - check and returns smallest subtree
 * @node: pointer to node
 *
 * Return: smallest path as int
 */
int subtree_len(heap_t *node)
{
	int left, right;

	if (!node)
		return (-1);
	left = subtree_len(node->left);
	right = subtree_len(node->right);
	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heap_insert - insert a value into a Max Binary Heap
 * @root: double pointer to root node
 * @value: value to insert in the new node
 *
 * Return: pointer to freshly inserted node, NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (*root == NULL)
	{
		*root = malloc(sizeof(heap_t));
		if (*root == NULL)
			return NULL;
		(*root)->n = value;
		(*root)->left = NULL;
		(*root)->right = NULL;
		return *root;
	}

	if (value < (*root)->n)
	{
		heap_insert(&((*root)->left), value);
		if ((*root)->left->n > (*root)->n)
			swap(&((*root)->left->n), &((*root)->n));
		return *root;
	}

	heap_insert(&((*root)->right), value);
	if ((*root)->right->n > (*root)->n)
		swap(&((*root)->right->n), &((*root)->n));
	return *root;
}
