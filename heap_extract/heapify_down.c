#include "binary_trees.h"

/**
 * heapify_down - fix the heap to be Max again
 * 
 * 
*/

void heapify_down(binary_tree_t *root)
{
	binary_tree_t *child = NULL;
	int tmp = 0;

	while (1)
	{
		if (!root->left)
			break;
		else if (!root->right)
			child = root->left;
		else
		{
			if (root->left->n >= root->right->n)
				child = root->left;
			else
				child = root->right;
		}
		if (root->n >= child->n)
			break;
			
		tmp = root->n;
		root->n = child->n;
		child->n = tmp;

		root = child;
	}
}
