#ifndef __INFMUL__
#define __INFMUL__

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

int _putchar(char c);
int is_digit(char *dig);
void print_error(void);
void mult(unsigned int *prod_array, char *n1, char *n2, size_t len1, size_t len2);
unsigned int *init_product_array(int prod_len);

#endif /* __INFMUL__ */
