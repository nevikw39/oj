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

#include "2348.h"

int main()
{
    int a[] = {1, 3, 0, 0, 2, 0, 0, 4}, b[] = {0, 0, 0, 2, 0, 0}, c[] = {2, 10, 2019};
    printf("%" PRId64 "\n%" PRId64 "\n%" PRId64 "\n",
           zeroFilledSubarray(a, sizeof(a) / sizeof(int)),
           zeroFilledSubarray(b, sizeof(b) / sizeof(int)),
           zeroFilledSubarray(c, sizeof(c) / sizeof(int)));
    return 0;
}
