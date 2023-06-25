#include "slide_line.h"

/**
 * slide_line - slide an int array in the 2048 game style but on single line
 * @line: pointer to int array
 * @size: number of elements in the array
 * @direction: direction to slide to => Left (-1) Right (1)
 * Return: 1 success, 0 otherwise
 */

int slide_line(int *line, size_t size, int direction)
{
	int i = 0, j = 0;

	if (!line)
		return (0);
	if (direction != SLIDE_RIGHT && direction != SLIDE_LEFT)
		return (0);
	for (i = (direction == SLIDE_LEFT) ? 0 : size - 1;
		 (direction == SLIDE_LEFT) ? (i < (int)size - 1) : i >= 0; i += direction)
	{
		for (j = i + direction; (direction == SLIDE_LEFT) ? (j < (int)size - 1)
														  : j >= 0;
			 j += direction)
		{
			if (line[i] == 0 && line[j] != 0)
			{
				line[i] = line[j];
				line[j] = 0;
				i -= direction;
				break;
			}
			else if (line[i] == line[j] && line[i] != 0)
			{
				line[i] <<= 1;
				line[j] = 0;
				break;
			}
			else if (line[i] != line[j] && line[i] == 0)
				break;
		}
	}
	return (1);
}
