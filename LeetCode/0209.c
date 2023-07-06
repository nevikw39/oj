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

#include "0209.h"

int main()
{
    int a[] = {2, 3, 1, 2, 4, 3}, b[] = {1, 4, 4}, c[] = {1, 1, 1, 1, 1, 1, 1, 1};
    printf("%d\n%d\n%d\n",
           minSubArrayLen(7, a, sizeof a / sizeof(int)),
           minSubArrayLen(4, b, sizeof b / sizeof(int)),
           minSubArrayLen(11, c, sizeof c / sizeof(int)));
    return 0;
}
