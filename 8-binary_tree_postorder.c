#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_postorder - Performs post-order traversal.
 *
 * @tree: a pointer to the root node.
 * @func: a pointer to a function caller for each node.
 *
 * Return: Nothing
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
