#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - completes the sum of two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 * Return: Void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int temp[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
	while (grid1[0][0] > 3 || grid1[0][1] > 3 || grid1[0][2] > 3 ||
		grid1[1][0] > 3 || grid1[1][1] > 3 || grid1[1][2] > 3 ||
		grid1[2][0] > 3 || grid1[2][1] > 3 || grid1[2][2] > 3)
	{
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				temp[i][j] = grid1[i][j];
		printf("=\n");
		print_grid(grid1);
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					if (i - 1 >= 0)
						temp[i - 1][j]++;
					if (i + 1 < 3)
						temp[i + 1][j]++;
					if (j - 1 >= 0)
						temp[i][j - 1]++;
					if (j + 1 < 3)
						temp[i][j + 1]++;
					temp[i][j] -= 4;
				}
			}
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				grid1[i][j] = temp[i][j];
	}
}
