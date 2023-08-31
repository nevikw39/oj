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

#include "1326.h"

int main()
{
    int a[] = {3,4,1,1,0,0}, b[] = {0,0,0,0};
    printf("%d\n%d\n",
           minTaps(sizeof a / sizeof(int) + 1, a, sizeof a / sizeof(int)),
           minTaps(sizeof b / sizeof(int) + 1, b, sizeof b / sizeof(int)));
    return 0;
}
