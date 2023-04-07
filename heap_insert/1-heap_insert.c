#include "binary_trees.h"

/**
 * heap_insert - insert a value into a Max Binary Heap
 * @root: double pointer to root node
 * @value: value to insert in the new node
 * Return: pointer to freshly inserted node, NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;

	new = binary_tree_node(NULL, value);
	if (!new)
		return (NULL);

	if (*root == NULL)
		return (*root = new);

	if (subtree_len((*root)->left) <= subtree_len((*root)->right))
	{
		if ((*root)->left == NULL)
		{
			new->parent = *root;
			return ((*root)->left = new);
		}
		else
			return (heap_insert(&((*root)->left), value));
	}
	else
	{
		if ((*root)->right == NULL)
		{
			new->parent = *root;
			return ((*root)->right = new);
		}
		else
			return (heap_insert(&((*root)->right), value));
	}
}

/**
 * subtree_len - returns the length of the subtree from a given node
 * @node: pointer to the node to measure the subtree length from
 * Return: length of the subtree
 */
size_t subtree_len(const binary_tree_t *node)
{
	size_t len = 0;

	if (node == NULL)
		return (0);

	if (node->left != NULL)
		len += subtree_len(node->left) + 1;

	if (node->right != NULL)
		len += subtree_len(node->right) + 1;

	return (len);
}
