#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: a pointer to the root node.
 *
 * Return: 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lt, rt;

	if (tree == NUL)
		return (0);

	lt = 0;
	rt = 0;

	lt = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	rt = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (((rt < lt) ? lt : rt));

}
