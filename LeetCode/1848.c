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

#include "1848.h"

int main()
{
    int a[] = {1, 2, 3, 4, 5}, b[] = {1}, c[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    assert(getMinDistance(a, sizeof a / sizeof *a, 5, 3) == 1);
    assert(getMinDistance(b, sizeof b / sizeof *b, 1, 0) == 0);
    assert(getMinDistance(c, sizeof c / sizeof *c, 1, 0) == 0);
    return 0;
}
