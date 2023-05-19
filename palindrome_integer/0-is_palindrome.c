#include "palindrome.h"

/**
 * is_palindrome - check whether a given unsgined int as args
 * is palindromick or not
 * @n: the unsigned integer to check
 * Return: 0 is palindrome, 1 if not
 */

int is_palindrome(unsigned long n)
{
	int reverse = 0;
	int origin = n;

	while (n != 0)
	{
		reverse = reverse * 10 + n % 10;
		n /= 10;
	}
	return (origin == reverse);
}
