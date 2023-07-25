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

#include "0852.h"

int main()
{
    int a[] = {0, 1, 0}, b[] = {0, 2, 1, 0}, c[] = {0, 10, 5, 2};
    printf("%d\n%d\n%d\n",
           peakIndexInMountainArray(a, sizeof a / sizeof(int)),
           peakIndexInMountainArray(b, sizeof b / sizeof(int)),
           peakIndexInMountainArray(c, sizeof c / sizeof(int)));
    return 0;
}
