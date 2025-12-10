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

#include "3977.h"

int main()
{
    int a[] = {1, 2, 3}, b[] = {3, 3, 3, 4, 4, 4};
    assert(countPermutations(a, sizeof a / sizeof *a) == 2);
    assert(countPermutations(b, sizeof b / sizeof *b) == 0);
    return 0;
}
