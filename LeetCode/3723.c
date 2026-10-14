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

#include "3723.h"

int main()
{
    assert(!strcmp(maxSumOfSquares(2, 3), "30"));
    assert(!strcmp(maxSumOfSquares(2, 17), "98"));
    assert(!strcmp(maxSumOfSquares(1, 10), ""));
    return 0;
}
