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

#include "2833.h"

int main()
{
    assert(furthestDistanceFromOrigin("L_RL__R") == 3);
    assert(furthestDistanceFromOrigin("_R__LL_") == 5);
    assert(furthestDistanceFromOrigin("_______") == 7);
    return 0;
}
