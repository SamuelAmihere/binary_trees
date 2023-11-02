#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_delete - Deletes an entire tree.
 *
 * @tree: pointer to a tree
 *
 * Return: Nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		binary_tree_delete(tree->right);

		binary_tree_delete(tree->left);

		free(tree);
	}
}
