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

#include "1491.h"

int main()
{
    int a[] = {4000, 3000, 1000, 2000}, b[] = {1000, 2000, 3000};
    printf("%f\n%f\n",
           average(a, sizeof a / sizeof(int)),
           average(b, sizeof b / sizeof(int)));
    return 0;
}
