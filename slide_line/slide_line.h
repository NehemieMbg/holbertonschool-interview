#ifndef __SLIDE__
#define __SLIDE__

#include <stdio.h>
#include <stdlib.h>

#define SLIDE_LEFT 1
#define SLIDE_RIGHT -1

int slide_line(int *line, size_t size, int direction);
/* for another version */
/* void slider(int *line, size_t size, int direction); */

#endif /* __SLIDE__ */
