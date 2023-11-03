#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * @tree: a pointer to the root node.
 *
 * Return: integer, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t s;

	s = 0;
	if (tree)
	{
		s += 1;
		s += binary_tree_size(tree->left);
		s += binary_tree_size(tree->right);
	}
	return (s);
}

