#include <assert.h>
#include <ctype.h>
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

#include "1855.h"

int main()
{
    const int a0[] = {55, 30, 5, 4, 2}, a1[] = {100, 20, 10, 10, 5}, b0[] = {2, 2, 2}, b1[] = {10, 10, 1}, c0[] = {30, 29, 19, 5}, c1[] = {25, 25, 25, 25, 25};
    assert(maxDistance(a0, sizeof a0 / sizeof *a0, a1, sizeof a1 / sizeof *a1) == 2);
    assert(maxDistance(b0, sizeof b0 / sizeof *b0, b1, sizeof b1 / sizeof *b1) == 1);
    assert(maxDistance(c0, sizeof c0 / sizeof *c0, c1, sizeof c1 / sizeof *c1) == 2);
    return 0;
}
