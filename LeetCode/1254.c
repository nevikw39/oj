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

#include "1254.h"

int main()
{
    int (*a)[8] = {{1, 1, 1, 1, 1, 1, 1, 0},
                   {1, 0, 0, 0, 0, 1, 1, 0},
                   {1, 0, 1, 0, 1, 1, 1, 0},
                   {1, 0, 0, 0, 0, 1, 0, 1},
                   {1, 1, 1, 1, 1, 1, 1, 0}},
        col_a = 8,
        (*b)[5] = {{0, 0, 1, 0, 0},
                   {0, 1, 0, 1, 0},
                   {0, 1, 1, 1, 0}},
        col_b = 5,
        (*c)[7] = {{1, 1, 1, 1, 1, 1, 1},
                   {1, 0, 0, 0, 0, 0, 1},
                   {1, 0, 1, 1, 1, 0, 1},
                   {1, 0, 1, 0, 1, 0, 1},
                   {1, 0, 1, 1, 1, 0, 1},
                   {1, 0, 0, 0, 0, 0, 1},
                   {1, 1, 1, 1, 1, 1, 1}},
        col_c = 7;
    printf("%d\n%d\n%d\n",
           closedIsland(a, 5, &col_a),
           closedIsland(b, 3, &col_b),
           closedIsland(c, 7, &col_c));
    return 0;
}
