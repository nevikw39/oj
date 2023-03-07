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

#include "2187.h"

int main()
{
    int a[] = {1, 2, 3}, b[] = {2};
    printf("%" PRId64 "\n%" PRId64 "\n",
           minimumTime(a, sizeof(a) / sizeof(int), 5),
           minimumTime(b, sizeof(b) / sizeof(int), 1));
    return 0;
}
