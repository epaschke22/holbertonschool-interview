#include "sort.h"


/**
 * merge - merges both arrays
 * @copyarr: coppied array from original
 * @size: size of array
 * @middle: middle index of array
 * @mainarr: pointer to original array
 * Return: void
 */
void merge(int *copyarr, int size, int middle, int *mainarr)
{
	 int i, j = middle, k = 0;

	for (i = 0; i < size; i++)
	{
		if (k < middle && (j >= size || copyarr[k] <= copyarr[j]))
			mainarr[i] = copyarr[k], k++;
		else
			mainarr[i] = copyarr[j], j++;
	}
}

/**
 * merge_rec - recursive function for merging
 * @copyarr: coppied array from original
 * @size: size of array
 * @mainarr: pointer to original array
 * Return: void
 */
void merge_rec(int *copyarr, int size, int *mainarr)
{
	int middle = size / 2;

	if (size <= 1)
		return;
	merge_rec(mainarr, middle, copyarr);
	merge_rec((mainarr + middle), size - middle, (copyarr + middle));

	printf("Merging...\n");
	printf("[left]: ");
	print_array(copyarr, middle);
	printf("[right]: ");
	print_array((copyarr + middle), size - middle);

	merge(copyarr, size, middle, mainarr);

	printf("[Done]: ");
	print_array(mainarr, size);
}

/**
 * merge_sort - top down merge sort
 * @array: input array
 * @size: size of input array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int i, *a_copy;

	a_copy = malloc(sizeof(int) * size);
	for (i = 0; i < (int)size; i++)
		a_copy[i] = array[i];
	merge_rec(a_copy, (int)size, array);
	free(a_copy);
}
