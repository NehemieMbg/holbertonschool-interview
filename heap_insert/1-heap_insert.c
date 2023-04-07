#include "binary_trees.h"

/**
 * heap_insert - Insert a value into a Max Binary Heap.
 *
 * @root: Double pointer to root node.
 * @value: Value to insert in the new node.
 *
 * Return: Pointer to freshly inserted node, NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *parent;

	if (!root)
		return (NULL);

	parent = *root;
	new = binary_tree_node(parent, value);
	if (!new)
		return (NULL);

	if (!parent)
	{
		*root = new;
		return (new);
	}

	while (parent->left && parent->right)
		parent = (subtree_size(parent->left) <= subtree_size(parent->right))
					 ? parent->left
					 : parent->right;

	if (!parent->left)
		parent->left = new;
	else
		parent->right = new;

	return (swap_if_needed(new));
}

/**
 * swap_if_needed - Swap nodes if parent is less than the new node.
 *
 * @node: The newly inserted node.
 *
 * Return: Pointer to the new node after swap, or the original node.
 */
heap_t *swap_if_needed(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		node->n = node->parent->n ^ node->n;
		node->parent->n = node->parent->n ^ node->n;
		node->n = node->parent->n ^ node->n;
		node = node->parent;
	}

	return (node);
}

/**
 * subtree_size - Returns the number of nodes in a binary tree.
 *
 * @tree: Pointer to the root node of the tree to measure.
 *
 * Return: The number of nodes in the tree.
 */
size_t subtree_size(const heap_t *tree)
{
	if (!tree)
		return (0);

	return (1 + subtree_size(tree->left) + subtree_size(tree->right));
}
