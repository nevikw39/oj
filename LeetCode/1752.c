#include <assert.h>
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

#include "1752.h"

int main()
{
    int a[] = {3, 4, 5, 1, 2}, b[] = {2, 1, 3, 4}, c[] = {1, 2, 3};
    assert(check(a, sizeof a / sizeof(int)) == true);
    assert(check(b, sizeof b / sizeof(int)) == false);
    assert(check(c, sizeof c / sizeof(int)) == true);
    return 0;
}
