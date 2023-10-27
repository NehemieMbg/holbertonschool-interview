#ifndef __AVL__
#define __AVL__

/**
 * struct binary_tree_s - Binary tree standard node
 * @n: value in node
 * @parent: parent node
 * @right: right kiddo
 * @left: left kiddo
 */

struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *right;
	struct binary_tree_s *left;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;

void binary_tree_print(const binary_tree_t *);
int binary_tree_is_avl(const binary_tree_t *tree);

#endif /* __AVL__ */
