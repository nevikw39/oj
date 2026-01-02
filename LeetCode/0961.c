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

#include "0961.h"

int main()
{
    int a[] = {1, 2, 3, 3}, b[] = {2, 1, 2, 5, 3, 2}, c[] = {5, 1, 5, 2, 5, 3, 5, 4};
    assert(repeatedNTimes(a, sizeof a / sizeof *a) == 3);
    assert(repeatedNTimes(b, sizeof b / sizeof *b) == 2);
    assert(repeatedNTimes(c, sizeof c / sizeof *c) == 5);
    return 0;
}
