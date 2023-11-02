#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right - Inserts a node as the right-child.
 *
 * @parent: a pointer to the node to insert the left-child in
 * @value: new node's value
 *
 * Return: pointer to the created node, NULL on failure or
 * if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *temp;

	if (!parent)
		return (NULL);

	temp = binary_tree_node(parent, value);
	if (temp)
	{
		if (parent->right)
		{
			temp->right = parent->right;
			parent->right->parent = temp;
		}
		parent->right = temp;
	}

	return (temp);
}
