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

#include "0494.h"

int main()
{
    int a[] = {1, 1, 1, 1, 1}, b[] = {1};
    assert(findTargetSumWays(a, sizeof a / sizeof(int), 3) == 5);
    assert(findTargetSumWays(b, sizeof b / sizeof(int), 1) == 1);
    return 0;
}
