#include "binary_trees.h"

/**
 * count_nodes - counts the numeber of nodes in a binary tree
 * @root: input tree
 * Return: number of nodes
 */
unsigned int count_nodes(heap_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + count_nodes(root->left) + count_nodes(root->right));
}

/**
 * get_last - finds the last node in a binary heap
 * @root: input tree
 * Return: point to last node
 */
heap_t *get_last(heap_t *root)
{
	unsigned int count, binary = 1;

	count = count_nodes(root);
	while (count / binary > 1)
		binary = binary << 1;
	binary = binary >> 1;

	while (binary)
	{
		if (count & binary)
			root = root->right;
		else
			root = root->left;
		binary = binary >> 1;
	}
	return (root);
}

/**
 * heapreorder - finds the last node in a binary heap
 * @root: input tree
 * Return: point to last node
 */
void heapreorder(heap_t *root)
{
	heap_t *swap = root;
	int temp;

	if (root->left && root->right)
	{
		if (root->left->n >= root->right->n)
		{
			if (root->left->n > root->n)
				swap = root->left;
		}
		else
		{
			if (root->right->n > root->n)
				swap = root->right;
		}
	}
	else if (root->left && root->left->n > root->n)
		swap = root->left;
	else if (root->right && root->right->n > root->n)
		swap = root->right;

	if (swap != root)
	{
		temp = root->n;
		root->n = swap->n;
		swap->n = temp;
		heapreorder(swap);
	}
}

/**
 * heap_extract - extracts the root node of a max binary heat
 * @root: input tree
 * Return: number extracted, else 0
 */
int heap_extract(heap_t **root)
{
	heap_t *lastnode;
	int extracted;

	if (root == NULL || *root == NULL)
		return (0);
	lastnode = get_last(*root);
	extracted = (*root)->n;
	if (lastnode == *root)
	{
		free(*root);
		*root = NULL;
	}
	else
	{
		if (lastnode->parent->left == lastnode)
			lastnode->parent->left = NULL;
		else
			lastnode->parent->right = NULL;
		lastnode->parent = NULL;

		if ((*root)->left == lastnode)
			lastnode->left = NULL;
		else
			lastnode->left = (*root)->left;
		if ((*root)->right == lastnode)
			lastnode->right = NULL;
		else
			lastnode->right = (*root)->right;

		if (lastnode->left != NULL)
			lastnode->left->parent = lastnode;
		if (lastnode->right != NULL)
			lastnode->right->parent = lastnode;
		free(*root);
		*root = lastnode;
		heapreorder(lastnode);
	}
	return (extracted);
}
