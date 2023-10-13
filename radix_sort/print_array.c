#include <stdio.h>
#include <stdlib.h>

/**
 * print_array - Prints the array
 *
 * @array: array to be printed
 * @size: Number of elements in array
 *
 */

void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (i < size && array)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
