#include "sort.h"


/**
 * heapify - recersive sorting of array
 * @array: input list
 * @size: size of list
 * @index: index of list to check
 * @printsize: the true size of the list to print out
 * Return: Void
 */
void heapify(int *array, size_t size, int index, size_t printsize)
{
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int temp;

	if (left < (int)size && array[left] > array[largest])
		largest = left;
	if (right < (int)size && array[right] > array[largest])
		largest = right;
	if (largest != index)
	{
		temp = array[index];
		array[index] = array[largest];
		array[largest] = temp;
		print_array(array, printsize);
		heapify(array, size, largest, printsize);
	}
}


/**
 * heap_sort - sorts an array in heap sort order
 * @array: input list
 * @size: size of list
 * Return: Void
 */
void heap_sort(int *array, size_t size)
{
	int i, temp;

	for (i = (int)size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = (int)size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, (size_t)i, 0, size);
	}
}
