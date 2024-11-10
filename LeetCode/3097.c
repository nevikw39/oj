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

#include "3097.h"

int main()
{
    int a[] = {1, 2, 3}, b[] = {2, 1, 8}, c[] = {1, 2};
    assert(minimumSubarrayLength(a, sizeof a / sizeof(int), 2) == 1);
    assert(minimumSubarrayLength(b, sizeof b / sizeof(int), 10) == 3);
    assert(minimumSubarrayLength(c, sizeof c / sizeof(int), 0) == 1);
    return 0;
}
