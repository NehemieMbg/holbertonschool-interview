#include "binary_trees.h"

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

/**
 * subtree_len - check and returns smallest subtree
 * @node: pointer to node
 *
 * Return: smallest path as int
 */
int subtree_len(heap_t *node)
{
	if (!node)
		return (0);

	int left = subtree_len(node->left);
	int right = subtree_len(node->right);

	return (left <= right ? left + 1 : right + 1);
}
