#include "binary_trees.h"

/**
 * add_node - creates binary tree node
 * @parent: is a pointer to the parent node of the node to create
 * @value: is the value to put in the new node
 * Return: return the newly created node
 */
heap_t *add_node(heap_t *parent, int value)
{
	heap_t *new;

	new = malloc(sizeof(heap_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

/**
 * binary_tree_height - prints out the height of the tree
 * @tree: input tree to printout
 * Return: tree height
 */
int binary_tree_height(const heap_t *tree)
{
	int left_height;
	int right_height;

	if (tree == NULL)
		return (0);
	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);
	else
		left_height = 0;
	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);
	else
		right_height = 0;
	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_depth-counts tree depth
 * @tree:input
 * Return:size_t depth
 */
int binary_tree_depth(const heap_t *tree)
{
	int depth = 0;

	if (tree == NULL)
		return (0);
	while (tree->parent != NULL)
	{
		tree = tree->parent;
		depth++;
	}
	return (depth);
}

/**
 * binary_tree_is_leaf - check is node has null for both left and right
 * @node: input node
 * Return: 1 if end node, else 0
 */
int binary_tree_is_leaf(const heap_t *node)
{
	if (node == NULL)
		return (0);

	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * insert - inserts a value into a Max Binary Heap
 * @root: is a pointer to the root node of the Heap
 * @value: is the value to put in the new node
 * @level: the row to insert a node
 * Return: return the newly created node
 */
heap_t *insert(heap_t *root, int value, int level)
{
	heap_t *left, *right;

	if (root == NULL)
		return (NULL);
	if (binary_tree_depth(root) == level)
	{
		if (binary_tree_is_leaf(root))
			return (root->left = add_node(root, value));
		if (root->left != NULL && root->right == NULL)
			return (root->right = add_node(root, value));
		return (NULL);
	}
	left = insert(root->left, value, level);
	if (left == NULL)
		right = insert(root->right, value, level);
	else
		return (left);
	return (right);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: is a double pointer to the root node of the Heap
 * @value: is the value to put in the new node
 * Return: return the newly created node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	int height, i, tmp;
	heap_t *node = NULL;

	if (*root == NULL)
	{
		*root = add_node(NULL, value);
		return (*root);
	}
	height = binary_tree_height(*root);
	for (i = 0; i <= height; i++)
	{
		node = insert(*root, value, i);
		if (node != NULL)
			break;
	}
	while (node->parent != NULL && node->n > node->parent->n)
	{
		tmp = node->parent->n;
		node->parent->n = node->n;
		node->n = tmp;
		node = node->parent;
	}
	return (node);
}
