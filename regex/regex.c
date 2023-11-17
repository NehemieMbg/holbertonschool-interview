#include "regex.h"

/**
 * regex_match - Checks whether a given pattern matches
 * a given string
 * @str: Pointer to string to scan
 * @pattern: Pointer to the regular expression
 * Return: 1 if matches, 0 otherwise
 */

int regex_match(char const *str, char const *pattern)
{
	/* Let's begin by a 'the end' condition */
	/* so we are closer to the end =) */
	if (*str == '\0' && *pattern == '\0')
		return (1);

	if (*str != '\0' && *pattern == '\0')
		return (0);

	/* If we find a 'wildcard jocker character' */
	if (*(pattern + 1) == '*')
	{
		while ((*str != '\0' && *pattern == '.') || (*str == *pattern))
		{
			if (regex_match(str++, pattern + 2))
				return (1);
		}
		return (regex_match(str, pattern + 2));
	}

	if (*str == '\0' || (*pattern != '.' && *str != *pattern))
		return (0);

	return (regex_match(str + 1, pattern + 1));
}
