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

#include "1800.h"

int main()
{
    int a[] = {10, 20, 30, 5, 10, 50}, b[] = {10, 20, 30, 40, 50}, c[] = {12, 17, 15, 13, 10, 11, 12};
    assert(maxAscendingSum(a, sizeof a / sizeof(int)) == 65);
    assert(maxAscendingSum(b, sizeof b / sizeof(int)) == 150);
    assert(maxAscendingSum(c, sizeof c / sizeof(int)) == 33);
    return 0;
}
