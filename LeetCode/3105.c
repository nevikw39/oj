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

#include "3105.h"

int main()
{
    int a[] = {1, 4, 3, 3, 2}, b[] = {3, 3, 3, 3}, c[] = {3, 2, 1};
    assert(longestMonotonicSubarray(a, sizeof a / sizeof(int)) == 2);
    assert(longestMonotonicSubarray(b, sizeof b / sizeof(int)) == 1);
    assert(longestMonotonicSubarray(c, sizeof c / sizeof(int)) == 3);
    return 0;
}
