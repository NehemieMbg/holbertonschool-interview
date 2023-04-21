#include "sandpiles.h"

/**
 * sandpiles_sum - Computes the sum of two sandpiles and keeps the sum stable.
 * @grid1: 3x3 grid representing the first sandpile
 * @grid2: 3x3 grid representing the second sandpile to be added to the first
 *
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0, toppling = 0;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			if (grid1[i][j] > 3)
				toppling = 1;
		}

	while (toppling == 1)
	{
		if (toppling == 1)
			print_grid1(grid1);
		toppling = topple_check(grid1);
	}
}

/**
 * topple_check - checks if a "toppling" is needed
 * and manages neighbors accordingly
 * @grid1: the grid to check the "stability"
 * Return: 1 to keep toppling as stability is not reached yet, 0 otherwise
 */
int topple_check(int grid1[3][3])
{
	int i = 0, j = 0, status = 0;
	int tmp[3][3] = {{0}};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;
				if (i > 0)
					tmp[i - 1][j]++;
				if (i < 2)
					tmp[i + 1][j]++;
				if (j > 0)
					tmp[i][j - 1]++;
				if (j < 2)
					tmp[i][j + 1]++;
			}
		}
	}

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += tmp[i][j];
			if (grid1[i][j] > 3)
				status = 1;
		}
	return (status);
}

/**
 * print_grid - Prints a 3x3 grid of integers
 * @grid: Pointer to the 3x3 grid of integers
 * Return: void
 */

void print_grid1(int grid[3][3])
{
	int i, j;

	printf("=\n");
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
