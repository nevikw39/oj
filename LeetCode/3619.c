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

#include "3619.h"

int main()
{
    int *grid1[] = {
        (int[]){0, 2, 1, 0, 0},
        (int[]){0, 5, 0, 0, 5},
        (int[]){0, 0, 1, 0, 0},
        (int[]){0, 1, 4, 7, 0},
        (int[]){0, 2, 0, 0, 8}},
        gridColSize1[] = {5, 5, 5, 5, 5},
        *grid2[] = {
            (int[]){0, 2, 1, 0, 0},
            (int[]){0, 5, 0, 0, 5},
            (int[]){0, 0, 1, 0, 0},
            (int[]){0, 1, 4, 7, 0},
            (int[]){0, 2, 0, 0, 8}
        },
        gridColSize2[] = {5, 5, 5, 5, 5};
    assert(countIslands(grid1, sizeof grid1 / sizeof *grid1, gridColSize1, 5) == 2);
    assert(countIslands(grid2, sizeof grid2 / sizeof *grid2, gridColSize2, 3) == 6);
    return 0;
}
