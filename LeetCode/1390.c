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

#include "1390.h"

int main()
{
    int a[] = {21, 4, 7}, b[] = {21, 21}, c[] = {1, 2, 3, 4, 5};
    assert(sumFourDivisors(a, sizeof a / sizeof *a) == 32);
    assert(sumFourDivisors(b, sizeof b / sizeof *b) == 64);
    assert(sumFourDivisors(c, sizeof c / sizeof *c) == 0);
    return 0;
}
