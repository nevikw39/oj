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

#include "1877.h"

int main()
{
    int a[] = {3, 5, 2, 3}, b[] = {3, 5, 4, 2, 4, 6};
    assert(minPairSum(a, sizeof a / sizeof *a) == 7);
    assert(minPairSum(b, sizeof b / sizeof *b) == 8);
    return 0;
}
