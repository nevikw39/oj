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

#include "2444.h"

int main()
{
    int a[] = {1, 3, 5, 2, 7, 5}, b[] = {1, 1, 1, 1};
    printf("%" PRId64 "\n%" PRId64 "\n",
           countSubarrays(a, sizeof(a) / sizeof(int), 1, 5),
           countSubarrays(b, sizeof(b) / sizeof(int), 1, 1));
    return 0;
}
