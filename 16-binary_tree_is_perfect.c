#include "binary_trees.h"

/**
 * binary_tree_node_count - Counts the number of nodes
 * @tree: pointer to the binary tree to count
 * Return: The number of nodes in the bianry tree
 */

size_t binary_tree_node_count(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_node_count(tree->left) +
			binary_tree_node_count(tree->right));
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: If tree is NULL, your function must return 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0, height_r = 0;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_is_perfect- checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return ((int)binary_tree_node_count(tree) ==
			(1 << (binary_tree_height(tree) + 1)) - 1);
}
