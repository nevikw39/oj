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

#include "3314.h"

int main()
{
    int a[] = {2, 3, 5, 7}, b[] = {11, 13, 31}, x;
    const int ca[] = {-1, 1, 4, 3}, cb[] = {9, 12, 15};
    assert(!memcmp(minBitwiseArray(a, sizeof a / sizeof *a, &x), ca, sizeof ca));
    assert(!memcmp(minBitwiseArray(b, sizeof b / sizeof *b, &x), cb, sizeof cb));
    return 0;
}
