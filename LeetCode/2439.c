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

#include "2439.h"

int main()
{
    int a[] = {3, 7, 1, 6}, b[] = {10, 1}, c[] = {13, 13, 20, 0, 8, 9, 9}, d[] = {6, 9, 3, 8, 14};
    printf("%d\n%d\n%d\n%d\n",
           minimizeArrayValue(a, sizeof a / sizeof(int)),
           minimizeArrayValue(b, sizeof b / sizeof(int)),
           minimizeArrayValue(c, sizeof c / sizeof(int)),
           minimizeArrayValue(d, sizeof d / sizeof(int)));
    return 0;
}
