#include "sandpiles.h"

/**
 * sandpiles_sum - Computes the sum of two sandpiles and prints the final result
 * @grid1: 3x3 grid to be computed
 * @grid2: 3x3 grid to be added to grid1
 *
 * Return: Nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, toppling;

	do
	{
		toppling = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				grid1[i][j] += grid2[i][j];
				if (grid1[i][j] > 3)
				{
					toppling = 1;
				}
			}
		}

		if (toppling)
		{
			printf("=\n");
			print_grid(grid1);
			topple(grid1, grid2);
		}
	} while (toppling);
}

/**
 * topple - Check if a toppling is needed and update the grid accordingly
 * @grid1: The grid to be checked
 *
 * Return: 1 if a toppling is needed and 0 otherwise
 */
void topple(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid2[i][j] = 0;
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid2[i][j] = 1;
				if (i > 0)
				{
					grid2[i - 1][j] += 1;
				}
				if (i < 2)
				{
					grid2[i + 1][j] += 1;
				}
				if (j > 0)
				{
					grid2[i][j - 1] += 1;
				}
				if (j < 2)
				{
					grid2[i][j + 1] += 1;
				}
			}
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] > 3 ? grid1[i][j] - 4 : grid1[i][j];
			grid1[i][j] += grid2[i][j];
		}
	}
}

/**
 * print_grid - Prints the grid
 * @grid: The grid to be printed
 */
void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d", grid[i][j]);
			if (j < 2)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}
