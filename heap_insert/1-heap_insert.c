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

/**
 * heap_insert - insert a value into a Max Binary Heap
 * @root: double pointer to root node
 * @value: value to insert in the new node
 *
 * Return: pointer to freshly inserted node, NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	if (!(*root)->left)
	{
		(*root)->left = binary_tree_node(*root, value);
		return ((*root)->left);
	}

	if (!(*root)->right)
	{
		(*root)->right = binary_tree_node(*root, value);
		return ((*root)->right);
	}

	if (subtree_len((*root)->left) <= subtree_len((*root)->right))
		return (heap_insert(&((*root)->left), value));

	else
		return (heap_insert(&((*root)->right), value));
}
