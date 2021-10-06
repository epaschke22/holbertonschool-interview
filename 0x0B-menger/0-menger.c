#include "menger.h"

/**
 * menger - renders a menger sponge fractle wiht #
 * @level: sponge size
 * Return: void
 */
void menger(int level)
{
	int i = 0, j, d, dim = 1;

	if (level < 0)
		return;
	while (i < level)
	{
		i++;
		dim *= 3;
	}
	for (i = 0; i < dim; i++)
	{
		for (j = 0; j < dim; j++)
		{
			for (d = dim / 3; d; d /= 3)
				if ((i % (d * 3)) / d == 1 && (j % (d * 3)) / d == 1)
					break;
			printf(d ? " " : "#");
		}
		printf("\n");
	}
}
