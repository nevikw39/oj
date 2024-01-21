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

#include "0198.h"

int main()
{
    int a[] = {1, 2, 3, 1}, b[] = {2, 7, 9, 3, 1};
    printf("%d\n%d\n",
           rob(a, sizeof a / sizeof(int)),
           rob(b, sizeof b / sizeof(int)));
    return 0;
}
