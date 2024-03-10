#include <assert.h>
#include <ctype.h>
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

#include "2540.h"

int main()
{
    int a0[] = {1, 2, 3}, a1[] = {2, 4}, b0[] = {1, 2, 3, 6}, b1[] = {2, 3, 4, 5};
    printf("%d\n%d\n",
           getCommon(a0, sizeof a0 / sizeof(int), a1, sizeof a1 / sizeof(int)),
           getCommon(b0, sizeof b0 / sizeof(int), b1, sizeof b1 / sizeof(int)));
    return 0;
}
