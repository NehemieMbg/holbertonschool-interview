#include "sort.h"

/**
 * merge_them - sort the sub-arrays
 * and reunificates all those chunks to be happy and
 * love the earth
 * @array: array to merge sort
 * @start: start from where to sort
 * @mid: mid split
 * @end: end of portion
 * @copy: copy array to work with
 */

void merge_them(int *array, size_t start, size_t mid, size_t end,
				int *copy)
{
	size_t i, j, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);

	for (i = start, j = mid; i < mid && j < end; k++)
	{
		if (array[i] < array[j])
			copy[k] = array[i++];
		else
			copy[k] = array[j++];
	}
	while (i < mid)
		copy[k++] = array[i++];
	while (j < end)
		copy[k++] = array[j++];
	i = 0;
	for (k = start; k < end; k++)
		array[k] = copy[i++];
	printf("[Done]: ");
	print_array(array + start, end - start);
}

/**
 * merge_sort_recurs - recursively sort the array
 * using merge-top-down technic
 * @array: pointer to array to sort
 * @start: start of portion
 * @end: end of portion
 * @copy: copy of array
 */

void merge_sort_recurs(int *array, size_t start, size_t end, int *copy)
{
	size_t mid = 0;

	if (end - start > 1)
	{
		mid = ((end - start) / 2 + start);
		merge_sort_recurs(array, start, mid, copy);
		merge_sort_recurs(array, mid, end, copy);
		merge_them(array, start, mid, end, copy);
	}
}

/**
 * merge_sort - sorts an array of intergers
 * in ascending using Merge Sort with top-down
 *
 * @array: array to be sorted
 * @size: Number of elements
 *
 */

void merge_sort(int *array, size_t size)
{
	int *copy;

	if (!array || size < 2)
		return;

	copy = malloc(size * sizeof(int));
	if (!copy)
		return;

	merge_sort_recurs(array, 0, size, copy);
	free(copy);
}
