#include "binary_trees.h"

/**
 * bin_depth - Measures the depth of a node in a binary tree
 *
 * @tree: A pointer to the root node.
 *
 * Return: integer, 0 if tree is NULL
 */
size_t bin_depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + bin_depth(tree->parent) : 0);
}

/**
 * bin_is_leaf - Checks if a node is a leaf.
 *
 * @node: pointer to the node
 *
 * Return: 1 if node is a leaf, otherwise 0
 */
int bin_is_leaf(const binary_tree_t *node)
{
	if (!node || node->left || node->right)
		return (0);
	return (1);
}

/**
 * get_leaf - Finds leaf of a ree.
 *
 * @tree: A pointer to the root node.
 *
 * Return: A pointer to found leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (bin_is_leaf(tree) == 1)
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
	if (bin_is_leaf(tree))
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
 * Return: 1 if true, 0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_perfect(tree, bin_depth(get_leaf(tree)), 0));
}

