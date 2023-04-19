#include <stdio.h>
#include "sandpiles.h"

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: First sandpile grid
 * @grid2: Second sandpile grid
 *
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, unstable;

	do
	{
		unstable = 0;

		/* Add grids element-wise */
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				grid1[i][j] += grid2[i][j];
			}
		}

		/* Topple unstable cells */
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					unstable = 1;
					grid1[i][j] -= 4;
					if (i - 1 >= 0)
					{
						grid1[i - 1][j] += 1;
					}
					if (i + 1 < 3)
					{
						grid1[i + 1][j] += 1;
					}
					if (j - 1 >= 0)
					{
						grid1[i][j - 1] += 1;
					}
					if (j + 1 < 3)
					{
						grid1[i][j + 1] += 1;
					}
				}
			}
		}

		/* Print grid1 if it is unstable */
		if (unstable)
		{
			printf("=\n");
			print_grid(grid1);
		}

	} while (unstable);
}

/**
 * print_grid - Prints a 3x3 grid
 * @grid: Grid to print
 *
 * Return: void
 */
void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j != 0)
			{
				printf(" ");
			}
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
