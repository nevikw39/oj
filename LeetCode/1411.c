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

#include "1411.h"

int main()
{
    assert(numOfWays(1) == 12);
    assert(numOfWays(5000) == 30228214);
    return 0;
}
