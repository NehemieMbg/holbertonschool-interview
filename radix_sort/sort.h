#ifndef __RADIX__
#define __RADIX__

#include <stdio.h>
#include <stdlib.h>
/* for dealing with int max */
#include <limits.h>

/* No tricks we deal with array of base 10 */
#define RADIX 10

void radix_sort(int *array, size_t size);
void print_array(const int *array, size_t size);

#endif /* __RADIX__ */
