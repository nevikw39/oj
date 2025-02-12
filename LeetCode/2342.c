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

#include "2342.h"

int main()
{
    int a[] = {18, 43, 36, 13, 7}, b[] = {10, 12, 19, 14};
    assert(maximumSum(a, sizeof a / sizeof(int)) == 54);
    assert(maximumSum(b, sizeof b / sizeof(int)) == -1);
    return 0;
}
