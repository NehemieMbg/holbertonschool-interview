#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * count_sort - good old count sort, sort
 * by current digit
 * @array: array to sort
 * @size: size of the array
 * @semi: temp array used to sort working
 * @pos: current digit position
 */

void count_sort(int *array, size_t size, int *semi, long pos)
{
	size_t i;
	int bucket[RADIX] = {0};

	/* count the number of 'keys' digits that'll go in each bucket */
	for (i = 0; i < size; i++)
	{
		bucket[(array[i] / pos) % 10]++;
		semi[i] = 0;
	}

	for (i = 1; i < RADIX; i++)
		bucket[i] += bucket[i - 1];
	/* Use bucket to fill the semi-sorted array */
	for (i = size - 1; (int)i >= 0; i--)
		semi[--bucket[(array[i] / pos) % RADIX]] = array[i];

	for (i = 0; i < size; i++)
		array[i] = semi[i];
}

/**
 * radix_sort - sorts an array of int ascending order
 * using the radix sort LSD tech
 * @array: the array to sort
 * @size: Number of elements in the array
 */

void radix_sort(int *array, size_t size)
{
	size_t i = 0;
	int max = INT_MIN;
	int *semi;
	long pos;

	if (!array || size < 2)
		return;

	semi = malloc(size * sizeof(*semi));
	if (!semi)
		return;

	for (i = 0; i < size; i++)
		max = array[i] > max ? array[i] : max;

	for (pos = 1; max / pos > 0; pos *= RADIX)
	{
		count_sort(array, size, semi, pos);
		print_array(array, size);
	}
	free(semi);
}
