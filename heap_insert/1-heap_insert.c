#include "binary_trees.h"

/**
 * subtree_size - measures the size of a subtree
 * @tree: pointer to the root node of the subtree to measure the size
 * Return: size of the subtree
 */
size_t subtree_size(heap_t *tree)
{
	size_t size = 0;

	if (tree)
	{
		size += 1;
		size += subtree_size(tree->left);
		size += subtree_size(tree->right);
	}
	return (size);
}

/**
 * swap_int - swaps two integers
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL, *current = *root;
	int value_tmp;

	if (!root)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!(*root))
		return (*root = new_node);

	while (1)
	{
		if (!current->left)
		{
			current->left = new_node, new_node->parent = current;
			break;
		}
		else if (!current->right)
		{
			current->right = new_node, new_node->parent = current;
			break;
		}
		else if (subtree_size(current->left) <= subtree_size(current->right))
			current = current->left;
		else
			current = current->right;
	}
	while (new_node->parent && new_node->n > new_node->parent->n)
		swap_int(&(new_node->n), &(new_node->parent->n)), new_node = new_node->parent;

	return (new_node);
}
