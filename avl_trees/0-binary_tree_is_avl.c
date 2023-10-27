#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "binary_trees.h"

#define MAX(a, b) ((a) >= (b) ? (a) : (b))

/**
 * height - calculate height of left and right subtree
 * @tree: pointer to compute the left & right from
 * Return: 0 if tree is NULL, or the max height
 */

size_t height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + MAX(height(tree->left), height(tree->right)));
}

/**
 * avl - helper recursive function for checking AVl'ness
 * @tree: pointer to tree
 * @min: lower bound
 * @max: max bound
 * Return: 0 not AVL, 1 yes AVL !
 */

int avl(const binary_tree_t *tree, int min, int max)
{
	int l, r;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	l = tree->left ? height(tree->left) + 1 : 0;
	r = tree->right ? height(tree->right) + 1 : 0;
	/* balance factor must not exceed 1 */
	if (abs(l - r) > 1)
		return (0);
	/* if balance factor okay, check the BST property */
	return (avl(tree->left, min, tree->n - 1) &&
			avl(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - checks if a tree is a valid
 * Soviet AVL tree
 * @tree: pointer to root node of tree to be checked
 * Return: 1 if tree is AVL tree, 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (avl(tree, INT_MIN, INT_MAX));
}
