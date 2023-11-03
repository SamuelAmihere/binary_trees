#include "binary_trees.h"

/**
 * get_leaf - Finds leaf of a ree.
 *
 * @tree: A pointer to the root node.
 *
 * Return: A pointer to found leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (binary_tree_is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect - recursively checks if a tree is perfect.
 *
 * @tree: A pointer to the root node.
 * @leaf_depth: Leaf's depth in the tree.
 * @level: Current node's depth.
 *
 * Return: 1 if tree is perfect, 0 otherwise.
 */
int is_perfect(const binary_tree_t *tree, size_t leaf_depth, size_t level)
{
	if (binary_tree_is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (!tree->left || !tree->right)
		return (0);
	return (is_perfect(tree->left, leaf_depth, level + 1) &&
			is_perfect(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 *
 * @tree: a pointer to the root node.
 *
 * Return: integer, 0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_perfect(tree, binary_tree_depth(get_leaf(tree)), 0));
}

