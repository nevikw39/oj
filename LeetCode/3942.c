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

#include "2089.h"

int main()
{
    int a[] = {0, 2, 1}, b[] = {1, 0, 2}, c[] = {2, 0, 1, 3}, d[] = {0};
    assert(minOperations(a, sizeof a / sizeof *a) == 2);
    assert(minOperations(b, sizeof b / sizeof *b) == 2);
    assert(minOperations(c, sizeof c / sizeof *c) == -1);
    assert(minOperations(d, sizeof d / sizeof *d) == 0);
    return 0;
}
