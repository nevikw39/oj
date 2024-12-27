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

#include "1014.h"

int main()
{
    int a[] = {8, 1, 5, 2, 6}, b[] = {1, 2};
    assert(maxScoreSightseeingPair(a, sizeof a / sizeof(int)) == 11);
    assert(maxScoreSightseeingPair(b, sizeof b / sizeof(int)) == 2);
    return 0;
}
