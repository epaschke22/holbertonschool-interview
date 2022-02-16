#include "sort.h"

/**
 * radix_sort - sorts an array with the radix sort method
 * @array: pointer to input array
 * @size: size of imput array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int i, max, exp, *count, output[size];

	if (size == 0)
		return;

	max = array[0];
	for (i = 1; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count = malloc(sizeof(int) * 10);
		for (i = 0; i < (int)size; i++)
			count[i] = 0;

		for (i = 0; i < (int)size; i++)
			count[(array[i] / exp) % 10]++;
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
		for (i = (int)size; i >= 0; i--)
		{
			output[count[(array[i] / exp) % 10] - 1] = array[i];
			count[(array[i] / exp) % 10]--;
		}
		for (i = 0; i < (int)size; i++)
			array[i] = output[i];

		free(count);
		print_array(array, size);
	}
}
