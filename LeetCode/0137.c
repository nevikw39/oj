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

#include "0137.h"

int main()
{
    int a[] = {2, 2, 3, 2}, b[] = {0, 1, 0, 1, 0, 1, 99};
    printf("%" PRId64 "\n%" PRId64 "\n",
           singleNumber(a, sizeof a / sizeof(int)),
           singleNumber(b, sizeof b / sizeof(int)));
    return 0;
}
