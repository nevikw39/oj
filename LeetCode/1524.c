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

#include "1524.h"

int main()
{
    int a[] = {1, 3, 5}, b[] = {2, 4, 6};
    assert(numOfSubarrays(a, sizeof a / sizeof(int)) == 4);
    assert(numOfSubarrays(b, sizeof b / sizeof(int)) == 0);
    return 0;
}
