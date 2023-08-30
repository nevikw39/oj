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

#include "2366.h"

int main()
{
    int a[] = {3, 9, 3}, b[] = {1, 2, 3, 4, 5}, c[] = {2, 10, 20, 19, 1};
    printf("%d\n%d\n%d\n",
           minimumReplacement(a, sizeof a / sizeof(int)),
           minimumReplacement(b, sizeof b / sizeof(int)),
           minimumReplacement(c, sizeof c / sizeof(int)));
    return 0;
}
