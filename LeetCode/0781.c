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

#include "0781.h"

int main()
{
    int a[] = {1, 1, 2}, b[] = {10, 10, 10};
    assert(numRabbits(a, sizeof a / sizeof(int)) == 5);
    assert(numRabbits(b, sizeof b / sizeof(int)) == 11);
    return 0;
}
