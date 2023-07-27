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

#include "2141.h"

int main()
{
    int a[] = {3, 3, 3}, b[] = {1, 1, 1, 1}, c[] = {1};
    printf("%" PRId64 "\n%" PRId64 "\n%" PRId64 "\n",
           maxRunTime(2, a, sizeof a / sizeof(int)),
           maxRunTime(2, b, sizeof b / sizeof(int)),
           maxRunTime(1, c, sizeof c / sizeof(int)));
    return 0;
}
