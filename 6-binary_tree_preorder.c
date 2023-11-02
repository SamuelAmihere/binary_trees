#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_preorder - Performs pre-order traversal.
 *
 * @tree: a pointer to the root node.
 * @func: a pointer to a function caller for each node.
 *
 * Return: Nothing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
