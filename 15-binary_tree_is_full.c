#include "binary_trees.h"

/**
 * is_full - Recursively checks if a binary tree is full.
 * @tree: Pointer to the node.
 *
 * Return: 0 if tree is not full, Otherwise, 1.
 */
int is_full(const binary_tree_t *tree)
{
	if (tree)
	{
		if ((tree->left && !tree->right) || (!tree->left && tree->right) ||
				is_full(tree->left) == 0 || is_full(tree->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 *
 * @tree: a pointer to the root node.
 *
 * Return: integer, 0 if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_full(tree));
}

