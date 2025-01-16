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

#include "2425.h"

int main()
{
    int a0[] = {2, 1, 3}, a1[] = {10, 2, 5, 0}, b0[] = {1, 2}, b1[] = {3, 4}; 
    assert(xorAllNums(a0, sizeof a0 / sizeof(int), a1, sizeof a1 / sizeof(int)) == 13);
    assert(xorAllNums(b0, sizeof b0 / sizeof(int), b1, sizeof b1 / sizeof(int)) == 0);
    return 0;
}
