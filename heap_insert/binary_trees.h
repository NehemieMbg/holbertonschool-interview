#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdlib.h>

/**
 * struct binary_tree_s - Binary tree node
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s heap_t;

size_t binary_tree_size(const binary_tree_t *tree);
void binary_tree_print(const binary_tree_t *tree);
void swap_int(int *a, int *b);
size_t subtree_size(heap_t *tree);

#endif /* _BINARY_TREES_H_ */
