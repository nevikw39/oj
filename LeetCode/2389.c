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

#include "2389.h"

int main()
{
    int a[] = {4, 4, 4, 5, 6}, b[] = {1, 1, 1, 2};
    printf("%d\n%d\n",
           validPartition(a, sizeof a / sizeof(int)),
           validPartition(b, sizeof b / sizeof(int)));
    return 0;
}
