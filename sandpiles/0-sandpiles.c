#include "sandpiles.h"

void topple(int grid[3][3], int row, int col)
{
	int grains = grid[row][col];
	grid[row][col] = grains % 4;

	if (grains >= 4)
	{
		if (row > 0)
		{
			grid[row - 1][col] += 1;
			topple(grid, row - 1, col);
		}
		if (row < 2)
		{
			grid[row + 1][col] += 1;
			topple(grid, row + 1, col);
		}
		if (col > 0)
		{
			grid[row][col - 1] += 1;
			topple(grid, row, col - 1);
		}
		if (col < 2)
		{
			grid[row][col + 1] += 1;
			topple(grid, row, col + 1);
		}
	}
}

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int unstable = 1;
	while (unstable)
	{
		unstable = 0;
		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				if (grid1[row][col] > 3)
				{
					unstable = 1;
					topple(grid1, row, col);
				}
			}
		}
		if (unstable)
		{
			printf("=\n");
			print_grid(grid1);
		}
	}
}

void print_grid(int grid[3][3])
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			printf("%d", grid[row][col]);
			if (col < 2)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}
