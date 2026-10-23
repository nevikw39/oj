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

#include "3644.h"

int main()
{
    int a[] = {0, 3, 2, 1}, b[] = {0, 1, 3, 2}, c[] = {3, 2, 1, 0};
    assert(sortPermutation(a, sizeof a / sizeof *a) == 1);
    assert(sortPermutation(b, sizeof b / sizeof *b) == 2);
    assert(sortPermutation(c, sizeof c / sizeof *c) == 0);
    return 0;
}
