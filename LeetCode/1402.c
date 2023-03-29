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

#include "1402.h"

int main()
{
    int a[] = {-1, -8, 0, 5, -9}, b[] = {4, 3, 2}, c[] = {-1, -4, -5};
    printf("%d\n%d\n%d\n",
           maxSatisfaction(a, sizeof a / sizeof(int)),
           maxSatisfaction(b, sizeof b / sizeof(int)),
           maxSatisfaction(c, sizeof c / sizeof(int)));
    return 0;
}
