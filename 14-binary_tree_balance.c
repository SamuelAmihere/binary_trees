#include "binary_trees.h"
#include <stdlib.h>

/**
 * bin_tree_height - Measures the height of a binary tree.
 *
 * @tree: a pointer to the root node.
 *
 * Return: 0 if tree is NULL
 */
size_t bin_tree_height(const binary_tree_t *tree)
{
	size_t lt, rt;

	if (tree == NULL)
		return (0);

	lt = 0;
	rt = 0;
	lt = tree->left ? 1 + bin_tree_height(tree->left) : 1;
	rt = tree->right ? 1 + bin_tree_height(tree->right) : 1;

	return (((rt < lt) ? lt : rt));
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 *
 * @tree: a pointer to the root node.
 *
 * Return: integer, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bin_tree_height(tree->left) - bin_tree_height(tree->right));

}
