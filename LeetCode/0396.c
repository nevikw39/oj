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

#include "0396.h"

int main()
{
    const int a[] = {4,3,2,6}, b[] = {100};
    assert(maxRotateFunction(a, sizeof a / sizeof *a) == 26);
    assert(maxRotateFunction(b, sizeof b / sizeof *b) == 0);
    return 0;
}
