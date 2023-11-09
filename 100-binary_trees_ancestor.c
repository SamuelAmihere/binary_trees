#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 *
 * @first: A pointer to the first node.
 * @second: A pointer to the second node
 *
 * Return: lowest common ancestor node, else NULL
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	binary_tree_t *first_p, *sec_p;

	if (first == second)
		return ((binary_tree_t *)first);

	if (first == NULL || second == NULL)
		return (NULL);

	first_p = first->parent, sec_p = second->parent;
	if (first == sec_p || first_p == NULL || (!first_p->parent && sec_p))
		return (binary_trees_ancestor(first, sec_p));
	else  if (first_p == second || sec_p == NULL ||
			(!sec_p->parent && first_p))
		return (binary_trees_ancestor(first_p, second));
	return (binary_trees_ancestor(first_p, sec_p));
}
