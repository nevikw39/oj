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
    const int a[] = {1, 2, 3, 4}, b[] = {2, 7, 1, 19, 18, 3};
    assert(sumOfSquares(a, sizeof a / sizeof *a) == 21);
    assert(sumOfSquares(b, sizeof b / sizeof *b) == 63);
    return 0;
}
