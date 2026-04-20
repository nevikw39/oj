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

#include "2078.h"

int main()
{
    const int a[] = {1, 1, 1, 6, 1, 1, 1}, b[] = {1, 8, 3, 8, 3}, c[] = {0, 1};
    assert(maxDistance(a, sizeof a / sizeof *a) == 3);
    assert(maxDistance(b, sizeof b / sizeof *b) == 4);
    assert(maxDistance(c, sizeof c / sizeof *c) == 1);
    return 0;
}
