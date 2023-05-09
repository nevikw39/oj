#include <assert.h>
#include <errno.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "0054.h"

int main()
{
    int **a = malloc(sizeof(int **));
    *a = malloc(sizeof(int *));
    **a = 1;
    int col[] = {1}, size, *ptr = spiralOrder(a, 1, col, &size);
    while (size--)
        printf("%d ", *ptr++);
    putchar('\n');
    return 0;
}
