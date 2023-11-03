#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_uncle - Finds the uncle of a node.
 *
 * @node: a pointer to a node.
 *
 * Return: tree, NULL: node is NULL, node has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);
}
