#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 *
 * @root: Pointer to the root node of the heap.
 * @value: Value to insert in the new node.
 *
 * Return: Pointer to the freshly inserted node, NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL, *parent = NULL;

	/* Check if root is NULL, create a new node as the root and return. */
	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	/* Traverse the heap to find the right parent for the new node. */
	parent = get_parent(*root);
	new_node = binary_tree_node(parent, value);

	/* Assign the new node to the parent's left or right pointer. */
	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	/* Swap the values of the new node and its parent if needed. */
	while (parent && new_node->n > parent->n)
	{
		swap_values(new_node, parent);
		new_node = parent;
		parent = new_node->parent;
	}

	return (new_node);
}

/**
 * get_parent - Finds the parent of the next node to insert.
 *
 * @root: Pointer to the root node of the heap.
 *
 * Return: Pointer to the parent node of the next node to insert.
 */
heap_t *get_parent(heap_t *root)
{
	heap_t *parent = NULL;

	/* If left child is empty, parent is the node to the left of the new node. */
	if (root->left == NULL)
		return (root);

	/* If right child is empty, parent is the node to the right of the new node. */
	if (root->right == NULL)
		return (root);

	/* Otherwise, traverse left and right subtrees to find the right parent. */
	parent = get_parent(root->left);

	if (subtree_size(parent->left) <= subtree_size(parent->right))
		return (parent->left);
	else
		return (parent->right);
}

/**
 * swap_values - Swaps the values of two nodes in the heap.
 *
 * @node: First node to swap.
 * @parent: Second node to swap.
 */
void swap_values(heap_t *node, heap_t *parent)
{
	int temp;

	temp = node->n;
	node->n = parent->n;
	parent->n = temp;
}

/**
 * subtree_size - Computes the size of a subtree rooted at a given node.
 *
 * @tree: Pointer to the root node of the subtree.
 *
 * Return: The size of the subtree rooted at `tree`.
 */
size_t subtree_size(const heap_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + subtree_size(tree->left) + subtree_size(tree->right));
}
