#include "binary_trees.h"

/**
 * sortedArrayToBST - recursive function
 * @arr: The array to be sorted
 * @start: starting index to loop through
 * @end: ending index to loop through
 * @par: parrent node to append to next nodes
 * Return: return the newly created node
 */
avl_t *sortedArrayToBST(int *arr, int start, int end, avl_t *par)
{
	avl_t *root;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = malloc(sizeof(avl_t));
	if (root == NULL)
		return (NULL);
	root->n = arr[mid];
	root->left = NULL;
	root->right = NULL;
	root->parent = par;

	root->left = sortedArrayToBST(arr, start, mid - 1, root);
	root->right = sortedArrayToBST(arr, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl  - converts an array into a AVL tree
 * @array: The array to be sorted
 * @size: Size of the array
 * Return: root of tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (sortedArrayToBST(array, 0, (int)size - 1, NULL));
}
