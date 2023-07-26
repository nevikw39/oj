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

#include "1870.h"

int main()
{
    int a[] = {1, 3, 2};
    printf("%d\n%d\n%d\n",
           minSpeedOnTime(a, sizeof a / sizeof(int), 6),
           minSpeedOnTime(a, sizeof a / sizeof(int), 2.7),
           minSpeedOnTime(a, sizeof a / sizeof(int), 1.9));
    return 0;
}
