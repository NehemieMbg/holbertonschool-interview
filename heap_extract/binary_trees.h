#ifndef __EXTRACTOR__
#define __EXTRACTOR__

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s heap_t;

int heap_extract(heap_t **root);


#endif /* __EXTRACTOR__ */
