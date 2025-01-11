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

#include "1400.h"

int main()
{
    assert(canConstruct("annabelle", 2) == true);
    assert(canConstruct("leetcode", 3) == false);
    assert(canConstruct("true", 4) == true);
    assert(canConstruct("cr", 7) == false);
    return 0;
}
