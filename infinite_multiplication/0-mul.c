#include "holberton.h"

/**
 * is_digit - check if arguement provided are correct
 * @dig: supposed digit
 *
 * Return: 1 for success, 0 otherwise
 */

int is_digit(char *dig)
{
	int i;

	for (i = 0; dig[i]; i++)
	{
		if ((dig[i] < '0' || dig[i] > '9'))
			return (0);
	}
	return (1);
}

/**
 * print_error - handles error and exit with status 98
 */

void print_error(void)
{
	int i = 0;
	char msg[] = "Error";

	while (msg[i] != '\0')
		_putchar(msg[i]), ++i;
	_putchar('\n');

	exit(98);
}

/**
 * mult - performs the multiplication of argv[1] * argv[2]
 * @prod_array: allocated array for storing result
 * @n1: first number
 * @n2: second number
 * @len1: length of first number
 * @len2: length of second number
 */

void mult(unsigned int *prod_array, char *n1, char *n2,
		  size_t len1, size_t len2)
{
	int i, j, tmp_sum;
	unsigned char digit1, digit2;

	if (prod_array == NULL || n1 == NULL || n2 == NULL)
		return;

	for (i = len1 - 1; i >= 0; i--)
	{
		/* clear after storing the carry if carry */
		tmp_sum = 0;
		digit1 = n1[i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			digit2 = n2[j] - '0';
			tmp_sum += (digit1 * digit2) + prod_array[i + j + 1];
			prod_array[i + j + 1] = tmp_sum % 10;
			tmp_sum /= 10;
		}
		if (tmp_sum)
			prod_array[i + j + 1] += tmp_sum;
	}
}

/**
 * init_product_array - initializes an array
 * based on expected length of result according to len
 * of argument 1 + 2
 * @prod_len: the length expected
 *
 * Return: pointer to first element of allocated array
 */

unsigned int *init_product_array(int prod_len)
{
	unsigned int *arr = NULL;
	int i;

	arr = malloc(sizeof(unsigned int) * prod_len);
	if (!arr)
		return (NULL);

	for (i = 0; i < prod_len; i++)
		arr[i] = 0;
	return (arr);
}

/**
 * main - entry point of program mul
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, exit(98) otherwise
 */

int main(int argc, char *argv[])
{
	int i, len_a1 = 0, len_a2 = 0, len_prod = 0;
	unsigned int *prod = NULL;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
		print_error();

	for (i = 0; argv[1][i]; i++)
		len_a1++;
	for (i = 0; argv[2][i]; i++)
		len_a2++;

	len_prod = len_a1 + len_a2;
	prod = init_product_array(len_prod);

	mult(prod, argv[1], argv[2], len_a1, len_a2);

	for (i = 0; !prod[i] && i < len_prod; i++)
		;
	if (i == len_prod)
		_putchar('0');

	for (; i < len_prod; i++)
		_putchar(prod[i] + '0');
	_putchar('\n');

	free(prod);

	return (0);
}
