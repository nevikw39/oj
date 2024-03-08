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

#include "3005.h"

int main()
{
    int a[] = {1, 2, 2, 3, 1, 4}, b[] = {1, 2, 3, 4, 5};
    printf("%d\n%d\n",
           maxFrequencyElements(a, sizeof a / sizeof(int)),
           maxFrequencyElements(b, sizeof b / sizeof(int)));
    return 0;
}
