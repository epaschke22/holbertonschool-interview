#include "search_algos.h"

/**
 * recursive - searches through an array like a binary tree
 * @array: input array
 * @left: left most index
 * @right: right most index
 * @value: value to search for
 * Return: index where value is stored, else -1
 */
int recursive(int *array, int left, int right, int value)
{
	int mid, i;

	if (right >= left)
	{
		/* print array */
		printf("Searching in array: ");
		for (i = left; i <= right; i++)
			printf("%i%s", array[i], i <= right - 1 ? ", " : "\n");

		mid = left + (right - left) / 2;
		if (array[mid] == value && array[mid - 1] != value)
			return (mid);
		if (array[mid] >= value)
			return (recursive(array, left, mid - 1, value));
		return (recursive(array, mid + 1, right, value));
	}
	return (-1);
}

/**
 * advanced_binary - searches through an array like a binary tree
 * @array: input array
 * @size: size of input array
 * @value: value to search for
 * Return: index where value is stored, else -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	return (recursive(array, 0, size - 1, value));
}
