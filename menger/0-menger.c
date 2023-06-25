#include "menger.h"

/**
 * menger - draws a 2D menger sponge
 * => a Sierpinski carpet (hooray poland! chess and vodka)
 * @level: level of that carpet
 * if we write coordinate of any point on the carpet in base 3
 * the pixel is blank if and only if any matching pair of digits are (1, 1)
 */

void menger(int level)
{
	int i, j, row, col, depth, pattern;

	if (level < 0)
		return;
	/* size of level N 2D sponge is 3^N */
	depth = pow(3, level);
	for (i = 0; i < depth; i++)
	{
		for (j = 0; j < depth; j++)
		{
			pattern = '#';
			row = i;
			col = j;
			while (row || col)
			{
				if (row % 3 == 1 && col % 3 == 1)
					pattern = ' ';
				row /= 3;
				col /= 3;
			}
			putchar(pattern);
		}
		putchar('\n');
	}
}
