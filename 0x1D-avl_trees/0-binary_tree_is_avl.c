#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * max - returns the higher of 2 values
 * @a: first int
 * @b: second int
 * Return: which value is bigger
 */
int max(int a, int b)
{
	return ((a >= b) ? a : b);
}

/**
 * height - returns the height of the tree
 * @node: current node to check for
 * Return: int amount of nodes returned
 */
int height(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	return (1 + max(height(node->left), height(node->right)));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a vaild AVL tree
 * @tree: a pointer to the root node of the tree
 * Return: 1 if tree is valid, else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int lh, rh;

	if (tree == NULL)
		return (1);

	lh = height(tree->left);
	rh = height(tree->right);

	if (abs(lh - rh) <= 1 && binary_tree_is_avl(tree->left) &&
							 binary_tree_is_avl(tree->right))
		return (1);

	return (0);
}
