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

#include "1493.h"

int main()
{
    int a[] = {1, 1, 0, 1}, b[] = {0, 1, 1, 1, 0, 1, 1, 0, 1}, c[] = {1, 1, 1};
    printf("%d\n%d\n%d\n",
           longestSubarray(a, sizeof(a) / sizeof(int)),
           longestSubarray(b, sizeof(b) / sizeof(int)),
           longestSubarray(c, sizeof(c) / sizeof(int)));
    return 0;
}
