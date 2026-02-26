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

#include "1404.h"

int main()
{
    assert(numSteps("1101") == 6);
    assert(numSteps("10") == 1);
    assert(numSteps("1") == 0);
    assert(numSteps("11000") == 6);
    return 0;
}
