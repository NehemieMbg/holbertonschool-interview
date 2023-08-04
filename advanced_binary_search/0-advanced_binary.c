#include "search_algos.h"

/**
 * recurs_bin - performs the binary search in recursion style
 * @a: pointer to first element of array
 * @size: number of elements in array
 * @value: the value to look for
 * Return: recursive call to grasp the djik djik
 */

int recurs_bin(int *a, size_t size, int value)
{
	size_t mid = 0, i;
	int idx;

	mid = (size - 1) / 2;

	if (size < 1)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
		printf("%d%s", a[i], i != size - 1 ? ", " : "\n");
	if (a[0] >= value)
		return (a[0] == value ? 0 : -1);
	else if (a[mid] >= value)
		return (recurs_bin(a, mid + 1, value));
	idx = recurs_bin(a + mid + 1, size - mid - 1, value);

	if (idx != -1)
		return (idx + mid + 1);
	return (-1);
}

/**
 * advanced_binary - search for a value in a given array of int
 * @array: pointer to first element of array
 * @size: number of element sin the array
 * @value: value to look for
 * Return: -1 if not found, otherwise the index of first value found
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (!array || !value)
		return (-1);
	return (recurs_bin(array, size, value));
}
