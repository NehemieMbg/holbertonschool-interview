#include "search.h"

/**
 * linear_skip - search for a value in sorted skip list
 * @list: pointer to the head of skip list
 * @value: the value to look for
 * Return: a pointer to the first node where value is located
*/

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *voyager;

	if (list)
	{
		while (list->next && list->n < value)
		{
			voyager = list;
			/* record previous 'list' pointer position and */
			/* take the fast lane vroooom */
			list = list->express;
			if (!list)
			{
				/* if out of bounds => back to previous and iterate to max pos */
				list = voyager;
				while (list->next)
					list = list->next;
			}
			if (list != voyager->express)
				break;
			printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
		}
		/* out of while so value was detected */
		printf("Value found between indexes [%ld] and [%ld]\n",
			voyager->index, list->index);
		while (voyager && voyager->index <= list->index)
		{
			printf("Value checked at index [%ld] = [%d]\n", voyager->index, voyager->n);
			if (value == voyager->n)
				return (voyager);
			voyager = voyager->next;
		}
	}
	return (NULL);
}
