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

#include "0977.h"

int main()
{
    int a[] = {-4, -1, 0, 3, 10}, aa[] = {0, 1, 9, 16, 100}, b[] = {-7, -3, 2, 3, 11}, bb[] = {4, 9, 9, 49, 121}, returnSize, *ptr;
    ptr = sortedSquares(a, sizeof a / sizeof(int), &returnSize);
    assert(returnSize == sizeof a / sizeof(int) && !memcmp(ptr, aa, sizeof aa / sizeof(int)));
    ptr = sortedSquares(b, sizeof b / sizeof(int), &returnSize);
    assert(returnSize == sizeof b / sizeof(int) && !memcmp(ptr, bb, sizeof bb / sizeof(int)));
    return 0;
}
