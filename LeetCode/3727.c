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

#include "2778.h"

int main()
{
    int a[] = {1, 2, 3}, b[] = {1, -1, 2, -2, 3, -3};
    assert(maxAlternatingSum(a, sizeof a / sizeof *a) == 12);
    assert(maxAlternatingSum(b, sizeof b / sizeof *b) == 16);
    return 0;
}
