#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_left - Inserts a node as the left-child. 
 *
 * @parent: a pointer to the node to insert the left-child in
 * @value: new node's value
 *
 * Return: ointer to the created node, NULL on failure or
 * if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *temp;

	if (!parent)
		return (NULL);

	temp = binary_tree_node(parent, value);
	if (temp)
		parent->left = temp;
	else
	{
		temp->left = parent->left;
		parent->left = temp;
	}

	return (temp);
}
