#include "substring.h"

/**
 * find_substring - Finds all the possible subtrings containing a list
 * of words, within a given string
 * @s: String to scan
 * @words: Array of words all substrings must be a concatenation arragenment of
 * @nb_words: Number of elements in the array words
 * @n: Hold the address at which to store the number of elements
 * in the returned array
 *
 * Return: An allocated array, storing each index in `s`, at which
 * a substring was found, If no solution is found, return NULL
 * -> All words in the array `words` are the same length.
 * -> A valid substring of `s` is the concatenation of each word in `words`
 *  exactly once and without any intervening character
 */

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i = 0, j, k;
	/* all words are assumed same length */
	int len = strlen(s), word_len = strlen(words[0]);
	int *sub, *found;

	if (!s)
		return (NULL);
	/* Init found addrs to 0 */
	*n = 0;
	found = malloc(nb_words * sizeof(int));
	sub = malloc(len * sizeof(int));

	/* sub is necessary inside bounds (len - nb_words * word_len) */
	/* Restrict iteration to the only 'available space place' for a sub */
	while (i <= len - nb_words * word_len)
	{
		for (j = 0; j < nb_words; j++)
			found[j] = 0;
		/* Iterate through position in substring */
		for (j = 0; j < nb_words; j++)
		{
			/* Check each words against the substring */
			for (k = 0; k < nb_words; k++)
			{
				if (found[k] == 0 && !strncmp(s + i + j * word_len,
											  words[k], word_len))
				{
					found[k] = 1;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
			sub[(*n)++] = i;
		i++;
	}
	free(found);
	return (sub);
}
