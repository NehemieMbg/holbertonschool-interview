#include "binary_trees.h"

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

/**
 * heap_insert - insert a value into a Max Binary Heap
 * @root: double pointer to root node
 * @value: value to insert in the new node
 * Return: pointer to freshly inserted node, NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *current;

	if (root == NULL)
		return (NULL);

	/* Create new node */
	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	/* Insert new node into Max Binary Heap */
	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	current = *root;
	while (current != NULL)
	{
		/* Insert new node as left child */
		if (subtree_size(current->left) <= subtree_size(current->right))
		{
			if (current->left == NULL)
			{
				current->left = new_node;
				new_node->parent = current;
				break;
			}
			current = current->left;
		}
		/* Insert new node as right child */
		else
		{
			if (current->right == NULL)
			{
				current->right = new_node;
				new_node->parent = current;
				break;
			}
			current = current->right;
		}
	}

	/* Sort the tree after each insertion */
	while (new_node->parent != NULL && new_node->n > new_node->parent->n)
	{
		swap_int(&(new_node->n), &(new_node->parent->n));
		new_node = new_node->parent;
	}

	return (new_node);
}
