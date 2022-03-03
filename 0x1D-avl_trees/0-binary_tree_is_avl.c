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
 * is_tree_bst - checks if a binary tree is a vaild BST tree
 * @tree: a pointer to the root node of the tree
 * @min: min
 * @max: max
 * Return: 1 if tree is valid, else 0
 */
int is_tree_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->left != NULL && tree->left->n < min)
		return (0);
	if (tree->right != NULL && tree->right->n > max)
		return (0);

	return (is_tree_bst(tree->left, min, tree->n - 1) &&
			is_tree_bst(tree->right, tree->n + 1, max));
}

/**
 * is_tree_avl - recursive function to check if tree is height balanced
 * @tree: a pointer to the root node of the tree
 * Return: 1 if tree is valid, else 0
 */
int is_tree_avl(const binary_tree_t *tree)
{
	int lh, rh;

	if (tree == NULL)
		return (1);

	lh = height(tree->left);
	rh = height(tree->right);

	if (abs(lh - rh) <= 1 && is_tree_avl(tree->left) &&
							 is_tree_avl(tree->right))
		return (1);

	return (0);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a vaild AVL tree
 * @tree: a pointer to the root node of the tree
 * Return: 1 if tree is valid, else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (is_tree_bst(tree, -10000, 10000) == 0)
		return (0);
	return (is_tree_avl(tree));
}
