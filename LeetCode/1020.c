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

#include "1020.h"

int main()
{
    int (*a)[4] = {{0, 0, 0, 0},
                   {1, 0, 1, 0},
                   {0, 1, 1, 0},
                   {0, 0, 0, 0}},
        (*b)[4] = {{0, 1, 1, 0},
                   {0, 0, 1, 0},
                   {0, 0, 1, 0},
                   {0, 0, 0, 0}},
        col = 4;
    printf("%d\n%d\n",
           numEnclaves(a, 4, &col),
           numEnclaves(b, 4, &col));
    return 0;
}
